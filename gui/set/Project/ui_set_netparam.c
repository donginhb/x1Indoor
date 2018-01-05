/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_set_netparam.c
  Author:   	yanjl
  Version:   	2.0
  Date: 		14-11-27
  Description:  
  				���������������
  History:                 
*********************************************************/

#include "gui_include.h"
#include "storage_include.h"

CREATE_FORM(FrmNetParam);
static HWND g_rightwin;
static HWND g_listwin;
static LISTCTRL_INFO g_listCtrl;
static RIGHTCTRL_INFO g_rightCtrl;
static int16 g_index = -1;
static uint32 g_ip[IP_MAX];
static uint32 g_ipType[] =
{
	HOST_IPADDR,		
	HOST_NETMASK,		
	HOST_GATEWAY,		
	CENTER_IPADDR,		
	MANAGER1_IPADDR,	
	#ifdef _MULTI_CENTER_
	MANAGER2_IPADDR,		
	MANAGER3_IPADDR,	
	#endif
	#ifdef _AURINE_REG_
	AURINE_IPADDR,		
	#endif
	#ifdef _USE_ELEVATOR_
	DIANTI_IPADDR,	
	#endif
	#ifdef _LIVEMEDIA_
	RTSP_IPADDR		
	#endif		
};

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
	uint32 i, max = 0;
	PLISTITEM_INFO g_info = NULL;
	char tmp[40];
	g_index = -1;
	max = (sizeof(g_ipType))/sizeof(uint32);
	
	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info,0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 2;
			g_info[i].Icon = BID_ListIcon;
			g_info[i].Item[0].Change = FALSE;
			g_info[i].Item[0].Image = 0;
			g_info[i].Item[0].ShowType = STYLE_LEFT;

			memset(g_info[i].Item[0].Text,0,sizeof(g_info[i].Item[0].Text));
			strcpy(g_info[i].Item[0].Text, get_str(SID_Set_Prj_Net_HostIP+g_ipType[i]));

			#if 0
			// �������ù���ƽ̨ʱ,��ԭ����ʾ���ַ������滻��ʾ�ɹ��ֵ��ݿ�����
			#ifndef _AURINE_REG_
			if (i == max-1)
			{
				strcpy(g_info[i].Item[0].Text, get_str(SID_Set_Prj_Net_AurineElevator));
			}
			#endif
			#endif
			
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%s",":");
			strcat(g_info[i].Item[0].Text, tmp);
			g_info[i].Item[1].TextID = 0;			
			g_info[i].Item[1].ShowType = STYLE_LEFT;
			change_ip_to_str(g_ip[HOST_IPADDR+g_ipType[i]], g_info[i].Item[1].Text);
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
  Function:		ListCtrlCommand
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
	ui_netparam_dialog_win(hDlg, (g_ipType[lParam]+HOST_IPADDR), &g_ip[HOST_IPADDR+g_ipType[lParam]], 0);
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
	uint8 i;
	
	for (i = 0; i < IP_MAX; i++)
	{
		storage_set_netparam(0, HOST_IPADDR+i, g_ip[i]);	
	}
	
	// ����ע���
	storage_set_netparam(1, HOST_IPADDR, g_ip[0]);	
	net_set_local_param(storage_get_netparam());
	show_msg(hDlg, IDC_MSG_CTRL, MSG_RIGHT, SID_Save_OK);
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
		case SID_Right_Save:
			save_param(hDlg);
			break;
			
		case BID_Right_Exit:
			close_page();
			break;
	}
}

/*************************************************
  Function:		NetParamCommand
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
  Function:		CreateListCtrl
  Description: 	��ʼ���б�ؼ�
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void CreateListCtrl(HWND hDlg)
{
	g_listCtrl.Parent = hDlg;
	g_listCtrl.Mode = LIST_MODE_COMMON;				// ̧���ͷţ�û�и�����ʾ
	g_listCtrl.Caption = 1;							// �Ƿ��б�����
	#ifdef _USE_ELEVATOR_
	g_listCtrl.Sidebar = 1;							// �����
	#else
	g_listCtrl.Sidebar = 0;							// �����
	#endif
	g_listCtrl.SideBarMode = 1;
	g_listCtrl.KeyCallBack = NULL;
	g_listCtrl.Drawcallback = (SidebarCallBack)draw_Sidebar;// �����
	g_listCtrl.fonttype = Font16X16;				// ������ʾ��С
	#ifdef _TFT_7_
	g_listCtrl.PageCount = 8;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK8_0;
	#else
	g_listCtrl.PageCount = 5;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK5_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK5_0;
	#endif
	g_listCtrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_listCtrl.HeadInfo.TextID = SID_Set_Prj_Net;
	g_listCtrl.Width[0] = 150;
	g_listCtrl.Width[1] = 200;
	
	g_listwin = CreateWindow(AU_LIST_CTRL, "", 
		 		 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				 IDC_LIST_CTRL, 
				 LIST_CTRL_X, LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
				 hDlg, (DWORD)&g_listCtrl);	
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
	uint32 ImageID[5] = {0, 0, BID_Right_Table,0, BID_Right_Exit};
	uint32 TextID[5] = {0, SID_Right_Save, 0, SID_Right_Sure, 0};

	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = 5;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = Font16X16;
	g_rightCtrl.parent = hDlg;
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
  Function:		ui_netparam_win
  Description: 	�����������������
  Input:		
  	1.hDlg
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_netparam_win(HWND hDlg)
{ 
	uint8 i;
	
	for (i = 0; i < IP_MAX; i++)
	{
		g_ip[i] = storage_get_netparam_bytype(HOST_IPADDR+i);
	}

	form_show(&FrmNetParam);
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
			
		case WM_RELOAD:
			OnPaint(hDlg);
			break;

		case MSG_DESTROY:
			break;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

