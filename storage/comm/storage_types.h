/*************************************************
  Copyright (C), 2006-2010, Aurine
  File name: 	storage_types.h
  Author:		xiewr
  Version:  	1.0
  Date: 
  Description:  �������Ͷ���

  History:        
    1. Date:	
       Author:	
       Modification:
    2. ...
*************************************************/
#ifndef _STORAGE_TYPES_H_
#define _STORAGE_TYPES_H_

#include "au_types.h"
#include "AppConfig.h"

#ifdef  __cplusplus
extern "C"
{
#endif

 #pragma pack(push,1)  								// ��ʼ�������ݰ�, ʹ���ֽڶ��뷽ʽ

// ����汾
typedef struct
{
	uint8	MajorVer;								// ���汾
	uint8	MinorVer;								// �ΰ汾
	uint16	BuildVer;								// build�汾
}SOFT_VERSION;

// �豸����1B������汾2b+�����С2B+�ļ�����50B
typedef struct 
{
	uint8 			DevType;
	SOFT_VERSION 	SoftVer;
	uint32 			FileSize;
	char 			FileName[50];
}SOFT_INFO, * PSOFT_INFO;							// ������ǰ���ϱ�����Ϣ

// ʱ��ṹ
typedef struct
{
	uint16		year;								// ��
	uint8		month;								// ��
	uint8		day;								// ��
	uint8		week;								// ����
	uint8		hour;								// Сʱ
	uint8		min;								// ��
	uint8		sec;								// ��
}DATE_TIME, *PDATE_TIME;

typedef struct
{
	uint32 year;
	uint8 month;
	uint8 day;
	uint8 hour;
	uint8 min;
	uint8 sec;	
	uint8 week;
}ZONE_DATE_TIME, * PZONE_DATE_TIME;					// ʱ��ṹ��

// ���ڻ��������ע�����Ϣ
typedef struct
{
	uint32 		Address;							// ������ַ
	uint16 		CmdPort;							// ����˿�
	uint16 		SipPort;							// Sip�˿�
	uint16 		AudioPort;							// ��Ƶ�˿�
	uint16 		VideoPort;							// ��Ƶ�˿�
}REG_DATA, *PREG_DATA;

typedef enum
{ 
	CHINESE = 0,
	CHNBIG5 = 1,
	ENGLISH = 2,
	MAX_LANGUAGE
}LANGUAGE_E;					// ��������

/**********************************************************************/
/*								��������							  */
/**********************************************************************/
typedef struct
{
	uint8 		b_write;							// �жϰ�����Ϣ�Ƿ��ʼ����	
	uint8   	defend_state;						// ����״̬,�ڼң������ҹ��

	// ������ʾҳ���������ݣ�һ���ֽڱ�ʾ�˷���(����ʱ��,��ʱ����ʱ��,���ͳ���)
	uint8 		enable;		   						// ���� ��ر�   
	uint8       is_24_hour;							// �Ƿ�24Сʱ����
	uint8		finder_state;						// ̽ͷ����(1-���� 0-����)
	uint8       can_hear;                           // ����
	uint8       can_see;  							// �ɼ�
	uint8   	area_type[8];						// ������Ӧ��ͼ������
	uint8       delay_time[8];            			// ��ʱ����ʱ��
	uint8   	alarm_time;							// ����ʱ��
	uint32      validate_code;						// ������֤��
	// �û�����ҳ������
	uint8		exit_alarm_time;				    // �˳�Ԥ��ʱ��
	uint8 		isolation;							// ��ʱ����	1 = ��ʱ����	
	uint8       part_valid;							// �Ƿ��Ǿַ���Ч 1 = ��Ч��0 = ��Ч
	uint8 		remote_set;							// bit0:Զ�̰�������,bit1:Զ�̳���,bit2:Զ�̲���,bit3:Զ�ַ̾�
	uint8       link_param;							// ��������
	uint8		link_scene[2];						// ���������龰ģʽ		
	uint8       used_exit_sound;					// �Ƿ�����Ԥ������
	uint8  		short_msg[2][15];  					// ���ź���
	uint8		alarm_num[2][15];					// ��������

	// ������ʾҳ�棬ֻ������һ��������ʾ
	uint8 		show_state[8];						// ����������ʾ״̬
}AF_FLASH_DATA, * PAF_FLASH_DATA;

/**********************************************************************/
/*								ϵͳ����							  */
/**********************************************************************/

/***********************����Ϊ��������ṹ����***********************/
#define DEFAULT_DEVICEIP				0XC0A8003A 	// ����IP  192.168.0.10
#define DEFAULT_SUBNET					0XFFFFFF00 	// �������� 255.255.255.0
#define DEFAULT_GATEWAY					0XC0A800FE 	// ���� 192.168.1.254

#define DEFAULT_DNS1					0X00 		// 0.0.0.0
#define DEFAULT_DNS2					0X00 		// 0.0.0.0
//#define DEFAULT_CENTERIP				0XC0A80002 	// ���ķ����� 192.168.0.2
#define DEFAULT_CENTERIP				0X00	 	// modi by chenbh 2015-03-25
//#define DEFAULT_MANAGERIP				0XC0A80003 	// ����Ա��1 192.168.0.3
#define DEFAULT_MANAGERIP				0X00	 	// modi by chenbh 2015-03-25
#define DEFAULT_SIPPROXYSERVER			0X00 		// 0.0.0.0
#define DEFAULT_DIANTISERVER			0x0A6E70EB  // ���ֵ��ݿ�����Ĭ��IP 10.110.112.235
#define DEFAULT_AURINESERVER			0xDCFA1E36  // ���ַ����� 220.250.30.54
#define DEFAULT_STUNSERVER				0X00 		// 0.0.0.0
#define DEFAULT_DEVICEIP1       		0X00  	   	// 0.0.0.0 
#define DEFAULT_SUBNET1         		0X00 		// 0.0.0.0   
#define DEFAULT_MANAGERIP1				0X00 		// ����Ա��2
#define DEFAULT_MANAGERIP2				0X00 		// ����Ա��3

typedef struct
{
	uint32	IP;										// �豸IP
	uint32	SubNet;									// ��������
	uint32	DefaultGateway;							// Ĭ������
	uint32	DNS1;									// DNS1������IP  DHCP��DNS1ͬIP
	uint32	DNS2;									// DNS2������IP  Ԥ��������
	uint32	CenterIP;								// ���ķ�����IP
	uint32	ManagerIP;								// ����Ա��IP
	uint32	SipProxyServer;							// SIP���������, DNS1�����������, ��ͬ
	uint32	AurineServer;							// ���ַ�����
	uint32	StunServer;								// Stun������
	uint32  IP1;          							// �豸IP1    
	uint32  SubNet1;        						// ��������1  
	uint32	ManagerIP1;								// ����Ա��2IP 
	uint32	ManagerIP2;								// ����Ա��3IP
	uint32	DiantiServer;							// ���ֵ��ݿ�����
	#ifdef _ETHERNET_DHCP_
	uint8	Enable;									// �Ƿ����þ�̬IP 0: ������ 1:����
	#endif
}NET_PARAM, * PNET_PARAM;

typedef struct
{
	uint32	IP;										// �豸IP
	uint32	SubNet;									// ��������
	uint32	DefaultGateway;							// Ĭ������
	uint32	DNS1;									// DNS1������IP  DHCP��DNS1ͬIP
	uint32	DNS2;									// DNS2������IP  Ԥ��������
	uint32	CenterIP;								// ���ķ�����IP
	uint32	ManagerIP;								// ����Ա��IP
	char	SipProxyServer[50];						// SIP���������, DNS1�����������, ��ͬ
	char	AurineServer[50];						// ���ַ�����
	char	StunServer[50];							// Stun������
	uint32  IP1;          							// �豸IP1      hyy��ӣ�2007.11.23
	uint32  SubNet1;        						// ��������1    hyy��ӣ�2007.11.23
}NET_PARAM_SEND,*PNET_PARAM_SEND;

typedef struct
{
	uint32	DoorIP1;								// ������ǰ��IP1
	uint32	DoorIP2;								// ������ǰ��IP1
}NET_DOOR_PARAM, * PNET_DOOR_PARAM;

typedef enum
{
    HOST_IPADDR = 0x00,												
	HOST_NETMASK,
	HOST_GATEWAY,	
	CENTER_IPADDR,
	MANAGER1_IPADDR,
	MANAGER2_IPADDR,
	MANAGER3_IPADDR,
	AURINE_IPADDR,
	DIANTI_IPADDR,
	RTSP_IPADDR,
	#ifdef _SEND_EVENT_TO_STAIR_
	STUN_IPADDR,
	#endif
	IP_MAX
}IP_TYPE;											// ���õ� IP ����

/***********************����Ϊ��������ṹ����***********************/

/***********************����Ϊ�豸��Žṹ����***********************/
#define DEFAULT_AREANO					1			// ���ţ�Ĭ��1
#define DEFAULT_DEVICENO1				0			// �豸��1��Ĭ��0

// modi by luofl 2012-02-13 ǰ����0�������Ļ���ʾ����
#define DEFAULT_DEVICENO2				10101010	// �豸��2��Ĭ��010101010

#define DEFAULT_RULE_STAIRNOLEN			4			// �ݺų��ȣ�Ĭ��4
#define DEFAULT_RULE_ROOMNOLEN			4			// ���ų��ȣ�Ĭ��4
#define DEFAULT_RULE_CELLNOLEN			2			// ��Ԫ�ų��ȣ�Ĭ��2	
#define DEFAULT_RULE_USECELLNO			1			// ������Ԫ��־��0��false 1��true�� Ĭ��1
#define DEFAULT_RULE_SUBSECTION			224			// �ֶβ�����0Ϊ���ֶΣ�Ĭ��224
#define DEFAULT_DEV_TYPE				0x32		// DEVICE_TYPE_ROOM	Ĭ���豸����
#define DEFAULT_DEVNO_LEN				(DEFAULT_RULE_STAIRNOLEN+DEFAULT_RULE_ROOMNOLEN+1)
#define DEFAULT_ISRIGHT					1
#define DEFAULT_DEVNO_STR				"010101010"	// Ĭ���豸���



// Ĭ���豸������ XX��XX��ԪXXXX��
#if 1
#define DEFAULT_DEV_DESC				{0xb6,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
									0xb5,0xa5,0xd4,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0xb7,\
									0xbf,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#else
#define DEFAULT_DEV_DESC				{0xb4,0xc9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
									0xb3,0xe6,0xa4,0xb8,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,\
									0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}

#endif

#ifdef _AU_PROTOCOL_
typedef struct
{
	uint32		DeviceNo1;							// �豸�Ÿ�λ��������999999999
	uint32		DeviceNo2;							// �豸�ŵ�λ��������999999999
}DEVICE_NO, *PDEVICE_NO;
#else
// �豸��ţ����ţ�
typedef struct
{
	uint8 		DeviceType;                         // �豸���� 
	uint8 		Resver;								// Ԥ��λ
	uint16 		AreaNo;								// С�����
	uint32		DeviceNo1;							// �豸�Ÿ�λ��������999999999
	uint32		DeviceNo2;							// �豸�ŵ�λ��������999999999
}DEVICE_NO, *PDEVICE_NO;
#endif

#ifdef	_USE_AURINE_SET_
typedef struct
{
	uint8 		DeviceType;                         // �豸���� 
	uint8 		Resver;								// Ԥ��λ
	uint16 		AreaNo;								// С�����
	uint32		DeviceNo1;							// �豸�Ÿ�λ��������999999999
	uint32		DeviceNo2;							// �豸�ŵ�λ��������999999999
}DEVICE_SET_NO, *PDEVICE_SET_NO;
#endif

// �豸��Ź���, ����ڴ洢ͷ�ļ��ж���
typedef struct
{
	uint8		StairNoLen;							// �ݺų��ȣ�Ĭ��4
	uint8		RoomNoLen;							// ���ų��ȣ�Ĭ��4
	uint8		CellNoLen;							// ��Ԫ�ų��ȣ�Ĭ��2
	uint8		UseCellNo;							// ������Ԫ��־��0��false 1��true�� Ĭ��1
	uint32		Subsection;							// �ֶβ�����0Ϊ���ֶΣ�Ĭ��224
}DEVICENO_RULE;

/*
|-----------|----------------|------------------------------------|-------------------------|
|�豸		|�豸�����ַ���	 |˵��								  |��ע                     |
|-----------|----------------|------------------------------------|-------------------------|
|���ڻ�		|xx-xx-xx-xx	 |����1B(1~99)-��Ԫ��1B(1~99)-���	  |1. ��x�� ����ʾ0��9������|
|			|				 |1B(1~99)-����1B(1~99)				  |						  	|
|-----------|----------------|------------------------------------|2. ��-�� ��Ϊ�ָ���ţ�ʵ|
|�ݿڻ�		|xx-xx-00-0x	 |����1B(1~99)-��Ԫ��1B(1~99)-0x00-	  |	���޴˷ָ��	      	|
|			|				 |�ݿڷֻ���1B(0~9)					  |                         |
|-----------|----------------|------------------------------------|3. DNS�����ѯ�豸IPʱ�� |
|���ڻ�		|00-00-01-xx	 |00-00-01-���1B(0��99),���һ����	  |	  ������Ϊ:�豸�����ַ�	|
|			|				 |�ڱ�ʾ���ڻ���ţ�00Ϊ�����ڣ���	  |   ����'.'+�����ַ�����  |
|			|				 |��Ϊ������						  |	  �����ɱ�����ã���� 	|
|-----------|----------------|------------------------------------|   ������������DNS������ |
|����Ա��	|00-00-02-xx	 |00-00-02-���1B(1��99),���һ����	  |	  �����ڲ�ͬ���ܾ����� 	|
|			|				 |�ڱ�ʾ����Ա�����				  |	                      	|
|-----------|----------------|------------------------------------|                         |
|������		|00-00-00-00	 |���������Ψһ					  |					  		|	
|-----------|----------------|------------------------------------|-------------------------|
*/

typedef struct
{
	uint32  AreaNo;	 								// С�����
	DEVICE_NO DeviceNo;								// �豸���
	DEVICENO_RULE Rule;								// �豸��Ź���
	uint8 DeviceType;								// �豸����
	uint8 DevNoLen;									// �豸�ų���
	uint8 IsRight;									// �����Ƿ�������ȷ
	char DeviceNoStr[20];							// �豸����ַ���
	uint8 Ret;										// ����λ
}FULL_DEVICE_NO,*PFULL_DEVICE_NO;	

// �豸����
typedef enum
{
	DEVICE_TYPE_NONE					= 0x00,	
	DEVICE_TYPE_AURINE_SERVER_COMM 		= 0x10,		// ���ַ�����
	DEVICE_TYPE_AURINE_SERVER_WEB		= 0x11,		// ����WEB������
	DEVICE_TYPE_AURINE_SERVER_SERVICE	= 0x12,		// ���ַ�����ϵͳ
	DEVICE_TYPE_AURINE_SERVER_STREAMINGSERVER = 0x13,  // ��ý�������
	DEVICE_TYPE_AURINE_SERVER_SMSMMSSERVER    = 0x14,  // SMS/MMS ������
	DEVICE_TYPE_CENTER					= 0x20,		// ���ķ�����
	DEVICE_TYPE_MANAGER,							// ����Ա��
	DEVICE_TYPE_UNIT_MANAGER,                       // ¥������Ա��
	DEVICE_TYPE_AREA					= 0x30,		// ���ڻ�
	DEVICE_TYPE_STAIR,								// �ݿڻ�
	DEVICE_TYPE_ROOM,								// ���ڻ�
	DEVICE_TYPE_FENJI_NET,							// ����ֻ�
	DEVICE_TYPE_AREA_ROXY,							// С������Ŀǰ�ƻ�DNS Server��DHCP Server������ͬһ̨�豸��
	DEVICE_TYPE_MEDIA_AD,							// ý�巢������沥��
	DEVICE_TYPE_PHONE					= 0x40,		// ��ͨ�绰
	DEVICE_TYPE_DOOR_PHONE,							// ��ǰ��(�绰)
	DEVICE_TYPE_DOOR_NET,							// ��ǰ��(����)
	DEVICE_TYPE_GATEWAY					= 0x50,		// ��ͥ����
	DEVICE_TYPE_IPCAMERA,							// IP Camera
	DEVICE_TYPE_IPC						= 0x70,		// ����IPC�豸
	DEVICE_TYPE_HOME_IPC				= 0x71		// �Ҿ�IPC�豸
}DEVICE_TYPE_E;
/***********************����Ϊ�豸��Žṹ����***********************/

/***********************����ΪMAC�����ṹ����***********************/
typedef enum
{
    HOUSE_MAC = 0x00,							// ����Ա����
	DOOR1_MAC,									// �û�����
	DOOR2_MAC									// �û���������
}MAC_TYPE;

typedef struct
{
	uint8 HouseMac[6];
	uint8 Door1Mac[6];
	uint8 Door2Mac[6];
}MAC_PARAM;
/***********************����ΪMAC�����ṹ����***********************/

/***********************����Ϊ��������ṹ����***********************/
#define MAX_ADMIN_LEN					6			
#define MAX_USER_LEN					5 		
#define MAX_DOOR_USER_LEN				5
#define MAX_DOOR_SERVER_LEN				5

typedef enum
{
    PASS_TYPE_ADMIN = 0x00,							// ����Ա����
	PASS_TYPE_USER,									// �û�����
	PASS_TYPE_DOOR_USER,							// �û���������
	PASS_TYPE_DOOR_SERVER,							// ������������	
	PASS_TYPE_SERVER,								// ��������
	PASS_TYPE_MAX
}PASS_TYPE;

typedef struct
{
	uint8 doorserverEnable;							// ������������ʹ��
	uint8 admin[MAX_ADMIN_LEN+1];					// ����Ա����
	uint8 user[MAX_ADMIN_LEN+1];					// �û�����
	uint8 door_user[MAX_ADMIN_LEN+1];				// �û���������
	uint8 door_server[MAX_ADMIN_LEN+1];				// ������������	
	uint8 userserverenb; 							// ��������ʹ��
	uint8 user_server[MAX_ADMIN_LEN+1];				// ��������	
}PASS_PARAM, *PPASS_PARAM;

/***********************����Ϊ��������ṹ����***********************/

/***********************����Ϊ���Բ����ṹ����***********************/
typedef enum
{
    LYLY_LINK_ALARMOUT = 0x00,						// �����������
	LYLY_LINK_ALARMNIGHT,							// ����ҹ������
	LYLY_LINK_NOFACE,								// �������������
	LYLY_LINK_MAX	
}LYLY_LINK_TYPE;

typedef enum
{
	LYLY_TYPE_AUDIO = 0x00,							// ����ģʽ
	LYLY_TYPE_PIC_AUDIO,							// Ӱ��ģʽ
	LYLY_TYPE_VIDEO,								// ��Ƶģʽ
    LYLY_TYPE_MAX		
}LYLY_TYPE;

typedef struct
{
	LYLY_TYPE Mode;									// ����ģʽ
	uint8 Enable;									// ����ʹ��
	uint8 Link[LYLY_LINK_MAX];						// ���Ե����� 1 ���� 0������
	uint8 default_tip;								// ���Ե�Ĭ����ʾ�� 0 Ĭ�� 1 �Զ�¼��
}LYLY_PARAM, *PLYLY_PARAM;

/***********************����Ϊ���Բ����ṹ����***********************/

/***********************����Ϊ����Ų����ṹ����**********************/
typedef enum
{
	NOFACE_TIME_30 = 0x00,
	NOFACE_TIME_60,
	NOFACE_TIME_120,
	NOFACE_TIME_180,
	NOFACE_TIME_300,
	NOFACE_TIME_480,
	NOFACE_TIME_MAX
}NOFACE_TIME;										// �����ʱ��

typedef struct
{
	uint8 noface;									// �����ʹ��
	NOFACE_TIME time;								// �����ʱ��
}NOFACE_PARAM, *PNOFACE_PARAM;						// ����Ų���
/***********************����Ϊ����Ų����ṹ����**********************/

/**********************����Ϊ�����������ṹ����*********************/
typedef enum
{
	EPHOTO_TIME_HALF = 0x00,
	EPHOTO_TIME_1,
	EPHOTO_TIME_3,
	EPHOTO_TIME_5,
	EPHOTO_TIME_10,
	EPHOTO_TIME_15,
	EPHOTO_TIME_30,
	EPHOTO_TIME_60,
	EPHOTO_TIME_120,
	EPHOTO_TIME_NEVER,
}EPHOTO_TIME;										// �������ʱ��

typedef struct
{
	uint8 used;										// �������ʹ��
	EPHOTO_TIME intime;								// ����������ʱ��
	EPHOTO_TIME holdtime;							// ������ᱣ��ʱ��
}EPHOTO_PARAM, *PEPHOTO_PARAM;						
/**********************����Ϊ�����������ṹ����*********************/

typedef enum
{
    EXT_MODE_ALARM = 0x00,							// ����ģ��
	EXT_MODE_NETDOOR1,								// ������ǰ��1ģ��
	EXT_MODE_NETDOOR2,								// ������ǰ��2ģ��
	EXT_MODE_PHONEDOOR1,							// ģ����ǰ�� 1
	EXT_MODE_PHONEDOOR2,							// ģ����ǰ�� 2
	EXT_MODE_JD,									// �ҵ�ģ��
	EXT_MODE_JD_FACTORY,							// �ҵ糧��
	EXT_MODE_GENERAL_STAIR,							// ͨ���ݿڻ�
	#ifdef _ADD_BLUETOOTH_DOOR_
	EXT_MODE_BLUETOOTHDOOR1,						// ������ǰ��1ģ��
	EXT_MODE_BLUETOOTHDOOR2,						// ������ǰ��2ģ��
	#endif
	EXT_MODE_MAX
}EXT_MODE_TYPE;

#define MAX_RING_VOLUME			8
#define MIN_RING_VOLUME			1
#define MAX_TALK_VOLUME			8
#define MIN_TALK_VOLUME			1
#define MIN_MIC_VOLUME			1
#define MAX_MIC_VOLUME			8

#define MAX_RING_TYPE			8					// ��������
#define MAX_RING_ID				8					// �������ID
#define MAX_MSG_ID				4					// �����ϢID
#define MAX_YJ_ID				4					// ���Ԥ��ID

/**********************����ΪIPģ������ṹ����*********************/
typedef struct
{
	uint32 	State;									// ��״̬: 0-δ�� 1-��
	uint32	BindCode;								// ������֤��
	uint32	IpAddr;									// IP��ַ
}IPMODULE_INFO,*PIPMODULE_INFO;						// IPģ����Ϣ
/**********************����ΪIPģ������ṹ����*********************/

typedef struct
{
	NET_PARAM Netparam;								// �������	
	FULL_DEVICE_NO 	Devparam;						// �豸���
	char DevDesc[70];								// �豸������
	PASS_PARAM Passparam;							// �������
	LYLY_PARAM Lylyparam;							// ���Բ���
	NOFACE_PARAM Nofaceparam;						// ����Ų���
	EPHOTO_PARAM Ephotoparam;						// ����������
	MAC_PARAM MacAddr;								// MAC���ַ
	uint8 Extparam[EXT_MODE_MAX];					// �ⲿģ��
	uint8 Bright;             						// ��������
	uint8 DeskId;									// ��������
	uint8 RingID[MAX_RING_TYPE];					// ����ID(�ݿ� ���� �ſ� ���� ס�� �ֻ� ��Ϣ Ԥ��)
	uint8 RingVolume;								// ����������С
	uint8 TalkVolume;								// ͨ��������С
	uint8 MicVolume;								// MIC����С
	uint8 KeyBeep;									// �Ƿ����ð����� 1 ����  0 ������
	uint32 RegCode;									// ƽ̨ע�����
	#ifdef _LIVEMEDIA_
	uint32 RtspServer;								// ��ý�������
	#endif
	#ifdef _IP_MODULE_
	IPMODULE_INFO IpModule;							// IPģ��
	#endif
	NET_DOOR_PARAM NetDoor;							// ������ǰ��IP
	LANGUAGE_E Language;							// ϵͳ����
	uint8 OpenScreen;								// �Ƿ��� 0:���� 1:������	
}SYS_FLASH_DATA, * PSYS_FLASH_DATA;					// ϵͳ����

/********************* ����Ϊ��ƵSDP���� ******************/
typedef struct
{
	uint8   encMode;				// ��Ƶ�����ʽ 0Ϊ��������
	uint8   frameRate;				// ��Ƶ֡��     0Ϊ��������
	uint8   imgSize;				// ��Ƶ�ֱ���   0Ϊ��������
	uint8   resver0;				// ����λ
	uint32  bitRate;				// ��Ƶ���� ��λ(kbps) 0��������
	uint32  resver1;				// ����λ
	uint32  resver2;				// ����λ
} VIDEO_SDP_PARAM, * PVIDEO_SDP_PARAM;

// ��Ƶ�����ʽ
typedef enum	
{
	VIDEO_ENCMODE_NONE 	= 0,
	VIDEO_ENCMODE_H264 	= 1
}VIDEO_ENCMODE_E;

// ��Ƶ�ֱ���
typedef enum
{
	VIDEO_SIZE_NONE		= 0,
	VIDEO_SIZE_QQVGA	= 1,
	VIDEO_SIZE_QCIF		= 2,
	VIDEO_SIZE_QVGA		= 3,
	VIDEO_SIZE_CIF		= 4,
	VIDEO_SIZE_VGA		= 5,
	VIDEO_SIZE_4CIF		= 6, //704*576
	VIDEO_SIZE_D1		= 7,
	VIDEO_SIZE_SVGA		= 8, //800*600
	VIDEO_SIZE_720P		= 9
}VIDEO_SIZE_E;

/********************* ����Ϊ��ƵSDP���� ******************/


/**************** ����Ϊ��ƵSDP���� ******************/
typedef struct
{
	uint8 encMode;			// ��Ƶ��ʽ 0Ϊ��������
	uint8 resver0;
	uint16 resver1;
	uint32 resver2;
}AUDIO_SDP_PARAM, * PAUDIO_SDP_PARAM;

// ��Ƶ��ʽ
typedef enum
{
	AUDIO_ENCMODE_NONE		= 0,
	AUDIO_ENCMODE_PCMA		= 1,
	AUDIO_ENCMODE_PCMU		= 2
}AUDIO_ENCMODE_E;

typedef struct __AU_VIDEO_CONFIG_S
{
	uint8 brightness;       // ���� 0-255
	uint8 contrast;			// �Աȶ� 0-255
	uint8 hue;				// ɫ�� 0-255
	uint8 saturation;		// ���Ͷ� 0-255
}AU_VIDEO_CONFIG_S;

/**************** ����Ϊ��ƵSDP���� ******************/

extern VIDEO_SDP_PARAM g_venc_parm;
extern AUDIO_SDP_PARAM g_audio_parm;
 
/*********************** ����Ϊ����汾��������״ֵ̬ **********************/
typedef enum
{
	ECHO_VER_UPG_OK				  = 0x00,           // ������������
	ECHO_VER_UPG_NOT_SUPPORT      = 0x01,		    // ��֧�ָ�����ģʽ
	ECHO_VER_UPG_HW_ERR           = 0x02,			// Ӳ���汾����
	ECHO_VER_UPG_SF_ERR			  = 0x03,			// ����汾�ϵͻ���ֲ
	ECHO_VER_UPG_FLIE_ERR		  = 0x04			// �����ļ�̫��

}ECHO_VER_STATE_E;
/*********************** ����Ϊ����汾��������״ֵ̬ **********************/

typedef struct
{
	DEVICE_NO 	deviceno;		// rtsp �������豸���
	uint32	  	ip;				// rtsp ������IP
	uint32 	  	comm_port;		// ����ͨѶ�˿�	
	uint32 		rtsp_port;		// rtsp �˿�
}RTSP_SERVER_INFO;

typedef struct 
{
	uint32 ip;					// �ϱ���ַ
	uint32 port;				// �ϱ��˿�
}RP_EVENT_SERVER_INFO;

extern RTSP_SERVER_INFO	 g_Rtsp_ServerInfo;
extern RP_EVENT_SERVER_INFO g_Event_Server;

#ifdef _APP_CALL_ELEVATOR_
typedef struct _stNetSubCtrlData
{
		uint32 systype;			// ���ͷ�ϵͳ����
		uint32 cmdtype;			// �������ͣ�͸��������ֵ��
		uint32 dire;			// ����
		uint32 seq;				// ���к�,�Զ�����
		uint32 dataSize;		// ���ݳ��ȣ�͸�������
		char * dataparam;		// ��������ݲ�����͸�������
}TunnelSendData;

typedef struct _stNetSubReplyData
{
		uint32 systype;			//Ӧ��ϵͳ����
		uint32 cmdtype;			// �������ͣ�͸��������
		uint32 dire;			// ����
		uint32 seq;				// ���к�,�ͷ��Ͱ���ͬ
		uint32 dataSize;		// ���ݳ���
		char * dataparam;		// ��������ݲ���
}TunnelReplayData;

typedef enum
{
	CMDTYPE_MEDIA			= 0xC1,
	CMDTYPE_ELEVATOR		= 0xC2,
}CMDTYPE;
#endif

#pragma pack(pop)  									// �����������ݰ�, �ָ�ԭ���뷽ʽ

#ifdef  __cplusplus
}
#endif

#endif

