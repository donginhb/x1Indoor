/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	ui_right_ctrl.h
  Author:     	luofl
  Version:    	2.0
  Date: 		2014-09-12
  Description:  
				�ұ߿ؼ�����ͷ�ļ�
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
#ifndef __UI_RIGHT_CTRL_H__
#define __UI_RIGHT_CTRL_H__

/********************************************************/
/*						�ؼ��ṹ						*/
/********************************************************/
#define RIGHT_NUM_MAX						5		// ���֧�ְ�����
#define KEYDOWN  							1
#define KEYUP  								0
#define DEFAULT_IMAGE_H						100	

#define RIGHT_KEY0							0
#define RIGHT_KEY1							1
#define RIGHT_KEY2							2
#define RIGHT_KEY3							3
#define RIGHT_KEY4							4
#define RIGHT_KEY_MAX						5

#define KEY_WINMAX							5

typedef void(*RightbarCallBack)(void);

typedef struct 
{
	HWND hDlg;
	int iMsg;
	WPARAM wParam;
	LPARAM lParam;
}WIN_MSG, * PWIN_MSG;

typedef struct 
{
	uint8 count;
	WIN_MSG button[KEY_WINMAX];
}WIN_INFO, * PWIN_INFO;

typedef struct 
{
	uint8 Enabled;									// ʹ��
	uint8 Hold;										// ��������
	uint32 TextID;									// ����ID
	uint32 ImageID;									// ͼƬID	
	uint16 TextLen;									// �������ݳ���
	uint32 ImageW;									// ͼƬ�߶�
	uint32 ImageH;									// ͼƬ���
}BUTTON_INFO, * PBUTTON_INFO;

typedef struct 
{
	HWND parent;									// ������
	uint16 BmpBk;									// ����ͼƬ
	uint8 holdmode;									// ��ť����ģʽ
	int8 VideoMode;									// ��Ƶ����
	int8 Index;										// ��ǰ���µڼ�������
	uint8 state;									// ����״̬
	uint8 MaxNum;									// ��󰴼���
	uint8 TextSize;									// ���ִ�С
	BUTTON_INFO buttons[RIGHT_NUM_MAX+1];			// ÿ��������Ϣ
	WIN_INFO wininfo[RIGHT_NUM_MAX+1];				// �ؼ���Ϣ
	RightbarCallBack proc;
}RIGHTCTRL_INFO, * PRIGHTCTRL_INFO;

#if 0
/*************************************************
  Function:		ui_draw_rightctrl_button
  Description: 	���ұ߰���
  Input:		
  	1.hWnd		����
  	2.rect		����
  	3.WButObj 	�ؼ��ṹ��		
  Output:		��
  Return:		��
  Others:
*************************************************/
void ui_draw_rightctrl_button(HWND hWnd, RECT * rect, PRIGHTCTRL_INFO WButObj);

/*************************************************
  Function:		draw_rightctrl_bk
  Description: 	���ұ߱���
  Input:	
  	1.hWnd		����
  	2.rect		����
  	3.WButObj 	�ؼ��ṹ��	
  Output:		��
  Return:		��
  Others:
*************************************************/
void ui_draw_rightctrl_bk(HWND hWnd, RECT * rect, PRIGHTCTRL_INFO WButObj);
#endif
/*************************************************
  Function:		change_rightctrl_allimagetext
  Description: 	
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
void change_rightctrl_allimagetext(HWND hDlg , uint32 * BmpID, uint32 * StrID);

/*************************************************
  Function:		add_rightctrl_win
  Description: 	��Ӵ���
  Input:		
  	1.Parent	����
  	2.hDlg		����
  	3.wParam	����1
  	4.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
void add_rightctrl_win(HWND Parent, int Index, HWND hDlg, int msg, WPARAM wParam, LPARAM lParam);
#endif
