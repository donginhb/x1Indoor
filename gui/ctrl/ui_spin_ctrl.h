/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_spin_ctrl.h
  Author:   	caogw	
  Version:   	2.0
  Date: 		2014-11-27
  Description:  
                IP�ؼ�ͷ�ļ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __UI_SPIN_CTRL_H__
#define __UI_SPIN_CTRL_H__

/********************************************************/
/*						�ؼ��ṹ						*/
/********************************************************/


#define BIDON_NUM							1		
#define BIDUNENABLE_NUM						2

typedef enum
{
   SPIN_MODE_NUM 		= 0x00,						// ����
   SPIN_MODE_TEXT,									// �����б�
   SPIN_MODE_IP										// IP����ģʽ
}SPIN_MODE_E;

typedef struct
{
	uint32  TextID;
	char	Text[30];
}SPIN_ITEM,*PSPIN_ITEM;

typedef struct 
{
	SPIN_MODE_E	Mode;								// �ؼ�ģʽ
	uint8 	Enable;									// ����ʹ��
	uint8 	state;									// ��ǰ״̬
	uint8	loop;									// �Ƿ�ѭ��
	int8    selall;									// ȫѡ��־
	int8	index;									// 0 ��� 1 �ұ�
	int32	Value;									// ��ǰ��ֵ
	uint16	MinNum;									// ��С��ֵ
	uint16 	MaxNum;									// ����ֵ
	uint32  ImageId[2];								// ͼƬID
	uint32  ImageBK;								// BKͼƬID
	uint32  ImageIpSel;								// IPר��ѡ��ͼƬ
	uint8	IP[4];									// IP��ַ
	uint8 	active;									// ����
	UILIST 	*ListList;   							// �˵��б�
}SPIN_INFO,*PSPIN_INFO;

#endif

