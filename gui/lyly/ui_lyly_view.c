/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_lyly_view.c
  Author:   	caogw
  Version:   	2.0
  Date: 		14-12-13
  Description:  
  				���Բ���
  History:     
  	1. Date:	
		   Author:	
		   Modification:
*********************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

/************************��������************************/
#define MEDIA_LYLY_STOP			0
#define MEDIA_LYLY_PLAY			1
#define MEDIA_LYLY_PAUSE		2
#define OPER_DELAY_TIME			2
#define GUI_TIMER_ID			1

#if (_LCD_DPI_ == _LCD_800480_)
#define LYLY_TEXT_LEFT_1		280	
#define LYLY_TEXT_TOP_1			400	
#define LYLY_TEXT_LEFT_2		254		
#define LYLY_TEXT_TOP_2			420	
#define LYLY_TEXT_LEN			150
#define LYLY_PIC_LEFT			0
#define LYLY_PIC_TOP			0
#define LYLY_PIC_RIGHT			640
#define LYLY_PIC_BOTTOM	    	480
#elif (_LCD_DPI_ == _LCD_1024600_)
#define LYLY_TEXT_LEFT_1		330	
#define LYLY_TEXT_TOP_1			500	
#define LYLY_TEXT_LEFT_2		315		
#define LYLY_TEXT_TOP_2			525	
#define LYLY_TEXT_LEN			188
#define LYLY_PIC_LEFT			0
#define LYLY_PIC_TOP			0
#define LYLY_PIC_RIGHT			820
#define LYLY_PIC_BOTTOM	    	600
#endif

/************************��������************************/
static PLYLYLIST_INFO g_lylylist = NULL;			// ��Ϣ�б�
static int16 g_index = -1;
static HWND g_RighthDlg = -1;
static HWND g_ParenthDlg;
static RIGHTCTRL_INFO g_rightCtrl;					// �ұ߿ؼ���Ϣ
static uint32 g_RightIndex = 0;
static uint8 g_media_state = MEDIA_LYLY_STOP;
static uint8 g_operdelaytimer = 0;
static char g_filename[100];
static HWND g_lylywin = 0;

/************************��������************************/
CREATE_FORM(FrmLylyView);

/*************************************************
  Function:		reflash_page
  Description: 	ˢ�½���
  Input: 		��	
  Output:		��
  Return:		��
  Others:
*************************************************/
static void reflash_page(void)
{
	RECT rc;
	
	rc.left = FORM_X;
	rc.top = FORM_Y;
	rc.right = FORM_W;
	rc.bottom = FORM_H;
	InvalidateRect(self->hWnd, &rc, FALSE);
}

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
	if (g_lylylist->Count)
	{	
		if (g_lylylist->LylyInfo[g_index].LyType == LYLY_TYPE_AUDIO || g_media_state == MEDIA_LYLY_STOP)
		{
			DrawBmpID(hdc, 0, 0, 0, 0, BID_LYLY_BK);
		}
		else
		{
			DrawBmpID(hdc, 0, 0, 0, 0, BID_Inter_VideoWinBK);
		}
	}
}

/*************************************************
  Function:		draw_dev_hint
  Description: 	���豸����ʾ
  Input:
   1.hdc		���
  Output:		��
  Return:			
  Others:		
*************************************************/
static void draw_dev_hint(HDC hdc)
{
	RECT rc;
	char devtext[50];
	char time[50];
	
	memset(devtext, 0, sizeof(devtext));
	memset(time, 0, sizeof(time));
	
	SetTextColor(hdc, COLOR_GREEN);
	SelectFont(hdc, GetFont(WIN_COMM_FONT));
	get_dev_description(g_lylylist->LylyInfo[g_index].DevType, g_lylylist->LylyInfo[g_index].DevNo, devtext, 50);
	
	rc.left = LYLY_TEXT_LEFT_1;
	rc.top = LYLY_TEXT_TOP_1;
	rc.right = rc.left + 165;
	rc.bottom = rc.top + WIN_COMM_FONT;
	if (g_lylylist->LylyInfo[g_index].DevType == DEVICE_TYPE_ROOM)
	{
		DrawText(hdc, devtext, -1, &rc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		DrawText(hdc, devtext, -1, &rc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);
	}
	else
	{
		DrawText(hdc, devtext, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
	
	sprintf(time, "%04d-%02d-%02d %02d:%02d:%02d", g_lylylist->LylyInfo[g_index].Time.year, g_lylylist->LylyInfo[g_index].Time.month, g_lylylist->LylyInfo[g_index].Time.day,
		g_lylylist->LylyInfo[g_index].Time.hour, g_lylylist->LylyInfo[g_index].Time.min, g_lylylist->LylyInfo[g_index].Time.sec);
	rc.left = LYLY_TEXT_LEFT_2;
	rc.top = LYLY_TEXT_TOP_2;
	rc.right = rc.left + LYLY_TEXT_LEN;
	rc.bottom = rc.top + WIN_COMM_FONT;
	DrawText(hdc, time, -1, &rc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);
}

/*************************************************
  Function:		OnPaint
  Description: 	��ʾ����
  Input: 		
	1.hDlg		���ھ��
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
	SetBrushColor(hdc, PAGE_BK_COLOR);
	draw_bk(hdc);
	draw_dev_hint(hdc);
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		start_change_rightkey
  Description:  ��ʼ�ı��ұ߿ؼ�����ʾ����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void change_rightkey(void)
{
	uint32 TextID[2] = {SID_Right_Stop, SID_Right_Play};
	if (g_media_state == MEDIA_LYLY_PLAY)
	{
		SendMessage(g_RighthDlg, WM_Right_Set_TextID, 3, (LPARAM)TextID[0]);
	}
	else
	{
		SendMessage(g_RighthDlg, WM_Right_Set_TextID, 3, (LPARAM)TextID[1]);
	}
}

/*************************************************
  Function:			ProcessProc
  Description: 		ֹͣ��������
  Input:		
  	1.win
  Output:			��
  Return:			��
  Others:		
*************************************************/
static int32 ProcessProc(int32 param1,int32 param2,int32 state)
{
	LYLY_TYPE type;
	
	type = g_lylylist->LylyInfo[g_index].LyType;
	if 	(FALSE == state)
	{
		g_media_state = MEDIA_LYLY_STOP;
		if (type == LYLY_TYPE_PIC_AUDIO)
		{
			media_stop_show_pict();
		}
		change_rightkey();
		reflash_page();
		return TRUE;
	}

	if (g_media_state == MEDIA_LYLY_PLAY)
	{
		if (100 == param2)
		{
			g_media_state = MEDIA_LYLY_STOP;
			if (type == LYLY_TYPE_PIC_AUDIO)
			{
				media_stop_show_pict();
			}
			change_rightkey();
			reflash_page();
		}
	}
	return TRUE;
}

/*************************************************
  Function:			StopProc
  Description: 		ֹͣ��������
  Input:		
  	1.win
  Output:			��
  Return:			��
  Others:		
*************************************************/
static void StopProc(void)
{
	if (g_media_state == MEDIA_LYLY_PLAY)
	{
		g_media_state = MEDIA_LYLY_STOP;
		change_rightkey();
		reflash_page();
	}
}

/*************************************************
  Function:		Load_pic_audio
  Description:  ��ʼ����ͼƬ����������
  Input:		��
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void Load_pic_audio(void)
{
	char * data;
	char path[50];
	LYLY_TYPE type;

	if (NULL != g_lylylist)
	{	
		uint8 ret = 0;
		type = g_lylylist->LylyInfo[g_index].LyType;
		if (type == LYLY_TYPE_PIC_AUDIO || type == LYLY_TYPE_AUDIO)
		{
			// ��������	
			//ret = sys_start_play_audio(SYS_MEDIA_MUSIC, g_filename, FALSE, LYLY_VIEW_VOL, ProcessProc, StopProc);
			ret = sys_start_play_leaveword(g_filename, type, LYLY_VIEW_VOL, ProcessProc, StopProc);
			if (ret == SYS_MEDIA_ECHO_OK)
			{
				g_media_state = MEDIA_LYLY_PLAY;
				reflash_page();
				change_rightkey();
				storage_set_lylyrecord_flag(g_index, FALSE);
				sys_sync_hint_state();
			}
		}
		if (type == LYLY_TYPE_PIC_AUDIO && ret == SYS_MEDIA_ECHO_OK)
		{
			// ��ͼƬ
			data = get_lylypic_path(path, &(g_lylylist->LylyInfo[g_index].Time)); 
			if (NULL != data)
			{
				media_start_show_pict(data, LYLY_PIC_LEFT, LYLY_PIC_TOP, LYLY_PIC_RIGHT, LYLY_PIC_BOTTOM);
				data = NULL;                
			}
		}
	}
}

/*************************************************
  Function:			play_media_file
  Description: 		������Ƶ�ļ�
  Input:			�� 		
  Output:			��
  Return:			��
  Others:
*************************************************/
static void play_media_file(void)
{
	uint32 ret = sys_start_play_leaveword(g_filename, LYLY_TYPE_VIDEO, 7, ProcessProc, StopProc);
	if (SYS_MEDIA_ECHO_OK == ret)
	{
		g_media_state = MEDIA_LYLY_PLAY;
		reflash_page();
		change_rightkey();
		storage_set_lylyrecord_flag(g_index, FALSE);
		sys_sync_hint_state();
	}
}

/*************************************************
  Function:			media_lyly_play
  Description: 		��������
  Input:		
  	1.win
  Output:			��
  Return:			��
  Others:		
*************************************************/
static void media_lyly_play(void)
{
	if (g_media_state == MEDIA_LYLY_STOP && g_lylylist && g_lylylist->Count > 0 && 0 == g_operdelaytimer)
	{
		//g_operdelaytimer = OPER_DELAY_TIME+1;
		memset(g_filename,0,sizeof(g_filename));
		get_lylyrecord_path(g_filename, &(g_lylylist->LylyInfo[g_index].Time));
		
		switch (g_lylylist->LylyInfo[g_index].LyType) 
		{
			case LYLY_TYPE_PIC_AUDIO:							// Ӱ��ģʽ
			case LYLY_TYPE_AUDIO:								// ����ģʽ	
				strcat(g_filename,".wav");
				Load_pic_audio();
				break;
				
			case LYLY_TYPE_VIDEO:								// ��Ƶģʽ
				strcat(g_filename,".avi");
				play_media_file();
				break;
				
			default:
				break;
		}	
	}
}

/*************************************************
  Function:			media_lyly_stop
  Description: 		ֹͣ��������
  Input:		
  	1.win
  Output:			��
  Return:			��
  Others:		
*************************************************/
static void media_lyly_stop(void)
{
	if (MEDIA_LYLY_PLAY == g_media_state && 0 == g_operdelaytimer)
	{
		//g_operdelaytimer = OPER_DELAY_TIME;
		LYLY_TYPE type;
		type = g_lylylist->LylyInfo[g_index].LyType;
		
		if (type == LYLY_TYPE_VIDEO)
		{
			sys_stop_play_leaveword();
		}
		else
		{
			if (type == LYLY_TYPE_PIC_AUDIO)
			{
				media_stop_show_pict();
			}
			//sys_stop_play_audio(SYS_MEDIA_MUSIC);
			sys_stop_play_leaveword();
		}
		g_media_state = MEDIA_LYLY_STOP;
		change_rightkey();
		reflash_page();
	}
}

/*************************************************
  Function:		lyly_tick_proc
  Description: 	��ʱ
  Input:		
  	1.hDlg      ���ھ��
  	2.wParam
  	3.lParam
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void lyly_tick_proc(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	g_operdelaytimer--;
	if (g_operdelaytimer == 0)
	{		
		KillTimer(hDlg, GUI_TIMER_ID);
		media_lyly_play();
	}
}

/*************************************************
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		
  	1.hDlg
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM index)
{
	uint32 Image;
	
	g_RightIndex = SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Get_ImageOrTextID, index, 0);
	Image = g_RightIndex;
	switch (Image)
	{		
		case SID_Right_Stop:
			media_lyly_stop();
			break;
			
		case SID_Right_Play:
			media_lyly_play();
			break;
			
		case BID_Right_Exit:
			if (g_media_state == MEDIA_LYLY_STOP)
			{
				SendMessage(g_ParenthDlg, MSG_COMMAND, IDC_FORM, 0);
				close_page();
			}
			break;
	}
}

/*************************************************
  Function:		OnCommand
  Description: 	�ؼ��¼�������
  Input: 		
	1.id		���صĿؼ�ID
	2.index		�ؼ�����
	3.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void OnCommand( HWND hDlg, WPARAM id, LPARAM index)
{	
	switch (id)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg, index);
			break;
			
		default:
			break;
	}
}

/*************************************************
  Function:		ui_lyly_view
  Description: 	��Ӱ���Խ���
  Input:		
  
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_lyly_view(HWND hDlg, uint8 index, PLYLYLIST_INFO lylylist)
{
	g_ParenthDlg = hDlg;		// ���游������
	g_index = index;
	g_lylylist = lylylist;
	g_media_state = MEDIA_LYLY_STOP;
	g_operdelaytimer = 1;
	form_show(&FrmLylyView);
	
	return TRUE;
}

/*************************************************
  Function:		OnDestroy
  Description: 	���ٴ�����
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 OnDestroy(HWND hDlg)
{
	g_index = -1;
	if (hDlg)
	{
		KillTimer(hDlg, GUI_TIMER_ID);
	}
	media_stop_show_pict();

	return TRUE;
}

/*************************************************
  Function:		CreateRightCtrl
  Description: 	�����ұ߿ؼ�
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateRightCtrl(HWND hDlg)
{
	uint32 i;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, 0, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Play, 0};
	
	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = RIGHT_CTRL_FONT;
	g_rightCtrl.parent = hDlg;
	for (i = 0; i < g_rightCtrl.MaxNum; i++)
	{
		g_rightCtrl.buttons[i].Enabled = TRUE;
		g_rightCtrl.buttons[i].ImageID = ImageID[i];
		g_rightCtrl.buttons[i].TextID = TextID[i];
	}
	g_RighthDlg = CreateWindow(AU_RIGHT_BUTTON, "", 
				WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				IDC_RIGHT_BUTTON, 
				RIGHT_CTRL_X, RIGHT_CTRL_Y, RIGHT_CTRL_W, RIGHT_CTRL_H, 
				hDlg, (DWORD)&g_rightCtrl);
}

/*************************************************
  Function:		create_ctrls
  Description: 	�����ؼ�
  Input: 		
	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void create_ctrls(HWND hDlg)	
{
	CreateRightCtrl(hDlg);
}

#ifdef _ENABLE_TOUCH_
/*************************************************
  Function:		get_touch_down
  Description: 	����������
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static int get_touch_down(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

/*************************************************
  Function:		get_touch_up
  Description: 	������̧��
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static int get_touch_up(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
#endif

/*************************************************
  Function:		WindowProc
  Description: 	��Ϣ������
  Input: 		
  	1.hDlg		���ھ��
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
			g_lylywin = hDlg;
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
				SetTimer(hDlg, GUI_TIMER_ID, 5);
			}
			else if (wParam == SW_HIDE)
			{
				close_page();
			}
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			break;

		#ifdef _ENABLE_TOUCH_
		case MSG_LBUTTONDOWN:
			if (GetCapture() == hDlg)
			{
				break;
			}
			SetCapture(hDlg);
    		get_touch_down(hDlg, LOWORD(lParam), HIWORD(lParam));
   			break;
   			
	    case MSG_LBUTTONUP:
	    	if (GetCapture() != hDlg)
			{
				break;
			}
			ReleaseCapture();
	        get_touch_up(hDlg, LOWORD(lParam), HIWORD(lParam));
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
			lyly_tick_proc(hDlg, wParam, lParam);
			break;	
			
		case MSG_CLOSE:
			DestroyMainWindow(hDlg);
			PostQuitMessage(hDlg);	
			return 0;
			
		case MSG_DESTROY:
			OnDestroy(hDlg);
			return 0;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

