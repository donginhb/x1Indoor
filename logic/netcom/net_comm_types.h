/*************************************************
  Copyright (C), 2006-2010, Aurine
  File name: 	net_comm_types.h
  Author:		xiewr
  Version:  	1.0
  Date: 
  Description:  ��������ͨѶЭ��_���Ͷ���
				˵������ϵͳö�����ͳ�����˵���⣬
				��������о�ת��Ϊunsigned char��
  History:        
    1. Date:	
       Author:	
       Modification:
    2. ...
*************************************************/
#ifndef _NET_COMM_TYPES_H_
#define _NET_COMM_TYPES_H_

//#include "typedef.h"
//#include "storage_types.h"
#include "storage_include.h"
//#include "logic_include.h"

#ifdef  __cplusplus
extern "C"
{
#endif
// �����־
#define DIR_SEND				0xAA 				// ����
#define DIR_ACK 				0x00 				// Ӧ��
#define DIR_DONOTHING           0xFF                // ������
#define SOCK_ADDR_SIZE			(sizeof(struct sockaddr_in))  			 // ��ַ����
#define NET_PACKBUF_SIZE		(1024*4)             					 // UDP�����ֵ

#ifdef _AU_PROTOCOL_
#define _SUB_PROTOCOL_ENCRYPT_	0x00									// ����Э�鲻����
#define _PROTOCOL_VER_ 			0x0200  								// Э��汾
#define	MAIN_NET_HEAD_SIZE		0										// ��Э�������ͷ����
#define	SUB_NET_HEAD_SIZE		(sizeof(NET_HEAD))						// ��Э�������ͷ����
#define	NET_HEAD_SIZE			(sizeof(NET_HEAD))	// �����ͷ����
#define MANAGER_NUM				50					// ����Ա����ʼ���
#define MANAGER_LEN				2					// ����Ա����ų���
#define SCREENSAVE_NUM			12					// ��������

#define NETCMD_UDP_PORT			20625 				// ͳһ������˿�,����Ϊӳ���Ķ˿�
#define	NETVIDEO_UDP_PORT		24010				// ��Ƶ�˿�
#define	NETAUDIO_UDP_PORT		24020				// ��Ƶ�˿�
#else
#define MAINPROTOCOL_VER        0x0801              // ��Э��汾
#define SUBPROTOCALTYPE         0x08 				// ��Э������
#define SUBPROTOCALPACKTYPE     0x00				// ��Э������ʽ
#define SUBPROTOCALECHO         0x00                // ��Э��Ӧ����

#if (_SUB_PROTOCOL_ENCRYPT_ == _ML_PROTOCOL_ENCRYPT_)
#define ENCRYPT_KEY		"ML80_20140315@yfzx.ml"
#elif (_SUB_PROTOCOL_ENCRYPT_ == _SD_PROTOCOL_ENCRYPT_)
#define ENCRYPT_KEY		"TFSUODI_20141201@yfzx.cn"
#elif (_SUB_PROTOCOL_ENCRYPT_ == _TF_PROTOCOL_ENCRYPT_)
#define ENCRYPT_KEY		"TF_20150201@tianfu.cn"
#elif (_SUB_PROTOCOL_ENCRYPT_ == _HY_PROTOCOL_ENCRYPT_)
#define ENCRYPT_KEY		"TFHUAYING_20160310@tianfu.cn"
#endif

#if (_SUB_PROTOCOL_ENCRYPT_ == _NO_PROTOCOL_ENCRYPT_)
#define ENCRYPT_KEY_LEN		0
#else
#define ENCRYPT_KEY_LEN		strlen(ENCRYPT_KEY)
#endif

//#define INADDR_BROADCAST 		0xffffffff

#define	MAIN_NET_HEAD_SIZE		(sizeof(MAIN_NET_HEAD))					// ��Э�������ͷ����
#define	SUB_NET_HEAD_SIZE		(sizeof(NET_HEAD))						// ��Э�������ͷ����
#define	NET_HEAD_SIZE			(sizeof(MAIN_NET_HEAD)+sizeof(NET_HEAD))// �����ͷ����
#define MANAGER_NUM				100					// ����Ա����ʼ���
#define MANAGER_LEN				3					// ����Ա����ų���
#define SCREENSAVE_NUM			6					// ��������

#define NETCMD_UDP_PORT			14301				// ͳһ������˿�,����Ϊӳ���Ķ˿�
#define	NETVIDEO_UDP_PORT		31410
#define	NETAUDIO_UDP_PORT		31420
#endif

#define NETCMD_ELEVATOR_PORT	8008				// ������Ȩ����˿�
#define NET_DATA_MAX			(NET_PACKBUF_SIZE-NET_HEAD_SIZE) 	// �����������
/***************************����Ϊö�����Ͷ���***********************/

// ��Э���������
typedef enum
{
	SUB_ENCRYPT_NONE           = 0x00,				// ������
	SUB_ENCRYPT_YH             = 0x01				// ���ʽ����
	
}SUB_PROTOCAL_ENCRYPT;

// ��Э�������
typedef enum
{
	MAIN_PACKTYPE_NORM			= 0x0000,				// ��ͨ��
	MAIN_PACKTYPE_TC			= 0xFFFF				// ͸����

}MAIN_PROTOCAL_PACKTYPE;

#ifdef _AU_PROTOCOL_
// ��ϵͳ����
typedef enum
{
	SSC_PUBLIC					= 0x00,				// ��������
	SSC_INTERPHONE				= 0x10,				// �Խ���������ͨ��
	SSC_IPPHONE					= 0x11,				// IP�绰
	SSC_PSTNPHONE				= 0x12,				// ��ͨ�绰
	SSC_ALARM					= 0x20,				// ����
	SSC_INFO					= 0x30,				// ��Ϣ
	SSC_EHOME					= 0x40,				// �ҵ�
	SSC_MULTIMEDIA				= 0x50,				// ��ý��
	SSC_ELIVE					= 0x60,				// E����
	SSC_OTHER					= 0x70,				// ��������
	SSC_VIDEOMONITORING 		= 0x75,		 	   	// ��Ƶ����
	SSC_IPDOORPHONE				= 0x80,				// ��ͥ���� add by luofl 2007-9-29
}SUB_SYS_CODE_E;
#else
//  ��ϵͳ����
typedef enum
{
	SSC_PUBLIC					= 0xFF,				// ��������
	SSC_INTERPHONE				= 0xF0,				// �Խ���������ͨ��
	SSC_ALARM					= 0xF5,				// ����
	SSC_INFO					= 0xE5,				// ��Ϣ
	SSC_EHOME					= 0xE0,				// �ҵ�
	SSC_MULTIMEDIA				= 0xD0,				// ��ý��
	SSC_ELIVE					= 0xD1,				// E����
	SSC_OTHER					= 0xD2,				// ��������
	SSC_VIDEOMONITORING 		= 0xC0,		 	   	// ��Ƶ����
	SSC_IPDOORPHONE				= 0xF1,				// ������ǰ��
	SSC_SOFTWARE 				= 0XB0				// ���������Э��
}SUB_SYS_CODE_E;
#endif

// ����Ӧ����
typedef enum
{
	ECHO_OK						= 0x00,				// ��ȷӦ��
	ECHO_ERROR					= 0x01,				// һ�����
	ECHO_BUSY					= 0x02,				// æӦ��
	ECHO_NO_RECORD				= 0x03,				// �������Ϣ������
	ECHO_UNALLOWDD				= 0x04,				// ������Զ�̿���
	ECHO_NO_APPLY				= 0x05,				// δ����÷��񣨻��޴˷���
	ECHO_CARD_FULL				= 0x06,				// ��������
	ECHO_HAVED					= 0x07,				// ��¼�Ѿ�����
	ECHO_OFFLINE				= 0x08,				// ��������
	ECHO_MAC					= 0x09,				// MAC�����
	ECHO_REPEAT					= 0x0A,				// �����ظ�
	ECHO_ALARM_ERROR			= 0x0B,				// ��������ʧ��, ��Ҫ���ڲ���ʱ�������������ڹ��ϡ�������״̬
	ECHO_NOT_SUPPORT			= 0x0C              // ��֧�ָ�ý�����
}ECHO_VALUE_E;

#if 0
// ����ִ���ߣ�����Զ�̿��ơ��ҵ�Զ�̿��ƣ�
typedef enum
{
	EXECUTOR_LOCAL_HOST			= 0x01,				// ��������
	EXECUTOR_REMOTE_DEVICE		= 0x02,				// ң����

	EXECUTOR_LOCAL_FJ			= 0x05,				// ��������ֻ�(���������նˡ���ͥPC)
	EXECUTOR_LOCAL_MNFJ			= 0x06,				// ����ģ��ֻ�

	EXECUTOR_MANAGER			= 0x10,				// ����Ա��
	EXECUTOR_STAIR				= 0x11,				// �ݿڻ�
	EXECUTOR_AREA				= 0x12, 			// ���ڻ�
	EXECUTOR_IE_USER			= 0x13,				// Զ��IEƽ̨
	EXECUTOR_SHORT_MSG			= 0x20,				// ס������
	EXECUTOR_PHONE_USER			= 0x21,				// ס���绰
	EXECUTOR_SERVER				= 0x22				// ���ķ�����
}EXECUTOR_E;
#endif

// �¼����ͷ�
typedef enum
{
	EST_AURINE					= 0x01,				// ���͵�����ƽ̨
	EST_SERVER					= 0x02,				// ���͵����ķ�����
	EST_MANAGER					= 0x03				// ���͵�����Ա��
}EVENT_SENDTO_E;

// ���Ͱ�״̬
typedef enum
{
	 SEND_STATE_SEND_READY		= 0,				// �ȴ�����
	 SEND_STATE_SENDING, 							// ���ڷ���
	 SEND_STATE_WAIT_ECHO,							// �ȴ�Ӧ��
	 SEND_STATE_RECIVED_ECHO,						// �յ�Ӧ���
	 SEND_STATE_ECHO_TIMEOUT						// Ӧ��ʱ	
}SEND_STATE_E;

// ��������ȼ�
typedef enum
{
	PRIRY_HIGHEST = 0x00,							//������ȼ���һ�����ڱ���
	PRIRY_REALTIME = 0x01,							//ʵʱ����翪����
	PRIRY_DEFAULT = 0xFF							//Ĭ�ϲ�����û�ж������ȼ��ģ�Ĭ����ò���
}PRIRY_TYPE_E;
/***************************����Ϊö�����Ͷ���***********************/

/***************************����Ϊ���������**************************/
// ���緢�Ͱ�
typedef struct SEND_PACKET_NODE
{
	struct SEND_PACKET_NODE * next;
	struct SEND_PACKET_NODE * prev;
	char SendState;									// ����״̬, ��TSendState
	char SendTimes; 								// ��ǰ���ʹ���
	char SendTimesMax; 								// ��෢�ʹ���
	int TimeOut;									// ���ͳ�ʱʱ��, ��
	int WaitCount; 									// �ȴ�ʱ�����
	uint32 address;									// �Է�IP��ַ
	uint16 port;									// �Է��˿ں�
	int size;										// ���ݰ���С
	char * data;									// ��������
}SEND_PACKET, *PSEND_PACKET;

// ������հ�
typedef struct RECIVE_PACKET_NODE
{
	struct RECIVE_PACKET_NODE * next;
	uint32 address;									// �Է�IP��ַ
	uint16 port;									// �Է��˿ں�
	int size;										// ���ݰ���С
	char * data;									// ��������
}RECIVE_PACKET, *PRECIVE_PACKET;
/***************************����Ϊ���������**************************/

/********************����Ϊ����������صĽṹ���Ͷ���************************/

// ��ʼ�������ݰ�, ʹ���ֽڶ��뷽ʽ
#pragma pack(push,1)  

// ��������ͷ ML80
typedef struct
{
	uint8 		subProtocolType;                   	// ��Э������
	uint8 		DirectFlag;							// �������־
	uint16 		mainProtocolType;					// ��Э��汾
	uint8 		hwEncrypt[16];						// Ӳ���豸��������
	uint32 		mainSeq;							// ���ݰ����к�
	uint8 		sysChipType;						// ϵͳоƬ����������
	uint8 		subProtocolPackType;				// ��Э��������
	uint8 		subProtocolEncrypt;					// ��Э���������
	uint8 		EchoValue;							// Ӧ����
	uint16	 	mainPacketType;						// ��Э�������
	uint16 		subPacketLen;                       // ��Э�������
} MAIN_NET_HEAD, *PMAIN_NET_HEAD;

#ifdef _AU_PROTOCOL_
// �����ͷ
typedef struct
{
	uint16		PackageID;							// ����ʶ
	uint16		ProtocolVer;						// Э��汾
	uint32		AreaCode;							// С�����
	DEVICE_NO	DeviceNo;							// �豸���
	uint8		DeviceType;							// �豸����
	uint8		DirectFlag;							// �����־��������0xAA��Ӧ��0x00��
	uint8		SubSysCode;							// ��ϵͳ����
	uint8		command;							// ����ֵ
	uint8		EchoValue;							// Ӧ����
	uint8		Encrypt;							// ��������
	uint16		DataLen;							// ���ݳ���
}NET_HEAD, *PNET_HEAD;
#else
typedef struct
{ 
	uint32		PackageID;                          // ����ʶ
	uint16 		ProtocolVer;						// Э��汾
	uint16 		Priry;								// �����ȼ�
	DEVICE_NO 	SrcDeviceNo;						// Դ�豸���
	DEVICE_NO 	DestDeviceNo;						// Ŀ���豸���
	//uint8 		Resver;								// ����λ
	uint8 		DeviceType;
	uint8 		DirectFlag;							// �����־
	uint8 		SubSysCode;							// ��ϵͳ����
	uint8		command;							// ����
	uint8		EchoValue;							// Ӧ����
	uint8 		Encrypt;							// ��������
	uint16 		DataLen;							//���ݳ���
}NET_HEAD, *PNET_HEAD;
#endif

// ����ʱ��ṹ��
typedef struct
{
	uint16 		year;
	uint8  		month;
	uint8  		day;
	uint8  		week;
	uint8  		hour;
	uint8  		min;
	uint8  		sec;
}NET_DATA_TIME, *PNET_DATA_TIME;

// ������������������
typedef enum
{
	NET_COMM_TYPE_NONE         = 0x00,        // ��
	NET_COMM_TYPE_CALL         = 0x01,		  // �Խ�����
	NET_COMM_TYPE_EVENT        = 0x02,		  // �Է����Ϊ���Ļ�
	NET_COMM_TYPE_CONTROL      = 0x03		  // �Է����Ϊ�㲥���
}NET_COMM_TYPE_E;
#pragma pack(pop)  									// �����������ݰ�, �ָ�ԭ���뷽ʽ
/********************����Ϊ����������صĽṹ���Ͷ���************************/

#ifdef __cplusplus
}
#endif
#endif 

