/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	Logic_audio.c
  Author:		luofl
  Version:		2.0
  Date: 		2015-03-21
  Description:	��Ƶ�������
  
  History:		  
	1. Date:
	   Author:
	   Modification:
	2. ...
*************************************************/
#ifndef _AU_AUDIO_H_
#define _AU_AUDIO_H_
#include "logic_include.h"


#define _SW_AEC_				0			// �Լ���˾��������
#define _HW_AEC_				1			// Ӳ����������������������������
#define _AEC_TYPE_				_HW_AEC_




// ������
typedef enum auAIO_SAMPLE_RATE_E
{
    AIO_SAMPLE_RATE_8       = 8000,     /* 8 k Hz sampling rate.     */
    AIO_SAMPLE_RATE_11025   = 11025,    /* 11.025 k Hz sampling rate.*/
    AIO_SAMPLE_RATE_16      = 16000,    /* 16 k Hz sampling rate.    */
    AIO_SAMPLE_RATE_22050   = 22050,    /* 22.050 k Hz sampling rate.*/
    AIO_SAMPLE_RATE_24      = 24000,    /* 24 k Hz sampling rate.    */
    AIO_SAMPLE_RATE_32      = 32000,    /* 32 k Hz sampling rate.    */
    AIO_SAMPLE_RATE_441     = 44100,    /* 44.1 k Hz sampling rate.  */
    AIO_SAMPLE_RATE_48      = 48000,    /* 48 k Hz sampling rate.    */
    AIO_SAMPLE_RATE_64      = 64000,    /* 64 k Hz sampling rate.    */
    AIO_SAMPLE_RATE_882     = 88000,    /* 88.2 k Hz sampling rate.  */
    AIO_SAMPLE_RATE_96      = 96000,    /* 96 k Hz sampling rate.    */
    AIO_SAMPLE_RATE_1764    = 176400,   /* 176.4 k Hz sampling rate. */
    AIO_SAMPLE_RATE_192     = 192000,   /* 192 k Hz sampling rate.   */
    AIO_SAMPLE_RATE_BUTT
} AIO_SAMPLE_RATE_E;

// ����λ��
typedef enum auAIO_BIT_WIDTH_E
{
    AIO_BIT_WIDTH_8   = 8,   			/* 8-bit sampling bitwidth.  */
    AIO_BIT_WIDTH_16  = 16,  			/* 16-bit sampling bitwidth. */
    AIO_BIT_WIDTH_20  = 20,   			/* 20-bit sampling bitwidth. */
    AIO_BIT_WIDTH_24  = 24,   			/* 24-bit sampling bitwidth. */
    AIO_BIT_WIDTH_BUTT
}AIO_BIT_WIDTH_E;


// ��Ƶ״̬ģʽ
typedef enum
{
	AS_NONE			= 0x00,							// �ر�״̬
	AS_NETTALK		= 0x01,							// ����ͨ��״̬
	AS_PLAY			= 0x02,							// ��������ģʽ
	AS_HINT_LYLY 	= 0x04,							// ����������ʾ��ģʽ
	AS_JRLY_RECORD  = 0x08,							// ����¼��ģʽ
	AS_CLOUD_TALK	= 0x10,							// �ƶ˶Խ�
}AUDIO_STATE_E;			

// ��Ƶ����
typedef struct
{	
	bool isPack;								
	float AiAgc;
	float AoAgc;
}AUDIO_PARAM, * PAUDIO_PARAM;

typedef void (*PMEDIA_AU_CALLBACK)(uint32 cmd, uint32 time, uint32 percent);

// �ļ���ʽ
typedef enum
{
	FILE_NONE				= 0x00,
	FILE_TXT				= 0x01,
	FILE_BMP				= 0x02,
	FILE_JPG				= 0x03,
	FILE_GIF				= 0x04,
	FILE_PNG				= 0x05,
	FILE_FLASH				= 0x06,
	FILE_MP3				= 0x20,
	FILE_WAVE				= 0x21,	
	FILE_AAC				= 0x22,
	FILE_MP4				= 0x23,
	FILE_ASF				= 0x24,
	FILE_BUTT				= 0xFF
}FILE_TYPE_E;

// ����˳�򼰴���
typedef enum
{
    AR_ONCE,										// ���β���
    AR_REPEAT,										// ����ѭ��
    AR_ALLONCE,										// ˳�򲥷�
    AR_ALLREPEAT,									// ѭ������
    AR_TRY											// ����
}AUDIO_REPEAT_E;

// ��Ƶģʽ
typedef enum
{
	AM_CLOSE,										// �ر�ģʽ
	AM_NET_TALK,									// ����ͨ��ģʽ
	AM_NET_REC,										// ����¼����Ӱ����ģʽ
	AM_NET_PLAY,									// ����������ʾ��ģʽ
	AM_LOCAL_REC,									// ��������ģʽ
	AM_LOCAL_PLAY,									// ��������ģʽ
	AM_LYLY_PLAY									// ��Ӱ���Բ���
}AUDIO_MODE_E;	

typedef void (*AudioPlay_CallBack)(int cmd, int time, int percent);

// ��Ƶ�ļ����Ų���
typedef struct
{
	char filename[50];					// �ļ�����(����·��)
	uint8 IsRepeat;						// �Ƿ�ѭ��
	FILE_TYPE_E FileType;				// �ļ�����
	AudioPlay_CallBack callback;		// �ļ����Żص�����
}AUDIOPLAY_PARAM, *PAUDIOPLAY_PARAM;

/*************************************************
  Function:    	audio_dec_enable
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int audio_dec_enable(void);

/*************************************************
  Function:    		audio_dec_disable
  Description: 		
  Input:		��
  Output:		��
  Return:		��	
  Others:
*************************************************/
int audio_dec_disable(void);

/*************************************************
  Function:    	audio_ai_enable
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int audio_ai_enable(void);

/*************************************************
  Function:    		audio_ai_disable
  Description: 		
  Input:		��
  Output:		��
  Return:		��	
  Others:
*************************************************/
int audio_ai_disable(void);

/*************************************************
  Function:    		audio_aec_enable
  Description: 		
  Input:		
  Output:			��
  Return:			��		
  Others:
*************************************************/
int audio_aec_enable(void);

/*************************************************
  Function:    		audio_aec_disable
  Description: 		
  Input:		
  Output:			��
  Return:			��		
  Others:
*************************************************/
int audio_aec_disable(void);

/*************************************************
  Function:    		open_audio_mode
  Description:		������Ƶģʽ
  Input: 			len=0 ���Գ��� ����=ÿ�����ȵ�λ�ֽ�
  Output:			��
  Return:			��
  Others:
*************************************************/
int open_audio_mode(AUDIO_STATE_E mode, void* arg1, void *arg2, void *arg3);

/*************************************************
  Function:    	close_audio_mode
  Description:		
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
int close_audio_mode(AUDIO_STATE_E mode);
#endif

