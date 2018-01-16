/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	logic_video.h
  Author:   	�±���
  Version:  	1.0
  Date: 		2014-12-11
  Description:  ��Ƶ����
				
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#ifndef _AU_VIDEO_H_
#define _AU_VIDEO_H_

#include <linux/fb.h>
#include "logic_include.h"
#include "logic_media_core.h"

#define DEFAULT_BIT_RATE			2048000
#define DEFAULT_WIDTH				640
#define DEFAULT_HEIGHT				480

#define DEFAULT_CLOUD_BIT_RATE		512000
#define DEFAULT_CLOUD_WIDTH			320
#define DEFAULT_CLOUD_HEIGHT		240
#define DEFAULT_CLOUD_FRAMERATE 	15

#define DEFAULT_FRAMERATE 			15

#if (_LCD_DPI_ == _LCD_800480_)
#define JPEG_ENC_W					640
#define JPEG_ENC_H					480

#define JPEG_DEC_W					640
#define JPEG_DEC_H					480

// ������Ƶ��ʾλ��
#define H264_DISPLAY_X				0
#define H264_DISPLAY_Y				0
#define H264_DISPLAY_W				820
#define H264_DISPLAY_H				600
#define H264_DISPLAY_W_FULL			1024
#define H264_DISPLAY_H_FULL			600


// RTSP��Ƶ��ʾλ��
#define RTSP_DISPLAY_X 				0
#define RTSP_DISPLAY_Y 				0
#define RTSP_DISPLAY_W 				640
#define RTSP_DISPLAY_H 				480

// ��Ӱ������Ƶ��ʾλ��
#define AVI_DISPLAY_X 				0
#define AVI_DISPLAY_Y 				0
#define AVI_DISPLAY_W 				640
#define AVI_DISPLAY_H 				480
#elif (_LCD_DPI_ == _LCD_1024600_)
#define JPEG_ENC_W					640
#define JPEG_ENC_H					480

#define JPEG_DEC_W					640
#define JPEG_DEC_H					480

// ������Ƶ��ʾλ��
#define H264_DISPLAY_X				0
#define H264_DISPLAY_Y				0
#define H264_DISPLAY_W				820
#define H264_DISPLAY_H				600
#define H264_DISPLAY_W_FULL			1024
#define H264_DISPLAY_H_FULL			600


// RTSP��Ƶ��ʾλ��
#define RTSP_DISPLAY_X 				0
#define RTSP_DISPLAY_Y 				0
#define RTSP_DISPLAY_W 				640
#define RTSP_DISPLAY_H 				480

// ��Ӱ������Ƶ��ʾλ��
#define AVI_DISPLAY_X 				0
#define AVI_DISPLAY_Y 				0
#define AVI_DISPLAY_W 				640
#define AVI_DISPLAY_H 				480
#endif

typedef enum
{
 	FB_DISPLAY_MODE_RGB555 = 0,
 	FB_DISPLAY_MODE_RGB565 = 1,
 	FB_DISPLAY_MODE_CBYCRY = 4,
 	FB_DISPLAY_MODE_YCBYCR = 5,
 	FB_DISPLAY_MODE_CRYCBY = 6,
 	FB_DISPLAY_MODE_YCRYCB = 7,

}FB_DISPLAY_MODE_E;			// FB ��ʾģʽ

typedef enum
{
	VS_NONE					= 0x0000,			    // �ر�״̬
	VS_NETTALK_BOTH			= 0x0001,	            // ����ͨ��״̬,˫����Ƶ
	VS_NETTALK_SEND			= 0x0002,	            // ����ͨ��״̬,��������Ƶ
	VS_NETTALK_RECIVE		= 0x0004,	            // ����ͨ��״̬,��������Ƶ
	VS_NET_SNAP				= 0x0008,				// ������Ƶ���ݽ���ץ��
	VS_LOCAL_SNAP			= 0x0010,				// ��������ͷ����ץ��
	VS_NET_RECORD			= 0x0020,				// ��������¼��
	VS_LOCAL_RECORD			= 0x0040,				// �������ݵ�¼��
	VS_CLOUD_SEND			= 0x0080,				// �ƶ˷���
	VS_LYLY_PLAY			= 0x0200,				// ��Ӱ���Բ���
}VIDEO_STATE_E;

typedef enum
{
	AVI_CMD_STOP,	                           		// ֹͣ
	AVI_CMD_PAUSE,	                            	// ��ͣ/�����л�
	AVI_CMD_PLAY,	                            	// ����
	AVI_CMD_CHANGE,									// �л������ļ�
}AVI_CMD_E;

typedef enum
{
	STREAM_SRC_H264_DEC = 0,	// ԴΪ�����
	STREAM_SRC_ANOLOG   = 1,	// ԴΪģ���豸��Ƶ
}STREAM_SRC_E;

// RTSP״̬
typedef enum
{
	RTSP_STATE_NONE = 0,
	RTSP_STATE_CONNECT,
	RTSP_STATE_OPER_PLAY,
	RTSP_STATE_PLAY,
	RTSP_STATE_PAUSE,
	RTSP_STATE_OPER_STOP,
	RTSP_STATE_STOP,

	// ����״̬���������ص��ã�������RTSP��ǰ״̬
	RTSP_STATE_HEART,								// ��������
}RTSP_STATE_E;


typedef struct video_params
{
    unsigned int bit_rate;
    unsigned int width;   //length per dma buffer
    unsigned int height;
    unsigned int framerate;
    unsigned int frame_rate_base;
    unsigned int gop_size;
    unsigned int qmax;
    unsigned int qmin;
    unsigned int quant;
    unsigned int intra;
    unsigned int targetw;
    unsigned int targeth;
} video_params;


// ������λ��
typedef struct auRECT_S
{
    unsigned int   x;
    unsigned int   y;
    unsigned int   width;
    unsigned int   height;
}V_RECT_S, * V_PRECT_S;


typedef void (*PAVI_CALLBACK)(uint32 cmd, uint32 time, uint32 percent);
typedef void (*PMP3_CALLBACK)(uint32 cmd, uint32 time, uint32 percent);
typedef void (*PRTSP_CALLBACK)(RTSP_STATE_E echo, int param);

typedef struct _AviPlayState{
	AVI_CMD_E cmd;
	uint8 filename[100];
	PAVI_CALLBACK callback;
	
}AviPlayState;

typedef struct _Mp3PlayState{
	AVI_CMD_E cmd;
	uint8 filename[100];
	PAVI_CALLBACK callback;
	
}Mp3PlayState;

typedef struct _RecordParam{
	uint8 filename[100];
	uint8 RecordMode;
	uint8 AudioFormat;
	uint8 VideoFormat;
	
}RecordParam;






#endif

