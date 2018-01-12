/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	ui_right_ctrl.c
  Author:     	luofl
  Version:    	2.0
  Date: 		2014-09-12
  Description:  
				�ұ߿ؼ�����
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
#include "gui_include.h"

#if (_LCD_DPI_ == _LCD_800480_)
#define ICON_TOPDISY			18
#define ICON_DISY				28
#define ICONBK_W				160
#define ICONBK_H				66
#define ICON_W					40
#define ICON_H					40

#define BK_BMP_W				160
#define BK_BMP_H				480
#elif (_LCD_DPI_ == _LCD_1024600_)
#define ICON_TOPDISY			6
#define ICON_DISY				6
#define ICONBK_W				100
#define ICONBK_H				48
#define ICON_W					28
#define ICON_H					28

#define BK_BMP_W				100
#define BK_BMP_H				272
#endif

//static PGUI_FORM frm = NULL;

static uint8 g_KeyFlag = 0;
static uint32 g_ClearBack = 0;

/*************************************************
  Function:		ui_reflash_ctrl
  Description: 	ˢ�¿ؼ�
  Input:	
  	1.hDlg		����
  	2.WButObj 	�ؼ��ṹ��		
  Output:		��
  Return:		��
  Others:
*************************************************/
static void ui_reflash_ctrl(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	InvalidateRect(hDlg, NULL, TRUE);
}

#if 0
/*************************************************
  Function:		ui_rightctrl_destroy
  Description: 	�ؼ�����
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_rightctrl_destroy(HWND hDlg , WPARAM wParam, LPARAM lParam)
{
    PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
    	free(WButObj);
		WButObj = NULL;
	}
	
    return TRUE;
}
#endif

/*************************************************
  Function:		ui_draw_rightctrl_bk
  Description: 	���ұ߿ؼ�����
  Input:	
  	1.hdc		����
  	2.rect		����
  	3.WButObj 	�ؼ��ṹ��	
  Output:		��
  Return:		��
  Others:
*************************************************/
void ui_draw_rightctrl_bk(HDC hdc, RECT * rect, PRIGHTCTRL_INFO WButObj)
{	
	#if 0
	if (WButObj->proc != NULL)
	{
		WButObj->proc();
	}
	else
	{
		DrawBmpID(hdc, rect->left, rect->top, 0, 0, WButObj->BmpBk);
	}
	#else
	DrawBmpID(hdc, rect->left, rect->top, BK_BMP_W, BK_BMP_H, WButObj->BmpBk);
	#endif
}

/*************************************************
  Function:		ui_draw_rightctrl_button
  Description: 	���ұ߿ؼ�����
  Input:		
  	1.hDlg		����
  	2.rect		����
  	3.WButObj 	�ؼ��ṹ��		
  Output:		��
  Return:		��
  Others:
*************************************************/
void ui_draw_rightctrl_button(HDC hdc, RECT * rect, PRIGHTCTRL_INFO WButObj)
{
	RECT rc;
	uint32 bmpID;
	uint32 i, x, y;
	
	if (0 == WButObj->VideoMode)
	{
		//SetTranspColor(COLOR_TRANSPARE);
	}

	x = rect->left;
	y = rect->top + ICON_TOPDISY;
	for (i = 0; i < WButObj->MaxNum; i++)
	{
		bmpID = BID_RightButtonBK1;
		if (WButObj->holdmode)
		{
			if (WButObj->Index == i)
			{
				if (WButObj->buttons[i].Hold)
				{
					bmpID += 2;
				}
				else
				{
					bmpID += 1;
				}
			}
		}
		else
		{
			if (WButObj->state == KEYDOWN && WButObj->Index == i)
			{
				bmpID += 1;
			}
		}
		if (WButObj->buttons[i].ImageID)
		{
			DrawBmpID(hdc, x, y, ICONBK_W, ICONBK_H, bmpID);	// ������������
			DrawBmpID(hdc, x+(ICONBK_W-ICON_W)/2, y+(ICONBK_H-ICON_H)/2, ICON_W, ICON_H, WButObj->buttons[i].ImageID);		
		}
		else if (WButObj->buttons[i].TextID)
		{
			DrawBmpID(hdc, x, y, ICONBK_W, ICONBK_H, bmpID);								
			rc.left = x;
			rc.top = y +(ICONBK_H-WButObj->TextSize)/2 ;
			rc.right = ICONBK_W;
			rc.bottom = (y + ICONBK_H)-(ICONBK_H-WButObj->TextSize)/2;
			SetTextColor(hdc, COLOR_BUTTON_TEXT);
			SelectFont(hdc, GetFont(WButObj->TextSize));
			DrawText(hdc, get_str(WButObj->buttons[i].TextID), -1, &rc, DT_CENTER | DT_BOTTOM | DT_VCENTER);
		}
		
		y += ICON_DISY + ICONBK_H;
	}
}

#if 0
/*************************************************
  Function:		get_pos
  Description:  ��ȡ��ǰ�����ĸ�����
  Input:
  	1.hDlg		������
  	2.x			X����
  	3.y			Y����	
  Output:		��
  Return:		��
  Others:
*************************************************/
static int8 get_pos(HWND hDlg, PRIGHTCTRL_INFO WButObj, int x, int y)
{
	RECT rect;
	uint32 sy;
	uint32 index = -1;
	uint32 one_h = (WButObj->buttons[2].ImageH +WButObj->buttons[1].ImageH +WButObj->buttons[0].ImageH + ICON_DISY*2)/3;

	GetClientRect(hDlg, &rect);
	sy = y - rect.top;
	if (sy > (rect.bottom - WButObj->buttons[3].ImageH))
	{
		index = 3;
	}
	else
	{
		index = sy/one_h;
		if (index == 3)
		{
			index = -1;
		}
	}
	return index;
}

/*************************************************
  Function:		ui_rightctrl_touch
  Description: 	�������¼�
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_rightctrl_touch(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
    PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	PUHPOINT touchPoint = (PUHPOINT)lParam;

	switch(wParam)
	{
		case TM_STATE_DOWN:
			WButObj->Index = get_pos(hDlg, WButObj, touchPoint->x, touchPoint->y);
			if (4 == WButObj->Index)
			{
				sys_key_beep();
				WButObj->state = KEYDOWN;
				ui_reflash_ctrl(hDlg, wParam, lParam);
			}
			else
			{
				if (-1 != WButObj->Index && WButObj->buttons[WButObj->Index].Enabled 
					&& ((WButObj->buttons[WButObj->Index].ImageID > 0) || (WButObj->buttons[WButObj->Index].TextID > 0)))
				{
					sys_key_beep();
					WButObj->state = KEYDOWN;
					ui_reflash_ctrl(hDlg, wParam, lParam);
					#if 0
					if (WButObj->VideoMode)
					{
						WindowSendMessage(hDlg->Parent, WM_COMMAND, ((UINT32)(hDlg->id)) << 16 | WButObj->Index, &(WButObj->state));
					}	
					#endif
				}
			}
			break;

		case TM_STATE_UP:
			if (KEYDOWN == WButObj->state)
	    	{
	    		WButObj->state = KEYUP;
				ui_reflash_ctrl(hDlg, wParam, lParam);
				WindowSendMessage(hDlg->Parent, WM_COMMAND, ((UINT32)(hDlg->id)) << 16 | WButObj->Index, &(WButObj->state));
	    	}
			break;
	}
	return TRUE;
}

/*************************************************
  Function:		get_touch_up
  Description:  ������̧��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void get_touch_up(HWND hDlg, WPARAM wParam, LPARAM lParam,PRIGHTCTRL_INFO pData)
{
	return;
}

/*************************************************
  Function:		get_touch_down
  Description:  ����������
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void get_touch_down(HWND hDlg, WPARAM wParam, LPARAM lParam, PRIGHTCTRL_INFO pData)
{
	return;
}
#endif

/*************************************************
  Function:		ui_set_textlen
  Description:  �������ֳ���
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_textlen(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uint32 index;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		index = (uint32)wParam;
		if (index < RIGHT_NUM_MAX)
		{
			WButObj->buttons[index].TextLen = (uint8)lParam;
			ui_reflash_ctrl(hDlg, wParam, lParam);
			return TRUE;
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_set_textID
  Description:  ��������ID
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_textID(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uint32 index, i;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	uint32 * Data;

	if (WButObj)
	{
		index = (uint32)wParam;
		if (0xFF == index)
		{
			Data = (uint32*)lParam;
			for (i = 0; i < RIGHT_NUM_MAX; i++)
			{
				WButObj->buttons[i].TextID = Data[i];
			}
			ui_reflash_ctrl(hDlg, wParam, lParam);
			return TRUE;
		}
		else
		{
			if ((index < RIGHT_NUM_MAX) && (WButObj->buttons[index].TextID != (uint16)lParam))
			{	
				WButObj->buttons[index].ImageID= 0;
				WButObj->buttons[index].TextID = (uint32)lParam;
				ui_reflash_ctrl(hDlg, wParam, lParam);
				return TRUE;
			}
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_get_textID
  Description:  ��ȡ����ID
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_get_textID(HWND hDlg ,  WPARAM wParam, LPARAM lParam)
{
	uint32 index;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		index = (uint32)wParam;
		if (index < RIGHT_NUM_MAX)
		{
			return WButObj->buttons[index].TextID;
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_set_Image
  Description:  ����ͼƬID
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_image(HWND hDlg,  WPARAM wParam, LPARAM lParam)
{
	uint32 index,i;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	uint32 * Data;
	
	if (WButObj)
	{
		index = (uint32)wParam;
		if (0xFF == index)
		{
			Data = (uint32*)lParam;
			for (i = 0; i < RIGHT_NUM_MAX; i++)
			{
				WButObj->buttons[i].ImageID = Data[i];
			}
			ui_reflash_ctrl(hDlg, wParam, lParam);
			return TRUE;
		}
		else
		{
			if ((index < RIGHT_NUM_MAX) && (WButObj->buttons[index].ImageID != (uint32)lParam))
			{
				WButObj->buttons[index].TextID = 0;
				WButObj->buttons[index].ImageID = (uint32)lParam;
				ui_reflash_ctrl(hDlg, wParam, lParam);
				return TRUE;
			}
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_get_Image
  Description:  ��ȡͼƬID
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_get_image(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uint32 index;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		index = (uint32)wParam;
		if (index < RIGHT_NUM_MAX)
		{
			return WButObj->buttons[index].ImageID;
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_get_Image
  Description:  ��ȡͼƬ������ID
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_get_imageortextID(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uint32 index;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		index = (uint32)wParam;
		if (index < RIGHT_NUM_MAX)
		{
			if (WButObj->buttons[index].TextID)
			{
				return WButObj->buttons[index].TextID;
			}
			else
			{
				return WButObj->buttons[index].ImageID;
			}	
		}
	}
	
	return FALSE;
}

/*************************************************
  Function:		ui_set_enable
  Description:  ����ʹ��
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_enable(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uint32 index, i;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		index = wParam;
		if (0xFF == index)
		{
			for (i = 0; i < RIGHT_NUM_MAX; i++)
			{
				WButObj->buttons[i].Enabled = (uint8)lParam;
			}
		}
		else
		{	
			if (index < RIGHT_NUM_MAX && WButObj->buttons[index].Enabled != (uint8)lParam)
			{
				WButObj->buttons[index].Enabled = (uint8)lParam;
				ui_reflash_ctrl(hDlg, wParam, lParam);
			}
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_get_enable
  Description:  ��ȡʹ��
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_get_enable(HWND hDlg ,  WPARAM wParam, LPARAM lParam)
{
	uint32 index;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		index = (uint32)wParam;
		if (index < RIGHT_NUM_MAX)
		{
			return WButObj->buttons[index].Enabled;
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_set_video_mode
  Description:  ������Ƶ״̬
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_video_mode(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		if (WButObj->VideoMode != (uint8)wParam)
		{
			WButObj->VideoMode = (uint8)wParam;
			ui_reflash_ctrl(hDlg, wParam, lParam);
			return TRUE;
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_get_video_mode
  Description:  ��ȡ��Ƶ
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint8 ui_get_video_mode(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		if (WButObj->VideoMode != (uint8)wParam)
		{
			return WButObj->VideoMode;
		}
	}
	
	return TRUE;
}

/*************************************************
  Function:		ui_get_select
  Description:  ��ȡ��ǰѡ����
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static int32 ui_get_select(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		return WButObj->Index;
	}
	else
	{
		return -1;
	}
}

/*************************************************
  Function:		ui_set_select
  Description:  ���õ�ǰѡ����
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_select(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj && WButObj->Index != (uint8)wParam && (uint8)wParam < WButObj->MaxNum)
	{
		WButObj->Index = (uint8)wParam;
		ui_reflash_ctrl(hDlg, wParam, lParam);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*************************************************
  Function:		ui_add_win
  Description:  ��Ӵ�����Ϣ
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_add_win(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	PWIN_MSG info = (PWIN_MSG)lParam;

	if (WButObj && (uint8)wParam < RIGHT_KEY_MAX && NULL != info)
	{
		if (WButObj->wininfo[wParam].count < KEY_WINMAX)
		{
			WButObj->wininfo[wParam].button[WButObj->wininfo[wParam].count].hDlg = info->hDlg;
			WButObj->wininfo[wParam].button[WButObj->wininfo[wParam].count].iMsg = info->iMsg;
			WButObj->wininfo[wParam].button[WButObj->wininfo[wParam].count].wParam = info->wParam;
			WButObj->wininfo[wParam].button[WButObj->wininfo[wParam].count].lParam = info->lParam;
			WButObj->wininfo[wParam].count += 1;	
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*************************************************
  Function:		ui_clear_win
  Description:  ���������Ϣ
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_clear_win(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	int i;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);

	if (WButObj && (uint8)wParam < RIGHT_KEY_MAX)
	{
		for (i = 0; i < KEY_WINMAX; i++)
		{
			WButObj->wininfo[wParam].button[i].hDlg = 0;
			WButObj->wininfo[wParam].button[i].iMsg = 0;
			WButObj->wininfo[wParam].button[i].wParam = 0;
			WButObj->wininfo[wParam].button[i].lParam = 0;
		}
		WButObj->wininfo[wParam].count = 0;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*************************************************
  Function:		ui_rightctrl_defaultkey
  Description:  
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_rightctrl_defaultkey(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		if (WButObj->buttons[wParam].TextID > 0 || WButObj->buttons[wParam].ImageID > 0)
		{
			WButObj->state = KEYUP;
			SendMessage(WButObj->parent, MSG_COMMAND, IDC_RIGHT_BUTTON, wParam);
		}
		return TRUE;
	}

	return FALSE;
}

/*************************************************
  Function:		get_key_down
  Description:  �������´���
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 get_key_down(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	int index = -1;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	// ��ֹ��������������������������
	hw_clr_monitor_dog();

	switch (wParam)
	{
		case SCANCODE_F1:
		case SCANCODE_F2:
		case SCANCODE_F3:
		case SCANCODE_F4: 
		case SCANCODE_F5:
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			{
				if (SCANCODE_F1 == wParam)
				{
					index = 0;
				}
				else
				{
					index = wParam - SCANCODE_F2+1;
				}
			}
			#else
			{
				index = wParam - SCANCODE_F1;
			}
			#endif
			if (WButObj->buttons[index].TextID > 0 || WButObj->buttons[index].ImageID > 0)
			{
				WButObj->Index = index;
				WButObj->state = KEYDOWN;
				sys_key_beep();
				ui_reflash_ctrl(hDlg, wParam, lParam);
			}
			break;

		case TK_CENTER:
		case TK_MONITOR:
			sys_key_beep();
			break;
			
		default:
			break;
	}

	return TRUE;
}

/*************************************************
  Function: 	get_key_up
  Description:	����̧����
  Input:		
	1.hDlg		����
	2.wParam	����1
	3.lParam	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 get_key_up(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	int i, ret = 0;
	int index = -1;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);

	log_printf("%s  wParam %d\n", __FUNCTION__, wParam);
	switch(wParam)
	{
		case SCANCODE_F1:
		case SCANCODE_F2:
		case SCANCODE_F3:
		case SCANCODE_F4: 
		case SCANCODE_F5:
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			{
				if (SCANCODE_F1 == wParam)
				{
					index = 0;
				}
				else
				{
					index = wParam - SCANCODE_F2+1;
				}
			}
			#else
			{
				index = wParam - SCANCODE_F1;
			}
			#endif
			if (WButObj)
			{
				if (WButObj->wininfo[index].count > 0)
				{
					for (i = 0; i < WButObj->wininfo[index].count; i++)
					{
						if (WButObj->wininfo[index].button[i].hDlg != 0)
						{
							ret = SendMessage(WButObj->wininfo[index].button[i].hDlg, 
								WButObj->wininfo[index].button[i].iMsg,
								WButObj->wininfo[index].button[i].wParam, 
								WButObj->wininfo[index].button[i].lParam);
							if (ret)
							{
								break;
							}
						}
					}
				}

				//log_printf("ret = %d\n",ret);
				if (0 == ret)
				{
					ret = ui_rightctrl_defaultkey(hDlg, index, 0);
				}
				else
				{
					WButObj->state = KEYUP;
				}
				ui_reflash_ctrl(hDlg, wParam, lParam);
			}
			break;

		case TK_CENTER:	
			// ��������
			#if 0
			frm = get_cur_form();
			if (FrmMain.hWnd != frm->hWnd)
			{
				back_main_page();
			}
			#endif
			{
				char no[10] = {0};

				log_printf("call cneter!\n");
				sprintf(no, "%d", MANAGER_NUM+1);
				ui_callout_appstart(DEVICE_TYPE_MANAGER, no);
			}
			break;
			
		case TK_MONITOR:
			// �����ݿ�
			#if 0
			frm = get_cur_form();
			if (FrmMain.hWnd != frm->hWnd)
			{
				back_main_page();
			}
			#endif
			{
				PMONITORINFO info = NULL;
				PGUI_FORM frm = get_cur_form();
				
				log_printf("monitor!\n");
				info = storage_get_monitorinfo(DEVICE_TYPE_STAIR, 0);
				if (info == NULL)
				{
					ui_monitor_list_appstart(DEVICE_TYPE_STAIR);
				}
				else
				{
					if (FrmMonitor.hWnd)
					{	
						// add by caogw 2016-04-25 ��ֹ�����ڹرս���ʱ������ݼ�����洴�����������
						if (FrmMonitor.hWnd != frm->hWnd)
						{
							ui_monitor_appstart(DEVICE_TYPE_STAIR, 0);
						}
						else
						{
							log_printf("can not monitor!!!\n");
						}
					}
					else
					{
						ui_monitor_appstart(DEVICE_TYPE_STAIR, 0);
					}
				}
				//ui_monitor_appstart(DEVICE_TYPE_STAIR, 0);
			}
			break;
			
		default:
			break;
	}

	return ret;
}

/*************************************************
  Function:		add_rightctrl_win
  Description: 	��Ӵ���
  Input:		
  	1.Parent	����
  	2.hDlg		����
  	3.wParam	����1
  	4.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
void add_rightctrl_win(HWND Parent, int Index, HWND hDlg, int msg, WPARAM wParam, LPARAM lParam)
{
	WIN_MSG msginfo;
	
	msginfo.hDlg = hDlg;
	msginfo.iMsg = msg;
	msginfo.wParam = wParam;
	msginfo.lParam = lParam;
	SendMessage(Parent, WM_Right_Add_Win, Index, (LPARAM)&msginfo);
}

/*************************************************
  Function:		add_rightctrl_proc
  Description: 	
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
void add_rightctrl_proc(HWND hDlg , RightbarCallBack proc)
{
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj)
	{
		WButObj->proc = proc;
	}
}

/*************************************************
  Function:		change_rightctrl_allimagetext
  Description: 	
  Input:		
  	1.hDlg		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
void change_rightctrl_allimagetext(HWND hDlg , uint32 * BmpID, uint32 * StrID)
{
	uint8 i;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (WButObj && StrID && BmpID)
	{
		for (i = 0; i < RIGHT_NUM_MAX; i++)
		{
			WButObj->buttons[i].ImageID = BmpID[i];
			WButObj->buttons[i].TextID = StrID[i];
		}
		ui_reflash_ctrl(hDlg, 0, 0);
	}
}

/*************************************************
  Function:		create_ctrls
  Description: 	�����ؼ�
  Input: 		
	1.hDlg		���ھ��
	2.pData		��������
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint8 create_ctrls(HWND hDlg, WPARAM wParam, LPARAM lParam)	
{
	uint8 i, j;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);

	if (NULL == WButObj)
	{
		return FALSE;
	}

	WButObj->proc = NULL;
	for (i = 0; i < (RIGHT_NUM_MAX+1); i++)
	{
		WButObj->wininfo[i].count = 0;
		for (j = 0 ; j < KEY_WINMAX; j++)
		{
			WButObj->wininfo[i].button[j].hDlg = 0;
			WButObj->wininfo[i].button[j].iMsg = 0;
			WButObj->wininfo[i].button[j].wParam = 0;
			WButObj->wininfo[i].button[j].lParam = 0;
		}
	}
	ui_reflash_ctrl(hDlg, wParam, lParam);
	
	return TRUE;
}

/*************************************************
  Function:			draw_ctrls
  Description: 		���ؼ�
  Input: 		
	1.hDlg			���ھ��
	2.pData			��������		
  Output:			��
  Return:			��
  Others:
*************************************************/
static void draw_ctrls(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	PRIGHTCTRL_INFO WButObj = (PRIGHTCTRL_INFO)GetWindowAdditionalData(hDlg);
	
	if (NULL == WButObj)
	{
		log_printf("WButObj is NULL!!!");
		return;
	}

	HDC hdc = BeginPaint(hDlg);
	GetClientRect(hDlg, &rect);  	
	SetBkMode(hdc, BM_TRANSPARENT);
	if (!g_ClearBack)
	{
		ui_draw_rightctrl_bk(hdc, &rect, WButObj);
		ui_draw_rightctrl_button(hdc, &rect, WButObj);
	}
	else
	{
		DrawBmpID(hdc, rect.left, rect.top, BK_BMP_W, BK_BMP_H, BID_Inter_VideoWinBK4);
	}
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:			MyControlProc
  Description: 		������Ϣ������
  Input: 		
	1.hDlg			���
	2.message		��Ϣ����
	3.wParam		��������
	4.lParam		��������
  Output:			��
  Return:			��
  Others:
*************************************************/
static int MyControlProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{	
	#if 0
	if (message != MSG_IDLE)
	{
		log_printf("---MyControlProc--- %x\n\n", message);
	}
	#endif
	
	switch (message)
	{
		case MSG_CREATE:
			create_ctrls(hDlg, wParam, lParam);
			break;

		case MSG_INITDIALOG:
			SetWindowBkColor(hDlg, PAGE_BK_COLOR);
			break;	
			
		case MSG_PAINT:
			draw_ctrls(hDlg, wParam, lParam);
			break;
		
		#ifdef _ENABLE_TOUCH_
		case MSG_LBUTTONDOWN:
			if (GetCapture() == hDlg)
			{
				break;
			}
			SetCapture(hDlg);
    		get_touch_down(hDlg, LOWORD(lParam), HIWORD(lParam), pData);
   			break;
   			
	    case MSG_LBUTTONUP:
	    	if (GetCapture() != hDlg)
			{
				break;
			}
			ReleaseCapture();
	        get_touch_up(hDlg, LOWORD(lParam), HIWORD(lParam), pData);
	        break;
		#endif

		case MSG_KEYDOWN:
			SetScreenTimer();
			if (g_LcdState == SYS_LCD_OPEN)
			{
				if (!g_KeyFlag)
				{
					g_KeyFlag = 1;
					get_key_down(hDlg, wParam, lParam);
					ui_reflash_ctrl(hDlg, wParam, lParam);
				}
			}
			break;
			
		case MSG_KEYUP:
			if (g_LcdState == SYS_LCD_CLOSE)
			{
				log_printf("ui_right_ctrl.c open lcd\n");
				sys_open_lcd();
				SendMessage(FrmMain.hWnd, WM_RELOAD, 0, 0);
			}
			else
			{
				g_KeyFlag = 0;
				get_key_up(hDlg, wParam, lParam);
				ui_reflash_ctrl(hDlg, wParam, lParam);
			}
        	break;

		case WM_Right_Set_TextLen:
			ui_set_textlen(hDlg, wParam, lParam);
			break;
			
		case WM_Right_Set_TextID:
			ui_set_textID(hDlg, wParam, lParam);
			break;

		case WM_Right_Get_TextID:
			return ui_get_textID(hDlg, wParam, lParam);
			break;

		case WM_Right_Set_Image:
			ui_set_image(hDlg, wParam, lParam);
			break;

		case WM_Right_Get_Image:
			return ui_get_image(hDlg, wParam, lParam);
			break;

		case WM_Right_Get_ImageOrTextID:
			return ui_get_imageortextID(hDlg, wParam, lParam);
			break;

		case WM_Right_Set_enable:
			ui_set_enable(hDlg, wParam, lParam);
			break;	

		case WM_Right_Get_enable:
			ui_get_enable(hDlg, wParam, lParam);
			break;

		case WM_Right_Set_VideoMode:
			ui_set_video_mode(hDlg, wParam, lParam);
			break;

		case WM_Right_Get_VideoMode:
			ui_get_video_mode(hDlg, wParam, lParam);
			break;

		case WM_Right_Set_Select:
			ui_set_select(hDlg, wParam, lParam);
			break;

		case WM_Right_Get_Select:
			ui_get_select(hDlg, wParam, lParam);
			break;

		case WM_Right_Add_Win:
			ui_add_win(hDlg, wParam, lParam);
			break;

		case WM_Right_Clear_Win:
			ui_clear_win(hDlg, wParam, lParam);
			break;

		case WM_Right_Query_Key:
			break;

		case WM_Right_Set_ALLImage:
			break;

		case WM_Right_Clear_BackGround:
			g_ClearBack = (uint32)lParam;
			break;

		case MSG_TIMER:
			break;
		
		case MSG_CLOSE:
			return 0;

		case MSG_DESTROY:
			g_ClearBack = 0;
			return 0;
	}

	return DefaultControlProc(hDlg, message, wParam, lParam);
}	

/*************************************************
  Function:			register_right_button
  Description: 		ע���ұ߿ؼ�
  Input: 		
	1.void			��
  Output:			��
  Return:			��
  Others:
*************************************************/
BOOL register_right_button(void)
{
	WNDCLASS MyClass;

	MyClass.spClassName = AU_RIGHT_BUTTON;
	MyClass.dwStyle = WS_NONE;
	MyClass.dwExStyle = WS_EX_NONE;
	MyClass.hCursor = GetSystemCursor(IDC_ARROW);
	MyClass.iBkColor = COLOR_black;
	MyClass.WinProc = MyControlProc;
	
	return RegisterWindowClass(&MyClass);
}

/*************************************************
  Function:			unregister_right_button
  Description: 		ɾ���ұ߿ؼ�
  Input: 		
	1.void			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void unregister_right_button(void)
{
	UnregisterWindowClass(AU_RIGHT_BUTTON);
}

