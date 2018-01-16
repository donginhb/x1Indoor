/********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	logic_audio_ai.h
  Author:		�޷�»
  Version:		V2.0
  Date: 		2014-04-01
  Description:	��Ƶ�������
  
	History:				 
		1.Date: 
		Author: 
		Modification: 
*********************************************************/
#ifndef _LOGIC_AUDIO_AI_H_
#define _LOGIC_AUDIO_AI_H_

#include "logic_audio.h"

typedef struct _AudioAIParam
{	
	bool Enable;					// �ӿ�ʹ��
	bool AecEnable;					// ������ʹ��
	float AiAgc;					// ����ֵ
	MSThread aithread;				
}AudioAIParam;

#define MS_AUDIO_AI_OPEN			MS_MEDIA_METHOD(MS_AUDIO_AI_ID, 0x00, const char)
#define MS_AUDIO_AI_CLOSE			MS_MEDIA_METHOD_NO_ARG(MS_AUDIO_AI_ID, 0x01)
#define MS_AUDIO_AI_PARAM			MS_MEDIA_METHOD(MS_AUDIO_AI_ID,0x02, PAUDIO_PARAM)
#define MS_AUDIO_AI_ENABLE			MS_MEDIA_METHOD(MS_AUDIO_AI_ID, 0x03, const char)
#define MS_AUDIO_AI_AEC_ENABLE		MS_MEDIA_METHOD(MS_AUDIO_AI_ID, 0x04, const char)
#endif

