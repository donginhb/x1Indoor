/*********************************************************
  Copyright (C), 2006-2010, Aurine
  File name:	logic_ipmodule_alarm.c
  Author:   	txl
  Version:   	2.0
  Date: 		12.10.21
  Description:  ��������
  History:                   
    1. Date:			 
       Author:				
       Modification:	
    2. ...
*********************************************************/
#if 0
#include "include.h"
#include "logic_alarm.h"
#include "storage_include.h"
#endif

#include "storage_include.h"
#include "logic_include.h"

#ifdef _IP_MODULE_ALARM
/*************************************************
  Function:			ipmodule_transmit_alarmrecord
  Description:		���ƶ��ֻ�ת��������¼
  Input: 			
  	1.type			��������
  	2.areano		������
  	3.timestr		����ʱ���ַ���
  Output:			��
  Return:			�ɹ�ʧ�� true/false
  Others:
*************************************************/
int ipmodule_transmit_alarmrecord(uint32 type, uint32 areano, char *timestr)
{
	int i = 0;
	uint32 address = 0;
	char data[30] = {0};
	//IPAD_EXTENSION_LIST ipadList;
	
	if (NULL == timestr)
	{
		log_printf("ipmodule_transmit_alarmrecord: input argument timestr = NULL.\n");
		return FALSE;
	}
	log_printf("ipmodule_transmit_alarmrecord: type=%d, areano=%d, timestr=%s\n", type, areano, timestr);
	memcpy(data, &type, 4);
	memcpy(data+4, &areano, 4);
	memcpy(data+8, timestr, 20);

	// 2014-03-10 luofl modi Ϊ���IOS�����͹���,��ԭ������������ƶ��ն˵ĸ�Ϊ����IPģ��
	#if 0
	get_ipad_extension(&ipadList);
	for (i = 0; i < ipadList.count; i++)
	{
		address = ipadList.ipadData[i].ipAddr;
		if (address > 0 && ipadList.ipadData[i].state == 1)
		{		
			log_printf("ipmodule_transmit_alarmrecord: address=0x%x\n", address);
			net_direct_send(CMD_TRANSMIT_ALARMRECORD, data, 28, address, NETCMD_UDP_PORT);
		}
	}
	#else
	address = get_ipmodule_address();				// ��ȡIPģ���ַ
	set_nethead(G_CENTER_DEVNO, PRIRY_HIGHEST);
	net_direct_send(CMD_TRANSMIT_ALARMRECORD, data, 28, address, NETCMD_UDP_PORT);
	#endif
	
	return TRUE;
}

/*************************************************
  Function:			ipmodule_query_alarmrecord
  Description:		��ѯ��ǰ������¼
  Input: 			
  	1.recPacket		���հ�
  Output:			��
  Return:			0:ʧ�� >0: �ɹ�
  Others:
*************************************************/
int ipmodule_query_alarmrecord(PRECIVE_PACKET recPacket)
{
	uint8 excutor = 0;
	char verCode[10] = {0};
	PALARM_TOUCH_INFO_LIST pList = NULL;
	int i, count = 0;
	int len = 0;
	char data1[512] = {0};	
	char * data = recPacket->data + NET_HEAD_SIZE;

	// δ�յ���֤��
	if (NULL == data)
	{
		log_printf(">>>ipmodule_query_alarmrecord: data = NULL.\n");
		net_send_echo_packet(recPacket, ECHO_ERROR, NULL, 0);
		return ;
	}

	// �ж���֤���Ƿ�ƥ��
	memcpy(verCode, data, 6);
	if (get_ipmodule_bindcode() != atoi(verCode))
	{
		log_printf(">>>ipmodule_query_alarmrecord: bindcode = %s, error.\n", verCode);
		net_send_echo_packet(recPacket, ECHO_MAC, NULL, 0);
		return ;
	}
	log_printf(">>>ipmodule_query_alarmrecord: bindCode=%s.\n", verCode);
	log_printf(">>>address=0x%x.size=%d\n", recPacket->address, sizeof(ALARM_TOUCH_INFO));

	pList = storage_get_afbj_unread_record();
	pList->pAlarmRec[1].bReaded = 1;
	if (pList)
	{
		// ֻ�ϴ����µ����10����¼
		int j, startIndex = 0;

		count = pList->nCount;
		if (count > 10)
		{
			count = 10;
			pList->nCount = 10;
		}
		
		// �������Ӧ��
		memcpy(data1, &count, 4);
		memcpy(data1+4, (char*)&(pList->pAlarmRec[startIndex]), count*sizeof(ALARM_TOUCH_INFO));
		len  = count*sizeof(ALARM_TOUCH_INFO) + 4;
		log_printf("count %d len %d\n",count,len);
		net_send_echo_packet(recPacket, ECHO_OK, data1, len);
		
		for (i = startIndex; i < pList->nCount; i++)
		{
			log_printf("i:%d, type=%d, no=%d, read=%d, time1=%s\n", i, pList->pAlarmRec[i].type, pList->pAlarmRec[i].TouchNum, \
						pList->pAlarmRec[i].bReaded, pList->pAlarmRec[i].time);
		}
		free(pList);
		pList = NULL;
	}
	else
	{
		count = 0;
		net_send_echo_packet(recPacket, ECHO_OK, &count, 4);
		log_printf("ipmodule_query_alarmrecord: count = 0.\n");
	}
}

/*************************************************
  Function:			ipmodule_clear_alarm
  Description:		�����ʾ
  Input: 			
  	1.recPacket		���հ�
  Output:			��
  Return:			0:ʧ�� >0: �ɹ�
  Others:
*************************************************/
void ipmodule_clear_alarm(PRECIVE_PACKET recPacket)
{
	uint8 excutor = 0;
	char verCode[10] = {0};
	char * data = recPacket->data + NET_HEAD_SIZE;

	// δ�յ���֤��
	if (NULL == data)
	{
		log_printf(">>>ipmodule_clear_alarm: data = NULL.\n");
		net_send_echo_packet(recPacket, ECHO_ERROR, NULL, 0);
		return ;
	}

	// �ж�ִ����
	memcpy(&excutor, data, 1);
	if (EXECUTOR_LOCAL_FJ != excutor)
	{
		log_printf(">>>ipmodule_clear_alarm: excutor = 0x%x, error.\n", excutor);
		net_send_echo_packet(recPacket, ECHO_ERROR, NULL, 0);
		return ;
	}

	// �ж���֤���Ƿ�ƥ��
	memcpy(verCode, data+1, 6);
	if (get_ipmodule_bindcode() != atoi(verCode))
	{
		log_printf(">>>ipmodule_clear_alarm: bindcode = %s, error.\n", verCode);
		net_send_echo_packet(recPacket, ECHO_MAC, NULL, 0);
		return ;
	}

	// �����ʾ
	net_send_echo_packet(recPacket, ECHO_OK, NULL, 0);
	alarm_clear_alerts_operator();
	//af_gui_reaload();
}

/*************************************************
  Function:			ipmodule_sos_remotectrl
  Description:		Զ��SOS��������
  Input: 			
  	1.recPacket		���հ�
  Output:			��
  Return:			0:ʧ�� >0: �ɹ�
  Others:
*************************************************/
void ipmodule_sos_remotectrl(PRECIVE_PACKET recPacket)
{
	uint8 excutor = 0;
	char verCode[10] = {0};
	char * data = recPacket->data + NET_HEAD_SIZE;

	// δ�յ���֤��
	if (NULL == data)
	{
		log_printf(">>>ipmodule_sos_remotectrl: data = NULL.\n");
		net_send_echo_packet(recPacket, ECHO_ERROR, NULL, 0);
		return;
	}

	// �ж�ִ����
	memcpy(&excutor, data, 1);
	if (EXECUTOR_LOCAL_FJ != excutor)
	{
		log_printf(">>>ipmodule_sos_remotectrl: excutor = 0x%x, error.\n", excutor);
		net_send_echo_packet(recPacket, ECHO_ERROR, NULL, 0);
		return ;
	}
	
	// �ж���֤���Ƿ�ƥ��
	memcpy(verCode, data+1, 6);
	if (get_ipmodule_bindcode() != atoi(verCode))
	{
		log_printf(">>>ipmodule_sos_remotectrl: bindcode = %s, error.\n", verCode);
		net_send_echo_packet(recPacket, ECHO_MAC, NULL, 0);
		return;
	}
	log_printf(">>>ipmodule_sos_remotectrl: bindCode=%s.\n", verCode);

	// sos����
	sos_alarm_report();
	//RockOSSendMsg(MBGUI, AS_ALARM_PROC, (void *)0);
	net_send_echo_packet(recPacket, ECHO_OK, NULL, 0);
}
#endif

