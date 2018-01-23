/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_set_lyly.c
  Author:   	yanjl
  Version:   	1.0
  Date: 		2014-12-01
  Description:  
  				��Ӱ���Խ�������
  History:            
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#include "gui_include.h"
#include "storage_include.h"

CREATE_FORM(FrmlylyParam);

static HWND g_rightwin;
static HWND g_listwin;
static uint8 g_page = 0;
static LYLY_PARAM *g_param = NULL;
static RIGHTCTRL_INFO g_rightCtrl;
static LISTCTRL_INFO g_listCtrl;

/*************************************************
  Function:		set_list_enable
  Description:
  Input:		
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void set_list_enable(uint8 enable)
{
	SendMessage(g_listwin, WM_List_Set_Enable, 1, (LPARAM)&enable);
	SendMessage(g_listwin, WM_List_Set_Enable, 2, (LPARAM)&enable);
	SendMessage(g_listwin, WM_List_Set_Enable, 3, (LPARAM)&enable);
	SendMessage(g_listwin, WM_List_Set_Enable, 4, (LPARAM)&enable);
	SendMessage(g_listwin, WM_List_Set_Enable, 5, (LPARAM)&enable);
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
  Function:		show_win
  Description: 	��ʾ�ľ�����Ϣ
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void show_win(HDC hdc)
{
	uint32 i,max = 4;
	PLISTITEM_INFO g_info = NULL;
	uint32 TextID1;
	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);

	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info, 0, (sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			switch (i)
			{
				case 0:
					g_info[i].Num = 2;
					g_info[i].Icon = 0;
					g_info[i].Item[0].Change = FALSE;
					if (g_param->Enable)
					{
						g_info[i].Item[0].Image = BID_Com_Chose;
					}
					else
					{
						g_info[i].Item[0].Image = BID_Com_UnChose;
					}
					g_info[i].Item[0].ShowType = STYLE_LEFT;
					g_info[i].Item[1].TextID = SID_Set_Used;
					g_info[i].Item[1].ShowType = STYLE_LEFT;
					break;

				case 1:
					g_info[i].Num = 2;
					g_info[i].Item[0].TextID = SID_Set_Mode;
					g_info[i].Item[0].ShowType = STYLE_LEFT;
					g_info[i].Icon = BID_ListIcon;
					g_info[i].Item[1].Change = FALSE;
					g_info[i].Item[1].TextID = SID_Set_Lyly_Mode_Audio+g_param->Mode;
					g_info[i].Item[1].ShowType = STYLE_LEFT;
					break;

				case 2:
				case 3:	
				case 4:	
					g_info[i].Num = 2;
					g_info[i].Icon = 0;
					g_info[i].Item[0].Change = FALSE;
					if (g_param->Link[i-2])
					{
						g_info[i].Item[0].Image = BID_Com_Chose;
					}
					else
					{
						g_info[i].Item[0].Image = BID_Com_UnChose;
					}
					g_info[i].Item[0].ShowType = STYLE_LEFT;
					g_info[i].Item[1].TextID = SID_Set_Lyly_Link1+i-2;
					g_info[i].Item[1].ShowType = STYLE_LEFT;
					break;	

				case 5:
					g_info[i].Num = 2;
					g_info[i].Item[0].TextID = SID_Set_hit;
					g_info[i].Item[0].ShowType = STYLE_LEFT;
					g_info[i].Icon = BID_ListIcon;
					g_info[i].Item[1].Change = FALSE;
					g_info[i].Item[1].TextID = SID_Set_Lyly_default_tip+g_param->default_tip;
					g_info[i].Item[1].ShowType = STYLE_LEFT;
					break;	
			}
		}
		SendMessage(g_listwin, WM_List_Add_Item, max, (LPARAM)g_info);

		if (FALSE == g_param->Enable)
		{
			set_list_enable(g_param->Enable);
		}

		TextID1 = SID_Right_Save;
		SendMessage(g_rightwin, WM_Right_Set_TextID, 1, (LPARAM)TextID1);	
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
  Function:		save_param
  Description: 	����
  Input:		
  	1.hDlg
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void save_param(HWND hDlg)
{
	uint8 ret = TRUE;
	ret = storage_set_lyly_param(g_param);
	if (ret)
	{
		sys_sync_hint_state();
		show_msg(hDlg, IDC_MSG_CTRL, MSG_RIGHT, SID_Save_OK);
	}
	else
	{
		show_msg(hDlg, IDC_MSG_CTRL, MSG_INFORMATION, SID_Save_ERR);
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
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	uint32 id = SendMessage(g_rightwin, WM_Right_Get_ImageOrTextID, lParam, 0);
	
	switch(id)
	{
		case SID_Right_Save:
			save_param(hDlg);
			break;
			
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
	switch(lParam)
	{
		case 0:
			if (g_param->Enable)
			{
				g_param->Enable = FALSE;
				set_list_Image(g_listwin, lParam, 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				g_param->Enable = TRUE;
				set_list_Image(g_listwin, lParam, 0, BID_Com_Chose, CHECK_IMAGE);
			}	
			set_list_enable(g_param->Enable);
			break;
			
		case 1:
			if (g_param->Enable)
			{
				ui_lylymode_win(hDlg, g_param->Mode);
			}
			break;

		case 2:
		case 3:
		case 4:
			if (g_param->Enable)
			{
				if (g_param->Link[lParam-2])
				{
					g_param->Link[lParam-2] = FALSE;
					set_list_Image(g_listwin, lParam, 0, BID_Com_UnChose, CHECK_IMAGE);
				}
				else
				{
					g_param->Link[lParam-2] = TRUE;
					set_list_Image(g_listwin, lParam, 0, BID_Com_Chose, CHECK_IMAGE);
				}	
			}
			break;

		case 5:
			//ui_lyrecord_win(hDlg, 0, &g_param->default_tip);
			break;
	}
}

/*************************************************
  Function:		lylyCommand
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
			
		default:
			if (wParam == FrmlylyMode.hWnd)
			{
				g_param->Mode = *((uint32*)lParam);
				InvalidateRect(hDlg, NULL, FALSE);
			}
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
	uint16 ImageID[RIGHT_NUM_MAX] = {0, 0,BID_Right_Table,0,BID_Right_Exit};
	uint16 TextID[RIGHT_NUM_MAX] = {0, SID_Right_Save, 0, SID_Right_Sure, 0};
	
	memset(&g_rightCtrl,0,sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.parent = hDlg;
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = RIGHT_CTRL_FONT;
	for(i = 0; i < g_rightCtrl.MaxNum; i++)
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
	memset(&g_listCtrl,0,sizeof(LISTCTRL_INFO));
	g_listCtrl.Parent = hDlg;
	g_listCtrl.Mode = LIST_MODE_COMMON;				// ̧���ͷţ�û�и�����ʾ
	g_listCtrl.Caption = 1;							// �Ƿ��б�����
	g_listCtrl.Sidebar = 0;							// �����
	g_listCtrl.SideBarMode = 1;
	g_listCtrl.KeyCallBack = (SidebarKeyCallBack)get_Sidebar_key;
	g_listCtrl.Drawcallback = (SidebarCallBack)draw_Sidebar;// �����
	g_listCtrl.fonttype = LIST_CTRL_FONT;				// ������ʾ��С
	g_listCtrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_listCtrl.HeadInfo.TextID = SID_Set_User_LyLy;
	#if (_LCD_DPI_ == _LCD_800480_)
	g_listCtrl.Width[0] = 100;
	g_listCtrl.Width[1] = 300;
	#elif (_LCD_DPI_ == _LCD_1024600_)
	g_listCtrl.Width[0] = 125;
	g_listCtrl.Width[1] = 375;
	#endif
	
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	g_listCtrl.PageCount = 8;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK8_0;
	#else
	g_listCtrl.PageCount = 5;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK5_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK5_0;
	#endif

	g_listwin = CreateWindow(AU_LIST_CTRL, "", 
	 		 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
			 IDC_LIST_CTRL, 
			 LIST_CTRL_X,LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
			 hDlg, (DWORD)&g_listCtrl);	
}

/*************************************************
  Function:		ui_lyly_win
  Description: 	������Ӱ���Խ���
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_lyly_win(HWND hDlg)
{ 
	uint8 ret = FALSE;
	
	ret = form_show(&FrmlylyParam);
	if (ret == TRUE)
	{
	 	g_page = 0;
		g_param = (PLYLY_PARAM) malloc(sizeof(LYLY_PARAM));
		if (NULL == g_param)
		{
			return FALSE;
		}
		memcpy(g_param, (PLYLY_PARAM)storage_get_lyly_param(), sizeof(LYLY_PARAM));
	}
	
	return ret;
}

/*************************************************
  Function:		lylyDestroyProc
  Description: 	���ٴ�����
  Input:		
  	1.hDlg
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void lylyDestroyProc(HWND hDlg , WPARAM wParam, LPARAM lParam)
{
	if (g_param)
	{
		free(g_param);
		g_param = NULL;
	}
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
			return 0;
		
		case MSG_DESTROY:
			lylyDestroyProc(hDlg , wParam, lParam);
			return 0;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

