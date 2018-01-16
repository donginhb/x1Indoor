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
uint8 AudioVolumeLevel[9] = {0, 7, 10, 13, 15, 17, 19, 20, 21};
uint8 V7_AudioVolumeLevel[9] = {0, 7, 10, 13, 17, 18, 21, 22, 23};


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
#if 0
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
		media_snapshot(picname, NULL, DEVICE_TYPE_NONE);

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
#endif
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
#if 0
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
#endif
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
  Others:
*************************************************/
int32 media_start_show_pict(char *filename, uint16 pos_x, uint16 pos_y, uint16 with, uint16 heigh)
{
	int32 ret = FALSE;
#if 0	
	set_jpg_dec_param(filename, pos_x, pos_y, with, heigh);
	ret = open_jpeg_dec();
	if (ret == 0)
	{
		sys_set_view_picture_state(TRUE);
		return TRUE;
	}
#endif	
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
#if 0
	sys_set_view_picture_state(FALSE);
	close_jpeg_dec();
	#endif
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
#if 0
	int ret = lyly_play_pause();
	if (RT_FAILURE == ret)
	{
		return TRUE;
	}
#endif
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
	//return lyly_play_start(filename, proc);
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
	//lyly_play_stop();								
}



#if 1
#endif
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
		//ret = media_set_analog_video_win(flg);
	}
	else
	{
		set_full_screen(flg);
		ret = TRUE;
	}
	return ret;
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
	if (vol > 8)
	{
		log_printf("volume parameter more than max level!!!\n");
		vol = 8;
	}
	
	if (vol == 0)
	{
		Alsa_Play_SetVolume(0);
	}
	Alsa_Play_SetVolume(AudioVolumeLevel[vol]);
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

	g_Aplay_type = PLAY_AUDIO_TYPE_NONE;
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

	mMediaStream.AudioAi = ms_media_new(MS_AUDIO_AI_ID);
	mMediaStream.AudioAo = ms_media_new(MS_ALAW_AO_ID);
	mMediaStream.AudioDec= ms_media_new(MS_ALAW_DEC_ID);	
	mMediaStream.AudioEnc = ms_media_new(MS_ALAW_ENC_ID);
	mMediaStream.AudioRtpSend = ms_media_new(MS_RTP_SEND_A_ID);
	mMediaStream.AudioRtpRecv = ms_media_new(MS_RTP_RECV_A_ID);
	mMediaStream.WavRecord = ms_media_new(MS_WAV_RECORD_ID);
	
	mMediaStream.VideoDec = ms_media_new(MS_H264_DEC_ID);
	mMediaStream.VideoRtpRecv = ms_media_new(MS_RTP_RECV_V_ID);
	
	mMediaStream.JpegDec  = ms_media_new(MS_JPEG_DEC_ID);
	mMediaStream.JpegEnc  = ms_media_new(MS_JPEG_ENC_ID);

	mMediaStream.FilePlayer = ms_media_new(MS_FILE_PLAYER_ID);	
	mMediaStream.AviPlay = ms_media_new(MS_AVI_PLAY_ID);
	mMediaStream.Mp3Play = ms_media_new(MS_MP3_PLAY_ID);
	mMediaStream.AviRecord = ms_media_new(MS_AVI_RECORD_ID);	
	mMediaStream.LylyHitPlay = ms_media_new(MS_LYLY_HIT_ID);
	mMediaStream.RtspPlay = ms_media_new(MS_RTSP_PLAY_ID);

	#ifdef _ENABLE_CLOUD_
	mMediaStream.AudioCloudRecv = ms_media_new(MS_CLOUD_RECV_AUDIO_ID);
	mMediaStream.AudioCloudSend = ms_media_new(MS_CLOUD_SEND_AUDIO_ID);
	mMediaStream.VideoCloudSend = ms_media_new(MS_CLOUD_SEND_VIDEO_ID);
	mMediaStream.VideoCloudEnc = ms_media_new(MS_CLOUD_H264_ENC_ID);
	#endif

	video_mutex_init();
	audio_mutex_init();
}

