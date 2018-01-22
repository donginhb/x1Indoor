/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_set_alarm_single_attr.c
  Author:   	yanjl
  Version:   	1.0
  Date: 		14-11-13
  Description:  
  				�������÷������Ե�����
  History:            
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

typedef enum										// �������ý���ѡ��
{
	ATTR_ENABLE = 0,
	ATTR_AREA_TYPE,
	ATTR_PART_VALID,
	ATTR_24H,
	ATTR_FINDER,
	ATTR_DELAY,
	ATTR_PICTURE,
	ATTR_VOICE,
	MAX_LIST_NUM
}ATTR_ITEM_TYPE_E;

static HDLG g_rightwin = 0;
static HDLG g_listwin = 0;
static HWND g_upperwin = 0;

static RIGHTCTRL_INFO g_rightCtrl;					// �ұ߿ؼ���Ϣ
static LISTCTRL_INFO  g_listCtrl;	

static AF_FLASH_DATA g_ui_secu_data;
static uint8  g_area_num =	0;						//ȡֵ��0-7			      

CREATE_FORM(FrmAlarmSingleAttr);

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
	uint32 i,max = 8;
	uint8 enable = 0;
	PLISTITEM_INFO g_info = NULL;
	uint16	first_col_str[] = {0, SID_Bj_Tantou_Type, 0, 0, 0, SID_Bj_Alarm_Delay, 0, 0};	
	uint16 delay_time_type[] =  {SID_Bj_None, SID_Bj_30Seconds, SID_Bj_1Minute, SID_Bj_2Minutes,SID_Bj_5Minutes};
	uint16 secondColStr[MAX_LIST_NUM];
	uint8 attr_val[MAX_LIST_NUM];
	uint16  image_id[2] = {BID_Com_UnChose, BID_Com_Chose};

	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);
	SendMessage(g_listwin, WM_List_Set_HeadText, SID_Bj_Fangqu1+ g_area_num, 0);
	
	attr_val[0] = (g_ui_secu_data.enable>>(g_area_num))&0x01;
	attr_val[1] = g_ui_secu_data.area_type[g_area_num];
	attr_val[2] = (g_ui_secu_data.part_valid>>(g_area_num))&0x01;
	attr_val[3] = (g_ui_secu_data.is_24_hour>>(g_area_num))&0x01;
	attr_val[4] = (g_ui_secu_data.finder_state>>(g_area_num))&0x01;
	attr_val[5] = g_ui_secu_data.delay_time[g_area_num];
	attr_val[6] = (g_ui_secu_data.can_see>>(g_area_num))&0x01;
	attr_val[7] = (g_ui_secu_data.can_hear>>(g_area_num))&0x01;

	secondColStr[0] = SID_Bj_Enable;
	secondColStr[1] = SID_Bj_SOS+g_ui_secu_data.area_type[g_area_num];
	secondColStr[2] = SID_Set_Alarm_AfJuFang;
	secondColStr[3] = SID_Bj_24Hour_Fangqu;
 	secondColStr[4] = SID_Bj_Normally_Open;
	secondColStr[5] = delay_time_type[g_ui_secu_data.delay_time[g_area_num]];
    secondColStr[6] = SID_Bj_Picture;
	secondColStr[7] = SID_Bj_Voice;
	 
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info,0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 2;
			if (0 != first_col_str[i])
			{
				g_info[i].Item[0].TextID = first_col_str[i];
				g_info[i].Icon = BID_ListIcon;
			}
			else
			{
				g_info[i].Item[0].Image = image_id[attr_val[i]];
			}
			g_info[i].Item[1].TextID = secondColStr[i];

			g_info[i].Item[0].ShowType = STYLE_LEFT;
			g_info[i].Item[1].ShowType = STYLE_LEFT;
		}
		SendMessage(g_listwin, WM_List_Add_Item, max, (LPARAM)g_info);
	
		free(g_info);
		g_info = NULL;
		if (0 == g_area_num)
		{
			enable = 0;
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_AREA_TYPE, (LPARAM)&enable);				
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_PART_VALID, (LPARAM)&enable);				
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_DELAY, (LPARAM)&enable);
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_24H, (LPARAM)&enable);
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_PICTURE, (LPARAM)&enable);
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_VOICE, (LPARAM)&enable);

			set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_Chose_Unenable, CHECK_IMAGE);
			set_list_Image(g_listwin, (ATTR_24H), 0, BID_Com_Chose_Unenable, CHECK_IMAGE);
			set_list_Image(g_listwin, (ATTR_PICTURE), 0, BID_Com_UnChose_Unenable, CHECK_IMAGE);
			set_list_Image(g_listwin, (ATTR_VOICE), 0, BID_Com_UnChose_Unenable, CHECK_IMAGE);
		}
		else if(1 == ((g_ui_secu_data.is_24_hour>>g_area_num)&0x01))
		{
			enable = 0;
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_PART_VALID, (LPARAM)&enable);				
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_DELAY, (LPARAM)&enable);
			set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_Chose_Unenable, CHECK_IMAGE);
		}
		else
		{	
			enable = 1;
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_PART_VALID, (LPARAM)&enable);				
			SendMessage(g_listwin, WM_List_Set_Enable, ATTR_DELAY, (LPARAM)&enable);	
			if(0 == ((g_ui_secu_data.part_valid>>(g_area_num))&0x01))
			{
				set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_Chose, CHECK_IMAGE);
			}
		}
	}
	#if 0
	 if (URGENCY_ALARM == g_ui_secu_data.area_type[g_area_num-1])
	 {
	 	info.ItemGray[ATTR_24H] = 1;
		info.ItemGray[ATTR_PART_VALID] = 1;		// �ַ����Ի�
		info.ItemGray[ATTR_DELAY] = 1;			// ������ʱ�Ի�
		info.ItemGray[ATTR_VOICE] = 1;			// ����
	 }
	 else if (1 == (g_ui_secu_data.is_24_hour>>(g_area_num-1))&0x01)
	 {
		info.ItemGray[ATTR_PART_VALID] = 1;		// �ַ����Ի�
		info.ItemGray[ATTR_DELAY] = 1;			// ������ʱ�Ի�
	 }
	 #endif
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
	//SetBkMode(hdc, BM_TRANSPARENT);
	//SetBrushColor(hdc, PAGE_BK_COLOR);
	//FillBox(hdc, rc.left, rc.top, rc.right, rc.bottom);
	show_win(hdc);
	EndPaint(hDlg, hdc);
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

	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	g_listCtrl.Sidebar = 0;										// �����
	#else
	g_listCtrl.Sidebar = 1;										// �����
	g_listCtrl.Drawcallback = (SidebarCallBack)draw_Sidebar;	// �����
	#endif
	
	#if (_LCD_DPI_ == _LCD_800480_)
	g_listCtrl.PageCount = 8;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK8_0;
	#elif (_LCD_DPI_ == _LCD_1024600_)
	g_listCtrl.PageCount = 8;						// ��ʾ����
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK8_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK8_0;
	#endif
	g_listCtrl.HeadInfo.Image = BID_ListCtrl_Title;
	g_listCtrl.Width[0] = 100;
	g_listCtrl.Width[1] = 200;
	g_listCtrl.HeadInfo.TextID = SID_Bj_Fangqu1+ g_area_num;

	g_listwin = CreateWindow(AU_LIST_CTRL, "", 
				 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				 IDC_LIST_CTRL, 
				 LIST_CTRL_X, LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
				 hDlg, (DWORD)&g_listCtrl);	
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
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void CreateRightCtrl(HWND hDlg)
{
	uint32 i;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0,BID_Right_Table ,0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, SID_Right_Save, 0, SID_Right_Sure, 0};

	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
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
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		
  	1.win		���ھ��
	2.lParam		�б�Ԫ������
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	uint32 id = 0;
	id = SendMessage(g_rightwin, WM_Right_Get_ImageOrTextID, lParam, 0);
	
	switch (id)
	{
		case SID_Right_Save:
			logic_set_alarm_param((uint8*)(&g_ui_secu_data));
			//WindowInvalidateWindow(win);
			show_msg(hDlg, IDC_MSG_CTRL, MSG_RIGHT, SID_Save_OK);
			hw_get_zone_status();	
			break;
			
		case BID_Right_Exit:
			close_page();
			SetAlarmAreaList(FrmAlarmWholeAttr.hWnd, 3);
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
	uint8 enable = 0;
	
	switch(lParam)
	{
		case ATTR_ENABLE: 							//�Ƿ�����
			if(1 == ((g_ui_secu_data.enable>>(g_area_num))&0x01))
			{
				SET_ONE_VALUE(g_ui_secu_data.enable, 0, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				SET_ONE_VALUE(g_ui_secu_data.enable, 1, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_Chose, CHECK_IMAGE);
			}
			return;
			
		case ATTR_PART_VALID: 						//�ַ���Ч
			if(1 == ((g_ui_secu_data.part_valid>>(g_area_num))&0x01))
			{
				SET_ONE_VALUE(g_ui_secu_data.part_valid, 0, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				SET_ONE_VALUE(g_ui_secu_data.part_valid, 1, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_Chose, CHECK_IMAGE);
			}
			return;
			
		case ATTR_24H:								//�Ƿ�24Сʱ����
			if(1 == ((g_ui_secu_data.is_24_hour>>(g_area_num))&0x01))
			{
				SET_ONE_VALUE(g_ui_secu_data.is_24_hour, 0, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_UnChose, CHECK_IMAGE);
				enable = 1;
				SendMessage(g_listwin, WM_List_Set_Enable, ATTR_PART_VALID, (LPARAM)&enable);				
				SendMessage(g_listwin, WM_List_Set_Enable, ATTR_DELAY, (LPARAM)&enable);

				if(0 == ((g_ui_secu_data.part_valid>>(g_area_num))&0x01))
				{
					set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_UnChose, CHECK_IMAGE);
				}
				else
				{
					set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_Chose, CHECK_IMAGE);
				}
			}
			else
			{	
				SET_ONE_VALUE(g_ui_secu_data.is_24_hour, 1, (g_area_num));
				g_ui_secu_data.delay_time[g_area_num] = 0;
				SET_ONE_VALUE(g_ui_secu_data.part_valid, 1, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_Chose, CHECK_IMAGE);
				set_list_Image(g_listwin, (ATTR_PART_VALID), 0, BID_Com_Chose_Unenable, CHECK_IMAGE);
				set_list_text(g_listwin, (ATTR_DELAY), 1, SID_Bj_None, NULL,NULL,CHECK_IMAGE);
				enable = 0;
				SendMessage(g_listwin, WM_List_Set_Enable, ATTR_PART_VALID, (LPARAM)&enable);				
				SendMessage(g_listwin, WM_List_Set_Enable, ATTR_DELAY, (LPARAM)&enable);				
			}
			return;
		
		case ATTR_AREA_TYPE:					//̽ͷ����
			SetAlarmAreaList(hDlg, 4);
			break;
			
		case ATTR_FINDER:						//̽ͷ״̬
			if(1 == ((g_ui_secu_data.finder_state>>(g_area_num))&0x01))
			{
				SET_ONE_VALUE(g_ui_secu_data.finder_state, 0, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				SET_ONE_VALUE(g_ui_secu_data.finder_state, 1, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_Chose, CHECK_IMAGE);
			}
			break;
			
		case ATTR_DELAY:						//�����ӳ�
			SetAlarmTime(hDlg,2,g_ui_secu_data.delay_time[g_area_num]);
			break;
			
		case ATTR_PICTURE:						// ����
			if(1 == ((g_ui_secu_data.can_see>>(g_area_num))&0x01))
			{
				SET_ONE_VALUE(g_ui_secu_data.can_see, 0, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				SET_ONE_VALUE(g_ui_secu_data.can_see, 1, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_Chose, CHECK_IMAGE);
			}
			break;
			
		case ATTR_VOICE:					    // �Ƿ�������
			if(1 == ((g_ui_secu_data.can_hear>>(g_area_num))&0x01))
			{
				SET_ONE_VALUE(g_ui_secu_data.can_hear, 0, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_UnChose, CHECK_IMAGE);
			}
			else
			{
				SET_ONE_VALUE(g_ui_secu_data.can_hear, 1, (g_area_num));
				set_list_Image(g_listwin, (lParam), 0, BID_Com_Chose, CHECK_IMAGE);
			}
			break;
	}
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
			RightCtrlCommand(hDlg, lParam);
			break;

		case IDC_LIST_CTRL:
			ListCtrlCommand(hDlg, lParam);
			break;
			
		default:
			if (wParam == FrmAlarmTime.hWnd)
			{
				g_ui_secu_data.delay_time[g_area_num] = *((uint8*)lParam);
				InvalidateRect(hDlg, NULL, true);
			}
			else if (wParam == FrmAlarmAreaList.hWnd)
			{
				g_ui_secu_data.area_type[g_area_num] =  *((uint8*)lParam);
				InvalidateRect(hDlg, NULL, true);
			}
			break;
	}
}

/*************************************************
  Function:		SetAlarmSingleAttr
  Description:	�������õ������Դ���
  Input: 		
	1.hDlg		��ǰ����Ĵ���
	2.num 		������
  Output:		
  Return:		
  Others:
*************************************************/ 
uint32 SetAlarmSingleAttr(HWND hDlg, uint8 num)
{
	logic_get_alarm_param((uint8*)&g_ui_secu_data);
	g_area_num = num;
	g_upperwin = hDlg;
	
	form_show(&FrmAlarmSingleAttr);

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

