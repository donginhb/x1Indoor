/*********************************************************
  Copyright (C), 2006-2010, Aurine
  File name:	logic_pubsetcmd.h
  Author:   	wufn
  Version:   	
  Date: 		
  Description:  ��������
  
  History:                   
    1. Date:			 
       Author:				
       Modification:	
    2. ...
*********************************************************/
#ifndef __LOGIC_PUBSETCMD_H__
#define __LOGIC_PUBSETCMD_H__

//#include "logic_net_comm.h"
#include "logic_include.h"
#include "storage_include.h"

//�������ʹ���
typedef enum
{
	DATA_ID_SYSPARAM	= 1,		// ϵͳ����
	DATA_ID_SECUPARAM	= 2,		// ��������
	DATA_ID_ELECPARAM	= 3,		// �ҵ����
	DATA_ID_ELEVATORLIST = 4,		// �����б�
	DATA_ID_CAMERALIST	= 5,		// ����ͷ�б�
	DATA_ID_STAIRPARAM	= 6,		// �ݿ����ò���
}FUNCTION_CODE_E;

typedef enum
{
	LAN_BIG5	= 1028,				// ����
	LAN_ENGLISH = 1033,				// Ӣ��
	LAN_CHINESE = 2052,				// ����
}WORLD_LANGUAGE_E;					// �������Ա�ʾ

typedef enum
{
	OPER_RECOVER = 0X00,			// �ָ�����
	OPER_REBOOT  = 0X01,			// ����
}TERMINAL_OPER_E;					// ��������

#pragma pack(push,1) 

//�������
typedef struct
{
	uint32	IP;						// �豸IP��Ĭ��10.100.1.4
	uint32	SubNet;					// �������룬Ĭ��255.255.255.0
	uint32	DefaultGateway;			// Ĭ�����أ�Ĭ��10.100.1.254
	uint32	DNS1;					// DNS1��������Ĭ��0.0.0.0
	uint32	DNS2;					// DNS2��������Ĭ��0.0.0.0
	uint32	CenterIP;				// ���ķ�����IP��Ĭ��0.0.0.0
	uint32	RtspServerIP;			// RTSP��������Ĭ��0.0.0.0
	uint32	ManagerIP[8];			// ����Ա��IP�����8̨��Ĭ��0.0.0.0
	uint32  NetdoorIP[2];        	// ������ǰ����Ĭ��0.0.0.0
}NET_SETPARAM,*PNET_SETPARAM;	

//ϵͳ������Ϣ
typedef struct
{
	NET_SETPARAM NetParam;			// �������
	#ifdef	_USE_AURINE_SET_
	DEVICE_SET_NO DeviceNo;
	#else
	DEVICE_NO DeviceNo;				// �豸���
	#endif
	DEVICENO_RULE DeviceRule;		// ��Ź���

	char ProjectPwd[8];				// �������룬Ĭ��13572468
	uint8 ExtModule[8];				// �ⲿģ�飺�ҵ����������ǰ��1����ǰ��2
									// ��ǰ��3����ǰ��4��֧��ͨ���ݿڻ�
									// ���ý��վ��鹦�ܡ����ý���SOS����	
	uint16 language;				// ����
	uint8 LockType;					// ������: 0 ���� 1 ���� , Ĭ�ϳ���
	uint8 LockTime;					// ������

	uint8 NetComm;					// �Ƿ���������ͨ��
	uint8 IsCallConvert;			// �Ƿ����ת��	
	char ConvertNumber[20];			// ת���豸��
	uint16 Reserver2;				// Ԥ��

	char HardwareVer[64];			// Ӳ���汾
	char SoftwareVer[64];			// ����汾
	char Mac[6];					// mac��
}SYSTEM_SETINFO;					// ����Ӧ��

//��������
typedef struct
{
	uint8 Enable;				// �Ƿ�����
	uint8 ProbeType;			// ̽ͷ���ͣ�0-7		
	uint8 DelayTime;			// �ӳ�ʱ�� 			
	uint8 IsPartValid;			// �Ƿ�ַ���Ч
	uint8 Is24Hour;				// �Ƿ�24Сʱ����
	uint8 IsSee;				// �Ƿ�ɼ�
	uint8 IsSound;				// �Ƿ����
	uint8 ProbeState;			// ̽ͷ״̬��0 ���� 1 ����
}SECU_ZONEINFO;

//�ҵ��豸��Ϣ
typedef struct
{
	uint8	JdType;				// �豸���ͣ���EHOME_TYPE_E����
	uint8	Index;				// �豸�����ţ���0��ʼ
	uint16	Address;			// �豸��ַ(bit7-15:��;bit0-7:��)��Ĭ��0
	char	Name[30];			// ���ƣ�Ĭ��Ϊ��
	uint8	IsUsed;				// �Ƿ�����(1:���ã�0:δ��)��Ĭ�ϲ�����
	uint8	IsTune;				// �Ƿ�ɵ���(�ƹ⣺���⣬�յ�������)��Ĭ�ϲ��ɵ�
}ELEC_DEVINFO;

//����������ṹ
typedef struct 
{
    uint8 	Enable;        		//�Ƿ����ã�Ĭ�ϲ�����
	char 	DeviceName[32];		//�豸���ƣ�Ĭ��Ϊ��
	uint32 	DeviceIP;			//�豸IP��Ĭ��Ϊ0.0.0.0
	uint16	DevPort	;			//�豸�˿ڣ�Ĭ��Ϊ80
	uint16	Channel;			//ͨ�����룬Ĭ��0
	char 	FactoryName[12];    //�豸�������ƣ�Ĭ��Ϊ��
	char 	UserName[16];		//�豸��½�û�����Ĭ��Ϊ��
	char 	Password[16];		//�豸��½���룬Ĭ��Ϊ��
	uint32	CanControlPTZ; 		//��̨�ɿر�־(0: ���ɿ��ƣ�1:�ɿ���)��Ĭ�ϲ��ɿ�
	int      IsOnline;			//�Ƿ����� ���޷��ж����ߵ�Ĭ�Ϲ̶�Ϊ���ߣ�
								//<0: �޷�ȷ�����߷�0�����ߣ�1������
}NEWHOMECAMERA;

#pragma pack(pop)  									// �����������ݰ�, �ָ�ԭ���뷽ʽ

#endif

