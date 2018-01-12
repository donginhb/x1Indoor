/*********************************************************
  Copyright (C), 2006-2016
  File name:	ui_msg_ctrl.h
  Author:   	caogw
  Version:   	2.0
  Date: 		2014-10-22
  Description:  ��Ϣ��
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __UI_MSG_CTRL_H__
#define __UI_MSG_CTRL_H__

#if (_UI_STYLE_ == _V6_UI_STYLE_)
#define FORM_MSG_W				360					// �����С
#define FORM_MSG_H				200
#define FORM_MSG_X				(SCREEN_WIDTH-FORM_MSG_W-RIGHT_CTRL_W)/2
#define FORM_MSG_Y				(SCREEN_HEIGHT-FORM_MSG_H)/2
#elif (_UI_STYLE_ == _E81S_UI_STYLE_)
#define FORM_MSG_W				360
#define FORM_MSG_H				136
#define FORM_MSG_X				(SCREEN_WIDTH - FORM_MSG_W)/2
#define FORM_MSG_Y				(SCREEN_HEIGHT - FORM_MSG_H)/2

#define FORM_QUERY_W			360
#define FORM_QUERY_H			200
#define FORM_QUERY_X			(SCREEN_WIDTH - FORM_QUERY_W)/2
#define FORM_QUERY_Y			(SCREEN_HEIGHT - FORM_QUERY_H)/2

#define FORM_HIT_W				300
#define FORM_HIT_H				100
#define FORM_HIT_X				(SCREEN_WIDTH - FORM_HIT_W)/2
#define FORM_HIT_Y				(SCREEN_HEIGHT - FORM_HIT_H)/2
#endif

#define MAX_PASSWORD_LEN 6

typedef enum
{
	MSG_EVENT_YES = 0x01,							// ��
	MSG_EVENT_NO,									// ��
	MSG_EVENT_XIECHI								// Ю������
} MSG_EVENT;	


typedef struct 
{
	HWND 		parent;                          	// ������
	uint32		ID;
	AU_MSG_TYPE	Mode;								// ��Ϣ����
	uint32		TextID;								// ��������ID
	uint32 		MsgBk;								// ��Ϣ�򱳾�ͼ
	uint32		MsgIcon;							// ��Ϣͼ��
	uint32  	TimeId;								// ��ʱ��ID
	uint8 		VideoMode;							// �Ƿ�����Ƶģʽ
	uint8		State;								// ����״̬
	int8 		Select;								// �����ڼ�������
	uint8 		echo;								// �Ƿ���Ҫ֪ͨ������
	uint8		xiechi;								// �Ƿ���Ю������
	char		InputPass[MAX_PASSWORD_LEN+1];		// ����
	char 		adminPass[MAX_PASSWORD_LEN+1];		// ��������
	char 		Pass[MAX_PASSWORD_LEN+1];			// �Ƚ�����
	uint8 		addrsel;							// ȫѡ
	uint8 		addrpos;							// ��ַλ��
	uint16 		AddrStart;							// ��ʼ��ַ
	uint16 		AddrEnd;							// ������ַ
	uint16 		Addr[2];							// ��ַ
	char		DevName[MSG_CHAR];					// �ҵ��豸��
	uint8		devtype;							// �ҵ��豸
	uint8 		devstate;							// �豸״̬
	uint32 		devMaxValue;						// �豸���ֵ
	uint32 		devMinValue;						// �豸��Сֵ
	uint32 		devNowValue;						// �豸��ǰֵ
	uint32 		Hit;								// ��ʾ����
	uint8       factory;                            // �ҵ糧��
	uint8       flag;
	uint8       style;                              // ���ڿյ���˵����ʾģʽ�����¶�
	uint8       kt_mode;                            // �յ���ģʽ
	uint32		Code;								// IP Code
	RIGHTCTRL_INFO  button;
}MSG_INFO,*PMSG_INFO;		// ��Ϣ ���� ���� �ṹ

#endif /* __UI_MSG_CTRL_H__ */

