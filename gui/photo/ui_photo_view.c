/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_photo_view.c
  Author:   	caogw
  Version:   	2.0
  Date: 		14-12-10
  Description:  
  				��Ƭ�鿴����
  History:     
  	1. Date:	
		   Author:	
		   Modification:
*********************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

/************************��������************************/
#if (_LCD_DPI_ == _LCD_800480_)
#define TEXT_LEFT1			280				
#define TEXT_TOP1			400
#define TEXT_LEFT2			242				
#define TEXT_TOP2			420
#define TEXT_LEN			150
#define PHOTO_PIC_LEFT		0
#define PHOTO_PIC_TOP		0
#define PHOTO_PIC_RIGHT		640
#define PHOTO_PIC_BOTTOM	480
#elif (_LCD_DPI_ == _LCD_1024600_)
#define TEXT_LEFT1			280				
#define TEXT_TOP1			400
#define TEXT_LEFT2			242				
#define TEXT_TOP2			420
#define TEXT_LEN			150
#define PHOTO_PIC_LEFT		0
#define PHOTO_PIC_TOP		0
#define PHOTO_PIC_RIGHT		640
#define PHOTO_PIC_BOTTOM	480
#endif

/************************��������************************/
static PPHOTOLIST_INFO g_photolist = NULL;					// ��Ϣ�б�
static int16 g_index = -1;
static HWND g_RighthDlg = -1;
static HWND g_ParenthDlg;
static RIGHTCTRL_INFO g_rightCtrl;					// �ұ߿ؼ���Ϣ
static uint32 g_RightIndex = 0;
static uint8 g_LoadFlag = FALSE;					// ��һ�ν���ҳ�����ʱ��Flag

/************************��������************************/
CREATE_FORM(FrmPhotoView);

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
	if (g_photolist->Count)
	{	
		DrawBmpID(hdc, 0, 0, 0, 0, BID_Inter_VideoWinBK);
	}
	else
	{
		DrawBmpID(hdc, 0, 0, 0, 0, BID_Snap_Bk);
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
	if (!g_photolist->Count)
	{
		return;
	}
	
	RECT rc;
	char devtext[50];
	char time[50];
	
	memset(devtext, 0, sizeof(devtext));
	memset(time, 0, sizeof(time));
	
	SetTextColor(hdc, COLOR_GREEN);
	SelectFont(hdc, GetFont(FONT_16));
	get_dev_description(g_photolist->PhotoInfo[g_index].Type, g_photolist->PhotoInfo[g_index].DevNo, devtext, 50);	
	rc.left = TEXT_LEFT1;
	rc.top = TEXT_TOP1;
	rc.right = rc.left + TEXT_LEN;
	rc.bottom = rc.top + Font16X16;
	DrawText(hdc, devtext, -1, &rc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
	DrawText(hdc, devtext, -1, &rc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);
	
	sprintf(time,"%04d-%02d-%02d %02d:%02d:%02d",g_photolist->PhotoInfo[g_index].Time.year,g_photolist->PhotoInfo[g_index].Time.month,g_photolist->PhotoInfo[g_index].Time.day
		,g_photolist->PhotoInfo[g_index].Time.hour,g_photolist->PhotoInfo[g_index].Time.min,g_photolist->PhotoInfo[g_index].Time.sec);
	rc.left = TEXT_LEFT2;
	rc.top = TEXT_TOP2;
	rc.right = rc.left + TEXT_LEN;
	rc.bottom = rc.top + Font16X16;
	DrawText(hdc, time, -1, &rc, DT_CALCRECT|DT_LEFT|DT_VCENTER|DT_SINGLELINE);
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
static void start_change_rightkey(HWND hDlg)
{
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Sure, 0};
	change_rightctrl_allimagetext(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), ImageID, TextID);
}

/*************************************************
  Function:		finish_change_rightkey
  Description:  ����ʱ�ı��ұ߿ؼ�����ʾ����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void finish_change_rightkey(HWND hDlg)
{
	uint32 ImageID[RIGHT_NUM_MAX] = { 0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Del, 0};
	change_rightctrl_allimagetext(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), ImageID, TextID);
}

/*************************************************
  Function:		Loadphoto
  Description:  ��ʼ������Ϣ����
  Input:		��
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void Loadphoto(void)
{
	char * data;
	char filename[100];
	if (NULL != g_photolist)
	{
		// ��ͼƬ
		memset(filename, 0, sizeof(filename));
		if (g_photolist->Count)
		{
			data = get_photo_path(filename, &g_photolist->PhotoInfo[g_index].Time);
			if (NULL != data)
			{
				media_start_show_pict(data, PHOTO_PIC_LEFT, PHOTO_PIC_TOP, PHOTO_PIC_RIGHT, PHOTO_PIC_BOTTOM);
				data = NULL;              
			}
		}
	}	
	reflash_page();	
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
		case BID_Right_Up:
			g_index = (g_index+g_photolist->Count-1) % (g_photolist->Count);
			break;

		case BID_Right_Table:	
		case BID_Right_Down:
			if (-1 != g_index && g_index < g_photolist->Count && g_photolist->Count)
			{
				g_index = (g_index+1 )% g_photolist->Count;
				Loadphoto();
			}
			break;
			
		case SID_Right_Del:
			if (-1 != g_index && g_index < g_photolist->Count && g_photolist->Count)
			{
				start_change_rightkey(hDlg);
				show_msg(hDlg, IDC_MSG_CTRL, MSG_QUERY, SID_Bj_Query_Del_Rec_One);
			}
			break;
			
		case BID_Right_Exit:
			SendMessage(g_ParenthDlg, MSG_COMMAND, IDC_FORM, 0);
			close_page();
			break;
	}
}

/*************************************************
  Function:		MsgCtrlCommand
  Description: 	��Ϣ��ؼ��Ĵ�����
  Input:		
  	1.hDlg		���ھ��
  	2.event		�¼���Ϣ
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void MsgCtrlCommand(HWND hDlg, LPARAM event)
{
	ECHO_STORAGE ret = ECHO_STORAGE_ERR;

	if (MSG_EVENT_YES == event)
	{
		switch(g_RightIndex)
		{
			// ɾ��������Ƭ
			case SID_Right_Del:
				if (-1 != g_index && g_photolist && g_index < g_photolist->Count)
				{
					ret = storage_del_photo(g_index);
					if (ECHO_STORAGE_OK == ret)
					{
						storage_free_photo_memory(&g_photolist);
						storage_get_photo(&g_photolist);
						if (g_photolist && g_index > (g_photolist->Count-1))
						{
							g_index = g_photolist->Count-1;
						}
						show_msg(hDlg, IDC_Msg_Notice, MSG_RIGHT, SID_Oper_OK);
						if (g_photolist->Count)
						{
							Loadphoto();
						}
						else
						{
							media_stop_show_pict();
							reflash_page();
						}
					}
					else
					{
						show_msg(hDlg, IDC_Msg_Notice, MSG_INFORMATION, SID_Oper_ERR);
					}	
				}
				break;
		}
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

		
		case IDC_MSG_CTRL:
			MsgCtrlCommand(hDlg, index);
			break;
			
		default:
			break;
	}
}

/*************************************************
  Function:		ui_msg_view
  Description: 	��Ϣ�鿴������
  Input:		
  
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_photo_view(HWND hDlg, uint8 index, PPHOTOLIST_INFO photolist)
{
	g_ParenthDlg = hDlg;		// ���游������
	g_index = index;
	g_photolist = photolist;
	g_LoadFlag = TRUE;
	form_show(&FrmPhotoView);
	
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
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Del, 0};
	
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
			create_ctrls(hDlg);
			break;

		case MSG_INITDIALOG:
			SetWindowBkColor(hDlg, PAGE_BK_COLOR);
			break;
			
		case MSG_ACTIVE:
			break;

		case MSG_SHOWWINDOW:
			if (wParam == SW_HIDE)
			{
				close_page();
			}
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			if (g_LoadFlag)
			{
				Loadphoto();
				g_LoadFlag = FALSE;	
			}
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
			switch((int)wParam)
			{
				case TK_CENTER:						
				case TK_MONITOR:					
					media_stop_show_pict();	
					break;
			}
			SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), MSG_KEYUP, wParam, lParam);
            break;

		case MSG_COMMAND:
			OnCommand(hDlg, wParam, lParam);
			break;
			
		case WM_Change_RightKey:
			finish_change_rightkey(hDlg);
			break;
			
		case MSG_TIMER:
			break;	

		case MSG_CLOSE:
			DestroyMainWindow(hDlg);
			PostQuitMessage(hDlg);
			return 0;
		
		case MSG_DESTROY:
			OnDestroy(hDlg);
			break;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

