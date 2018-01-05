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

#define 	RT_SUCCESS  			0
#define	 	RT_FAILURE   			-1

#define		H264VER          		0x00010000
#define 	H264VER_MAJOR    		(H264VER>>16)
#define 	H264VER_MINOR    		(H264VER&0xffff)

#define 	DISPLAY_MODE_RGB555     0
#define 	DISPLAY_MODE_RGB565     1
#define 	DISPLAY_MODE_RGB888_MODE0     2
#define 	DISPLAY_MODE_RGB888_MODE1     3
#define 	DISPLAY_MODE_CBYCRY     4
#define 	DISPLAY_MODE_YCBYCR     5
#define 	DISPLAY_MODE_CRYCBY     6
#define 	DISPLAY_MODE_YCRYCB     7

#define 	IOCTL_LCD_GET_DMA_BASE      _IOR('v', 32, unsigned int *)
#define 	IOCTL_LCD_ENABLE_INT		_IO('v', 28)
#define 	IOCTL_LCD_DISABLE_INT		_IO('v', 29)
#define 	IOCTL_FB_LOCK				_IOW('v', 64, unsigned int)	
#define 	IOCTL_FB_UNLOCK				_IOW('v', 65, unsigned int)
#define 	VIDEO_FORMAT_CHANGE			_IOW('v', 50, unsigned int)  

#define FB_DEVICE       	"/dev/fb0"  

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
	STREAM_SRC_H264_DEC = 0,	// ԴΪ�����
	STREAM_SRC_ANOLOG   = 1,	// ԴΪģ���豸��Ƶ
}STREAM_SRC_E;

typedef enum
{
	VS_CLOSE,			                            // �ر�״̬
	VS_NETTALK_BOTH,	                            // ����ͨ��״̬,˫����Ƶ
	VS_NETTALK_SEND,	                            // ����ͨ��״̬,��������Ƶ
	VS_NETTALK_RECIVE,	                            // ����ͨ��״̬,��������Ƶ
	VS_NETSNAP,
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
	MP3_CMD_STOP,	                           		// ֹͣ
	MP3_CMD_PAUSE,	                            	// ��ͣ/�����л�
	MP3_CMD_PLAY,	                            	// ����
	MP3_CMD_CHANGE,									// �л������ļ�
}MP3_CMD_E;

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

typedef struct AVFrame 
{
    unsigned char *data[4];
} AVFrame;

typedef struct AVPacket 
{
    unsigned char *data;
    int     size;
} AVPacket;

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





/*************************************************
  Function:			rtsp_set_full_screen
  Description:		ȫƵ����
  Input: 	
  	1.flg			�Ƿ�ȫ��		
  Output:			��
  Return:			��
  Others:
*************************************************/
int rtsp_set_full_screen(uint8 flg);

/*************************************************
  Function:			rtsp_play_open
  Description:		����rtsp����
  Input: 			��
  Output:			��
  Return:		
  Others:
*************************************************/
int32 rtsp_play_open(V_RECT_S rect, char *Url, void *callback_func);

/*************************************************
  Function:			rtsp_play_close
  Description:		�ر�rtsp����
  Input: 			��
  Output:			��
  Return:		
  Others:
*************************************************/
int32 rtsp_play_close(void);

/*************************************************
  Function:			inter_full_screen
  Description:		ȫƵ����
  Input: 	
  	1.flg			�Ƿ�ȫ��		
  Output:			��
  Return:			��
  Others:
*************************************************/
void set_full_screen(uint8 flg);


/*************************************************
  Function:    		open_video_mode
  Description:		
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
int open_video_mode(VIDEO_STATE_E mode, int addr);

/*************************************************
  Function:    		close_video_mode
  Description:		
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
int close_video_mode(VIDEO_STATE_E mode);

/*************************************************
  Function:    	set_jpg_param
  Description: 		
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void set_jpg_dec_param(char *filename, uint16 pos_x, uint16 pos_y, uint16 width, uint16 heigh);

/*************************************************
  Function:    	set_jpg_param
  Description: 		
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void set_jpg_enc_param(char *filename, uint16 width, uint16 heigh, DEVICE_TYPE_E DevType);

/*************************************************
  Function:    	open_jpeg_dec
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_jpeg_dec(void);

/*************************************************
  Function:    	close_jpeg_dec
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int close_jpeg_dec(void);

/*************************************************
  Function:    	open_jpeg_enc
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int open_jpeg_enc(void);

/*************************************************
  Function:    	close_jpeg_enc
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int close_jpeg_enc(void);

/*************************************************
  Function:			lyly_play_start
  Description:		������Ӱ����
  Input: 			��
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int32 lyly_play_start(char *filename, void * proc);

/*************************************************
  Function:			lyly_play_stop
  Description:		
  Input: 			��
  Output:			��
  Return:		
  Others:
*************************************************/
void lyly_play_stop(void);

/*************************************************
  Function:			lyly_play_pause
  Description:		��ͣ/�����л�
  Input: 			��
  Output:			��
  Return:		
  Others:
*************************************************/
int32 lyly_play_pause(void);

/*************************************************
  Function:			mp3_play_pause
  Description:		��ͣ/�����л�
  Input: 			��
  Output:			��
  Return:		
  Others:
*************************************************/
int32 mp3_play_pause(void);

/*************************************************
  Function:			lyly_play_start
  Description:		������Ӱ����
  Input: 			��
  Output:			��
  Return:			TRUE/FALSE
  Others:
*************************************************/
int32 mp3_play_start(char *filename, void * proc);

/*************************************************
  Function:			mp3_play_stop
  Description:		�������ã�������һ�׻��Լ�����ʼ��
  Input: 			��
  Output:			��
  Return:		
  Others:
*************************************************/
void mp3_play_stop(void);

/*************************************************
  Function:    	get_avi_record_param
  Description: 		
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
int32 set_avi_record_param(uint8 mode, uint8 atp, uint8 vtp, char * filename);

/*************************************************
  Function:    	lyly_record_start
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int lyly_record_start(void);

/*************************************************
  Function:    	lyly_record_stop
  Description: 		
  Input:		��
  Output:		��
  Return:		��		
  Others:
*************************************************/
int lyly_record_stop(void);
#endif

