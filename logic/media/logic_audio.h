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

#define AUDIO_NUM				6
//#define AUDIO_AEC_NUM			6


#if (_AEC_TYPE_ == _HW_AEC_)
#define SPEEX_AEC_NUM   		2 
#else
#define SPEEX_AEC_NUM   		6
#endif

#define SAMPLE_AUDIO_PTNUMPERFRM	80

#define _AEC_BUF_SIZE_			(6000)
#define _AEC_FRAME_SIZE			(2*SAMPLE_AUDIO_PTNUMPERFRM)
#if 1
#define AACRECORDER_BIT_RATE	64000				// 64K bps
#define AACRECORDER_CHANNEL_NUM	1		   			// Mono
#define AACRECORDER_QUALITY		90		   			// 1 ~ 999
#define AUDIO_SAMPLE_RATE_8000 	8000      			// ������
#define AUDIO_BIT_WIDTH_16     	16        			// ����λ��
#endif
			
// ��Ƶ״̬ģʽ
typedef enum
{
	AS_CLOSE,										// �ر�״̬
	AS_NETTALK,										// ����ͨ��״̬
	AS_PLAY,										// ��������ģʽ
	AM_HINT_LYLY,									// ����������ʾ��ģʽ
}AUDIO_STATE_E;		

// ��Ƶ����
typedef struct
{
	uint8 MicValue;									// mic��С
	uint8 SpkValue;									// spk��С
	uint8 IsAec;									// �Ƿ��������
	uint8 IsPack;									// �Ƿ����
	uint8 PackNum;									// �������
	uint8 AgcType;
	uint8 VideoMode;
	uint8 recsrc;
	int byte_per_packet;							// ÿ���ж����ֽ���
	float MultAgcH;
	float MultAgcL;
	float AIAgcH;
	float AIAgcL;
	float SpkAgcH;
	float SpkAgcL;
	float AoAgcH;
	float AoAgcL;	
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

//��Ƶ����
typedef enum
{
	AS_LPLAY,										// ����
    AS_FFD, 										// ���
    AS_FFW, 										// ����
    AS_PAUSE,										// ��ͣ
    AS_STOP,  										// ֹͣ
    AS_ERROR,										// ����
    AS_REC,
    AS_TALK,
    AS_SAVE											// ����,����¼������Ӱ����ʱ
}AUDIO_CONTROL_STATE_E;	

typedef struct _MEDIA_AU_CTRL
{
	FILE * filehald;								// �ļ�ָ��
	char filename[50];								// �ļ���
	uint32 FileSize;								// �ļ���С
	uint8 * data;									// �ļ�����
	
	PMEDIA_AU_CALLBACK	callback;					// �ص�
	AUDIO_MODE_E	mode;							// ����ģʽ
	AUDIO_STATE_E 	state;							// ����״̬
	unsigned long 	totaltime;						// �ļ���ʱ��
	unsigned long 	remaintime;						// ʣ��ʱ��
	unsigned long 	currenttime;					// ��ǰ����ʱ��
	uint8			volume;							// ��������
	AUDIO_REPEAT_E	repeat;							// ����ģʽ
	unsigned int	codectype;						// ��Ƶ��������

	unsigned long	bitrate;						// ÿ�������λ��
	unsigned long	samplerate;						// ������,ÿ������Ĵ���
	uint8			channels;						// ͨ����
}MEDIA_AU_CTRL, * PMEDIA_AU_CTRL;

extern AUDIO_PARAM AudioParam;

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
  Function:    		set_audio_pack_mode
  Description: 		������Ƶ�Ƿ����
  Input:			��
  Output:			��
  Return:			��		
  Others:
*************************************************/
void set_audio_pack_mode(uint8 IsPack);

/*************************************************
  Function:    	close_audio_local_enc
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int close_audio_local_enc(void);

/*************************************************
  Function:    	open_audio_local_enc
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_audio_local_enc(void);

/*************************************************
  Function:    		set_audio_codec_param
  Description:		������Ƶ����
  Input: 		
  Output:			AudioParam ��Ƶ��������
  Return:			��
  Others:
*************************************************/
void set_audio_codec_param(AUDIO_PARAM *g_AudioParam, int len);

/*************************************************
  Function:    	open_audio_ai
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_audio_ai(void);

/*************************************************
  Function:    	close_audio_ai
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int close_audio_ai(void);

/*************************************************
  Function:    	open_audio_enc
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_audio_enc(void);

/*************************************************
  Function:    	close_audio_enc
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int close_audio_enc(void);

/*************************************************
  Function:    		set_audio_ai_enable
  Description: 		�����Ƿ���������
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int set_audio_aec_enable(unsigned char enable);

/*************************************************
  Function:    		open_audio_mode
  Description:		������Ƶģʽ
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
int open_audio_mode(AUDIO_STATE_E mode, int address, int len);

/*************************************************
  Function:    		close_audio_mode
  Description:		
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
int close_audio_mode(AUDIO_STATE_E mode);

/*************************************************
  Function:    	open_dec_enable
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_dec_enable(void);

/*************************************************
  Function:    		open_dec_disable
  Description: 		
  Input:		��
  Output:		��
  Return:		��	
  Others:
*************************************************/
int open_dec_disable(void);

/*************************************************
  Function:    		get_audio_addr_count
  Description: 		��ȡRTP��Ƶ������
  Input:			��
  Output:			��
  Return:			�����ӵ�����		
  Others:
*************************************************/
int get_audio_addr_count(void);

/*************************************************
  Function:    		del_audio_sendaddr
  Description: 		ȥ����Ƶ���͵�ַ
  Input: 			
  	1.IP			IP��ַ
  	2.AudioPort		��Ƶ�˿�
  Output:			��
  Return:			��
  Others:
*************************************************/
void del_audio_sendaddr(uint32 IP, uint16 AudioPort);

/*************************************************
  Function:			play_sound_file
  Description: 		��ʼ���������ļ��ͼ�������
  Input: 			
  	1.FileName		�ļ�����
  	2.proc			���Ž��Ȼص�����,����Ϊ��
  Output:			����ID, 0Ϊʧ��, ����ʱ�ô�ID
  Return:			��
*************************************************/
int play_sound_file(char * FileName, int IsRepeat, void * proc);

/*************************************************
  Function:			stop_play_file
  Description: 		ֹͣ��������
  Input: 			
  	1.FileName		
  	2.proc			
  Output:			
  Return:			
*************************************************/
 int stop_play_file(void);

/*************************************************
  Function:    	start_play_hint_lyly
  Description: 		
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 start_play_hint_lyly(uint8 RemoteDeviceType, char * FileName, void * proc);

/*************************************************
  Function:    	stop_play_hint_lyly
  Description: 		
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 stop_play_hint_lyly(void);

/*************************************************
  Function:    	close_audio_rtp_send
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int close_audio_rtp_send(void);

/*************************************************
  Function:    	open_audio_rtp_send
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_audio_rtp_send(void);

/*************************************************
  Function:    		open_audio_rtp_recv
  Description: 		��Ӱ�����п�����Ƶ�ӿ�
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
int32 start_lyly_audio_recv(int32 address);

/*************************************************
  Function:    		stop_lyly_audio_recv
  Description: 		
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void stop_lyly_audio_recv(void);

/*************************************************
  Function:    		add_audio_sendaddr
  Description: 		������Ƶ���͵�ַ
  Input: 			
  	1.IP			IP��ַ
  	2.AudioPort		��Ƶ�˿�
  Output:			��
  Return:			�ɹ����true/false
  Others:
*************************************************/
int32 add_audio_sendaddr(uint32 IP, uint16 AudioPort);
#endif

