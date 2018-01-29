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
#include "logic_play_lyly_hit.h"


#define LEAVE_PIC_TYPE			".jpg"
#define LEAVE_AVI_TYPE			".avi"
#define LEAVE_WAV_TYPE			".wav"


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
uint8 Ring_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};

uint8 V2_STAIR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V2_CENTER_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V2_NETDOOR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V2_ROOM_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};

uint8 VXM_STAIR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 VXM_CENTER_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 VXM_NETDOOR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 VXM_ROOM_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};

uint8 V7M_STAIR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V7M_CENTER_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V7M_NETDOOR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V7M_ROOM_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};

uint8 E81M_STAIR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 E81M_CENTER_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 E81M_NETDOOR_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 E81M_ROOM_AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};


static uint8 ChangVideoWin = 0;
static struct ThreadInfo VideoPreviewThread;		// ģ����ǰ����ƵԤ���߳�
static PLAY_AUDIO_TYPE_E g_Aplay_type;				// ���ŵ���Ƶ����
MediaStream mMediaStream;

static uint8 g_Video_Flg = FALSE;								// �Ƿ�����Ƶ��־
static uint8 g_DealVideo = FALSE;



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
	//return rtsp_set_full_screen(flg);
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
	//return rtsp_play_open(rect, Url, callback_func);
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
	//return rtsp_play_close();
}




#if 1
#endif
/*************************************************
  Function:				set_video_enc_param
  Description:			���ñ�����Ƶ����
  Input:
  Output:				��
  Return:				��
  Others:
*************************************************/
static void media_get_video_size(int imgSize, int *width, int *heigth)
{
	switch (imgSize)
	{
		case VIDEO_SIZE_QQVGA:
			{
				*width  = 160;
				*heigth = 120;
			}
			break;
		case VIDEO_SIZE_QCIF:
			{
				*width  = 176;
				*heigth = 144;
			}
			break;

		case VIDEO_SIZE_QVGA:
			{
				*width  = 320;
				*heigth = 240;
			}
			break;

		case VIDEO_SIZE_CIF:
			{
				*width  = 352;
				*heigth = 288;
			}
			break;

		case VIDEO_SIZE_VGA:
			{
				*width  = 640;
				*heigth = 480;
			}
			break;

		default:
			{
				*width  = 640;
				*heigth = 480;
			}
			break;		
	}
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
static void media_fill_LylyRecordCtrl(LEAVE_WORD_MODE_E mode, char * filename)
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
  Function:			media_stream_FileExtCmp
  Description:		��ѯ�ļ�����
  Input:
  Output:			��
  Return:			�ɹ���ʧ��
  Others:
*************************************************/
int media_stream_FileExtCmp(const char* pu8FileName, const char* pu8Ext)
{
	int32		i32Len1 = strlen((char*)pu8FileName);
	int32		i32Len2 = strlen(pu8Ext);
	uint8*	pu8Tmp = (uint8*)(pu8FileName + (i32Len1 - i32Len2));

	if (i32Len2 > i32Len1)
		return -1;

	return strcasecmp((char*)pu8Tmp, pu8Ext);
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
static uint32 media_set_analog_video_win(uint8 flag)
{
/*
	media_stop_video_preview();
	
	if (FALSE == flag)
	{
		return media_start_video_preview(PREVIEW_XPOS, PREVIEW_YPOS, PREVIEW_WIDTH, PREVIEW_HEIGHT); 
	}
	else
	{
		return media_start_video_preview(PREVIEW_XPOS, PREVIEW_YPOS, PREVIEW_FULL_WIDTH, PREVIEW_FULL_HEIGHT); 
	}
*/
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
	log_printf("media_set_output_volume = %d\n", vol);
	#ifdef _DOOR_PHONE_
	hw_mk_volume_ctrl(1);
	/*
	if (MEDIA_CTRL_VOLUME > g_VolumeLevel)
	{
		hw_mk_volume_up((MEDIA_CTRL_VOLUME-g_VolumeLevel)*2);
	}
	else if (MEDIA_CTRL_VOLUME < g_VolumeLevel)
	{
		hw_mk_volume_down((g_VolumeLevel-MEDIA_CTRL_VOLUME)*2);
	}
	else
	{
		// ������Ȳ�����
	}
	g_VolumeLevel = MEDIA_CTRL_VOLUME;
	*/
	if (0 == vol)
	{	
		hw_mk_volume_ctrl(0);
		return TRUE;
	}
	else
	{
		//hw_mk_volume_ctrl(1);
	}
	#endif
	
	if (vol > 8)
	{
		log_printf("volume parameter more than max level!!!\n");
		vol = 8;
	}
	
	if (vol == 0)
	{
		Alsa_Play_SetVolume(0);
	}
	Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
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
	#ifdef _DOOR_PHONE_
	if (devtype == DEVICE_TYPE_DOOR_PHONE)
	{
		hw_mk_volume_ctrl(1);		
		//return media_set_analog_output_volume(vol);
		vol = (vol <= 0) ? 0 : vol;
		vol = (vol >= 8) ? 8 : vol;
		log_printf("vol: %d\n", vol);
		/*
		if (TRUE == mute)
		{
			hw_mk_volume_ctrl(0);
		}			
		else
		{
			if (vol > g_VolumeLevel)
			{
				hw_mk_volume_up((vol-g_VolumeLevel)*2);
			}
			else if (vol < g_VolumeLevel)
			{
				hw_mk_volume_down((g_VolumeLevel-vol)*2);
			}
			else
			{
				// ������Ȳ�����
			}
			g_VolumeLevel = vol;

			// �������������� �ٿ���ctrl�����������ܳ�����
			if (0 == vol)
			{
				hw_mk_volume_ctrl(0);
			}
			else
			{
				//hw_mk_volume_ctrl(1);	
			}
		}
		*/
	}
	else	
	{
		#ifdef _DOOR_PHONE_
		hw_mk_volume_ctrl(1);
		/*
		if (TRUE == mute)
		{
			hw_mk_volume_ctrl(0);
			return TRUE;
		}			
		else
		{
			if (MEDIA_CTRL_VOLUME > g_VolumeLevel)
			{
				hw_mk_volume_up((MEDIA_CTRL_VOLUME-g_VolumeLevel)*2);
			}
			else if (MEDIA_CTRL_VOLUME < g_VolumeLevel)
			{
				hw_mk_volume_down((g_VolumeLevel-MEDIA_CTRL_VOLUME)*2);
			}
			else
			{
				// ������Ȳ�����
			}
			g_VolumeLevel = MEDIA_CTRL_VOLUME;

			if (0 == vol)
			{
				hw_mk_volume_ctrl(0);
				return TRUE;
			}
			else
			{
				//hw_mk_volume_ctrl(1);	
			}
		}*/
		#endif

		vol = (vol <= 0) ? 0 : vol;
		vol = (vol >= 8) ? 8 : vol;
		log_printf("vol: %d\n", vol);
			
		if (vol == 0)
		{
			Alsa_Play_SetVolume(0);
		}
		else
		{										
			#if (JIEGOU_TYPE == RV1108_M4_DV7)
			switch (devtype)
			{
				case DEVICE_TYPE_MANAGER:
					Alsa_Play_SetVolume(M4_DV7_CENTER_AudioVolumeLevel[vol]);
					break;

				case DEVICE_TYPE_ROOM:
					Alsa_Play_SetVolume(M4_DV7_ROOM_AudioVolumeLevel[vol]);
					break;

				case DEVICE_TYPE_FENJI_NET:
					Alsa_Play_SetVolume(M4_DV7_FENJI_NET_AudioVolumeLevel[vol]);
					break;
					
				case DEVICE_TYPE_NONE:
				default:
					Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
					break;
			}	
			#elif (JIEGOU_TYPE == RV1108_M4_DV7S)
			switch (devtype)
			{
				case DEVICE_TYPE_MANAGER:
					Alsa_Play_SetVolume(M4_DV7S_CENTER_AudioVolumeLevel[vol]);
					break;

				case DEVICE_TYPE_ROOM:
					Alsa_Play_SetVolume(M4_DV7S_ROOM_AudioVolumeLevel[vol]);
					break;

				case DEVICE_TYPE_FENJI_NET:
					Alsa_Play_SetVolume(M4_DV7S_FENJI_NET_AudioVolumeLevel[vol]);
					break;
					
				case DEVICE_TYPE_NONE:
				default:
					Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
					break;
			}	
			#else
			Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
			#endif
		}
		return TRUE;
	}
	#else
	vol = (vol <= 0) ? 0 : vol;
	vol = (vol >= 8) ? 8 : vol;
	log_printf("vol: %d\n", vol);
		
	if (vol == 0)
	{
		Alsa_Play_SetVolume(0);
	}
	else
	{			

		#if (JIEGOU_TYPE == ML8_V2)
		switch (devtype)
		{
			case DEVICE_TYPE_MANAGER:
				Alsa_Play_SetVolume(V2_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
				Alsa_Play_SetVolume(V2_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_STAIR:
				Alsa_Play_SetVolume(V2_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_NET:
				Alsa_Play_SetVolume(V2_NETDOOR_AudioVolumeLevel[vol]);
				break;
				
			case DEVICE_TYPE_NONE:
			default:
				Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
				break;
		}	
		#elif (JIEGOU_TYPE == ML8_V7M)
		switch (devtype)
		{
			case DEVICE_TYPE_MANAGER:
				Alsa_Play_SetVolume(V7M_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
				Alsa_Play_SetVolume(V7M_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_STAIR:
				Alsa_Play_SetVolume(V7M_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_NET:
				Alsa_Play_SetVolume(V7M_NETDOOR_AudioVolumeLevel[vol]);
				break;
				
			case DEVICE_TYPE_NONE:
			default:
				Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
				break;
		}
		#elif (JIEGOU_TYPE == ML8_V5M || JIEGOU_TYPE == ML8_V6M || JIEGOU_TYPE == ML8_V8M)
		switch (devtype)
		{
			case DEVICE_TYPE_MANAGER:
				Alsa_Play_SetVolume(VXM_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
				Alsa_Play_SetVolume(VXM_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_STAIR:
				Alsa_Play_SetVolume(VXM_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_NET:
				Alsa_Play_SetVolume(VXM_NETDOOR_AudioVolumeLevel[vol]);
				break;
				
			case DEVICE_TYPE_NONE:
			default:
				Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
				break;
		}	
		#elif (JIEGOU_TYPE == AH8_E81M || JIEGOU_TYPE == AH8_F91M)
		switch (devtype)
		{
			case DEVICE_TYPE_MANAGER:
				Alsa_Play_SetVolume(E81M_CENTER_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_ROOM:
				Alsa_Play_SetVolume(E81M_ROOM_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_STAIR:
				Alsa_Play_SetVolume(E81M_STAIR_AudioVolumeLevel[vol]);
				break;

			case DEVICE_TYPE_DOOR_NET:
				Alsa_Play_SetVolume(E81M_NETDOOR_AudioVolumeLevel[vol]);
				break;
				
			case DEVICE_TYPE_NONE:
			default:
				Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
				break;
		}
		#else
		Alsa_Play_SetVolume(Ring_AudioVolumeLevel[vol]);
		#endif
	}
	return TRUE;
	#endif
}

/*************************************************
  Function:			media_enable_audio_ai
  Description:		ʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_enable_audio_ai(void)
{
	return audio_ai_enable();
}

/*************************************************
  Function:			media_disable_audio_ai
  Description:		ȥʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_disable_audio_ai(void)
{
	return audio_ai_disable();
}

/*************************************************
  Function:			media_enable_audio_dec
  Description:		ʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_enable_audio_dec(void)
{
	return audio_dec_enable();
}

/*************************************************
  Function:			media_disable_audio_dec
  Description:		ȥʹ����Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int media_disable_audio_dec(void)
{
	return audio_dec_disable();
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
	return audio_aec_enable();
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
	return audio_aec_disable();
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
	return audio_sendaddr_add(IP, AudioPort);
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
	audio_sendaddr_del(IP, AudioPort);
	log_printf("media_del_audio_send_addr\n");
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
	if (PLAY_AUDIO_TYPE_NONE != g_Aplay_type)
	{
		media_stop_sound();
	}

	#ifdef _DOOR_PHONE_
	mag_hw_mk_talk_mode(DIGITAL_RING);
	#endif

	log_printf("audio file: %s\n", filename);
	if ((media_stream_FileExtCmp((const uint8*)filename, ".wav") == 0)
		|| (media_stream_FileExtCmp((const uint8*)filename, ".WAV")) == 0)
	{
		log_printf(" audio type wav \n");
		int repeat = IsRepeat;
		ret = open_audio_mode(AS_PLAY, (void *)filename, &repeat, proc);
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
		int repeat = IsRepeat;
		ret = open_audio_mode(AS_PLAY, (void *)filename, &repeat, proc);
		if (RT_SUCCESS == ret)
		{
			g_Aplay_type = PLAY_AUDIO_TYPE_MP3;
			ret = TRUE;
		}
	}
	else
	{
		ret = FALSE;
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
		close_audio_mode(AS_PLAY);
	}
	else if (g_Aplay_type == PLAY_AUDIO_TYPE_MP3)
	{
		close_audio_mode(AS_PLAY);
	}

	#ifdef _DOOR_PHONE_
	if(PLAY_AUDIO_TYPE_NONE != g_Aplay_type)
	{
		mag_hw_mk_talk_mode(ANALOG_IDLE);
	}
	#endif
	g_Aplay_type = PLAY_AUDIO_TYPE_NONE;
}

/*************************************************
  Function:			meida_start_phone_lyly_hint
  Description:		ģ����ǰ�������������ʾ��״̬
  Input: 			
  	2.filename		�ļ���
  	4.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 meida_start_phone_lyly_hint(char *filename, void * proc)
{
	uint8 ret = FALSE;
	if (PLAY_AUDIO_TYPE_NONE != g_Aplay_type)
	{
		media_stop_sound();
	}

	log_printf("audio file: %s\n", filename);
	if ((media_stream_FileExtCmp((const uint8*)filename, ".wav") == 0)
		|| (media_stream_FileExtCmp((const uint8*)filename, ".WAV")) == 0)
	{
		log_printf(" audio type wav \n");
		int repeat = FALSE;
		ret = open_audio_mode(AS_PLAY, (void *)filename, &repeat, proc);
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
		int repeat = FALSE;
		ret = open_audio_mode(AS_PLAY, (void *)filename, &repeat, proc);
		if (RT_SUCCESS == ret)
		{
			g_Aplay_type = PLAY_AUDIO_TYPE_MP3;
			ret = TRUE;
		}
	}
	else
		return FALSE;

	return ret;
}

/*************************************************
  Function:			meida_stop_phone_lyly_hint
  Description:		ģ����ǰ�������������ʾ��״̬
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void meida_stop_phone_lyly_hint(void)
{
	if (g_Aplay_type == PLAY_AUDIO_TYPE_WAV)
	{
		//audio_file_play_stop();
		close_audio_mode(AS_PLAY);
	}
	else if (g_Aplay_type == PLAY_AUDIO_TYPE_MP3)
	{
		close_audio_mode(AS_PLAY);
	}
	g_Aplay_type = PLAY_AUDIO_TYPE_NONE;
}

/*************************************************
  Function:			media_start_net_audio_record
  Description:		��������¼��
  Input: 			
  	1.filename		�ļ���
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_audio_record(char *filename, uint32 address)
{
	uint32 recv_ip = address;
	int ret = open_audio_mode(AS_NET_RECORD, (void *)filename, (void *)&recv_ip, NULL);
	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:			media_stop_net_audio_record
  Description:		ֹͣ����¼��
  Input: 			
  	1.issave		�Ƿ񱣴�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_net_audio_record(void)
{
	close_audio_mode(AS_NET_RECORD);
}

/*************************************************
  Function:			media_start_jrly_record
  Description:		��������¼��
  Input: 			
  	1.filename		�ļ���
  	2.maxtime		¼�Ƶ��ʱ��
  	3.proc			�ص�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_jrly_record(char *filename)
{
	int ret = open_audio_mode(AS_JRLY_RECORD, (void *)filename, NULL, NULL);
	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:			media_stop_jrly_record
  Description:		ֹͣ����¼��
  Input: 			
  	1.issave		�Ƿ񱣴�
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_jrly_record(void)
{
	close_audio_mode(AS_JRLY_RECORD);
}


/*************************************************
  Function:			media_start_net_hint
  Description:		����������ʾ������
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_hint(uint8 RemoteDeviceType, char *filename, void * proc)
{
	int ret = FALSE;
	AUDIO_HIT_PARAM param;
	memset(&param, 0, sizeof(AUDIO_HIT_PARAM));
	if ((media_stream_FileExtCmp((const uint8*)filename, ".wav") == 0)
		|| (media_stream_FileExtCmp((const uint8*)filename, ".WAV")) == 0)
	{
		param.FileType = FILE_WAVE;
	}
	else							
	{
		return FALSE;
	}

	strcpy(param.filename, filename);
	param.IsPack = TRUE;
	param.PackNum = 6;
	if (DEVICE_TYPE_STAIR == RemoteDeviceType)
	{
		param.PerFrameNum = 1;		// �ݿڻ�ÿ֡80
	}
	else
	{
		param.PerFrameNum = param.PackNum;
	}
		
	ret = open_audio_mode(AS_HINT_LYLY, (void *)&param, proc, NULL);
	if (HI_SUCCESS == ret)
	{
		ret = TRUE;
	}
	
	return ret;
}

/*************************************************
  Function:			media_stop_net_hint
  Description:		ֹͣ��ʾ������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_net_hint(void)
{
	close_audio_mode(AS_HINT_LYLY);
}

/*************************************************
  Function:			media_start_net_audio
  Description:		����������Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_audio(int address)
{	
	int addr = address;
	int ret = open_audio_mode(AS_NETTALK,  &addr, NULL, NULL);
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
	//driver_speak_off();
	close_audio_mode(AS_NETTALK);	
	return;
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
uint32 media_snapshot(char *filename, void *proc, DEVICE_TYPE_E DevType)
{
	int ret = RT_FAILURE;
	if (DEVICE_TYPE_DOOR_PHONE == DevType)
	{
		ret = open_video_mode(VS_LOCAL_SNAP, (void *)filename, proc, NULL);
	}
	else
	{
		if (g_Video_Flg == TRUE)
		{
			ret = open_video_mode(VS_NET_SNAP, (void *)filename, proc, NULL);
		}
	}

	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
		
	return FALSE;
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
	int ret = video_lyly_play_pause();
	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
		
	return FALSE;
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
	#ifdef _DOOR_PHONE_
	mag_hw_mk_talk_mode(DIGITAL_RING);
	#endif
	
	int ret = open_video_mode(VS_LYLY_PLAY, (void *)filename, proc, NULL);
	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
		
	return FALSE;
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
	close_video_mode(VS_LYLY_PLAY);
	#ifdef _DOOR_PHONE_
	mag_hw_mk_talk_mode(ANALOG_IDLE);
	#endif

}


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
	// ��Ƶ�Ѿ��������ٿ���
	if (g_Video_Flg == TRUE)
	{
		return TRUE;
	}

	if (g_DealVideo == TRUE)
	{
		int times = 20;
		while (g_DealVideo == TRUE && times > 0)
		{
			times--;			
			usleep(100*1000);
		}

		if (g_DealVideo == TRUE)
		{
			printf("media_start_net_video fail !!! \n");
			return FALSE;
		}
	}
	
	VIDEO_STATE_E VideoMode = VS_NONE;
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
	
	uint32 ip = address;
	int ret = open_video_mode(VideoMode, &ip, NULL, NULL);
	if (ret == 0)
	{
		g_Video_Flg = TRUE;
		return TRUE;
	}
	return FALSE;
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
	g_Video_Flg = FALSE;
	g_DealVideo = TRUE;
	
	VIDEO_STATE_E VideoMode = VS_NONE;
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
		g_DealVideo = FALSE;
		return ;
	}
	close_video_mode(VideoMode);
	g_DealVideo = FALSE;
	return;
}

/*************************************************
  Function:			media_start_video_preview
  Description:		��ƵԤ��
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_video_preview(int x, int y, int w, int h)
{
#if 0
	int ret = rk_media_start_video_preview(x, y, w, h);
	if (-1 == ret)
	{
		err_printf(" :return err !!!\n");
		return FALSE;
	}
#endif
	return TRUE;
}

/*************************************************
  Function:			media_stop_video_preview
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_video_preview(void)
{
	//rk_media_stop_video_preview();
}

/*************************************************
  Function:			media_start_show_win
  Description:		fb��Ԥ��
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_show_win(void)
{
	video_jpeg_dec_show();
/*
	int ret = rk_media_show_win();
	if (-1 == ret)
	{
		err_printf(" :return err !!!\n");
		return FALSE;
	}
*/
	return TRUE;
}

/*************************************************
  Function:			media_start_display_jpeg
  Description:		ͼƬԤ��
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int32 media_start_display_jpeg(char *filename, uint16 pos_x, uint16 pos_y, uint16 with, uint16 heigh)
{
/*
	int ret = rk_media_start_display_jpeg(filename, pos_x, pos_y, with, heigh);
	if (-1 == ret)
	{
		err_printf(" :return err !!!\n");
		return FALSE;
	}
*/
	return TRUE;
}

/*************************************************
  Function:			media_start_decode_jpeg_2fb
  Description:		ͼƬ��䵽fb ����δ����ʾ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int32 media_start_decode_jpeg_2fb(char *filename, uint16 pos_x, uint16 pos_y, uint16 with, uint16 heigh, int clearfb)
{
/*
	int ret = rk_media_start_decode_jpeg_2fb(filename, pos_x, pos_y, with, heigh, clearfb);
	if (-1 == ret)
	{
		err_printf(" :return err !!!\n");
		return FALSE;
	}
*/
	return TRUE;
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
  Others:			����ͼƬֱ����ʾ ���Ե��ñ��ӿ�
*************************************************/
int32 media_start_show_pict(char *filename, uint16 pos_x, uint16 pos_y, uint16 with, uint16 heigh)
{
	int32 ret = FALSE;
	int sync = TRUE;		// ����ͼƬֱ����ʾ 
	set_jpg_dec_param(filename, pos_x, pos_y, with, heigh);
	ret =  open_video_mode(VS_JPEG_SHOW, &sync, NULL, NULL);
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
	close_video_mode(VS_JPEG_SHOW);
}


/*************************************************
  Function:			media_start_local_video_record
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_local_video_record(char *filename)
{
	int ret = open_video_mode(VS_LOCAL_RECORD, (void *)filename, NULL, NULL);	
	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:			media_stop_local_video_record
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_local_video_record(void)
{
	close_video_mode(VS_LOCAL_RECORD);
}

/*************************************************
  Function:			media_start_net_video_record
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_net_video_record(char *filename, uint32 address)
{
	int ret = RT_FAILURE;
	if (g_Video_Flg == TRUE)
	{
		uint32 recv_ip = address;
		ret = open_video_mode(VS_NET_RECORD, (void *)filename, (void *)&recv_ip, NULL);
	}
	
	if (RT_SUCCESS == ret)
	{
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:			media_stop_net_video_record
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
void media_stop_net_video_record(void)
{
	close_video_mode(VS_NET_RECORD);
}

/*************************************************
  Function:			meida_start_net_leave_rec
  Description:		������������¼��
  Input: 			
  	1.mode			¼�Ƶ�ģʽ
  	2.address		�Զ�IP
  	4.filename		������ļ���
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 meida_start_net_leave_rec(LEAVE_WORD_MODE_E mode, uint32 address, char * filename)
{
	if (mode == LWM_NONE)
	{
		return FALSE;
	}
	media_fill_LylyRecordCtrl(mode, filename);

	if (mode == LWM_AUDIO_VIDEO)
	{
		return media_start_net_video_record(filename, address);
	}
	else
	{
		if (mode == LWM_AUDIO_PIC)
		{
			char picname[100] = {0};
			sprintf(picname, "%s%s", filename, LEAVE_PIC_TYPE);
			log_printf("snap name ; %s\n ", picname);
			media_snapshot(picname, NULL, DEVICE_TYPE_NONE);
		}
		
		return media_start_net_audio_record(filename, address);
	}

	return TRUE;
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

	if (g_LylyRecordCtrl.mode == LWM_AUDIO_VIDEO)
	{
		media_stop_net_video_record();
	}
	else
	{
		media_stop_net_audio_record();
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
  Function:			media_take_screen_capture
  Description:		��Ļץ��
  Input: 			��
  Output:			��
  Return:			
  Others:
*************************************************/
uint32 media_take_screen_capture(void)
{
/*
	int ret = rk_media_take_screen_capture();
	if (ret == -1)
	{
		return FALSE;
	}
*/
	return TRUE;
}

/*************************************************
  Function:		media_set_color_key
  Description: 	���ùؼ�ɫ
  Input: 		
  	color		ARGB
  Output:		��
  Return:		��
  Others:	
*************************************************/
void media_set_color_key(uint32 color)
{
	VideoSetColorKey(color);
}

/*************************************************
  Function:		media_save_fb_date
  Description: 	����fb����
  Input: 		
  	fb_index	ͼ�� 0 1 2
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 media_save_fb_date(uint8 fb_index)
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
	pLCMBuffer = mmap( NULL, (fb_finfo.line_length * fb_vinfo.yres )*(fb_index+1), PROT_READ|PROT_WRITE, MAP_SHARED, FB_FD, 0 );
	if ((int)pLCMBuffer == -1 )
	{
		log_printf( "### Error: failed to map LCM device to memory!\n" );
		return FALSE;
	}
	else
	{
		log_printf( "### LCM Buffer at:%p, width = %d, height = %d, line_length = %d.\n\n", pLCMBuffer, fb_vinfo.xres, fb_vinfo.yres, fb_finfo.line_length );
	}
	
	//memset(pLCMBuffer, 0x00, (fb_finfo.line_length * fb_vinfo.yres ));
	//usleep(1000);
	char filename[128] = {0};
	sprintf(filename, "%s/yuv_fb%d.yuv", CFG_PUBLIC_DRIVE, fb_index);
	log_printf("filename[%s]\n", filename);
	FILE *pYUV = fopen(filename, "wb");
	fwrite(pLCMBuffer+(fb_finfo.line_length * fb_vinfo.yres )*fb_index, (fb_finfo.line_length * fb_vinfo.yres ), 1, pYUV);
	FSFlush(pYUV);
	fclose(pYUV);
	
	munmap(pLCMBuffer, (fb_finfo.line_length * fb_vinfo.yres )*(fb_index+1));
	close(FB_FD);
	FB_FD = -1;
	pLCMBuffer = NULL;
	return TRUE;
}

/*************************************************
  Function:		media_clear_fb
  Description: 	���fb
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 media_clear_fb(void)
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

#ifdef _ENABLE_CLOUD_
static uint8 g_CloudVideoFlg = FALSE;								// �Ƿ�����Ƶ��־
static uint8 g_CloudDealVideo = FALSE;

/*************************************************
  Function:			media_enable_cloud_audio_send
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_enable_cloud_audio_send()
{
	int ret = audio_cloud_send_enable();
	if (ret == -1)
	{
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:			media_disable_cloud_audio_send
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_disable_cloud_audio_send()
{
	int ret = audio_cloud_send_disable();
	if (ret == -1)
	{
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:			media_enable_cloud_audio_recv
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_enable_cloud_audio_recv()
{
	int ret = audio_cloud_recv_enable();
	if (ret == -1)
	{
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:			media_disable_cloud_audio_recv
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_disable_cloud_audio_recv()
{
	int ret = audio_cloud_recv_disable();
	if (ret == -1)
	{
		return FALSE;
	}

	return TRUE;
}

uint32 media_set_cloud_audio_send_func(void *func)
{
	int ret = set_cloud_audio_send_func(func);
	if (ret == -1)
	{
		printf(" set_cloud_audio_send_func return err !!!\n");
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:    		media_send_audio_data
  Description: 		
  Input:		��
  Output:		��
  Return:		��	
  Others:
*************************************************/
int media_send_audio_data(char *data)
{
	send_cloud_audio_data(data);
}

/*************************************************
  Function:			media_start_cloud_audio
  Description:		�����ƶ���Ƶ����
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_cloud_audio(void)
{
	int ret = open_audio_mode(AS_CLOUD_TALK, NULL, NULL, NULL);
	if (ret == -1)
	{
		return FALSE;
	}
	
	return TRUE;
}

/*************************************************
  Function:			media_stop_cloud_audio
  Description:		
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_cloud_audio(void)
{
	log_printf("net_stop_audio\n");
	//driver_speak_off();
	close_audio_mode(AS_CLOUD_TALK);
	
	return;
}

/*************************************************
  Function:				media_set_cloud_video_enc_param
  Description:			���ñ�����Ƶ����
  Input:
  	1��pvideoparam		��Ƶ����
  	2��single			1 ��ʾ�Խ��жԷ��豸ֻ��һ̨
  	3��iswifi			wifiģʽ ��Ƶ������Ҫ������
  Output:				��
  Return:				��
  Others:
*************************************************/
void media_set_cloud_video_enc_param(VIDEO_SDP_PARAM *videoparam)
{
	int width, heigth;
	video_params EncParam;
	media_get_video_size(videoparam->imgSize, &width, &heigth);
	EncParam.bit_rate = videoparam->bitRate;
	EncParam.framerate = videoparam->frameRate;
	EncParam.width = width;
	EncParam.height = heigth;
	set_cloud_video_param(&EncParam);
}

/*************************************************
  Function:			media_enable_cloud_video_send
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_enable_cloud_video_send()
{
	int ret = video_cloud_enable_send();
	if (ret == -1)
	{
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:			media_disable_cloud_video_send
  Description:		
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_disable_cloud_video_send()
{
	int ret = video_cloud_disable_send();
	if (ret == -1)
	{
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:			media_set_cloud_video_send_func
  Description:		
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
uint32 media_set_cloud_video_send_func(void *func)
{
	int ret = video_cloud_set_send_func(func);
	if (ret == -1)
	{
		printf(" video_cloud_set_send_func return err !!!\n");
		return FALSE;
	}

	return TRUE;
}

/*************************************************
  Function:			media_cloud_request_IFrame
  Description:		
  Input: 
  Output:			
  Return:			
  Others:
*************************************************/
int media_cloud_request_IFrame(void)
{
	return video_cloud_request_IFrame();
}

/*************************************************
  Function:			media_start_cloud_video
  Description:		�����ƶ���Ƶ
  Input: 			
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
uint32 media_start_cloud_video(void)
{	
	// ��Ƶ�Ѿ��������ٿ���
	if (g_CloudVideoFlg == TRUE)
	{
		return TRUE;
	}

	if (g_CloudDealVideo == TRUE)
	{
		int times = 20;
		while (g_CloudDealVideo == TRUE && times > 0)
		{
			times--;			
			usleep(100*1000);
		}

		if (g_CloudDealVideo == TRUE)
		{
			printf("media_start_cloud_video fail !!! \n");
			return FALSE;
		}
	}
		
	int ret = open_video_mode(VS_CLOUD_SEND, NULL, NULL, NULL);
	if (ret == 0)
	{
		g_CloudVideoFlg = TRUE;
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:			media_stop_cloud_video
  Description:		ֹͣ��������Ƶ����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void media_stop_cloud_video(void)
{
	g_CloudVideoFlg = FALSE;
	g_CloudDealVideo = TRUE;
		
	close_video_mode(VS_CLOUD_SEND);
	g_CloudDealVideo = FALSE;
	return;
}
#endif


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
	VideoMutexInit();
	Alsa_mutex_init();
	ms_media_init();
	ms_rtp_session_Init();

	mMediaStream.AudioAi = ms_media_new(MS_AUDIO_AI_ID);
	mMediaStream.AudioAo = ms_media_new(MS_AUDIO_AO_ID);
	mMediaStream.AudioDec= ms_media_new(MS_ALAW_DEC_ID);	
	mMediaStream.AudioEnc = ms_media_new(MS_ALAW_ENC_ID);
	mMediaStream.AudioRtpSend = ms_media_new(MS_RTP_SEND_A_ID);
	mMediaStream.AudioRtpRecv = ms_media_new(MS_RTP_RECV_A_ID);
	mMediaStream.WavRecord = ms_media_new(MS_WAV_RECORD_ID);
	mMediaStream.WavPlayer = ms_media_new(MS_WAV_PLAYER_ID);
	
	mMediaStream.VideoDec = ms_media_new(MS_H264_DEC_ID);
	mMediaStream.VideoRtpRecv = ms_media_new(MS_RTP_RECV_V_ID);
	
	mMediaStream.JpegDec  = ms_media_new(MS_JPEG_DEC_ID);
	mMediaStream.JpegEnc  = ms_media_new(MS_JPEG_ENC_ID);

		
	mMediaStream.LylyPlay = ms_media_new(MS_LYLY_PLAY_ID);
	//mMediaStream.Mp3Play = ms_media_new(MS_MP3_PLAY_ID);
	mMediaStream.LylyRecord = ms_media_new(MS_LYLY_RECORD_ID);	
	mMediaStream.LylyHitPlay = ms_media_new(MS_LYLY_HIT_ID);
	mMediaStream.RtspPlay = ms_media_new(MS_RTSP_PLAY_ID);

	#ifdef _ENABLE_CLOUD_
	mMediaStream.VideoEnc = ms_media_new(MS_H264_ENC_ID);
	mMediaStream.AudioCloudRecv = ms_media_new(MS_CLOUD_RECV_AUDIO_ID);
	mMediaStream.AudioCloudSend = ms_media_new(MS_CLOUD_SEND_AUDIO_ID);
	mMediaStream.VideoCloudSend = ms_media_new(MS_CLOUD_SEND_VIDEO_ID);
	mMediaStream.VideoCloudEnc = ms_media_new(MS_CLOUD_H264_ENC_ID);
	#endif

	video_mutex_init();
	audio_mutex_init();
}

