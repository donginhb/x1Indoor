/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	ui_callout.c
  Author:     	caogw
  Version:    	2.0
  Date: 		2014-10-25
  Description:  
				���н���
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
#include "gui_include.h"
#include "storage_include.h"
#include "logic_include.h"

/************************��������************************/
#define GUI_TIMER_ID            1     		 		// ��ʱ��ID

#ifdef _TFT_7_
#define	HOUSE_ICON_W			40
#define HOUSE_ICON_H			38
#define	HOUSE_ICON_XPOS			(INPUT_CTRL_X-HOUSE_ICON_W-20)
#define HOUSE_ICON_YPOS			(INPUT_CTRL_Y+(INPUT_CTRL_H-HOUSE_ICON_H)/2)
#else
#define HOUSE_ICON_XPOS         70
#define HOUSE_ICON_YPOS         50
#endif
		
/************************��������************************/
static INPUT_INFO g_input;
static KEYBOARD_INFO g_keyboard;
static RIGHTCTRL_INFO g_rightCtrl;
static CALL_STATE_E g_InterState;
static DEVICE_TYPE_E g_DevType;
static char g_DevNo[50];
static char g_CallNo[50];								// ���к���
static HWND g_CallOutWin = 0;
static HWND g_RightWin = 0;
static HWND g_InputWin = 0;
static HWND g_KeybordWin = 0;
static uint8 g_CallType = 0;							// ��������
static uint8 g_MaxNoLen = 0; 				
static uint32 g_HintStrID = 0;							// ��ʾ����ID
static uint32 g_MainStrID = 0;							// ��ʾ������ID
static uint8 g_ExitBtnDown = FALSE;

/************************��������************************/
CREATE_FORM(FrmCall);

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
    if (g_DevType == DEVICE_TYPE_ROOM || g_DevType == DEVICE_TYPE_FENJI_NET)
	{
	    DrawBmpID(hdc, 0, 0, 0, 0, BID_DEFAULT_BK);
	    DrawBmpID(hdc, HOUSE_ICON_XPOS, HOUSE_ICON_YPOS, 0, 0, BID_Inter_CallHouseIcon);	
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
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:			request_callno_addr_callbak
  Description: 		��������ص�����
  Input:			
  	1.param1		
  	2.param2
  Output:			��
  Return:			
  Others:			
*************************************************/
void request_callno_addr_callbak(uint32 param1, uint32 param2)
{
	switch (param1)
	{
		case CALL_STATE_REQUEST:
		{
			char tmp[31] = {0};
			memcpy(tmp, (char *)param2, sizeof(tmp));
			if (tmp[0] == 0)
			{
				//g_HintStrID = SID_Inter_Connecting;
				//SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_HintStrID);
			}
			else
			{
				INTER_INFO_S CallInfo = {0};

				g_HintStrID = SID_Inter_Connecting;
				SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_HintStrID);
				// ��ʾ��Ƶ����
				CallInfo.InterType = INTER_CALLOUT_E;
				CallInfo.DevType = g_CallType;
				if (g_CallType == DEVICE_TYPE_ROOM)
				{
					strcpy(CallInfo.DevStr, tmp+1);
				}
				else
				{
					strcpy(CallInfo.DevStr, g_CallNo);
				}
				ui_becall_win(0, (void*)&CallInfo);
			}
			break;
		}	
		
		case CALL_STATE_END:
		{
			g_InterState = CALL_STATE_NONE;
			if (param2 == END_BY_REQUESET_ERR)		// ����ʧ��
			{
				g_HintStrID = SID_Inter_NoNotFound;
				SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_HintStrID);
				//return;
			}
			// �˳���
			if (g_ExitBtnDown == TRUE)
			{
				g_ExitBtnDown = FALSE;
				close_page();
			}
			break;
		}	
	}
}

/*************************************************
  Function:		check_callno_valid
  Description: 	����������Ϸ���
  Input:			
  	1.CallNo	�������
  Output:		��
  Return:		TRUE / FALSE
  Others:		ֻ�����ȼ��
*************************************************/
static int32 check_callno_valid(char *CallNo)
{
	int8 len;
	
	if (CallNo == NULL)
	{
		return FALSE;
	}
	
	len = strlen(CallNo);
	if (len <= 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*************************************************
  Function:		callout_event_start
  Description: 	��ʼ����
  Input:		
  Output:		��
  Return:		��	
  Others:		��
*************************************************/
static void callout_event_start(void)
{
	int32 ret = 0;
	
	ret = check_callno_valid(g_CallNo);
	if (ret == FALSE)
	{
		g_HintStrID = SID_Inter_WrongNo;
		SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_HintStrID);
	}
	else
	{
		if (g_CallType == DEVICE_TYPE_ROOM)
		{
			ret = inter_call_resident(FALSE, g_CallNo);
		}
		else if (g_CallType == DEVICE_TYPE_FENJI_NET)
		{
			ret = inter_call_sub_terminal(g_CallNo);
		}
		
		if (ret == 0)
		{
			g_HintStrID = SID_Inter_Connecting;
			SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_HintStrID);
			call_out();			// ���������߳�
		}
		else if (ret == 1)
		{
			g_HintStrID = SID_Inter_WrongNo;
			SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_HintStrID);
		}
		else
		{
			log_printf("media is not null\n");
		}
	}
}

/*************************************************
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hWnd, HWND hDlg,LPARAM lParam)
{
	uint32 image = SendMessage(g_RightWin, WM_Right_Get_ImageOrTextID, hWnd, 0);
	switch (image)
	{
	    case BID_Right_Exit:
			// ��������״̬ʱ���˳���Ҫ֪ͨ�����̣߳���Ȼ�ᵼ���˳���Ӧ�ã��߳�û��ִ�и��еĲ���
			if (g_HintStrID == SID_Inter_Connecting)
			{
				g_ExitBtnDown = TRUE;
				inter_hand_down();
			}
			else
			{
				close_page();
			}
			break;
				 
		default:
			break;
    }
}

/*************************************************
  Function:		InputCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void InputCtrlCommand(HWND hWnd, HWND hDlg, LPARAM lParam)
{
	memset(g_CallNo, 0, sizeof(g_CallNo));
    strcpy(g_CallNo,(char *)lParam);
	callout_event_start();
}

/*************************************************
  Function:		OnCommand
  Description: 	�ؼ��¼�������
  Input: 		
	1.id		���صĿؼ�ID
	2.hWnd		�ؼ����
	3.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
static void OnCommand(WPARAM id, HWND hWnd, HWND hDlg,LPARAM lParam)
{
	switch (id)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hWnd, hDlg, lParam);
            break;
			
		case IDC_INPUT_CTRL:
			InputCtrlCommand(hWnd, hDlg, lParam);
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
static uint32 callout_tick_proc(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	static uint8 ticks = 0;
	
	// ���������󡢲��޴˺� ������ʾ��ʾ2s����ʾ���������ʾ���������
	if (g_HintStrID == SID_Inter_WrongNo || g_HintStrID == SID_Inter_NoNotFound )
	{
		if (ticks == 2)
		{
		    g_HintStrID = g_MainStrID;    
			if (g_CallType == DEVICE_TYPE_ROOM)				// ס�����������ʾ��
			{
				SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_MainStrID);		
			}
			else if (g_CallType == DEVICE_TYPE_FENJI_NET)	// ���зֻ����������ʾ��
			{
				SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_MainStrID);
			}
			ticks = 0;
		}
		ticks++;
	}

	return TRUE;
}

/*************************************************
  Function:		Init_Key
  Description: 	
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void Init_Key(void)
{
    if (g_DevType == DEVICE_TYPE_ROOM || g_DevType == DEVICE_TYPE_FENJI_NET)
	{
		add_rightctrl_win(g_RightWin, RIGHT_KEY0, g_KeybordWin, WM_Key_Left, 0, 0);
		add_rightctrl_win(g_RightWin, RIGHT_KEY1, g_KeybordWin, WM_Key_Right, 0, 0);
		add_rightctrl_win(g_RightWin, RIGHT_KEY2, g_KeybordWin, WM_Key_Ok, 0, 0);
		add_rightctrl_win(g_RightWin, RIGHT_KEY3, g_InputWin, WM_Input_Send_Value, 0, 0);	
    }
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
	uint32 ImageID[RIGHT_NUM_MAX] = {BID_Right_Left, BID_Right_Right, 0, 0, BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {0, 0, SID_Right_Input, SID_Right_Call, 0};

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

	Init_Key();
}

/*************************************************
  Function:		CreateInputCtrl
  Description: 	��ʼ���ұ߿ؼ�
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateInputCtrl(HWND hDlg)
{
    memset(&g_input, 0, sizeof(INPUT_INFO));
	g_input.parent = hDlg;
	g_input.mode = INPUT_MODE_CALL;
	
	g_InputWin = CreateWindow(AU_INPUT_CTRL, "", 
				WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				IDC_INPUT_CTRL, 
				INPUT_CTRL_X, INPUT_CTRL_Y,
				INPUT_CTRL_W, INPUT_CTRL_H, 
				hDlg, (DWORD)&g_input);	
}

/*************************************************
  Function:		CreateKeyBord
  Description: 	��ʼ���ұ߿ؼ�
  Input:		
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void CreateKeyBordCtrl(HWND hDlg)
{
   	memset(&g_keyboard, 0, sizeof(KEYBOARD_INFO));
   	g_keyboard.InputNum = 1;
    g_keyboard.InputhDlg[0] = g_InputWin;
	g_keyboard.Max = KEYBORD_NUM_MAX;
	g_keyboard.Mode = KEYBOARD_MODE1;
	
	g_KeybordWin = CreateWindow(NUM_KEYBORD, "", 
				WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				IDC_KEYBOARD_CTRL, 
				KEYBOARD_CTRL_X, KEYBOARD_CTRL_Y,
				KEYBOARD_CTRL_W, KEYBOARD_CTRL_H, 
				hDlg, (DWORD)&g_keyboard);	
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
   	CreateInputCtrl(hDlg);
	CreateKeyBordCtrl(hDlg);
    CreateRightCtrl(hDlg);
}

/*************************************************
  Function:			set_callout_info
  Description: 		���ú�����Ϣ
  Input:			
  	1.DevType		��������
  	2.CallNo		���к���
  Output:			��
  Return:			��
  Others:		
*************************************************/
static uint32 set_callout_info(DEVICE_TYPE_E DevType, char *CallNo)
{
	PFULL_DEVICE_NO pDevParam = storage_get_devparam();
	g_CallType = DevType;
	memset(g_CallNo, 0, sizeof(g_CallNo));
	
	if (g_CallType == DEVICE_TYPE_ROOM)				// ����ס������������ֵ
	{
		g_MaxNoLen = pDevParam->DevNoLen - 1;
		g_MainStrID = SID_Inter_EnterUserNo;
		SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_MainStrID);
		SendMessage(g_InputWin, WM_Input_Set_Textlen, 0, g_MaxNoLen);		
	}
	else if (g_CallType == DEVICE_TYPE_FENJI_NET)	// ���зֻ�����������ֵ
	{
		g_MaxNoLen = 1;
		g_MainStrID = SID_Inter_EnterFJNo;	
		SendMessage(g_InputWin, WM_Input_Set_TextID, 0, g_MainStrID);
		SendMessage(g_InputWin, WM_Input_Set_Textlen, 0,g_MaxNoLen);
	}
	
	g_InterState = CALL_STATE_NONE;
	g_ExitBtnDown = FALSE;
	g_HintStrID = 0;
	
    return TRUE;
}

/*************************************************
  Function:		ui_callout_win
  Description: 	���н���
  Input:			
  	1.hDlg		���ھ��
  	2.wParam    ����1
  	3.lParam    ����2
  Output:		��
  Return:		��	
  Others:		
*************************************************/
static uint32 ui_callout_win(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	g_CallOutWin = hDlg;
    create_ctrls(hDlg);	
	
	return TRUE;
}

/*************************************************
  Function:		ui_callout_appstart
  Description: 	��������Ӧ��
  Input:			
  	1.OperType	�����豸����
  	2.CallNo	���к���
  Output:		��
  Return:		��	
  Others:		
*************************************************/
void ui_callout_appstart(DEVICE_TYPE_E DevType, char * DevNo)
{
	INTER_INFO_S CallInfo = {0};
	
	int32 ret = ui_show_win_arbitration(0, SYS_OPER_CALLOUT);
	if (ret == TRUE)
	{
		PGUI_FORM frm;
		frm = get_cur_form();
		if (FrmMain.hWnd != frm->hWnd)
		{
			back_main_page();
		}
		
		g_DevType = DevType;
		memset(g_DevNo, 0, sizeof(g_DevNo));
		
		CallInfo.InterType = INTER_CALLOUT_E;
		CallInfo.DevType = DevType;
		if (DevNo)
		{
			strcpy(CallInfo.DevStr, DevNo);
		}
		
		// �жϹ���Ա���Ƿ����� 
		if (DevType == DEVICE_TYPE_MANAGER)
		{
			PGUI_FORM frm = get_cur_form();
			uint8 ManagerIndex = 0;
			uint8 managernum = 0;
			
			managernum = atoi(DevNo) - MANAGER_NUM;
			if (1 == managernum)
			{
				ManagerIndex = 1;
			}
			else if (2 == managernum)
			{
				ManagerIndex = 2;
			}
			else if (3 == managernum)
			{
				ManagerIndex = 3;
			}

			#ifdef _USE_NEW_CENTER_
			// ���ж��Ƿ����Ա��IP��δ����
			if (net_get_manager_ip(1) == 0 &&
				net_get_manager_ip(2) == 0 &&
				net_get_manager_ip(3) == 0)
			{	
				uint8 EchoValue, ret1, i;
				uint16 ReciSize;
				char RecData[200];				
				uint32 CenterIp = net_get_center_ip();

				for (i=0; i<MANAGER_COUNTS_MAX; i++)
				{
					g_Manager_IP[i] = 0;
				}
				set_nethead(G_CENTER_DEVNO, PRIRY_DEFAULT);
				ret1 = net_send_command(CMD_GET_MANAGER_IP, NULL, 0, CenterIp, NETCMD_UDP_PORT, 2, &EchoValue, RecData, &ReciSize);
				if (ret1 == TRUE)
				{
					if (EchoValue == ECHO_OK && ReciSize == 8)
					{
						g_Manager_IP[0] = *(uint32 *)RecData;
						log_printf("g_Manager_IP: %x\n ", g_Manager_IP[0]);
					}
					else
					{
						ret	= FALSE;
						log_printf(" recv data is wrong!!!!\n ");
					}
				}
				else
				{
					log_printf(" can not get manager list !!!! \n");
					ret	= FALSE;
				}

			}
			else if (net_get_manager_ip(ManagerIndex) == 0)
			{
				log_printf("ui_callout_appstart : manager %d is not set\n", ManagerIndex);
				ret	= FALSE;
			}

			if (ret	== FALSE)
			{
				show_msg(frm->hWnd, IDC_Msg_Notice, MSG_INFORMATION, SID_Inter_ManagerNoSet);
				return;
			}
			else
			{
				ui_becall_win(0, (void *)&CallInfo);
				inter_call_manager(CallInfo.DevStr);
				call_out();							// ���������߳�
			}
			#else
			if (net_get_manager_ip(ManagerIndex) == 0)
			{
				show_msg(frm->hWnd, IDC_Msg_Notice, MSG_INFORMATION, SID_Inter_ManagerNoSet);
				return;
			}
			else
			{
				ui_becall_win(0, (void *)&CallInfo);
				inter_call_manager(CallInfo.DevStr);
				call_out();							// ���������߳�
			}
			#endif
		}
		else
		{
        	form_show(&FrmCall);
		}
	}
	else
	{
		SendMessage(FrmBeCall.hWnd, WM_CENTER_HANDUP, 0, 0);
	}
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
			ui_callout_win(hDlg, wParam, lParam);
			break;
		
		case MSG_INITDIALOG:
			SetWindowBkColor(hDlg, PAGE_BK_COLOR);
			//SetTimer(hDlg, GUI_TIMER_ID, 50);
			break;
			
		case MSG_ACTIVE:
			break;

		case MSG_SHOWWINDOW:
			if (wParam == SW_SHOWNORMAL)
			{
				SetTimer(hDlg, GUI_TIMER_ID, 50);
				set_callout_info(g_DevType, NULL);
			}
			else if (wParam == SW_HIDE)
			{
				//SendMessage(g_KeybordWin, WM_Key_Exit, 0, 0);
				//SendMessage(g_InputWin, WM_Input_Clear, 0, 0);
				close_page();
			}
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			break;
			
       	#ifdef _ENABLE_TOUCH_
		case MSG_LBUTTONDOWN:
    		get_key_down(hDlg, LOWORD(lParam), HIWORD(lParam));
   			break;
   			
	    case MSG_LBUTTONUP:
	        get_key_up(hDlg, LOWORD(lParam), HIWORD(lParam));
	        break;
        #endif
		
	    case MSG_KEYDOWN:
			SendMessage(g_RightWin, MSG_KEYDOWN, wParam, lParam);
        	break;

		case MSG_KEYUP:
			SendMessage(g_RightWin, MSG_KEYUP, wParam, lParam);
			break;
			
		case MSG_COMMAND:
			if (g_InputWin == wParam)
			{
				wParam = IDC_INPUT_CTRL;
			}
			OnCommand(wParam, (HWND)lParam, hDlg, lParam);
			break;
			
		case MSG_TIMER:	
			callout_tick_proc(hDlg, wParam, lParam);
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
			return 0;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}

