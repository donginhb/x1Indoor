/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_set_ring.c
  Author:   	yanjl
  Version:   	1.0
  Date: 		2014-12-01
  Description:  
  				�������ý���
  History:            
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#include "gui_include.h"
#include "storage_include.h"

CREATE_FORM(FrmringParam);

static HWND g_rightwin;
static HWND g_listwin;
static uint8 g_page = 0;
static RIGHTCTRL_INFO g_rightCtrl;
static LISTCTRL_INFO g_listCtrl;

/*************************************************
  Function:		show_win_1
  Description: 	��ʾ�ľ�����Ϣ
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void show_win(HWND hDlg)
{
	uint32 i, max = MAX_RING_TYPE;
	PLISTITEM_INFO g_info = NULL;
	
	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);
	//SendMessage(g_listwin, WM_List_Set_HeadText, SID_Set_User_Sound, 0);
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info,0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 2;
			g_info[i].Icon = BID_ListIcon;
			g_info[i].Item[0].Change = FALSE;
			g_info[i].Item[0].ShowType = STYLE_LEFT;
			g_info[i].Item[0].TextID = SID_Set_ring_Stair+i;
		}
		SendMessage(g_listwin, WM_List_Add_Item, max, (LPARAM)g_info);
	
		free(g_info);
		g_info = NULL;
	}
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
	show_win(hdc);
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		Init_Key
  Description: 	
  Input:		
  	1.hDlg
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void Init_Key(HWND hDlg)
{
	add_rightctrl_win(g_rightwin, RIGHT_KEY2, g_listwin, WM_List_Go_NextSel, 0, 0);
	add_rightctrl_win(g_rightwin, RIGHT_KEY3, g_listwin, WM_List_OkKey, 0, 0);
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
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	uint32 id = SendMessage(g_rightwin, WM_Right_Get_ImageOrTextID, lParam, 0);
	
	switch (id)
	{	
		case BID_Right_Exit:
			close_page();
			break;
	}
}

/*************************************************
  Function:		ListViewCommand
  Description: 	�б�ؼ����µĴ�����
  Input:		
  	1.hDlg
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void ListCtrlCommand(HWND hDlg, LPARAM lParam)
{
	//uint32 oldsel;

	g_page = lParam+1;
	ui_ringtype_win(hDlg, g_page);
}

/*************************************************
  Function:		ringCommand
  Description: 	���˵���Ϣ������Ϣ����
  Input:		
  	1.hDlg
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 OnCommand(HWND hDlg , WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg, lParam);
			break;

		case IDC_LIST_CTRL:
			ListCtrlCommand(hDlg, lParam);
			break;	
	}
	
    return TRUE;
}

/*************************************************
  Function:		CreateRightCtrl
  Description: 	��ʼ���ұ߿ؼ�
  Input:		
  	1.hDlg
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void CreateRightCtrl(HWND hDlg)
{
	uint32 i;	
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Sure, 0};
	
	memset(&g_rightCtrl,0,sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.parent = hDlg;
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = Font16X16;
	for (i = 0; i < g_rightCtrl.MaxNum; i++)
	{
		g_rightCtrl.buttons[i].Enabled = TRUE;
		g_rightCtrl.buttons[i].ImageID = ImageID[i];
		g_rightCtrl.buttons[i].TextID = TextID[i];
	}

	g_rightwin = CreateWindow(AU_RIGHT_BUTTON, "", 
				 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				 IDC_RIGHT_BUTTON, 
				 RIGHT_CTRL_X, RIGHT_CTRL_Y, RIGHT_CTRL_W, RIGHT_CTRL_H, 
		 		 hDlg, (DWORD)&g_rightCtrl);
	Init_Key(hDlg);
}

/*************************************************
  Function:		CreateListCtrl
  Description: 	��ʼ���б�ؼ�
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void CreateListCtrl(HWND hDlg)
{
	memset(&g_listCtrl, 0, sizeof(LISTCTRL_INFO));
	g_listCtrl.Parent = hDlg;
	g_listCtrl.Mode = LIST_MODE_COMMON;				// ̧���ͷţ�û�и�����ʾ
	g_listCtrl.Caption = 1;							// �Ƿ��б�����
	g_listCtrl.SideBarMode = 1;
	g_listCtrl.Drawcallback = (SidebarCallBack)draw_Sidebar;// �����
	g_listCtrl.fonttype = Font16X16;				// ������ʾ��С
	#ifdef _TFT_7_
	g_listCtrl.Sidebar = 0;							// ����ʾ�����
	g_listCtrl.PageCount = 8;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK8_0;
	#else
	g_listCtrl.Sidebar = 1;							// �����
	g_listCtrl.PageCount = 5;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK5_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK5_0;
	#endif
	g_listCtrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_listCtrl.HeadInfo.TextID = SID_Set_User_Sound;
	g_listCtrl.Width[0] = 100;
	g_listCtrl.Width[1] = 200;
	
	g_listwin = CreateWindow(AU_LIST_CTRL, "", 
		 		 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				 IDC_LIST_CTRL, 
				 LIST_CTRL_X,LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
				 hDlg, (DWORD)&g_listCtrl);	
}

/*************************************************
  Function:		ui_ring_win
  Description: 	������������
  Input:		
  	1.hDlg
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_ring_win(HWND hDlg)
{ 
	//uint8 i;
	g_page = 0;
	form_show(&FrmringParam);

	return TRUE;
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
	CreateListCtrl(hDlg);
	CreateRightCtrl(hDlg);
}

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
			break;

		case MSG_LBUTTONDOWN:
   			break;
   			
	    case MSG_LBUTTONUP:
	        break;

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
			break;	
			
		case MSG_CLOSE:
			DestroyMainWindow(hDlg);
			PostQuitMessage(hDlg);
			return  0;
		
		case MSG_DESTROY:
			break;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

