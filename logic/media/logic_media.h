/*************************************************
  Copyright (C), 2006-2010, Aurine
  File name: 	logic_media.h
  Author:   	�±���
  Version:  	2.0
  Date: 		2014-12-11
  Description:  ��ý��ӿں���
				
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#include "logic_media_core.h"
#include "logic_include.h"
#include "logic_video.h"
#include "logic_audio.h"

#ifndef _LOGIC_MEDIA_H_
#define _LOGIC_MEDIA_H_


typedef void (*PMEDIA_CALLBACK)(uint32 cmd, uint32 time, uint32 percent);

#ifdef _AU_PROTOCOL_
#define MEDIA_AUDIO_PORT		24020				// ��Ƶ�˿�
#define MEDIA_VIDEO_PORT		24010				// ��Ƶ�˿�
#else
#define MEDIA_AUDIO_PORT		31420				// ��Ƶ�˿�
#define MEDIA_VIDEO_PORT		31410				// ��Ƶ�˿�
#endif
#define MEDIA_VIDEOL_PORT		31430

#define AUDIO_REC_PT			PT_G711A			// ������Ƶ¼�Ƹ�ʽ(��˼)
#define VIDEO_REC_PT			PT_H264				// ������Ƶ¼�Ƹ�ʽ(��˼)


typedef struct 
{
	MSMediaDesc* System;
	MSMediaDesc* VideoEnc;
	MSMediaDesc* VideoDec;
	MSMediaDesc* VideoRtpSend;
	MSMediaDesc* VideoRtpRecv;
	MSMediaDesc* AudioDec;
	MSMediaDesc* AudioAi;
	MSMediaDesc* AudioAo;	
	MSMediaDesc* AudioEnc;
	MSMediaDesc* AudioRtpSend;
	MSMediaDesc* AudioRtpRecv;
	MSMediaDesc* FilePlayer;
	MSMediaDesc* JpegDec;
	MSMediaDesc* JpegEnc;
	MSMediaDesc* AlawAgc;	
    MSMediaDesc* Speex; 
	MSMediaDesc* AviPlay; 
	MSMediaDesc* AviRecord;
	MSMediaDesc* WavRecord; 
	MSMediaDesc* Mp3Play; 
	MSMediaDesc* RtspPlay;
	MSMediaDesc* LylyHitPlay;
	#ifdef _ENABLE_CLOUD_
	MSMediaDesc* VideoCloudSend;
	MSMediaDesc* AudioCloudSend;
	MSMediaDesc* AudioCloudRecv;
	MSMediaDesc* VideoCloudEnc;
	#endif

}MediaStream, * PMediaStream;

// ͷ�ļ����治���ж���
extern MediaStream mMediaStream;

// ����Ƶ�ĸ�ʽ
typedef enum
{
	/* audio & voice payload type */
	PT_PCMU = 0,
	PT_1016 = 1, 
	PT_G721 = 2,     
	PT_GSM = 3,
	PT_G723 = 4,
	PT_DVI4_8K = 5,     							// clock rate=8,000Hz, channels=1
	PT_DVI4_16K = 6,    							// clock rate=16,000Hz, channels=1 
	PT_LPC = 7,
	PT_PCMA = 8,
	PT_G722 = 9,
	PT_S16BE_STEREO = 10,     						// clock rate=44,100Hz, channels=2
	PT_S16BE_MONO = 11,       						// clock rate=44,100Hz, channels=1
	PT_QCELP = 12,
	PT_CN = 13,
	PT_MPEGAUDIO = 14,
	PT_G728 = 15,
	PT_DVI4_3 = 16,    								// clock rate=11,025Hz, channels=1
	PT_DVI4_4 = 17,    								// clock rate=22,050Hz, channels=1
	PT_G729 = 18,

	/* user-defined */
	PT_G711A    = 19,
	PT_G711U    = 20,
	PT_G726     = 21,
	PT_G729A    = 22,   							// w54130 defined
    PT_LPCM     = 23,
    PT_ILBC     = 24,   							// added by ghtao, 2007-06-21

	/* video payload type */
	PT_CelB = 25,
	PT_JPEG = 26,
	PT_CUSM = 27, 
	PT_NV = 28, 
	PT_PICW = 29, 
	PT_CPV = 30,     
	PT_H261 = 31,
	PT_MPEGVIDEO = 32,
	PT_MPEG2TS = 33,
	PT_H263 = 34,
	PT_SPEG = 35, 

	/* user-defined */
	PT_MPEG2VIDEO = 36,
	PT_AAC = 37,
	PT_WMA9STD = 38,
	PT_HEAAC = 39,
	PT_PCM_VOICE = 40,                         		// (PCM data replay), mono audio channel, low sampling rate.
	PT_PCM_AUDIO = 41,                         		// (PCM data replay), multi audio channels, high sampling rate.
	
    PT_AACLC   = 42,
    PT_MP3     = 43,
    PT_AMR      = 44,
    PT_AMRDTX   = 45, 
    PT_ADPCMA   = 49,
    PT_AEC      = 50,
    
    PT_X_LD = 95, 
	PT_H264 = 96,
	PT_D_GSM_HR = 200, 
	PT_D_GSM_EFR = 201, 
	PT_D_L8 = 202, 
	PT_D_RED = 203, 
	PT_D_VDVI = 204, 
	PT_D_BT656 = 220, 
	PT_D_H263_1998 = 221, 
	PT_D_MP1S = 222, 
	PT_D_MP2P = 223, 
	PT_D_BMPEG = 224, 
	PT_MP4VIDEO = 230,
	PT_MP4AUDIO = 237, 
	PT_VC1 = 238,
	PT_JVC_ASF = 255, 
	PT_D_AVI = 256, 
	PT_MAX = 257
}PAYLOAD_TYPE_E;

// ���ŵ���Ƶ��ʽ
typedef enum
{
	PLAY_AUDIO_TYPE_WAV,
	PLAY_AUDIO_TYPE_MP3,
	PLAY_AUDIO_TYPE_NONE
}PLAY_AUDIO_TYPE_E;

// ��Ӱ����ģʽ
typedef enum
{
	LWM_AUDIO = 0,									// ����Ƶģʽ
	LWM_AUDIO_PIC,									// ��Ƶ+ͼƬģʽ
	LWM_AUDIO_VIDEO,								// ����Ƶģʽ
	LWM_NONE										// ������
}LEAVE_WORD_MODE_E;	

typedef struct 
{
	uint32 ip;
	uint16 port;
}RTP_ADDRESS, * PRTP_ADDRESS;

// ý���ļ�ͷ�ṹ
typedef struct
{
    uint8 RecFlag;		                            // ������: bit0 ��Ƶ   bit1 ��Ƶ
    uint8 AudioFormat;	                            // ��Ƶ��ʽ
    uint8 VideoFormat;	                            // ��Ƶ��ʽ
    uint8 reserved;		                            // ����, ��0xFF
    uint32 time;		                            // ¼��ʱ��
}MEDIA_FILE_HEAD, * PMEDIA_FILE_HEAD;

typedef struct
{
    uint8 reserved;	                                // ����, ��0xFF
    uint8 flag;		                                // 0-��Ƶ, 1-��Ƶ
    uint16 size;	                           		// ����
    uint32 ts;		                                // ʱ���
}MEDIA_HEAD, * PMEDIA_HEAD;

// ����Ƶͬ����ʱ��
typedef struct
{
    uint32 current;
	uint32 redress;
	uint32 ts0;
} SYNC_TIME;

typedef struct _MEDIA_LYLY_CTRL
{
	FILE 			* FileHald;						// �ļ�ָ��
	char			FileName[50];					// �ļ���
	uint32 			FileSize;						// �ļ���С
	MEDIA_FILE_HEAD FileHead;						// �ļ�ͷ,ֻ�а���HI�ļ�ͷ���ļ�������
	uint8			* data;							// �ļ�����
	LEAVE_WORD_MODE_E mode;							// ��Ӱ�������� 1����Ƶ  2����Ƶ  3����Ƶ
	SYNC_TIME		TimeA;							// ��Ƶʱ���
	SYNC_TIME		TimeV;							// ��Ƶʱ���
	uint8			state;							// 0-���� 1-���� 2-¼��
	uint8			issave;							// 0:no 1:yes
	PMEDIA_CALLBACK callback;						// �ص�
}MEDIA_LYLY_CTRL, * PMEDIA_LYLY_CTRL;



/*************************************************
  Function:			media_stream_FileExtCmp
  Description:		��ѯ�ļ�����
  Input:
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
int media_stream_FileExtCmp(const char* pu8FileName, const char* pu8Ext);

/*************************************************
  Function:		media_set_color_key
  Description: 	���ùؼ�ɫ
  Input: 		
  	color		ARGB
  Output:		��
  Return:		��
  Others:	
*************************************************/
void media_set_color_key(uint32 color);

/*************************************************
  Function:		media_clear_fb
  Description: 	���fb
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 media_clear_fb(void);

/*************************************************
  Function:			media_enable_audio_ai
  Description:		ʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_enable_audio_ai(void);

/*************************************************
  Function:			media_disable_audio_ai
  Description:		ȥʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_disable_audio_ai(void);

/*************************************************
  Function:			media_enable_audio_dec
  Description:		ʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_enable_audio_dec(void);

/*************************************************
  Function:			media_disable_audio_dec
  Description:		ȥʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_disable_audio_dec(void);

/*************************************************
  Function:			media_enable_audio_aec
  Description:		ʹ���������ӿ�
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_enable_audio_aec(void);

/*************************************************
  Function:			media_disable_audio_aec
  Description:		ʹ���������ӿ�
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_disable_audio_aec(void);

/*************************************************
  Function:			media_play_sound
  Description:		������Ƶ�ļ�
  Input: 			
  	1.type			��������
  	2.filename		�ļ���
  	3.isrepeat		�Ƿ��ظ�����	1�ظ� 0���ظ�
  	4.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_play_sound(char *filename, uint8 IsRepeat, void * proc);

/*************************************************
  Function:			media_stop_sound
  Description:		ֹͣ����
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
void media_stop_sound (void);

/*************************************************
  Function:			media_start_net_hint
  Description:		����������ʾ������
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_hint(uint8 RemoteDeviceType, char *filename, void * proc);

/*************************************************
  Function:			media_stop_net_hint
  Description:		ֹͣ��ʾ������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_net_hint(void);

/*************************************************
  Function:			media_start_net_audio
  Description:		����������Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_audio(int address);

/*************************************************
  Function:			media_stop_net_audio
  Description:		ֹͣ������Ƶ����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_net_audio(void);

/*************************************************
  Function:			media_snapshot
  Description:		ץ��
  Input: 			
  	1.filename		ͼ�񱣴���ļ���
  					���>1ʱ�ļ����Զ����ϱ��
	2.dstW			Ŀ��ͼƬ�Ŀ�
	3.dstH			Ŀ��ͼƬ�ĸ�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_snapshot(char *filename, void *proc, DEVICE_TYPE_E DevType);


/*************************************************
  Function:			media_start_net_video
  Description:		����������Ƶ����
  Input: 	
  	1.addres		�Զ˵�ַ
  	2.mode			��Ƶģʽ ���͡�����
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
uint32 media_start_net_video(uint32 address, uint8 mode);

/*************************************************
  Function:			media_stop_net_video
  Description:		ֹͣ������Ƶ����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_net_video(uint8 mode);

/*************************************************
  Function:		init_media
  Description: 	ý���ʼ��
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void media_init(void);
#endif

