/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_set_alarm_time.c
  Author:   	yanjl
  Version:   	1.0
  Date: 		14-10-09
  Description:  
  				����ʱ���������
  History:            
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

static HDLG g_rightwin = 0;
static HDLG g_listwin = 0;
static HDLG g_upperwin = 0;							// ��һ������

static RIGHTCTRL_INFO g_rightCtrl;					// �ұ߿ؼ���Ϣ
static LISTCTRL_INFO  g_listctrl;	

static uint8 g_time_type = 0;
static uint32 g_time = 0;
 
CREATE_FORM(FrmAlarmTime);

/*************************************************
  Function:		show_win
  Description: 	��ʾ�ľ�����Ϣ
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void show_win(HWND hDlg)
{
	uint32 i,max = 5;
	PLISTITEM_INFO g_info = NULL;
	uint16 alarm_id[5] = { SID_Bj_1Minute, SID_Bj_3Minutes, SID_Bj_5Minutes, SID_Bj_10Minutes, SID_Bj_15Minutes};
	uint16 exit_time_id[6] = {SID_Bj_30Seconds, SID_Bj_1Minute, SID_Bj_2Minutes, SID_Bj_3Minutes,SID_Bj_5Minutes};
	uint16 delay_time_id[5] = {SID_Bj_None, SID_Bj_30Seconds, SID_Bj_1Minute, SID_Bj_2Minutes, SID_Bj_5Minutes};

	uint16 *time_type = NULL;
	switch (g_time_type)
	{
		case 0:
			time_type = alarm_id;
			break;
		case 1:
			time_type = exit_time_id;
			max = 5;
			break;
		case 2:
			time_type = delay_time_id;
			break;
	}
	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info,0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 2;
			if (i == g_time)
			{
				g_info[i].Item[0].Image = BID_Set_Sel;
			}
			else
			{
				g_info[i].Item[0].Image = 0;
			}
			g_info[i].Item[0].ShowType = STYLE_LEFT;
			g_info[i].Item[1].TextID = time_type[i];			
			g_info[i].Item[1].ShowType = STYLE_CENTER;
		}
		SendMessage(g_listwin, WM_List_Add_Item, max, (LPARAM)g_info);
		SendMessage(g_listwin, WM_List_Set_Sel,g_time, (LPARAM)g_info);
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
	SetBrushColor(hdc, PAGE_BK_COLOR);
	FillBox(hdc, rc.left, rc.top, rc.right, rc.bottom);
	show_win(hdc);
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		CreateListCtrl
  Description: 	��ʼ���б�ؼ�
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateListCtrl(HWND hDlg)
{
	g_listctrl.Parent = hDlg;
	g_listctrl.Mode = LIST_MODE_COMMON;				// ̧���ͷţ�û�и�����ʾ
	g_listctrl.Caption = 1;							// �Ƿ��б�����
	g_listctrl.Sidebar = 0;							// �����
	g_listctrl.SideBarMode = 1;
	g_listctrl.Drawcallback = NULL;					// �����
	g_listctrl.fonttype = Font16X16;				// ������ʾ��С
	g_listctrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_listctrl.Width[0] = 70;
	g_listctrl.Width[1] = 200;

	// 0:����ʱ�䣬1���˳�Ԥ��ʱ�� 2:������ʱ
	switch (g_time_type)
	{
		case 0:
			g_listctrl.HeadInfo.TextID = SID_Bj_Alarm_Time;
			break;
		case 1:
			g_listctrl.HeadInfo.TextID = SID_Bj_Early_Warning_Time;
			break;
		case 2:
			g_listctrl.HeadInfo.TextID = SID_Bj_Alarm_Delay;
			break;
	}
	
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	g_listctrl.PageCount = 8;						// ��ʾ����
	g_listctrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listctrl.ImageBk = BID_ListCtrl_BK8_0;
	#else
	g_listctrl.PageCount = 5;						// ��ʾ����
	g_listctrl.ImageTopBk = BID_ListCtrl_TopBK5_0;
	g_listctrl.ImageBk = BID_ListCtrl_BK5_0;
	#endif
	
	g_listwin = CreateWindow(AU_LIST_CTRL, "", 
		 		 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				 IDC_LIST_CTRL, 
				 LIST_CTRL_X,LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
				 hDlg, (DWORD)&g_listctrl);	

	SendMessage(g_listwin, WM_List_SetKeyMode, 1, 0);
}
/*************************************************
  Function:		Init_Key
  Description: 	
  Input:		��
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
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateRightCtrl(HWND hDlg)
{
	uint32 i;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Sure, 0};

	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = Font16X16;
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
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		
  	1.hDlg		���ھ��
  	2.lParam	�ؼ�����
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	uint32 StrID;
	StrID = SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Get_ImageOrTextID, lParam, 0);
	
	switch (StrID)
	{
		case SID_Right_Sure:
			SendMessage(g_upperwin , MSG_COMMAND, FrmAlarmTime.hWnd, (LPARAM)&g_time);
			close_page();
			break;
			
		case BID_Right_Exit:	
			close_page();
			break;
			
		default:
			break;
	}
}

/*************************************************
  Function:		ListViewCommand
  Description: 	�б�ؼ����µĴ�����
  Input:		
  	1.hDlg		���ھ��
  	2.lParam	�б�Ԫ������	
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void ListCtrlCommand(HWND hDlg, LPARAM lParam)
{
	set_list_Image(g_listwin, g_time, 0, 0,CHECK_IMAGE);
	set_list_Image(g_listwin, lParam, 0, BID_Set_Sel,CHECK_IMAGE);
	g_time = lParam;
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
  Function:		SetAlarmPara
  Description: 	�������ò���������
  Input: 		
	1.hDlg   	��ǰ����Ĵ���
	2.tpye      0:����ʱ�䣬1���˳�Ԥ��ʱ�� 2:������ʱ
  Output:		
  Return:		
  Others:
*************************************************/
uint32 SetAlarmTime(HWND hDlg, uint8 type, uint8 time)
{
	g_upperwin = hDlg;
	g_time_type = type;
	g_time = time;
	
	form_show(&FrmAlarmTime);
	
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

