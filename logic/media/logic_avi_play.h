/********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	logic_avi_play.c
  Author:		�±���
  Version:		V1.0
  Date:			2014-12-11
  Description:	4.3�����ڻ���Ӱ����AVI �ļ�����
  
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef _LOGIC_AVI_PLAY_H_
#define _LOGIC_AVI_PLAY_H_

#include "logic_include.h"
#include "logic_media_core.h"

typedef enum
{
	AVI_STATE_STOP,	                           		// ֹͣ
	AVI_STATE_PAUSE,	                            // ��ͣ
	AVI_STATE_PLAY,	                            	// ����
}AVI_STATE_E;

typedef struct _AviPlayParam{
	AVI_STATE_E state;
	uint8 *val;
	MSThread aviplaythread;
	uint32 m_hMediaHandle;
	PAVI_CALLBACK callback;

}AviPlayParam;

#define MS_AVI_PLAY_OPEN	MS_MEDIA_METHOD(MS_AVI_PLAY_ID, 0x00, const char)
#define MS_AVI_PLAY_CLOSE	MS_MEDIA_METHOD_NO_ARG(MS_AVI_PLAY_ID, 0x01)
#define MS_AVI_PLAY_STATE   MS_MEDIA_METHOD(MS_AVI_PLAY_ID, 0x02, AviPlayState)   

#endif
