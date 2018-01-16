/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	storage_path.h
  Author:		luofl
  Version:		2.0
  Date: 		2014-10-02
  Description:	�洢·��

  History:		  
	1. Date:
	   Author:
	   Modification:
	2. ...
*************************************************/
#ifndef __STORAGE_PATH_H__
#define __STORAGE_PATH_H__


/**************************************************************************/
/*				����·������·����Ϊ��·������Ŀ¼ 						  */	
/**************************************************************************/
#define SOFTWARE_VER_PATH		"/etc/firmVer"									// ����汾·��
#define HARDWARE_VER_PATH		"/etc/chipVer"									// �̼��汾·��
#if 0
#define CFG_PUBLIC_DRIVE		"/sdcard/user/nand-2"						// ��ż�¼ ��ʱ�ļ�
#define CFG_PRIVATE_DRIVE		"/sdcard/user/nand-1"						// ϵͳ���� ��Ҫ�ļ�
#define CFG_RES_DRIVE			"/sdcard/user/res/"							// ��Դ�ļ� ����ԭ���ʹ��ڵ�·��
#else
#define CFG_PUBLIC_DRIVE		"/nand/user/nand-2"								// ��ż�¼ ��ʱ�ļ�
#define CFG_PRIVATE_DRIVE		"/nand/user/nand-1"								// ϵͳ���� ��Ҫ�ļ�
#define CFG_RES_DRIVE			"/nand/user/res/"								// ��Դ�ļ� ����ԭ���ʹ��ڵ�·��
#endif



/**************************************************************************/
/*							��Դ�ļ�·��								  */	
/**************************************************************************/
#define UI_PIC_DIR_PATH			CFG_RES_DRIVE"/app/"							// uiͼƬ��Դ·��
#define AUDIO_RES_DIR_PATH		CFG_RES_DRIVE"/ring/"							// ����·��



// ��������
#define CALL_RING1_PATH			AUDIO_RES_DIR_PATH"/Ring/RING1.WAV"			// ����1
#define CALL_RING2_PATH			AUDIO_RES_DIR_PATH"/Ring/RING2.WAV"			// ����2
#define CALL_RING3_PATH			AUDIO_RES_DIR_PATH"Ring/RING3.WAV"			// ����3
#define CALL_RING4_PATH			AUDIO_RES_DIR_PATH"Ring/RING4.WAV"			// ����4
#define CALL_RING5_PATH			AUDIO_RES_DIR_PATH"Ring/RING5.WAV"			// ����5
#define CALL_RING6_PATH			AUDIO_RES_DIR_PATH"Ring/RING6.WAV"			// ����6
#define CALL_RING7_PATH			AUDIO_RES_DIR_PATH"Ring/RING7.WAV"			// ����7
#define CALL_RING8_PATH			AUDIO_RES_DIR_PATH"Ring/RING8.WAV"			// ����8
#define CALL_RINGOUT_PATH		AUDIO_RES_DIR_PATH"Ring/RINGOUT.WAV"		// ������


// ������ʾ��·��
#define AF_YJ_PATH				AUDIO_RES_DIR_PATH"Alarm/YUJING.WAV"		// Ԥ������·��
#define AF_BJ_PATH				AUDIO_RES_DIR_PATH"Alarm/BAOJING.WAV"		// ��������·��
#define AF_YJ_WC_PATH			AUDIO_RES_DIR_PATH"Alarm/YJ_WC.WAV"			// Ԥ���ġ������غ��š�������
#define AF_YJQ_PATH				AUDIO_RES_DIR_PATH"Alarm/YJQ.WAV"			// ����ʱ�о���������ʾ����ע���о��顱
#define AF_FQCF_PATH			AUDIO_RES_DIR_PATH"Alarm/FQCF.WAV"			// "�����������ܲ���"��������ʾ
#define AF_JJYJC_PATH			AUDIO_RES_DIR_PATH"Alarm/JJYJC.WAV"			// ���г�����������ʾ����ã������ѽ��
#define AF_WANAN_PATH			AUDIO_RES_DIR_PATH"Alarm/WANAN.WAV"			// ���оַ�ʱ������ʾ����
#define AF_ZONE1_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE1.WAV"			// ��ע���о���, 1��������
#define AF_ZONE2_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE2.WAV"	
#define AF_ZONE3_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE3.WAV"	
#define AF_ZONE4_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE4.WAV"	
#define AF_ZONE5_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE5.WAV"	
#define AF_ZONE6_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE6.WAV"	
#define AF_ZONE7_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE7.WAV"	
#define AF_ZONE8_PATH			AUDIO_RES_DIR_PATH"Alarm/ZONE8.WAV"	
// Ӣ����ʾ��·��
#define AF_YJ_WC_PATH_E			AUDIO_RES_DIR_PATH"Alarm/YJ_WC_E.WAV"		// Ԥ���ġ������غ��š�������
#define AF_YJQ_PATH_E			AUDIO_RES_DIR_PATH"Alarm/YJQ_E.WAV"		// ����ʱ�о���������ʾ����ע���о��顱
#define AF_FQCF_PATH_E			AUDIO_RES_DIR_PATH"Alarm/FQCF_E.WAV"		// "�����������ܲ���"��������ʾ
#define AF_JJYJC_PATH_E			AUDIO_RES_DIR_PATH"Alarm/JJYJC_E.WAV"		// ���г�����������ʾ����ã������ѽ��
#define AF_WANAN_PATH_E			AUDIO_RES_DIR_PATH"Alarm/WANAN_E.WAV"		// ���оַ�ʱ������ʾ����
#define AF_ZONE1_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE1_E.WAV"		// ��ע���о���, 1��������
#define AF_ZONE2_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE2_E.WAV"	
#define AF_ZONE3_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE3_E.WAV"	
#define AF_ZONE4_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE4_E.WAV"	
#define AF_ZONE5_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE5_E.WAV"	
#define AF_ZONE6_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE6_E.WAV"	
#define AF_ZONE7_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE7_E.WAV"	
#define AF_ZONE8_PATH_E			AUDIO_RES_DIR_PATH"Alarm/ZONE8_E.WAV"	

// Ԥ����ʾ��
#define AF_YJ1_PATH				AUDIO_RES_DIR_PATH"Alarm/YUJING1.WAV"		// Ԥ����ʾ��1
#define AF_YJ2_PATH				AUDIO_RES_DIR_PATH"Alarm/YUJING2.WAV"		// Ԥ����ʾ��2
#define AF_YJ3_PATH				AUDIO_RES_DIR_PATH"Alarm/YUJING3.WAV"		// Ԥ����ʾ��3
#define AF_YJ4_PATH				AUDIO_RES_DIR_PATH"Alarm/YUJING4.WAV"		// Ԥ����ʾ��4

// ��Ϣ��ʾ��
#define MSG_HIT1_PATH			AUDIO_RES_DIR_PATH"Hit/MSG1.WAV"			// ��Ϣ��ʾ��1
#define MSG_HIT2_PATH			AUDIO_RES_DIR_PATH"Hit/MSG2.WAV"			// ��Ϣ��ʾ��2
#define MSG_HIT3_PATH			AUDIO_RES_DIR_PATH"Hit/MSG3.WAV"			// ��Ϣ��ʾ��3
#define MSG_HIT4_PATH			AUDIO_RES_DIR_PATH"Hit/MSG4.WAV"			// ��Ϣ��ʾ��4

// ������ʾ��
#define LYLY_HIT_CN_PATH		AUDIO_RES_DIR_PATH"Hit/LYLYCN.WAV"			// Ĭ������������ʾ��
#define LYLY_HIT_EN_PATH		AUDIO_RES_DIR_PATH"Hit/LYLYEN.WAV"			// Ĭ��Ӣ��������ʾ��



/**************************************************************************/
/*							ϵͳ�洢�ļ�·��							  */	
/**************************************************************************/
#define SYSCONFIG_DIR_PATH		CFG_PRIVATE_DRIVE"/SYSCONFIG/"   				// ϵͳ����·��
#define CALL_DIR_PATH			CFG_PUBLIC_DRIVE"/RECORD/"   					// �Խ���·��
#define AF_DIR_PATH				CFG_PUBLIC_DRIVE"/ALARM/"						// ����·��
#define MSG_DIR_PATH			CFG_PUBLIC_DRIVE"/INFO/"						// ��Ϣ�ļ���
#define MSG_VOICE_PATH			CFG_PUBLIC_DRIVE"/INFO/VOICE/"					// ��Ϣ�����ļ�
#define SNAP_DIR_PATH			CFG_PUBLIC_DRIVE"/SNAP/"						// ץ���ļ���		
#define LYLY_DIR_PATH			CFG_PUBLIC_DRIVE"/LYLY/"						// ��Ӱ�����ļ���		
#define JRLY_DIR_PATH			CFG_PUBLIC_DRIVE"/JRLY/"						// ���������ļ���
#define JD_DIR_PATH				CFG_PUBLIC_DRIVE"/JD/"						// �ҵ��ļ���
#define YUYUE_DIR_PATH			CFG_PUBLIC_DRIVE"/YUYUE/"						// ԤԼ�ļ�
#define MONITOR_DIR_PATH		CFG_PUBLIC_DRIVE"/MONITOR/"				
#define SCREEN_CAP_DIR_PATH		CFG_PUBLIC_DRIVE"/SCREEN_CAP/"				
#define DOOR_PIC_DIR_PATH		CFG_PUBLIC_DRIVE"/BLEDOORPIC/"					// ������ǰ�����ϴ�ͼƬ�ļ���		


// ϵͳ���ô洢(����ϵͳ�����Ͱ�������)
#define SYSCONFIG_PARAM_PATH	SYSCONFIG_DIR_PATH"/PARAM.BIN"   				// ϵͳ���ò���


// �Խ�
#define CALL_IN_PATH			CALL_DIR_PATH"/IN.BIN"   						// �Խ������¼
#define CALL_OUT_PATH			CALL_DIR_PATH"/OUT.BIN"  						// �Խ�������¼
#define CALL_MISS_PATH			CALL_DIR_PATH"/MISS.BIN" 						// �Խ�δ�Ӽ�¼


// ����
#define AF_CZ_REC_PATH			AF_DIR_PATH"/CZREC.BIN"						// ����������¼
#define AF_BJ_REC_PATH			AF_DIR_PATH"/BJBRE.BIN"						// ����������¼


// ��Ϣ
#define MSG_MANAGE_PATH			MSG_DIR_PATH"/MANAGE.BIN"						// ��Ϣ�����ļ�


// ץ��
#define SNAP_MANAGE_PATH		SNAP_DIR_PATH"/MANAGE.BIN"						// ץ�Ĺ����ļ�


// ��Ӱ����
#define LYLY_MANAGE_PATH		LYLY_DIR_PATH"/MANAGE.BIN"						// ��Ӱ���Թ����ļ�
#define LYLY_HIT_RE_PATH		LYLY_DIR_PATH"/LYLY.WAV"						// ¼��������ʾ��


// ��������
#define JRLY_MANAGE_PATH		JRLY_DIR_PATH"/MANAGE.BIN"						// �������Թ����ļ�


// �ҵ�
#define JD_LIGHT_VALUE_PATH     JD_DIR_PATH"/ALIGHT.BIN"
#define JD_KONGTIAO_VALUE_PATH  JD_DIR_PATH"/AKONGTIAO.BIN"
#define JD_DEVICE_LIGHT_PATH	JD_DIR_PATH"/LIGHT.BIN"						// �ҵ�ƹ�����ļ�
#define JD_DEVICE_WINDOW_PATH	JD_DIR_PATH"/WINDOW.BIN"						// �ҵ細�������ļ�
#define JD_DEVICE_KONGTIAO_PATH	JD_DIR_PATH"/KONGTIAO.BIN"						// �ҵ�յ������ļ�
#define JD_DEVICE_POWER_PATH	JD_DIR_PATH"/POWER.BIN"						// �ҵ��Դ�����ļ�
#define JD_DEVICE_GAS_PATH		JD_DIR_PATH"/GAS.BIN"							// �ҵ�ú�������ļ�
#define JD_SCENE_PATH			JD_DIR_PATH"/SCENE"							// �ҵ��龰�����ļ�
#define JD_AURINE_SCENE_PATH    JD_DIR_PATH"/ASCENE.BIN"
#ifdef _AIR_VOLUME_MODE_
#define JD_KONGTIAO_VOLUME_PATH  JD_DIR_PATH"/VOLUMEKONGTIAO.BIN"				// ����
#endif


// ԤԼ
#define YUYUE_MANAGE_PATH		YUYUE_DIR_PATH"/YUYUE.BIN"						// ԤԼ�б�


// ��Ƶ����
#define HOME_CAMERA_PATH		MONITOR_DIR_PATH"/HOME_CAMERA.BIN"	
#define COMMUNITY_CAMERA_PATH	MONITOR_DIR_PATH"/COMMUNITY_CAMERA.BIN"

#define MONITOR_DOOR_PATH		MONITOR_DIR_PATH"/MONITOR_DOOR.BIN"	
#define MONITOR_STAIR_PATH		MONITOR_DIR_PATH"/MONITOR_STAIR.BIN"	
#define MONITOR_AREA_PATH		MONITOR_DIR_PATH"/MONITOR_AREA.BIN"	

// ����ע��ɹ��豸���
#ifdef _USE_NEW_CENTER_
#define PRE_DEVNO_FILENAME		CFG_PUBLIC_DRIVE"/pre_devno.dat"				
#endif

// ������ǰ�������ϴ�ͼƬ����
#ifdef _ADD_BLUETOOTH_DOOR_
#define DOOR_PIC_1_PATH			DOOR_PIC_DIR_PATH"/BLEDOORPIC1.BIN"				// ������ǰ�����ϴ�ͼƬ�����ļ�
#define DOOR_PIC_2_PATH			DOOR_PIC_DIR_PATH"/BLEDOORPIC2.BIN"				// ������ǰ�����ϴ�ͼƬ�����ļ�
#endif

// ��Ƶ��������
#define VIDEO_PARAM_PATH		CFG_PRIVATE_DRIVE"/VIDEO_PARAM.INI"				
#endif 

