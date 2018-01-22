/*********************************************************
  Copyright (C), 2006-2010, Aurine
  File name:	au_model_func.h
  Author:   	������
  Version:   	2.0
  Date: 		08.3.26
  Description:  ��������ͷ�ļ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __AU_MODEL_FUNC_H__
#define __AU_MODEL_FUNC_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "gui_include.h"

#if (_LCD_DPI_ == _LCD_800480_)
#define SIDEBAR_W				80
#define SIDEBAR_H				428
#define SIDEBAR_DOWN_ICON_Y		389
#define SIDEBAR_ICON_W			30
#define SIDEBAR_ICON_H			70
#define SIDEBAR_YDIS			21
#define SIDEBAR_SCRLEN			384
#elif (_LCD_DPI_ == _LCD_1024600_)
#define SIDEBAR_W				102
#define SIDEBAR_H				535
#define SIDEBAR_DOWN_ICON_Y		496
#define SIDEBAR_ICON_W			36
#define SIDEBAR_ICON_H			87
#define SIDEBAR_YDIS			21
#define SIDEBAR_SCRLEN			480
#endif

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
#undef SIDEBAR_ICON_W
#undef SIDEBAR_YDIS
#undef SIDEBAR_SCRLEN			
#undef SIDEBAR_DOWN_ICON_Y		
#define SIDEBAR_ICON_W			42
#define SIDEBAR_YDIS			60
#define SIDEBAR_SCRLEN			280
#define SIDEBAR_DOWN_ICON_Y		360
#endif

#define SCREENPORTECT_OFF		0x00				// ��Ļ������
#define SCREENPORTECT_ON		0x01				// ��Ļ������
#define SCREENPORTECT_NOUSE		0x02				// ��Ļ����������

typedef enum
{
	STYLE_MAIN_NEWMESSAGE, 
	STYLE_MAIN_LYLY,
	STYLE_MAIN_NOFAZE,
	STYLE_MAIN_COUNT
} MAIN_ICON_STYLE;									// ����Сͼ������

// �첽�����ٲ�: IO��������Ӧ���������紥�����������
// ��Ҫ����ҳ����ת�ٲ�, ������ý��֮����ٲ�
typedef enum
{
	SYS_OPER_ALARMING,								// ��������-��תҳ��					
	SYS_OPER_ALARM_SOS,								// ������Ӧ����
	SYS_OPER_CALLOUT,								// �������ġ�ס�����ֻ����ز���¼
	SYS_OPER_CALLIN,								// ����
	SYS_OPER_MONITOR								// ����
}SYS_ASYN_OPER_TYPE;

#define CREATE_FORM(frm)	static CTRLDATA Ctrls[] ={};\
static DLGTEMPLATE DlgInit =\
{ \
	DW_STYLE, \
	DW_STYLE_EX,\
	FORM_X, FORM_Y, FORM_W, FORM_H,	\
	"",\
	0,\
	0,\
	sizeof(Ctrls)/sizeof(CTRLDATA),\
	Ctrls, \
	0\
};\
static int WindowProc(HWND hDlg, int message, WPARAM wParam, LPARAM lParam);\
GUI_FORM frm = {0, &FrmMain, &DlgInit, WindowProc, -1, 0, NULL, NULL, 0};\
static PGUI_FORM self = &frm

#define close_page() form_close(self)

#define ip_addr1(ipaddr) ((uint8)(ipaddr >> 24) & 0xff)
#define ip_addr2(ipaddr) ((uint8)(ipaddr >> 16) & 0xff)
#define ip_addr3(ipaddr) ((uint8)(ipaddr >> 8) & 0xff)
#define ip_addr4(ipaddr) ((uint8)(ipaddr) & 0xff)

/********************************************************/
/*			            ������غ���                    */	
/********************************************************/
/*************************************************
  Function:    		InitLogFont
  Description:		��ʼ������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void InitLogFont(void);

/*************************************************
  Function:    		FreeLogFont
  Description:		�ͷ�����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void FreeLogFont(void);

/*************************************************
  Function:    		GetFont
  Description:		�������
  Input: 			
  	1.size			(FONT_12--->FONT_24)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetFont(int8 size);

/*************************************************
  Function:    		GetFont
  Description:		��ô�������
  Input: 			
  	1.size			(FONT_12--->FONT_24)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetBoldFont(int8 size);

/*************************************************
  Function:    		GetFont_ABC
  Description:		��ô���ABC������
  Input: 			
  	1.size			(FONT_24,FONT_26)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetFont_ABC(int8 size);

/********************************************************/
/*			            Ƥ����غ���                    */	
/********************************************************/
/*************************************************
  Function:    		set_skin
  Description:		����Ƥ������
  Input: 			
  	1.mode			��������(SKIN_1--->SKIN_4)
  Output:			��
  Return:			���óɹ�Ϊtrue������Ϊfalse
  Others:
*************************************************/
uint8 set_skin(int8 mode);

/*************************************************
  Function:    		get_skin_count
  Description:		���Ƥ����������
  Input: 			��
  Output:			��
  Return:			Ƥ����������Ŀ������ͼƬ�����ڵķ���1
  Others:
*************************************************/
uint8 get_skin_count(void);

/*************************************************
  Function:    		get_skin
  Description:		���Ƥ������
  Input: 			��
  Output:			��
  Return:			��������(SKIN_1--->SKIN_4)
  Others:
*************************************************/
uint8 get_skin(void);

/*************************************************
  Function:    		GetSysColor
  Description:		���ϵͳ��ɫ
  Input: 			
  	1.id			ID
  Output:			��
  Return:			��ɫ
  Others:
*************************************************/
uint32 GetSysColor(int id);

/********************************************************/
/*			           ������غ���                     */	
/********************************************************/

/*************************************************
  Function:    		get_cur_form
  Description:		�õ���ǰ��ʾ�Ĵ���
  Input: 			��
  Output:			��
  Return:			��ǰ��ʾ�Ĵ���
  Others:
*************************************************/
PGUI_FORM get_cur_form(void);

/*************************************************
  Function:    		get_cur_hDlg
  Description:		��ȡ��ǰ������
  Input: 			��
  Output:			��
  Return:			��ǰ����ľ��
  Others:
*************************************************/
HWND get_cur_hDlg(void);

/*************************************************
  Function:    		form_show
  Description:		��ʾ��ģ̬����
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			�ɹ�(true)���(false)
  Others:
*************************************************/
uint8 form_show(PGUI_FORM frm);

/*************************************************
  Function:    		form_hide
  Description:		���ش���(ģ̬ʱ,�رմ���)
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void form_hide(PGUI_FORM frm);

/*************************************************
  Function:    		form_close
  Description:		�رմ���
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void form_close(PGUI_FORM frm);

/*************************************************
  Function:    		init_frm_language
  Description:		��ʼ����������
  Input: 			
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
void init_frm_language(void);

/*************************************************
  Function:    		DefaultMsgProc
  Description:		Ĭ����Ϣ����
  Input: 			
  	1.frm			��������
  	2.hDlg			���
  	3.message		��Ϣ
  	4.wParam		����1
  	5.lParam		����2
  Output:			��
  Return:			������
  Others:
*************************************************/
int DefaultMsgProc(PGUI_FORM frm, HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

/*************************************************
  Function:    		form_showmodal
  Description:		��ʾ����(ģ̬,����������)
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			�ɹ�(true)���(false)
  Others:
*************************************************/
int form_showmodal(PGUI_FORM frm);

/*************************************************
  Function:    		form_create
  Description:		��������(��ģ̬)
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			������
  Others:
*************************************************/
HWND form_create(PGUI_FORM frm);

/*************************************************
  Function:    		exit_page
  Description:		�˳�ҳ��
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void exit_page(void);

/*************************************************
  Function:    		close_curren_page
  Description:		�رյ�ǰҳ��
  Input: 			
  	frm				��ǰ�����ַ
  Output:			��
  Return:			��
  Others:
*************************************************/
void close_curren_page(PGUI_FORM frm);

/*************************************************
  Function:    		parent_page
  Description:		����ǰһ������ľ��
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
HWND parent_page(void);

/*************************************************
  Function:    		exit_the_page
  Description:		�˳���ǰҳ��
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void exit_the_page(PGUI_FORM frm);

/*************************************************
  Function:    		close_msg_page
  Description:		�ر���Ϣ��ҳ��
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void close_msg_page(PGUI_FORM frm);

/*************************************************
  Function:    		back_main_page
  Description:		�˻���ҳ��
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void back_main_page(void);

//*************************************************************//
//***************��������Ϣ��ʾ��**********************//
//*************************************************************//
/*************************************************
  Function:		set_windowsize
  Description: 	���ô��ڴ�С
  Input:
  	1.frm		��������
  	2.x			��ʼ����
  	3.y			
  	4.w			���ڿ�
  	5.h			���ڸ�
  Output:		��
  Return:		��	
  Others:		
*************************************************/
void set_windowsize(PGUI_FORM frm, int x, int y, int w, int h);

/*************************************************
  Function:		show_msg
  Description:  ��ʾ��
  Input:		
  	1.hDlg		����
  	2.ID		�ؼ�ID
  	3.style		���
  	4.TextID	����ID
  Output:		��
  Return:		��
  Others:
*************************************************/
void show_msg(HWND hDlg , uint32 ID, AU_MSG_TYPE style, uint32 TextID);

/*************************************************
  Function:     show_msg_video
  Description:  ��ʾ��
  Input:        
    1.win       ����
    2.ID        ID
    3.style     ���
    4.TextID    ����ID
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_video(HWND hDlg , uint32 ID, AU_MSG_TYPE style, uint32 TextID);

/*************************************************
  Function:		show_msg_pass
  Description:  ������ʾ��
  Input:		
  	1.win		����
  	2.ID		ID
  	3.type		��������
  	4.xiechi	Ю���ж�
  Output:		��
  Return:		��
  Others:
*************************************************/
void show_msg_pass(HWND hDlg, uint32 id, PASS_TYPE type, uint8 xiechi);

#if 0
/*************************************************
  Function:     show_msg_jd_addr
  Description:  �ҵ��ַ��ʾ��
  Input:        
    1.win       ����
    2.ID        ID
    3.startaddr ��ʼ��ַ
    4.endaddr   ������ַ
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_jd_addr(HWND hDlg , uint32 ID, uint16 startaddr, uint16 endaddr);

/*************************************************
  Function:     show_msg_jd_control
  Description:  �ҵ����
  Input:        
    1.win       ����
    2.ID        ID
    3.startaddr ��ʼ��ַ
    4.endaddr   ������ַ
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_jd_control(HWND hDlg , uint32 ID, AU_JD_DEV_TYPE devtype, uint8  state,  uint8 Value, uint16 *text, uint8 factory);

/*************************************************
  Function:     show_msg_aurine_jd_control
  Description:  �ҵ����
  Input:        
    1.win       ����
    2.ID        ID
    3.startaddr ��ʼ��ַ
    4.endaddr   ������ַ
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_tabus_jd_control(HWND hDlg , uint32 ID, AU_JD_DEV_TYPE devtype, uint8  state,  uint8 Value, uint16 *text, uint8 style,uint8 flag);

/*************************************************
  Function:     show_msg_ipmodule_code
  Description:  ��֤����ʾ��
  Input:        
    1.win       ����
    2.ID        ID
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_ipmodule_code(HWND hDlg , uint32 ID);
#endif

/*************************************************
  Function:		show_msg_hit
  Description:  ����������Ϣ����������ʾ
  Input:		
  	1.hDlg		����
  	2.ID		�ؼ�ID
  	3.style		���
  	4.TextID	����ID	
  Output:		��
  Return:		��
  Others:
*************************************************/
void show_msg_hit(HWND hDlg , uint32 ID, AU_MSG_TYPE style, uint32 TextID);


/*************************************************
  Function:		show_msg_pass
  Description:  ������ʾ��
  Input:		
  	1.win		����
  	2.ID		ID
  	3.type		��������
  	4.xiechi	Ю���ж�
  Output:		��
  Return:		��
  Others:
*************************************************/
void show_msg_pass(HWND hDlg, uint32 id, PASS_TYPE type, uint8 xiechi);

/*************************************************
  Function:    		toXiechiPwd
  Description:		ת����Ю������
  Input: 			
  	1.oldPwd		Ҫת��������
  	2.bAdd			Ю�������Ƿ�+1��true:+1��false: -1;
  Output:			
  	1.newPwd		ת���������
  Return:			
*************************************************/
void toXiechiPwd(char * oldPwd, uint8 bAdd, char * newPwd);

/*************************************************
  Function:		change_ip_to_char
  Description:  �л�IP��ַ4���ֽ�
  Input:		
  	1.IP		IP��ַ
  	2.ipaddr	��ַ
  Output:		��
  Return:		��
  Others:
*************************************************/
void change_ip_to_char(uint32 IP, uint8* ipaddr);

/*************************************************
  Function:		change_char_to_ip
  Description:  �л�4���ֽ�ΪIP��ַ
  Input:		
  	1.ipaddr	ip��ַ
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 change_char_to_ip(uint8* ipaddr);

/*************************************************
  Function:		change_ip_to_str
  Description:  �л�IP��ַ�ַ���
  Input:		
  	1.IP		IP��ַ
  	2.ipaddr	��ַ
  Output:		��
  Return:		��
  Others:
*************************************************/
void change_ip_to_str(uint32 IP,char *ip);

/*************************************************
  Function:			show_sys_event_hint
  Description: 		ϵͳ�¼���ʾ��������Ϣ���������ѵ�
  Input:		
  	1.EventType		�¼�����
  Output:			��
  Return:			��
  Others:
*************************************************/
void show_sys_event_hint(uint16 EventType);

/*************************************************
  Function:		get_colorkey
  Description: 	
  Input: 		
	1.			��
  Output:		��
  Return:		��
  Others:
*************************************************/
int get_colorkey(void);

/*************************************************
  Function:		draw_video
  Description: 	����Ƶ���
  Input: 		
	1.hdc
	2.x			X��ַ
	3.y			Y��ַ
	4.w			���
	5.h			�߶�
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_video(HDC hdc, int x, int y, int w, int h);

/*************************************************
  Function:		get_now_ymd
  Description: 	��ȡ��ǰ���ڵ�������
  Input: 		
	1.			��
  Output:		��
  Return:		��
  Others:
*************************************************/
void get_now_ymd(int *y,int *m,int *d);

/*************************************************
  Function:		get_houseno_desc
  Description: 	��÷�������
  Input: 		��
  Output:		��
  Return:		��
  Others:		add by luofl 2008-1-10
*************************************************/
char * get_houseno_desc( char * numtext, char * temp);

/*************************************************
  Function:		get_isFullScreen
  Description: 	
  Input: 		
	1.			��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 get_isFullScreen(void);

/*************************************************
  Function:		set_fullscreen_NormalRc
  Description: 	
  Input: 		
	1.			��
  Output:		��
  Return:		��
  Others:
*************************************************/
//void set_fullscreen_NormalRc(RECT_S * pRc);

/*************************************************
  Function:		get_isFullScreen
  Description: 	����ȫ���Ƿ�����Ƶ
  Input: 		
	1.			��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 set_fullscreen_video(uint8 isVideo);

#if 0
/*************************************************
  Function:		full_screen
  Description: 	��ȫ��
  Input: 		
	1.			�� 
  Output:		��
  Return:		��
  Others:
*************************************************/
int full_screen(HWND hOwner);
#endif

/*************************************************
  Function:		close_full_screen
  Description: 	�ر�ȫ��
  Input: 		
	1.			��
  Output:		��
  Return:		��
  Others:
*************************************************/
int close_full_screen(int SetVideo);
/*************************************************
  Function:    		show_msg_byID
  Description:		��Ϣ��(��ʾ�ַ���ID)
  Input: 			
  ��1.ParentFrm		������
  	��.TitleID		����ID
  	��.TextId		�ı�����ID
  	��.msgtype		��Ϣ������
  	5.pData         ���ݽṹ��
  Output:			0:�û�ȡ���������� 1:�û�ȷ�ϲ�������
  Return:			��
  Others: 
*************************************************/
uint32 show_msg_byID(PGUI_FORM ParentFrm,  int TitleID,int TextId,AU_MSG_TYPE msgtype, PJIADIAN_ITEM pData);

/*************************************************
  Function:    		show_msg_bytext
  Description:		��Ϣ��(��ʾ�ַ���)
  Input: 			
  ��1.ParentFrm		������
  	��.TitleID		����ID
  	��.text			�ı�����
  	��.msgtype		��Ϣ������
  Output:			0:�û�ȡ���������� 1:�û�ȷ�ϲ�������
  Return:			��
  Others: 
*************************************************/
uint32 show_msg_bytext(PGUI_FORM ParentFrm,  int TitleID,char *text,AU_MSG_TYPE msgtype);

/********************************************************/
/*			           ������غ���                     */	
/********************************************************/
/*************************************************
  Function:    		change_mainIcon_state
  Description:		�ı�������Сͼ����˸״̬
  Input: 			
  	1.check_state	��ǰҪ����ͼ��״̬
  	2.pflash		��ǰ״̬ 0 �� 1 �� ����ת�ƣ������ ����˸
  Output:			
  Return:			��
  Others:
*************************************************/
void change_mainIcon_state(MAIN_ICON_STYLE check_state, uint8 pflash);

/*************************************************
  Function:    		get_mainIcon_state
  Description:		���Сͼ��״̬
  Input: 			
  	1.public_state	���ù�������
  	2.state:   		״̬
  Output:			��
*************************************************/
//void get_mainIcon_state(PUBLIC_STATE public_state);

/*************************************************
  Function:    		draw_backbmp
  Description:		��ĳ�������л�ͼƬ
  Input: 			
  	1.hdc			hdc
  	2.rect			Ҫ���ľ���λ�ô�С
  	3.bmp			ͼƬ
  	4.bmpMode		��ģʽ��0:���죻1�����У�2��ƽ��
  	5.isFreeBmp 	true:�ͷ�ͼƬ��Դ
  Output:			�� 
  Others:
*************************************************/
void draw_backbmp(HDC hdc,RECT rect ,PBITMAP bmp ,int bmpMode,uint8 isFreeBmp);

/*************************************************
  Function:    utf8_2_gb2312
  Description: ��utf8�ַ���ת��Ϊgb2312�ַ���
  Input:
  1.��ת�����ַ���ָ��
  Return:
  ת���ɹ����
*************************************************/
int utf8_2_gb2312(char *p);

/*************************************************
  Function:		ConvertFileName
  Description: 	��ȫ·����ת�����ļ����� 
  Input: 		
	1.fullpathname: Ҫת�����ļ�ȫ·������	
	2.finame:  	ת������ļ����� 
  Output:		��
  Return:		
  Others:
*************************************************/
void ConvertFileName(char * fullpathname,char * filename);

/*************************************************
  Function:		draw_text_by_myfont
  Description: 	
  Input: 		
	1.			hdc
	2.			x
	3.			y
	4.			TextID
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_text_by_myfont(HDC hdc, int x, int y, uint32 TextID);

/*************************************************
  Function:		DrawBmpID
  Description: 	����ͼƬID��ָ��λ�û�ͼƬ,��߸���
  				ʵ��ͼƬ��С����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void DrawBmpID(HDC hdc, int x, int y, int w, int h, int id);

/*************************************************
  Function:		DrawBmpID_EX
  Description: 	����ͼƬID��ָ��λ�û�ͼƬ
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void DrawBmpID_EX(HDC hdc, int x, int y, int w, int h, int id);

/*************************************************
  Function:		draw_Sidebar
  Description:  �������
  Input:		
  	1.win		
  	2.x			
  	3.y			
  	4.allpage
  	5.page
  	6.mode
  	7.keystate
  	8.select
  Output:		��
  Return:		��
  Others:
*************************************************/
//void draw_Sidebar(HWND hDlg, uint32 H,uint32 x, uint32 y, uint8 allpage, uint8 page, uint8 mode, uint8 keystate, uint8 select);
void draw_Sidebar(HWND hDlg, uint32 H, uint32 x, uint32 y, uint8 allpage, uint8 pageCount, uint8 Count, uint8 keystate, uint8 select, uint32 curSelect);

/*************************************************
  Function:		get_Sidebar_key
  Description:  �����������
  Input:		
  	1.win		
  	2.x			�Ѿ�������ʼ�����X����	
  	3.y			�Ѿ�������ʼ�����Y����	
  Output:		��
  Return:		��
  Others:
*************************************************/
int8 get_Sidebar_key(uint32 H, uint8 mode, uint32 x, uint32 y);

/*************************************************
  Function:			ui_show_win_arbitration
  Description: 		��ʾҳ��ʱ�ٲ�
  Input: 		
  	1.hDlg			��ǰҳ��
  	2.OperType		��������
  Output:			��
  Return:			TRUE / FALSE
  Others:			
*************************************************/
int32 ui_show_win_arbitration(HWND hDlg, SYS_ASYN_OPER_TYPE OperType);

/*************************************************
  Function:		ScreenOnTimer
  Description: 	��Ļ��LCD��ʱ
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
void ScreenOnTimer(void);

/*************************************************
  Function:		SetScreenTimer
  Description: 	�ָ���Ļ��LCD��ʱʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void RestoreScreenTimer(void);

/*************************************************
  Function:		SetScreenTimer
  Description: 	�ָ���Ļ��LCD��ʱʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
uint8 SetScreenTimer(void);

/*************************************************
  Function:		InitScreenTimer
  Description: 	��ʼ����Ļ��LCD��ʱ
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void InitScreenTimer(void);

/*************************************************
  Function:			get_houseno_desc
  Description: 		��÷�������
  Input: 			
  	1.numtext		�豸���
  	2.temp			�豸����
  Output:			��
  Return:			��
  Others:		
*************************************************/
char * get_houseno_desc(char * numtext, char * temp);

/*************************************************
  Function:			get_dev_description
  Description: 		����豸����
  Input: 			
  	1.DevType		�豸����
  	2.DevStr		�豸���
 	3.StrOutLen		��������С
  Output:			
  	1.DevStrOut		�豸����
  Return:			��
  Others:		
*************************************************/
uint32 get_dev_description(DEVICE_TYPE_E DevType, char * DevStr, char * DevStrOut, uint32 StrOutLen);

/*************************************************
  Function:		OnPaintBack
  Description: 	������
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
void OnPaintBack(HWND hDlg);

/*************************************************
  Function:		OnPaintWhite
  Description: 	����ɫ����
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
void OnPaintWhite(HWND hDlg);

#ifdef _TIMER_REBOOT_NO_LCD_
/*************************************************
  Function:     timer_reboot_LCD_func
  Description:  ��ʱ��������������л�
  Input:        
    1.flag       1:��Ƭ������������ 
                 0: N32926����������
  Output:       ��
  Return:       ��
  Others:   
  ҹ������ʱ���������������쿪������
  �������û�����쳣��
*************************************************/
void timer_reboot_control(uint8 flag);
#endif

#ifdef __cplusplus 
}
#endif

#endif /* __AU_MODEL_FUNC_H__ */
