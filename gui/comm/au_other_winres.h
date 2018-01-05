/********************************************************
  Copyright (C), 2006-2016, Aurine
  File name:	au_other_winres.h
  Author:		�޷�»
  Version:		V2.0
  Date: 		2015-02-03
  Description:	��Դͷ�ļ�(��ɫ,�ṹ�嶨��,�Զ�����Ϣ)
  
  History:		  
	1. Date:
	   Author:
	   Modification:
	2. ...
*********************************************************/
#ifndef __AU_OTHER_WINRES_H__
#define __AU_OTHER_WINRES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "gui_include.h"
#include "logic_include.h"

/************************��������************************/
#define FONT_12				12						// 12������
#define FONT_14				14						// 14������
#define FONT_16				16						// 16������
#define FONT_20				20						// 20������
#define FONT_24				24						// 24������
#define FONT_26				26						// 26������
#define FONT_28				28						// 28������

#define SKIN_1				1						// Ƥ������1
#define SKIN_2				2						// Ƥ������2
#define SKIN_3				3						// Ƥ������3
#define SKIN_4				4						// Ƥ������4    

#ifdef _TFT_7_
#define SCREEN_WIDTH	  		800						// ����Ŀ��
#define SCREEN_HEIGHT     		480						// ����ĸ߶�
#define DW_STYLE				(WS_VISIBLE | WS_NONE)	// ����ķ��
//#define DW_STYLE_EX			WS_EX_NONE				// �������չ���
#define DW_STYLE_EX				WS_EX_AUTOSECONDARYDC	// �������չ���
#define FORM_X					0						// �������x
#define FORM_Y					0						// �������y 
#define FORM_W					(SCREEN_WIDTH-FORM_X)	// ����Ŀ��
#define FORM_H					(SCREEN_HEIGHT-FORM_Y)	// ����ĸ߶�
#define FORM_RIGHT_W			160						// �ұߴ�����
#define FORM_RIGHT_H			480						// �ұߴ���߶�

//#define DEFAULT_STYLE	  		(WS_VISIBLE | WS_NONE)	// Ĭ�ϴ���ķ��
//#define DEFAULT_STYLE_EX  	(WS_EX_NONE)			// Ĭ�ϴ������չ���
#define DEFAULT_BN_STYLE		(WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_NOTIFY)

#define TEXT_X              	15

// �����궨��
#define KEYDOWN  				1
#define KEYUP  					0
#define MAX_LEN					8     
#define PASSWORD_LEN 			6

#define INPUT_CTRL_W			356
#define INPUT_CTRL_H			74
#define	INPUT_CTRL_X			((FORM_W-RIGHT_CTRL_W-INPUT_CTRL_W)/2)
#define INPUT_CTRL_Y			90

// ���̿ؼ��궨��
#define KEYBORD_NUM_MAX         11
#define KEYDOWN  			    1
#define KEYUP  					0

#define KEYBOARD_CTRL_W         640
#define KEYBOARD_CTRL_H         90  
#define KEYBOARD_CTRL_X         0
#define KEYBOARD_CTRL_Y         (FORM_H-KEYBOARD_CTRL_H)

// �ұ߿ؼ��궨��
#define RIGHT_CTRL_X			640
#define RIGHT_CTRL_Y			0
#define RIGHT_CTRL_W			160
#define RIGHT_CTRL_H			480

// �б�ؼ��궨��
#define LIST_CTRL_X				0
#define LIST_CTRL_Y				0
#define LIST_CTRL_W				640
#define LIST_CTRL_H				480

// ���С����С�������ʾ��λ��
#define TEXT_XPOS           	40
#define TEXT_YPOS          		20
#define TEXT_DISX               12
#define TEXT_DISY				30	
#define TEXT_LEN          		200

// ��������
#define MUTE_ICON_XPOS			181
#define MUTE_ICON_YPOS			240
#define VOLUME_ICON_XPOS    	249
#define VOLUME_ICON_YPOS    	240
#define VOLUME_TOTAL_H			48					// ����ͼ���ܸ߶�
#define VOLUME_TOTAL_W			(210+48+20)
#define VOLUME_ALL_ICON_Y		((VIDEO_WIN_H-VOLUME_TOTAL_H)/2+150)
#else
#define SCREEN_WIDTH	  		480						// ����Ŀ��
#define SCREEN_HEIGHT     		272						// ����ĸ߶�
#define DW_STYLE				(WS_VISIBLE | WS_NONE)	// ����ķ��
//#define DW_STYLE_EX			WS_EX_NONE				// �������չ���
#define DW_STYLE_EX				WS_EX_AUTOSECONDARYDC	// �������չ���
#define FORM_X					0						// �������x
#define FORM_Y					0						// �������y 
#define FORM_W					(SCREEN_WIDTH-FORM_X)	// ����Ŀ��
#define FORM_H					(SCREEN_HEIGHT-FORM_Y)	// ����ĸ߶�
#define FORM_RIGHT_W			100						// �ұߴ�����
#define FORM_RIGHT_H			272						// �ұߴ���߶�

//#define DEFAULT_STYLE	  		(WS_VISIBLE | WS_NONE)	// Ĭ�ϴ���ķ��
//#define DEFAULT_STYLE_EX  	(WS_EX_NONE)			// Ĭ�ϴ������չ���
#define DEFAULT_BN_STYLE		(WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_NOTIFY)

#define TEXT_X              	15

// �����궨��
#define KEYDOWN  				1
#define KEYUP  					0
#define MAX_LEN					8     
#define PASSWORD_LEN 			6
#define INPUT_CTRL_X			100
#define INPUT_CTRL_Y			41
#define INPUT_CTRL_W			210
#define INPUT_CTRL_H			44

// ���̿ؼ��궨��
#define KEYBORD_NUM_MAX         11
#define KEYDOWN  			    1
#define KEYUP  					0
#define KEYBOARD_CTRL_X         0
#define KEYBOARD_CTRL_Y         219
#define KEYBOARD_CTRL_W         380
#define KEYBOARD_CTRL_H         53  

// �ұ߿ؼ��궨��
#define RIGHT_CTRL_X			380
#define RIGHT_CTRL_Y			0
#define RIGHT_CTRL_W			100
#define RIGHT_CTRL_H			272

// �б�ؼ��궨��
#define LIST_CTRL_X				0
#define LIST_CTRL_Y				0
#define LIST_CTRL_W				380
#define LIST_CTRL_H				272

// ���С����С�������ʾ��λ��
#define TEXT_XPOS           	12
#define TEXT_YPOS          		5
#define TEXT_DISX               12
#define TEXT_DISY				21	
#define TEXT_LEN          		200

// ��������
#define MUTE_ICON_XPOS			103
#define MUTE_ICON_YPOS			225
#define VOLUME_ICON_XPOS    	141
#define VOLUME_ICON_YPOS    	225
#define VOLUME_TOTAL_H			29					// ����ͼ���ܸ߶�
#define VOLUME_TOTAL_W			170
#define VOLUME_ALL_ICON_Y		MUTE_ICON_YPOS
#endif

// ������ǰ����ʱ��ʱ��
#define NETDOOR_TIME			10

/************************��������************************/

/************************��ɫ����************************/
#define MAKE_RGB16(r, g, b)	(((WORD)((BYTE)(r) & 0xF8) << 8) | ((WORD)((BYTE)(g) & 0xFC) << 3) \
				| ((WORD)((BYTE)(b) & 0xF8) >> 3))

#define MAKE_RGB32(a, r, g, b)	(((DWORD)((BYTE)(a) & 0xFF) << 24) | ((DWORD)((BYTE)(r) & 0xFF) << 16) \
				| ((DWORD)((BYTE)(g) & 0xFF) << 8) | ((DWORD)((BYTE)(b) & 0xFF)))

#ifdef _USE_RGB32_
#define COLOR_BLACK		 	(MAKE_RGB32(255, 0, 0, 0))				// ��ɫ	
#define COLOR_WHITE		 	(MAKE_RGB32(255, 255, 255, 255)) 		// ��ɫ
#define COLOR_RED			(MAKE_RGB32(255, 255, 0, 0))	    	// ��ɫ
#define COLOR_GREEN			(MAKE_RGB32(255, 0, 255, 0))			// ��ɫ
#define COLOR_BLUE			(MAKE_RGB32(255, 0, 0, 255))			// ��ɫ
#define COLOR_YELLOW		(MAKE_RGB32(255, 255, 255, 0))			// ��ɫ	
#else
#define COLOR_BLACK		 	(MAKE_RGB16(0, 0, 0))					// ��ɫ	
#define COLOR_WHITE		 	(MAKE_RGB16(255, 255, 255)) 			// ��ɫ
#define COLOR_RED			(MAKE_RGB16(255, 0, 0))	    			// ��ɫ
#define COLOR_GREEN			(MAKE_RGB16(0, 255, 0))					// ��ɫ
#define COLOR_BLUE			(MAKE_RGB16(0, 0, 255))					// ��ɫ
#define COLOR_YELLOW		(MAKE_RGB16(255, 255, 0))				// ��ɫ		
#endif
#define COLOR_GREY			PIXEL_lightgray							// ��ɫ
#define PAGE_BK_COLOR	  	COLOR_BLACK								// Ĭ�ϱ���ɫ

// ����1
#define COLOR_BUTTON_TEXT	GetSysColor(0)			// ��ť�ϵ�����
#define COLOR_COMMON_TEXT	GetSysColor(1)			// ��ͨ����
#define COLOR_DOWN_TEXT		GetSysColor(2)			// ����������ͨ����
#define COLOR_ERR			GetSysColor(3)			// ������ʾ��Ϣ����ɫ
#define COLOR_DEVNO_TEXT	GetSysColor(4)			// �����豸��ŵ�������ɫ
#define COLOR_BLUE_TEXT		GetSysColor(5)			// ��������ĺ�������
#define SYS_COLOR_LIGHT		GetSysColor(6)			// Ĭ����ɫ
#define SYS_COLOR_BK		GetSysColor(7)			// Ĭ�ϱ���ɫ
#define SYS_COLOR_DARK		GetSysColor(8)			// Ĭ�ϰ�ɫ
#define SYS_DOWN_LIGHT		GetSysColor(9)			// �����ɫ
#define SYS_DOWN_BK			GetSysColor(10)			// �������ɫ
#define SYS_DOWN_DARK		GetSysColor(11)			// ��ͨ���ֵ����ɫ
#define SYS_INFO_LIGHT		GetSysColor(12)			// ��ʾ����ɫ
#define SYS_INFO_BK			GetSysColor(13)			// ��ʾ�򱳾�ɫ
#define SYS_INFO_DARK		GetSysColor(14)			// ��ʾ��ɫ
/************************��ɫ����************************/

/**********************�ؼ����ƶ� ��**********************/
#define AU_RIGHT_BUTTON		"AU_R_BUTTON"
#define AU_LIST_CTRL		"AU_LIST_CTRL"
#define AU_CHOSE_BUTTON     "AU_C_BUTTON"
#define AU_AREA_BUTTON		"AU_AREA_BUTTON"
#define AU_KEY_BUTTON       "AU_KEY_BUTTON"
#define AU_SPIN_EDIT		"AU_SPIN_EDIT"
#define NUM_KEYBORD			"NUM_KEYBORD"
#define AU_MSG_BUTTON       "AU_MSG_BUTTON"
#define AU_SET_VOLUME       "AU_SET_VOLUME"
#define AU_FLAT_EDIT        "AU_FLAT_EDIT"
#define AU_INPUT_CTRL       "AU_INPUT_CTRL"
#define AU_EIGHTAREA_CTRL	"AU_EIGHT_CTRL"
#define AU_SPIN_CTRL		"AU_SPIN_CTRL"
#define AU_PROC_CTRL		"AU_PROC_CTRL"
/**********************�ؼ����ƶ���**********************/

/*******************�û����幫���ؼ�ID*******************/
typedef enum
{
	IDC_RIGHT_BUTTON = 901,	
	IDC_KEYBOARD_CTRL,
	IDC_LIST_CTRL,		
	IDC_INPUT_CTRL,          
	IDC_INPUT1_CTRL,
	IDC_MSG_CTRL,
	IDC_EIGHTAREA_CTRL,
	IDC_SPIN_CTRL,
	IDC_FORM,
	IDC_Msg_Admin,
	IDC_Msg_User,
	IDC_Msg_Notice,
	IDC_Set_Back,
	IDC_SEARCH_LIST, 			// �����б�ʱ�õ�����IDC
	IDC_PROC_CTRL,
}IDC_TYPE;

/*********************�û�������Ϣ***********************/
typedef enum
{
    // �ұ߿ؼ���Ϣ
	WM_Right_Set_TextID = MSG_USER+1,
	WM_Right_Get_TextID,
	WM_Right_Set_Image,
	WM_Right_Get_Image,
	WM_Right_Get_ImageOrTextID,
	WM_Right_Set_enable,
	WM_Right_Get_enable,
	WM_Right_Set_VideoMode,
	WM_Right_Get_VideoMode,
	WM_Right_SetTextLen,
	WM_Right_Set_Select,
	WM_Right_Get_Select,
	WM_Right_Set_TextLen,
	WM_Right_Add_Win,
	WM_Right_Query_Key,
	WM_Right_Set_ALLImage,
	WM_Right_Clear_Win,
	WM_Right_Clear_BackGround,
	WM_Right_reflash,

	// �б�ؼ���Ϣ
	WM_List_Set_Enable,
	WM_List_Get_Enable,
	WM_List_Set_Text,
	WM_List_Get_Text,
	WM_List_Set_Image,
	WM_List_SetT_BKColor,
	WM_List_Go_LastSel,
	WM_List_Go_NextSel,
	WM_List_Add_Item,
	WM_List_Clear_Item,
	WM_List_Del_Item,
	WM_List_Go_LastPage,
	WM_List_Go_NextPage,
	WM_List_Get_AllPage,
	WM_List_Get_Page,
	WM_List_Set_Page,
	WM_List_Get_Sel,
	WM_List_Set_ItemColor,
	WM_List_Get_Image,
	WM_List_OkKey,
	WM_List_Set_Sel,
	WM_List_Set_HeadText,
	WM_List_Get_HeadText,
	WM_List_Set_Side,
	WM_List_Set_ItemWidth,
	WM_List_SetKeyMode,
	
	// ���̿ؼ���Ϣ
	WM_Key_Set_Select,
	WM_Key_Get_Select,
	WM_Key_Set_enable,
	WM_Key_Get_enable,
	WM_Key_Left,
	WM_Key_Right,
	WM_Key_Ok,
	WM_Key_Exit,
	WM_Key_Set_Flag,

	// �����ؼ�
	WM_Input_Set_enable,
	WM_Input_Get_enable,
	WM_Input_Set_Text,
	WM_Input_Get_Text,
	WM_Input_Set_Textlen,
	WM_Input_Set_Hit,
	WM_Input_Set_TextID,
	WM_Input_Set_Flag,
	WM_Input_Clear,
	WM_Input_del_Num,
	WM_Input_add_Text,
	WM_Input_Set_Active,
	WM_Input_Get_Active,
	WM_Input_Get_Value,
	WM_Input_Send_Value,	
	WM_Input_Set_ShowType,
	WM_Input_Get_Text_Value,

	// �˷����ؼ�
	WM_Eight_Set_Text,
	WM_Eight_Get_Text,
	WM_Eight_Set_TextW,
	WM_Eight_Get_TextW,
	WM_Eight_Set_Image,
	WM_Eight_Set_MidImage,
	WM_Eight_Get_Image,
	WM_Eight_Set_enable,
	WM_Eight_Get_enable,
	WM_Eight_Set_Param,
	WM_Eight_End_Timer,
	WM_Eight_Set_MaxNum,
	WM_Eight_Set_BKImage,

	// IP�ؼ���Ϣ
	WM_Spin_Set_Value,
	WM_Spin_Get_IPValue,
	WM_Spin_Get_Value,
	WM_Spin_Set_MaxValue,
	WM_Spin_Get_MaxValue,
	WM_Spin_Add_Item,
	WM_Spin_Clear_Item,
	WM_Spin_Set_enable,
	WM_Spin_Get_enable,
	WM_Spin_Set_SelAll,
	WM_Spin_Del,
	WM_Spin_Right,
	WM_Spin_Left,
	WM_Spin_Active,

	// ������Ϣ
	WM_Change_RightKey,								// queryʱ��Ϣ����ˢ�ұ߿ؼ�
	WM_MSG_VIEW,									// ��Ϣ�鿴
	WM_RELOAD,										// ����
	WM_MSG_Close,									// �ر���Ϣ��
	WM_CENTER_HANDUP,								// ���ĹҶ���Ϣ
	WM_NETDOOR,                      			   	// ������ǰ���õ���Ϣ
	WM_FORM_SHOW,									// ��ʾ����
	
	// ������Ϣ
	WM_Procress_Set_Proc,			
	WM_Procress_Set_Allproc,
}WM_TYPE;
/*********************�û�������Ϣ***********************/

/**********************�ṹ�嶨��************************/
typedef void (*PROC)(void);							// ������ؽṹ��

typedef enum
{
	MSG_INFORMATION = 0x01,							// ��Ϣ
	MSG_WARNING,									// ����
	MSG_ERROR,										// ����
	MSG_RIGHT,										// ��ȷ
	MSG_QUERY,										// ȷ��
	MSG_PASS,										// �����
	MSG_ALARM,										// ����
	MSG_MESSAGE,									// ����Ϣ
	MSG_CALL_MESSAGE,								// ������Ϣ
	MSG_TS,											// У��
	MSG_JDADDR,										// �ҵ�
	MSG_JD_TJ,										// �ҵ����
	MSG_AURINE_JD_TJ,                               // ���ּҵ����
	MSG_AURINE_JD_MODE,                             // ���ּҵ�ģʽ
	MSG_HIT,                                        // ��ʾ
	MSG_IPCODE,										// IPģ���ַ
	MSG_JD_HIT,
	MSG_NEW_PASS,
} AU_MSG_TYPE;	

typedef struct
{
	int year;										// ��
	int mon;										// ��
	int mday;										// ��
	int wday;										// ����
	int hour;										// Сʱ
	int min;										// ��	
	int sec;										// ��
}GUI_TIME,*PGUI_TIME;

typedef struct _GUI_FORM
{
	HWND hWnd;
	struct _GUI_FORM * Parent; 						//���常��
	PDLGTEMPLATE pDlgTemplate; 						//����ģ��
	WNDPROC	WinProc;								//��Ϣ������
	int language;									//���嵱ǰ����
	int skin;										//Ƥ������
	PROC ChangeLanguage;							//�ı����Ժ���
	PROC ChangeSkin;								//�ı�Ƥ������
	int IsDlg;										//�Ƿ�ģ̬����
}GUI_FORM, *PGUI_FORM;

#if 0
typedef struct
{
	int TextID;                                     // ��������
	int ImageID;                                    // ����ͼƬ
	uint8 enable;                                   // ����ʹ��
	uint8 mode;                                     // ����ģʽ    1:Ϊ����̧�����ԭ����״̬  0:���»���״̬
	uint8 state;                                    // ����״̬
}BUTTON_INFO, *PBUTTON_INFO;

typedef struct
{
	PGUI_FORM ParentFrm;                             // ������
	int8 ButtonNum;                                  // ��������
	BUTTON_INFO Buttons[BUTTON_COUNT];               // ���������ṹ��
	int8 select;                                     // ����ѡ��״̬
	char text[60];                                   // ������Ϣ
	int8 On_ID;                                      
}RIGHT_BUTTON, *PRIGHT_BUTTON;
#endif

typedef struct
{
	PGUI_FORM ParentFrm;                             // ������
	uint32 TextID;                                   // ��������
	uint32 ImageID;                                  // ����ͼƬ
	uint8 enable;                                    // ����ʹ��
	uint8 keystate;
	uint8 state;                                     // ����״̬ 0:û��ѡ�� 1:ѡ��
	uint8 check;                                     // 0:ѡ��󰴼�ͼƬ����   1:ѡ��󰴼�ͼƬ��Ϊ��ѡ��ͼƬ
}KEY_BUTTON, *PKEY_BUTTON;

typedef struct
{
	PGUI_FORM ParentFrm;                             // ������
	int TextID;                                      // ��������
	uint8 enable;                                    // ����ʹ��
	uint8 state;                                     // ����״̬ 0:û��ѡ�� 1:ѡ��
	uint8 mode;                                      // 0:ΪԲ�򰴼� 1:Ϊ���򰴼�
}CHOSE_BUTTON, * PCHOSE_BUTTON;

typedef enum
{
	SECU_MODE 	 = 0,								// ����ģʽ
	ISO_MODE,										// ����ģʽ
	PART_MODE,										// �ַ���Чģʽ
	DEFIND_MODE,									// ����ģʽ
	AREA_TYPE_MODE,									// ��������ģʽ
	JIADIAN_MODE,  									// �ҵ�ģʽ
}SECU_SHOW_MODE;

typedef struct
{
	uint8			  	area_info[8];				// ������Ϣ
	uint8				area_type[8];				// ��������
	uint8				other_info;					// �����ַ���Ч����Ϣ
	PGUI_FORM 			ParentFrm;					// ������	
	SECU_SHOW_MODE  	mode;						// ѡ���ģʽ
	int8				select;						// ��ǰѡ�е�״̬
	uint8               amount;						// ��ť���������8��
	uint8               column;						// ÿ���м���
	uint8               always;						// ������ʾ
	uint8               text[8][20];				// ����id
	uint32              imageid[8];                 // ͼƬid
}SECU_BOTTON_INFO, *PSECU_BOTTON_INFO;

typedef struct
{
	PGUI_FORM ParentFrm;							// ������	
	NT_BOOL  	mode;								// ����ģʽ 0 �������� 1 ���𷵻� 
	NT_BOOL 	enable;							 
	uint16 	value;
	uint16  max_val;								// ���ֵ
	uint16  min_val;								// ��Сֵ
	uint32  text_id;								// ��ʼ����ID
	uint32   *ptext;								// ȫ�ֻ�̬����
}SPIN_EDIT_INFO, *PSPIN_EDIT_INFO;

typedef enum
{
	KEYBOARD_MODE0 = 0,					     		// �׵����밴��
	KEYBOARD_MODE1,							 		// �Խ�����	
	KEYBOARD_MODE2,                          		// �ڵ����밴��
}KEYBOARD_STYLE;									

typedef struct
{
	//PGUI_FORM ParentFrm;							// ������
	uint8 InputNum;									// ��������
	#ifdef _E81S_UI_STYLE_
	HWND InputhDlg[5];                         		// �������
	#else	
	HWND InputhDlg[2];                         		// �������
	#endif
	int8 Max;							    		// ���
	KEYBOARD_STYLE Mode;							// ģʽ 
	uint8 Enable;									// ʹ��
	int8 KeyValue;						    		// ��ֵ	
	uint8 State;									// ����״̬
	uint8 IPmode;									// IPģʽ
}KEYBOARD_INFO, *PKEYBOARD_INFO;


typedef struct
{
	uint32 TextID;									// ���ݵ�����ID
	uint32 ImageID;								    // ���ݵ�ͼƬID
	char name[30];									// ���ݵ������ַ���
	char *text;                                     // ��Ϣ����
	char date[80];                                  // ���ݵ�ʱ���ַ���
}EVE_INFO, *PEVE_INFO;

#if 0
typedef struct
{
	list_t list;
	EVE_INFO Buttons;							// ����
}LIST_MSG_DATE, * PLIST_MSG_DATE;

typedef struct
{
	uint32	MaxListCount;							// �ܹ���ʾ����
	uint32  Page_Col;                               // ÿҳ��ʾ����
	uint32  Page_Count;								// ÿҳ��ʾ������
	uint32  Select;									// ��ǰѡ�еĸ���
	int		one_w;									// ���еĿ��
	int		one_h;									// ���еĸ߶�
	uint8   del_enable;								// �Ƿ�����ɾ��
	uint32   TextID;                                // ���������
	list_t listItem;								// �б���
}MSG_DATE, *PMSG_DATE;
#endif

typedef struct
{
	uint8 MaxValue;
	uint8 NowValue;
	uint8 enable;
}VOLUME_INFO, *PVOLUME_INFO;

#if 0
typedef struct
{
	DWORD   status;         	// status of box
	RECT    rcText;          	// content rect
	char	numtext[31];    	// string text buffer
	int		numlen;
	uint32  BKColor;			
	char *  hint;				//hintΪNULLʱΪ����ģʽ
	int		mode;				//0��һ���ʽ  1:���ָ�ʽ,2��ʱ���ʽ;3:IP�����ʽ
	int 	selpos;				//��ǰ����λ�ã���mode=3 ʱΪIP�Ķ��е�ĳ�� Add by hxf 2006.10.14
	int 	Maxchar;			//����ַ�����
	int 	ippos[4];				//
	char 	ip[4][3];			//4�Σ��ֵ
	int 	selposBegin;
	int 	selposEnd;				
}LFLAT_EDIT_DATA, *PLFLAT_EDIT_DATA;
#endif

typedef enum
{
	PASS_ADMIN,										// ����Ա����
	PASS_USER,										// �û�����
	PASS_DOOR,										// ��������
}AU_PASS_TYPE;

typedef enum
{
	SYTLE_NONE			= 0x00,						// ��								
	STYLE_PICTURE_SOUND = 0x11,						// ����+ͼƬ
	STYLE_ONLY_SOUND    = 0x12,
}ITEM_STYLE;

#if 0
typedef struct
{
	list_t list;
	uint8 IsRead;									// �Ƿ���� 0δ�� 1����
	ITEM_STYLE style;								// �����ø�����
	char *text;										// ��������(ȫ��·��)
	char *name;										// ��������(�ļ���)
}EXPLORER_ITEM, *PEXPLORER_ITEM;					// ���ڸ��ĵ������ڽṹ
#endif

typedef enum
{
	STATE_NONE = 0x10,
	STATE_STOP,
	STATE_PLAY,
	STATE_REC,
}PLAY_STATE;

typedef struct
{
	uint8 kind;                                     // �ҵ�����  0:�ƹ����  1:�¶ȵ���
	uint8 value;                                    // ��ǰ��ֵ
	uint8 state;                                    // ����״̬  0:��  1:��
	uint8 MaxValue;                                 // ����ֵ
	uint16 addr;                                    // �豸��ַ
}JIADIAN_ITEM, *PJIADIAN_ITEM;

typedef enum
{ 
	MODE_NONE      =   0,							// ����ʾ
	MODE_COMMON    =   1,							// ��ʾ���Ե���(<-->)	
	MODE_LIGHT     =   2,							// �ƹ�ɵ���
	MODE_AIR	   =   3,							// �յ��ɵ���
} SINGLELINE_MODE;									// ���е�����

typedef enum
{
	VOLUME_MUTE = 1,                                // ����
	VOLUME_DEL,                                     // ������
	VOLUME_ADD,	                                    // ������
} VOLUME_TYPE;

/**********************�ṹ�嶨��************************/

/************************�ⲿ����************************/
// ע��ؼ�
BOOL register_input_ctrl(void);
BOOL register_right_button(void);
BOOL register_num_keybord(void);
BOOL register_list_ctrl(void);
BOOL register_eightarea_ctrl(void);
BOOL register_spin_ctrl(void);
BOOL register_procress_ctrl(void);
#if 0
BOOL register_chose_button(void);
BOOL register_area_button(void);
BOOL register_key_button(void);
BOOL register_spin_edit(void);
BOOL register_msg_button(void);
BOOL register_volume_button(void);
BOOL register_au_flat_edit(void);
#endif

// ж�ؿؼ�
void unregister_input_ctrl(void);
void unregister_right_button(void);
void unregister_num_keybord(void);
void unregister_list_ctrl(void);
void unregister_eightarea_ctrl(void);
void unregister_spin_ctrl(void);
void unregister_procress_ctrl(void);
#if 0
void unregister_chose_button(void);
void unregister_area_button(void);
void unregister_key_button(void);
void unregister_spin_edit(void);
void unregister_msg_button(void);
void unregister_volume_button(void);
void unregister_au_flat_edit(void);
#endif

// ��������
extern void ui_callout_appstart(DEVICE_TYPE_E DevType, char *DevNo);
extern void ui_monitor_appstart(DEVICE_TYPE_E DevType, uint8 index);

#ifdef __cplusplus
}
#endif
#endif

