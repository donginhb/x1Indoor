/*************************************************
  Copyright (C), 2009-2012, Aurine
  File name: 	logic_udp_comm.c
  Author:    	xiewr
  Version:   	1.0
  Date: 
  Description:  UDPͨѶ
				
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "logic_udp_comm.h"
//#include "rockmsg.h"

#define RECV_BUF_LEN			(240 * 1024)		// UDP���ջ����С, ��ʱ����
#define SEND_BUF_LEN			(240 * 1024)		// UDP���ͻ����С, ��ʱ����

static int32 g_CmdSocketFd = -1;	 				// ��������Socket

#ifdef	_USE_AURINE_SET_
static int32 g_CmdSetSocketFd = -1;	 				// ��������Socket ��������
static char g_ReciveSetData[NET_PACKBUF_SIZE]; 		// ������հ�����
static struct sockaddr_in g_ReciveSetAddress; 		// ���յ�ַ
static struct sockaddr_in g_DestSetAddress; 		// ���͵�ַ
#endif

static struct sockaddr_in g_DestAddress; 			// ���͵�ַ
static struct sockaddr_in g_ReciveAddress; 			// ���յ�ַ
static char g_ReciveData[NET_PACKBUF_SIZE]; 		// ������հ�����
static int g_udpcomm= FALSE;						//ͨѶ�Ƿ�����

#if (_SUB_PROTOCOL_ENCRYPT_ != 0x00)
static char g_EncryptBuf[NET_PACKBUF_SIZE];	  		// ����Buf ���ܺ�����
#endif
static uint8 g_SetMACFlag = FALSE;           		// add by caogw 20160418 ����MAC��д����Ĭ��MLЭ��

/**************************����Ϊ���������ӿ�************************/
static PFRECIVE_PACKET_PROC g_RecvMultPacketProc = NULL;	// ������մ�����
static PFRECIVE_PACKET_PROC g_RecvDNSPacketProc = NULL;		// DNS�����մ�����


NET_COMMAND net_get_cmd_by_nethead(const PNET_HEAD netHead);

/*************************************************
  Function:		net_set_mac
  Description:	mac�빤������mac����
  Input: 
    1.data		��������
    2.len		���ݳ���
  Output:		��
  Return:       ��  
  Others:   	MAC��д����Ĭ��MLЭ��
*************************************************/
void net_set_mac(const PRECIVE_PACKET recPacket)
{   
	uint8 mac[6] = {0}; 
               
    memcpy(mac, recPacket->data+NET_HEAD_SIZE, 6);
    int32 ret = net_set_local_mac(mac);
    if (ret == TRUE)
    {
        net_send_echo_packet_ext(recPacket, ECHO_OK, 0, 0);
    }
    else
    {
        net_send_echo_packet_ext(recPacket, ECHO_ERROR, 0, 0);
    }	
}

/*************************************************
  Function:    		create_udpsocket
  Description:		����udpsocket
  Input: 
	1.port			�˿ں�
	2.RecBufSize	����Buf��С
	3.SendBufSize	����Buf��С
  Output:			��
  Return:			TRUE / FALSE
  Others:
*************************************************/
static int32 create_cmd_socket(uint16 port, int32 RecBufSize, int32 SendBufSize)
{
	int32 socketFd;
	int32 ret;
	int32 flag;
	struct sockaddr_in addrLocal;

	socketFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (socketFd < 0)
    {
    	log_printf("get socket err\n");
        return FALSE;
    }
    else
    {
    	log_printf("get socket : %d\n", socketFd);
    }

#if 0		// lwip-v1.0.1�Ŀ����ò��ɹ�	
	ret = setsockopt(socketFd, SOL_SOCKET, SO_RCVBUF, (char*)&RecBufSize, sizeof(RecBufSize)) ;
	log_printf("set socket SO_RCVBUF ret : %d\n", ret);
    ret = setsockopt(socketFd, SOL_SOCKET, SO_SNDBUF, (char*)&SendBufSize, sizeof(SendBufSize)) ;
    log_printf("set socket SO_SNDBUF ret : %d\n", ret);
#endif    

    flag = 1;
	ret = setsockopt(socketFd, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));
	// ��ֹ����������ʱ���˿�δ���ͷţ�������������ʧ��
	ret = setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
		
    memset(&addrLocal, 0, SOCK_ADDR_SIZE);    
    addrLocal.sin_family      = AF_INET;
	addrLocal.sin_addr.s_addr = htonl(INADDR_ANY);
    addrLocal.sin_port        = htons(port);
    
    if (bind(socketFd, (struct sockaddr *)&addrLocal, SOCK_ADDR_SIZE))
    {
    	close(socketFd);
		perror("bind");
    	log_printf("bind socket err\n");
    	return FALSE;
    }
    g_CmdSocketFd = socketFd;
    return TRUE;
}

#ifdef _USE_AURINE_SET_
/*************************************************
  Function:    		create_cmd_socket_exr
  Description:		����udpsocket
  Input: 
	1.port			�˿ں�
	2.RecBufSize	����Buf��С
	3.SendBufSize	����Buf��С
  Output:			��
  Return:			TRUE / FALSE
  Others:
*************************************************/
static int32 create_cmd_socket_exr(uint16 port, int32 RecBufSize, int32 SendBufSize)
{
	int32 socketFd;
	int32 ret;
	int32 flag;
	struct sockaddr_in addrLocal;

	socketFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (socketFd < 0)
    {
    	log_printf("get socket err\n");
        return FALSE;
    }
    else
    {
    	log_printf("get socket : %d\n", socketFd);
    }

#if 0		// lwip-v1.0.1�Ŀ����ò��ɹ�	
	ret = setsockopt(socketFd, SOL_SOCKET, SO_RCVBUF, (char*)&RecBufSize, sizeof(RecBufSize)) ;
	log_printf("set socket SO_RCVBUF ret : %d\n", ret);
    ret = setsockopt(socketFd, SOL_SOCKET, SO_SNDBUF, (char*)&SendBufSize, sizeof(SendBufSize)) ;
    log_printf("set socket SO_SNDBUF ret : %d\n", ret);
#endif    

    flag = 1;
	ret = setsockopt(socketFd, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));
	// ��ֹ����������ʱ���˿�δ���ͷţ�������������ʧ��
	ret = setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
		
    memset(&addrLocal, 0, SOCK_ADDR_SIZE);    
    addrLocal.sin_family      = AF_INET;
	addrLocal.sin_addr.s_addr = htonl(INADDR_ANY);
    addrLocal.sin_port        = htons(port);
    
    if (bind(socketFd, (struct sockaddr *)&addrLocal, SOCK_ADDR_SIZE))
    {
    	close(socketFd);
		perror("bind");
    	log_printf("bind socket err\n");
    	return FALSE;
    }
    g_CmdSetSocketFd = socketFd;
    return TRUE;
}
#endif

#if (_SUB_PROTOCOL_ENCRYPT_ != 0x00)
/*************************************************
  Function:    		data_encrypt
  Description:		���ݼ��ܽ��� ���
  Input: 
	1.buf			����
	2.len			���ݳ���
  Output:			
  	1.buf			���ܡ����ܳ���������
  Return:			�ɹ����
  Others:
*************************************************/
void data_encrypt( char *buf, int len )
{
	int i;
	char *pKey = ENCRYPT_KEY;
	char key;
	log_printf("ENCRYPT_KEY : %s, ENCRYPT_KEY_LEN: %d\n", ENCRYPT_KEY, ENCRYPT_KEY_LEN);

	for( i = 0; i < len; i ++ )
	{
		key = pKey[ i % ENCRYPT_KEY_LEN];
		buf[i] = buf[i] ^ key;
	}
}
#endif


/*************************************************
  Function:    		check_hwEncrypt
  Description:		�������ͷ����
  Input: 
	1.PMainNethead			У�������
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
static int32 check_MainNethead(PMAIN_NET_HEAD PMainNethead)
{
	#ifndef _AU_PROTOCOL_
	uint32 U32Encrypt = 0;
	uint8 hwEncrypt[16] = {0};
	
	memcpy(hwEncrypt, PMainNethead->hwEncrypt, sizeof(PMainNethead->hwEncrypt));
	memcpy(&U32Encrypt, &hwEncrypt[12], 4);
	log_printf("U32Encrypt : %08x\n", U32Encrypt);
	log_printf("subProtocolEncrypt : %02x\n", PMainNethead->subProtocolEncrypt);
	
	// �����汾���Լ��������ϰ汾,�����İ汾ֻ�ܸ��Լ�ͨѶ
	if ((_HW_ENCRYPT_ == _ML_HWENCRYPT_ && U32Encrypt != 0 && U32Encrypt != _ML_HWENCRYPT_) || 
		(_HW_ENCRYPT_ != _ML_HWENCRYPT_ && U32Encrypt != _HW_ENCRYPT_))
	{
		log_printf("MainNethead hwEncrypt error!!!!\n ");
		return FALSE;
	}

	// �������Ͳ��� ���ش���
	if (PMainNethead->subProtocolEncrypt != 0X00 && PMainNethead->subProtocolEncrypt != _SUB_PROTOCOL_ENCRYPT_)
	{
		log_printf("MainNethead subProtocolEncrypt error!!!!\n ");
		return FALSE;
	}
	return TRUE;
	#endif
}

/*************************************************
  Function:    		check_packet
  Description:		�����Ƿ�Ϸ�
  Input: 
	1.data			У�������
	2.size			��У������ݳ���
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
static int32 check_packet(const char * data, int32 size)
{
	int32 ret = FALSE;
	PNET_HEAD nethead = NULL;
	
	if (size > NET_PACKBUF_SIZE || size < NET_HEAD_SIZE)
	{	
		log_printf("size err!\n");
		return FALSE;
	}	
	
	nethead = (PNET_HEAD)(data + MAIN_NET_HEAD_SIZE);
	
	// ����
	if (nethead->DataLen != (size-NET_HEAD_SIZE))
	{	
		log_printf("data len err : size: %d, datalen: %d\n", size, nethead->DataLen);
		return FALSE;
	}	
	
	// �汾	
	if (nethead->ProtocolVer != _PROTOCOL_VER_)
	{
		log_printf("protocol ver err!  nethead->ProtocolVer : %x\n", nethead->ProtocolVer);
		return FALSE;	
	}	
	
	// ����
	if (nethead->DirectFlag != DIR_SEND && nethead->DirectFlag != DIR_ACK)
	{
		log_printf("direct flg err!\n");
		return FALSE;	
	}
	
	return TRUE; 
}

/*************************************************
  Function:    		recive_cmd_data_proc
  Description:		����UDP��������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void* recive_cmd_data_proc(void *arg)
{
	uint32 ret;
	int32 len = 0;
	int32 addr_len = SOCK_ADDR_SIZE;
	NET_COMMAND cmd = 0;
	RECIVE_PACKET RecPacket;
	PNET_HEAD head;

	//static int32 RecvPacketCount = 0;				// ���Խ��հ�����	
	
	if (g_CmdSocketFd >= 0)
	{
		while (1)
		{
			len = recvfrom(g_CmdSocketFd, g_ReciveData, sizeof(g_ReciveData), 0, (struct sockaddr *)&g_ReciveAddress, &addr_len);
			if (len <= 0)
			{
				continue;
			}
			else
			{			
				// ���Խ��հ�����
				#if 0	
				RecvPacketCount++;	
				if ((RecvPacketCount%100==0) && (RecvPacketCount >= 100))
				{
					log_printf("len:%d, RecvPacketCount:%d, addr:0x%x, port:%d\n", len, RecvPacketCount, ntohl(g_ReciveAddress.sin_addr.s_addr), ntohs(g_ReciveAddress.sin_port));
				}	
				net_send_cmd_packet(g_ReciveData, 100, ntohl(g_ReciveAddress.sin_addr.s_addr), ntohs(g_ReciveAddress.sin_port));
			
				break;
				#endif		
			}

			log_printf("***************** recv packet len : %d *******************  \n", len);
			#ifndef _AU_PROTOCOL_
           	PMAIN_NET_HEAD PMainNethead = (PMAIN_NET_HEAD)(g_ReciveData);
			ret = check_MainNethead(PMainNethead);
			if (ret == FALSE)							// ����FALSE ������mac���� ��ɫ�������� TFͳһЭ��
			{
				log_printf("MainNethead err !!!!\n");
				if (PMainNethead->subProtocolEncrypt == _NO_PROTOCOL_ENCRYPT_)
            	{
               		head = (PNET_HEAD)(g_ReciveData + MAIN_NET_HEAD_SIZE);
                	cmd = net_get_cmd_by_nethead(head);
					
                	switch (cmd)
					{
						case CMD_SET_MAC:
							{
								RecPacket.data = g_ReciveData;
								RecPacket.size = len;
								RecPacket.address = ntohl(g_ReciveAddress.sin_addr.s_addr);
								RecPacket.port = ntohs(g_ReciveAddress.sin_port);
								net_set_mac(&RecPacket);
							}
							break;
							
						case CMD_SOFT_SET_PARAM:
						case CMD_SOFT_GET_PARAM:
						case CMD_SOFT_TERMINAL_CMD:
							{
								RecPacket.data = g_ReciveData;
								RecPacket.size = len;
								RecPacket.address = ntohl(g_ReciveAddress.sin_addr.s_addr);
								RecPacket.port = ntohs(g_ReciveAddress.sin_port);
								net_add_recive_packet(RecPacket.data, RecPacket.size, RecPacket.address, RecPacket.port);
							}
							break;

						default:
							break;
					}	                
           		}
				
				continue;
			}
			#endif

			// ���ݽ���
			#if (_SUB_PROTOCOL_ENCRYPT_ != 0x00)
			char *encrypt_databuf = NULL;
			encrypt_databuf = (char *)g_ReciveData + MAIN_NET_HEAD_SIZE;
			data_encrypt(encrypt_databuf, (len - MAIN_NET_HEAD_SIZE));
			#endif
			
			// ���˰�, ����Ƿ�Ϸ�	
			if (!check_packet(g_ReciveData, len))
			{
				continue;
			}

			// dns�㲥���Ͷ������ֱ�Ӵ���,���������
		#if 1
			RecPacket.data = g_ReciveData;
			RecPacket.size = len;
			RecPacket.address = ntohl(g_ReciveAddress.sin_addr.s_addr);
			RecPacket.port = ntohs(g_ReciveAddress.sin_port);

			head = (PNET_HEAD)(g_ReciveData + MAIN_NET_HEAD_SIZE);
			cmd = net_get_cmd_by_nethead(head);

			log_printf("recive_cmd_data_proc: %04x\n", cmd);
			switch (cmd)
			{											
				case CMD_SEND_MAXDATA:					// �������
				case CMD_STOP_SEND_MAXDATA: 			// �ж϶������
					if (g_RecvMultPacketProc != NULL)	// ��������ö�����ͽ��պ���
					{
		 				g_RecvMultPacketProc(cmd, &RecPacket);
					}
					break;
					 
				case CMD_DNS_GETIP:						// DNS�㲥��
					if (g_RecvDNSPacketProc != NULL)
					{
						g_RecvDNSPacketProc(cmd, &RecPacket);
					}
					break;
					
				case CMD_SET_MAC:						// ����MAC
				{					
					uint8 mac[6] = {0};					
					memcpy(mac, g_ReciveData+NET_HEAD_SIZE, 6);
					ret = net_set_local_mac(mac);
					if (ret == TRUE)
					{
						net_send_echo_packet(&RecPacket, ECHO_OK, 0, 0);
					}
					else
					{
						net_send_echo_packet(&RecPacket, ECHO_ERROR, 0, 0);
					}
					break;
				}

				#ifdef _ADD_BLUETOOTH_DOOR_
				case CMD_NETDOOR_SNAP_REPORT:
				{	
					recv_bluetoothdoor_pic_start(&RecPacket);
					break;
				}

				case CMD_REQ_SYN_TIME:
					{
						ZONE_DATE_TIME LocalDateTime = {0};
						DATE_TIME SendTime = {0};
						get_timer(&LocalDateTime);
						get_utc_time(&LocalDateTime, 8);

						SendTime.year = LocalDateTime.year;
						SendTime.month = LocalDateTime.month;
						SendTime.day = LocalDateTime.day;
						SendTime.hour = LocalDateTime.hour;
						SendTime.min = LocalDateTime.min;
						SendTime.sec = LocalDateTime.sec;
						SendTime.week = LocalDateTime.week;

						net_send_echo_packet(&RecPacket, ECHO_OK, &SendTime, sizeof(DATE_TIME));
					}
					break;
				#endif

				// ���Ӳ������������ַ�����ͬ�����ֻ� add by luofl 2011-4-27
				#ifdef _ALARM_OPER_SYNC_
				case CMD_SYNC_SET_EVENT:
					ret = alarm_check_devno(&RecPacket);
					if (ret == TRUE)
					{
						alarm_set_response();		// ��������ͬ�����ֻ�
					}
					break;

				case CMD_SYNC_UNSET_EVENT:
					ret = alarm_check_devno(&RecPacket);
					if (ret == TRUE)
					{
						alarm_unset_response();		// ��������ͬ�����ֻ�
					}
					break;

				case CMD_SYNC_PARTSET_EVENT:
					ret = alarm_check_devno(&RecPacket);
					if (ret == TRUE)
					{
						alarm_partset_response();	// �ַ�����ͬ�����ֻ�
					}
					break;
				#endif
				
				default:							// ��������, ����Ϣ����������ַ��߳�
					net_add_recive_packet(g_ReciveData, len, RecPacket.address, RecPacket.port);
		
					break;	
			}
		#else	// dns�㲥��, ������շ��ڽ����̴߳���
			net_add_recive_packet(g_ReciveData, len, ntohl(g_ReciveAddress.sin_addr.s_addr), ntohs(g_ReciveAddress.sin_port));
			//RockOSSendMsg(MB_NETDIST, AS_NET_RECV_PACKET_DISTRIBUTE, NULL);
		#endif	
		}
		
		pthread_exit(NULL);
		return NULL;
	}
	
	return NULL;
}

#ifdef	_USE_AURINE_SET_
/*************************************************
  Function:    		recive_set_cmd_data_proc
  Description:		����UDP��������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void* recive_set_cmd_data_proc(void *arg)
{
	uint32 ret;
	int32 len = 0;
	int32 addr_len = SOCK_ADDR_SIZE;
	NET_COMMAND cmd = 0;
	RECIVE_PACKET RecPacket;
	PNET_SET_HEAD head;

	//static int32 RecvPacketCount = 0;				// ���Խ��հ�����	
	
	if (g_CmdSetSocketFd >= 0)
	{
		while (1)
		{
			len = recvfrom(g_CmdSetSocketFd, g_ReciveSetData, sizeof(g_ReciveSetData), 0, (struct sockaddr *)&g_ReciveSetAddress, &addr_len);
			if (len <= 0)
			{
				continue;
			}
			else
			{			
				// ���Խ��հ�����
				#if 0	
				RecvPacketCount++;	
				if ((RecvPacketCount%100==0) && (RecvPacketCount >= 100))
				{
					log_printf("len:%d, RecvPacketCount:%d, addr:0x%x, port:%d\n", len, RecvPacketCount, ntohl(g_ReciveAddress.sin_addr.s_addr), ntohs(g_ReciveAddress.sin_port));
				}	
				net_send_cmd_packet(g_ReciveData, 100, ntohl(g_ReciveAddress.sin_addr.s_addr), ntohs(g_ReciveAddress.sin_port));
			
				break;
				#endif		
			}

			log_printf("***************** recv packet set len : %d *******************  \n", len);
           	PMAIN_NET_HEAD PMainNethead = (PMAIN_NET_HEAD)(g_ReciveSetData);
			if (PMainNethead->subProtocolEncrypt == _NO_PROTOCOL_ENCRYPT_)
        	{
           		head = (PNET_SET_HEAD)(g_ReciveSetData + AU_MAIN_NET_HEAD_SIZE);
				cmd = au_net_get_cmd_by_nethead(head);				
            	switch (cmd)
				{
					case CMD_SOFT_SET_PARAM:
						RecPacket.data = g_ReciveSetData;
						RecPacket.size = len;
						RecPacket.address = ntohl(g_ReciveSetAddress.sin_addr.s_addr);
						RecPacket.port = ntohs(g_ReciveSetAddress.sin_port);						
						set_param_cmd_deal(&RecPacket);
						break;

					case CMD_SOFT_GET_PARAM:
						RecPacket.data = g_ReciveSetData;
						RecPacket.size = len;
						RecPacket.address = ntohl(g_ReciveSetAddress.sin_addr.s_addr);
						RecPacket.port = ntohs(g_ReciveSetAddress.sin_port);
						get_param_cmd_deal(&RecPacket);
						break;

					case CMD_SOFT_TERMINAL_CMD:
						RecPacket.data = g_ReciveSetData;
						RecPacket.size = len;
						RecPacket.address = ntohl(g_ReciveSetAddress.sin_addr.s_addr);
						RecPacket.port = ntohs(g_ReciveSetAddress.sin_port);
						terminal_cmd_deal(&RecPacket);
						break;

					default:
						break;
				}	                
       		}
			
			continue;			
		}
		
		pthread_exit(NULL);
		return NULL;
	}
	
	return NULL;
}
#endif

/*************************************************
  Function:    		udp_get_cmd_by_nethead
  Description:		�������ֵ(����ϵͳ����)
  Input: 
	1.netHead		�����ͷ
  Output:			��
  Return:			��������
  Others:
*************************************************/
NET_COMMAND net_get_cmd_by_nethead(const PNET_HEAD netHead)
{
	return ((netHead->SubSysCode<<8)&0xFF00) | netHead->command;
}

#ifdef	_USE_AURINE_SET_
/*************************************************
  Function:    		au_net_get_cmd_by_nethead
  Description:		�������ֵ(����ϵͳ����)
  Input: 
	1.netHead		�����ͷ
  Output:			��
  Return:			��������
  Others:
*************************************************/
NET_COMMAND au_net_get_cmd_by_nethead(const PNET_SET_HEAD netHead)
{
	return ((netHead->SubSysCode<<8)&0xFF00) | netHead->command;
}
#endif

/*************************************************
  Function:    		net_send_cmd_packet
  Description:		����cmd��
  Input: 
	1.data			��������
	2.size			���ݴ�С
	3.address		���͵�ַ
	4.port			���Ͷ˿�
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
int32 net_send_cmd_packet(char * data, int32 size, uint32 address, uint16 port)
{
	fd_set fdWrite; 
	int32 ret = 0;
	int32 SendSize = 0;
	
	if (g_CmdSocketFd < 0)
	{
		return FALSE;
	}	
	if (address == 0)
	{
		return FALSE;
	}
	
	g_DestAddress.sin_addr.s_addr = htonl(address);
  	g_DestAddress.sin_port        = htons(port);
    
	/*
	struct timeval timeout;  
	timeout.tv_sec  = 0 ;
	timeout.tv_usec = 0;
	*/

	FD_ZERO(&fdWrite); 
	FD_SET(g_CmdSocketFd, &fdWrite);
	ret = select(FD_SETSIZE, NULL, &fdWrite, NULL, NULL);
	
	if (ret > 0)
	{
		#if (_SUB_PROTOCOL_ENCRYPT_ != 0x00)  		// ������Ҫ����
        if (data != NULL && size != 0 && g_SetMACFlag == FALSE)//modify by wangzc 20160413 ����MAC��д����Ĭ��MLЭ��
		{
			char *encrypt_databuf = NULL;
			memset(g_EncryptBuf, 0, sizeof(g_EncryptBuf));
			memcpy(g_EncryptBuf, data, size);
			encrypt_databuf = (char *)g_EncryptBuf + MAIN_NET_HEAD_SIZE;
			data_encrypt(encrypt_databuf, (size-MAIN_NET_HEAD_SIZE));
			SendSize = sendto(g_CmdSocketFd, g_EncryptBuf, size, 0, (struct sockaddr *)&g_DestAddress, SOCK_ADDR_SIZE);	
		}
		else
		#endif
		SendSize = sendto(g_CmdSocketFd, data, size, 0, (struct sockaddr *)&g_DestAddress, SOCK_ADDR_SIZE);	
		//usleep(10);
	}

	if (SendSize == size)
	{	
		log_printf("net_send_cmd_packet : size:  %d \n",size);
		return TRUE;
	}	
	else
	{
		log_printf("send err: ret: %d\n", SendSize);
		return FALSE;
	}
}

/*************************************************
  Function:    		net_send_cmd_packet_ext
  Description:		����cmd�� ����������Ȳ���Ҫ���ܵ����ݷ���
  Input: 
	1.data			��������
	2.size			���ݴ�С
	3.address		���͵�ַ
	4.port			���Ͷ˿�
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
int32 net_send_cmd_packet_ext(char * data, int32 size, uint32 address, uint16 port)
{
	fd_set fdWrite; 
	int32 ret = 0;
	int32 SendSize = 0;
	
	if (g_CmdSocketFd < 0)
	{
		return FALSE;
	}	
	if (address == 0)
	{
		return FALSE;
	}
	
	g_DestAddress.sin_addr.s_addr = htonl(address);
  	g_DestAddress.sin_port        = htons(port);
    
	/*
	struct timeval timeout;  
	timeout.tv_sec  = 0 ;
	timeout.tv_usec = 0;
	*/

	FD_ZERO(&fdWrite); 
	FD_SET(g_CmdSocketFd, &fdWrite);
	ret = select(FD_SETSIZE, NULL, &fdWrite, NULL, NULL);
	
	if (ret > 0)
	{
		SendSize = sendto(g_CmdSocketFd, data, size, 0, (struct sockaddr *)&g_DestAddress, SOCK_ADDR_SIZE);	
		//usleep(10);
	}

	if (SendSize == size)
	{	
		log_printf("net_send_cmd_packet : size:  %d \n",size);
		return TRUE;
	}	
	else
	{
		log_printf("send err: ret: %d\n", SendSize);
		return FALSE;
	}
}

#ifdef	_USE_AURINE_SET_
/*************************************************
  Function:    		au_net_send_cmd_packet_ext
  Description:		����cmd�� ����������Ȳ���Ҫ���ܵ����ݷ���
  Input: 
	1.data			��������
	2.size			���ݴ�С
	3.address		���͵�ַ
	4.port			���Ͷ˿�
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
int32 au_net_send_cmd_packet_ext(char * data, int32 size, uint32 address, uint16 port)
{
	fd_set fdWrite; 
	int32 ret = 0;
	int32 SendSize = 0;
	
	if (g_CmdSetSocketFd < 0)
	{
		return FALSE;
	}	
	if (address == 0)
	{
		return FALSE;
	}
	
	g_DestSetAddress.sin_addr.s_addr = htonl(address);
  	g_DestSetAddress.sin_port        = htons(port);
    
	/*
	struct timeval timeout;  
	timeout.tv_sec  = 0 ;
	timeout.tv_usec = 0;
	*/

	FD_ZERO(&fdWrite); 
	FD_SET(g_CmdSetSocketFd, &fdWrite);
	ret = select(FD_SETSIZE, NULL, &fdWrite, NULL, NULL);
	
	if (ret > 0)
	{
		SendSize = sendto(g_CmdSetSocketFd, data, size, 0, (struct sockaddr *)&g_DestSetAddress, SOCK_ADDR_SIZE);	
		//usleep(10);
	}

	if (SendSize == size)
	{	
		log_printf("net_send_cmd_packet : size:  %d \n",size);
		return TRUE;
	}	
	else
	{
		log_printf("send err: ret: %d\n", SendSize);
		return FALSE;
	}
}
#endif

/*************************************************
  Function:    		net_start_udp_comm
  Description:		����UDPͨѶ
  Input: 			��
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
int32 net_start_udp_comm(void)
{
	int32 ret; 
	g_DestAddress.sin_family      = AF_INET ;
	g_DestAddress.sin_addr.s_addr = 0;
    g_DestAddress.sin_port        = 0; 
    memset(&(g_DestAddress.sin_zero), 0, 8);
	ret = create_cmd_socket(NETCMD_UDP_PORT, RECV_BUF_LEN, SEND_BUF_LEN);
	#ifdef	_USE_AURINE_SET_
	int32 aurine_ret;
	aurine_ret = create_cmd_socket_exr(PC_SET_UDP_PORT, RECV_BUF_LEN, SEND_BUF_LEN);
	if (ret && aurine_ret)
	#else
	if (ret)
	#endif
	{
		net_start_comm_thread();
		g_udpcomm = TRUE ;
	 	return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:    		net_stop_udp_comm
  Description:		ֹͣUDPͨѶ
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void net_stop_udp_comm(void)
{
	if (FALSE == g_udpcomm)
		return;
	
	net_stop_comm_thread();
	
	if (g_CmdSocketFd >= 0)
	{
		close(g_CmdSocketFd);
		g_CmdSocketFd = -1;
	}
	
	g_udpcomm = FALSE;
}


/*************************************************
  Function:    		net_set_mult_packet_recive
  Description: 		���ý��ն�����մ�����
  Input: 
	1.func			������մ�����
  Output:			��
  Return:			��
  Others:
*************************************************/
void net_set_mult_packet_recive(PFRECIVE_PACKET_PROC func)
{
	g_RecvMultPacketProc = func;
}

/*************************************************
  Function:    		net_set_dns_packet_recive
  Description: 		����DNS�����ʹ�����
  Input: 
	1.func			������մ�����
  Output:			��
  Return:			��
  Others:
*************************************************/
void net_set_dns_packet_recive(PFRECIVE_PACKET_PROC func)
{
	g_RecvDNSPacketProc = func;
}

