
/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	logic_audio_play.c
  Author:   	�±���
  Version:  	1.0
  Date: 		2015-04-29
  Description:  WAV��Ƶ����
				
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/

#ifndef _LOGIC_AUDIO_PLAY_H_
#define _LOGIC_AUDIO_PLAY_H_

#include "logic_media_core.h"
#include "logic_audio.h"


typedef enum
{
	AUDIO_STATE_STOP,	                 // ֹͣ
	AUDIO_STATE_PAUSE,	                 // ��ͣ
	AUDIO_STATE_START,	                 // ����
}AUDIO_PLAY_STATE_E;

// ��Ƶ����
typedef struct
{
	uint8 IsPack;						// �Ƿ����
	uint8 PackNum;						// �������
	uint8 channels;						// ͨ����	
	AIO_SAMPLE_RATE_E rate;				// ������
	AIO_BIT_WIDTH_E bit_width;			// ����λ��	
}WAV_AUDIO_PARAM, *PWAV_AUDIO_PARAM;


typedef struct _AudioPlayState
{
	int StreamID;
	WAV_AUDIO_PARAM audio_param;
	AUDIO_PLAY_STATE_E Play_State;
	AUDIOPLAY_PARAM AudioPlay_Param;
	MSThread msplaythread;

}AudioPlayState;



#define MS_AUDIO_PLAY_OPEN		MS_MEDIA_METHOD(MS_FILE_PLAYER_ID, 0x01, const char)
#define MS_AUDIO_PLAY_PARAM		MS_MEDIA_METHOD(MS_FILE_PLAYER_ID, 0x02, const char)
#define MS_AUDIO_PLAY_CONTROL   MS_MEDIA_METHOD(MS_FILE_PLAYER_ID, 0x03, const char)   
#define MS_AUDIO_PLAY_CLOSE		MS_MEDIA_METHOD_NO_ARG(MS_FILE_PLAYER_ID, 0x01)

#endif


