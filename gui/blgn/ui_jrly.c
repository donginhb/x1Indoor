/*********************************************************
  Copyright (C), 2009-2019
  File name:	ui_jrly.c
  Author:   	caogw
  Version:   	1.0
  Date: 		17.4.24
  Description:  �������Խ���
  History:            
*********************************************************/
#include "storage_include.h"
#include "gui_include.h"

#ifdef _JRLY_MODE_
/************************��������************************/
#define TOP_TEXT_H			52
#define LIST_CTRL_Y			TOP_TEXT_H

#define LIST_CTRL_H			(480-TOP_TEXT_H)
	
#define TOP_TEXT_XPOS		30	
#define TOP_TEXT_YPOS		((TOP_TEXT_H-Font16X16)/2)	

#define BUTTON_DISX			10
#define BUTTON_W			100
#define BUTTON_H			74
#define BUTTON_XPOS			((LIST_CTRL_W-5*BUTTON_W-4*BUTTON_DISX)/2)
#define BUTTON_YPOS			(LIST_CTRL_H+(FORM_H-LIST_CTRL_H-BUTTON_H)/2)

#define PROC_W				258
#define PROC_H				22
#define PROC_XPOS			(40+(LIST_CTRL_W-PROC_W)/2)
#define PROC_YPOS			(TOP_TEXT_H-PROC_H)/2

#define MEDIA_STATE_PIC_W	32
#define MEDIA_STATE_PIC_H	32
#define MEDIA_STATE_PIC_X	(LIST_CTRL_W-10-MEDIA_STATE_PIC_W)
#define MEDIA_STATE_PIC_Y	((TOP_TEXT_H-MEDIA_STATE_PIC_H)/2)

#define MAX_JRLY_TIME		30

#define DT_TEXT_DISX		200

typedef enum
{
	MEDIA_JRLY_STATE_STOP = 0x00,
	MEDIA_JRLY_STATE_PLAY,
	MEDIA_JRLY_STATE_REC,
}MEDIA_JRLY_STATE;	

/************************��������************************/
typedef struct 
{
	char filename[60];
 	MEDIA_JRLY_STATE mediastate;
 	int8 index;
	uint8 showtime;					// ��ʱ��
	uint8 rec_mem;					// 1�����ڵ�ǰ¼���ļ� 0 ����Ϊ�б����ļ�
 	ZONE_DATE_TIME time;
}MEDIA_JRLY_INFO,*PMEDIA_JRLY_INFO;	

static HWND g_RightWin;
static HWND g_listwin;
static HWND g_procwin;
static PMEDIA_JRLY_INFO g_jrlyinfo = NULL;
static PJRLYLIST_INFO jrlylist = NULL;
static RIGHTCTRL_INFO g_rightCtrl;
static LISTCTRL_INFO g_listCtrl;
static PROCRESS_CTRL g_ProcCtrl;

/************************��������************************/
CREATE_FORM(FormSetjrlyrecord);

/*************************************************
  Function:		ui_reflash
  Description: 	ˢ����Ļ
  Input:	
  	1.hDlg		���ھ��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void ui_reflash(void)
{
	InvalidateRect(self->hWnd, NULL, FALSE);
}

/*************************************************
  Function:		show_win
  Description: 	��ʾ�ľ�����Ϣ
  Input:		��
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void show_win(void)
{
	uint32 i,max = 0;
	PLISTITEM_INFO g_info = NULL;
	g_jrlyinfo->index = -1;
	SendMessage(g_listwin, WM_List_Clear_Item, 0, 0);
	if (jrlylist)
	{
		storage_free_jrly_memory(&jrlylist);	
		jrlylist = NULL;
	}
	storage_get_jrlyrecord(&jrlylist);

	if (NULL == jrlylist || jrlylist->Count == 0)
	{
		return;
	}
	max = jrlylist->Count;
	g_info = malloc((sizeof(LISTITEM_INFO))*max);
	if (g_info)
	{
		memset(g_info,0,(sizeof(LISTITEM_INFO))*max);
		for (i = 0; i < max; i++)
		{
			g_info[i].Num = 2;
			g_info[i].Icon = 0;
			g_info[i].Item[0].Change = FALSE;
			if (jrlylist->JrlyInfo[i].ReadFlag)
			{
				g_info[i].Item[0].Image = BID_Jrly_FLag_1;
			}
			else
			{
				g_info[i].Item[0].Image = BID_Jrly_FLag_2;
			}
			
			g_info[i].Item[0].ShowType = STYLE_LEFT;
			sprintf(g_info[i].Item[1].Text, "%04d-%02d-%02d %02d:%02d:%02d", jrlylist->JrlyInfo[i].Time.year,jrlylist->JrlyInfo[i].Time.month,jrlylist->JrlyInfo[i].Time.day
				,jrlylist->JrlyInfo[i].Time.hour,jrlylist->JrlyInfo[i].Time.min,jrlylist->JrlyInfo[i].Time.sec);
			g_info[i].Item[1].ShowType = STYLE_LEFT;
		}
		SendMessage(g_listwin, WM_List_Add_Item, max, g_info);
	
		free(g_info);
		g_info = NULL;
	}
} 

/*************************************************
  Function:		jrlyrecordPaint
  Description: 	������
  Input:		
  	1.win
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 jrlyrecordPaint(HDC hdc)
{
	char tmp[20];
	uint8 min, sec;
	RECT Textrc;
	if (storage_get_language() != ENGLISH)
	{
		SelectFont(hdc, GetFont(FONT_16));
	}
	else
	{
		SelectFont(hdc, GetFont_ABC(FONT_16));
	}		
	SetTextColor(hdc, COLOR_BLACK);
	DrawBmpID(hdc, 0, 0, 0, 0, BID_Set_BK);
	DrawBmpID(hdc, 0, 0, 0, 0, BID_ListCtrl_Title);

	Textrc.left = TOP_TEXT_XPOS;
	Textrc.top = TOP_TEXT_YPOS;
	Textrc.right = Textrc.left + DT_TEXT_DISX;
	Textrc.bottom = Textrc.top + Font16X16;
	DrawText(hdc, get_str(SID_Bl_Jrly), -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);	

	Textrc.left = PROC_XPOS - 41;
	Textrc.top = PROC_YPOS + (PROC_H - Font16X16)/2;
	Textrc.right = Textrc.left + DT_TEXT_DISX;
	Textrc.bottom = Textrc.top + Font16X16;
	memset(tmp, 0, sizeof(tmp));
	sprintf(tmp, "00:00", null);
	DrawText(hdc, tmp, -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);
	
	Textrc.left = PROC_XPOS + PROC_W + 10;
	Textrc.top = PROC_YPOS + (PROC_H - Font16X16)/2;
	Textrc.right = Textrc.left + DT_TEXT_DISX;
	Textrc.bottom = Textrc.top + Font16X16;
	min = g_jrlyinfo->showtime/60;
	sec = g_jrlyinfo->showtime%60;
	memset(tmp, 0, sizeof(tmp));
	sprintf(tmp, "%02d:%02d", min, sec);
	DrawText(hdc, tmp, -1, &Textrc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);

	if (MEDIA_JRLY_STATE_PLAY == g_jrlyinfo->mediastate)
	{
		DrawBmpID(hdc, MEDIA_STATE_PIC_X, MEDIA_STATE_PIC_Y, 0, 0, BID_Play);
	}
	else if (MEDIA_JRLY_STATE_REC == g_jrlyinfo->mediastate)
	{
		DrawBmpID(hdc, MEDIA_STATE_PIC_X, MEDIA_STATE_PIC_Y, 0, 0, BID_Rec);
	}
	
	return TRUE;
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
	jrlyrecordPaint(hdc);
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		init_key
  Description: 	��ʼ���б��ؼ���Ӧ�ұ߿ؼ���Ϣ
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void init_key(void)
{
	add_rightctrl_win(g_RightWin, RIGHT_KEY2, g_listwin, WM_List_Go_NextSel, 0, 0);
}

/*************************************************
  Function:		init_key
  Description: 	��ʼ���б��ؼ���Ӧ�ұ߿ؼ���Ϣ
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
static void uninit_key(void)
{
	SendMessage(g_RightWin, WM_Right_Clear_Win, RIGHT_KEY2, 0);
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
	uint8 i;
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0,  BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Right_Rec, SID_Right_Del, 0 ,SID_Right_Play, 0};

	for ( i = 0; i < RIGHT_NUM_MAX; i++)
	{
		SendMessage(g_RightWin, WM_Right_Set_Image, i, (LPARAM)ImageID[i]);
		SendMessage(g_RightWin, WM_Right_Set_TextID, i, (LPARAM)TextID[i]);
	}
}

/*************************************************
  Function:		Change_Right_Image
  Description: 	�ı��ұ߿ؼ�ͼƬ
  Input:		��
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void Change_Right_Image(void)
{
	uint8 i;
	uint32 ImageID1[RIGHT_NUM_MAX] = {0, 0, 0, 0, BID_Right_Exit};
	uint32 TextID1[RIGHT_NUM_MAX] = {0, SID_Right_Save, SID_Right_Del, SID_Right_Listen, 0};
	uint32 ImageID2[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0,  BID_Right_Exit};
	uint32 TextID2[RIGHT_NUM_MAX] = {SID_Right_Rec, SID_Right_Del, 0 ,SID_Right_Play, 0};
	uint32 ImageID3[RIGHT_NUM_MAX] = {0, 0, 0, 0, BID_Right_Exit};
	uint32 TextID3[RIGHT_NUM_MAX] = {0, 0, 0, SID_Right_Stop, 0};

	uninit_key();
	if (MEDIA_JRLY_STATE_STOP != g_jrlyinfo->mediastate)
	{
		for ( i = 0; i < RIGHT_NUM_MAX; i++)
		{
			SendMessage(g_RightWin, WM_Right_Set_Image, i, (LPARAM)ImageID3[i]);
			SendMessage(g_RightWin, WM_Right_Set_TextID, i, (LPARAM)TextID3[i]);
		}
		
		return;
	}
	
	if (0 == g_jrlyinfo->rec_mem)
	{
		init_key();
		for ( i = 0; i < RIGHT_NUM_MAX; i++)
		{
			SendMessage(g_RightWin, WM_Right_Set_Image, i, (LPARAM)ImageID2[i]);
			SendMessage(g_RightWin, WM_Right_Set_TextID, i, (LPARAM)TextID2[i]);
		}
	}
	else
	{
		for ( i = 0; i < RIGHT_NUM_MAX; i++)
		{
			SendMessage(g_RightWin, WM_Right_Set_Image, i, (LPARAM)ImageID1[i]);
			SendMessage(g_RightWin, WM_Right_Set_TextID, i, (LPARAM)TextID1[i]);
		}
	}
}

/*************************************************
  Function:		MediaRecord_Callback
  Description: 	���Ȼص�����
  Input:		
  	1.param1	�ļ�����ʱ��
  	2.param2	�ٷֱ� 0-100
  	3.state		false ���󷵻� true ��ȷ����
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 MediaRecord_Callback(int32 param1,int32 param2,int32 state)
{
	if (FALSE == state)
	{
		g_jrlyinfo->showtime  = 0;
		g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
		SendMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
		return TRUE;
	}

	if (g_jrlyinfo->mediastate == MEDIA_JRLY_STATE_REC)
	{
		if (100 == param2)
		{
			if (0 == g_jrlyinfo->rec_mem)
			{
				g_jrlyinfo->rec_mem = 1;
				g_jrlyinfo->showtime  = 0;
				g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
				SendMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
				Change_Right_Image();
				ui_reflash();
			}
		}
		else
		{	
			SendMessage(g_procwin, WM_Procress_Set_Proc, param2, 0);
		}
	}
	return TRUE;
}

/*************************************************
  Function:		MediaStop_Callback
  Description: 	
  Input:		
  	1.param1
  	2.param2
  	3.state
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void MediaStop_Callback(void)
{
	if (g_jrlyinfo->mediastate == MEDIA_JRLY_STATE_PLAY)
	{
		g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
		PostMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
		Change_Right_Image();
		ui_reflash();
	}
}

/*************************************************
  Function:		MediaPlay_Callback
  Description: 	
  Input:		
  	1.param1	�ļ�����ʱ��
  	2.param2	�ٷֱ� 0-100
  	3.state		false ���󷵻� true ��ȷ����
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 MediaPlay_Callback(int32 param1,int32 param2,int32 state)
{
	if (FALSE == state)
	{
		g_jrlyinfo->showtime  = 0;
		g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
		SendMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
		return TRUE;
	}

	if (g_jrlyinfo->mediastate == MEDIA_JRLY_STATE_PLAY)
	{
		if (100 == param2)
		{
			g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
			g_jrlyinfo->showtime = 0;
			ui_reflash();
			SendMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
			Change_Right_Image();
		}
		else
		{
			if (0 == g_jrlyinfo->showtime)
			{
				g_jrlyinfo->showtime = param1;
				ui_reflash();	
			}
			SendMessage(g_procwin, WM_Procress_Set_Proc, param2, 0);
		}
	}
	return TRUE;
}

/*************************************************
  Function:		media_stop
  Description: 	ֹͣ
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void media_stop(HWND hDlg)
{
	if (MEDIA_JRLY_STATE_STOP != g_jrlyinfo->mediastate)
	{
		switch (g_jrlyinfo->mediastate)
		{
			case MEDIA_JRLY_STATE_STOP:
				break;

			case MEDIA_JRLY_STATE_PLAY:
				sys_stop_play_audio(SYS_MEDIA_MUSIC);
				PostMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
				break;	

			case MEDIA_JRLY_STATE_REC:
				g_jrlyinfo->rec_mem = 1;
				sys_stop_family_record();
				PostMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
				break;	
		}
		g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
		g_jrlyinfo->showtime = 0;
		ui_reflash();	
		Change_Right_Image();
	}
}

/*************************************************
  Function:		media_rec
  Description: 	¼��
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void media_rec(HWND hDlg)
{
	uint32 ret;
	char filename[100];
	
	if (MEDIA_JRLY_STATE_STOP == g_jrlyinfo->mediastate)
	{
		if (jrlylist && jrlylist->Count >= MAX_JRLY_NUM)
		{
			show_msg(hDlg, IDC_MSG_CTRL, MSG_ERROR, SID_Msg_Jrly_rec_full);			
			return;
		}
		if (g_jrlyinfo->rec_mem)
		{
			get_jrlyrecord_path(filename, &g_jrlyinfo->time);
			FSFileDelete(filename);
		}
		get_timer(&g_jrlyinfo->time);
		memset(g_jrlyinfo->filename,0,sizeof(g_jrlyinfo->filename));
		get_jrlyrecord_file(g_jrlyinfo->filename,&g_jrlyinfo->time);
		ret = sys_start_family_record(g_jrlyinfo->filename, MediaRecord_Callback, NULL);
		if (SYS_MEDIA_ECHO_OK == ret)
		{
			g_jrlyinfo->rec_mem = 0;
			g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_REC;
			g_jrlyinfo->showtime = MAX_JRLY_TIME;
			Change_Right_Image();
			ui_reflash();	
		}
	}
}

/*************************************************
  Function:		media_play
  Description: 	����
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void media_play(HWND hDlg)
{
	uint32 ret = SYS_MEDIA_ECHO_ERR;
	
	if (MEDIA_JRLY_STATE_STOP == g_jrlyinfo->mediastate)
	{
		g_jrlyinfo->showtime = 0;
		
		memset(g_jrlyinfo->filename,0,sizeof(g_jrlyinfo->filename));
		if (g_jrlyinfo->rec_mem)
		{
			get_jrlyrecord_path(g_jrlyinfo->filename, &g_jrlyinfo->time);
			ret = sys_start_play_audio(SYS_MEDIA_MUSIC, g_jrlyinfo->filename, FALSE, JRLY_VOLUME, MediaPlay_Callback, MediaStop_Callback);
		}
		else
		{
			if (jrlylist && jrlylist->Count > 0 && g_jrlyinfo->index < jrlylist->Count && g_jrlyinfo->index != -1)
			{
				get_jrlyrecord_path(g_jrlyinfo->filename,&jrlylist->JrlyInfo[g_jrlyinfo->index].Time);
				ret = sys_start_play_audio(SYS_MEDIA_MUSIC, g_jrlyinfo->filename, FALSE, JRLY_VOLUME, MediaPlay_Callback, MediaStop_Callback);		
			}
		}
		if (SYS_MEDIA_ECHO_OK == ret)
		{
			g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_PLAY;
			
			if (FALSE == g_jrlyinfo->rec_mem && jrlylist && jrlylist->JrlyInfo[g_jrlyinfo->index].ReadFlag)
			{
				jrlylist->JrlyInfo[g_jrlyinfo->index].ReadFlag = FALSE;
				storage_set_jrlyrecord_flag(g_jrlyinfo->index, FALSE);
				sys_sync_hint_state();
				set_list_Image(g_listwin, g_jrlyinfo->index, 0, BID_Jrly_FLag_2, CHECK_IMAGE);
			}
			Change_Right_Image();
		}
	}
}

/*************************************************
  Function:		jrlyrecordDestroyProc
  Description: 	���ٴ�����
  Input:		
  	1.win
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 jrlyrecordDestroyProc(void)
{	
	switch (g_jrlyinfo->mediastate)
	{
		case MEDIA_JRLY_STATE_STOP:
			if (g_jrlyinfo->rec_mem)
			{
				storage_add_jrlyrecord(g_jrlyinfo->time);
				g_jrlyinfo->rec_mem = 0;
				g_jrlyinfo->showtime = 0;
				sys_sync_hint_state();
			}
			break;

		case MEDIA_JRLY_STATE_PLAY:
			sys_stop_play_audio(SYS_MEDIA_MUSIC);
			storage_add_jrlyrecord(g_jrlyinfo->time);
			sys_sync_hint_state();
			break;	

		case MEDIA_JRLY_STATE_REC:
			sys_stop_family_record();
			storage_add_jrlyrecord(g_jrlyinfo->time);
			sys_sync_hint_state();
			break;	
	}

	if (jrlylist)
	{
		storage_free_jrly_memory(&jrlylist);	
	}
	
	return 0;
}

/*************************************************
  Function:		RightCtrlCommand
  Description: 	�ұ߿ؼ����µĴ�����
  Input:		
  	1.win
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static void RightCtrlCommand(HWND hDlg, LPARAM lParam)
{
	uint32 Image = SendMessage(GetDlgItem(hDlg, IDC_RIGHT_BUTTON), WM_Right_Get_ImageOrTextID, lParam, 0);
	g_jrlyinfo->index = SendMessage(GetDlgItem(hDlg, IDC_LIST_CTRL), WM_List_Get_Sel, lParam, 0);
	ECHO_STORAGE ret = ECHO_STORAGE_ERR;
	
	switch(Image)
	{
		case SID_Right_Rec:
			media_rec(hDlg);
			break;

		case SID_Right_Listen:
		case SID_Right_Play:
			media_play(hDlg);
			break;

		case SID_Right_Stop:
			media_stop(hDlg);
			break;
	
		case SID_Right_Save:
			if (MEDIA_JRLY_STATE_STOP != g_jrlyinfo->mediastate)
			{	
				return;
			}
			if (g_jrlyinfo->rec_mem)
			{
				ret = storage_add_jrlyrecord(g_jrlyinfo->time);
				if (ECHO_STORAGE_OK == ret)
				{
					g_jrlyinfo->rec_mem = 0;
					sys_sync_hint_state();
					Change_Right_Image();
					show_msg(hDlg, IDC_MSG_CTRL, MSG_INFORMATION, SID_Save_OK);
					show_win();
				}
				else
				{
					show_msg(hDlg, IDC_MSG_CTRL, MSG_INFORMATION, SID_Save_ERR);
				}
			}
			break;
	
		case SID_Right_Del:
			if (MEDIA_JRLY_STATE_STOP != g_jrlyinfo->mediastate)
			{	
				return;
			}
			if (g_jrlyinfo->rec_mem)
			{
				start_change_rightkey(hDlg);
				show_msg(hDlg, IDC_MSG_CTRL, MSG_QUERY, SID_Msg_Jrly_rec_tmp);
			}
			else
			{
				if (NULL != jrlylist && jrlylist->Count > 0 && g_jrlyinfo->index < jrlylist->Count && g_jrlyinfo->index != -1)
				{
					start_change_rightkey(hDlg);
					show_msg(hDlg, IDC_MSG_CTRL, MSG_QUERY, SID_Bj_Query_Del_Rec_One);
				}
			}
			break;
			
		case BID_Right_Exit:
			if (MEDIA_JRLY_STATE_STOP == g_jrlyinfo->mediastate)
			{
				close_page();
			}
			break;
	}
}

/*************************************************
  Function:		jrlyrecordCommand
  Description: 	���˵���Ϣ������Ϣ����
  Input:		
  	1.win
  	2.wParam
  	3.lParam
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
static uint32 OnCommand(HWND hDlg , WPARAM wParam, LPARAM lParam)
{
	uint32 ret = ECHO_STORAGE_ERR;
	char filename[100];
	
	switch (wParam)
	{
		case IDC_RIGHT_BUTTON:
			RightCtrlCommand(hDlg, lParam);
			break;

		case IDC_LIST_CTRL:
			g_jrlyinfo->index = lParam;
			break;
		
		case IDC_MSG_CTRL:
			if (MSG_EVENT_YES != lParam)
			{
				return TRUE;
			}
			
			if (g_jrlyinfo->rec_mem)
			{
				g_jrlyinfo->rec_mem = 0;
				FSFileDelete(get_jrlyrecord_path(filename,&g_jrlyinfo->time));
				Change_Right_Image();
				show_msg(hDlg, IDC_MSG_CTRL, MSG_INFORMATION, SID_Oper_OK);
				
			}
			else
			{
				
				ret = storage_del_jrlyrecord(g_jrlyinfo->index);
				if (ECHO_STORAGE_OK == ret)
				{	
					sys_sync_hint_state();
					SendMessage(g_listwin, WM_List_Del_Item, 0, 0);
					if (jrlylist)
					{
						storage_free_jrly_memory(&jrlylist);	
						jrlylist = NULL;
					}
					storage_get_jrlyrecord(&jrlylist);
					show_msg(hDlg, IDC_MSG_CTRL, MSG_INFORMATION, SID_Oper_OK);
				}
				else
				{
					show_msg(hDlg, IDC_MSG_CTRL, MSG_INFORMATION, SID_Oper_ERR);
				}
			}
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
	memset(&g_listCtrl, 0, sizeof(LISTCTRL_INFO));
	g_listCtrl.Parent = hDlg;
	g_listCtrl.Mode = LIST_MODE_LIGHT;				// ̧���ͷţ��и�����ʾ
	g_listCtrl.Caption = 0;							// �Ƿ��б�����
	g_listCtrl.PageCount = 5;						// ��ʾ����
	g_listCtrl.Sidebar = 0;							// �����
	g_listCtrl.SideBarMode = 0;
	g_listCtrl.fonttype = Font16X16;				// ������ʾ��С
	g_listCtrl.ImageTopBk = BID_ListCtrl_TopBK5_0;
	g_listCtrl.ImageBk = BID_ListCtrl_BK5_0;
	g_listCtrl.HeadInfo.Image = 0;
	g_listCtrl.HeadInfo.TextID = 0;
	g_listCtrl.Width[0] = 100;
	g_listCtrl.Width[1] = 300;

	g_listwin = CreateWindow(AU_LIST_CTRL, "", 
	 		 WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
			 IDC_LIST_CTRL, 
			 LIST_CTRL_X, LIST_CTRL_Y, LIST_CTRL_W, LIST_CTRL_H, 
			 hDlg, (DWORD)&g_listCtrl);	
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
	uint32 ImageID[RIGHT_NUM_MAX] = {0, 0, BID_Right_Table, 0,  BID_Right_Exit};
	uint32 TextID[RIGHT_NUM_MAX] = {SID_Right_Rec, SID_Right_Del, 0 ,SID_Right_Play, 0};
	
	memset(&g_rightCtrl, 0, sizeof(RIGHTCTRL_INFO));
	g_rightCtrl.parent = hDlg;
	g_rightCtrl.VideoMode = 0;
	g_rightCtrl.MaxNum = RIGHT_NUM_MAX;
	g_rightCtrl.BmpBk = BID_RightCtrlBK;
	g_rightCtrl.TextSize = Font16X16;

	for(i = 0; i < g_rightCtrl.MaxNum; i++)
	{
		g_rightCtrl.buttons[i].Enabled = TRUE;
		g_rightCtrl.buttons[i].TextID = TextID[i];
		g_rightCtrl.buttons[i].ImageID = ImageID[i];
	}
	
	g_RightWin = CreateWindow(AU_RIGHT_BUTTON, "", 
							WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
							IDC_RIGHT_BUTTON, 
							RIGHT_CTRL_X, RIGHT_CTRL_Y, RIGHT_CTRL_W, RIGHT_CTRL_H, 
							hDlg, (DWORD)&g_rightCtrl);

	init_key();
}

/*************************************************
  Function:		CreateProcCtrl
  Description: 	��ʼ�����ȿؼ�
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
static void CreateProcCtrl(HWND hDlg)
{
	memset(&g_ProcCtrl,0,sizeof(PROCRESS_CTRL));
	g_ProcCtrl.allproc = 100;
	g_ProcCtrl.proc = 0;
	g_ProcCtrl.ImageBK = BID_Proc2_Bk;
	g_ProcCtrl.Image[0] = BID_Proc2_Left;
	g_ProcCtrl.Image[1] = BID_Proc2_Right;
	g_ProcCtrl.ImageProc = BID_Proc2_On;	
	
	g_procwin = CreateWindow(AU_PROC_CTRL, "", 
							WS_VISIBLE | BS_NOTIFY | BS_DEFPUSHBUTTON, 
							IDC_PROC_CTRL, 
							PROC_XPOS, PROC_YPOS,PROC_W,PROC_H, 
							hDlg, (DWORD)&g_ProcCtrl);
}

/*************************************************
  Function:		ui_jrlyrecord_win
  Description: 	��������
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �ɹ� FALSE ʧ��
  Others:		
*************************************************/
uint32 ui_jrlyrecord_win(HWND hDlg)
{
	OnPaintBack(hDlg);
	if (g_jrlyinfo)
	{
		free(g_jrlyinfo);
		g_jrlyinfo = NULL;
	}

	if (jrlylist)
	{
		storage_free_jrly_memory(&jrlylist);	
	}
	g_jrlyinfo = (PMEDIA_JRLY_INFO)malloc(sizeof(MEDIA_JRLY_INFO));
	if (NULL == g_jrlyinfo)
	{
		return FALSE;
	}
	memset(g_jrlyinfo,0,sizeof(MEDIA_JRLY_INFO));
	g_jrlyinfo->mediastate = MEDIA_JRLY_STATE_STOP;
	g_jrlyinfo->index = -1;
	form_show(&FormSetjrlyrecord);
	show_win();
	Change_Right_Image();
	
	return TRUE;
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
	CreateProcCtrl(hDlg);
	CreateRightCtrl(hDlg);
	CreateListCtrl(hDlg);
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
                SendMessage(g_procwin, WM_Procress_Set_Proc, 0, 0);
            }
            else
            {
                close_page();
            }
			break;
			
		case MSG_PAINT:
			OnPaint(hDlg);
			return 0;

	    case MSG_KEYDOWN:
			SendMessage(g_RightWin, MSG_KEYDOWN, wParam, lParam);
        	break;

		case MSG_KEYUP:
			SendMessage(g_RightWin, MSG_KEYUP, wParam, lParam);
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
			jrlyrecordDestroyProc();
			return 0;
	}
	
	return DefaultMsgProc(self, hDlg, message, wParam, lParam);
}
#endif

