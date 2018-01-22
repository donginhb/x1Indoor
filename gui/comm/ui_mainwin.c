/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	mainwin.c
  Author:     	luofl
  Version:    	2.0
  Date: 		2014-08-30
  Description:  
				GUI�����ڴ������
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
#define SYS_GLOBALS

#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

/************************��������************************/
#if (_LCD_DPI_ == _LCD_800480_)
#define NET_W					28
#define NET_H					28
#define NET_XPOS				10
#define NET_YPOS				5
#ifdef _IP_MODULE_
#define IP_NET_DISX				8
#define IPMODULE_W				28
#define IPMODULE_H				28
#endif
#elif (_LCD_DPI_ == _LCD_1024600_)
#define NET_W					36
#define NET_H					36
#define NET_XPOS				13
#define NET_YPOS				7
#ifdef _IP_MODULE_
#define IP_NET_DISX				8
#define IPMODULE_W				36
#define IPMODULE_H				36
#endif
#endif

#if (_LCD_DPI_ == _LCD_800480_)
#elif (_LCD_DPI_ == _LCD_1024600_)
#endif


#ifdef _IP_MODULE_
#define IPMODULE_XPOS			(NET_XPOS + NET_W + IP_NET_DISX)
#define IPMODULE_YPOS			NET_YPOS
#endif

#if (_UI_STYLE_ == _V6_UI_STYLE_)
#if (_LCD_DPI_ == _LCD_800480_)
#define TOP_DISY				30					// ͼ��ඥ���ļ��
#define MAIN_RIGHT_W			160					// �ұ߿ؼ����
#define MAIN_ICON_DISX			90					// ͼ��X����
#define MAIN_ICON_DISY			90					// ͼ��Y����
#define MAIN_ICON_W				88					// ͼ���
#define MAIN_ICON_H				88					// ͼ���
#define ICON_TEXT_DISY      	15 					// ����ͼ����

#define ICON_SEL_DIS			6					// ѡ�п���
#define NEW_HIT_DISX			70					// ���¼���ʾX����
#define NEW_HIT_DISY			10					// ���¼���ʾY����
#elif (_LCD_DPI_ == _LCD_1024600_)
#define TOP_DISY				40					// ͼ��ඥ���ļ��
#define MAIN_RIGHT_W			RIGHT_CTRL_W		// �ұ߿ؼ����
#define MAIN_ICON_DISX			116					// ͼ��X����
#define MAIN_ICON_DISY			116					// ͼ��Y����
#define MAIN_ICON_W				112					// ͼ���
#define MAIN_ICON_H				112					// ͼ���
#define ICON_TEXT_DISY      	19 					// ����ͼ����

#define ICON_SEL_DIS			8					// ѡ�п���
#define NEW_HIT_DISX			88					// ���¼���ʾX����
#define NEW_HIT_DISY			13					// ���¼���ʾY����
#endif

#elif (_UI_STYLE_ == _E81S_UI_STYLE_)
#define TOP_DISY				20					// ͼ��ඥ���ļ��
#define MAIN_RIGHT_W			160					// �ұ߿ؼ����
#define MAIN_ICON_DISX			94					// ͼ��X����
#define MAIN_ICON_DISY			40					// ͼ��Y����
#define MAIN_ICON_W				88					// ͼ���
#define MAIN_ICON_H				88					// ͼ���
#define ICON_TEXT_DISY      	0 					// ����ͼ����

#define ICON_SEL_DIS			2					// ѡ�п���
#define NEW_HIT_DISX			47+13				// ���¼���ʾX����
#define NEW_HIT_DISY			 -8					// ���¼���ʾY����
#define MAIN_NET_W 				30					//����ͼ�������
#endif
#define MAIN_ICON_XPOS			(FORM_W-MAIN_RIGHT_W-MAIN_ICON_DISX*2-MAIN_ICON_W*3)/2	// ͼ��X�����

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
#define MAIN_ICON_YPOS			(FORM_H-TOP_DISY-3*MAIN_ICON_H-2*MAIN_ICON_DISY)/2		// ͼ��Y�����
#else
#define MAIN_ICON_YPOS			(FORM_H-TOP_DISY-2*MAIN_ICON_H-MAIN_ICON_DISY)/2		// ͼ��Y�����
#endif
#define GUI_TIMER_ID			1					// ��ʱ��ID
#define NET_CHECK_TIME			3

#define PAGE_LEVEL				6

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
#define MainIconNum     		9
#define MainCallNum     		2
#else
#define MainIconNum     		6
#define MainCallNum     		3
#endif

#define MainCenterNum     		3
#ifdef _LIVEMEDIA_
#define MainMonitorNum     		4
#else
#define MainMonitorNum     		3
#endif

#ifdef _JRLY_MODE_
#ifdef _DIANTI_CALL_
#define MainBianliNum     		2
#else
#define MainBianliNum     		1
#endif
#else
#ifdef _DIANTI_CALL_
#define MainBianliNum     		1
#else
#define MainBianliNum     		0
#endif
#endif
#define MainMediNum     		2

#ifdef _USE_NEW_CENTER_
#define REG_CENTER_TIME			30
static uint16 g_keeptime = 0;
#endif

#define NET_RC(rc)\
        rc.left = NET_XPOS;\
		rc.top =  NET_YPOS;\
		rc.right = rc.left+NET_W;\
		rc.bottom = rc.top+NET_H
		
#ifdef _IP_MODULE_
#define IPMODULE_RC(rc)\
            rc.left = NET_XPOS;\
            rc.top =  IPMODULE_YPOS;\
            rc.right = rc.left+IPMODULE_W+NET_W+IP_NET_DISX;\
            rc.bottom = rc.top+IPMODULE_H;
#endif

#define TOP_RC(rc)\
        rc.left = 0;\
		rc.top =  0;\
		rc.right = rc.left+640;\
		rc.bottom = rc.top+24

#define MAIN_RC(rc)\
        rc.left = 0;\
		rc.top =  24;\
		rc.right = rc.left+640;\
		rc.bottom = 480


// �������ʼ��
static CTRLDATA Ctrls[] = {};
static DLGTEMPLATE DlgInit =
{ 
	DW_STYLE, 
	DW_STYLE_EX,
	FORM_X, FORM_Y, FORM_W, FORM_H,	
	"",
	0,
	0,
	sizeof(Ctrls)/sizeof(CTRLDATA),
	Ctrls, 
	0 
};

static uint8 g_MaxPage[PAGE_LEVEL] = {
	MainIconNum, MainCallNum, MainCenterNum,
	MainMonitorNum, MainBianliNum, MainMediNum};

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
const uint32 MainIconID[MainIconNum*2] =
{
	BID_Main1Alarm, SID_MainAlarm,
    BID_Main2Call, SID_MainCall,
	BID_Main3Message, SID_MainInfo,
	BID_Main4Center, SID_MainCenter,
    BID_Main5Monitor, SID_MainMonitor,    
	BID_Main7LyLy, SID_MainLyLy,
	BID_Main7_Snap, SID_Media_Snap,
	#ifdef _JRLY_MODE_
	BID_Main8BianLi, SID_MainBianli,	
	#else
	BID_MainControl_DianTi, SID_MainBianLi_Dianti,
	#endif
	BID_Main9Setting, SID_MainSet,
};

const uint32 MainIconID_1[MainIconNum*2] =
{
	BID_Main1Alarm_1, SID_MainAlarm,
    BID_Main2Call_1, SID_MainCall,
	BID_Main3Message_1, SID_MainInfo,
	BID_Main4Center_1, SID_MainCenter,
    BID_Main5Monitor_1, SID_MainMonitor,    
	BID_Main7LyLy_1, SID_MainLyLy,
	BID_Main7_Snap_1, SID_Media_Snap,
	#ifdef _JRLY_MODE_
	BID_Main8BianLi_1, SID_MainBianli,	
	#else
	BID_MainControl_DianTi_1, SID_MainBianLi_Dianti,
	#endif
	BID_Main9Setting_1, SID_MainSet,
};
#else
const uint32 MainIconID[MainIconNum*2] =
{
	BID_Main1Alarm, SID_MainAlarm,
    BID_Main2Call, SID_MainCall,
	BID_Main3Message, SID_MainInfo,
	BID_Main5Monitor, SID_MainMonitor,
    BID_Main7_Media, SID_MainMedia,    
	BID_Main9Setting, SID_MainSet,
};
#endif

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
const uint32 MainCallIconID[MainCallNum*2] = 
{
	BID_MainCall_User, SID_MainCall_User,		
	BID_MainCall_FengJi, SID_MainCall_FengJi,
};

const uint32 MainCallIconID_1[MainCallNum*2] = 
{
	BID_MainCall_User_1, SID_MainCall_User,		
	BID_MainCall_FengJi_1, SID_MainCall_FengJi,
};

#else
const uint32 MainCallIconID[MainCallNum*2] = 
{
	BID_MainCall_User, SID_MainCall_User,		
	BID_MainCall_FengJi, SID_MainCall_FengJi,
	BID_Main4Center, SID_MainCenter,
};
#endif


const uint32 MainCenterIconID[MainCenterNum*2] = 
{
	BID_MainCenter_1, SID_MainCenter_1,
	BID_MainCenter_2, SID_MainCenter_2,	
	BID_MainCenter_3, SID_MainCenter_3,	
};

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
const uint32 MainMonitorIconID_1[MainMonitorNum*2] = 
{
	BID_MainMonitor1_Door_1, SID_MainMonitor_Door,
	BID_MainMonitor2_Stair_1, SID_MainMonitor_Stair,		
	BID_MainMonitor3_Area_1, SID_MainMonitor_Area,
	#ifdef _LIVEMEDIA_
	BID_MainMonitor3_Camera, SID_MainMonitor_Camera,
	#endif
};

const uint32 MainMonitorIconID[MainMonitorNum*2] = 
{
	BID_MainMonitor1_Door, SID_MainMonitor_Door,
	BID_MainMonitor2_Stair, SID_MainMonitor_Stair,		
	BID_MainMonitor3_Area, SID_MainMonitor_Area,
	#ifdef _LIVEMEDIA_
	BID_MainMonitor3_Camera, SID_MainMonitor_Camera,
	#endif
};

#else
const uint32 MainMonitorIconID[MainMonitorNum*2] = 
{
	BID_MainMonitor1_Door, SID_MainMonitor_Door,
	BID_MainMonitor2_Stair, SID_MainMonitor_Stair,		
	BID_MainMonitor3_Area, SID_MainMonitor_Area,
	#ifdef _LIVEMEDIA_
	BID_MainMonitor3_Camera, SID_MainMonitor_Camera,
	#endif
};
#endif

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
const uint32 MainBianliIconID[MainBianliNum*2] = 
{
	#ifdef _JRLY_MODE_
	BID_Main_JRLY, SID_Bl_Jrly,
	#endif
	#ifdef _DIANTI_CALL_
	BID_MainControl_DianTi, SID_MainBianLi_Dianti,  
	#endif		
};

const uint32 MainBianliIconID_1[MainBianliNum*2] = 
{
	#ifdef _JRLY_MODE_
	BID_Main_JRLY_1, SID_Bl_Jrly,
	#endif
	#ifdef _DIANTI_CALL_
	BID_MainControl_DianTi_1, SID_MainBianLi_Dianti,  
	#endif		
};
#else
const uint32 MainBianliIconID[MainBianliNum*2] = 
{
	#ifdef _JRLY_MODE_
	BID_Main_JRLY, SID_Bl_Jrly,
	#endif
	#ifdef _DIANTI_CALL_
	BID_MainControl_DianTi, SID_MainBianLi_Dianti,  
	#endif		
};
#endif

const uint32 MainMediIconID[MainMediNum*2] = 
{
	BID_Main7LyLy, SID_Media_Lyly,
	BID_Main7_Snap, SID_Media_Snap,		
};

/************************��������************************/
GUI_FORM FrmMain;
static PGUI_FORM self = &FrmMain;
static HWND g_RightWin;
static RIGHTCTRL_INFO g_rightCtrl;
static uint8 g_CurPage = 0;
static uint8 g_CurKey = 0;
static uint8 g_OldKey = 0;
static uint8 g_NetCnt = 0;
static uint8 g_NetState = 0;
static uint8 g_UnreadMsgNum = 0;
static uint8 g_UnreadLylyNum = 0;
static uint8 g_IPModuleState = 0; // IPģ��״̬
#ifdef _TEST_REBOOT_
static uint8 reboot_time = 0;
#endif

#ifdef _RTSP_REG_KEEP_
static uint8 g_RtspKeepTime = 0;	// ����ý�屣�ֵ�����ͨѶʱ��
#endif

/************************��������************************/
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
	#if 0
	RECT rc;
	uint8 i, j;
	
	i = index /3;
	j = index %3;
	rc.left = MAIN_ICON_XPOS+j*(MAIN_ICON_W+MAIN_ICON_DIS_X*3/4);
	rc.top = MAIN_ICON_YPOS+i*(MAIN_ICON_H+MAIN_ICON_DIS_Y+FONT_16);
	rc.right = rc.left+(MAIN_ICON_W+MAIN_ICON_DIS_X*3/4)+FONT_16;
	rc.bottom = rc.top+(MAIN_ICON_H+MAIN_ICON_DIS_Y+FONT_16);
	InvalidateRect(self->hWnd, &rc, TRUE);
	#else	
	RECT rc;
	rc.left = FORM_X;
	rc.top = FORM_Y;
	rc.right = FORM_W;
	rc.bottom = FORM_H;
	InvalidateRect(self->hWnd, &rc, FALSE);
	#endif
}

/*************************************************
  Function:		change_rightkey
  Description:  �ı��ұ߿ؼ�����ʾ����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void change_rightkey(HWND hDlg)
{
	DEFEND_STATE defend_state;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, 0};
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Bj_Bf_Home, SID_MainCenter, 0, SID_Right_Sure, SID_MainBianLi_Dianti};
	#else
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Bj_Bf_Home, SID_MainInfo, 0, SID_Right_Sure, SID_MainBianLi_Dianti};	
	#endif
	uint32 ImageID1[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, BID_Right_Exit};
	uint32 TextID1[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Sure, 0};

	switch (g_CurPage)
	{
		case 0:
			defend_state = storage_get_defend_state();
			switch (defend_state)
			{
				case DIS_DEFEND:
					TextID[0] = SID_Bj_Bf_Out;
					break;
					
				case SET_DEFEND:
				case PART_DEFEND:	
					TextID[0] = SID_Bj_Bf_Home;
					break;
				
				default:
					break;
			}
			change_rightctrl_allimagetext(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), ImageID, TextID);
			break;

		case 1:	
		case 3:
		case 4:
		case 5:
			change_rightctrl_allimagetext(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), ImageID1, TextID1);
			break;

		default:
			break;
	}
	reflash_page();
}

/*************************************************
  Function:		net_ontime
  Description: 	����ͼ�궨ʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void net_ontime(void)
{
	RECT rc;

	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	TOP_RC(rc);
	#else
	NET_RC(rc);
	#endif
		
	if (g_NetCnt++ >= NET_CHECK_TIME)
	{
		g_NetCnt = 0;
		if (0 == net_get_net_status(NULL))
		{
			if (g_NetState == 0) 
			{
				g_NetState = 1;
			}
		}
		else
		{
			g_NetState = 0;
		}
		
		#ifndef _IP_MODULE_
		InvalidateRect(self->hWnd, &rc, FALSE);
		#endif
	}
	else
	{
		if (g_NetState > 0)
		{
			g_NetState++;
			if (g_NetState > 4)
			{
				g_NetState = 1;
			}
			
			#ifndef _IP_MODULE_
			InvalidateRect(self->hWnd, &rc, FALSE);
			#endif
		}
	}
}

#ifdef _IP_MODULE_
/*************************************************
  Function:     ipmodule_ontime
  Description:  IPģ��ͼ�궨ʱ��
  Input:        ��
  Output:       ��
  Return:       ��
  Others:       
*************************************************/
static void ipmodule_ontime(void)
{
    RECT rc;
    uint8 state_tmp = 0;
    IPMODULE_RC(rc);
    if(get_ipmodule_bindstate())
    {
    	if (is_main_DeviceNo())
    	{
	        if(get_ipmodule_online())
	        {
	            state_tmp = 2;
	        }
	        else
	        {
	            state_tmp = 1;
	        }
    	}
		else
		{
			state_tmp = 2;
		}
    }
    else
    {
        state_tmp = 0;
    }
	
    if(state_tmp != g_IPModuleState)
    {
        g_IPModuleState = state_tmp;
    }
	InvalidateRect(self->hWnd, &rc, FALSE);
}
#endif

/*************************************************
  Function:		check_msg
  Description: 	����Ƿ�������Ӱ���Ժ�����Ϣ
  Input:		��
  Output:		��
  Return:		TURE/FALSE
  Others:		
*************************************************/
static uint8 check_msg(void)
{
	uint8 ret = FALSE;
	
	if (g_UnreadLylyNum != g_LylyNum)
	{
		ret = TRUE;	
		g_UnreadLylyNum = g_LylyNum;
	}

	if (g_UnreadMsgNum != g_MsgNum)
	{
		ret = TRUE;	
		g_UnreadMsgNum = g_MsgNum;
	}

	return ret;
}

#ifdef _USE_NEW_CENTER_
/*************************************************
  Function:		reg_center_ontime
  Description: 	�ն˱��ֶ�ʱ��
  Input:		
  	1.win
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void reg_center_ontime(void)
{
	int32 ret = 0;
	g_keeptime++;
	
	ret = logic_reg_center_state();
	if (ret == 0)
	{
		if (g_keeptime >= 600)
		{
			// ���ʮ���Ӻ�ûע��ɹ� ���·���ע��
			logic_reg_center_ini();
			g_keeptime = 0;
		}
		return;
	}	

	log_printf("g_keeptime : %d\n",g_keeptime);
	if (g_keeptime >= REG_CENTER_TIME)
	{
		g_keeptime = 0;
		logic_reg_center_ontimer();
	}
}
#endif

#ifdef _RTSP_REG_KEEP_
/*************************************************
  Function:		keep_rtsp_ontime
  Description: 	����ý���������������
  Input:		��
  Output:		��
  Return:		��
  Others:		ʹipad���Ի�ȡ��������ͷ
*************************************************/
static void keep_rtsp_ontime(void)
{
	g_RtspKeepTime ++;
	if (g_RtspKeepTime >= 15)
	{
		g_RtspKeepTime = 0;
		logic_rtsp_ontimer();
	}
}
#endif

/*************************************************
  Function:		on_timer
  Description: 	��ʱ��ִ�к���
   Input: 		
   	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
static void on_timer(uint32 wParam)
{	
	uint8 flag = FALSE;
	PGUI_FORM frm = get_cur_form();
	
	ScreenOnTimer();
	hw_clr_monitor_dog();
	#ifdef _USE_NEW_CENTER_
	reg_center_ontime();
	#endif

	#ifdef _TEST_REBOOT_
	reboot_time ++;
	if (reboot_time >= 10)
	{
		reboot_time = 0;
		hw_stop_feet_dog();
	}
	#endif
	
	#ifdef _RTSP_REG_KEEP_			
	keep_rtsp_ontime();	
	#endif

	if (&FrmMain == frm)
	{
		net_ontime();
		#ifdef _IP_MODULE_
		ipmodule_ontime();
		#endif
		if (TRUE == check_msg())
		{
			InvalidateRect(FrmMain.hWnd, NULL, FALSE);
		}
	}	
}

#if 0
/*************************************************
  Function:		stop_timer
  Description: 	ֹͣ��ʱ
  Input: 		��	
  Output:		��
  Return:		��
  Others:
*************************************************/
static void stop_timer(void)
{
	KillTimer(self->hWnd, GUI_TIMER_ID);
}
#endif

/*************************************************
  Function:		start_timer
  Description: 	������ʱ
  Input: 		��	
  Output:		��
  Return:		��	
  Others:
*************************************************/
static void start_timer(void)
{
	SetTimer(self->hWnd, GUI_TIMER_ID, 50);
	//on_timer(self->hWnd);
}

/*************************************************
  Function:		get_icon_text_image
  Description: 	��ȡͼ���������
  Input: 		��	
  Output:		��
  Return:		��	
  Others:
*************************************************/
static uint32 get_icon_text_image(uint8 mode, uint8 index)
{
	if (0 == mode)
	{
		switch (g_CurPage)
		{
			case 0: 
				return MainIconID[index*2]; 
				
			case 1: 
				return MainCallIconID[index*2]; 
				
			case 2: 
				return MainCenterIconID[index*2]; 
				
			case 3: 
				return MainMonitorIconID[index*2]; 

			case 4:
				return MainBianliIconID[index*2]; 

			case 5:
				return MainMediIconID[index*2]; 
				
			default: 
				return 0;
		}
	}
	else
	{
		switch (g_CurPage)
		{
			case 0: 
				return MainIconID[index*2+1]; 
				
			case 1: 
				return MainCallIconID[index*2+1]; 
				
			case 2: 
				return MainCenterIconID[index*2+1]; 
				
			case 3: 
				return MainMonitorIconID[index*2+1]; 

			case 4:
				return MainBianliIconID[index*2+1]; 

			case 5:
				return MainMediIconID[index*2+1]; 	
				
			default: 
				return 0;
		}
	}
}

/*************************************************
  Function:		draw_top
  Description: 	��ҳ�涥��
  Input: 		
	1.hdc		���ھ��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void draw_top(HDC hdc)
{
	RECT rc;
	
	// ������ͼ��
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	TOP_RC(rc);
	#else
	NET_RC(rc);
	#endif
	
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)	
	DrawBmpID(hdc, 0, 0, 0, 0, BID_MAIN_TOP);
	DrawBmpID(hdc, MAIN_NET_W, 0, 0, 0, BID_Main_Net_1+g_NetState);

	char temp[50];
	ZONE_DATE_TIME Time;
	get_timer(&Time);	
	SelectFont(hdc, GetFont(FONT_20));
	rc.left = 210;
	rc.top = 0;
	rc.right = rc.left + 220;
	rc.bottom = rc.top + FONT_20;
	memset(temp, 0, sizeof(temp));
	sprintf(temp, "%04d-%02d-%02d   %02d:%02d", Time.year, Time.month, Time.day, Time.hour, Time.min);
	DrawText(hdc, temp, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	
	SelectFont(hdc, GetFont(FONT_12));
	rc.left = 510;
	rc.top = 0;
	rc.right = rc.left + 120;
	rc.bottom = rc.top + FONT_20;
	memset(temp, 0, sizeof(temp));
	sprintf(temp, "NO:%s", storage_get_devno_str());
	DrawText(hdc, temp, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	
	#ifdef _IP_MODULE_
	DrawBmpID(hdc, IPMODULE_XPOS, IPMODULE_YPOS, 0, 0, BID_Ipmodule_Bind_Err+g_IPModuleState);
	#endif
	#else
	DrawBmpID(hdc, rc.left, rc.top, 0, 0, BID_Main_Net_1+g_NetState);
	#ifdef _IP_MODULE_
	DrawBmpID(hdc, IPMODULE_XPOS, IPMODULE_YPOS, 0, 0, BID_Ipmodule_Bind_Err+g_IPModuleState);
	#endif
	#endif
}

/*************************************************
  Function:		draw_icon
  Description: 	��ͼ��
  Input: 		
	1.hdc	
  Output:		��
  Return:		��
  Others:
*************************************************/
static void draw_icon(HDC hdc)
{
	RECT rc;
	uint32 i, x, y;

	x = MAIN_ICON_XPOS;
	y = MAIN_ICON_YPOS;

	SetTextColor(hdc, COLOR_COMMON_TEXT);
	for (i = 0; i < g_MaxPage[g_CurPage]; i++)
	{
		// ��ͼ��
		#if (_UI_STYLE_ == _E81S_UI_STYLE_)
		if (g_CurKey == i)
		{
			switch (g_CurPage)
			{
				case 0: 
					DrawBmpID(hdc, x, y, 0, 0, MainIconID_1[i*2]);
					break;
					
				case 1: 
					DrawBmpID(hdc, x, y, 0, 0, MainCallIconID_1[i*2]);
					break;
				
				case 3: 					
					DrawBmpID(hdc, x, y, 0, 0, MainMonitorIconID_1[i*2]);
					break;

				case 4:
					DrawBmpID(hdc, x, y, 0, 0, MainBianliIconID_1[i*2]);
					break;
				
			}
		}
		else
		{
			DrawBmpID(hdc, x, y, 0, 0, get_icon_text_image(0, i));
		}
		#else
		if (g_CurKey == i)
		{
			DrawBmpID(hdc, x - ICON_SEL_DIS, y - ICON_SEL_DIS, 0, 0, BID_Main_KeyDown);	// ��ѡ�е�ͼ�걳��
		}
		DrawBmpID(hdc, x, y, 0, 0, get_icon_text_image(0, i));
		#endif
		
		// ������Ϣ����Ӱ����ʱ������ʾͼ��  
		if (BID_Main3Message == get_icon_text_image(0, i))
		{
			if (g_UnreadMsgNum)
			{
				DrawBmpID(hdc, x+NEW_HIT_DISX, y-NEW_HIT_DISY, 0, 0, BID_Un_Read_1 + (g_UnreadMsgNum - 1));
			}
		} 
	    if (BID_Main7LyLy == get_icon_text_image(0, i) || 
			BID_Main7_Media == get_icon_text_image(0, i))
		{
			if (g_UnreadLylyNum)
			{
				#if (_UI_STYLE_ == _E81S_UI_STYLE_)				
				DrawBmpID(hdc, x+NEW_HIT_DISX, y-NEW_HIT_DISY - 6, 0, 0, BID_Un_Read_1 + (g_UnreadLylyNum - 1));
				#else				
				DrawBmpID(hdc, x+NEW_HIT_DISX, y-NEW_HIT_DISY, 0, 0, BID_Un_Read_1 + (g_UnreadLylyNum - 1));
				#endif
			}
		}
		
		// ��ͼ���µ�����
		if (storage_get_language() != ENGLISH)
		{
			SelectFont(hdc, GetFont(FONT_20));
		}
		else
		{
			SelectFont(hdc, GetFont_ABC(FONT_20));
		}
		rc.left = x-MAIN_ICON_DISX/2;
		rc.top = y+MAIN_ICON_H+ICON_TEXT_DISY;
		rc.right = rc.left + MAIN_ICON_W+ MAIN_ICON_DISX;
		rc.bottom = rc.top + FONT_20;
		DrawText(hdc, get_str(get_icon_text_image(1, i)), -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		
		if (i == 2 || i == 5)
		{
			x = MAIN_ICON_XPOS;
			y += MAIN_ICON_H + MAIN_ICON_DISY;
		}
		else
		{
			x += MAIN_ICON_W + MAIN_ICON_DISX;
		}
	}

	if (g_CurPage == 0)
	{
		uint32 TextId;
		DEFEND_STATE defend_state = storage_get_defend_state();
		switch (defend_state)
		{
			case DIS_DEFEND:
				TextId = SID_Bj_Bf_Out;
				break;

			case SET_DEFEND:
			case PART_DEFEND:
				TextId = SID_Bj_Bf_Home;
				break;

			default:
				break;
		}

		SendMessage(g_RightWin, WM_Right_Set_TextID, 0, TextId);
	}
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
	RECT rc;

	rc.left = FORM_X;
	rc.top = FORM_X;
	rc.right = FORM_W;
	rc.bottom = FORM_H;
	
	// ������(���Կ���ֱ������ɫ,�����ǻ�ͼƬ)
	DrawBmpID(hdc, rc.left, rc.top, 0, 0, BID_DEFAULT_BK);
}

/*************************************************
  Function:		OnPaint
  Description: 	������������
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
	
	#if (_UI_STYLE_ == _V6_UI_STYLE_)
	draw_bk(hdc);
	draw_icon(hdc);
	draw_top(hdc);
	#elif (_UI_STYLE_ == _E81S_UI_STYLE_)
	draw_bk(hdc);
	draw_icon(hdc);
	draw_top(hdc);
	#endif
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		get_icon_max
  Description:  ��ȡ��ǰҳ����ͼ����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static int get_icon_max(void)
{
	if (PAGE_LEVEL > g_CurPage)
	{
		return g_MaxPage[g_CurPage];
	}

	return 0;
}

/*************************************************
  Function:		SelectModule
  Description:  ѡ����ģ��
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static int SelectModule(HWND hDlg)
{
	uint32 image = get_icon_text_image(0, g_CurKey);

	switch (image)
	{
		case BID_Main1Alarm:
			// ����
			AlarmWindow(hDlg);
			break;
			
		case BID_Main2Call:
			g_CurPage = 1;
			g_OldKey = g_CurKey;
			g_CurKey = 0;
			change_rightkey(hDlg);			
			break;
			
		case BID_Main3Message:
			// ��Ϣ
			form_show(&FrmMsg);
			break;
        
		case BID_Main4Center:
		{
			// ��������
			char no[10] = {0};
			
			sprintf(no, "%d", MANAGER_NUM+1);
			ui_callout_appstart(DEVICE_TYPE_MANAGER, no);
			break;
		}
		
		case BID_Main5Monitor:
			g_CurPage = 3;
			g_OldKey = g_CurKey;
			g_CurKey = 0;
			change_rightkey(hDlg);				
			break;
		
		case BID_Main4EControl:
			#ifdef _JD_MODE_
			if (FALSE == storage_get_extmode(EXT_MODE_JD))
			{
				//show_msg(win, WID_MsgCtrl, MSG_WARNING, SID_Jd_Mode_Unused);
			}
			else
			{
			    if (JD_FACTORY_ACBUS == storage_get_extmode(EXT_MODE_JD_FACTORY))
			    {
			        //ProcStartAppGuidEx(GUID_EXE_AURINE_JD, NULL, ProcGetProcGuid(GUID_EXE_DESKTOP), NULL, NULL);
			    }
				else
				{
				    //ProcStartAppGuidEx(GUID_EXE_JD, NULL, ProcGetProcGuid(GUID_EXE_DESKTOP), NULL, NULL);
				}
			}
			#endif	
			break;

		case BID_Main6Record:					
			// ͨ����¼
			break;
			
		case BID_Main7LyLy:
			// ��Ӱ����
			form_show(&FrmLyLy);
			break;
			
		case BID_Main8BianLi:
			g_CurPage = 4;
			g_OldKey = g_CurKey;
			g_CurKey = 0;
			change_rightkey(hDlg);	
			break;	
			
		case BID_Main9Setting:
			// ����
			form_show(&FrmSet);
			break;
					
		case BID_MainCall_User:
		{
			// ����ס��
			ui_callout_appstart(DEVICE_TYPE_ROOM, NULL);
			break;
		}
		
		case BID_MainCall_FengJi:
		{
			// ���зֻ�
			ui_callout_appstart(DEVICE_TYPE_FENJI_NET, NULL);
			break;
		}
		
		case BID_MainCenter_1:
		case BID_MainCenter_2:
		case BID_MainCenter_3:
		{		
			//char no[10] = {0};
			//sprintf(no, "%d", g_ImageId-BID_MainCenter_1+1+50);
			// ��������
			break;
		}
		
		case BID_MainMonitor1_Door:
			// ������ǰ
			ui_monitor_list_appstart(DEVICE_TYPE_DOOR_NET);
			break;
			
		case BID_MainMonitor2_Stair:
			// �����ݿ�
			ui_monitor_list_appstart(DEVICE_TYPE_STAIR);
			break;
			
		case BID_MainMonitor3_Area:
			// ��������
			ui_monitor_list_appstart(DEVICE_TYPE_AREA);
			break;
		
		case BID_Main_JRLY:
			// ��������
			#ifdef _JRLY_MODE_
			ui_jrlyrecord_win(hDlg);
			#endif
			break;

		case BID_Main_CleanScreen:
			// �����Ļ
			break;

		case BID_Main7_Media:
			// ��ý��
			g_CurPage = 5;
			g_OldKey = g_CurKey;
			g_CurKey = 0;
			change_rightkey(hDlg);
			break;

		case BID_Main7_Snap:
			// ץ��
			form_show(&FrmPhoto);
			break;

	    case BID_MainControl_DianTi:
	        #ifdef _DIANTI_CALL_
            // ���ݿ���         
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			form_show(&FrmDianti);
			#endif
			#endif
      	   break;	

		case BID_MainMonitor3_Camera:
			#ifdef _LIVEMEDIA_
            // ��������
            #endif
			break;
			
		default:
			break;	
	}

	return TRUE;
}

/*************************************************
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	int max = 0;
	uint32 TextId = 0;
	uint32 image = SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON),
		WM_Right_Get_ImageOrTextID, lParam, 0);
	switch (image)
	{
		case BID_Right_Table:
			max = get_icon_max();	
			if (max > 1)
			{
				if (g_CurKey < (max-1))
				{
					g_CurKey++;
				}
				else
				{
					g_CurKey = 0;
				}
			}
			
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			RECT rc;
			MAIN_RC (rc);
			InvalidateRect(self->hWnd, &rc, FALSE);
			#else
			reflash_page();
			#endif			
			break;

		case SID_Right_Sure:
			SelectModule(hDlg);
			break;

		case BID_Right_Exit:
			g_CurPage = 0;
			g_CurKey = g_OldKey;
			change_rightkey(hDlg);
			break;

		case SID_MainBianLi_Dianti:
			// ��ʾ����ҳ��
			form_show(&FrmDianti);
			break;

		case SID_Bj_Bf_Out:
			if (FALSE == storage_get_extmode(EXT_MODE_ALARM))
			{
				show_msg(hDlg, IDC_MSG_CTRL, MSG_WARNING, SID_Af_Mode_Unused);
			}
			else if(AF_SUCCESS == alarm_set_operator(EXECUTOR_LOCAL_HOST))
			{
				TextId = SID_Bj_Bf_Home;
				SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON),	WM_Right_Set_TextID, 0, (LPARAM)TextId);
			}
			break;

		case SID_Bj_Bf_Home:
			if (FALSE == storage_get_extmode(EXT_MODE_ALARM))
			{
				show_msg(hDlg, IDC_MSG_CTRL, MSG_WARNING, SID_Af_Mode_Unused);
			}
			else
			{
				show_msg_pass(hDlg, IDC_FORM, PASS_TYPE_USER, 0xff);
			}

			break;

		case SID_MainInfo:
			// ��ʾ��Ϣҳ��
			form_show(&FrmMsg);
			break;

		#if (_UI_STYLE_ == _E81S_UI_STYLE_)
		case SID_MainCenter:
		{
			// ��������
			char no[10] = {0};
			
			sprintf(no, "%d", MANAGER_NUM+1);
			ui_callout_appstart(DEVICE_TYPE_MANAGER, no);
			break;
		}	
		#endif
		#if 0
		case BID_mainmonitor2_stair:
			//ui_monitor_appstart(DEVICE_TYPE_STAIR);
			// ��ʾ����ҳ��
			break;
		#endif

		default:
			break;
	}
}

/*************************************************
  Function:			InputCtrlCommand
  Description: 	 	���������
  Input: 		
	1.win:   		��ǰ����Ĵ���
  Output:			��
  Return:		
  Others:
*************************************************/
static void InputCtrlCommand(HWND hDlg, uint32 event, uint32 ID)
{
	//DEFEND_STATE defend_state;
	uint32 TextId;

	switch (ID)
	{
		case MSG_EVENT_YES:							// ������ȷ	
			if (AF_SUCCESS == alarm_unset_operator(EXECUTOR_LOCAL_HOST, 0))
			{	
				TextId = SID_Bj_Bf_Out;
				SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Set_TextID, 0, TextId);
			}
			break;
			
		case MSG_EVENT_XIECHI:						// Ю�ֱ���
			if (AF_SUCCESS == alarm_unset_operator(EXECUTOR_LOCAL_HOST, 1))
			{	
				TextId = SID_Bj_Bf_Out;
				SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Set_TextID, 0, TextId);
			}
			break;
			
		case MSG_EVENT_NO:							// �������
			break;
	}
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
static void OnCommand(HWND hDlg, WPARAM id, LPARAM lParam)
{
	switch (id)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg, lParam);
			break;

		case IDC_FORM:
			InputCtrlCommand(hDlg, id, lParam);
			break;

		default:
			break;
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
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, 0};
	
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Bj_Bf_Home, SID_MainCenter, 0, SID_Right_Sure, SID_MainBianLi_Dianti};
	#elif (_UI_STYLE_ == _V6_UI_STYLE_)
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Bj_Bf_Home, SID_MainInfo, 0, SID_Right_Sure, SID_MainBianLi_Dianti};	
	#endif
	DEFEND_STATE defend_state = storage_get_defend_state();
	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.parent = hDlg;
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = RIGHT_CTRL_FONT;
	for (i = 0; i < g_rightCtrl.MaxNum; i++)
	{
		g_rightCtrl.buttons[i].Enabled = TRUE;
		g_rightCtrl.buttons[i].ImageID = ImageID[i];
		if (i == 0)
		{
			switch (defend_state)
			{
				case DIS_DEFEND:
					g_rightCtrl.buttons[i].TextID = SID_Bj_Bf_Out;
					break;

				case SET_DEFEND:
				case PART_DEFEND:
					g_rightCtrl.buttons[i].TextID = SID_Bj_Bf_Home;
					break;

				default:
					break;
			}
		}
		else
		{
			g_rightCtrl.buttons[i].TextID = TextID[i];
		}
	}

	g_RightWin = CreateWindow(AU_RIGHT_BUTTON, "", 
				WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
				IDC_RIGHT_BUTTON, 
				RIGHT_CTRL_X, RIGHT_CTRL_Y, RIGHT_CTRL_W, RIGHT_CTRL_H, 
				hDlg, (DWORD)&g_rightCtrl);
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
	CreateRightCtrl(hDlg);
}

/*************************************************
  Function:		hook_msg_proc
  Description: 	�����źŴ���
  Input: 		
	1.hDlg		���
  	2.message	��Ϣ
  	3.wParam	����1
  	4.lParam	����2
  Output:		��
  Return:		�Ƿ���������¼�
  Others:
*************************************************/
static int hook_msg_proc(void* context, HWND hWnd, int message, WPARAM wParam, LPARAM lParam)
{	
	// ��ֹ������������������������
	hw_clr_monitor_dog();

	printf("x: %d  y: %d\n ", LOWORD(lParam), HIWORD(lParam));
	int32 x = LOWORD(lParam);
	int32 y = HIWORD(lParam);
	int32 msg = 0;

	if (x > 820)
	{
		if (MSG_LBUTTONUP == message)
		{
			if (y > 0 && y < 120)
			{
				msg = RIGHT_SCANCODE_F1;
			}
			else if(y > 120 && y < 240)
			{
				msg = RIGHT_SCANCODE_F2;
			}
			else if(y > 240 && y < 360)
			{
				msg = RIGHT_SCANCODE_F3;
			}
			else if(y > 360 && y < 480)
			{
				msg = RIGHT_SCANCODE_F4;
			}
			else
			{
				msg = RIGHT_SCANCODE_F5;
			}

			PGUI_FORM frm = get_cur_form();
			if(frm == NULL)
			{
				log_printf("get_cur_form is NULL!\n");
				return FALSE;
			}
			SendNotifyMessage(GetDlgItem(frm->hWnd, IDC_RIGHT_BUTTON), MSG_KEYUP, msg, lParam);
			return HOOK_STOP;
		}
	}
	return HOOK_GOON;
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
  Function:		set_curkey
  Description: 	�����˻�������ʱ ���������һ��ͼƬ
  				����Ϊ��ǰѡ��ͼ��
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void set_curkey(void)
{
	DEFEND_STATE defend_state;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0, 0};
	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Bj_Bf_Home, SID_MainCenter, 0, SID_Right_Sure, SID_MainBianLi_Dianti};
	#else
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Bj_Bf_Home, SID_MainInfo, 0, SID_Right_Sure, SID_MainBianLi_Dianti};	
	#endif
	defend_state = storage_get_defend_state();
	switch (defend_state)
	{
		case DIS_DEFEND:
			TextID[0] = SID_Bj_Bf_Out;
			break;
			
		case SET_DEFEND:
		case PART_DEFEND:	
			TextID[0] = SID_Bj_Bf_Home;
			break;
		
		default:
			break;
	}
	change_rightctrl_allimagetext(g_RightWin, ImageID, TextID);
	g_CurKey = 0;
	g_CurPage = 0;
	InvalidateRect(FrmMain.hWnd, NULL, FALSE);
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
	//log_printf("mainwin %s  message: %04x wParam: %04x\n", __FUNCTION__, message, wParam);
	switch (message) 
	{
		case MSG_CREATE:
			set_skin(SKIN_1);						// ����Ƥ������
			create_ctrls(hDlg);
			RegisterKeyMsgHook(hDlg, hook_msg_proc);	// ע�ṳ��
			RegisterMouseMsgHook(hDlg, hook_msg_proc);
			break;
		
		case MSG_INITDIALOG:
			self->hWnd = hDlg;
			SetWindowBkColor(hDlg, PAGE_BK_COLOR);
			start_timer();
			break;
			
		case MSG_ACTIVE:
			if (wParam)
			{
				reflash_page();
			}
			break;

		case MSG_SHOWWINDOW:
			#if 0
			//form_show(&FrmBeCall);
			//form_hide(&FrmBeCall);
			//form_show(&FrmAlarm);
			//form_hide(&FrmAlarm);
			//form_show(&FrmMsgHit);
			//form_hide(&FrmMsgHit);
			#endif
			media_clear_fb();						// ���fb ���ͼ��ȥ�� ֻ���ڿ�����һ�ε���
			sys_sync_hint_state();
			hw_start_monitor_dog();
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			return 0;
			
		case MSG_COMMAND:
			OnCommand(hDlg, wParam, lParam);
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
						
		case MSG_TIMER:	
			on_timer(wParam);
			break;

		// �߼��޷�ֱ�Ӵ�������,�跢��Ϣ��������������
		case WM_FORM_SHOW:
			form_show((PGUI_FORM)lParam);
			return 0;

		case WM_RELOAD:
			InvalidateRect(FrmMain.hWnd, NULL, FALSE);
			break;
			
		case MSG_DESTROY:
			break;	
	}
	
	return DefaultDialogProc (hDlg, message, wParam, lParam);
}

/*************************************************
  Function:		register_controls
  Description: 	ע��ؼ�
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void register_controls(void)
{
	register_right_button();
	register_num_keybord();
	register_list_ctrl();
	register_input_ctrl();
	register_eightarea_ctrl();
	register_spin_ctrl();
	register_procress_ctrl();
}

/*************************************************
  Function:		unregister_controls
  Description: 	ɾ���ؼ�
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void unregister_controls(void)
{
	unregister_right_button();
	unregister_num_keybord();
	unregister_list_ctrl();
	unregister_input_ctrl();
	unregister_eightarea_ctrl();
	unregister_spin_ctrl();
	unregister_procress_ctrl();
}

/*************************************************
  Function:		InitGui
  Description: 	��ʼ��GUI
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void InitGui(void)
{	
	InitLogFont();				// ��ʼ������
	register_controls();		// ע��ؼ�
	FrmMain.hWnd = 0;
	FrmMain.Parent = NULL;
	FrmMain.pDlgTemplate = &DlgInit;
	FrmMain.WinProc = WindowProc;
	FrmMain.language = 0;
	FrmMain.skin = -1;
	FrmMain.ChangeLanguage = NULL;
	FrmMain.ChangeSkin = NULL;
	log_printf("---------------InitGui--------------\n");
}

/*************************************************
  Function:		FreeGUI
  Description: 	�ͷ�GUI������Դ
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void FreeGUI(void)
{
	//close_all_form();			// �رմ���
	FreeLogFont();				// �ͷ�����
	free_bmp_res();				// �ͷ�ͼƬ��Դ
	unregister_controls();		// ж�ؿؼ�
}

