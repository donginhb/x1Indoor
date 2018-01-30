/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	AppConfig.h
  Author:     	luofl
  Version:    	2.0
  Date: 
  Description:  N32926������ʵ�ֵĹ��ܣ�ͨ���궨����������Ӧ�Ĺ��ܣ�
  				#define	_ELEVATOR_MODE_				// ������Ȩ����
  				#define _DOOR_PHONE_				// ģ����ǰ��
*************************************************/
#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__

#define DEBUG_PRINT				1

//#define AEC_DEBUG									// �����������ļ�
#define SCREEN_CAPTURE			0					// ��Ļ��ͼ,���¿�������һ�ű�����D���С�
#define SCREEN_CHECK			0					// ��ĻУ������
#define _USE_RGB32_				

// ====������ʾ������========================================
#define MSG_HIT_VOL				4
#define AF_HIT_VOL				4
#define LYLY_VIEW_VOL			8//6
#define MSG_VIEW_VOL			4
#define AVI_PLAY_VOL			60
#define MP3_PLAY_VOL			60
#define JRLY_VOLUME				8//6
#define RING_OUT_VOL			8//6

// ==== ϵͳ���������� =========================================
#define RK2918					11
#define RK3066					12
#define RK2818					13
#define RV1108					14
#define Cx92755					21
#define Hi3515					31
#define N32926					92
#define X1						41

#define SYYCHIPTYPE				X1

// ====����ṹ��(��ͬ�ṹ�����ȼ���ͬ)=====================
#define ML8_V6S					1
#define ML8_V7S					2
#define AH8_E81S				3

// ====�汾����================================================
#define ML8_V6S_JHB_VER			1					// ML8_V6S
#define ML8_V7S_JHB_VER			2					// ML8_V7S
#define AH8_E81S_JHB_VER		3					// AH8_E81S


#define SYS_TYPE				AH8_E81S_JHB_VER

// ====��Ļ�ֱ���================================================
#define _LCD_1024600_			1					//1024*600
#define	 _LCD_800480_			2					//800*480

#define _LCD_DPI_				_LCD_1024600_


// ====UI��ʽ����================================================
#define _V6_UI_STYLE_			1
#define _E81S_UI_STYLE_			2

#if (SYS_TYPE == AH8_E81S_JHB_VER)
#define _UI_STYLE_				_E81S_UI_STYLE_
#elif (SYS_TYPE == ML8_V7S_JHB_VER)
#define _UI_STYLE_				_V6_UI_STYLE_	
#elif (SYS_TYPE == ML8_V6S_JHB_VER)
#define _UI_STYLE_				_V6_UI_STYLE_	
#endif



// Ӳ��������Ҳ���ǳ��̴���
#define _TYSET_HWENCRYPT_		0XFF5459FF			// ������ʹ�õ�ͨ�ó��Ҵ���
#define _ML_HWENCRYPT_			0X00004753			// ����ʹ�õ�Ӳ��������
#define _TF_HWENCRYPT_			0X54460000			// �츻ʹ�õ�Ӳ��������
#define _ZH_HWENCRYPT_			0X00005A48			// �к�ʹ�õ�Ӳ��������
#define _SD_HWENCRYPT_			0X54465344			// ����ʹ�õ�Ӳ��������
#define _HY_HWENCRYPT_			0X54464859			// �츻��ӥ��Ӳ��������

// Э��汾��
#define _ML_PROTOCOL_VER_		0X0101				// ����Э��汾
#define _TF_PROTOCOL_VER_		0XA0AF				// �츻Э��汾
#define _ZH_PROTOCOL_VER_   	0XA101				// �к�Э��汾
#define _SD_PROTOCOL_VER_		0XA001				// ����Э��汾
#define _HY_PROTOCOL_VER_		0XA0A1				// ��ӥЭ��汾

// Э���������,��ͬ�ļ��������в�ͬ��KEY, 0-������
#define _NO_PROTOCOL_ENCRYPT_   0x00				// Э�鲻����
#define _TF_PROTOCOL_ENCRYPT_ 	0xAF				// �츻Э���������
#define _SD_PROTOCOL_ENCRYPT_   0xA0				// ����Э���������
#define _HY_PROTOCOL_ENCRYPT_   0xA1				// ��ӥЭ���������


// ====���汾���ܶ���============================================
//-----------��������------------------
//#define _JD_MODE_									// �ҵ�ģ��
//#define	_YUYUE_MODE_							// ����ԤԼ����
#define _SHOW_USED_JDDEV_ONLY_						// �ҵ���ƺ��龰���ý���ֻ��ʾ���õ��豸
#define _USE_ELEVATOR_								// ���õ��ݿ�����
#define _TY_STAIR_									// ֧��ͨ���ݿڻ�
#define _AURINE_ELEC_NEW_                           // add by fanfj�����¹��ּҵ�
#define _DIANTI_CALL_								// �������ݹ���
#define _IP_MODULE_									// IPģ��
//#define _LIVEMEDIA_								// RTSPģ��
//#define _MULTI_CENTER_							// ������
#define _USE_NEW_CENTER_							// ʹ���°汾���ķ�����
#define _SEND_SDP_PARAM_							// �Ƿ���ý�����
//#define _RTSP_REG_KEEP_							// RTSP��������(Ŀ�Ļ�ȡ��������ͷ�����б�)
#define _TIMER_REBOOT_NO_LCD_           			// ��ʱ����ʱ��������
//#define _UPLOAD_PHOTO_							// ������ǰ�������ϴ�����
//#define _NEVER_CLOSE_LCD_							// ���ôӲ�����
#undef _JD_MODE_
#undef _YUYUE_MODE_
#undef _LIVEMEDIA_
#undef _MULTI_CENTER_
#undef _RTSP_REG_KEEP_

//-----------���汾���칦��-------------
#if (SYS_TYPE == ML8_V6S_JHB_VER)
#define _HW_ENCRYPT_			_ML_HWENCRYPT_			// �ð汾ʹ�õ�Ӳ��������
#define _PROTOCOL_VER_			_ML_PROTOCOL_VER_		// �ð汾ʹ�õ�Э��汾
#define _SUB_PROTOCOL_ENCRYPT_  _NO_PROTOCOL_ENCRYPT_	// Э���������,�����汾������

#define HARD_VER_COMM		    "SNV641-100201"
#define JIEGOU_TYPE				ML8_V6S
#define _ALARM_IO_										// ����ֱ����IO��

#elif (SYS_TYPE == ML8_V7S_JHB_VER)
#define _HW_ENCRYPT_			_ML_HWENCRYPT_			// �ð汾ʹ�õ�Ӳ��������
#define _PROTOCOL_VER_			_ML_PROTOCOL_VER_		// �ð汾ʹ�õ�Э��汾
#define _SUB_PROTOCOL_ENCRYPT_  _NO_PROTOCOL_ENCRYPT_	// Э���������,�����汾������

#define HARD_VER_COMM		    "SNV741-100201"
#define JIEGOU_TYPE				ML8_V7S
#define _ALARM_IO_										// ����ֱ����IO��
#define _CP2526_TOUCH_KEY_								// ���ø�Ӧ���������

#elif (SYS_TYPE == AH8_E81S_JHB_VER)
#define _AU_PROTOCOL_									// ʹ�ù���Э��
#define _UPLOAD_PHOTO_									
#define JIEGOU_TYPE				AH8_E81S
#define _ALARM_IO_										// ����ֱ����IO��	
#define _USE_TIME_SET_									// �Ƿ�����ʱ������

#define	 SOFTSUBVER				"AH8-E81S"
#define HARDSUBVER				"E81S"

#define _TIMER_REBOOT_NO_LCD_           				// ��ʱ����ʱ��������
#define _CP2526_TOUCH_KEY_								// ���ø�Ӧ���������
#define _USE_AURINE_SET_								// �Ƿ����ù���Э�����ù���
//#define _TEST_REBOOT_									// ����һֱ����
#undef _USE_NEW_CENTER_	
#undef _IP_MODULE_	

#endif

#ifdef _IP_MODULE_
#define _IP_MODULE_DJ_									// IPģ��Խ�
#define _IP_MODULE_ALARM								// ��������
#ifdef _JD_MODE_
#define _IP_MODULE_JD_									// IPģ��ҵ�
#endif
//#define _IP_MODULE_RTSP_								// RTSPע��
#endif



//-----------Ӳ���汾------------------
#ifndef HARD_VER_COMM
#define HARD_VER_COMM		    "X1-"
#endif

//----------����汾---------------------
#ifndef SOFT_VER_COMM
#define SOFT_VER_COMM		    "V2.03.0001_"
#endif

#define BUILD_TIME				__TIME__ "_" __DATE__

#ifndef HARDSUBVER
#define HARDSUBVER				"-REL"
#endif

#ifndef SOFTSUBVER
#define SOFTSUBVER				BUILD_TIME
#endif

#define HARD_VER				(HARD_VER_COMM HARDSUBVER)
#define SOFT_VER				(SOFT_VER_COMM SOFTSUBVER)
#define SDK_VER					BUILD_TIME

#endif

