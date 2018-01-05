/*************************************************
  Copyright (C), 2006-2010, Aurine
  File name: 	logic_media.c
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
#include "storage_include.h"
#include "logic_include.h"

#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>
#include <errno.h>
#include <sys/time.h>
#include <semaphore.h>
#include <wchar.h>
#include <sys/mman.h>

#include "logic_audio.h"
#include "logic_video.h"
#include "logic_media.h"
#include "logic_tran_rtp.h"

#define IDR						5
#define SEI						6
#define SPS						7
#define PPS						8

#define STAP_A					24
#define STAP_B					25
#define MTAP16					26
#define MTAP24					27
#define FU_A					28
#define FU_B					29

#define LEAVE_PIC_TYPE			".jpg"
#define LEAVE_AVI_TYPE			".avi"
#define LEAVE_WAV_TYPE			".wav"

typedef enum
{
    Audio_Once,
    Audio_Repeat,
    Audio_AllOnce,
    Audio_AllRepeat,
    Audio_Try
}AUDIOREPEATMODE;

RTP_ADDRESS g_AudioAddress;
RTP_ADDRESS g_VideoAddress;

extern uint32 PlayVoffset;
extern uint32 PlayVremain;

MEDIA_LYLY_CTRL g_LylyRecordCtrl = 
{
	NULL,
	{0},
	0,
	{0, 0, 0, 0, 0},
	NULL,
	LWM_NONE,
	{0, 0, 0},
	{0, 0, 0},
	0,
	0,
	NULL
};

// modi by luofl 2014-08-28 ����������󼶳�����׼85DB
//uint8 AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 16, 17, 18, 19};
uint8 AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V7_AudioVolumeLevel[9] = {0, 7, 10, 13, 17, 18, 21, 22, 23};

#if 0
#if 0
uint8 E81_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 20, 24, 25, 26, 27, 28};
uint8 E81_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 E81_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 17, 18, 19, 20, 21};
uint8 E81_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 20, 25, 26, 27, 28, 29};
#else
uint8 E81_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 E81_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 E81_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 E81_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
#endif

// E91,F91���ڻ�
uint8 E91_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 E91_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 E91_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 E91_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};

// modi by luofl 2013-09-03
// F99���ڻ�
uint8 F99_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 F99_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 F99_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 F99_ROOM_AudioVolumeLevel[9] = {0, 5, 10, 15, 17, 18, 19, 20, 21};

// F102���ڻ�
uint8 F102_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 F102_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 F102_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 F102_ROOM_AudioVolumeLevel[9] = {0, 5, 10, 15, 17, 18, 19, 20, 21};

// D7���ڻ�
uint8 D7_STAIR_AudioVolumeLevel[9] = {0, 5, 10, 15, 18, 19, 20, 21, 22};
uint8 D7_CENTER_AudioVolumeLevel[9] = {0, 5, 9, 10, 12, 13, 14, 15, 16};
uint8 D7_NETDOOR_AudioVolumeLevel[9] = {0, 5, 9, 11, 12, 13, 14, 15, 16};
uint8 D7_ROOM_AudioVolumeLevel[9] = {0, 5, 10, 15, 17, 18, 19, 20, 21};

// V5���ڻ�
uint8 V5_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 V5_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 14, 15, 16, 17, 18};
uint8 V5_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 V5_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 22, 23, 24, 25, 26};

// V6���ڻ�
uint8 V6_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 V6_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 V6_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 V6_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};

// V8���ڻ�
uint8 V8_STAIR_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
uint8 V8_CENTER_AudioVolumeLevel[9] = {0, 5, 10, 13, 16, 17, 18, 19, 20};
uint8 V8_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 V8_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};
#endif

// ============V1���ڻ�(���������ڻ��������������)========================
//uint8 V1_STAIR_AudioVolumeLevel[9] = {0, 10, 13, 16, 18, 20, 21, 22, 23};
uint8 V1_STAIR_AudioVolumeLevel[9] = {0, 10, 16, 21, 22, 23, 24, 25, 26};

uint8 V1_CENTER_AudioVolumeLevel[9] = {0, 10, 13, 18, 21, 22, 23, 24, 25};
//uint8 V1_CENTER_AudioVolumeLevel[9] = {0, 10, 13, 16, 18, 20, 21, 22, 23};

uint8 V1_NETDOOR_AudioVolumeLevel[9] = {0, 10, 16, 20, 22, 24, 25, 26, 27};
//uint8 V1_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};

uint8 V1_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};

// =========================V7���ڻ���Ƶ����================================
//uint8 V7_STAIR_AudioVolumeLevel[9] = {0, 10, 13, 16, 18, 20, 21, 22, 23};
uint8 V7_STAIR_AudioVolumeLevel[9] = {0, 10, 16, 21, 24, 25, 26, 27, 28};

//uint8 V7_CENTER_AudioVolumeLevel[9] = {0, 10, 13, 16, 18, 20, 21, 22, 23};
uint8 V7_CENTER_AudioVolumeLevel[9] = {0, 9, 13, 17, 21, 22, 23, 24, 25};

//uint8 V7_NETDOOR_AudioVolumeLevel[9] = {0, 10, 13, 15, 16, 17, 18, 19, 20};
uint8 V7_NETDOOR_AudioVolumeLevel[9] = {0, 10, 16, 20, 22, 24, 25, 26, 27};

uint8 V7_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};

// ============V5���ڻ�(���������ڻ��������������)========================
uint8 V5_STAIR_AudioVolumeLevel[9] = {0, 10, 16, 21, 22, 23, 24, 25, 26};

uint8 V5_CENTER_AudioVolumeLevel[9] = {0, 10, 13, 16, 18, 20, 21, 22, 23};

uint8 V5_NETDOOR_AudioVolumeLevel[9] = {0, 10, 16, 18, 20, 22, 24, 25, 26};

uint8 V5_ROOM_AudioVolumeLevel[9] = {0, 10, 15, 19, 21, 22, 23, 24, 25};

static DEVICE_TYPE_E g_device = DEVICE_TYPE_NONE;
static uint8 ChangVideoWin = 0;
static struct ThreadInfo VideoPreviewThread;		// ģ����ǰ����ƵԤ���߳�
static PLAY_AUDIO_TYPE_E g_Aplay_type;				// ���ŵ���Ƶ����
MediaStream mMediaStream;
AUDIO_PARAM AudioParam;

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
uint32 media_start_net_video(uint32 address, uint8 mode)
{	
	VIDEO_STATE_E VideoMode = VS_CLOSE;
	
	log_printf("mode : 0X%x\n", mode);
    if (mode == _SENDONLY)
    {
        VideoMode = VS_NETTALK_SEND;
    }
    else if (mode == _RECVONLY)
    {
        VideoMode = VS_NETTALK_RECIVE;
    }
	else if (mode == _SENDRECV)
	{
		VideoMode = VS_NETTALK_BOTH;
	}
	else
	{
		log_printf("video mode is none!! \n");
		return FALSE;
	}
	open_video_mode(VideoMode, address);
	
	return TRUE;
}

/*************************************************
  Function:			media_stop_net_video
  Description:		ֹͣ������Ƶ����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_net_video(uint8 mode)
{
	VIDEO_STATE_E VideoMode = VS_CLOSE;
	log_printf("mode : 0X%x\n", mode);
    if (mode == _SENDONLY)
    {
        VideoMode = VS_NETTALK_SEND;
    }
    else if (mode == _RECVONLY)
    {
        VideoMode = VS_NETTALK_RECIVE;
    }
	else if (mode == _SENDRECV)
	{
		VideoMode = VS_NETTALK_BOTH;
	}
	else
	{
		log_printf("video mode is none!! \n");
		return ;
	}
	close_video_mode(VideoMode);
	return;
}

extern int s_i32FBWidth;
extern int s_i32FBHeight;

int32_t i32FBFd;
uint8_t * pu8FBBufAddr;
uint32_t u32FBBufSize;

static uint8_t* g_v4laddr;
static uint8 g_start_video = 0;      // ��Ƶ������־

/*************************************************
  Function:			media_stream_FileExtCmp
  Description:		��ѯ�ļ�����
  Input:
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
int32 media_stream_FileExtCmp(const uint8*	pu8FileName, const char* pu8Ext)
{
	int32		i32Len1 = strlen((char*)pu8FileName);
	int32		i32Len2 = strlen(pu8Ext);
	uint8*	pu8Tmp = (uint8*)(pu8FileName + (i32Len1 - i32Len2));

	if (i32Len2 > i32Len1)
		return -1;

	return strcasecmp((char*)pu8Tmp, pu8Ext);
}

/*************************************************
  Function:			media_get_v4l_addr
  Description:		
  Input:
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
void media_get_v4l_addr(uint8 **addr)
{
	*addr = g_v4laddr;
}

/*************************************************
  Function:			media_start_analog_video_proc
  Description:		ģ����ƵԤ���߳�
  Input:
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
static void* media_start_analog_video_proc(void *param)
{
	// ���÷����߳�
	pthread_detach(pthread_self());
	uint8_t * pu8PicPtr;
	uint64_t u64TS;
	uint32_t u32PicPhyAdr;

	while (VideoPreviewThread.running)
	{
	#if 0
		if (ChangVideoWin)
		{
			usleep(10*1000);
		}
		else if (ReadV4LPicture(&pu8PicPtr, &u64TS, &u32PicPhyAdr) == ERR_V4L_SUCCESS)
		{ 
			g_start_video = 1;
			g_v4laddr = pu8PicPtr;
			TriggerV4LNextFrame();
		}
	#endif
	}

thread_end:
	VideoPreviewThread.thread = -1;
	pthread_exit(NULL);
	return NULL;             // ���غ���Դ��ϵͳ�ͷ�
}

/*************************************************
  Function:			media_start_analog_video
  Description:		����ģ����ƵԤ��
  Input:
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
uint32 media_start_analog_video(void)
{
#if _DOOR_PHONE_
	uint32_t u32EncodeImgWidth = 0, u32EncodeImgHeight = 0;
	uint32_t u32PreviewImgWidth = 0, u32PreviewImgHeight = 0;

	E_IMAGE_RESOL ePreviewImgResol;
	E_IMAGE_RESOL eEncodeImgResol;

	#if 0
	signal(SIGINT, myExitHandler);
	//signal(SIGQUIT, myExitHandler);
	//signal(SIGILL, myExitHandler);
	//signal(SIGABRT, myExitHandler);
	//signal(SIGFPE, myExitHandler);
	signal(SIGKILL, myExitHandler);
	//signal(SIGPIPE, myExitHandler);
	signal(SIGTERM, myExitHandler);
	#endif

	ePreviewImgResol = eIMAGE_WQVGA;
	eEncodeImgResol = eIMAGE_WQVGA;
	if (ePreviewImgResol == eIMAGE_WQVGA)
	{
		u32PreviewImgWidth = 380;//480;
		u32PreviewImgHeight = 272;
	}
	else if(ePreviewImgResol == eIMAGE_VGA)
	{
		u32PreviewImgWidth = 640;
		u32PreviewImgHeight = 480;
	}
	else if(ePreviewImgResol == eIMAGE_QVGA)
	{
		u32PreviewImgWidth = 320;
		u32PreviewImgHeight = 240;
	}

	if(eEncodeImgResol == eIMAGE_QVGA)
	{
		u32EncodeImgWidth = 320;
		u32EncodeImgHeight = 240;
	}
	else if(eEncodeImgResol == eIMAGE_WQVGA)
	{
		u32EncodeImgWidth = 480;
		u32EncodeImgHeight = 272;
	}
	else if(eEncodeImgResol == eIMAGE_VGA)
	{
		u32EncodeImgWidth = 640;
		u32EncodeImgHeight = 480;
	}

	usleep(500*1000); 			// �ȴ���Ƶ�ȶ�
	// Init frame buffer
	i32FBFd = InitFBDevice(&pu8FBBufAddr, &u32FBBufSize);
	log_printf("FB = %d\n", i32FBFd);
	if (i32FBFd < 0)
	{
		log_printf("Init fb device fail\n");
		goto exit_prog1;
	}

	// Init video in
	if (InitV4LDevice(eEncodeImgResol) != ERR_V4L_SUCCESS)
	{
		ioctl(i32FBFd, IOCTL_LCD_DISABLE_INT, 0);
		ioctl(i32FBFd, VIDEO_FORMAT_CHANGE, DISPLAY_MODE_RGB565); //2012-0808 
		memset(pu8FBBufAddr, 0x00, u32FBBufSize);		
		munmap(pu8FBBufAddr, u32FBBufSize);
		ioctl(i32FBFd, IOCTL_LCD_ENABLE_INT, 0);
		close(i32FBFd);
		log_printf("Init V4L device fail\n");
		goto exit_prog1;
	}
	log_printf("Init V4L device pass\n");
	
	// for stride issue
	StartPreview();
	SetV4LViewWindow(s_i32FBWidth, s_i32FBHeight, u32PreviewImgWidth, u32PreviewImgHeight);
	StartV4LCapture();
	ioctl(i32FBFd, IOCTL_LCD_ENABLE_INT, 0);
	log_printf("s_i32FBWidth: %d  s_i32FBHeight: %d\n", s_i32FBWidth, s_i32FBHeight);
	if (inter_start_thread(&VideoPreviewThread, media_start_analog_video_proc, NULL, 0) != 0)
	{
		goto exit_prog2;
	}
	return TRUE;
	
exit_prog2:
		ioctl(i32FBFd, IOCTL_LCD_DISABLE_INT, 0);
		StopV4LCapture();	
		FinializeV4LDevice();
		ioctl(i32FBFd, VIDEO_FORMAT_CHANGE, DISPLAY_MODE_RGB565);
		memset(pu8FBBufAddr, 0x00, u32FBBufSize);		
		munmap(pu8FBBufAddr, u32FBBufSize);
		ioctl(i32FBFd, IOCTL_LCD_ENABLE_INT, 0);
		close(i32FBFd);

exit_prog1:

	return FALSE;
#endif
}

/*************************************************
  Function:			media_stop_analog_video
  Description:		ֹͣģ����ƵԤ��
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_analog_video(void)
{
#if _DOOR_PHONE_
	if (1 == VideoPreviewThread.running)
	{
		VideoPreviewThread.running = 0;
		ioctl(i32FBFd, IOCTL_LCD_DISABLE_INT, 0);
		StopV4LCapture();	
		//log_printf("Clear Frame Buffer Addr = 0x%x\n",  (uint32_t)pu8FBBufAddr);
		//wmemset((wchar_t *)pu8FBBufAddr, 0x00000000, (s_i32FBWidth*s_i32FBHeight*2)/4);
		FinializeV4LDevice();
		ioctl(i32FBFd, VIDEO_FORMAT_CHANGE, DISPLAY_MODE_RGB565);
		memset(pu8FBBufAddr, 0x00, u32FBBufSize);
		
		munmap(pu8FBBufAddr, u32FBBufSize);
		ioctl(i32FBFd, IOCTL_LCD_ENABLE_INT, 0);
		close(i32FBFd);
		g_start_video = 0;
	}
	
	return;
#endif
}

/*************************************************
  Function:			media_set_analog_video_win
  Description:		����ģ����ƵԤ������
  Input:
  	1.flag			1-ȫ����ʾ, ����Ϊ������ʾ
  Output:			��
  Return:			��
  Others:
*************************************************/
static int32 media_set_analog_video_win(uint8 flag)
{
	#ifdef _DOOR_PHONE_
	if (VideoPreviewThread.running && g_start_video == 1)
	{
		ChangVideoWin = 1;
		ioctl(i32FBFd, IOCTL_LCD_DISABLE_INT, 0);
		if (flag)
		{
			SetV4LViewWindow(480, 272, 480, 272);
		}
		else
		{
			SetV4LViewWindow(480, 272, 380, 272);
		}
		ioctl(i32FBFd, IOCTL_LCD_ENABLE_INT, 0);
		ClearVDBuf();
		ChangVideoWin = 0;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	#else
	return TRUE;
	#endif
}

/*************************************************
  Function:			media_set_analog_output_volume
  Description:		����ģ���豸ͨ������
  Input: 
  	vol				�����ȼ�(0���� - 8���)
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_set_analog_output_volume(uint32 vol)
{
	int32 ret = hw_set_volume(vol);
	if (ret == -1)
	{
		return FALSE;
	}
	return TRUE;
}

/*************************************************
  Function:			media_start_rtsp_video
  Description:		����RTSP��Ƶ����
  Input: 	
  	1.tp			��Ƶ��ʽ
  	2.vorect		��Ƶ���λ��
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_rtsp_video(PAYLOAD_TYPE_E tp, V_RECT_S * vorect, void * proc)
{
	#if 0
	uint32 ret;

	log_printf("media_start_net_video\n");
	ret = h264_player_start(NULL, vorect, VM_TLAK, 0, proc);
	if (ret != TRUE)
	{
		log_printf("media_start_net_video : h264_player_start err\n");
		return ret;
	}
	#endif
	return TRUE;
}

/*************************************************
  Function:			media_stop_rtsp_video
  Description:		ֹͣRTSP��Ƶ����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_rtsp_video(void)
{
	#if 0
	uint32 ret;

	h264_player_stop_immediate();
	#endif
}

/*************************************************
  Function:			media_start_raw_video_file
  Description:		��������H264�������ļ�
  Input: 	
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_raw_video_file(char * filename)
{	
	#if 0
	V_RECT_S	vorect;
	uint32 ret;
	
	vorect.x = 200;
	vorect.y = 120;
	vorect.width = 320;
	vorect.height = 240;
	
	log_printf("media start raw video file\n");
	
	ret = h264_player_start(filename, &vorect, VM_FILE, 0, NULL);
	if (ret != TRUE)
	{
		log_printf("media_start_raw_video_file : h264_player_start err\n");
		return ret;
	}
	#endif
	return TRUE;
}

/*************************************************
  Function:			media_stop_raw_video_file
  Description:		ֹͣ����H264�������ļ�
  Input: 	
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_raw_video_file(void)
{
	//log_printf("media_stop_raw_video_file\n");
	//h264_player_stop();

	return;
}

/*************************************************
  Function:			media_start_net_audio
  Description:		����������Ƶ����
  Input: 			
  	1.tp			��Ƶ��ʽ
  	2.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_audio(int address, int len)
{
	int ret = open_audio_mode(AS_NETTALK,  address, len);
	if (ret == -1)
	{
		return FALSE;
	}
	return TRUE;
}

/*************************************************
  Function:			media_stop_net_audio
  Description:		ֹͣ������Ƶ����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_net_audio(void)
{
	log_printf("net_stop_audio\n");
	close_audio_mode(AS_NETTALK);
	return;
}

/*************************************************
  Function:			meida_start_net_hint
  Description:		����������ʾ������
  Input: 			
  	1.tp			���͵ĸ�ʽ
  	2.filename		��ʾ���ļ�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 meida_start_net_hint(uint8 RemoteDeviceType, char *filename, void * proc)
{
	int ret =  open_audio_rtp_send();	
    if (ret != HI_SUCCESS)
    {
   		goto erraudio0;
    }
	
	ret = start_play_hint_lyly(RemoteDeviceType, filename, proc);
	if (ret != HI_SUCCESS)
	{
		goto erraudio1;
	}
	
	ms_media_link(mMediaStream.LylyFilePlayer, mMediaStream.AudioRtpSend);	
	return ret;

erraudio1:
	stop_play_hint_lyly();
	
erraudio0:
	close_audio_rtp_send();
	
	return ret;
}

/*************************************************
  Function:			meida_stop_net_hint
  Description:		ֹͣ��ʾ������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
uint32 meida_stop_net_hint(void)
{
	stop_play_hint_lyly();
	close_audio_rtp_send();

	ms_media_unlink(mMediaStream.LylyFilePlayer, mMediaStream.AudioRtpSend);	
	return 0;
}

/*************************************************
  Function:			media_fill_LylyRecordCtrl
  Description:		
  Input: 			
  	1.mode			¼�Ƶ�ģʽ
  	2.atp			��Ƶ��ʽ
  	3.vtp			��Ƶ��ʽ
  	4.filename		������ļ���
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
static void media_fill_LylyRecordCtrl(LEAVE_WORD_MODE_E mode, PAYLOAD_TYPE_E atp, PAYLOAD_TYPE_E vtp, char * filename)
{
	memset(g_LylyRecordCtrl.FileName, 0, sizeof(g_LylyRecordCtrl.FileName));
	strcpy(g_LylyRecordCtrl.FileName, filename);
	g_LylyRecordCtrl.mode = mode;
}

/*************************************************
  Function:			media_clean_LylyRecordCtrl
  Description:		
  Input: 			
  Output:			��
  Return:			
  Others:
*************************************************/
static void media_clean_LylyRecordCtrl(void)
{
	g_LylyRecordCtrl.mode = LWM_NONE;
	memset(g_LylyRecordCtrl.FileName, 0, sizeof(g_LylyRecordCtrl.FileName));
}

/*************************************************
  Function:			meida_start_net_leave_rec
  Description:		������������¼��
  Input: 			
  	1.mode			¼�Ƶ�ģʽ
  	2.atp			��Ƶ��ʽ
  	3.vtp			��Ƶ��ʽ
  	4.filename		������ļ���
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 meida_start_net_leave_rec(LEAVE_WORD_MODE_E mode,
						PAYLOAD_TYPE_E atp, PAYLOAD_TYPE_E vtp, char * filename)
{
	uint32 ret;

	log_printf("[%d] \n", __LINE__);
	if (mode == LWM_NONE)
	{
		return FALSE;
	}
	media_fill_LylyRecordCtrl(mode, atp, vtp, filename);
	
	ret = set_avi_record_param(mode, atp, vtp, filename);
	if (ret == FALSE)
	{
		return FALSE;
	}

	ret = start_lyly_audio_recv(g_AudioAddress.ip);	
	if (ret != 0)
	{
		log_printf("error : start_lyly_audio_recv return : %d \n", ret);
		goto error0;
	}

	ret = lyly_record_start();
	if (ret != 0)
	{
		log_printf("error : lyly_record_start return : %d \n", ret);
		goto error1;
	}

	if (mode == LWM_AUDIO_PIC)
	{
		char picname[100] = {0};
		sprintf(picname, "%s%s", filename, LEAVE_PIC_TYPE);
		log_printf("snap name ; %s\n ", picname);
		media_snapshot(picname, 0, 0, DEVICE_TYPE_NONE);

	}
	
	ms_media_link(mMediaStream.AudioRtpRecv, mMediaStream.AviRecord);
	if (mode == LWM_AUDIO_VIDEO)
	{
		ms_media_link_chunk(mMediaStream.VideoRtpRecv, mMediaStream.AviRecord, 2); // ��Ƶ��䵽�ڶ�������
	}
	return TRUE;

error1:
	stop_lyly_audio_recv();
	
error0:
	media_clean_LylyRecordCtrl();
	
	return FALSE;
	
}

/*************************************************
  Function:			stop_leave_word_net
  Description:		ֹͣ¼��
  Input: 			
  	1.issave		�Ƿ񱣴�(1����, 0������)
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_stop_net_leave_rec(uint8 issave)
{
	log_printf("  1111111111111111 \n");
	char filename[100] = {0};
	stop_lyly_audio_recv();
	
	lyly_record_stop();
	
	ms_media_unlink(mMediaStream.AudioRtpRecv, mMediaStream.AviRecord);
	if (g_LylyRecordCtrl.mode == LWM_AUDIO_VIDEO)
	{
		ms_media_unlink(mMediaStream.VideoRtpRecv, mMediaStream.AviRecord);
	}

	if (issave == FALSE)
	{
		if (g_LylyRecordCtrl.mode == LWM_AUDIO_PIC)
		{
			char picname[100] = {0};
			sprintf(picname, "%s%s", g_LylyRecordCtrl.FileName, LEAVE_PIC_TYPE);
			FSFileDelete(picname);
		}

		if (g_LylyRecordCtrl.mode == LWM_AUDIO_VIDEO)
		{			
			sprintf(filename, "%s%s", g_LylyRecordCtrl.FileName, LEAVE_AVI_TYPE);
		}
		else
		{
			sprintf(filename, "%s%s", g_LylyRecordCtrl.FileName, LEAVE_WAV_TYPE);
		}
		FSFileDelete(filename);	
	}
	media_clean_LylyRecordCtrl();
	
	return TRUE;
}

/*************************************************
  Function:			meida_set_audio_send_addr
  Description:		������Ƶ�ķ��͵�ַ�Ͷ˿�
  Input: 			
  	1.ip			IP��ַ
  	2.port			�˿�
  Output:			��
  Return:			��
  Others:
*************************************************/
void meida_set_audio_send_addr(uint32 ip, uint16 port)
{	
	log_printf("meida_set_audio_send_addr ip = 0X%08x , port = %d\n", ip, port);
	g_AudioAddress.ip = ip;
	g_AudioAddress.port = port;

	return;
}

/*************************************************
  Function:    		media_add_audio_sendaddr
  Description: 		������Ƶ���͵�ַ
  Input: 			
  	1.IP			IP��ַ
  	2.AudioPort		��Ƶ�˿�
  Output:			��
  Return:			�ɹ����true/false
  Others:
*************************************************/
int32 media_add_audio_sendaddr(uint32 IP, uint16 AudioPort)
{
	return add_audio_sendaddr(IP, AudioPort);
}

/*************************************************
  Function:			media_del_audio_send_addr
  Description:		ɾ����Ƶ�ķ��͵�ַ�Ͷ˿�
  Input: 
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_del_audio_send_addr(uint32 IP, uint16 AudioPort)
{
	del_audio_sendaddr(IP, AudioPort);
	//open_dec_disable();
	log_printf("media_del_audio_send_addr\n");
	g_AudioAddress.ip = 0;
	g_AudioAddress.port = 0;
	return;
}

/*************************************************
  Function:			media_set_dec_enable
  Description:		����Ƶ�������
  Input: 
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_set_dec_enable(void)
{
	open_dec_enable();
}

/*************************************************
  Function:			media_set_dec_disable
  Description:		�ر���Ƶ�������
  Input: 
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_set_dec_disable(void)
{
	open_dec_disable();
}

/*************************************************
  Function:			media_set_video_send_addr
  Description:		������Ƶ�ķ��͵�ַ�Ͷ˿�
  Input: 			
  	1.ip			IP��ַ
  	2.port			�˿�
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_set_video_send_addr(uint32 ip, uint16 port)
{
	//log_printf("media_set_video_send_addr ip = %x , port = %d\n", ip, port);
	g_VideoAddress.ip = ip;
	g_VideoAddress.port = port;
	return;
}

/*************************************************
  Function:			media_del_video_send_addr
  Description:		ɾ����Ƶ�ķ��͵�ַ�Ͷ˿�
  Input: 
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_del_video_send_addr(void)
{
	log_printf("media_del_video_send_addr\n");
	g_VideoAddress.ip = 0;
	g_VideoAddress.port = 0;
	return;
}

/*************************************************
  Function:			media_set_device
  Description:		�����豸����
  Input: 
  	dev				�豸����
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_set_device(DEVICE_TYPE_E dev)
{
	g_device = dev;
}

/*************************************************
  Function:			media_get_device
  Description:		��ȡ�豸����
  Input: 
  	dev				�豸����
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint8 media_get_device(void)
{
	return g_device;
}




/*************************************************
  Function:			media_set_output_volume
  Description:		������Ƶcodec�������
  Input: 
  	vol				�����ȼ�(0���� - 8���)
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_set_output_volume(uint32 vol)
{
#if 0
	log_printf("media_set_output_volume = %d\n", vol);
	if (vol > 8)
	{
		log_printf("volume parameter more than max level!!!\n");
		vol = 8;
	}
	
	if (vol == 0)
	{
		alsa_set_volume(0);
	}
	else
	{		
		#if (JIEGOU_TYPE == ML8_V1)
		switch (g_device)
		{
			case DEVICE_TYPE_MANAGER:
				alsa_set_volume(V1_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_AREA:
			case DEVICE_TYPE_STAIR:
				alsa_set_volume(V1_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
			case DEVICE_TYPE_FENJI_NET:
				alsa_set_volume(V1_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_PHONE:
			case DEVICE_TYPE_DOOR_NET:
				alsa_set_volume(V1_NETDOOR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_NONE:
			default:
				alsa_set_volume(AudioVolumeLevel[vol]);
				log_printf("vol  %d AudioVolumeLevel[vol] %d\n", vol, AudioVolumeLevel[vol]);
				break;
		}
		#elif (JIEGOU_TYPE == ML8_V7)
		switch (g_device)
		{
			case DEVICE_TYPE_MANAGER:
				alsa_set_volume(V7_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_AREA:
			case DEVICE_TYPE_STAIR:
				alsa_set_volume(V7_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
			case DEVICE_TYPE_FENJI_NET:
				alsa_set_volume(V7_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_PHONE:
			case DEVICE_TYPE_DOOR_NET:
				alsa_set_volume(V7_NETDOOR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_NONE:
			default:
				alsa_set_volume(V7_AudioVolumeLevel[vol]);
				break;
		}
		#elif (JIEGOU_TYPE == ML8_V5)
		switch (g_device)
		{
			case DEVICE_TYPE_MANAGER:
				alsa_set_volume(V5_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_AREA:
			case DEVICE_TYPE_STAIR:
				alsa_set_volume(V5_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
			case DEVICE_TYPE_FENJI_NET:
				alsa_set_volume(V5_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_PHONE:
			case DEVICE_TYPE_DOOR_NET:
				alsa_set_volume(V5_NETDOOR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_NONE:
			default:
				alsa_set_volume(AudioVolumeLevel[vol]);
				break;
		}
		#else
		alsa_set_volume(AudioVolumeLevel[vol]);
		#endif
	}
#endif
	return TRUE;
}

/*************************************************
  Function:			media_set_output_volume_high
  Description:		������Ƶcodec�������
  Input: 
  	vol				�����ȼ�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_set_output_volume_high(uint32 vol)
{
	#if 0
	media_set_output_volume(vol);
	#if 0
	log_printf("media_set_output_volume_high vol = %d\n", vol);
	if (vol > 8)
	{
		log_printf("volume parameter error\n");
		return FALSE;
	}
	
	if (vol == 0)
	{
		Codec_DACMute();
	}
	else
	{
		alsa_set_volume(AudioVolumeLevelHigh[vol]);
		Codec_DACUnMute();
	}
	#endif
	return TRUE;
	#endif
	
	return TRUE;
}

/*************************************************
  Function:			media_set_input_volume
  Description:		������Ƶcodec��������
  Input: 
  	vol				�����ȼ�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_set_input_volume(uint8 vol)
{
	#if 0
	log_printf("media_set_intput_volume = %d\n", vol);
	if (vol > 8)
	{
		vol = 8;
	}
	
	Codec_SetMic(MicVolumeLevel[vol]);
	return TRUE;
	#endif
	
	return TRUE;
}

/*************************************************
  Function:			media_set_talk_volume
  Description:		����ͨ������
  Input: 
  	vol				�����ȼ�(0���� - 8���)
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_set_talk_volume(DEVICE_TYPE_E devtype, uint32 vol)
{
	if (devtype == DEVICE_TYPE_DOOR_PHONE)
	{
		return media_set_analog_output_volume(vol);
	}
	else
	{
		return media_set_output_volume(vol);
	}
}

/*************************************************
  Function:			media_fill_audio_data
  Description:		��������Ƶ�����buf
  Input: 
  	1.data			����ָ��
  	2.len			���ݳ���
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_fill_audio_data(uint8 *data, uint32 len, uint32 time)
{
#if 0
	uint32 ret;
	
	if (LeaveFlag & 0x01)							// ��Ӱ����
	{
		//log_printf("media_fill_audio_data : leave\n");
		leave_fill_data(data, len, time, 0);		// �����Ƶ����
	}
#if 1
	if (g_MediaAuCtrl.mode == AM_NET_TALK)
	{
		ret = talk_audio_put_data(data, len, time);
		if (ret != TRUE)
		{
			return ret;
		}
	}
#endif
	return TRUE;
#endif
return TRUE;
}

/*************************************************
  Function:			media_fill_video_data
  Description:		��������Ƶ�����buf
  Input: 
  	1.data			����ָ��
  	2.len			���ݳ���
  	3.time			ʱ���
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_fill_video_data(uint8 *data, uint32 len, uint32 time)
{
#if 0
	uint32 ret;
	
	if (LeaveFlag & 0x02)							// ��Ӱ����
	{
		leave_fill_data(data, len, time, 1);		// �����Ƶ����
	}
	
	ret = talk_video_put_data(data, len, time);
	if (ret != TRUE)
	{
		log_printf("media_fill_video_data : err\n");
		return ret;
	}

	/*
	if (g_H264File)
	{
		g_DataLen += len;
		if (g_DataLen > 1024*512*5)
		{
			FS_fwrite(LeaveStaticBuf, 1, g_DataLen-len, g_H264File);
			g_DataLen = len;
			memcpy(LeaveStaticBuf, data, len);
		}
		else
		{
			memcpy(LeaveStaticBuf+g_DataLen-len, data, len);
		}
	}
	*/
#endif
	return TRUE;
}

/*************************************************
  Function:			media_full_dispaly_video
  Description:		ȫ����ʾ��Ƶ
  Input: 			
  	1.devtype		�豸����
  	2.flg			1 ȫ�� 0����
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_full_dispaly_video(DEVICE_TYPE_E devtype, uint8 flg)
{
	int32 ret = FALSE;
	if (devtype == DEVICE_TYPE_DOOR_PHONE) // ģ����ǰ��
	{
		ret = media_set_analog_video_win(flg);
	}
	else
	{
		set_full_screen(flg);
		ret = TRUE;
	}
	return ret;
}

/*************************************************
  Function:			media_rtsp_set_full_screen
  Description:		ȫ����ʾ��Ƶ
  Input: 			
   	2.flg			1 ȫ�� 0����
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_rtsp_set_full_screen(uint8 flg)
{
	return rtsp_set_full_screen(flg);
}

/*************************************************
  Function:			media_beep
  Description:		���Ű�����
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
void media_beep(void)
{
	
}

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
uint32 media_snapshot(char *filename, uint32 dstW, uint32 dstH, DEVICE_TYPE_E DevType)
{
	// ģ��״̬�� ��Ƶδ������ץ��ֱ�ӷ��ش���
	if (DEVICE_TYPE_DOOR_PHONE == DevType && g_start_video == 0)
	{
		return FALSE;
	}
	set_jpg_enc_param(filename, dstW, dstH, DevType);
	int32 ret =  open_jpeg_enc();
	if (ret == 0)
	{
		close_jpeg_enc();
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:			media_start_show_pict
  Description:		JPGͼƬ��ʾ
  Input: 			
  	1.filename		ͼ�񱣴���ļ���
  					���>1ʱ�ļ����Զ����ϱ��
	2.pos_x			Ŀ��ͼƬ��ʾX ����
	3.pos_y			Ŀ��ͼƬ��ʾY ����
	4.with			Ŀ��ͼƬ��ʾ���
	5.heigh			Ŀ��ͼƬ��ʾ����
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int32 media_start_show_pict(char *filename, uint16 pos_x, uint16 pos_y, uint16 with, uint16 heigh)
{
	int32 ret = FALSE;
	
	set_jpg_dec_param(filename, pos_x, pos_y, with, heigh);
	ret = open_jpeg_dec();
	if (ret == 0)
	{
		sys_set_view_picture_state(TRUE);
		return TRUE;
	}
	
	return FALSE;
}

/*************************************************
  Function:			media_stop_show_pict
  Description:		�ر�ͼƬ��ʾ
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_show_pict(void)
{
	sys_set_view_picture_state(FALSE);
	close_jpeg_dec();
}

/*************************************************
  Function:			media_enable_audio_aec
  Description:		ʹ���������ӿ�
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_enable_audio_aec(void)
{
	return set_audio_aec_enable(1);
}

/*************************************************
  Function:			media_disable_audio_aec
  Description:		ʹ���������ӿ�
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_disable_audio_aec(void)
{
	return set_audio_aec_enable(0);
}

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
uint32 media_play_sound(char *filename, uint8 IsRepeat, void * proc)
{
	uint8 ret = FALSE;	
	g_Aplay_type = PLAY_AUDIO_TYPE_NONE;
	log_printf("audio file: %s\n", filename);
	if ((media_stream_FileExtCmp((const uint8*)filename, ".wav") == 0)
		|| (media_stream_FileExtCmp((const uint8*)filename, ".WAV")) == 0)
	{
		log_printf(" audio type wav \n");
		ret = play_sound_file(filename, IsRepeat, proc);
		if (HI_SUCCESS == ret)
		{
			g_Aplay_type = PLAY_AUDIO_TYPE_WAV;
			ret = TRUE;
		}
	}
	else if ((media_stream_FileExtCmp((const uint8*)filename, ".mp3") == 0)
		|| (media_stream_FileExtCmp((const uint8*)filename, ".MP3")) == 0)
	{
		log_printf(" audio type mp3 \n");
		ret = mp3_play_start(filename, proc);
		if (RT_SUCCESS == ret)
		{
			g_Aplay_type = PLAY_AUDIO_TYPE_MP3;
			ret = TRUE;
		}
	}
	else
	{
		return FALSE;
	}

	return ret;
}

/*************************************************
  Function:			media_stop_sound
  Description:		ֹͣ����
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
void media_stop_sound (void)
{
	if (g_Aplay_type == PLAY_AUDIO_TYPE_WAV)
	{
		stop_play_file();
	}
	else if (g_Aplay_type == PLAY_AUDIO_TYPE_MP3)
	{
		mp3_play_stop();
	}
	g_Aplay_type = PLAY_AUDIO_TYPE_NONE;
}

/*************************************************
  Function:			media_start_rtsp
  Description:		����rtsp
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
int media_start_rtsp(V_RECT_S rect, char *Url, void *callback_func)
{	
	return rtsp_play_open(rect, Url, callback_func);
}

/*************************************************
  Function:			media_stop_rtsp
  Description:		�ر�rtsp
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
int media_stop_rtsp(void)
{
	return rtsp_play_close();
}

/*************************************************
  Function:			media_pause_lyly
  Description:		��ͣ/�����л�
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
uint32 media_pause_lyly (void)
{
	int ret = lyly_play_pause();
	if (RT_FAILURE == ret)
	{
		return TRUE;
	}
	return TRUE;
}

/*************************************************
  Function:			media_play_lyly
  Description:		������Ӱ�����ļ�
  Input: 			
  	1.filename		�ļ���
  	2.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_play_lyly (char *filename, void * proc)
{
	return lyly_play_start(filename, proc);
}

/*************************************************
  Function:			media_stop_lyly
  Description:		ֹͣ��Ӱ���Բ���
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
void media_stop_lyly (void)
{
	lyly_play_stop();								
}

/*************************************************
  Function:			media_pause_mp3
  Description:		��ͣ/�����л�
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
void media_pause_mp3 (void)
{
	mp3_play_pause();
}

/*************************************************
  Function:			media_play_mp3
  Description:		����MP3�ļ�
  Input: 			
  	1.filename		�ļ���
  	2.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_play_mp3 (char *filename, void * proc)
{
	return mp3_play_start(filename, proc);
}

/*************************************************
  Function:			media_stop_lyly
  Description:		ֹͣ��Ӱ���Բ���
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
void media_stop_mp3 (void)
{
	mp3_play_stop();								
}

/*************************************************
  Function:			media_start_local_record
  Description:		��������¼��
  Input: 			
  	1.filename		�ļ���
  	2.maxtime		¼�Ƶ��ʱ��
  	3.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_local_record(char *filename)
{
	uint32 ret;

	#if 0
	ret = set_avi_record_param(LWM_AUDIO, PT_G711A, PT_H264, filename);
	if (ret == FALSE)
	{
		return FALSE;
	}

	ret = lyly_record_start();
	if (ret != 0)
	{
		log_printf("error : lyly_record_start return : %d \n", ret);
		goto error0;
	}

	set_audio_codec_param(&AudioParam, BYTES_PER_PACKET_SHORT);
	ret = open_audio_enc();
	if (ret != 0)
	{
		log_printf("error : open_audio_enc return : %d \n", ret);
		goto error1;
	}	
	else
	{
		// ��ҪΪ�˽�rtp����ʱǰ���������ֽ�00 00 00 01 ����ȥ��
		open_audio_local_enc();
	}

	ret = open_audio_ai();
	if (ret != 0)
	{
		log_printf("error : open_audio_ai return : %d \n", ret);
		goto error2;
	}
	else
	{
		media_disable_audio_aec();
	}
	
	ms_media_link(mMediaStream.AudioSfEnc, mMediaStream.AviRecord);
	ms_media_link(mMediaStream.AudioAI, mMediaStream.AudioSfEnc);
	
	return TRUE;
	
error2:
	close_audio_enc();
error1:
	lyly_record_stop();	
error0:	
	printf("media_start_local_record return error !!!!\n");
	return FALSE;
	#else
	ret = open_audio_ai();
	if (ret != 0)
	{
		log_printf("error : open_audio_ai return : %d \n", ret);
		goto error0;
	}
	else
	{
		media_disable_audio_aec();
	}

	set_audio_codec_param(&AudioParam, BYTES_PER_PACKET_SHORT);
	ret = open_audio_enc();
	if (ret != 0)
	{
		log_printf("error : open_audio_enc return : %d \n", ret);
		goto error1;
	}	
	else
	{
		// ��ҪΪ�˽�rtp����ʱǰ���������ֽ�00 00 00 01 ����ȥ��
		open_audio_local_enc();
	}
	
	ret = set_avi_record_param(LWM_AUDIO, PT_G711A, PT_H264, filename);
	if (ret == FALSE)
	{
		return FALSE;
	}

	ret = lyly_record_start();
	if (ret != 0)
	{
		log_printf("error : lyly_record_start return : %d \n", ret);
		goto error2;
	}

	ms_media_link(mMediaStream.AudioSfEnc, mMediaStream.AviRecord);
	ms_media_link(mMediaStream.AudioAI, mMediaStream.AudioSfEnc);
	
	return TRUE;
	
error2:
	close_audio_enc();
error1:
	close_audio_ai();
error0: 
	printf("media_start_local_record return error !!!!\n");
	return FALSE;
	#endif
}

/*************************************************
  Function:			media_stop_local_record
  Description:		ֹͣ����¼��
  Input: 			
  	1.issave		�Ƿ񱣴�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_local_record(void)
{
	close_audio_ai();
	close_audio_enc();
	lyly_record_stop();

	ms_media_unlink(mMediaStream.AudioSfEnc, mMediaStream.AviRecord);
	ms_media_unlink(mMediaStream.AudioAI, mMediaStream.AudioSfEnc);
}

/*************************************************
  Function:			media_get_total_time
  Description:		��ȡý���ļ�����ʱ��
  Input: 			��
  Output:			��
  Return:			��ʱ�� ��λ:s
  Others:			�����Ӱ������:����Ƶģʽ�Ļ�
  					������ȡ������ȷ��ʱ��
  					��ʱû������ģʽ
*************************************************/
uint32 media_get_total_time(void)
{
	//return (g_MediaAuCtrl.totaltime/1000);
	return 0;
}

/*************************************************
  Function:    		media_w_close
  Description: 		
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void media_w_close(void)
{
	
}

/*************************************************
  Function:		media_clear_fb
  Description: 	���fb
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
int32 media_clear_fb(void)
{
	unsigned char *pLCMBuffer = NULL;             // fb ӳ���ַ
	struct fb_var_screeninfo fb_vinfo;
	struct fb_fix_screeninfo fb_finfo;
	
	int FB_FD = open( "/dev/fb0", O_RDWR );
	if (FB_FD <= 0)
	{
		log_printf( "### Error: cannot open FB device, returns %d!\n", FB_FD );
		return FALSE;
	}

	if (ioctl(FB_FD, FBIOGET_VSCREENINFO, &fb_vinfo))
	{
		log_printf( "ioctl FBIOGET_VSCREENINFO failed!\n" );
		close(FB_FD);
		return FALSE;
	}

	if (ioctl(FB_FD, FBIOGET_FSCREENINFO, &fb_finfo))
	{
		log_printf( "ioctl FBIOGET_FSCREENINFO failed!\n" );
		close(FB_FD);
        return FALSE;
    }

	// Map the device to memory
	pLCMBuffer = mmap( NULL, (fb_finfo.line_length * fb_vinfo.yres ), PROT_READ|PROT_WRITE, MAP_SHARED, FB_FD, 0 );
	if ((int)pLCMBuffer == -1 )
	{
		log_printf( "### Error: failed to map LCM device to memory!\n" );
		return FALSE;
	}
	else
	{
		log_printf( "### LCM Buffer at:%p, width = %d, height = %d, line_length = %d.\n\n", pLCMBuffer, fb_vinfo.xres, fb_vinfo.yres, fb_finfo.line_length );
	}
	
	memset(pLCMBuffer, 0x00, (fb_finfo.line_length * fb_vinfo.yres ));
	usleep(1000);

	munmap(pLCMBuffer, (fb_finfo.line_length * fb_vinfo.yres ));
	close(FB_FD);
	FB_FD = -1;
	pLCMBuffer = NULL;
	return TRUE;
}

/*************************************************
  Function:		init_media
  Description: 	ý���ʼ��
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void media_init(void)
{
	ms_media_init();
	ms_rtp_session_Init();

	mMediaStream.AlawAgc = ms_media_new(MS_ALAW_AGC_ID);
	mMediaStream.Speex = ms_media_new(MS_SPEEX_ID);
	mMediaStream.AudioDec= ms_media_new(MS_ALAW_DEC_ID);
	mMediaStream.AudioRtpSend = ms_media_new(MS_RTP_SEND_A_ID);
	mMediaStream.AudioRtpRecv = ms_media_new(MS_RTP_RECV_A_ID);
	mMediaStream.AudioSfEnc = ms_media_new(MS_ALAW_SF_ENC_ID);
	mMediaStream.VideoDec = ms_media_new(MS_H264_DEC_ID);
	mMediaStream.VideoRtpRecv = ms_media_new(MS_RTP_RECV_V_ID);
	mMediaStream.JpegDec  = ms_media_new(MS_JPEG_DEC_ID);
	mMediaStream.JpegEnc  = ms_media_new(MS_JPEG_ENC_ID);
	mMediaStream.FilePlayer = ms_media_new(MS_FILE_PLAYER_ID);
	mMediaStream.AudioAI = ms_media_new(MS_AUDIO_AI_ID);
	mMediaStream.AudioAo = ms_media_new(MS_ALAW_AO_ID);
	mMediaStream.AviPlay = ms_media_new(MS_AVI_PLAY_ID);
	mMediaStream.Mp3Play = ms_media_new(MS_MP3_PLAY_ID);
	mMediaStream.AviRecord = ms_media_new(MS_AVI_RECORD_ID);	
	mMediaStream.LylyFilePlayer = ms_media_new(MS_FILE_LYLY_ID);
	mMediaStream.RtspPlay = ms_media_new(MS_RTSP_PLAY_ID);
}

