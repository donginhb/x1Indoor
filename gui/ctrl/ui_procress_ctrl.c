/*********************************************************
  Copyright (C), 2009-2012
  File name:	ui_procress_ctrl.c
  Author:   	zhengxc
  Version:   	1.0
  Date: 		15.7.15
  Description:  ���ȿؼ�
  History:            
*********************************************************/

#include "gui_include.h"

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

/*************************************************
  Function:		procctrlPaint
  Description: 	��ť������Ϣ
  Input:		
  	1.win		����
  	2.wParam	����1
  	3.lParam 	����2
  Output:		��
  Return:		��
  Others:
*************************************************/
static void ui_procctrl_paint(HDC hdc, RECT * rc, PPROCRESS_CTRL WButObj)
{
	int endpos, startpos, oper;
	PBITMAP bmpBK = NULL;
	uint32 bmpW[2];
	uint32 bmpProcW;
	
	bmpBK = get_bmp(WButObj->ImageBK);
	bmpW[0] = get_bmp(WButObj->Image[0])->bmWidth;
	bmpW[1] = get_bmp(WButObj->Image[1])->bmWidth;
	bmpProcW = get_bmp(WButObj->ImageProc)->bmWidth;	
	
	DrawBmpID(hdc, 0, 0, bmpBK->bmWidth, bmpBK->bmHeight, WButObj->ImageBK);
	if (WButObj->allproc > 0)
	{
		if ((WButObj->proc > 0)&&(WButObj->proc <= WButObj->allproc))
		{
			if (1 == WButObj->proc)
			{
				DrawBmpID(hdc, 0, 0, bmpW[0], bmpBK->bmHeight, WButObj->Image[0]);
			}
			else
			{
				endpos = bmpW[0] + ((bmpBK->bmWidth - bmpW[0] - bmpW[1]) * WButObj->proc) / WButObj->allproc;
				DrawBmpID(hdc, 0, 0, bmpW[0], bmpBK->bmHeight, WButObj->Image[0]);
				oper = TRUE;
				startpos = bmpW[0];
				while(oper)
				{
					startpos += bmpProcW;
					if (startpos < endpos)
					{
						DrawBmpID(hdc, (startpos - bmpProcW), 0, bmpProcW, bmpBK->bmHeight, WButObj->ImageProc); 	
					}
					else
					{
						startpos = endpos - bmpProcW;
						DrawBmpID(hdc, startpos, 0, bmpProcW, bmpBK->bmHeight, WButObj->ImageProc); 
						oper = FALSE;
					}
				}
				DrawBmpID(hdc, endpos, 0, endpos + bmpW[1], bmpBK->bmHeight, WButObj->Image[1]); 
			}
		}
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
	PLISTCTRL_INFO WObj = (PLISTCTRL_INFO)GetWindowAdditionalData(hDlg);
	if (NULL == WObj)
	{
		log_printf("WButObj is NULL!!!");
		return;
	}
	
	hdc = BeginPaint(hDlg);
	GetClientRect(hDlg, &rc);  	
	SetBkMode(hdc, BM_TRANSPARENT);
	//SetBrushColor(hdc, PAGE_BK_COLOR);
	//FillBox(hdc, rc.left, rc.top, rc.right, rc.bottom);
	ui_procctrl_paint(hdc, &rc, WObj);
	EndPaint(hDlg, hdc);
}

/*************************************************
  Function:		ui_set_proc
  Description: 	
  Input:		
  	1.win		����
  	2.wParam	����1
  	3.lParam	PPROCRESS_CTRL �ṹ
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_proc(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PPROCRESS_CTRL WButObj = (PPROCRESS_CTRL)GetWindowAdditionalData(hDlg);
	if (WButObj && WButObj->proc != wParam)
	{
		WButObj->proc = wParam;		
		ui_reflash_ctrl(hDlg, wParam, lParam);
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:		ui_set_allproc
  Description: 	
  Input:		
  	1.win		����
  	2.wParam	����1
  	3.lParam	PPROCRESS_CTRL �ṹ
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_set_allproc(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PPROCRESS_CTRL WButObj = (PPROCRESS_CTRL)GetWindowAdditionalData(hDlg);
	if (WButObj && WButObj->allproc != wParam)
	{
		WButObj->allproc = wParam;
		ui_reflash_ctrl(hDlg, wParam, lParam);
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:		ui_procctrl_creat
  Description: 	�ؼ�����
  Input:		
  	1.win		����
  	2.wParam	����1
  	3.lParam	PPROCRESS_CTRL �ṹ
  Output:		��
  Return:		��
  Others:
*************************************************/
static uint32 ui_procctrl_creat(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PPROCRESS_CTRL WObj = (PPROCRESS_CTRL)GetWindowAdditionalData(hDlg);

	if (NULL == WObj)
	{
	    return FALSE;
	}
	
	WObj->proc = NULL;
	ui_reflash_ctrl(hDlg, wParam, lParam);
	
	return TRUE;
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
	switch (message)
	{
		case MSG_CREATE:
			ui_procctrl_creat(hDlg, wParam, lParam);
			break;

		case MSG_INITDIALOG:
			SetWindowBkColor(hDlg, PAGE_BK_COLOR);
			break;	
			
		case MSG_PAINT:
			OnPaint(hDlg);
			break;

		case WM_Procress_Set_Proc:
			ui_set_proc(hDlg, wParam, lParam);
			break;

		case WM_Procress_Set_Allproc:
			 ui_set_allproc(hDlg, wParam, lParam);
			 break;
	}

	return DefaultControlProc(hDlg, message, wParam, lParam);
}	

/*************************************************
  Function:			register_procress_ctrl
  Description: 		ע����ȿؼ�
  Input: 		
	1.void			��
  Output:			��
  Return:			��
  Others:
*************************************************/
BOOL register_procress_ctrl(void)
{
	WNDCLASS MyClass;

	MyClass.spClassName = AU_PROC_CTRL;
	MyClass.dwStyle = WS_NONE;
	MyClass.dwExStyle = WS_EX_NONE;
	MyClass.hCursor = GetSystemCursor(IDC_ARROW);
	MyClass.iBkColor = COLOR_lightwhite;
	MyClass.WinProc = MyControlProc;
	
	return RegisterWindowClass(&MyClass);
}

/*************************************************
  Function:			unregister_procress_ctrl
  Description: 		ɾ�����ȿؼ�
  Input: 		
	1.void			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void unregister_procress_ctrl(void)
{
	UnregisterWindowClass(AU_PROC_CTRL);
}

