/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	storage_syssave.c
  Author:    	luofl
  Version:   	2.0
  Date: 		2014-10-02
  Description:  ϵͳ���ô洢(����ϵͳ�����Ͱ�������)

  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#include "storage_include.h"

#define SYSCONFIG_SIZE			(sizeof(SYSCONFIG))

#ifdef _ADD_BLUETOOTH_DOOR_
#if SCREEN_CAPTURE
#define DIR_PATH_NUM			15
#else
#define DIR_PATH_NUM			14
#endif
#else
#if SCREEN_CAPTURE
#define DIR_PATH_NUM			14
#else
#define DIR_PATH_NUM			13
#endif
#endif

// ���²���Ϊ�ָ��������ú�ʹ��
SYSCONFIG gRecoSysConfig =
{
    sizeof(SYSCONFIG),
	SaveMagicNumber1,			// �����ַ��������鿴�ṹ�������Ƿ���ȷ
	
    /**************************������������**************************/
    {1,							// b_write �жϰ��������Ƿ��ʼ����
    DIS_DEFEND,					// defend_state ����״̬
	0x00,						// enable ����������ر�,Ĭ��ȫ������������
	0x07,						// is_24_hour һ������������ΪĬ��Ϊ24Сʱ����,����һ�����̶�Ϊ24Сʱ����,���ɸ���
	0xFF,						// finder_state ̽ͷ״̬
	0xFE,						// can_hear ����(��������)
	0xFE,						// can_see �ɼ�(������������)
    {0, 1, 2, 3, 4, 5, 6, 7},	// area_type ������Ӧ��ͼ������
    {0, 0, 0, 1, 1, 0, 0, 0},	// delay_time ��ʱ����ʱ��
    1,							// alarm_time ����ʱ��
    0,							// ������֤��	
    0,							// exit_alarm_time �˳�Ԥ��ʱ��
    0,							// isolation ��ʱ����
    0xEF,						// part_valid �ַ���Ч
    0x00,						// remote_set Զ������
    0,							// link_param ������������
    {3, 4},
    1,							// �Ƿ�����Ԥ������
   	{{""}, {""}},				// ���ź���
   	{{""}, {""}},				// ��������
	// ��������״̬
    {WORK_SHOW_STATE, WORK_SHOW_STATE, WORK_SHOW_STATE, NORM_SHOW_STATE,
     NORM_SHOW_STATE, NORM_SHOW_STATE, NORM_SHOW_STATE, NORM_SHOW_STATE}},

	/**************************ϵͳ��������**************************/
	// �����������
	{{DEFAULT_DEVICEIP,			// IP �豸IP
	DEFAULT_SUBNET,				// SubNet ��������
	DEFAULT_GATEWAY, 			// DefaultGateway Ĭ������
	DEFAULT_DNS1,				// DNS1 DNS1������IP  DHCP��DNS1ͬIP
	DEFAULT_DNS2, 				// DNS2 DNS2������IP  Ԥ��������
	DEFAULT_CENTERIP,			// CenterIP ���ķ�����IP
	DEFAULT_MANAGERIP, 			// ManagerIP ����Ա��IP
	DEFAULT_SIPPROXYSERVER,		// SipProxyServer SIP���������, DNS1�����������, ��ͬ
	DEFAULT_AURINESERVER, 		// AurineServer ���ַ�����
	DEFAULT_STUNSERVER,			// StunServer Stun������
	DEFAULT_DEVICEIP1,			// IP1 �豸IP1    
	DEFAULT_SUBNET1,			// SubNet1 ��������1  
	DEFAULT_MANAGERIP1,			// ManagerIP1 ����Ա��2IP 
	DEFAULT_MANAGERIP2,			// ManagerIP2 ����Ա��3IP
	#ifdef _ETHERNET_DHCP_
	DEFAULT_DIANTISERVER,		// DiantiServer ���ֵ��ݿ�����
	1},							// �����þ�̬IP	
	#else
	DEFAULT_DIANTISERVER},		// DiantiServer ���ֵ��ݿ�����
	#endif

	// �豸����
	{DEFAULT_AREANO,			// AreaNo С�����
	#ifdef _AU_PROTOCOL_
	{
	#else
	{DEFAULT_DEV_TYPE,			// DeviceType �豸����
	0,							// Ԥ��λ
	DEFAULT_AREANO,				// С�����
	#endif
	DEFAULT_DEVICENO1,			// DeviceNo1 �豸�Ÿ�λ
	DEFAULT_DEVICENO2},			// DeviceNo2 �豸�ŵ�λ
	{DEFAULT_RULE_STAIRNOLEN,	// StairNoLen �ݺų��ȣ�Ĭ��4
	DEFAULT_RULE_ROOMNOLEN,		// RoomNoLen ���ų��ȣ�Ĭ��4
	DEFAULT_RULE_CELLNOLEN,		// CellNoLen ��Ԫ�ų��ȣ�Ĭ��2
	DEFAULT_RULE_USECELLNO,		// UseCellNo ������Ԫ��־��0��false 1��true�� Ĭ��1
	DEFAULT_RULE_SUBSECTION},	// Subsection �ֶβ�����0Ϊ���ֶΣ�Ĭ��224
	DEFAULT_DEV_TYPE,			// DeviceType �豸����
	DEFAULT_DEVNO_LEN,			// DevNoLen �豸�ų���
	DEFAULT_ISRIGHT,			// IsRight �����Ƿ�������ȷ
	DEFAULT_DEVNO_STR,			// DeviceNoStr �豸����ַ���
	0},							// ����λ
	DEFAULT_DEV_DESC,			// DevDesc �豸������

	// �������
	{0,							// doorserverEnable ������������ʹ��
	"123456",						// admin ����Ա����
	"12345",						// user �û�����, edit by xiewr 20101214, ��Ϊ"12345"
	"",							// door_user �û���������
	"",							// door_server ������������	
	0,							// userserverenb ��������ʹ��
	""},							// user_server��������	
	// ��Ӱ���Բ���
	{LYLY_TYPE_VIDEO, 			// Mode ����ģʽ
	1,							// Enable ����ʹ��
	{0, 0, 0},					// Link���Ե�����
	0},							// default_tip���Ե�Ĭ����ʾ�� 0 Ĭ�� 1 �Զ�¼��
	// �����
	{0,							// noface �����ʹ��
	NOFACE_TIME_30},			// time�����ʱ��
	// ����������
	{1,							// used �������ʹ��
	EPHOTO_TIME_1,				// intime ����������ʱ��
	EPHOTO_TIME_5},				// holdtime ������ᱣ��ʱ��
	// MAC���ַ
	{{00, 00, 00, 00, 00, 01},	// HouseMac ���ڻ�MAC��ַ
    {00, 00, 00, 00, 00, 02},	// Door1Mac ��ǰ��1MAC��ַ
    {00, 00, 00, 00, 00, 03}},	// Door2Mac ��ǰ��2MAC��ַ
	// ��������
	#ifdef _ADD_BLUETOOTH_DOOR_
	{1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
	#else
	{1, 1, 0, 0, 0, 1, 1, 0},	// Extparam �ⲿģ��
	#endif
    0,               			// Bright ���ȵ���
	0,               			// DeskId 0-������
    {0, 0, 0, 0, 0, 0, 0, 0},	// RingID ����ID(�ݿ� ���� �ſ� ���� ס�� �ֻ� ��Ϣ Ԥ��)
	4,
	4,							// TalkVolume ͨ��������С
	4,							// MICVolume ��ͷ���������С
	1,							// KeyBeep �Ƿ����ð�����
	0,							// ƽ̨ע��
	#ifdef _LIVEMEDIA_
	0,							// ��ý�������
	#endif
	#ifdef _IP_MODULE_
	{0, 0, 0},
	#endif
	{0, 0},						// ������ǰ��IP
	0,							// ϵͳ����
	0},							// Ĭ�Ͽ���

	/**************************��ƵSDP��������**************************/
	{VIDEO_ENCMODE_H264,		// ��Ƶ�����ʽ 0Ϊ��������
	20,							// ��Ƶ֡��     0Ϊ��������
	VIDEO_SIZE_VGA,				// ��Ƶ�ֱ���   0Ϊ�������� 		
	0,							// ����λ								
	2048000,					// ��Ƶ���� ��λ(kbps) 0��������
	0,							// ����λ
	0},							// ����λ

	/**************************��ƵSDP��������**************************/
	{AUDIO_ENCMODE_PCMA,		// ��Ƶ�����ʽ
	0,							// ����λ
	0,							// ����λ				
	0},							// ����λ
	
	SaveMagicNumber2,			// �����ַ��������鿴�ṹ�������Ƿ���ȷ
};

// ���²���Ϊ��һ����дʱ��
const SYSCONFIG  gInitSysConfig =
{
    sizeof(SYSCONFIG),
	SaveMagicNumber1,			// �����ַ��������鿴�ṹ�������Ƿ���ȷ
	
    /**************************������������**************************/
    {1,							// b_write �жϰ��������Ƿ��ʼ����
    SET_DEFEND,					// defend_state ����״̬
	0xFF,						// enable ����������ر�,Ĭ��ȫ������������
	0x07,						// is_24_hour һ������������ΪĬ��Ϊ24Сʱ����,����һ�����̶�Ϊ24Сʱ����,���ɸ���
	0xFF,						// finder_state ̽ͷ״̬
	0xFF,						// can_hear ����(��������)
	0xFF,						// can_see �ɼ�(������������)
    {0, 1, 2, 3, 4, 5, 6, 7},	// area_type ������Ӧ��ͼ������
    {0, 0, 0, 0, 0, 0, 0, 0},	// delay_time ��ʱ����ʱ��
    1,							// alarm_time ����ʱ��
    0,							// ������֤��	
    0,							// exit_alarm_time �˳�Ԥ��ʱ��
    0,							// isolation ��ʱ����
    0xEF,						// part_valid �ַ���Ч
    0x00,						// remote_set Զ������
    0,							// link_param ������������
    {3, 4},
    1,							// �Ƿ�����Ԥ������
   	{{""}, {""}},				// ���ź���
   	{{""}, {""}},				// ��������
	// ��������״̬
    {WORK_SHOW_STATE, WORK_SHOW_STATE, NORM_SHOW_STATE, NORM_SHOW_STATE,
     NORM_SHOW_STATE, NORM_SHOW_STATE, NORM_SHOW_STATE, NORM_SHOW_STATE}},

	/**************************ϵͳ��������**************************/
	// �����������
	{{DEFAULT_DEVICEIP,			// IP �豸IP
	DEFAULT_SUBNET,				// SubNet ��������
	DEFAULT_GATEWAY, 			// DefaultGateway Ĭ������
	DEFAULT_DNS1,				// DNS1 DNS1������IP  DHCP��DNS1ͬIP
	DEFAULT_DNS2, 				// DNS2 DNS2������IP  Ԥ��������
	DEFAULT_CENTERIP,			// CenterIP ���ķ�����IP
	DEFAULT_MANAGERIP, 			// ManagerIP ����Ա��IP
	DEFAULT_SIPPROXYSERVER,		// SipProxyServer SIP���������, DNS1�����������, ��ͬ
	DEFAULT_AURINESERVER, 		// AurineServer ���ַ�����
	DEFAULT_STUNSERVER,			// StunServer Stun������
	DEFAULT_DEVICEIP1,			// IP1 �豸IP1    
	DEFAULT_SUBNET1,			// SubNet1 ��������1  
	DEFAULT_MANAGERIP1,			// ManagerIP1 ����Ա��2IP 
	DEFAULT_MANAGERIP2,			// ManagerIP2 ����Ա��3IP
	#ifdef _ETHERNET_DHCP_
	DEFAULT_DIANTISERVER,		// DiantiServer ���ֵ��ݿ�����
	1},							// �����þ�̬IP	
	#else
	DEFAULT_DIANTISERVER},		// DiantiServer ���ֵ��ݿ�����
	#endif

	// �豸����
	{DEFAULT_AREANO,			// AreaNo С�����
	#ifdef _AU_PROTOCOL_
	{
	#else
	{DEFAULT_DEV_TYPE,			// DeviceType �豸����
	0,							// Ԥ��λ
	DEFAULT_AREANO,				// С�����
	#endif
	DEFAULT_DEVICENO1,			// DeviceNo1 �豸�Ÿ�λ
	DEFAULT_DEVICENO2},			// DeviceNo2 �豸�ŵ�λ
	{DEFAULT_RULE_STAIRNOLEN,	// StairNoLen �ݺų��ȣ�Ĭ��4
	DEFAULT_RULE_ROOMNOLEN,		// RoomNoLen ���ų��ȣ�Ĭ��4
	DEFAULT_RULE_CELLNOLEN,		// CellNoLen ��Ԫ�ų��ȣ�Ĭ��2
	DEFAULT_RULE_USECELLNO,		// UseCellNo ������Ԫ��־��0��false 1��true�� Ĭ��1
	DEFAULT_RULE_SUBSECTION},	// Subsection �ֶβ�����0Ϊ���ֶΣ�Ĭ��224
	DEFAULT_DEV_TYPE,			// DeviceType �豸����
	DEFAULT_DEVNO_LEN,			// DevNoLen �豸�ų���
	DEFAULT_ISRIGHT,			// IsRight �����Ƿ�������ȷ
	DEFAULT_DEVNO_STR,			// DeviceNoStr �豸����ַ���
	0},							// ����λ
	DEFAULT_DEV_DESC,			// DevDesc �豸������

	// �������
	{0,							// doorserverEnable ������������ʹ��
	"123456",						// admin ����Ա����
	"12345",						// user �û�����, edit by xiewr 20101214, ��Ϊ"12345"
	"",							// door_user �û���������
	"",							// door_server ������������	
	0,							// userserverenb ��������ʹ��
	""},							// user_server��������	
	// ��Ӱ���Բ���
	{LYLY_TYPE_VIDEO, 			// Mode ����ģʽ
	1,							// Enable ����ʹ��
	{0, 0, 0},					// Link���Ե�����
	0},							// default_tip���Ե�Ĭ����ʾ�� 0 Ĭ�� 1 �Զ�¼��
	// �����
	{0,							// noface �����ʹ��
	NOFACE_TIME_30},			// time�����ʱ��
	// ����������
	{1,							// used �������ʹ��
	EPHOTO_TIME_1,				// intime ����������ʱ��
	EPHOTO_TIME_5},				// holdtime ������ᱣ��ʱ��
	// MAC���ַ
	{{00, 00, 00, 00, 00, 0x6F},// HouseMac ���ڻ�MAC��ַ
    {00, 00, 00, 00, 00, 02},	// Door1Mac ��ǰ��1MAC��ַ
    {00, 00, 00, 00, 00, 03}},	// Door2Mac ��ǰ��2MAC��ַ
	// ��������
	#ifdef _ADD_BLUETOOTH_DOOR_
	{1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
	#else
	{1, 1, 0, 0, 0, 1, 1, 0},	// Extparam �ⲿģ��
	#endif
    0,               			// Bright ���ȵ���
	0,               			// DeskId 0-������
    {0, 0, 0, 0, 0, 0, 0, 0},	// RingID ����ID(�ݿ� ���� �ſ� ���� ס�� �ֻ� ��Ϣ Ԥ��)
	4,
	4,							// TalkVolume ͨ��������С
	4,							// MICVolume ��ͷ���������С
	1,							// KeyBeep �Ƿ����ð�����
	0,							// ƽ̨ע��
	#ifdef _LIVEMEDIA_
	0,							// ��ý�������
	#endif
	#ifdef _IP_MODULE_
	{0, 0, 0},
	#endif
	{0, 0},						// ������ǰ��IP
	0,							// ϵͳ����
	0},							// Ĭ�Ͽ���
	
	/**************************��ƵSDP��������**************************/
	{VIDEO_ENCMODE_H264,		// ��Ƶ�����ʽ 0Ϊ��������
	20,							// ��Ƶ֡��     0Ϊ��������
	VIDEO_SIZE_VGA,				// ��Ƶ�ֱ���   0Ϊ�������� 		
	0,							// ����λ								
	2048000,					// ��Ƶ���� ��λ(kbps) 0��������
	0,							// ����λ
	0},							// ����λ

	/**************************��ƵSDP��������**************************/
	{AUDIO_ENCMODE_PCMA,		// ��Ƶ�����ʽ
	0,							// ����λ
	0,							// ����λ				
	0},							// ����λ
	
	SaveMagicNumber2,			// �����ַ��������鿴�ṹ�������Ƿ���ȷ
};

/*************************************************
  Function:		check_sysconfig_ifcorrect
  Description: 	У�������Ƿ���ȷ
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void check_sysconfig_ifcorrect(void)
{

	if (gpSysConfig->MagicNumber1 == SaveMagicNumber1 
		&& gpSysConfig->MagicNumber2 == SaveMagicNumber2)
	{
		log_printf("the data of sysconfig is correct!!!!!!!!!!!!!!!!! \n");
	}
	log_printf("gpSysConfig->MagicNumber1 : %x\n", gpSysConfig->MagicNumber1);	
	log_printf("gpSysConfig->MagicNumber2 : %x\n", gpSysConfig->MagicNumber2);
}

/*************************************************
  Function:		get_sysconfig_from_storage
  Description: 	��FLASH�л�ȡϵͳ���ò���
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void get_sysconfig_from_storage(PSYSCONFIG list)
{
	if (list)
	{
		Fread_common(SYSCONFIG_PARAM_PATH, list, SYSCONFIG_SIZE, 1);
	}
}

/*************************************************
  Function:		save_sysconfig_to_storage
  Description: 	ϵͳ���ò������浽FLASH��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static ECHO_STORAGE save_sysconfig_to_storage(PSYSCONFIG list)
{
	ECHO_STORAGE ret = ECHO_STORAGE_ERR;
	
	if (list)
	{
		ret =  Fwrite_common(SYSCONFIG_PARAM_PATH, list, SYSCONFIG_SIZE, 1);
	}
	
	return ret;
}

#if 0
/*************************************************
  Function:		storage_free_sysconfig_memory
  Description: 	�ͷ�ϵͳ���ò�����ռ�õ��ڴ�
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void storage_free_sysconfig_memory(PSYSCONFIG list)
{
	if (list)
	{
		free(list);	
		list = NULL;
	}
}
#endif

/*************************************************
  Function:		storage_malloc_sysconfig_memory
  Description: 	����ϵͳ���ò������ڴ�
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void storage_malloc_sysconfig_memory(PSYSCONFIG * list)
{
	* list = (PSYSCONFIG)malloc(SYSCONFIG_SIZE);
}		

/*************************************************
  Function:		create_sys_dir
  Description:	����ϵͳ�����Ŀ¼
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void create_sys_dir(void)
{	
	int32 i;
	char dir_path[DIR_PATH_NUM][50] = {
		{CFG_PUBLIC_DRIVE},
		{CFG_PRIVATE_DRIVE},
		{SYSCONFIG_DIR_PATH}, 
		{CALL_DIR_PATH}, 
		{AF_DIR_PATH},
		{MSG_DIR_PATH},
		{MSG_VOICE_PATH},
		{SNAP_DIR_PATH},
		{LYLY_DIR_PATH},
		{JRLY_DIR_PATH},
		{JD_DIR_PATH},
		{YUYUE_DIR_PATH},
		#if SCREEN_CAPTURE
		{SCREEN_CAP_DIR_PATH},
		#endif
		#ifdef _ADD_BLUETOOTH_DOOR_
		{DOOR_PIC_DIR_PATH},
		#endif
		{MONITOR_DIR_PATH}};

	// Ŀ¼�������򴴽�
	for (i = 0; i < DIR_PATH_NUM; i++)
	{
		if ((is_fileexist(dir_path[i])) == FALSE)	
		{
			mkdir(dir_path[i], 0x777);
			log_printf("mkdir %s\n", dir_path[i]);
		}
	}
}

/*************************************************
  Function: 	SaveRegInfo
  Description:	����ע���-ϵͳ���ò���
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void SaveRegInfo(void)
{
	save_sysconfig_to_storage(gpSysConfig);
}

/*************************************************
  Function:    	storage_recover_factory
  Description: 	�ָ���������
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void storage_recover_factory(void)
{
	// ɾ��NAND1-2�ϵ�Ŀ¼���ļ�
	system("rm -rvf /mnt/nand1-2/*");
	system("sync");

	// MAC�벻�ָ�
	memcpy(gRecoSysConfig.SysFlashData.MacAddr.HouseMac, gpSysParam->MacAddr.HouseMac, sizeof(gpSysParam->MacAddr.HouseMac));
	memcpy(gRecoSysConfig.SysFlashData.MacAddr.Door1Mac, gpSysParam->MacAddr.Door1Mac, sizeof(gpSysParam->MacAddr.Door1Mac));
	memcpy(gRecoSysConfig.SysFlashData.MacAddr.Door2Mac, gpSysParam->MacAddr.Door2Mac, sizeof(gpSysParam->MacAddr.Door2Mac));

	// ���Բ��ָ�
	gRecoSysConfig.SysFlashData.Language = gpSysParam->Language;
	storage_init_get_dev_desc(gRecoSysConfig.SysFlashData.DevDesc, gpSysParam->Language);
	memcpy(gpSysConfig, &gRecoSysConfig, sizeof(SYSCONFIG));
	SaveRegInfo();
}

/*************************************************
  Function:    	storage_format_system
  Description: 	��ʽ��NAND1-2��
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void storage_format_system(void)
{
	// ɾ��NAND1-2�ϵ�Ŀ¼���ļ�
	system("rm -rvf /mnt/nand1-2/INFO/");
	system("rm -rvf /mnt/nand1-2/SNAP/");
	system("rm -rvf /mnt/nand1-2/LYLY/");
	#ifndef _AU_PROTOCOL_
    system("rm -rvf /mnt/nand1-2/JRLY/");
    system("rm -rvf /mnt/nand1-2/JD/");
    system("rm -rvf /mnt/nand1-2/RECORD/");
	system("rm -rvf /mnt/nand1-2/ALARM/");
    system("rm -rvf /mnt/nand1-2/MONITOR/");
    system("rm -rvf /mnt/nand1-2/YUYUE/");
	#endif
	#ifdef _ADD_BLUETOOTH_DOOR_
	system("rm -rvf /mnt/nand1-2/BLEDOORPIC/");
	#endif
	create_sys_dir();
	system("sync");
}

/*************************************************
  Function:		storage_init_sysconfig
  Description: 	��ʼ��ϵͳ����
  Input:		��
  Output:		��
  Return:		ECHO_STORAGE
  Others:
*************************************************/
void storage_init_sysconfig(void)
{
	create_sys_dir();
	storage_malloc_sysconfig_memory(&gpSysConfig);
	if (is_fileexist(SYSCONFIG_PARAM_PATH) == FALSE)
	{
		if (gpSysConfig)
		{
			memcpy(gpSysConfig, &gInitSysConfig, sizeof(SYSCONFIG));
			SaveRegInfo();
		}
	}
	else
	{
		get_sysconfig_from_storage(gpSysConfig);
	}
	gpAfParam = &gpSysConfig->AfFlashData;
	gpSysParam = &gpSysConfig->SysFlashData;
	
	memset(&g_venc_parm, 0, sizeof(VIDEO_SDP_PARAM));
	memcpy(&g_venc_parm, &gpSysConfig->VideoSdpData, sizeof(VIDEO_SDP_PARAM));
	
	memset(&g_audio_parm, 0, sizeof(AUDIO_SDP_PARAM));
	memcpy(&g_audio_parm, &gpSysConfig->AudioSdpData, sizeof(AUDIO_SDP_PARAM));
}

