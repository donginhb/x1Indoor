/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_keyboard_ctrl.c
  Author:   	caogw	
  Version:   	2.0
  Date: 		2014-10-22
  Description:  
                �����ؼ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#include "gui_include.h"

/************************��������************************/
#if (_LCD_DPI_ == _LCD_800480_)
#define KEYBOARD_BK_X			0
#define KEYBOARD_BK_Y      	    0
#define KEYBOARD_BK_W       	640
#define KEYBOARD_BK_H       	90			   		             		
#define KEYBOARD_NUM_DISX       52             		// ѡ�����Ծ���
#define KEYBOARD_SELECT_XPOS    1              		
#define KEYBOARD_SELECT_YPOS    8 
#elif (_LCD_DPI_ == _LCD_1024600_)
#define KEYBOARD_BK_X			0
#define KEYBOARD_BK_Y      	    0
#define KEYBOARD_BK_W       	640
#define KEYBOARD_BK_H       	90			   		             		
#define KEYBOARD_NUM_DISX       52             		// ѡ�����Ծ���
#define KEYBOARD_SELECT_XPOS    1              		
#define KEYBOARD_SELECT_YPOS    8 
#endif

#define KEYBOARD_MODE0_BK		BID_KeyBoardBK_Pass
#define KEYBOARD_MODE1_BK		BID_KeyBoardBK_Call
#define KEYBOARD_MODE2_BK		BID_KeyBoardBK_Pass_1

/************************��������************************/
static uint8 g_FirstFlag = 1; 						// �Ƿ����´����˿ؼ�
/*************************************************
  Function:		ui_reflash_ctrl
  Description: 	ˢ�¿ؼ�
  Input:	
  	1.hDlg		���ھ��
  	2.wParam 	����1
   	3.lParam    ����2	
  Output:		��
  Return:		��
  Others:
*************************************************/
static void ui_reflash_key(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	InvalidateRect(hDlg, NULL, TRUE);
}

/*************************************************
  Function:		KeyboardCtrlPaint_mode0
  Description: 	��
  Input:		
    1.hdc		���
   	2.Keyval    �����ֵ	
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 KeyboardCtrlPaint_mode0(HDC hdc, int8 Keyval)
{
	uint32 xpos,ypos;
	
	DrawBmpID(hdc, KEYBOARD_BK_X, KEYBOARD_BK_Y, KEYBOARD_BK_W, KEYBOARD_BK_H, KEYBOARD_MODE0_BK);
	xpos = KEYBOARD_SELECT_XPOS + KEYBOARD_NUM_DISX * Keyval;
	ypos = KEYBOARD_SELECT_YPOS;
	DrawBmpID(hdc, xpos, ypos, 0, 0, BID_Keyboard_Select);
	
	return TRUE;
}

/*************************************************
  Function:		KeyboardCtrlPaint_mode1
  Description: 	��
  Input:		
    1.hdc		���
   	2.Keyval    �����ֵ 		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 KeyboardCtrlPaint_mode1(HDC hdc, int8 Keyval)
{
	uint32 xpos,ypos;
	
	DrawBmpID(hdc, KEYBOARD_BK_X, KEYBOARD_BK_Y, KEYBOARD_BK_W, KEYBOARD_BK_H, KEYBOARD_MODE1_BK);
	xpos = KEYBOARD_SELECT_XPOS + KEYBOARD_NUM_DISX * Keyval;
	ypos = KEYBOARD_SELECT_YPOS;
	DrawBmpID(hdc, xpos, ypos, 0, 0, BID_Keyboard_Select);
	
	return TRUE;
}

/*************************************************
  Function:		KeyboardCtrlPaint_mode2
  Description: 	��
  Input:		
    1.hdc		���
   	2.Keyval    �����ֵ 		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 KeyboardCtrlPaint_mode2(HDC hdc, int8 Keyval)
{
	uint32 xpos,ypos;
	
	DrawBmpID(hdc, KEYBOARD_BK_X, KEYBOARD_BK_Y, KEYBOARD_BK_W, KEYBOARD_BK_H, KEYBOARD_MODE2_BK);
	xpos = KEYBOARD_SELECT_XPOS + KEYBOARD_NUM_DISX * Keyval;
	ypos = KEYBOARD_SELECT_YPOS;
	DrawBmpID(hdc, xpos, ypos, 0, 0, BID_Keyboard_Select);
	
	return TRUE;
}

/*************************************************
  Function:		KeyboardCtrlPaint
  Description: 	��
  Input:		
  	1.hDlg		������
  	2.wParam	����1
  	3.lParam 	����2  		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_KeyboardCtrl_paint(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
    RECT rect;
	PKEYBOARD_INFO WButObj = (PKEYBOARD_INFO)GetWindowAdditionalData(hDlg);
	
   	if (NULL == WButObj)
	{
		log_printf("WButObj is NULL!!!");
		return FALSE;
	}
	
	HDC hdc = BeginPaint(hDlg);
	GetClientRect(hDlg, &rect);  	
	SetBkMode(hdc, BM_TRANSPARENT);
	
	switch(WButObj->Mode)
	{
		case KEYBOARD_MODE0:
			KeyboardCtrlPaint_mode0(hdc, WButObj->KeyValue);
			break;

		case KEYBOARD_MODE1:
			KeyboardCtrlPaint_mode1(hdc, WButObj->KeyValue);
			break;
			
		case KEYBOARD_MODE2:
			KeyboardCtrlPaint_mode2(hdc, WButObj->KeyValue);
			break;
			
		default:
			break;
	}
    EndPaint(hDlg, hdc);
	
	return TRUE;
}

/*************************************************
  Function:		ui_KeyboardCtrl_left
  Description: 	select������
  Input:		
  	1.hDlg		������
  	2.wParam	����1
  	3.lParam 	����2  		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_KeyboardCtrl_left(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PKEYBOARD_INFO WButObj = (PKEYBOARD_INFO)GetWindowAdditionalData(hDlg);
	if (NULL == WButObj)
	{
		log_printf("WButObj is NULL!!!");
		return FALSE;
	}
	
	if (WButObj->KeyValue == 0)
	{
		WButObj->KeyValue = WButObj->Max;
	}
	else
	{
		WButObj->KeyValue--;
	}
	ui_reflash_key(hDlg, wParam, lParam);
	
	return TRUE;
}

/*************************************************
  Function:		ui_KeyboardCtrl_right
  Description: 	select������
  Input:		
  	1.hDlg		������
  	2.wParam	����1
  	3.lParam 	����2   		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_KeyboardCtrl_right(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PKEYBOARD_INFO WButObj = (PKEYBOARD_INFO)GetWindowAdditionalData(hDlg);
	if (NULL == WButObj)
	{
		log_printf("WButObj is NULL!!!");
		return FALSE;
	}
	
	if (WButObj->KeyValue == WButObj->Max)
	{
		WButObj->KeyValue = 0;
	}
	else
	{
		WButObj->KeyValue++;
	}
	ui_reflash_key(hDlg, wParam, lParam);
	 
	return TRUE;
}

/*************************************************
  Function:		ui_KeyboardCtrl_Ok
  Description: 	�������ݸ������ؼ�
  Input:		
  	1.hDlg		������
  	2.wParam	����1
  	3.lParam 	����2  		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_KeyboardCtrl_Ok(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uint8 old;
	
	static uint8 active_win = 0;
	PKEYBOARD_INFO WButObj = (PKEYBOARD_INFO)GetWindowAdditionalData(hDlg);
   	if (NULL == WButObj)
	{
		log_printf("WButObj is NULL!!!");
		return FALSE;
	}

	if (WButObj->IPmode)
	{
		SendMessage(WButObj->InputhDlg[0], WM_Spin_Get_Value, IDC_KEYBOARD_CTRL, WButObj->KeyValue);
		return TRUE;
	}
	
	if (g_FirstFlag)
	{
		active_win = 0;
		g_FirstFlag = 0;
	}
	// ���к�����ģʽ ֻ��һ�������
	if (WButObj->Mode == KEYBOARD_MODE1 || WButObj->Mode == KEYBOARD_MODE2)
	{
		active_win = 0;
	}
	if (WButObj->InputhDlg[active_win])
	{
		if (WButObj->KeyValue == 10)
		{
			if (WButObj->Mode == KEYBOARD_MODE1)
			{
				SendMessage(WButObj->InputhDlg[active_win], WM_Input_Clear, 0, 0);
			}
			else
			{
				// ���������ʱTAB�����л�
				if (WButObj->InputNum == 2)
				{
					old = active_win;
					active_win ++;
					if (active_win >= 2)
					{
						active_win = 0;
					}
					SendMessage(WButObj->InputhDlg[old], WM_Input_Set_Active, 0, 1);
					SendMessage(WButObj->InputhDlg[active_win], WM_Input_Set_Active, 0, 0);
				}

				// ���������ʱTAB�����л�
				if (WButObj->InputNum == 5)
				{
					old = active_win;
					active_win ++;
					if (active_win >= 5)
					{
						active_win = 0;
					}
					SendMessage(WButObj->InputhDlg[old], WM_Input_Set_Active, 0, 1);
					SendMessage(WButObj->InputhDlg[active_win], WM_Input_Set_Active, 0, 0);
				}
			}
		}
		else if (WButObj->KeyValue == 11)
		{
			SendMessage(WButObj->InputhDlg[active_win], WM_Input_del_Num, 0, 0);
		}
		else
		{
			SendMessage(WButObj->InputhDlg[active_win],WM_Input_Get_Value,IDC_KEYBOARD_CTRL, WButObj->KeyValue);
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_KeyboardCtrl_exit
  Description: 	�˳�ʱselect���ص���ʼλ��
  Input:		
  	1.hDlg		������
  	2.wParam	����1
  	3.lParam 	����2  		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_KeyboardCtrl_exit(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PKEYBOARD_INFO WButObj = (PKEYBOARD_INFO)GetWindowAdditionalData(hDlg); 
	if (NULL == WButObj)
	{
		log_printf("WButObj is NULL!!!");
		return FALSE;
	}
	if (WButObj)
	{
		WButObj->KeyValue = 0;
	}
	ui_reflash_key(hDlg, wParam, lParam);
	 
	return TRUE;
}

/*************************************************
  Function:		ui_KeyboardCtrl_destroy
  Description: 	��
  Input:		
  	1.hDlg		������
  	2.wParam	����1
  	3.lParam 	����2  		
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_KeyboardCtrl_destroy(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PKEYBOARD_INFO WButObj = (PKEYBOARD_INFO)GetWindowAdditionalData(hDlg);
	if (WButObj)
	{
    	free(WButObj);
		WButObj = NULL;
	}
	
	return TRUE;
}

/*************************************************
  Function:			MyControlProc
  Description: 		ģ��-��Ϣ������
  Input: 		
	1.hwnd			���
	2.message		��Ϣ����
	3.wParam		��������
	4.lParam		��������
  Output:			��
  Return:			��
  Others:
*************************************************/
static int MyControlProc (HWND hWnd, int message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case MSG_CREATE:
			g_FirstFlag = 1;
        	break;
						
		case MSG_PAINT:
			ui_KeyboardCtrl_paint(hWnd, wParam, lParam);
			break;				
			
		 case WM_Key_Left:
		 	ui_KeyboardCtrl_left(hWnd, wParam, lParam);
			break;
			
		 case WM_Key_Right:
		 	ui_KeyboardCtrl_right(hWnd, wParam, lParam);
			break;
			
   		 case WM_Key_Ok:
		 	ui_KeyboardCtrl_Ok(hWnd, wParam, lParam);
			break;
			
   		 case WM_Key_Exit:
		 	ui_KeyboardCtrl_exit(hWnd, wParam, lParam);
			break;

   		 //case MSG_DESTROY:
		 //	ui_KeyboardCtrl_destroy(hWnd, wParam, lParam);
         // break;

		case MSG_CLOSE:
			return 0;

		case MSG_DESTROY:
			return 0;
	}
	
	return DefaultControlProc (hWnd, message, wParam, lParam);
}

/*************************************************
  Function:		register_num_keybord
  Description: 	ע��ؼ�
  Input: 		
	1.void		��	
  Output:		
  Return:		
  Others:
*************************************************/
BOOL register_num_keybord(void)
{
	WNDCLASS MyClass;

	MyClass.spClassName = NUM_KEYBORD;
	MyClass.dwStyle     = WS_NONE;
	MyClass.dwExStyle   = WS_EX_NONE;
	MyClass.hCursor     = GetSystemCursor (IDC_ARROW);
	MyClass.iBkColor    = PAGE_BK_COLOR;
	MyClass.WinProc     = MyControlProc;
	
	return RegisterWindowClass (&MyClass);
}

/*************************************************
  Function:		unregister_num_keybord
  Description: 	ȡ��ע��
  Input: 		
	1.void		��	
  Output:		
  Return:		
  Others:
*************************************************/
void unregister_num_keybord(void)
{
	UnregisterWindowClass (NUM_KEYBORD);
}

