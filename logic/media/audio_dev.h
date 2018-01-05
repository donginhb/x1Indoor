/*************************************************
  Copyright (C), 2006-2016, 
  File name: 	audio_dev.h
  Author:		chenbh
  Version:  	1.0
  Date: 		2015-04-27
  Description:  alsaģ��
				
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <locale.h>
#include <assert.h>
#include <sys/poll.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/signal.h>
#include <pthread.h>

#ifndef	_AUDIO_DEV_H_
#define	_AUDIO_DEV_H_

typedef void (*Audiofun)(char *DataBuffer, int DataSize);


typedef struct
{
	int StreamId;
	int SampleRate;
	int Bitwidth;
	int Channel;
	int BlockTime;				// �鴦��ʱʱ��
	int dwRecMuteCnt;			// ���������ݴ�С ��captureǰ������ݶ���
	int status;
	Audiofun callback;
	pthread_mutex_t lock;					
}alsa_info_t,*palsa_info_t;

typedef enum {
	ALSA_NO_ERROR 		= 0,
	ALSA_WRBUF_UNDERRUN = -1,
	ALSA_WRBUF_SENDFAIL = -2,
	ALSA_RDBUF_RECVFAIL = -3
} AlsaErrNum;

typedef enum {
	ALSA_NOT_WORKING = 0,
	ALSA_PLAYBAK_START,
	ALSA_CAPTURE_START
} AlsaStatusNum;

typedef enum {
	ALSA_MODE_RECORD,
	ALSA_MODE_PLAY
} AlSA_MODE_E;




#ifdef __cplusplus
extern "C" {
#endif


/*************************************************
  Function:			Alsa_Play_SetVolume
  Description:  	������������
  Input: 
  Output:		  
  Return:		 
  Others:  
*************************************************/
int Alsa_Play_SetVolume(int volume);

/*************************************************
  Function:			Alsa_Record_SetVolume
  Description:  	������ͷ����
  Input: 
  Output:		  
  Return:		 
  Others:  
*************************************************/
int Alsa_Record_SetVolume(int volume);

/*************************************************
  Function:			Alsa_Record_Start
  Description:  	alsa��ȡ�豸��ʼ��  
  Input: 
   1��Channel		ͨ����
   2��Bitwidth		λ��
   3��SampleRate	������
   4��BlockTime		�鴦��ʱ��
   5��Func			�ص�����
  Output:		  
  Return:		 
  Others:  
*************************************************/
int Alsa_Record_Start(int Channel, int Bitwidth, int SampleRate, int BlockTime, Audiofun Func);

/*************************************************
  Function:			CX_Alsa_Read_Close
  Description:  	�رն��豸
  Input: 
  Output:		  
  Return:		 
  Others:  
*************************************************/
int	Alsa_Record_Close(void);

/*************************************************
  Function:			Alsa_Play_Func
  Description:  	��alsa�豸д������ ����
  Input: 
   1��data			����ָ��
   2��size			���ݴ�С
  Output:		  
   1��status		����ֵ
  Return:		 
  Others:  
*************************************************/
int	Alsa_Play_Func(void * Data, int size, int* status);

/*************************************************
  Function:			Alsa_Play_Start
  Description:  	alsaд�豸��ʼ�� ���ų�ʼ��
  Input: 
   1��Channel		ͨ����
   2��Bitwidth		λ��
   3��SampleRate	������
   4��BlockTime		�鴦��ʱ��
  Output:		  
  Return:		 
  Others:  
*************************************************/
int	Alsa_Play_Start(int Channel, int Bitwidth, int SampleRate, int BlockTime);

/*************************************************
  Function:			CX_Alsa_Write_Close
  Description:  	�ر�д����
  Input: 
  Output:		  
  Return:		 
  Others:  
*************************************************/
int	Alsa_Play_Close(void);
#ifdef __cplusplus
}
#endif


#endif

