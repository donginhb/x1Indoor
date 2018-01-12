/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	ui_dianti_call.c
  Author:     	caogw
  Version:    	2.0
  Date: 		2014-12-03
  Description:  
				�����ٻ�
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

/************************��������************************/
#define GUI_TIMER_ID			1
#define TIMEOUT					5

#if (_LCD_DPI_ == _LCD_800480_)
#define DT_TEXT_LEFT			190
#define DT_TEXT_TOP1			400
#define DT_TEXT_TOP2			428
#define DT_TEXT_TOP3			398
#define DT_TEXT_TOP4			431
#define DT_TEXT_DISX			150
#elif (_LCD_DPI_ == _LCD_1024600_)
#define DT_TEXT_LEFT			75
#define DT_TEXT_TOP1			220
#define DT_TEXT_TOP2			238
#define DT_TEXT_TOP3			218
#define DT_TEXT_TOP4			241
#define DT_TEXT_DISX			150
#endif

/************************��������************************/
static RIGHTCTRL_INFO g_rightCtrl;
static HWND g_RightWin = 0;
static uint8 g_tick = 0;

/************************��������************************/
CREATE_FORM(FrmDianti);

/*************************************************
  Function:		draw_bk
  Description: 	������
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
static void draw_bk(HDC hdc)
{
    DrawBmpID(hdc, 0, 0, 0, 0, BID_Dianti_Call_main);
}

/*************************************************
  Function:		draw_string_hint
  Description: 	��������ʾ
  Input:
   1.hdc		���
  Output:		��
  Return:			
  Others:		
*************************************************/
static void draw_string_hint(HDC hdc)
{
	RECT Textrc;
	
	SetTextColor(hdc, COLOR_BLACK);
	SelectFont(hdc, GetFont(FONT_16));
	uint8 language = storage_get_language();
	if (language == ENGLISH)
	{
		Textrc.left = DT_TEXT_LEFT;
		Textrc.top = DT_TEXT_TOP1;
		Textrc.right = Textrc.left + DT_TEXT_DISX;
		Textrc.bottom = Textrc.top + Font16X16;
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit1), -1, &Textrc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit1), -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);	
		
		Textrc.left = DT_TEXT_LEFT;
		Textrc.top = DT_TEXT_TOP2;
		Textrc.right = Textrc.left + DT_TEXT_DISX;
		Textrc.bottom = Textrc.top + Font16X16;
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit2), -1, &Textrc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit2), -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);	
	}
	else
	{
		Textrc.left = DT_TEXT_LEFT;
		Textrc.top = DT_TEXT_TOP3;
		Textrc.right = Textrc.left + DT_TEXT_DISX;
		Textrc.bottom = Textrc.top + Font16X16;
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit1), -1, &Textrc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit1), -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);	
		
		Textrc.left = DT_TEXT_LEFT;
		Textrc.top = DT_TEXT_TOP4;
		Textrc.right = Textrc.left + DT_TEXT_DISX;
		Textrc.bottom = Textrc.top + Font16X16;
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit2), -1, &Textrc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		DrawText(hdc, get_str(SID_Msg_Dianti_Hit2), -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);	
	}
}

/*************************************************
  Function:		OnPaint
  Description: 	���ؼ�
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
static void OnPaint(HWND hDlg)
{
	HDC hdc;
	RECT rc;
	hdc = BeginPaint(hDlg);
	GetClientRect(hDlg, &rc);
	SetBkMode(hdc, BM_TRANSPARENT);
    draw_bk(hdc);
	draw_string_hint(hdc);
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		stop_timer
  Description: 	�ض�ʱ��
  Input: 		��	
  Output:		��
  Return:		��
  Others:
*************************************************/
static void stop_timer(HWND hDlg)
{
	KillTimer(hDlg, GUI_TIMER_ID);
	form_close(&FrmDianti);
}

/*************************************************
  Function:		callout_tick_proc
  Description: 	��ʱ
  Input:		
  	1.hDlg      ���ھ��
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void dianti_tick_proc(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if (g_tick != TIMEOUT)
	{
		g_tick ++;
	}
	else
	{
		stop_timer(hDlg);
		g_tick = 0;
	}
}

/*************************************************
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:
  	1.lParam    ����λ��
  	2.hDlg      ���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	uint32 image = SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Get_ImageOrTextID, lParam, 0);

	switch (image)
	{
		case BID_Right_Down:
			#ifdef _DIANTI_CALL_
			dianti_set_cmd(ELEVATOR_DOWN);
			#endif
			stop_timer(hDlg);
			break;
			 
		default:
			break;
    }
}

/*************************************************
  Function:		OnCommand
  Description: 	�ؼ��¼�������
  Input: 		
	1.id		���صĿؼ�ID
	2.lParam	����λ��
	3.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void OnCommand( HWND hDlg,WPARAM id, LPARAM lParam)
{
	switch(id)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg, lParam);
            break;
			
		default:
			break;
	}
	return;
}

#ifdef _ENABLE_TOUCH_
/*************************************************
  Function:		get_key_down
  Description: 	��������
  Input: 		
	1.hDlg		���
	2.x			X����
	3.y			Y����
  Output:		��
  Return:		��
  Others:
*************************************************/
static void get_key_down(HWND hDlg, int x, int y)
{
}

/*************************************************
  Function:		get_key_up
  Description: 	����̧��
  Input: 		
	1.hDlg		���
	2.x			X����
	3.y			Y����
  Output:		��
  Return:		��
  Others:
*************************************************/
static void get_key_up(void)
{ 
}
#endif

/*************************************************
  Function:		CreateRightCtrl
  Description: 	��ʼ���ұ߿ؼ�
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateRightCtrl(HWND hDlg)
{
	uint32 i;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, 0, 0, BID_Right_Down};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, 0, 0};

	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.parent = hDlg;
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = Font16X16;
	for(i = 0; i < g_rightCtrl.MaxNum; i++)
	{
		g_rightCtrl.buttons[i].Enabled = TRUE;
		g_rightCtrl.buttons[i].ImageID = ImageID[i];
		g_rightCtrl.buttons[i].TextID = TextID[i];
	}
	g_RightWin = CreateWindow(AU_RIGHT_BUTTON, "", 
				WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				IDC_RIGHT_BUTTON, 
				RIGHT_CTRL_X, RIGHT_CTRL_Y, 
				RIGHT_CTRL_W, RIGHT_CTRL_H, 
				hDlg, (DWORD)&g_rightCtrl);
}

/*************************************************
  Function:		create_ctrls
  Description: 	�����ؼ�
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
static void create_ctrls(HWND hDlg)	
{
	CreateRightCtrl(hDlg);
}

/*************************************************
  Function:		WindowProc
  Description: 	��Ϣ������
  Input: 		
  	1.hDlg		���
  	2.message	��Ϣ
  	3.wParam	����1
  	4.lParam	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static int WindowProc(HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
		case MSG_CREATE:
			 create_ctrls(hDlg);			
			break;
		
		case MSG_INITDIALOG:
			SetWindowBkColor(hDlg, PAGE_BK_COLOR);
			break;
			
		case MSG_ACTIVE:
			break;

		case MSG_SHOWWINDOW:
			if (wParam == SW_SHOWNORMAL)
			{
				g_tick = 0;
				SetTimer(hDlg, GUI_TIMER_ID, 50);	
			}
			else if (wParam == SW_HIDE)
			{
				close_page();
			}
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			return 0;
			
       	#ifdef _ENABLE_TOUCH_
		case MSG_LBUTTONDOWN:
    		get_key_down(hDlg, LOWORD(lParam), HIWORD(lParam));
   			break;
   			
	    case MSG_LBUTTONUP:
	        get_key_up(hDlg, LOWORD(lParam), HIWORD(lParam));
	        break;
        #endif
		
	    case MSG_KEYDOWN:
			SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), MSG_KEYDOWN, wParam, lParam);
        	break;

		case MSG_KEYUP:
			SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), MSG_KEYUP, wParam, lParam);
			break;
			
		case MSG_COMMAND:
			OnCommand(hDlg, wParam, lParam);
			break;
			
		case MSG_TIMER:	
			dianti_tick_proc(hDlg, wParam, lParam);
			break;
		
		case MSG_CLOSE:
			DestroyMainWindow(hDlg);
			PostQuitMessage(hDlg);
			return 0;
		
		case MSG_DESTROY:
			if (hDlg)
			{
				KillTimer(hDlg, GUI_TIMER_ID);
			}
			break;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

