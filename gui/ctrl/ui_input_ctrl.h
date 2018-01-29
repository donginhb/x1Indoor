/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_input_ctrl.h
  Author:   	caogw
  Version:   	2.0
  Date: 		2014-10-22
  Description:  
   				�����ؼ�ͷ�ļ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __UI_INPUT_CTRL_H__
#define __UI_INPUT_CTRL_H__

typedef enum
{
	INPUT_MODE_COMMON	       = 0x00,				// ��ͨ��ʾ 
	INPUT_MODE_PASSWORD,							// ������ʾ
	INPUT_MODE_CALL,								// ����ģʽ
	INPUT_MODE_NEW,
	INPUT_MODE_TIME,								// ����ģʽ	
}INPUT_MODE;				

typedef struct 
{
    HWND parent;                                    // ������
	INPUT_MODE mode;								// ģʽ 
	uint8 enable;									// ʹ��
	uint8 active;									// ����״̬
	uint8 videomode;								// ��Ƶģʽ
	uint8 maxlen;									// ��󳤶�
	uint8 showlen;									// ��ʾ����
	uint8 len;										// ��ǰ����
	uint16 maxdata;									// ���ֵ
	char text[50];						 		   //���������ֵ
	//WCHAR textw[MAX_CHAR_SHOW];
	uint32 BkID;									// ����ͼƬ
	uint32 BkOnID;									// ����ONͼƬ	
	uint8  Font;									// ����
	//TxtStyle txtstyle;							// ������ʾ��׼
	uint32 hit;										// ��ʾ
	uint32 textid;                                  // ��ʾ�ֵ�id
	uint8 showtype;									// ��ʾ���� 0-* 1-����
}INPUT_INFO,*PINPUT_INFO;	
#endif

