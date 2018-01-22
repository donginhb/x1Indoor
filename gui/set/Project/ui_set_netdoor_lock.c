/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_set_lockstyle.c
  Author:   	caogw
  Version:   	2.0
  Date: 		15-06-24
  Description:  
  				���������ý���
  History:                 
*********************************************************/
#include "gui_include.h"
#include "storage_include.h"

/************************��������************************/
#define GUI_TIMER_ID            10

/************************��������************************/
static HWND g_rightwin;
static HWND g_listwin;
static RIGHTCTRL_INFO  g_rightCtrl;
static LISTCTRL_INFO	g_listCtrl;
static uint8 g_state;					// 0:����  1:����
static int32 g_locktime = 1;			// ʱ��
static uint8 netdoorflag = 0;           //����������ǰ�������־λ

/************************��������************************/
CREATE_FORM(FrmSetnetdoorlock);

/*************************************************
  Function:     on_timer
  Description:  ��ʱ��ִ�к���
   Input:       
    1.hDlg      ���
  Output:       ��
  Return:       ��
  Others:
*************************************************/
static void on_timer(uint32 wParam)
{
    if(netdoorflag)
    {
    	uint8 i;
        netdoorflag = 0;
        KillTimer(self->hWnd, GUI_TIMER_ID);
        SendMessage(FrmSetnetdoorlock.hWnd, WM_NETDOOR, CMD_NETDOOR_GET_LOCK, 0);
    }
}

/*********************************************************
  Function:			show_win
  Description:	��ʾ������Ϣ
  Input: 		��
  Output:        ��
  Return: 		ture �ɹ�false ʧ��
  Others:                 
*********************************************************/
static void show_win(HWND hDlg)
{
	uint16 temp[30];
	char tmp[30];
	uint32 i,max = 3;
	uint32 len = CHAR_SIZE;
	PLISTITEM_INFO g_info = NULL;
	uint32 textid[3] = {SID_Net_Door_Open, SID_Net_Door_Close, 0};
	
	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info, 0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 2;
			if (i == g_state)
			{
				g_info[i].Item[0].Image = BID_Set_Sel;
			}
			else
			{
				g_info[i].Item[0].Image = 0;
			}

			g_info[i].Item[0].ShowType = STYLE_LEFT;
			g_info[i].Item[1].TextID = textid[i];	

			if (2 == i)
			{
				g_info[i].Icon = BID_ListIcon;
				g_info[i].Item[0].TextID = SID_Net_Door_LTime_Mh;	
				
				memset(tmp,0,sizeof(tmp));
				sprintf(tmp,"%d", g_locktime);
				strcat(g_info[i].Item[1].WText, tmp);
				memset(temp, 0, sizeof(temp));	
				strcpy(temp, get_str(SID_Time_Sec));
				strcat(g_info[i].Item[1].WText, temp);
			}
			g_info[i].Item[1].ShowType = STYLE_LEFT;
		}
	    SendMessage(g_listwin, WM_List_Add_Item,max,(LPARAM)g_info);
		SendMessage(g_listwin, WM_List_Set_Sel, g_state, (LPARAM)g_info);
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
			SendMessage(hDlg, WM_NETDOOR, CMD_NETDOOR_SET_LOCK, 0);
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
			g_state = 0;
			show_win(hDlg);
			break;
			
		case 1:		
			g_state = 1;
			show_win(hDlg);
			break;
			
		case 2:	
			ui_netdoor_lock_dialog_win(hDlg, SID_Net_Door_LockTime, g_locktime);
			break;
	
		default:
			break;
	}
}

/*************************************************
  Function:			OnNetDoorDeal
  Description: 		����������ǰ��
  Input: 		
	1.win:   		��ǰ����Ĵ���
	2.wParam:   
  Output:		
  Return:		
  Others:
*************************************************/
static uint32 OnNetDoorDeal(HWND hDlg ,WPARAM wParam, LPARAM lParam)
{
	uint32 ret = 0;
	switch (wParam)
	{
		case CMD_NETDOOR_GET_LOCK:
            show_msg(hDlg, IDC_SEARCH_LIST, MSG_HIT, SID_Inter_Connecting);
			if  (NETDOOR_ECHO_SUCESS == logic_get_netdevice_lockinfo(&g_state, &g_locktime))
			{
				show_win(hDlg);
			}
			else
			{
				show_msg(hDlg, IDC_MSG_CTRL, MSG_WARNING, SID_Msg_Connect_Outtime);
			}
			break;
			
		case CMD_NETDOOR_SET_LOCK:
			if (NETDOOR_ECHO_SUCESS == logic_set_netdevice_lockinfo(g_state, g_locktime))
			{
				show_msg(hDlg, IDC_MSG_CTRL, MSG_RIGHT, SID_Save_OK);
			}
			else
			{
				show_msg(hDlg, IDC_MSG_CTRL, MSG_WARNING, SID_Save_ERR);
			}
			break;
	}
}

/*************************************************
  Function:			OnNetDoorReload
  Description: 		����������ǰ��
  Input: 		
	1.win:   		��ǰ����Ĵ���
	2.wParam:   
  Output:		
  Return:		
  Others:
*************************************************/
static uint32 OnNetDoorReload(HWND hDlg ,WPARAM wParam, LPARAM lParam)
{
	g_locktime = (uint32)wParam;
	show_win(hDlg);
}

/*************************************************
  Function:		OnCommand
  Description: 	�ؼ��¼�������
  Input: 		
  	1.hDlg		���ھ��
  	2.wParam	�ؼ�ID
  	3.lParam	����
  Output:		��
  Return:		��
  Others:
*************************************************/
static void OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{	
	switch (wParam)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg,lParam);
			break;

		case IDC_LIST_CTRL:
			ListCtrlCommand(hDlg,lParam);
			break;
			
		default:
			break;
	}
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
	g_rightCtrl.TextSize = RIGHT_CTRL_FONT;
	g_rightCtrl.parent = hDlg;
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
	g_listCtrl.Parent = hDlg;
	g_listCtrl.Mode = LIST_MODE_COMMON;				// ̧���ͷţ�û�и�����ʾ
	g_listCtrl.Caption = 1;							// �Ƿ��б�����
	g_listCtrl.SideBarMode = 1;
	g_listCtrl.fonttype = Font16X16;				// ������ʾ��С
	g_listCtrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_listCtrl.HeadInfo.TextID = SID_Net_Door_LockType;
	g_listCtrl.Width[0] = 200;
	g_listCtrl.Width[1] = 100;	

	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	g_listCtrl.Sidebar = 0;							// �����
	g_listCtrl.PageCount = 8;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK8_0;
	#else
	g_listCtrl.Sidebar = 1;							// �����
	g_listCtrl.Drawcallback = (SidebarCallBack)draw_Sidebar;	// �����
	g_listCtrl.PageCount = 6;						// ��ʾ����
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
  Function:		ui_devno_win
  Description: 	���������ͽ���
  Input:		
  	1.hDlg
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_netdoor_lock_win(HWND hDlg)
{ 
	form_show(&FrmSetnetdoorlock);
	g_locktime = 1;
    netdoorflag = 1;
	
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

		case MSG_SHOWWINDOW:
			if(wParam == SW_SHOWNORMAL)
			{
				if (netdoorflag)
            	{
	                // ����һ�����Ϊ NETDOOR_TIME*10 MS�Ķ�ʱ��
	                SetTimer(hDlg, GUI_TIMER_ID, NETDOOR_TIME);
            	}
			}
			if (wParam == SW_HIDE)
			{
				close_page();
			}
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			break;

		case MSG_ACTIVE:
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
            on_timer(wParam);
			break;	
			
		case MSG_CLOSE:
			DestroyMainWindow(hDlg);
			PostQuitMessage(hDlg);
			return  0;

		case WM_NETDOOR:
			OnNetDoorDeal(hDlg ,wParam,lParam);			
			break;

		case WM_RELOAD:
			OnNetDoorReload(hDlg ,wParam, lParam);
			break;
			
		case MSG_DESTROY:
			break;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

