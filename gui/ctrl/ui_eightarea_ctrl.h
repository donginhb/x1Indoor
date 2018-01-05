/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_eightarea_ctrl.h
  Author:   	yanjl
  Version:   	2.0
  Date: 		14-10-29
  Description: 
  				�˷����ؼ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __UIEIGHTAREACTRL_H__
#define __UIEIGHTAREACTRL_H__
	
/************************��������************************/
#define AREA_NUM_MAX			8	
#define AREA_KEYDOWN			1
#define AREA_KEYUP				2
#define EADLG_TXTLEN			40
/************************��������************************/

/**********************�ṹ�嶨��************************/
typedef struct  
{
	uint8  Enabled;								// ʹ��
	uint8  Flash_state;							// ��˸״̬
	uint16 TextID;								// ����ID
	uint16 ImageID;								// ͼƬID
	uint16 Flash_imageID;						// ��˸ID
	uint16 MidBgImage;							// �м�㱳��
	uint32 ImageBK;								// ����ͼƬ
	uint16 Text[EADLG_TXTLEN];					// �����ַ���
}AREA_INFO,*PAREA_INFO;

typedef struct 
{
	int8 Index;								// ��ǰѡ�е�����
	uint8 MaxNum;								// ���������
	uint8 State;								// ����״̬
	uint8 Alarming;								// �б���
	int TimerID;    							// ��ʱ��ID
	AREA_INFO Areas[AREA_NUM_MAX];			// ÿ��������Ϣ
}EIGHTAREACTRL_INFO,*PEIGHTAREACTRL_INFO;
/**********************�ṹ�嶨��************************/
#endif

