/*********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	ui_list_ctrl.h
  Author:   	yanjl
  Version:   	1.0
  Date: 		2014-11-12
  Description:  �б�ؼ�ͷ�ļ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __UILISTCTRL_H__
#define __UILISTCTRL_H__

#if (_LCD_DPI_ == _LCD_800480_)
//#define LIST_ITEM_H				84					// �б����
//#define LIST_ITEM_W				640

#define TOP_TEXT_SIZE			200
//#define TOP_IMAMG_H				52

//#define LEFT_ICON_H				40					// �б�������Сͼ���
//#define LEFT_ICON_W				40			
#define LEFT_ICON_DIS_X			40					// �б�������Сͼ����ʼ���		

//#define RIGHT_ICON_H			16					// �б�����ұ�Сͼ���
//#define RIGHT_ICON_W			16
#define RIGHT_ICON_DIS_X		15
#elif (_LCD_DPI_ == _LCD_1024600_)
#define TOP_TEXT_SIZE			250	
#define LEFT_ICON_DIS_X			50					// �б�������Сͼ����ʼ���		
#define RIGHT_ICON_DIS_X		19
#endif

#define KEYDOWN  				1
#define KEYUP  					0
#define MAX_LIST_ITEM			5
#define CHAR_SIZE				50
#define ITEM_SIZE				4
#define LIST_KEY_OK				1

typedef enum
{
	LIST_MODE_COMMON = 0x00,						// ��ͨ��ʾ 
	LIST_MODE_LIGHT									// ������ʾ  ����ͼ���б仯
}LIST_MODE;										

typedef enum
{
	STYLE_CENTER = 0x00,							// �м�
    STYLE_LEFT, 									// ����
    STYLE_RIGHT		      							// ����
}SHOW_STYLE;										// ��ʾ���

typedef enum
{
	CHECK_IMAGE = 0x00,								// �鿴ͼƬ 
	CHECK_ICON,										// �鿴Сͼ��
	CHECK_TEXTID,									// �鿴����ID
	CHECK_CHAR,										// �鿴�����ַ���
	CHECK_WCHAR,									// �鿴WCHAR�����ַ���
	CHECK_HEAD_TEXTID,								// �鿴���������ID
	CHECK_HEAD_CHAR,								// �鿴������ַ���
	CHECK_HEAD_WCHAR								// �鿴������ַ���	
}CHECK_TYPE;	

typedef enum
{
	SIDEBARICON_NONE,
	SIDEBARICON_DOWNON,
	SIDEBARICON_UPON,
	SIDEBARICON_BOTH
}SIDEBARICON_ON;

typedef struct 
{
	SHOW_STYLE ShowType;							// ��ʾ���
	uint16 Width;									// ���
	uint16 Change;									// ͼ���Ƿ�Ҫ�仯
	uint32 TextID;									// ����ID
	uint32 Image;									// β��Сͼ��
	char Text[CHAR_SIZE];							// �����ַ�
	uint16 WText[CHAR_SIZE];							// �����ַ�
}LISTONE_INFO, * PLISTONE_INFO;

typedef struct 
{
	uint8 Enabled;									// ʹ��
	uint8 Num;										// ���и���
	uint32 Icon;									// β��Сͼ��
	//COLOR color;									// ����������ɫ
	LISTONE_INFO Item[ITEM_SIZE];					// ������
}LISTITEM_INFO, * PLISTITEM_INFO;

//typedef void(*SidebarCallBack)(HWND hDlg, uint32 H, uint32 x, uint32 y, uint8 allpage, uint8 page, uint8 mode, uint8 keystate, uint8 select);
typedef void(*SidebarCallBack)(HWND hDlg, uint32 H, uint32 x, uint32 y, uint8 allpage, uint8 pageCount, uint8 Count, uint8 keystate, uint8 select, uint32 curSelect);
typedef uint8(*SidebarKeyCallBack)(uint32 H, uint8 mode, uint32 x, uint32 y);

typedef struct 
{
	HWND Parent;									// ������ID
	LIST_MODE Mode;									// �б���ʾ
	uint8 Caption;									// �Ƿ��б��� 0û�� 1��
	uint8 SideBarMode;								// �������ģʽ ����Ϊ0 �̵�Ϊ1
	uint8 KeyMode;									// mode 0 Ҫ��ȷ��
	uint8 Sidebar;									// �Ƿ������±� 0û�� 1��
	uint32 SidebarW;								// ���
	int8 SidebarSel;  							    // �����ѡ���ĸ�
	SIDEBARICON_ON SidebarState;					// ����״̬
	uint8 keystate;									// ����״̬
	uint16 Width[MAX_LIST_ITEM];					// ���
	uint16 Count;									// �б�������
	int16 Select;									// ѡ����
	uint8 AllPage;									// ��ҳ��
	uint8 Page;										// ��ǰҳ
	uint8 PageCount;								// ��ҳ���ٸ�������
	uint8 MoveSelect;								// �ƶ���ѡ��
	uint32 ImageBk;								// ����ͼƬ
	uint32 ImageTopBk;							// ͷһ�ű���ͼƬ
	FontType fonttype;								// ���� 
	//COLOR HeadTextColor;							// �б�ͷ���ֵ���ɫ(���ַ�����Ч)
	LISTONE_INFO HeadInfo;							// �б�ͷ��Ϣ
	SidebarCallBack Drawcallback;					// �����ʵ�ֻص�
	SidebarKeyCallBack KeyCallBack;					// ����������ж�ʵ�ֻص�	
	UILIST 	*ListList;   							// �б�
}LISTCTRL_INFO, * PLISTCTRL_INFO;

typedef struct 
{
	CHECK_TYPE Check;								// �鿴ʲô����
	uint16 Select;									// ��ǰ��
	uint8 index;									// Ҫ�޸ĵĵڼ���
	uint32 Icon;									// β��Сͼ��
	LISTONE_INFO Item;								// ������
}CHANGE_LIST, * PCHANGE_LIST;

/*************************************************
  Function:		set_list_text
  Description: 	����ĳ�������
  Input: 		
	1.hDlg		�ؼ����
	2.select	�ڼ���
	3.index		�ڼ���
	4.str		���ĵ��ַ���
	5.wstr		���ĵ��ַ���
	6.check		Ҫ���õ�����
  Output:		��
  Return:		��
  Others:
*************************************************/
void set_list_text(HWND hDlg, uint16 select, uint8 index, int32 TextID, char* str, uint16 *wstr, CHECK_TYPE check);

/*************************************************
  Function:		get_list_text
  Description: 	���ĳ�������
  Input: 		
	1.hDlg		�ؼ����
	2.select	�ڼ���
	3.index		�ڼ���
	4.str		���ĵ��ַ���
	5.check		Ҫ��ѯ������
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 get_list_text(HWND hDlg, uint16 select, uint8 index, char* str, CHECK_TYPE check);

/*************************************************
  Function:		set_list_Image
  Description: 	����ĳ���ͼƬ
  Input: 		
	1.hDlg		�ؼ����
	2.select	�ڼ���
	3.index		�ڼ���
	4.ImageID	ͼƬID
	5.check		Ҫ���õ�����
  Output:		��
  Return:		��
  Others:
*************************************************/
void set_list_Image(HWND hDlg, uint32 select, uint8 index, uint32 ImageID, CHECK_TYPE check);

/*************************************************
  Function:		get_list_Image
  Description: 	���ĳ���ͼƬ 
  Input: 		
	1.hDlg		�ؼ����
	2.select	�ڼ���
	3.index		�ڼ���
	4.str		���ĵ��ַ���
	5.check		Ҫ��ѯ������
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 get_list_Image(HWND hDlg, uint16 select, uint8 index, CHECK_TYPE check);
#endif

