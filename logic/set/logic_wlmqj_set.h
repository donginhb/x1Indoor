/*********************************************************************
  COPYRIGHT (C), 2006-2010, AURINE
  FILE NAME: 		logic_wlmqj_set.h
  AUTHOR:   		xiewr
  VERSION:   		1.0 
  DATE:     		2010-06-04
  DESCRIPTION:		������ǰ������

  History:        
    1. Date:
       Author:
       Modification:
    2. ...     
*********************************************************************/
#ifndef _LOGIC_WLMQJ_SET_H_
#define _LOGIC_WLMQJ_SET_H_

#include "netcom/logic_net_comm.h"

#define NETDOOR_FAULT_IP		0x0A640104 						// 10.100.1.4

#define NETDOOR_ECHO_SUCESS		0								//�����ɹ�

#define NETDOOR_ECHO_COMM		0x030000

#define NETDOOR_ERR_SEND		(NETDOOR_ECHO_COMM|0x00)		//�������ݷ��ʹ���
#define NETDOOR_ERR_ECHO		(NETDOOR_ECHO_COMM|0x01)		//Ӧ��һ�����
#define NETDOOR_ERR_MAC			(NETDOOR_ECHO_COMM|0x09)		//MAC�����

typedef struct hiVERSION_INFO_S
{
    uint32 u32ProductVer;       /* The product version  */
    uint32 u32RootBoxVer;       /* RootBox version      */
    uint32 u32LinuxVer;         /* Linux kernel version */
    uint32 u32MspVer;           /* The MSP version      */
    uint32 u32AlgVer;           /* The codec alg version*/
    uint32 u32ChipVer;          /* The chip version     */
} VERSION_INFO_S, FWM_VERSION_T;

#ifdef _ADD_BLUETOOTH_DOOR_
//������ǰ��¼����
typedef enum
{
	BLE_RECORD_TYPE_OPEN		= 0x0,  			//������¼
	BLE_RECORD_TYPE_STATUS		= 0x01, 			//��״̬
	BLE_RECORD_TYPE_OPER		= 0x02, 			//������¼
}BLE_RECORD_TYPE_E;

//�����豸���Ͷ���
typedef enum
{
	BLE_OPENDEV_SELF		= 0x00, 			// ��������
	BLE_OPENDEV_NETDOOR		= 0x10, 			// ��ǰ������
	BLE_OPENDEV_PHONE		= 0x20, 			// �ֻ�����
}BLE_OPENLOCK_DEV_E;

//�������Ͷ���
typedef enum
{
	BLE_OPENTYPE_KEY			= 0x00, 			//��е����
	BLE_OPENTYPE_PWD			= 0x01, 			//���뿪��
	BLE_OPENTYPE_CARD			= 0x02, 			//ˢ������
	BLE_OPENTYPE_FINGER			= 0x03, 			//ָ�ƿ���
	BLE_OPENTYPE_FACE			= 0x04, 			//����ʶ����
	BLE_OPENTYPE_VISTOR			= 0x06, 			//�ÿͿ���
	BLE_OPENTYPE_MONITOR		= 0x07, 			//���ӿ���
	BLE_OPENTYPE_BLEPHONE		= 0x08, 			//�ֻ�����
	BLE_OPENTYPE_TEMP_AUTHOR	= 0x09, 			//��ʱ��Ȩ����
}BLE_OPENLOCK_TYPE_E;

// ������¼����
typedef enum
{
	BLE_OPER_DEL_USER			= 0X00,				//ɾ���û�
	BLE_OPER_SET_CHANGKAI		= 0X01,				//�����ų���
	BLE_OPER_CANCEL_CHANGKAI	= 0X02,				//ȡ���ų���
	BLE_OPER_RING				= 0X03,				//����
	BLE_OPER_DEFAULT			= 0X0F,				
}BLE_OPER_TYPES_E;

// ��¼�ṹ��
typedef struct
{
	uint32 UserId;							// �û�ID
	char UserName[16];						// �û�����
	uint32 RecordType;						// ��¼����
	char RecordTime[24];						// ��¼ʱ��
}NET_RECORD_INFO, *PNET_RECORD_INFO;

typedef struct
{
	uint32 counts;
	NET_RECORD_INFO *info;	
}NET_RECORD_LIST, *PNET_RECORD_LIST;

// ���ڰ��б�ṹ��
typedef struct
{
	DEVICE_NO DestNo;						// �豸���
	uint32 DestNoIP;						// IP
}NET_BING_ROOM, *PNET_BING_ROOM;

typedef struct
{
	uint32 counts;
	NET_BING_ROOM *info;	
}NET_BING_ROOM_LIST, *PNET_BING_ROOM_LIST;
#endif

/*************************************************
  Function:    		send_netdoor_cmd_noecho
  Description:		��������ǰ��������������
  					�˽ӿ���Ҫ������Ӧ�����ݵķ���
  					��MAC,MAC������ǰ��
  Input: 
  	1.cmd:			���͵�����
  	2.data: 		��������
  	3.datelen:		���ݵĳ���
  Output:			��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
uint32 send_netdoor_cmd_noecho(NET_COMMAND cmd ,unsigned char * SendData, uint32 len);

/*************************************************
  Function:			logic_set_netdoor_netparam
  Description:		����������ǰ���������
  Input: 				
    1.netparam		�������
  Output:			��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					���ݷ�������:0x030000
  Others:
*************************************************/
int32 logic_set_netdoor_netparam(PNET_PARAM netparam);

/*************************************************
  Function:			logic_get_netdevice_netparam
  Description:		��������豸�������
  Input: 				
  Output:			
  	1.netparam		�������
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:			
*************************************************/
int32 logic_get_netdevice_netparam(PNET_PARAM netparam);

/*************************************************
  Function:			logic_set_netdoor_devnoinfo
  Description:		����������ǰ���豸����Լ�����
  Input: 				
    1.devno			�豸���
    2.rule 			��Ź���
  Output:			��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_set_netdoor_devnoinfo(PFULL_DEVICE_NO devno, DEVICENO_RULE * rule);

/*************************************************
  Function:			logic_get_netdevice_devnoinfo
  Description:		��ȡ������ǰ���豸����Լ�����
  Input: 			
  Output:			
    1.devno			�豸���
    2.rule 			��Ź���
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_get_netdevice_devnoinfo(PFULL_DEVICE_NO devno, DEVICENO_RULE * rule);

/*************************************************
  Function:			logic_get_netdoor_version
  Description:		���������ǰ���ں˺ͳ���汾��
  Input: 			��
  Output:			
    1.KerVer		�ں˰汾��
  	2.BuildTime		����ʱ��
  	3.ver			����汾��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_get_netdoor_version(FWM_VERSION_T * KerVer, char * BuildTime, char * ver);

/*************************************************
  Function:			logic_mng_netdoor_card
  Description:		������Ϣ
  Input: 	
  	1.OperType		��������
    2.CardNo		����ָ��
  Output:			��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001/196609
  					ECHO_MAC:0x030009/196617
  					NETDOOR_ERR_SEND:0x030000/196608		
  Others:
*************************************************/
int32 logic_mng_netdoor_card(uint8 OperType, char * CardNo);

/*************************************************
  Function:			logic_get_netdevice_lockinfo
  Description:		�������Ϣ
  Input: 			��
  Output:			
  	1.LockType		������
  	2.LockTime		��ʱ��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001/196609
  					ECHO_MAC:0x030009/196617
  					NETDOOR_ERR_SEND:0x030000/196608		
  Others:
*************************************************/
int32 logic_get_netdevice_lockinfo(uint8 * LockType, int32 * LockTime);

/*************************************************
  Function:			logic_set_netdevice_lockinfo
  Description:		��������Ϣ
  Input: 	
  	1.LockType		������
    2.LockTime		��ʱ��
  Output:			��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001/196609
  					ECHO_MAC:0x030009/196617
  					NETDOOR_ERR_SEND:0x030000/196608		
  Others:
*************************************************/
int32 logic_set_netdevice_lockinfo(uint8 LockType, int32 LockTime);

/*************************************************
  Function:    		get_netdoor_mac
  Description:		���������ǰ����MAC��ַ
  Input: 			
    1.index			������ǰ����ID
  Output:			
	1.HWaddr		��õ�Ӳ����ַ
  Return:			�ɹ����, TRUE/FALSE
  Others:			�ڽ�����ǰ������ʱ���ȵ��ô˺���
*************************************************/
uint32 logic_get_netdoor_mac(uint8 index, unsigned char * HWaddr);

/*************************************************
  Function:			logic_set_netdoor_other_settings
  Description:		�����豸��������
  Input: 				
    1.OtherSettings	����ֵ 0:������,1:����
  Output:			��
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					���ݷ�������:0x030000
  Others:			�����СΪ10,�����һ��Ԫ��Ϊ�������õ�ֵ,
  					�ڶ���Ԫ��Ϊ�������õ�ֵ,������Ԫ��Ϊ����
  					���ĸ�Ԫ��Ϊ��Ƶ��ʽ
*************************************************/
uint32 logic_set_netdoor_other_settings(unsigned char * OtherSettings);

/*************************************************
  Function:			logic_get_netdoor_other_settings
  Description:		��������豸��������
  Input: 				
  Output:			
  	1.OtherSettings	��������ֵ
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					���ݷ�������:0x030000
  					����:0x0300**
  Others:			
*************************************************/
uint32 logic_get_netdoor_other_settings(unsigned char * OtherSettings);

/*************************************************
  Function:    		logic_netdoor_pub_ini
  Description:		��ʼ��:���������ǰ����ַ��MAC��ַ
  Input: 			��
  Output:			
  Return:			�ɹ����, TRUE/FALSE
  Others:			�����ն������ؽ�������֮ǰҪ���ô˺���
*************************************************/
uint32 logic_netdoor_pub_ini(uint8 index);

#ifdef _ADD_BLUETOOTH_DOOR_
/*************************************************
  Function:    		logic_netdoor_pub_ini
  Description:		��ʼ��:���������ǰ����ַ��MAC��ַ
  Input: 			��
  Output:			
  Return:			�ɹ����, TRUE/FALSE
  Others:			�����ն������ؽ�������֮ǰҪ���ô˺���
*************************************************/
uint32 logic_bluetoothdoor_pub_ini(uint8 index, uint32 NetdoorIp);

/*************************************************
  Function:			logic_get_bluetooth_door_sysinfo
  Description:		��ȡ������ǰϵͳ��Ϣ
  Input: 	
  Output:			
  	reccontent		��ǰ��������
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_get_bluetooth_door_sysinfo(char * data);

/*************************************************
  Function:			logic_get_bluetooth_door_sysinfo
  Description:		��ȡ������ǰ�������б�
  Input: 	
  Output:			
  	reccontent		��ǰ��������
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_get_bluetooth_door_room_list(PNET_BING_ROOM_LIST *prec_data);

/*************************************************
  Function:			logic_get_bluetooth_door_sysinfo
  Description:		����������ǰʱ��
  Input: 	
  Output:			
  	reccontent		��ǰ��������
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_set_bluetooth_door_time();

/*************************************************
  Function:			logic_get_bluetooth_door_record
  Description:		�鿴��ǰ���24Сʱ��¼����ʷ��¼
  Input: 	
    1.cmd			����
    2.index			��ȡ�ڼ�̨������ǰ��¼ 1:������ǰ1;   2:������ǰ2
    3.type 			��¼����
    4.start			��ʼ��¼��־
    5.num			��ȡ��¼����
  Output:			
  	1.recnum		��ǰ���ؼ�¼����
  	2.content		��ǰ��������
  Return:			ECHO_OK: 0
  					ECHO_ERROR:0x030001
  					ECHO_MAC:0x030009
  					����:0x0300**
  Others:
*************************************************/
int32 logic_get_bluetooth_door_record(NET_COMMAND cmd, uint8 index, uint8 type, uint32 start, uint32 num, PNET_RECORD_LIST *prec_data);

/*************************************************
  Function:			recv_bluetoothdoor_pic_start
  Description:		����������ǰץ��ͼƬ��ʼ(���ö������)
  Input: 	
  	1.recPacket		���հ�
  Output:			��
  Return:			��
  Others:
*************************************************/
void recv_bluetoothdoor_pic_start(const PRECIVE_PACKET recPacket);
#endif

#endif
