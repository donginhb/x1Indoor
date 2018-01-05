/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_lyly.c
  Author:   	caogw
  Version:   	2.0
  Date: 		14-12-11
  Description:  
  				��Ӱ���Խ���
  History:     
  	1. Date:	
		   Author:	
		   Modification:
*********************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

/************************��������************************/
static HWND g_RighthDlg = -1;
static HWND g_ListhDlg = -1;
static RIGHTCTRL_INFO g_rightCtrl;					// �ұ߿ؼ���Ϣ
static LISTCTRL_INFO g_ListCtrl;					// �б�ؼ���Ϣ
static PLYLYLIST_INFO g_LylyList = NULL;
static int32 g_ListIndex = -1;
static uint32 g_RightIndex = 0;

/************************��������************************/
CREATE_FORM(FrmLyLy);

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
	uint32 i,max = 0;
	PLISTITEM_INFO g_info = NULL;
	//char temp[80];
	//char tmp[40];
	int nlen = 0;
	
	g_ListIndex = -1;
	SendMessage(g_ListhDlg, WM_List_Clear_Item, 0, 0);
	if (g_LylyList)
	{
		storage_free_lyly_memory(&g_LylyList);	
		g_LylyList = NULL;
	}
	storage_get_lylyrecord(&g_LylyList);
	if (NULL == g_LylyList || g_LylyList->Count == 0)
	{
		return;
	}
	max = g_LylyList->Count;
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info,0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 3;
			g_info[i].Icon = 0;
			g_info[i].Item[0].Change = FALSE;
			if (g_LylyList->LylyInfo[i].UnRead)
			{
				g_info[i].Item[0].Image = BID_LyLy_UnRead;
			}
			else
			{
				g_info[i].Item[0].Image = BID_LyLy_Read;
			}
			g_info[i].Item[0].ShowType = STYLE_LEFT;
			
			nlen = CHAR_SIZE;
			get_dev_description(g_LylyList->LylyInfo[i].DevType, g_LylyList->LylyInfo[i].DevNo, g_info[i].Item[1].Text, nlen);	
			sprintf(g_info[i].Item[2].Text,"%04d-%02d-%02d %02d:%02d:%02d",g_LylyList->LylyInfo[i].Time.year,g_LylyList->LylyInfo[i].Time.month,g_LylyList->LylyInfo[i].Time.day
				,g_LylyList->LylyInfo[i].Time.hour,g_LylyList->LylyInfo[i].Time.min,g_LylyList->LylyInfo[i].Time.sec);
			g_info[i].Item[2].ShowType = STYLE_LEFT;
			#if 0
			g_info[i].Item[3].Change = FALSE;
			if (g_LylyList->LylyInfo[i].UnRead)
			{
				g_info[i].Item[3].Image = BID_Message_UnRead;
			}
			g_info[i].Item[3].ShowType = STYLE_LEFT;
			#endif
		}
		SendMessage(g_ListhDlg, WM_List_Add_Item, max, (LPARAM)g_info);
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
	#if 0
	HDC hdc;
	RECT rc;
	
	hdc = BeginPaint(hDlg);
	GetClientRect(hDlg, &rc);  	
	SetBkMode(hdc, BM_TRANSPARENT);
	SetBrushColor(hdc, PAGE_BK_COLOR);
	FillBox(hdc, rc.left, rc.top, rc.right, rc.bottom);
	show_win(hDlg);
	EndPaint(hDlg, hdc);
	#endif
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
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Right_Clear, SID_Right_Del, 0, SID_Right_View, 0};
	change_rightctrl_allimagetext(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), ImageID, TextID);
}

/*************************************************
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		
  	1.hDlg		���ھ��
	2.index		�б�Ԫ������
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM index)
{
	uint32 Image = 0;

	g_ListIndex = SendMessage(GetDlgItem(hDlg, IDC_LIST_CTRL), WM_List_Get_Sel, index, 0);
	g_RightIndex = SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Get_ImageOrTextID, index, 0);
	Image = g_RightIndex;
	switch (Image)
	{
		case SID_Right_View:
			if (NULL != g_LylyList && g_LylyList->Count > 0 && g_ListIndex < g_LylyList->Count && g_ListIndex != -1)
			{
				storage_free_lyly_memory(&g_LylyList);	
				storage_get_lylyrecord(&g_LylyList);
				ui_lyly_view(hDlg, g_ListIndex, g_LylyList);
			}	
			break;
			
		case SID_Right_Del:
			if (NULL != g_LylyList && g_LylyList->Count > 0 && g_ListIndex < g_LylyList->Count && g_ListIndex != -1)
			{
				start_change_rightkey(hDlg);
				show_msg(hDlg, IDC_MSG_CTRL, MSG_QUERY, SID_Bj_Query_Del_Rec_One);
			}
			break;
			
		case SID_Right_Clear:
			if (NULL != g_LylyList && g_LylyList->Count > 0 && g_ListIndex < g_LylyList->Count && g_ListIndex != -1)
			{
				start_change_rightkey(hDlg);
				show_msg(hDlg, IDC_MSG_CTRL, MSG_QUERY, SID_Bj_Query_Del_Rec_All);
			}
			break;
			
		case BID_Right_Exit:
			close_page();
			break;
			
		default:
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
static void MsgCtrlCommand(HWND hDlg, WPARAM event)
{
	ECHO_STORAGE ret = ECHO_STORAGE_ERR;

	if (MSG_EVENT_YES == event)
	{
		switch(g_RightIndex)
		{
			// ɾ��������Ӱ����
			case SID_Right_Del:
				g_ListIndex = SendMessage(g_ListhDlg, WM_List_Get_Sel, 0, 0);
				if (-1 != g_ListIndex && NULL != g_LylyList && g_ListIndex < g_LylyList->Count)
				{
					ret = storage_del_lylyrecord(g_ListIndex);
					if (ECHO_STORAGE_OK == ret)
					{
						SendMessage(g_ListhDlg, WM_List_Del_Item, g_ListIndex, 0);
						g_LylyList->Count--;
						show_msg(hDlg, IDC_Msg_Notice, MSG_RIGHT, SID_Oper_OK);
					}
					else
					{
						show_msg(hDlg, IDC_Msg_Notice, MSG_INFORMATION, SID_Oper_ERR);
					}
				}
				break;

			// �����Ӱ����
			case SID_Right_Clear:
				if (NULL != g_LylyList && g_LylyList->Count)
				{
					ret = storage_clear_lylyrecord();
					if (ECHO_STORAGE_OK == ret)
					{
						g_ListIndex = -1;
						if (NULL != g_LylyList)
						{
							free(g_LylyList);
							g_LylyList = NULL;
						}
						show_msg(hDlg, IDC_Msg_Notice, MSG_RIGHT, SID_Oper_OK);
						show_win(hDlg);
					}
					else
					{
						show_msg(hDlg, IDC_Msg_Notice, MSG_INFORMATION, SID_Oper_ERR);
					}	
				}
				break;
		}
		sys_sync_hint_state();
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
static void OnCommand(HWND hDlg, WPARAM id, LPARAM index)
{	
	switch (id)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg, index);
			break;

		case IDC_LIST_CTRL:
			g_ListIndex = index;
			break;

		case IDC_MSG_CTRL:
			MsgCtrlCommand(hDlg, index);
			break;
			
		case IDC_FORM:
			show_win(hDlg);
			break;

		default:
			break;
	}
}

/*************************************************
  Function:		Init_Key
  Description: 	��ʼ���б��ؼ���Ӧ�ұ߿ؼ���Ϣ
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void Init_Key(HWND hDlg)
{
	add_rightctrl_win(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), RIGHT_KEY2, GetDlgItem(hDlg, IDC_LIST_CTRL), WM_List_Go_NextSel, 0, 0);
}

/*************************************************
  Function:		CreateListCtrl
  Description: 	�����б��ؼ�
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateListCtrl(HWND hDlg)
{
	memset(&g_ListCtrl, 0, sizeof(LISTCTRL_INFO));
	g_ListCtrl.Mode = LIST_MODE_LIGHT;				// ̧���ͷţ�û�и�����ʾ
	g_ListCtrl.Caption = 1;							// �Ƿ��б�����
	g_ListCtrl.PageCount = 5;						// ��ʾ����
	g_ListCtrl.SideBarMode = 1;
	g_ListCtrl.KeyCallBack = (SidebarKeyCallBack)get_Sidebar_key;
	
	#ifdef _E81S_UI_STYLE_
	g_ListCtrl.Sidebar = 0;							// �����
	#else
	g_ListCtrl.Sidebar = 1;							// �����
	g_ListCtrl.Drawcallback = (SidebarCallBack)draw_Sidebar;	// �����
	#endif
	g_ListCtrl.fonttype = Font16X16;				// ������ʾ��С
	g_ListCtrl.ImageTopBk = BID_ListCtrl_TopBK5_0;
	g_ListCtrl.ImageBk = BID_ListCtrl_BK5_0;
	g_ListCtrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_ListCtrl.HeadInfo.TextID = SID_Media_Lyly;
	#ifdef _TFT_7_
	g_ListCtrl.Width[0] = 40;
	g_ListCtrl.Width[1] = 200;
	g_ListCtrl.Width[2] = 200;
	//g_ListCtrl.Width[3] = 100;
	#else
	g_ListCtrl.Width[0] = 32;
	g_ListCtrl.Width[1] = 135;
	g_ListCtrl.Width[2] = 135;
	//g_ListCtrl.Width[3] = 33;
	#endif
	g_ListhDlg = CreateWindow(AU_LIST_CTRL, "", 
				WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				IDC_LIST_CTRL, 
				LIST_CTRL_X, LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
				hDlg, (DWORD)&g_ListCtrl);
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
	uint32 ImageID[RIGHT_NUM_MAX] = { 0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Right_Clear, SID_Right_Del, 0, SID_Right_View, 0};

	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = Font16X16;
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
	
	Init_Key(hDlg);
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
  Function:		PhotoDestroyProc
  Description: 	���ٴ�����
  Input:		
  	1.win
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void LylyDestroyProc(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if (g_LylyList)
	{
		if (g_LylyList->LylyInfo)
		{
			free(g_LylyList->LylyInfo);
			g_LylyList->LylyInfo = NULL;
		}
		free(g_LylyList);
		g_LylyList = NULL;
	}
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
			if (wParam == SW_SHOWNORMAL)
			{	
				show_win(FrmLyLy.hWnd);
			}
			else if (wParam == SW_HIDE)
			{
				close_page();
			}
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			break;

		case MSG_ERASEBKGND:
			break;

		#ifdef _ENABLE_TOUCH_
		case MSG_LBUTTONDOWN:
			#if 0
			if (GetCapture() == hDlg)
			{
				break;
			}
			SetCapture(hDlg);
			#endif
    		get_touch_down(hDlg, LOWORD(lParam), HIWORD(lParam));
   			break;
   			
	    case MSG_LBUTTONUP:
			#if 0
	    	if (GetCapture() != hDlg)
			{
				break;
			}
			ReleaseCapture();
			#endif
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
			break;	

		case WM_Change_RightKey:
			finish_change_rightkey(hDlg);
			break;
			
		case MSG_CLOSE:
			DestroyMainWindow(hDlg);
			PostQuitMessage(hDlg);
			return 0;
		
		case MSG_DESTROY:
			LylyDestroyProc(hDlg, wParam, lParam);
			return 0;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

