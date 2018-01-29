/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	au_model_func.c
  Author:     	luofl
  Version:    	2.0
  Date: 		2014-09-01
  Description:  
				GUI�Ĺ����������
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
//#include "AppConfig.h"
#include "storage_include.h"
#include "gui_include.h"

typedef struct hiRECT_S
{
    uint32   x;
    uint32   y;
    uint32   width;
    uint32   height;
}RECT_S, * PRECT_S;

#define FONT_TYPE		FONT_TYPE_NAME_ALL			// ��������
#define FONT_COUNT		5							// �������
#define FONT_ABC_COUNT	3							// Ӣ�������������
#define	FORM_COUNT		50							// ���������

static int g_FontSize[FONT_COUNT] = {FONT_16, FONT_20, FONT_22, FONT_24, FONT_28};		// �߼������С
static PLOGFONT g_FontBIG5[FONT_COUNT];				// Big5��������
static PLOGFONT g_FontBIG5Bold[FONT_COUNT];			// Big5��������
static PLOGFONT g_FontGB[FONT_COUNT];				// GB2312��������
static PLOGFONT g_FontGBBold[FONT_COUNT];			// GB2312��������
static int g_FontABCSize[FONT_ABC_COUNT] = {FONT_12, FONT_16, FONT_20};			// Ӣ�������С  			
static PLOGFONT g_FontABC[FONT_ABC_COUNT];			// ABC��������	
static PLOGFONT g_FontABCBold[FONT_ABC_COUNT];		// ABC��������

static int8 g_Skin = SKIN_1;						// Ƥ������ 1, 2, 3, 4;
static PBITMAP g_SkinBmp = NULL;					// Ƥ��������ͼƬָ��
static uint8 SkinFileNotExist = false;				// Ƥ�������ļ��Ƿ����

static PGUI_FORM g_ShowForms[FORM_COUNT];			// ��ʾ�Ĵ���
static uint8 g_ShowFormCount = 0;					// ����ĸ���
static HWND g_FullScreenhWnd = 0;					// ȫ���ľ��
//static HWND g_LastScreenhWnd = 0;					// ʹ��ȫ���Ĵ�����
static RECT_S *g_oldVideoRc;						// ��Ļ������
static uint8 g_isFullScreenState = false;			// ȫ����״̬ false û��ȫ�� true ȫ��
static uint8 g_IsVideoFull = false;					// ȫ���Ƿ�����Ƶ false û��ȫ�� true ȫ��

static uint8 g_FormClose = FALSE;
extern uint8 Icon_state[STYLE_MAIN_COUNT];			// ������Сͼ��״̬

/**************************/
/*	   ����������ж�  	  */
/**************************/
static int16 g_MaxLcdTime = 100;					// �������ʱ�����
//static int16 g_MaxScreenTime = 100;				// ��Ļ�����������ʱ�����
static int16 g_LcdTime = 100;						// ����ʱ�����
//static int16 g_ScreenTime = 100;					// ��Ļ��������ʱ�����
//static uint8 g_ScreenState = SCREENPORTECT_OFF;	// ��Ļ����״̬	
//static uint16 g_NofaceTime = 100;					// �����ʱ��

/*************************************************
  Function:    		InitLogFont
  Description:		��ʼ������
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void InitLogFont(void)
{
	uint8 i;
	
	for (i = 0; i < FONT_COUNT; i++)
	{
		#if 0
		g_FontBIG5[i] = CreateLogFont(FONT_TYPE, "ming", "g_Big5", 
						FONT_WEIGHT_REGULAR, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);
						
		g_FontBIG5Bold[i] = CreateLogFont(FONT_TYPE, "ming", "g_Big5", 
						FONT_WEIGHT_BOLD, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);
		
		g_FontGB[i] = CreateLogFont(FONT_TYPE, "song", "GB2312",
						FONT_WEIGHT_REGULAR, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);

		g_FontGBBold[i] = CreateLogFont(FONT_TYPE, "song", "GB2312", 
						FONT_WEIGHT_BOLD, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);
		#else
		g_FontBIG5[i] = CreateLogFont(FONT_TYPE, "song", FONT_CHARSET_GB2312_0, 
						FONT_WEIGHT_BOOK, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);
						
		g_FontBIG5Bold[i] = CreateLogFont(FONT_TYPE, "song", FONT_CHARSET_GB2312_0, 
						FONT_WEIGHT_DEMIBOLD, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);

		g_FontGB[i] = CreateLogFont (FONT_TYPE, "fixed", FONT_CHARSET_GB2312_0,
						FONT_WEIGHT_BOOK, FONT_SLANT_ROMAN, FONT_FLIP_NIL,
						FONT_FLIP_NIL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE,
						g_FontSize[i], 0);

		g_FontGBBold[i] = CreateLogFont(FONT_TYPE, "fixed", FONT_CHARSET_GB2312_0, 
						FONT_WEIGHT_DEMIBOLD, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontSize[i], 0);
		#endif
	}			

	for (i = 0; i < FONT_ABC_COUNT; i++)
	{
		#if 0
		g_FontABC[i] = CreateLogFont(FONT_TYPE, "Arial", "ascii", 
						FONT_WEIGHT_REGULAR, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontABCSize[i], 0);
	
		g_FontABCBold[i] = CreateLogFont(FONT_TYPE, "Arial", "ascii", 
						FONT_WEIGHT_BOLD, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontABCSize[i], 0);
		#else
		g_FontABC[i] = CreateLogFont(FONT_TYPE, "times", FONT_CHARSET_ISO8859_1, 
						FONT_WEIGHT_BOOK, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontABCSize[i], 0);

		g_FontABCBold[i] = CreateLogFont(FONT_TYPE, "times", FONT_CHARSET_ISO8859_1, 
						FONT_WEIGHT_DEMIBOLD, FONT_SLANT_ROMAN, FONT_SETWIDTH_NORMAL,
						FONT_SPACING_CHARCELL, FONT_UNDERLINE_NONE, FONT_STRUCKOUT_NONE, 
						g_FontABCSize[i], 0);
		#endif
	}	
}

/*************************************************
  Function:    		FreeLogFont
  Description:		�ͷ�����
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void FreeLogFont(void)
{
	uint8 i;
	
	for (i = 0; i < FONT_COUNT; i++)
	{
		DestroyLogFont(g_FontBIG5[i]);
		DestroyLogFont(g_FontBIG5Bold[i]);
		DestroyLogFont(g_FontGB[i]);
		DestroyLogFont(g_FontGBBold[i]);
	}

	for (i = 0; i < FONT_ABC_COUNT; i++)
	{
		DestroyLogFont(g_FontABC[i]);
		DestroyLogFont(g_FontABCBold[i]);
	}
}

/*************************************************
  Function:    		GetFont
  Description:		�������
  Input: 			
  	1.size			(FONT_12--->FONT_24)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetFont(int8 size)
{
	int8 i, index = -1 ;

	if (ENGLISH == storage_get_language())
	{
		for (i = 0; i < FONT_ABC_COUNT; i++)
		{
			if (size == g_FontABCSize[i])
			{
				index = i;
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < FONT_COUNT; i++)
		{
			if (size == g_FontSize[i])
			{
				index = i;
				break;
			}
		}
	}
	
	if (-1 == index)
	{
		return NULL;
	}

	switch (storage_get_language())
	{
		case ENGLISH:
			return g_FontABC[index];
			break;

		case CHNBIG5:
			return g_FontBIG5[index];
			break;

		default:
		case CHINESE:
			return g_FontGB[index];
			break;
	}
}

#if 0
/*************************************************
  Function:    		GetChineseFont
  Description:		�������
  Input:
  	1.kind         0:ȡ���w����   1:ȡ��������
  	1.size			(FONT_12--->FONT_24)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetChineseFont(int8 kind, int8 size)
{
	int8 i, index = -1 ;

	for (i = 0; i < FONT_COUNT; i++)
	{
		if (size == g_FontSize[i])
		{
			index = i;
			break;
		}
	}
	
	if (-1 == index)
	{
		return NULL;
	}
	
	switch (kind)
	{
		case 0:
			return g_FontBIG5Bold[index];
			break;

		case 1:
		default:
			return g_FontGBBold[index];
			break;
	}
}
#endif

/*************************************************
  Function:    		GetBoldFont
  Description:		��ô�������
  Input: 			
  	1.size			(FONT_12--->FONT_24)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetBoldFont(int8 size)
{
	int8 i, index = -1 ;
	
	if (ENGLISH == storage_get_language())
	{
		for (i = 0; i < FONT_ABC_COUNT; i++)
		{
			if (size == g_FontABCSize[i])
			{
				index = i;
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < FONT_COUNT; i++)
		{
			if (size == g_FontSize[i])
			{
				index = i;
				break;
			}
		}
	}
	if (-1 == index)
	{
		return NULL;
	}
	
	switch (storage_get_language())
	{
		case ENGLISH:
			return g_FontABCBold[index];
			break;

		case CHNBIG5:
			return g_FontBIG5Bold[index];
			break;

		default:
		case CHINESE:
			return g_FontGBBold[index];
			break;
	}
}

/*************************************************
  Function:    		GetFont_ABC
  Description:		��ô���ABC������
  Input: 			
  	1.size			(FONT_24,FONT_26)
  Output:			��
  Return:			(��ȷ)�߼����壬(����)NULL
  Others:
*************************************************/
PLOGFONT GetFont_ABC(int8 size)
{
	int8 i, index = -1;
	
	for (i = 0; i < FONT_ABC_COUNT; i++)
	{
		if (size == g_FontABCSize[i])
		{
			index = i;
			break;
		}
	}
	
	if (-1 == index)
	{	
		return NULL;
	}
	
	switch (storage_get_language())
	{
		case CHINESE:
		case ENGLISH:
		case CHNBIG5:
			//return g_FontABCBold[index];
			return g_FontABC[index];
			break;
			
		default:
			return NULL;
	}
}


/*************************************************
  Function:    		DrawTextFont
  Description:		��Ӣ��ttf�ֿ�g��y����ĸ��ʾ��ȫ��������·�װ
  Input: 			��
  Output:			��
  Return:			��
  Others:			��
*************************************************/
void  DrawTextFont(HDC hdc, const char* pText, int nCount, RECT* pRect, uint32 nFormat)
{
	if (storage_get_language() == ENGLISH)
	{
		pRect->top -= ADD_ENGLISH_SIZE;
		pRect->bottom += ADD_ENGLISH_SIZE;
	}
	DrawText(hdc, pText, nCount, pRect, nFormat);
}

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
uint8 set_skin(int8 mode)
{
	if (mode > 0 && g_SkinBmp != NULL && mode <= g_SkinBmp->bmHeight)
	{
		g_Skin = mode;		
		reload_bmp_by_skin();
		return true;
	}
	
	return false;
}

/*************************************************
  Function:    		get_skin_count
  Description:		���Ƥ����������
  Input: 			��
  Output:			��
  Return:			Ƥ����������Ŀ������ͼƬ�����ڵķ���1
  Others:
*************************************************/
uint8 get_skin_count(void)
{
	if (g_SkinBmp != NULL)
	{
		return g_SkinBmp->bmHeight;
	}
	
	return 1;
}

/*************************************************
  Function:    		get_skin
  Description:		���Ƥ������
  Input: 			��
  Output:			��
  Return:			��������(SKIN_1--->SKIN_4)
  Others:
*************************************************/
uint8 get_skin(void)
{
	return g_Skin;
}

/*************************************************
  Function:    		GetSysColor
  Description:		���ϵͳ��ɫ
  Input: 			
  	1.id			ID
  Output:			��
  Return:			��ɫ
  Others:
*************************************************/
uint32 GetSysColor(int id)
{
	if (g_SkinBmp==NULL && !SkinFileNotExist)
	{
		g_SkinBmp = (PBITMAP)malloc(sizeof(BITMAP));
		if (0!=LoadBitmapFromFile((HDC)NULL, g_SkinBmp, SKIN_FILE))
		{
			SkinFileNotExist = true;
			free(g_SkinBmp);
			g_SkinBmp = NULL;
		}
	}
	
	if (g_SkinBmp==NULL)
	{
		return 0;	
	}
	
	if (id < 0 || id >= g_SkinBmp->bmWidth)
	{
		return 0;
	}
	
	return GetPixelInBitmap(g_SkinBmp, id, g_Skin-1);
}

/********************************************************/
/*			           ������غ���                     */	
/********************************************************/

/*************************************************
  Function:    		add_show
  Description:		��Ӵ���
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
static void add_show(PGUI_FORM frm)
{
	uint8 i, j;
	
	for (i = 1; i < g_ShowFormCount; i++)
	{
		if (g_ShowForms[i] == frm)
		{
			g_ShowFormCount--;
			for (j = i; j < g_ShowFormCount; j++)
			{
				g_ShowForms[j] = g_ShowForms[j+1];
			}		
			break;
		}
	}
	g_ShowForms[g_ShowFormCount++] = frm;
}

/*************************************************
  Function:    		init_frm_language
  Description:		��ʼ����������
  Input: 			
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
void init_frm_language(void)
{
	uint8 i;
	uint8 lan = storage_get_language();
	uint8 skin = get_skin();
	
	for (i = 1; i < g_ShowFormCount; i++)
	{
		log_printf("i = %d, lan = %d, skin = %d\n",i, lan, skin);
		g_ShowForms[i]->language = lan;
		g_ShowForms[i]->skin = skin;
	}
}

/*************************************************
  Function:    		del_show
  Description:		ɾ������
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			�ɹ����
  Others:
*************************************************/
static void del_show(PGUI_FORM frm)
{
	uint8 i, j;
	
	for (i = g_ShowFormCount-1; i > 0; i--)
	{
		if (g_ShowForms[i] == frm)
		{
			g_ShowFormCount--;
			for (j = i; j < g_ShowFormCount; j++)
			{
				g_ShowForms[j] = g_ShowForms[j+1];
			}
			break;
		}
	}
}

/*************************************************
  Function:    		get_cur_form
  Description:		�õ���ǰ��ʾ�Ĵ���
  Input: 			
  Output:			��
  Return:			��ǰ��ʾ�Ĵ���
  Others:
*************************************************/
PGUI_FORM get_cur_form(void)
{
	if (g_ShowFormCount > 0)
	{
		return g_ShowForms[g_ShowFormCount-1];
	}
	else
	{
		return NULL;
	}	
}

/*************************************************
  Function:    		get_cur_hDlg
  Description:		��ȡ��ǰ������
  Input: 			��
  Output:			��
  Return:			��ǰ����ľ��
  Others:
*************************************************/
HWND get_cur_hDlg(void)
{
	PGUI_FORM frm = get_cur_form();
	if (frm == NULL)
	{
		log_printf("get_cur_form is NULL!\n");
		return FALSE;
	}
	else
	{
		return frm->hWnd;
	}
}

/*************************************************
  Function:    		form_show
  Description:		��ʾ��ģ̬����
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			�ɹ�(true)���(false)
  Others:
*************************************************/
uint8 form_show(PGUI_FORM frm)
{
	if (frm->IsDlg == 1)
	{
		return false;
	}
	
	close_msg_page(&FrmMsgCtrl);
	log_printf("%s  %d\n", __FUNCTION__, __LINE__);
	if (form_create(frm) != 0)
	{
		//ShowWindow(frm->hWnd, SW_SHOW);
		//ShowWindow(frm->hWnd, SW_SHOWNORMAL);
		//frm->Parent = get_cur_form();
		add_show(frm);
		return true;
	}
	
	return false;
}

/*************************************************
  Function:    		form_hide
  Description:		���ش���(ģ̬ʱ,�رմ���)
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void form_hide(PGUI_FORM frm)
{
	if (frm->hWnd)
	{
		if (frm->IsDlg == 1)
		{
			EndDialog(frm->hWnd, 0);
			frm->hWnd = 0;
		}
		else
		{
			ShowWindow(frm->hWnd, SW_HIDE);
			SetActiveWindow(frm->Parent->hWnd);
			log_printf("frm->hWnd: %x  frm->Parent->hWnd: %x\n", frm->hWnd, frm->Parent->hWnd);
		}
		del_show(frm);
	}
}

/*************************************************
  Function:    		form_close
  Description:		�رմ���
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void form_close(PGUI_FORM frm)
{
	if (g_FormClose)
	{
		return;
	}
	if (frm->hWnd) 
	{
		if (frm->IsDlg == 1)
		{
			EndDialog(frm->hWnd, 0);
		}
		else
		{
			g_FormClose = TRUE;
			log_printf("DestroyAllControls.......start hwnd: %x\n",frm->hWnd);
			// ���ٱ����������е��ӿؼ�
			DestroyAllControls(frm->hWnd);
			usleep(100*1000);
			log_printf("DestroyAllControls.......end hwnd: %x\n",frm->hWnd);
			NT_BOOL bret = DestroyMainWindowIndirect(frm->hWnd);
			if (bret)
			{
				log_printf("DestroyMainWindowIndirect OK! hwnd: %x\n", frm->hWnd);
			}	
			else
			{
				log_printf("DestroyMainWindowIndirect ERROR!!! hwnd: %x\n", frm->hWnd);
			}	
		}
		del_show(frm);
		frm->hWnd = 0;
		g_FormClose = FALSE;
	}
}

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
int DefaultMsgProc(PGUI_FORM frm, HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
	if (1 == frm->IsDlg)
	{
		return DefaultDialogProc(hDlg, message, wParam, lParam);
	}
	else
	{
		return DefaultMainWinProc(hDlg, message, wParam, lParam);
	}
}

#if 0
/*************************************************
  Function:    		system_reboot_app
  Description:		��������Ӧ��
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void system_reboot_app(void)
{
	system("/mnt/nand1-1/reboot_script");
}
#endif

/*************************************************
  Function:    		form_showmodal
  Description:		��ʾ����(ģ̬,����������)
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			�ɹ�(true)���(false)
  Others:
*************************************************/
int form_showmodal(PGUI_FORM frm)
{
	if (NULL == frm || NULL == frm->pDlgTemplate)
	{
		return 0;
	}
	
	if (0 != frm->hWnd)
	{
		form_close(frm);
	}	
	
	uint8 lan = storage_get_language();
	if (frm->language != lan)
	{
		//frm->ChangeLanguage();
		frm->language = lan;
	}
	
	HWND hParent = HWND_DESKTOP; 
	if (frm->Parent != NULL)
	{
		hParent = frm->Parent->hWnd;
	}	
	frm->IsDlg = 1;
	add_show(frm);
	int ret = DialogBoxIndirectParam(frm->pDlgTemplate, hParent, frm->WinProc, 0L);
	frm->IsDlg = 0;
	frm->hWnd = 0;
	
	return ret;
}

/*************************************************
  Function:    		form_create
  Description:		��������(��ģ̬)
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			������
  Others:
*************************************************/
HWND form_create(PGUI_FORM frm)
{
	if (NULL == frm || NULL == frm->pDlgTemplate)
	{
		return 0;
	}

	uint8 lan = storage_get_language();
	uint8 skin = get_skin();

	//log_printf("%s  lan: %d ski: %d\n ", __FUNCTION__, lan, skin);
	//log_printf("%s  lan: %d ski: %d\n ", __FUNCTION__, frm->language, frm->skin);
	frm->Parent = get_cur_form();
	if (0 != frm->hWnd)
	{		
		if (frm->skin != skin)
		{
			SetWindowBkColor(frm->hWnd, PAGE_BK_COLOR);
			frm->skin = skin;
		}
		
		if (frm->language == lan)
		{
			log_printf("frm->hWnd = %0x retutn !!!!!!!!\n",frm->hWnd);
			ShowWindow(frm->hWnd, SW_SHOWNORMAL); //add by caogw ��ֹ����δ�رպ��޷���ʾ����
			return frm->hWnd;
		}
		else
		{
			form_close(frm);
		}		
	}

	log_printf("%s  %d\n", __FUNCTION__, __LINE__);
	HWND hParent = HWND_DESKTOP;
	if (frm->Parent != NULL)
	{
		hParent = frm->Parent->hWnd;
		log_printf("%s  %d hParent = %0x\n", __FUNCTION__, __LINE__,hParent);
	}
	
	if (frm->language != lan)
	{
		//frm->ChangeLanguage();
		frm->language = lan;
	}
	frm->skin = skin;
	frm->hWnd = CreateMainWindowIndirect(frm->pDlgTemplate, hParent, frm->WinProc); 
	if (frm->hWnd == 0xFFFFFFFF)
	{
		log_printf("CreateMainWindowIndirect ERROR!!! hwnd: %x\n", frm->hWnd);
		//system_reboot_app();
		hw_stop_feet_dog();
		frm->hWnd = 0;
		return 0;
	}
	log_printf("CreateMainWindowIndirect OK! hwnd: %x\n", frm->hWnd);
	
	return frm->hWnd;
}

/*************************************************
  Function:    		exit_page
  Description:		�˳�ҳ��
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
void exit_page(void)
{
	if (g_ShowFormCount > 1)
	{
		form_hide(g_ShowForms[g_ShowFormCount-1]);
	}	
}

/*************************************************
  Function:    		parent_page
  Description:		����ǰһ������ľ��
  Input: 			
  	1.frm			��������
  Output:			��
  Return:			��
  Others:
*************************************************/
HWND parent_page(void)
{
	if (g_ShowFormCount > 1)
	{
		return(g_ShowForms[g_ShowFormCount-2]->hWnd);
	}	
}

/*************************************************
  Function:    		exit_the_page
  Description:		�˳���ǰҳ��
  Input: 			
  	frm				��ǰ�����ַ
  Output:			��
  Return:			��
  Others:
*************************************************/
void exit_the_page(PGUI_FORM frm)
{
	if (g_ShowFormCount > 1)
	{
		form_hide(frm);
	}	
}

/*************************************************
  Function:    		close_msg_page
  Description:		�ر���Ϣ��ҳ��
  Input: 			��
  Output:			��
  Return:			��
  Others:			�ر���Ϣ�򣬷�ֹ��Ϣ����Ϊ�����ڣ�
  					�����������⡣
*************************************************/
void close_msg_page(PGUI_FORM frm)
{
	if (frm->hWnd)
	{	
		form_close(frm);
		//SendMessage(frm->hWnd, WM_MSG_Close, 0, 0);
	}
}

/*************************************************
  Function:    		back_main_page
  Description:		�˻���ҳ��
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
void back_main_page(void)
{
	uint8 i;
	
	log_printf("g_ShowFormCount = %d\n", g_ShowFormCount);
	for (i = g_ShowFormCount-1; i > 0; i--)
	{
		form_hide(g_ShowForms[i]);
		g_ShowForms[i] = NULL;
	}
	g_ShowFormCount = 1;
}

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
void set_windowsize(PGUI_FORM frm, int x, int y, int w, int h)
{
	frm->pDlgTemplate->x = x;
	frm->pDlgTemplate->y = y;
	frm->pDlgTemplate->w = w;
	frm->pDlgTemplate->h = h;
}

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
void show_msg(HWND hDlg , uint32 ID, AU_MSG_TYPE style, uint32 TextID)
{
	MSG_INFO info;
	
	memset(&info, 0, sizeof(MSG_INFO));
	info.VideoMode = 0;
	info.Mode = style;
	info.TextID = TextID;
	info.parent = hDlg;
	info.ID = ID;
	
	info.MsgBk = BID_Msg_BK2;
	switch (style)
	{
		case MSG_TS:
		case MSG_QUERY:		
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			info.MsgBk = BID_QueryBoxBK;
			#endif
			info.MsgIcon = BID_MsgQueryIcon;
			break;
			
		case MSG_WARNING:
		case MSG_ERROR:
		case MSG_HIT:
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			info.MsgBk = BID_MsgBoxBK;
			#endif
			info.MsgIcon = BID_MsgInfoIcon;
			break;
			
		case MSG_RIGHT:
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			info.MsgBk = BID_MsgBoxBK;
			info.MsgIcon = BID_MsgInfoIcon;
			#else
			info.MsgIcon = BID_MsgRight;
			#endif
			break;
			
		default:
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			info.MsgBk = BID_MsgBoxBK;
			#endif
			info.MsgIcon = BID_MsgInfoIcon;
			break;	
	}

	#if (_UI_STYLE_ == _E81S_UI_STYLE_)
	if (style == MSG_TS || style == MSG_QUERY)
	{
		set_windowsize(&FrmMsgCtrl, FORM_QUERY_X, FORM_QUERY_Y, FORM_QUERY_W, FORM_QUERY_H);
	}
	else
	#endif
	{
		set_windowsize(&FrmMsgCtrl, FORM_MSG_X, FORM_MSG_Y, FORM_MSG_W, FORM_MSG_H);
	}
		
	ui_msg_win(&info);
}

#if (_UI_STYLE_ == _E81S_UI_STYLE_)
/*************************************************
  Function:		show_aurine_msg_hit
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
void show_aurine_msg_hit(HWND hDlg, uint32 ID, AU_MSG_TYPE style, uint32 TextID)
{
	MSG_INFO info;
	
	memset(&info,0,sizeof(MSG_INFO));
	info.VideoMode = 0;
	info.Mode = style;
	info.TextID = TextID;
	info.parent = hDlg;
	info.ID = ID;
	switch (style)
	{		
		case MSG_ALARM:
			info.MsgBk = BID_MsgBoxAlarm;
			break;
			
		case MSG_MESSAGE:
			info.MsgBk = BID_MsgBoxMsg;
			break;
			
		case MSG_CALL_MESSAGE:
			info.MsgBk = BID_MsgBoxCallIn;
			break;

		default:
			break;
	}	
	set_windowsize(&FrmMsgCtrl, FORM_HIT_X, FORM_HIT_Y, FORM_HIT_W, FORM_HIT_H);
	ui_msg_win(&info);
}
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
void show_msg_hit(HWND hDlg, uint32 ID, AU_MSG_TYPE style, uint32 TextID)
{
	MSG_INFO info;
	
	memset(&info,0,sizeof(MSG_INFO));
	info.VideoMode = 0;
	info.Mode = style;
	info.TextID = TextID;
	info.parent = hDlg;
	info.ID = ID;
	info.MsgBk = BID_Msg_BK1;
	switch (style)
	{		
		case MSG_ALARM:
			info.MsgIcon = BID_MsgBoxAlarm;
			break;
			
		case MSG_MESSAGE:
			info.MsgIcon = BID_MsgBoxMsg;
			break;
			
		case MSG_CALL_MESSAGE:
			info.MsgIcon = BID_MsgBoxCallIn;
			break;

		default:
			break;
	}
	set_windowsize(&FrmMsgCtrl, FORM_MSG_X, FORM_MSG_Y, FORM_MSG_W, FORM_MSG_H);
	ui_msg_win(&info);
}

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
void show_msg_pass(HWND hDlg, uint32 id, PASS_TYPE type, uint8 xiechi)
{
	MSG_INFO info;
	
	memset(&info, 0, sizeof(MSG_INFO));
	info.xiechi = xiechi;
	info.parent = hDlg;
	info.ID = id;
	memset(info.adminPass, 0, sizeof(info.adminPass));
	memset(info.Pass, 0, sizeof(info.Pass));
	sprintf(info.adminPass, "%s", storage_get_pass(PASS_TYPE_ADMIN));
	sprintf(info.Pass, "%s", storage_get_pass(type));
	
	ui_passin_win(&info);
}

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
void show_msg_jd_addr(HWND hDlg , uint32 ID, uint16 startaddr, uint16 endaddr)
{
    MSG_INFO info;
    memset(&info,0,sizeof(MSG_INFO));
	info.parent = hDlg;
    info.VideoMode = 0;
    info.Mode = MSG_JDADDR;
    info.echo = 1;
    info.AddrStart = startaddr;
    info.AddrEnd = endaddr;
    info.Hit = 0;
	info.CtrlID = ID;
    #ifdef _AURINE_ELEC_NEW_
    if (JD_FACTORY_ACBUS == storage_get_extmode(EXT_MODE_JD_FACTORY))
    {
        info.factory = 1;
    }
    else
    {
        info.factory = 0;
    }
    #else
        info.factory = 0;
    #endif
    
    set_windowsize(&FrmMsgCtrl, FORM_PASS_X, FORM_PASS_Y, FORM_PASS_W, FORM_PASS_H);
    ui_msg_win(&info);
}

#ifdef _JD_MODE_
/*************************************************
  Function:     show_msg_jd_control
  Description:  ���Ƶƹ⡢�յ�ǿ��
  Input:        
    1.win       ����
    2.ID        ID
    3.startaddr ��ʼ��ַ
    4.endaddr   ������ַ
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_jd_control(HWND hDlg, uint32 ID, AU_JD_DEV_TYPE devtype, uint8 state, uint8 Value, uint16 *text, uint8 factory)
{
	MSG_INFO info;
    memset(&info,0,sizeof(MSG_INFO));
    info.VideoMode = 0;
    info.Mode = MSG_JD_TJ;
    info.echo = 1;
    info.devtype = devtype;
    info.devstate = state;
	info.CtrlID = ID;
	info.parent = hDlg;
	
    if (JD_DEV_LIGHT == devtype)
    {
        info.factory = factory;
        info.devMaxValue = MAX_LIGHT_VAULE;
        info.devNowValue = Value;
        
        if (info.factory == 1)
        {
            if (0 == Value)
            {
                info.devNowValue = 0;
            }
            info.devMinValue = 0;
        }
        else
        {
            if (0 == Value)
            {
                info.devNowValue = 1;
            }
            info.devMinValue = MIN_LIGHT_VAULE;
        }
        info.ImageID = BID_JD_Light1;
    }
    else
    {
        info.factory = factory;
        info.devMinValue = MIN_KONGTIAO_VAULE;
        info.devMaxValue = MAX_KONGTIAO_VAULE;
        info.devNowValue = Value;
        #if 0
        if (info.factory == 1)
        {
            if (0 == Value)
            {
                info.devNowValue = 0;
            }
            info.devMinValue = 0;
        }
        else
        {
            if (0 == Value)
            {
                info.devNowValue = 1;
            }
            info.devMinValue = MIN_KONGTIAO_VAULE;
        }
        #else
        if (0 == Value)
        {
            info.devNowValue = 1;
        }
        info.devMinValue = MIN_KONGTIAO_VAULE;
        #endif

        info.ImageID = BID_JD_Kongtiao1;
    }
    if (text)
    {	
        memcpy(info.DevName, text, 30);
    }   
    set_windowsize(&FrmMsgCtrl, FORM_JD_CONTROL_X, FORM_JD_CONTROL_Y, FORM_JD_CONTROL_W, FORM_JD_CONTROL_H);
    ui_msg_win(&info);
}

/*************************************************
  Function:     show_msg_tabus_jd_control
  Description:  �������յ�����
  Input:        
    1.win       ����
    2.ID        ID
    3.startaddr ��ʼ��ַ
    4.endaddr   ������ַ
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void show_msg_tabus_jd_control(HWND hDlg , uint32 ID, AU_JD_DEV_TYPE devtype, uint8 state,  uint8 Value, uint16 *text, uint8 style,uint8 flag)
{
    MSG_INFO info;
    memset(&info,0,sizeof(MSG_INFO));
	info.parent = hDlg;
    info.VideoMode = 0;
    info.Mode = MSG_AURINE_JD_TJ;
    info.echo = 1;
    info.devtype = devtype;
    info.devstate = state;
	info.CtrlID = ID;
    
    if (JD_DEV_KONGTIAO == devtype)
    {
        info.devMinValue = MIN_KONGTIAO_VAULE;
        info.devMaxValue = MAX_KONGTIAO_VAULE;
        info.devNowValue = Value;
        info.style = style;
        if (info.style == 0)
        {
            info.flag = flag;
        }
        if (0 == Value)
        {
            info.devNowValue = 1;
        }
        
        info.ImageID = BID_JD_Kongtiao1;
    }
    else if (JD_DEV_WINDOW == devtype)
    {  
        info.ImageID = BID_JD_Window1;
    }
    if (text)
    {
        memcpy(info.DevName, text, 30);
    }
    
    set_windowsize(&FrmMsgCtrl, FORM_JD_CONTROL_X, FORM_JD_CONTROL_KT_Y, FORM_JD_CONTROL_W, FORM_JD_CONTROL_KT_H);
    ui_msg_win(&info);
}
#endif

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
void show_msg_ipmodule_code(HWND hDlg , uint32 ID)
{
    MSG_INFO info;
    memset(&info,0,sizeof(MSG_INFO));
    info.VideoMode = 0;
    info.Mode = MSG_IPCODE;
    info.echo = 1;
	info.CtrlID = ID;
	info.parent = hDlg;
   	set_windowsize(&FrmMsgCtrl, FORM_PASS_X, FORM_PASS_Y, FORM_PASS_W, FORM_PASS_H);
    ui_msg_win(&info);
}

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
void show_msg_hit(HWND hDlg, uint32 ID, AU_MSG_TYPE style, uint32 TextID)
{
	MSG_INFO info;
	memset(&info,0,sizeof(MSG_INFO));
	info.VideoMode = 0;
	info.Mode = style;
	info.TextID = TextID;
	info.parent = hDlg;
	info.CtrlID = ID;
	switch (style)
	{		
		case MSG_ALARM:
			info.BmpBkID = BID_MsgBoxAlarm;
			break;
			
		case MSG_MESSAGE:
			info.BmpBkID = BID_MsgBoxMsg;
			break;
			
		case MSG_CALL_MESSAGE:
			info.BmpBkID = BID_MsgBoxCallIn;
			break;

		default:
			break;
	}	
	set_windowsize(&FrmMsgCtrl, FORM_HIT_X, FORM_HIT_Y, FORM_HIT_W, FORM_HIT_H);
    ui_msg_win(&info);
}
#endif

/*************************************************
  Function:			ToRightPwd
  Description: 		ת������ȷ������
  Input: 		
	1.nPwd			����
	2.bAdd			�Ƿ�ת��
  Output:			��
  Return:			��ȷ����
  Others:
*************************************************/
static char ToRightPwd(char nPwd, uint8 bAdd)
{
	char nResult = 0;
	
	if (bAdd)
	{
		if (nPwd == '9')
		{
			nResult = '0';
		}
		else
		{
			nResult = nPwd + 1;
		}
	}
	else
	{
		if (nPwd == '0')
		{
			nResult = '9';
		}
		else
		{
			nResult = nPwd - 1;
		}
	}
	return nResult;
}

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
void toXiechiPwd(char * oldPwd, uint8 bAdd, char * newPwd)
{
	int i;
	int len = strlen(oldPwd);
	char rightPwd ;
	if (len == 0)
	{  
		sprintf(newPwd,"%s","1");
		return;
	}
	
	rightPwd = oldPwd[len-1];
	
	if (rightPwd ==0)
	{
		rightPwd = oldPwd[len-2];
	}
	
	rightPwd = ToRightPwd(rightPwd,bAdd);
		
	for (i = 0; i < len; i++)
	{
		newPwd[i] = oldPwd[i];
		
		if (i == len-2 && oldPwd[len-1] == 0)
		{
			newPwd[i] = rightPwd;
		}	
		else 
		{
			if (i == len-1 && oldPwd[len-1] != 0 )
			{
				newPwd[i] = rightPwd;
			}
		}
	}	
}

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
void change_ip_to_char(uint32 IP, uint8* ipaddr)
{
	uint32 g_IP;
	
	if (ipaddr)
	{
		g_IP = IP;
		ipaddr[0] = ip_addr1(g_IP);
		g_IP = IP;
		ipaddr[1] = ip_addr2(g_IP);
		g_IP = IP;
		ipaddr[2] = ip_addr3(g_IP);
		g_IP = IP;
		ipaddr[3] = ip_addr4(g_IP);
	}
}

/*************************************************
  Function:		change_char_to_ip
  Description:  �л�4���ֽ�ΪIP��ַ
  Input:		
  	1.ipaddr	ip��ַ
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 change_char_to_ip(uint8* ipaddr)
{
	uint32 IP = 0;

	if (ipaddr)
	{
		IP = (((uint32)(ipaddr[0] & 0xff) << 24) | ((uint32)(ipaddr[1] & 0xff) << 16) | \
              ((uint32)(ipaddr[2] & 0xff) << 8) | (uint32)(ipaddr[3] & 0xff));
	}

	return IP;
}

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
void change_ip_to_str(uint32 IP,char *ip)
{
	uint32 g_IP;
	uint8 ipaddr[4] = {0,0,0,0};

	g_IP = IP;
	ipaddr[0] = ip_addr1(g_IP);
	g_IP = IP;
	ipaddr[1] = ip_addr2(g_IP);
	g_IP = IP;
	ipaddr[2] = ip_addr3(g_IP);
	g_IP = IP;
	ipaddr[3] = ip_addr4(g_IP);

	sprintf(ip,"%d.%d.%d.%d",ipaddr[0],ipaddr[1],ipaddr[2],ipaddr[3]);
}

/*************************************************
  Function:			show_sys_event_hint
  Description: 		ϵͳ�¼���ʾ��������Ϣ���������ѵ�
  Input:		
  	1.EventType		�¼�����
  Output:			��
  Return:			��
  Others:
*************************************************/
void show_sys_event_hint(uint16 EventType)
{
	PGUI_FORM CurWin = get_cur_form();
	if (CurWin == NULL)
	{
		log_printf("show msg hint : cur win is null\n");
		return;
	}
	// ����ʾϵͳ�¼�֮ǰ�������Ϣ���Ȱ���Ϣ��ر�
	if (CurWin->hWnd == FrmMsgCtrl.hWnd)
	{
		SendMessage(FrmMsgCtrl.hWnd, WM_MSG_Close, 0, 0);
		usleep(20*1000);
	}
	
	if (AS_NEW_MSG == EventType)
	{
		SetScreenTimer();							// ����
		log_printf("au_model_func.c open lcd!\n");
		sys_open_lcd();
		sys_start_play_audio(SYS_MEDIA_OPER_HINT, (char *)storage_get_msg_hit(), FALSE, MSG_HIT_VOL, NULL, NULL);
		
		#if (_UI_STYLE_ == _E81S_UI_STYLE_)
		show_aurine_msg_hit(CurWin->hWnd, IDC_FORM, MSG_MESSAGE, SID_Msg_Info_Hit);
		#else
		show_msg_hit(CurWin->hWnd, IDC_FORM, MSG_MESSAGE, SID_Msg_Info_Hit);
		#endif
	}
	else if (AS_CALLIN == EventType)
	{
		SYS_MEDIA_TYPE CurState = sys_get_media_state();
		if (CurState == SYS_MEDIA_ALARM)
		{
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			show_aurine_msg_hit(CurWin->hWnd, IDC_Msg_Notice, MSG_CALL_MESSAGE, SID_Msg_CallIn_Hit);
			#else
			show_msg_hit(CurWin->hWnd, IDC_Msg_Notice, MSG_CALL_MESSAGE, SID_Msg_CallIn_Hit);
			#endif
		}
	}
	else if (AS_ENTER_YUJING == EventType)
	{
		/*
		SYS_MEDIA_TYPE CurState = sys_get_media_state();
		if (CurState != SYS_MEDIA_NONE && CurState != SYS_MEDIA_ALARM
			CurState != SYS_MEDIA_YUJING)
		{
			show_msg_alarm(CurWin, WID_MsgNotice);
		}
		*/
		#if (_UI_STYLE_ == _E81S_UI_STYLE_)
		show_aurine_msg_hit(CurWin->hWnd, IDC_Msg_Notice, MSG_ALARM, SID_Msg_Alarm_Hit);
		#else
		show_msg_hit(CurWin->hWnd, IDC_Msg_Notice, MSG_ALARM, SID_Msg_Alarm_Hit);
		#endif
	}
}

/*************************************************
  Function:		get_colorkey
  Description: 	ת��RGB��ɫΪ����ɫ
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
int get_colorkey(void)
{
	return RGB2Pixel(HDC_SCREEN, 0x00,0x00,0xF8);
}

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
void draw_video(HDC hdc, int x, int y, int w, int h)
{
	uint32  BKColor;
	SetBkMode(hdc,BM_TRANSPARENT);
	BKColor = get_colorkey();
	SetBrushColor(hdc,BKColor);
	SetBrushType(hdc,BT_SOLID);
	FillBox(hdc,x,y,w,h);
}

/*************************************************
  Function:		get_now_ymd
  Description: 	��ȡ��ǰ���ڵ�������
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void get_now_ymd(int *y,int *m,int *d)
{
	struct tm *p;
   	time_t t;
	
	time(&t);
	p = gmtime(&t); 
	*y = 1900+p->tm_year;
	*m = 1+p->tm_mon;
	*d = p->tm_mday;
}

#if 0
/*************************************************
  Function:		get_houseno_desc
  Description: 	��÷�������
  Input: 		��
  Output:		��
  Return:		��
  Others:		add by luofl 2008-1-10
*************************************************/
/*
char * get_houseno_desc( char * numtext, char * temp)
{

    if (temp == NULL || numtext == NULL)
	{
    	return numtext;
    }
	log_printf("%s : numtext : %s \n", __FUNCTION__, numtext);    
    int number = atoi(numtext);
    if (number>=51 && number<90)
    {
    	log_printf("%s : manager \n", __FUNCTION__);
        sprintf(temp,"%s%d", get_str(362), number-50);
        return temp;
    }

    if (number > 0 && number < 41)
	{
		sprintf(temp,"%s%d",get_str(364), number);
    	return temp;
	}

    //char stair[10]={0}, cell[10]={0}, room[10]={0};
    char devno[30]={0};
    PFULL_DEVICE_NO fulldevno;
    uint8 StairNoLen, CellNoLen, RoomNoLen, UseCellNo;
    int i, j = 0;
    
    fulldevno = get_fulldevno_ex();
    StairNoLen = fulldevno->Rule.StairNoLen;
    CellNoLen = fulldevno->Rule.CellNoLen;
    RoomNoLen = fulldevno->Rule.RoomNoLen;
    UseCellNo = fulldevno->Rule.UseCellNo;
    uint32 sub = fulldevno->Rule.Subsection;
    
    char strsub[10];
    sprintf(strsub,"%d",sub);
    uint32 subLen = strlen(strsub);
    int nsub = 0;
    char des[100];
	log_printf("%s : sub : %d, strsub : %s, sublen : %d \n", __FUNCTION__, sub, strsub, subLen);
    if (read_sub_des_new(subLen,des)!=0 || subLen<2)
    {
    	log_printf("%s : read_sub_des_new : %d \n", __FUNCTION__, read_sub_des_new(subLen,des));
        return numtext;
    }

    char num1[10], des1[11];
    char num[2] = {0};
    int index = 0, numIndex = 0, numCount = 0;
    sprintf(devno,"%s",numtext);
    char tmp[50]={0};
    int numTextLen = strlen(devno);

    for (i=subLen-1;i>=0;i--)
    {
        num[0]=strsub[subLen-1-i];
        num[1] = 0;
        nsub = atoi(num);

        memcpy(des1,des+10*(subLen-1-i),10);
        des1[10] =0;
        numIndex =0;
        for ( j=index;j<nsub+numCount;j++)
        {
            num1[numIndex++] = devno[j];
            index++;
        }
        numCount = index;
        num1[numIndex] =0;
        sprintf(tmp,"%s%s%s",tmp,num1,des1);
        if ( j+1==numTextLen || j== numTextLen)
        {
            if ( j+1==numTextLen)
            {
                num1[0] =devno[j+1];
                num[1] = 0;
                sprintf(tmp,"%s%s",tmp,num1);
            }
            break;
        }
    }
    sprintf(temp,"%s",tmp);
    return temp;
}
*/

//��÷�������
char * get_houseno_desc( char * numtext, char * temp)
{
    if (temp == NULL || numtext == NULL)
	{
    	return numtext;
    }

	memset(temp,0,sizeof(temp));
    
	int nlen = strlen(numtext);
 	int number = atoi(numtext);

	if (2 == nlen || 1 == nlen || number < 100)
	{
		if (number >= 51 && number < 90)
	    {
	        sprintf(temp,"%s%d",get_str(362),number-50);
	        return temp;
	    }
	    else
	    {
	    	if (number > 0 && number < 41)
	    	{
	    		sprintf(temp,"%s%d",get_str(364),number);
	        	return temp;
	    	}
	    }
	}

    char stair[10]={0},cell[10]={0},room[10]={0};
    char devno[30]={0};
    PFULL_DEVICE_NO fulldevno;
    uint8 StairNoLen,CellNoLen,RoomNoLen,UseCellNo;
    int i,j=0;
    fulldevno = get_fulldevno_ex();

	// �ݿ�
    if (nlen == fulldevno->Rule.StairNoLen + 1)
    {
    	sprintf(temp,"%s%s",get_str(228),numtext+nlen-1);
    	return temp;
    }
    
    StairNoLen = fulldevno->Rule.StairNoLen;
    CellNoLen = fulldevno->Rule.CellNoLen;
    RoomNoLen = fulldevno->Rule.RoomNoLen;
    UseCellNo = fulldevno->Rule.UseCellNo;
    uint32 sub = fulldevno->Rule.Subsection;
    char strsub[10];
    sprintf(strsub,"%d",sub);
    uint32 subLen = strlen(strsub);
    int nsub = 0;
    char des[100];
    if ( read_sub_des_new(subLen,des)!=0 || subLen<2)
    {
        return numtext;
    }    
    char num1[10],des1[11];
    char num[2]={0};
    int index =0,numIndex =0,numCount =0;
    sprintf(devno,"%s",numtext);
    char tmp[50]={0};
    int numTextLen = strlen(devno);


    for ( i=subLen-1;i>=0;i--)
    {
        num[0]=strsub[subLen-1-i];
        num[1] = 0;
        nsub = atoi(num);

        memcpy(des1,des+10*(subLen-1-i),10);
        des1[10] =0;
        numIndex =0;
        for ( j=index;j<nsub+numCount;j++)
        {

            num1[numIndex++] = devno[j];
            index++;
        }
        numCount = index;
        num1[numIndex] =0;
        log_printf("get_houseno_desc i=%d %d %s des1=%s %s\n",i,nsub,num,des1,strsub);
        sprintf(tmp,"%s%s%s",tmp,num1,des1);
        if ( j+1==numTextLen || j== numTextLen)
        {
            if ( j+1==numTextLen)
            {
                num1[0] =devno[j+1];
                num[1] = 0;
                sprintf(tmp,"%s%s",tmp,num1);
            }
            break;
        }

    }
    sprintf(temp,"%s",tmp);
    return temp;
}

#if 0
/*************************************************
  Function:		get_houseno_desc
  Description: 	��÷�������
  Input: 		��
  Output:		��
  Return:		��
  Others:		add by luofl 2008-1-10
*************************************************/
char * get_houseno_desc(char * numtext, char * temp)
{
    if (temp == NULL || numtext == NULL)
	{
    	return numtext;
    }

	memset(temp,0,sizeof(temp));
    
	int nlen = strlen(numtext);
 	int number = atoi(numtext);

	if (2 == nlen || 1 == nlen || number < 100)
	{
		if (number >= 51 && number < 90)
	    {
	        sprintf(temp,"%s%d",get_str(362),number-50);
	        return temp;
	    }
	    else
	    {
	    	if (number > 0 && number < 41)
	    	{
	    		sprintf(temp,"%s%d",get_str(364),number);
	        	return temp;
	    	}
	    }
	}
	else
	{
		PFULL_DEVICE_NO fulldevno;
		char strsub[20];
		uint8 StairNoLen, CellNoLen, RoomNoLen, UseCellNo;
		fulldevno = get_fulldevno_ex();
	    StairNoLen = fulldevno->Rule.StairNoLen;
	    CellNoLen = fulldevno->Rule.CellNoLen;
	    RoomNoLen = fulldevno->Rule.RoomNoLen;
	    UseCellNo = fulldevno->Rule.UseCellNo;

		if (nlen == StairNoLen+1 || nlen == StairNoLen-CellNoLen+1)
		{
			memcpy(temp,numtext,(StairNoLen-CellNoLen));
	   		strcat(temp,get_str(207));
			if (UseCellNo)
			{
				memset(strsub,0,sizeof(strsub));
		    	memcpy(strsub,numtext+(StairNoLen-CellNoLen),CellNoLen);
		    	strcat(strsub,get_str(208));
		    	strcat(temp,strsub);
			}
			memset(strsub,0,sizeof(strsub));
			strcat(temp,get_str(228));
	    	memcpy(strsub,numtext+(StairNoLen),1);
	    	strcat(temp,strsub);
		}
		else
		{
			memcpy(temp,numtext,(StairNoLen-CellNoLen));
		    strcat(temp,get_str(207));
		    
		    if (UseCellNo)
		    {
		    	memset(strsub,0,sizeof(strsub));
		    	memcpy(strsub,numtext+(StairNoLen-CellNoLen),CellNoLen);
		    	strcat(strsub,get_str(208));
		    	strcat(temp,strsub);
		    	memset(strsub,0,sizeof(strsub));
	    		memcpy(strsub,numtext+(StairNoLen),RoomNoLen);
	    		strcat(strsub,get_str(209));
	    		strcat(temp,strsub);
		    }
			else
			{
				memset(strsub,0,sizeof(strsub));
	    		memcpy(strsub,numtext+(StairNoLen-CellNoLen),RoomNoLen);
	    		strcat(strsub,get_str(209));
	    		strcat(temp,strsub);
			}
		    
			/*	
		   if (nlen == StairNoLen+RoomNoLen+1)
		   {
				if ('8' == numtext[nlen-1])
				{
					memset(strsub,0,sizeof(strsub));
					sprintf(strsub,"%s%d",get_str(2251),1);
			    	strcat(temp,strsub);
				}
				else
				{
					if ('9' == numtext[nlen-1])
					{
						memset(strsub,0,sizeof(strsub));
						sprintf(strsub,"%s%d",get_str(2251),2);
				    	strcat(temp,strsub);
					}
				}
			}
			*/
		}
	}
    return temp;
}
#endif
#endif

/*************************************************
  Function:		get_isFullScreen
  Description: 	
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 get_isFullScreen(void)
{
	return g_isFullScreenState;
}

/*************************************************
  Function:		set_fullscreen_NormalRc
  Description: 	
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void set_fullscreen_NormalRc(RECT_S * pRc)
{
	g_oldVideoRc = pRc;
}

/*************************************************
  Function:		get_isFullScreen
  Description: 	����ȫ���Ƿ�����Ƶ
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 set_fullscreen_video(uint8 isVideo)
{
	if (g_IsVideoFull == isVideo) 
	{
		return true;
	}
	
	g_IsVideoFull = isVideo;

	if (g_FullScreenhWnd > 0)
	{
		InvalidateRect(g_FullScreenhWnd, NULL, FALSE);
	}
	return true;
}

/*************************************************
  Function:		fullscreen_form_proc
  Description: 	
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
int fullscreen_form_proc(HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
	static int n = 0;
	HDC hdc;
	
	switch (message) 
	{
		case MSG_LBUTTONUP: 
		{	
			n++;
			if (n >= 1)
			{
				//play_key();
				ShowWindow(hDlg, SW_HIDE);
				g_isFullScreenState = false;
				
				if (g_oldVideoRc)
				{
					//set_video_rectangle(true, g_oldVideoRc);	
					g_oldVideoRc = NULL;
				}
				else
				{
					//set_video_rectangle(true, get_video_rect());
				}
				n = 0;
			}
			break;
		}
		
		case MSG_PAINT:
			hdc = BeginPaint (hDlg);
			if (!g_IsVideoFull)
			{
				PBITMAP bmp = get_bmp(BID_DEFAULT_BK);
				if (bmp)
				{
					FillBoxWithBitmap(hdc, 0,0,SCREEN_WIDTH, SCREEN_HEIGHT, bmp);
				}	
			}
			else
			{
				draw_video(hdc, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			EndPaint (hDlg, hdc);
			return 0;	
	}
	
	return DefaultDialogProc (hDlg, message, wParam, lParam);
}

#if 0
/*************************************************
  Function:		full_screen
  Description: 	��ȫ��
  Input: 		
	1.			�˿���Ϣ 
  Output:		��
  Return:		��
  Others:
*************************************************/
int full_screen(HWND hOwner)
{
	if (g_FullScreenhWnd == 0)
	{
		DLGTEMPLATE DlgInit = {WS_VISIBLE | WS_NONE, WS_EX_NONE, 0, 0, 
			SCREEN_WIDTH, SCREEN_HEIGHT, "", 0, 0, 0, NULL, 0};
		
		g_FullScreenhWnd = CreateMainWindowIndirect(&DlgInit, hOwner, fullscreen_form_proc); 
		if (g_FullScreenhWnd == HWND_INVALID)
		{
			g_FullScreenhWnd = 0;
			return false;
		}
	}
	//set_video_rectangle1(true, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); 
	ShowWindow(g_FullScreenhWnd, SW_SHOWNORMAL);
	g_LastScreenhWnd = 	hOwner;
	g_isFullScreenState = true;
	return true;
}
#endif

/*************************************************
  Function:		close_full_screen
  Description: 	�ر�ȫ��
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
int close_full_screen(int SetVideo)
{
	int tmp = -1;
	if (g_FullScreenhWnd > 0)
	{
		ShowWindow(g_FullScreenhWnd, SW_HIDE);
		if (SetVideo)
		{
			//tmp = set_video_rectangle(true, get_video_rect());
		}
		g_isFullScreenState = false;
	}
	return tmp;
}

/*************************************************
  Function:    		show_msg_byID
  Description:		��Ϣ��(��ʾ�ַ���ID)
  Input: 			
  ��1.ParentFrm		������
  	��.TitleID		����ID
  	��.TextId		�ı�����ID
  	��.msgtype		��Ϣ������
  Output:			0:�û�ȡ���������� 1:�û�ȷ�ϲ�������
  Return:			��
  Others: 
*************************************************/
uint32 show_msg_byID(PGUI_FORM ParentFrm,  int TitleID,int TextId,AU_MSG_TYPE msgtype, PJIADIAN_ITEM pData)
{
	uint32 ret = 0;

	#if 0
	if (msgtype == MSG_QUERY || msgtype == MSG_ALARM || msgtype == MSG_INPUT_PW || msgtype == MSG_JIADIAN)
	{
		log_printf("-----------------MSG_QUERY-----------\n");
		if ( get_cur_form()== &FrmMsg )
		{
			exit_page();
		}
		
		if (ParentFrm) 
		{
			FrmMsgQ.Parent = ParentFrm;
		}
		else
		{
			FrmMsgQ.Parent = &FrmMain;
		}
		FrmMsgQ.IsDlg = 1;
	
		//set_msgquery_mode(msgtype,TitleID,TextId,NULL,pData);
		add_show(&FrmMsgQ);
		if (pData != NULL)
		{
			FrmMsgQ.pDlgTemplate->dwAddData = (DWORD)pData;
		}
		
		ret = DialogBoxIndirectParam (FrmMsgQ.pDlgTemplate, FrmMsgQ.Parent->hWnd, FrmMsgQ.WinProc, 0L);	
		log_printf("ret = %d; FrmMsgQ.Parent->hWnd = %d\n", ret, FrmMsgQ.Parent->hWnd);
		FrmMsgQ.IsDlg = 0;
		FrmMsgQ.hWnd = 0;
		del_show(&FrmMsgQ);
	}
	else
	{
		if (ParentFrm)
		{
			FrmMsg.Parent = ParentFrm;
		}
		else
		{
			FrmMsg.Parent = &FrmMain;
		}
		//set_msgform_mode(msgtype,TitleID,TextId,NULL);
		form_show(&FrmMsg);	
	}
	#endif
	
	return ret;
}

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
uint32 show_msg_bytext(PGUI_FORM ParentFrm,  int TitleID,char *text,AU_MSG_TYPE msgtype)
{
	uint32 ret = 0;

	#if 0
	if (msgtype == MSG_QUERY || msgtype == MSG_ALARM)
	{
		if ( get_cur_form()== &FrmMsg )
		{
			exit_page();
		}
		
		if (ParentFrm) 
		{
			FrmMsgQ.Parent = ParentFrm;
		}
		else
		{
			FrmMsgQ.Parent = &FrmMain;
		}
		FrmMsgQ.IsDlg = 1;
		//set_msgquery_mode(msgtype,TitleID,0,text);
		add_show(&FrmMsgQ);
		ret = DialogBoxIndirectParam (FrmMsgQ.pDlgTemplate, FrmMsgQ.Parent->hWnd, FrmMsgQ.WinProc, 0L);
		FrmMsgQ.IsDlg = 0;
		FrmMsgQ.hWnd = 0;
		del_show(&FrmMsgQ);
	}
	else
	{
		if (ParentFrm)
		{
			FrmMsg.Parent = ParentFrm;
		}
		else
		{
			FrmMsg.Parent = &FrmMain;
		}
		//set_msgform_mode(msgtype,TitleID,0,text);
		form_show(&FrmMsg);	
	}
	#endif
	
	return ret;	
}

/********************************************************/
/*			           ������غ���                     */	
/********************************************************/
#if 0
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
void change_mainIcon_state(MAIN_ICON_STYLE check_state, uint8 pflash)
{
	if (pflash)
	{
		Icon_state[check_state-STYLE_MAIN_NEWMESSAGE] = 1;
	}
	else
	{	
		Icon_state[check_state-STYLE_MAIN_NEWMESSAGE] = 0;
	}
}
#endif

#if 0
/*************************************************
  Function:    		get_mainIcon_state
  Description:		���Сͼ��״̬
  Input: 			
  	1.public_state	���ù�������
  	2.state:   		״̬
  Output:			��
*************************************************/
void get_mainIcon_state(PUBLIC_STATE public_state)
{
	int state = get_public_state(public_state);
	
	switch(public_state)
	{			
		case PUB_STATE_LEAVEWORD_NEWLY:						// ��Ӱ����δ��
			change_mainIcon_state(STYLE_MAIN_LYLY,state);
			break;
			
	   	case PUB_STATE_XINXI:								// ��Ϣ��ʾ
	   		change_mainIcon_state(STYLE_MAIN_NEWMESSAGE,state);
	   		break;

		case PUB_STATE_NOFAZE:
			change_mainIcon_state(STYLE_MAIN_NOFAZE, state);
		default:
			break;
	}
}
#endif

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
void draw_backbmp(HDC hdc, RECT rect ,PBITMAP bmp ,int bmpMode, uint8 isFreeBmp)
{
	int x,y,w,h;
	
	if (bmp)
	{
		int bmW = bmp->bmWidth;
		int bmH = bmp->bmHeight;
		x = rect.left;
		y = rect.top;
		w = rect.right-rect.left;
		h = rect.bottom-rect.top;
		
		if (bmpMode !=2)
		{
			if (bmpMode == 1)
			{
				if (bmW < w)
				{
					x = rect.left+(w-bmW)/2;
					w = bmW;
				}
				if (bmH < h)
				{
					y = rect.top+(h-bmH)/2;
					h= bmH;
				}
			}
			if (bmp)
			{
				FillBoxWithBitmap(hdc, x, y, w,h,bmp);
			}
		}
		else
		{
			int i,j;
			int col = w/bmW;
			int row =h/bmH;
			int rW =bmW;
			int rH = bmH;
			
			for (i = 0; i <= row; i++)
			{
				for (j = 0; j <= col; j++)
				{
					
					if (w-j*bmW > bmW)
					{
						rW = bmW;
					}	
					else
					{
						rW = w-j*bmW;
					}
					if (h-j*bmH > bmH)
					{
						rH= bmH;
					}	
					else
					{
						rH = h-j*bmH;
					}	
					FillBoxWithBitmapPart(hdc,x+j*bmW,y+i*bmH,rW,rH,0,0,bmp,0,0);
				}			
			}
		}
	}
	
	if (bmp && isFreeBmp)
	{
		UnloadBitmap(bmp);		
		bmp=NULL;
	}			 
}

/*************************************************
  Function:    utf8_2_gb2312
  Description: ��utf8�ַ���ת��Ϊgb2312�ַ���
  Input:
  1.��ת�����ַ���ָ��
  Return:
  ת���ɹ����
*************************************************/
int utf8_2_gb2312(char *p)
{
	char d[100];
	char s[100] ;
	int len = 0;	
	
	memset(d, 0, sizeof(d));
	memset(s,0,sizeof(s));
	sprintf(s,"%s",p);
	len = strlen(s);
	len += 1;
	//int d_len = 2*len;
	//CharsetConversion(CONV_FROM_UTF8, CONV_GB2312, s, len, d, &d_len);
	memset(p, 0, sizeof(p));
	strcpy(p, d);
	
	return TRUE;
} 

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
void ConvertFileName(char * fullpathname,char * filename)
{
 	int i,count,index =0;
 	char temp[100]={0};
 	int len = strlen(fullpathname);
 
	if (len == 0) 
 	{
  		sprintf(filename,"%s","");
  		return ;
 	}
 
 	for (i=len-1;i>=0;i--)
 	{
  		if ( fullpathname[i]=='/' )
   			break;
  		temp[index++] = fullpathname[i];
 	}
 	count = index;
 	index =0;
 	memset(filename,0,sizeof(filename));
 	for ( i=count-1;i>=0;i--)
 	{
  		filename[index++] =temp[i];
 	}
 	filename[index]=0; 
 	
 	utf8_2_gb2312(filename);
}

#if 0
/*************************************************
  Function:			get_text
  Description: 		��õ�ǰ����
  Input: 			��	
  Output:			��
  Return:			��
  Others:
*************************************************/
static uint8 get_text(PFULL_DEVICE_NO g_devtype, char *str,uint8 flag,char *name)
{
	char text[20] = {0};
	uint8 i,j;
	memset(text,0,sizeof(text));
	switch(flag)
	{
		case 0:										// �ݺ�
			for(i = 0; i < (g_devtype->Rule.StairNoLen - g_devtype->Rule.CellNoLen); i++)
			{
				text[i] = *(str+i);
			}
			break;

		case 1:										// ��Ԫ��
			if (g_devtype->Rule.UseCellNo)
			{
				j = 0;
				for(i = (g_devtype->Rule.StairNoLen - g_devtype->Rule.CellNoLen); i < g_devtype->Rule.StairNoLen; i++)
				{
					text[j] = *(str+i);
					j++;
				}
			}
			else
			{
				for(i = g_devtype->Rule.StairNoLen-g_devtype->Rule.CellNoLen; i < (g_devtype->Rule.StairNoLen+g_devtype->Rule.RoomNoLen-g_devtype->Rule.CellNoLen); i++)
				{
					text[j] = *(str+i);
					j++;
				}
			}
			break;

		case 2:										// ����
			j = 0;
			if (g_devtype->Rule.UseCellNo)
			{
				for(i = g_devtype->Rule.StairNoLen; i < (g_devtype->Rule.StairNoLen+g_devtype->Rule.RoomNoLen); i++)
				{
					text[j] = *(str+i);
					j++;
				}
			}
			else
			{
				for(i = g_devtype->Rule.StairNoLen-g_devtype->Rule.CellNoLen; i < (g_devtype->Rule.StairNoLen+g_devtype->Rule.RoomNoLen-g_devtype->Rule.CellNoLen); i++)
				{
					text[j] = *(str+i);
					j++;
				}
			}
			break;

		default:
			break;
	}
	memset(name,0,sizeof(name));
	sprintf(name,"%s",text);

	return strlen(text);
}
#endif

#if 0
/*************************************************
  Function:    		draw_input
  Description:		����
  Input: 			
  Output:			�� 
  Others:
*************************************************/
void draw_input(HDC hdc, int CallType, int x, int y, char *str)
{
	RECT rc;
	//uint8 i;
	//int len = 0;
	char text[50] = {0};
	//uint32 TextFONT = 0;
	//uint32 TextPOS1[2] = {200,200};
	//uint32 TextID1[2] = {207,209};
	//uint32 TextPOS2[3] = {150,60,160};
	PBITMAP bmp = get_bmp(BID_INPUT);
	if (bmp)
	{
		FillBoxWithBitmap(hdc, x,  y, 0, 0, bmp);
	}

    //PFULL_DEVICE_NO g_devtype = get_fulldevno_ex();   
	SetBkMode(hdc,BM_TRANSPARENT);

	int sx;
	if (CallType == 0)
	{
		log_printf("str ; %s\n", str);
		memset(text,0,sizeof(text));
		if (str)
		{
			memcpy(text, str, strlen(str));
		}		
		SetTextColor(hdc,COLOR_BLUE_TEXT);
		SetBkMode(hdc,BM_TRANSPARENT);
		SelectFont(hdc, GetFont(FONT_16));
		sx = x;
		rc.left = sx;
    	rc.top = y + (INPUT_CTRL_H-FONT_16)/2;
    	rc.right = rc.left+INPUT_CTRL_W;
    	rc.bottom = rc.top+FONT_16;
    	DrawTextFont(hdc, text, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);	
		/*
		if (g_devtype->Rule.UseCellNo)
		{
			sx = x;
			for(i = 0; i < 3; i++)
			{
				memset(text,0,sizeof(text));
				SetTextColor(hdc,COLOR_BLUE_TEXT);
				SelectFont(hdc, GetFont_ABC(FONT_28));
				len = get_text(g_devtype, str, i, text);
				rc.left = sx;
				rc.top = y + (INPUT_CTRL_H-FONT_28)/2;
				rc.right = rc.left+TextPOS2[i];
				rc.bottom = rc.top+FONT_28;
				DrawTextFont(hdc,text, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);

				sx += TextPOS2[i];
				
				memset(text,0,sizeof(text));
				SetTextColor(hdc,COLOR_WHITE);
				SetBkMode(hdc,BM_TRANSPARENT);
				SelectFont(hdc, GetBoldFont(FONT_12));
				rc.left = sx;
		    	rc.top = y + (INPUT_CTRL_H-FONT_12)/2;
		    	if (i == 1)
		    	{
		    		rc.right = rc.left+FONT_12*3;
		    	}
		    	else
		    	{
		    		rc.right = rc.left+FONT_12;
		    	}
		    	rc.bottom = rc.top+FONT_12;
		    	DrawTextFont(hdc,get_str(207+i), -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		    	if (i == 1)
		    	{
		    		sx += FONT_12*3;
		    	}
		    	else
		    	{
		    		sx += FONT_12;
		    	}
			}
		}
		else
		{
			sx = x;
			for(i = 0; i < 2; i++)
			{
				memset(text,0,sizeof(text));
				SetTextColor(hdc,COLOR_BLUE_TEXT);
				SelectFont(hdc, GetFont_ABC(FONT_28));
				len = get_text(g_devtype, str, i, text);
				rc.left = sx;
				rc.top = y + (INPUT_CTRL_H-FONT_28)/2;
				rc.right = rc.left+TextPOS1[i];
				rc.bottom = rc.top+FONT_28;
				DrawTextFont(hdc,text, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);

				sx += TextPOS1[i];
				
				memset(text,0,sizeof(text));
				SetTextColor(hdc,COLOR_WHITE);
				SetBkMode(hdc,BM_TRANSPARENT);
				SelectFont(hdc, GetBoldFont(FONT_12));
				rc.left = sx;
		    	rc.top = y + (INPUT_CTRL_H-FONT_12)/2;
		    	rc.right = rc.left+FONT_12;
		    	rc.bottom = rc.top+FONT_12;
		    	DrawTextFont(hdc,get_str(TextID1[i]), -1, &rc, DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		    	sx += FONT_12;
			}	
		}
		*/
	}
	else if(CallType == 1 || CallType == 2)
	{
		memset(text,0,sizeof(text));
		if (str)
		{
			memcpy(text, str, strlen(str));
		}
		
		SetTextColor(hdc,COLOR_BLUE_TEXT);
		SetBkMode(hdc,BM_TRANSPARENT);
		SelectFont(hdc, GetFont(FONT_16));
		sx = x;
		rc.left = sx;
    	rc.top = y + (INPUT_CTRL_H-FONT_16)/2;
    	rc.right = rc.left+INPUT_CTRL_W;
    	rc.bottom = rc.top+FONT_16;
    	DrawTextFont(hdc, text, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);	
	}
	else
	{
		memset(text,0,sizeof(text));
		if (str)
		{
			memcpy(text, str, strlen(str));
		}
		
		SetTextColor(hdc,COLOR_WHITE);
		SetBkMode(hdc,BM_TRANSPARENT);
		SelectFont(hdc, GetFont(FONT_16));
		sx = x;
		rc.left = sx;
    	rc.top = y + (INPUT_CTRL_H-FONT_16)/2;
    	rc.right = rc.left+INPUT_CTRL_W;
    	rc.bottom = rc.top+FONT_16;
    	DrawTextFont(hdc, text, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}
}
#endif

/*******************************************************************
  Function:			draw_circle
  Description:		�����߰�Բ
  Input: 			��
  Output:			��
  Return:			��
  Others:			
  					 add by jinsy 2007.11.2
*******************************************************************/  
void draw_circle(HDC hdc, int x, int y, int w, int h, DWORD lightcolor, DWORD darkcolor)
{
	#define ANGLE_1 64*90
	
   	SetBrushColor(hdc, lightcolor);
	FillBox(hdc, x+h/2, y, w-h, h/2);
	FillArcEx(hdc, x, y, h, h, ANGLE_1, ANGLE_1); 
	FillArcEx(hdc, x+w-h, y, h, h, 0, ANGLE_1);
	
	SetBrushColor(hdc, darkcolor);
	FillBox(hdc, x+h/2, y+h/2, w-h, h/2);
	FillArcEx(hdc, x, y, h, h, ANGLE_1*2, ANGLE_1);
	FillArcEx(hdc, x+w-h, y, h, h, -ANGLE_1, ANGLE_1);

	SetPenColor(hdc,PIXEL_darkgray);
	SetPenWidth(hdc, 2);
	LineEx(hdc, x+h/2, y + 1, w-h/2, y + 1);
	LineEx(hdc, x+h/2, y + h -1, w-h/2+5, h - 1);
	
	ArcEx(hdc, x, y, h-1, h-1, ANGLE_1, 2*ANGLE_1);
	ArcEx(hdc, x+w-h, y, h-1, h, ANGLE_1, -2*ANGLE_1);
}

/*************************************************
  Function:		draw_num
  Description: 	д����
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_num(HDC hdc, int index, int x, int y, int h, int w, int bw, int dis)
{
	POINT points[6];
	int x1,y1;
	int i;
	int x0=x+w/2,y0=y+h/2;//�е�����
	int sx[6],sy[6];
			
	switch (index)
	{
	case 0:
		points[0].x = x+bw/2+dis;
		points[0].y = y+bw/2;
		points[1].x = points[0].x +bw/2;
		points[1].y = y;
		points[2].x = x+w-bw-dis;
		points[2].y = points[1].y;
		points[3].x = points[2].x+bw/2;
		points[3].y = points[0].y;
		points[4].x = points[2].x;
		points[4].y = points[1].y+bw;
		points[5].x = points[1].x;
		points[5].y = points[4].y;
		break;
	case 1:
		points[0].x = x + w - bw/2;
		points[0].y = y+bw/2+dis;
		points[1].x = x + w;
		points[1].y = points[0].y + bw/2;
		points[2].x = points[1].x;
		points[2].y = y + h/2 - bw/2 -dis;
		points[3].x = points[0].x;
		points[3].y = points[2].y + bw/2;
		points[4].x = points[2].x-bw;
		points[4].y = points[2].y;
		points[5].x = points[4].x;
		points[5].y = points[1].y;
		break;
	case 2:
		points[0].x = x + w - bw/2;
		points[0].y = y+h/2+dis;
		points[1].x = x + w;
		points[1].y = points[0].y + bw/2;
		points[2].x = points[1].x;
		points[2].y = y + h - bw - dis;
		points[3].x = points[0].x;
		points[3].y = points[2].y + bw/2;
		points[4].x = points[2].x-bw;
		points[4].y = points[2].y;
		points[5].x = points[4].x;
		points[5].y = points[1].y;
		break;
	case 3:
		points[0].x = x+bw/2+dis;
		points[0].y = y+h-bw/2;
		points[1].x = points[0].x +bw/2;
		points[1].y = points[0].y-bw/2;
		points[2].x = x+w-bw-dis;
		points[2].y = points[1].y;
		points[3].x = points[2].x+bw/2;
		points[3].y = points[0].y;
		points[4].x = points[2].x;
		points[4].y = points[1].y+bw;
		points[5].x = points[1].x;
		points[5].y = points[4].y;
		break;
	case 4:
		points[0].x = x + bw/2;
		points[0].y = y+h/2+dis;
		points[1].x = x + bw;
		points[1].y = points[0].y + bw/2;
		points[2].x = points[1].x;
		points[2].y = y + h - bw - dis;
		points[3].x = points[0].x;
		points[3].y = points[2].y + bw/2;
		points[4].x = points[2].x-bw;
		points[4].y = points[2].y;
		points[5].x = points[4].x;
		points[5].y = points[1].y;
		break;
	case 5:
		points[0].x = x + bw/2;
		points[0].y = y+bw/2+dis;
		points[1].x = x + bw;
		points[1].y = points[0].y + bw/2;
		points[2].x = points[1].x;
		points[2].y = y + h/2 - bw/2 -dis;
		points[3].x = points[0].x;
		points[3].y = points[2].y + bw/2;
		points[4].x = points[2].x-bw;
		points[4].y = points[2].y;
		points[5].x = points[4].x;
		points[5].y = points[1].y;
		break;
	case 6:
		points[0].x = x+ bw/2+dis;
		points[0].y = y+h/2;
		points[1].x = points[0].x +bw/2;
		points[1].y = y+h/2-bw/2;
		points[2].x = x+w-bw-dis;
		points[2].y = points[1].y;
		points[3].x = points[2].x+bw/2;
		points[3].y = points[0].y;
		points[4].x = points[2].x;
		points[4].y = points[1].y+bw;
		points[5].x = points[1].x;
		points[5].y = points[4].y;
		break;

	case 7:	//��"."
		{
			x1 = x+(w-bw)/2;
			y1 = y+h-bw;
			FillBox(hdc,x1,y1,bw,bw);
			return;
		}
	case 8:
		//��":"
		{
			x1 = x+(w-bw)/2;
			y1 = y+(h/2-bw)/2;
			FillBox(hdc,x1,y1,bw,bw);
			y1 = y+(h/2-bw)/2+h/2;
			FillBox(hdc,x1,y1,bw,bw);
			return;	
		}

	case 9:
		//��*
		{
			SetPenColor(hdc,COLOR_BLACK);
			bw=3;
			SetPenWidth(hdc,bw); 
			//��׼����
			sx[0]=x+w/2;
			sy[0]=y+(h-w)/3;
			sx[1]=sx[0]+bw/2;
			sy[1]=sy[0]+bw/2;
			sx[2]=sx[1];
			sy[2]=sy[1]+w/4;
			sx[3]=sx[0];
			sy[3]=y0-bw/2;
			sx[4]=sx[0]-bw/2;
			sy[4]=sy[2];
			sx[5]=sx[4];
			sy[5]=sy[1];
			for(i=0;i<6;i++)
			{
				points[i].x=sx[i];
				points[i].y=sy[i];
			}
			FillPolygon(hdc, points, 6);
			//�����е�Գ�
			for(i=0;i<6;i++)
			{
				points[i].x=2*x0-sx[i];
				points[i].y=2*y0-sy[i];	
			}
			FillPolygon(hdc, points, 6);
			//ת�����������
			for (i=0;i<6;i++)
			{
				sx[i]-=x0;
				sy[i]-=y0;
			}
			//����y=1.732x�Գ�
			for(i=0;i<6;i++)
			{
				points[i].x=x0+(1.732*sy[i]-sx[i])/2;
				points[i].y=y0+(1.732*sx[i]+sy[i])/2;	
			}
			FillPolygon(hdc, points, 6);
			//����y=-1.732x�Գ�
			for(i=0;i<6;i++)
			{
				points[i].x=x0-(1.732*sy[i]+sx[i])/2;
				points[i].y=y0+(sy[i]-1.732*sx[i])/2;	
			}
			FillPolygon(hdc, points, 6);
			//����y=0.577x�Գ�
			for(i=0;i<6;i++)
			{
				points[i].x=x0+(1.414*sy[i]+sx[i])/2;
				points[i].y=y0+(1.732*sx[i]-sy[i])/2;	
			}
			FillPolygon(hdc, points, 6);
			//����y=-0.577x�Գ�
			for(i=0;i<6;i++)
			{
				points[i].x=x0+(sx[i]-1.732*sy[i])/2;
				points[i].y=y0-(1.732*sx[i]+sy[i])/2;	
			}
			FillPolygon(hdc, points, 6);
			return;
		}
	case 10:
		//��#
		{
			bw=3;
			SetPenColor(hdc,COLOR_BLACK);
			SetPenWidth(hdc,bw); 
			for (i=0;i<2;i++)
			{
				points[0].x = x+ w/3+i*w/3-1+i*2;
				points[0].y = y+(h-w)/3;
				points[1].x = points[0].x +bw/2;
				points[1].y = points[0].y+bw/2;
				points[2].x = points[1].x;
				points[2].y = y+h-(h-w)/3-bw/2;
				points[3].x = points[0].x;
				points[3].y = y+h-(h-w)/3;
				points[4].x = points[3].x-bw/2;
				points[4].y = points[2].y;
				points[5].x = points[4].x;
				points[5].y = points[1].y;
				FillPolygon(hdc, points, 6);
			}
			for (i=0;i<2;i++)
			{
				points[0].x = x;
				points[0].y = y+h/3+i*h/3+1-i*2;
				points[1].x = points[0].x+bw/2;
				points[1].y = points[0].y-bw/2;
				points[2].x = x+w-bw/2;
				points[2].y = points[1].y;
				points[3].x = x+w;
				points[3].y = points[2].y+bw/2;
				points[4].x = points[2].x;
				points[4].y = points[3].y+bw/2;
				points[5].x = points[1].x;
				points[5].y = points[0].y+bw/2;
				FillPolygon(hdc, points, 6);
			}
			return;	
		}	

	default:
		return;	
	}
	FillPolygon(hdc, points, 6);		
}

/*************************************************
  Function:		draw_num
  Description: 	д�����ַ���
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_num_str(HDC hdc, char * NumStr, int x, int y, int h, int w, int bw, int color)
{
	const unsigned char NumValue[11] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 54};	
	const unsigned char mark[7] = {1, 2, 4, 8, 16, 32, 64};	
	int NUM_DIST = w / 4;
	if (NUM_DIST<1)
		NUM_DIST = 1;
	/*
	if (h<6 || w<3 || bw<2)
		return;
		*/
	int i,j, index, left;
	int n = strlen(NumStr);
	for (i=0; i<n; i++)
	{
		/// edit by hxf 2006.12.1 ���ӻ�"."��":" ////
		//if (NumStr[i]=='-' || NumStr[i]==' '  )
		if (NumStr[i]=='-' || NumStr[i]==' '  || NumStr[i]=='.' || NumStr[i]==':' || NumStr[i]=='*' ||NumStr[i]=='#')//Add by lxr 2007.2.5
		// end edit by hxf 2006.12.1   ////
			continue;
		if (NumStr[i]<'0' || NumStr[i]>'9')
			return;
	}
	if (h%2)
		h--;
	if (bw%2)
		bw++;
	SetBrushType(hdc, BT_SOLID);
	if (color!=-1)
		SetBrushColor(hdc, (uint32)color);
	//x = x - n*(w+NUM_DIST);
	left = x;
	for (i=0; i<n; i++)
	{
		if (color==-1)
			SetBrushColor(hdc, COLOR_BLACK);
		if (' '==NumStr[i])
			continue;
		switch(NumStr[i])
		{
			case '-':
				draw_num(hdc, 6, left, y, h, w, bw, 1);
				left+=w+NUM_DIST;
				continue;	
			case '.':
				draw_num(hdc, 7, left, y, h, w/2, bw, 1);		
				left+=w/2+NUM_DIST;		
				continue;
			case ':':
				draw_num(hdc, 8, left, y, h, w/2, bw, 1);	
				left+=w/2+NUM_DIST;				
				continue;		
			case '*':
				draw_num(hdc, 9, left, y, h, w, bw, 1);
				left+=w+NUM_DIST;
				continue;	
			case '#':
				draw_num(hdc, 10, left, y, h, w, bw, 1);
				left+=w+NUM_DIST;
				continue;	
			default:
				index = NumStr[i]-'0';
				for (j=0; j<7; j++)
				{
					if (NumValue[index] & mark[j])
						draw_num(hdc, j, left, y, h, w, bw, 1);
				}
				left+=w+NUM_DIST;// Add by hxf 2006.12.1	
				break;	
		}	
	}
}

/*************************************************
  Function:		Display_Text
  Description: 	
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void Display_Text(HDC hdc, int x0, int y0, int w, int h, int scale, uint8 * data)
{
	if (scale<1)
		scale = 1;
	uint8 masks[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	uint8 B;
	int cw = w/8;
	int i, j, k, len = 0;
	if (w % 8) 
		len = w % 8;
	uint32 color = GetTextColor(hdc);
	int x, y;
	int pos = 0;
	y = y0-1;
	for (i=0; i<h; i++)
	{
		x = x0-scale;
		y += scale;
    	for (j= 0; j<cw; j++)
    	{
			//x = x0 + j*8;
			B = *(data+pos);
			pos++;
			if (!B)
			{
				x += 8*scale;
				continue;
			}
			for (k=0; k<8; k++)
			{
				
				x += scale;
				if (masks[k] & B)
				{
					if (1==scale)
						SetPixel(hdc, x, y, color);
					else
					{
						int m, n;
						for (m=0; m<scale; m++)
						{
							for (n=0; n<scale; n++)
								SetPixel(hdc, x+n, y+m, color);
						}
					}	
				}
			}
		}
		if (!len) continue;
		B = *(data+pos);
		pos++;
		
		if (!B) continue;
		for (k=0; k<len; k++)
		{
			x += scale;
			if (masks[k] & B)
			{
				if (1==scale)
				{	
					SetPixel(hdc, x, y, color);
				}
				else
				{
					int m, n;
					for (m=0; m<scale; m++)
					{
						for (n=0; n<scale; n++)
							SetPixel(hdc, x+n, y+m, color);
					}
				}	
			}
		}
	}

}

#if 0
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
void draw_text_by_myfont(HDC hdc, int x, int y, uint32 TextID)
{
	if (storage_get_language() == 2)
	{	
		RECT TextRc;
		int len = strlen(get_str(TextID));
		TextRc.left = x;
		TextRc.right = x + len * FONT_24;
		TextRc.top = y;
		TextRc.bottom = y + FONT_24;
		SelectFont(hdc, GetBoldFont(FONT_24));
		DrawTextFont(hdc, get_str(TextID), -1, &TextRc, DT_VCENTER|DT_SINGLELINE);	
	}
	else
	{
		int i,sx = x;
		uint8 index[20] = {0};
		int len = get_text_byID(TextID, index);
		if (len > 0)
		{
			for(i = 0; i < len; i++)
			{
				if (index[i] > TEXT_MAX_NUM + 1 && index[i] < TEXT_MAX_NUM + 9)
				{
					Display_Text(hdc, sx, y, FONT_24, FONT_24, 1, get_num_font_data(index[i] - TEXT_MAX_NUM));
				}
				else
				{
					Display_Text(hdc, sx, y, FONT_24, FONT_24, 1, get_font_data(index[i]));				
				}
				sx+=FONT_24;
			}
		}
	}
}
#endif

/*************************************************
  Function:		draw_ip_point
  Description: 	
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_ip_point(HDC hdc,int left,int top,int width,int height)
{
	SetBrushColor(hdc, COLOR_BLACK);
	FillCircle(hdc,left+2,top+height-3,2);
}

/*************************************************
  Function:		draw_slash
  Description: 	
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_slash(HDC hdc,int x,int y,int w,int h)
{
	int x1,y1,x2,y2;
	x1 = x;
	y1 = y+h;
	x2 = x+w;
	y2 = y;
	SetPenWidth(hdc,1);
 	LineEx(hdc, x1,y1,x2,y2);	
}

/*************************************************
  Function:		draw_num_str2
  Description: 	
  Input: 		
	1.			�˿���Ϣ
  Output:		��
  Return:		��
  Others:
*************************************************/
void draw_num_str2(HDC hdc, char * NumStr, int x, int y, int w, int dis)
{
	int i;
	log_printf("NumStr = %s\n", NumStr);
	log_printf("x = %d; y = %d; w = %d; dis = %d\n", x, y, w, dis);
	if (NumStr)
	{
		int n = strlen(NumStr);
		
		for (i=0; i<n; i++)
		{
			
			if (NumStr[i]=='*' || NumStr[i]=='#' || NumStr[i]=='.' || NumStr[i]==' ' || NumStr[i]=='/' || NumStr[i]==':'
			    || NumStr[i]== '-')
				continue;
			if (NumStr[i]<'0' || NumStr[i]>'9')
				return;
				
		}
		int index;
		SelectFont(hdc, GetFont(FONT_12));
		for (i=0; i<n; i++)
		{
			
			if (NumStr[i]=='*')
				index = 10;
			else if (NumStr[i]=='#')
				index = 11;
			else if ( NumStr[i]==46)
			{
				draw_ip_point(hdc,x+(w+dis)*i, y, 6, 12);
				continue;
			}
			else if ( NumStr[i]==':' )
			{
				RECT rc;
				rc.left =  x+(w+dis)*i;
				rc.right = rc.left+6;
				rc.top = y;
				rc.bottom = rc.top+12;
				DrawTextFont(hdc, ":", -1, &rc, DT_CENTER | DT_VCENTER|DT_SINGLELINE);
				//draw_num(hdc, 8, x+(w+dis)*i, y, 16, 8, 5, 1);
				continue;
			}	
			else if ( NumStr[i]=='/' )
			{
				//��б�� -- Add by hxf 2006.12.1
				draw_slash(hdc,x+(w+dis)*i,y,6,12);
				continue;
			}
			else if (NumStr[i]=='-')
			{
				RECT rc;
				rc.left =  x+(w+dis)*i;
				rc.right = rc.left+6;
				rc.top = y;
				rc.bottom = rc.top+12;
				DrawTextFont(hdc, "-", -1, &rc, DT_CENTER | DT_VCENTER|DT_SINGLELINE);	
				continue;
			}
			else if ( NumStr[i]==' ')
			{
				continue;
			}
			else
			{
				//Display_Text(hdc, x+(w+dis)*i, y, 12, 24, w/12, get_num_font_data(index));
				;
			}
		}
	}
}

#if 0
/*************************************************
  Function:    		get_executor_Id
  Description:		���ݲ����ߣ���ȡ�ַ���ID
  Input: 			
  	1.executor			�����ߴ���
  Output:			
  				
  create:			Add by hxf 2006.12.31
*************************************************/
int get_executor_Id(EXECUTOR_E executor)
{
	int strID = 0;
	switch ( executor )
	{
		case EXECUTOR_LOCAL_HOST://��������
			strID = 360;
			break;
		case EXECUTOR_REMOTE_DEVICE:
			strID = 361;
			break;
		case EXECUTOR_MANAGER:
			strID = 362;
			break;
		case EXECUTOR_STAIR:
			strID = 363;
			break;
		case EXECUTOR_AREA:
			strID = 364;
			break;
		case EXECUTOR_IE_USER:
			strID = 365;
			break;	
		case EXECUTOR_SHORT_MSG:
			strID = 366;
			break;
		case EXECUTOR_PHONE_USER:
			strID = 367;
			break;
		case EXECUTOR_SERVER:
			strID = 368;
			break;	
	}
	return strID;
}
#endif

/*************************************************
  Function:			draw_circle_ractange
  Description:  	������ʱ��߿�
  Input: 		
	1.hdc			�豸������
	2.lineColor		������ɫ
	3.left			left�����
	4.top			top�����
	5.right			����
	6.bottom		���
	7.r				Բ�ǰ뾶
	8.bw			����
  Output:		
  Return:			��
  Others:       	����Բ�ǵľ��ο� 
**************************************************/
void draw_circle_ractange(HDC hdc, uint32 lineColor, int left, int top, int right, int bottom, int r, int bw)
{
	int d,i;
	
	SetBrushColor(hdc, lineColor);
	SetPenColor(hdc, lineColor);
	SetPenWidth(hdc, 1);
	d = 2*r;
	
	for (i = 0; i < bw; i++)
	{
		ArcEx (hdc, left, top, d, d, 90*64, 90*64); 
		ArcEx (hdc, left, bottom-d, d, d, 180*64, 90*64); 
		ArcEx (hdc, right-d, top, d, d, 0, 90*64); 
		ArcEx (hdc, right-d, bottom-d, d, d, 0, -90*64); 

	    LineEx(hdc, left+r, top, right-r, top);
    	LineEx(hdc, left+r, bottom, right-r, bottom);
    	LineEx(hdc, left, top+r, left, bottom-r);
	    LineEx(hdc, right, top+r, right, bottom-r);
		
		left++;
		top++;
		right++;
		bottom++;
	}	
}

#if 0
/*******************************************************************
  Function:			draw_progress3
  Description:		����Բ�ǵľ��ο���Ϊ������
  Input: 			��
  Output:			��
  Return:			��
  Others:			
  					 add by jinsy 2007.11.2
*******************************************************************/ 
void draw_progress3(HDC hdc,RECT rc,uint32 borderColor,uint32 BKColor,
					uint32 rateColor,int progressCount,int rate)
{
#define Y_DIS		2

	int i,w,h,color,x,y;
	draw_circle_ractange(hdc,borderColor,rc.left,rc.top,rc.right,rc.bottom,6,2);
	w = (RECTW(rc)-4)/progressCount;
	x = rc.left+Y_DIS;
	h = RECTH(rc)-2*Y_DIS;
	y = rc.top+Y_DIS+1;

	for (i=0;i<progressCount;i++)
	{
		if ( i<rate)
			color = rateColor;
		else
			color = BKColor;
		SetBrushColor(hdc,color);	
		FillBox(hdc,x+w*i,y,w,h);
	}
}

/*******************************************************************
  Function:			get_mulpic
  Description:		����ϵͳ����ȡ��ʾͼƬ
  Input: 			��
  Output:			��
  Return:			��
  Others:			
  					 add by jinsy 2007.11.2
*******************************************************************/ 
int get_mulpic(int bmp_id)
{
	switch(store_get_language())
	{
		case 1:		
			//log_printf("Enter bmp_id=%u\n",bmp_id);
			return bmp_id+1;
		case 2:
			//log_printf("Enter bmp_id=%u\n",bmp_id);
			return 	bmp_id+2;
		default:
			//log_printf("Enter bmp_id=%u\n",bmp_id);
			return 	bmp_id;	
	}
}
#endif

/*************************************************
  Function:		DrawBmpID
  Description: 	����ͼƬID��ָ��λ�û�ͼƬ,��߸���
  				ʵ��ͼƬ��С����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void DrawBmpID(HDC hdc, int x, int y, int w, int h, int id)
{
	PBITMAP bmp;
	
	bmp = get_bmp(id);
	if (bmp)
	{
		//FillBoxWithBitmap(hdc, x, y, w, h, bmp);
		FillBoxWithBitmap(hdc, x, y, bmp->bmWidth, bmp->bmHeight, bmp);
	}
}

/*************************************************
  Function:		DrawBmpIdFree
  Description: 	����ͼƬID��ָ��λ�û�ͼƬ,��߸���
  				ʵ��ͼƬ��С����,�������ͷ��ڴ�
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void DrawBmpIdFree(HDC hdc, int x, int y, int w, int h, int id)
{
	PBITMAP bmp;
	
	bmp = get_bmp(id);
	if (bmp)
	{
		FillBoxWithBitmap(hdc, x, y, bmp->bmWidth, bmp->bmHeight, bmp);
		free_bitmaps(id);
	}
}

/*************************************************
  Function:		DrawBmpID_EX
  Description: 	����ͼƬID��ָ��λ�û�ͼƬ
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void DrawBmpID_EX(HDC hdc, int x, int y, int w, int h, int id)
{
	PBITMAP bmp;
	
	bmp = get_bmp(id);
	if (bmp)
	{
		FillBoxWithBitmap(hdc, x, y, w, h, bmp);
	}
}

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
void draw_Sidebar(HWND hDlg, uint32 H, uint32 x, uint32 y, uint8 allpage, 
uint8 pageCount, uint8 count, uint8 keystate, uint8 select, uint32 curSelect)
{
	uint32 xpos, ypos;

	if (allpage == 0)
	{
		return;
	}
	
	xpos = x;
	ypos = y;
	DrawBmpID(hDlg, xpos, ypos, SIDEBAR_W, SIDEBAR_H, BID_ScrollBK2);

	if (count <= pageCount || curSelect == 0)
	{		
		DrawBmpID(hDlg, xpos+(SIDEBAR_W-SIDEBAR_ICON_W)/2, ypos+SIDEBAR_YDIS, SIDEBAR_ICON_W, SIDEBAR_ICON_H, BID_ScrollIcon);
	}
	else
	{
		if (curSelect == count-1)
		{
			ypos = SIDEBAR_DOWN_ICON_Y;
			DrawBmpID(hDlg, xpos+(SIDEBAR_W-SIDEBAR_ICON_W)/2, ypos, SIDEBAR_ICON_W, SIDEBAR_ICON_H, BID_ScrollIcon);
		}
		else
		{
			#if (_UI_STYLE_ == _E81S_UI_STYLE_)
			ypos = ypos + (curSelect*SIDEBAR_SCRLEN)/count +SIDEBAR_YDIS;
			#else				
			ypos = ypos + (curSelect*SIDEBAR_SCRLEN)/count;
			#endif
			DrawBmpID(hDlg, xpos+(SIDEBAR_W-SIDEBAR_ICON_W)/2, ypos, SIDEBAR_ICON_W, SIDEBAR_ICON_H, BID_ScrollIcon);
		}
	}
}

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
int8 get_Sidebar_key(uint32 H, uint8 mode, uint32 x, uint32 y)
{
	#if 0
	uint32 ypos;
	int8 index = -1;
	
	if (0 == mode)
	{
		ypos = (H-DIS_SIDEBAR_H1-2*DIS_SIDEBAR_ICON_H)/2;
	}
	else
	{
		ypos = (H-DIS_SIDEBAR_H2-2*DIS_SIDEBAR_ICON_H)/2;
	} 

	if (y > 0 && y <(ypos*4+DIS_SIDEBAR_ICON_H))
	{
		index = 0;
	}
	else
	{
		if (y > (H-3*ypos-DIS_SIDEBAR_ICON_H))
		{
			index = 1;
		}
	}
	return index;
	#endif
	return 0;
}

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
int32 ui_show_win_arbitration(HWND hDlg, SYS_ASYN_OPER_TYPE OperType)
{
	SYS_MEDIA_TYPE CurState = sys_get_media_state();
	uint8 flg = FALSE;
	HWND CurWin ;

	//ui_back_main_page();							// �˻ص�������
	SetScreenTimer();								// ����
	sys_open_lcd();
	
	log_printf("ui_show_win_arbitration : CurState : %d\n", CurState);
	if (hDlg == 0)
	{
		CurWin = (get_cur_form())->hWnd;
	}
	else
	{
		CurWin = hDlg;
	}
	
	switch (OperType)
	{
		case SYS_OPER_ALARMING:
			flg = TRUE;
			break;
			
		case SYS_OPER_ALARM_SOS:
			switch (CurState)
			{
				case SYS_MEDIA_INTERCOM:
				case SYS_MEDIA_MONITOR:
				case SYS_MEDIA_FAMILY_RECORD:
					flg = FALSE;
					break;
				default:
					flg = TRUE;
					break;
			}
			break;
			
		case SYS_OPER_CALLOUT:
			switch (CurState)
			{
				// �ڸ�Ӧ�������С�������С��ز�����ʱ����ҳ���ϵ��ٲ�
				case SYS_MEDIA_ALARM:
				case SYS_MEDIA_INTERCOM:
				case SYS_MEDIA_MONITOR:
					flg = FALSE;
					break;
				default:
					flg = TRUE;
					break;
			}
			break;
	
		case SYS_OPER_CALLIN:
			// �ٲ��Ѿ��ڱ��н���ʱ��ɣ���ʱֻ��ɿ����Ȳ���
			return TRUE;
			
		case SYS_OPER_MONITOR:
			switch (CurState)
			{
				case SYS_MEDIA_ALARM:
				case SYS_MEDIA_INTERCOM:
				case SYS_MEDIA_MONITOR:
					flg = FALSE;
					break;
				default:
					flg = TRUE;
					break;
			}
			break;
		default:
			return FALSE;
	}

	if (flg == TRUE)
	{
		if (SYS_MEDIA_ALARM == CurState && (SYS_OPER_ALARMING == OperType || SYS_OPER_ALARM_SOS == OperType))
		{
			return TRUE;
		}
		
		if ((SYS_OPER_ALARM_SOS == OperType) && (SYS_MEDIA_YUJING == CurState))	// add by caogw 2015-09-24 ���ڱ�������������Ԥ��ʱ���ٰ�������ݼ�ʱ����Ԥ����
		{
			return TRUE;
		}

		#if 0
		if (SYS_MEDIA_YUJING == CurState && (SYS_OPER_ALARMING == OperType ))
		{
			return TRUE;
		}
		#endif
		
		sys_stop_cur_media();
		return TRUE;
	}
	else
	{	
		// ��ʾ��ʾ
		//show_msg(CurWin, WID_MsgNotice, MSG_ERROR, SID_Inter_CaptureFailed);
		return FALSE;
	}
}

/************************************************************/
/*						   ��Ļ����							*/
/************************************************************/
#if 0
/*************************************************
  Function:		Get_ScreenPortectState
  Description:  ��ȡ��ǰ��Ļ����״̬
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
uint8 Get_ScreenPortectState(void)
{
	return g_ScreenState;
}


/*************************************************
  Function:		Set_ScreenPortectState
  Description:  ��������״̬Ϊ�ر�
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void Set_ScreenPortectOff(void)
{
	g_ScreenTime = g_MaxScreenTime;
	g_ScreenState = SCREENPORTECT_OFF;
}

/*************************************************
  Function:		Open_ScreenPortect
  Description:  ����Ļ����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void Open_ScreenPortect(void)
{
	if (g_ScreenState == SCREENPORTECT_OFF)
	{
		g_ScreenTime = g_MaxScreenTime;
		g_ScreenState = SCREENPORTECT_ON;
		if (&FormScreenSaver != get_cur_form())
		{
			Start_ScreenSaver();
		}

		// add by luofl 2015-12-09����������ǰ����Ƶ�쳣ʱ������ڻ��������쳣,ԭ���ڹ����д���
		hw_reset_dev();
		usleep(10*1000);
		storage_set_ipaddr();
	}
}

/*************************************************
  Function:		Close_ScreenPortect
  Description:  �ر���Ļ����
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void Close_ScreenPortect(void)
{
	if (g_ScreenState == SCREENPORTECT_ON)
	{
		g_ScreenTime = g_MaxScreenTime;
		g_ScreenState = SCREENPORTECT_OFF;
		if (&FormScreenSaver == get_cur_form())
		{
			Stop_ScreenSaver();
		}
	}
}
#endif

/*************************************************
  Function:		ScreenOnTimer
  Description: 	��Ļ��LCD��ʱ
  Input:		
  	1.win
  Output:		��
  Return:		TRUE �� FALSE ��
  Others:		
*************************************************/
void ScreenOnTimer(void)
{
	if (SYS_LCD_CLOSE == sys_get_lcd_state() || SYS_MEDIA_NONE != sys_get_media_state())
	{
		return;
	}

	// �鿴ͼƬ״̬�²��،�
	if (sys_get_view_picture_state())
	{
		return;
	}
	
#if 0
	// ��ĺ��������
	if (g_ScreenState == SCREENPORTECT_OFF)
	{
		if (g_ScreenTime > 0)
		{
			//log_printf("g_ScreenTime = %d, g_MaxScreenTime = %d\n", g_ScreenTime, g_MaxScreenTime);
			g_ScreenTime--;
			if (g_ScreenTime == 0)
			{
				back_main_page();
				Open_ScreenPortect();
			}
		}
	}
#endif

	// ������ʱ������
	if (g_LcdTime > 0)
	{
		//log_printf("g_LcdTime = %d, g_MaxLcdTime = %d\n", g_LcdTime, g_MaxLcdTime);
		g_LcdTime--;
		if (g_LcdTime == 0)
		{			
			//Close_ScreenPortect();
			back_main_page();
			sys_close_lcd();
			set_curkey();
			
			// add by luofl 2015-12-09����������ǰ����Ƶ�쳣ʱ������ڻ��������쳣
			hw_reset_dev();
			usleep(10*1000);
			storage_set_ipaddr();
			return;
		}
	}
}

/*************************************************
  Function:		SetScreenTimer
  Description: 	�ָ���Ļ��LCD��ʱʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
uint8 SetScreenTimer(void)
{
	//g_ScreenTime = g_MaxScreenTime;
	g_LcdTime = g_MaxLcdTime;
	//return sys_open_lcd();

	return 0;
}

/*************************************************
  Function:		InitScreenTimer
  Description: 	��ʼ����Ļ��LCD��ʱ
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void InitScreenTimer(void)
{
	g_LcdTime = storage_get_closelcd_time();
	g_MaxLcdTime = storage_get_closelcd_time();
	#if 0
	g_MaxScreenTime = storage_get_screen_intime();
	g_ScreenTime = storage_get_screen_intime();
	log_printf("g_LcdTime=%d,  g_MaxLcdTime=%d,  g_MaxScreenTime=%d, g_ScreenTime=%d\n",
		g_LcdTime, g_MaxLcdTime, g_MaxScreenTime, g_ScreenTime);
	if (storage_get_screen_enable())
	{
		g_ScreenState = SCREENPORTECT_OFF;
	}
	else
	{
		g_ScreenState = SCREENPORTECT_NOUSE;
	}
	#endif
}

#if 0
/************************************************************/
/*						   �����							*/
/************************************************************/

/*************************************************
  Function:		distrub_ontimer
  Description:  ����ż�ʱ
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void distrub_ontimer(void)
{
	if (storage_get_noface())
	{
		if (g_NofaceTime > 0)
		{
			log_printf("g_NofaceTime=%d\n",g_NofaceTime);
			g_NofaceTime--;
			if (0 == g_NofaceTime)
			{
				storage_set_noface_enable(FALSE);
			}
		}
	}
}

/*************************************************
  Function:		init_distrub
  Description:  ��ʼ�������
  Input:		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
void init_distrub(void)
{
	g_NofaceTime = storage_get_noface_time();
}
#endif

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
char * get_houseno_desc(char * numtext, char * temp)
{   
    char devno[30] = {0};
    PFULL_DEVICE_NO fulldevno;
    int32 i = 0, j = 0, nsub = 0;
    uint32 sub, subLen;
    char strsub[10];
    char des[100] = {0};
	char DevDesc[70] = {0xb6,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0xb5,0xa5,0xd4,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0xb7,
						0xbf,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	
	char DevDesc_Big5[70] = {0xb4,0xc9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0xb3,0xe6,0xa4,0xb8,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,
						0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

	char DevDesc_En[3][10] ={"Room ","Unit ","Build "}; 

	char num1[10], des1[11];
    char num[10] = {0};
    int32 index = 0, numIndex = 0, numCount = 0;
    char tmp[100] = {0};
    int32 numTextLen;

 	if (temp == NULL || numtext == NULL)
	{
    	return numtext;
    }
 
    fulldevno = storage_get_devparam();
    sub = fulldevno->Rule.Subsection;
    sprintf(strsub, "%d", sub);
    subLen = strlen(strsub);
    if (subLen < 2)
    {
    	strcpy(temp, numtext);
        return numtext;
    }
    
    nsub = 0;
	
	#if 1
    memcpy(des, storage_get_dev_desc(), 70);		// �ֶ�������
	#else
	if (storage_get_language() == CHINESE)
	{
		memcpy(des, DevDesc, 70);
	}
	else if(storage_get_language() == CHNBIG5)
	{
		memcpy(des, DevDesc_Big5, 70);
	}
	#endif
	
    sprintf(devno, "%s", numtext);
    numTextLen = strlen(devno);

	// subLen: ���ٸ��ֶ�, �����224��subLen = 3;
	// strsub: ��"224"
	// i: 0-(subLen-1),��"224"ʱ��i=0 - 2
    for (i = subLen-1; i >= 0; i--)
    {
    	memset(num, 0, sizeof(num));
        num[0] = strsub[subLen-1-i];
        //num[1] = 0;
        // nsub: ÿ���ֶε�����ֵ����2,2,4
        nsub = atoi(num);
		// des: sub data�ļ���ֵ��"224"ʱΪ30���ֽ�
		// des1: ÿ���ֶε�������
		#if 1
        memcpy(des1, des+10*(subLen-1-i), 10);
		#else
		if (storage_get_language() == ENGLISH)
		{
			memcpy(des1, DevDesc_En[i], 10);
		}
		else
		{
			memcpy(des1, des+10*(subLen-1-i), 10);
		}
		#endif
        des1[10] = 0;
        numIndex = 0;
        for (j=index;j<nsub+numCount;j++)
        {       	
        	// num1: ÿ���ֶεı��, ��224�����"010203040"���, num1 = "01"��"02"��"0304"
            num1[numIndex++] = devno[j];
            index++;
        }
        // numCount,index: ��ס�ϸ��ֶο������λ��
        numCount = index;
        num1[numIndex] = 0;
		
        // �����ֶα��,����
        sprintf(tmp, "%s%s%s", tmp, num1, des1);
        if (j+1 == numTextLen || j == numTextLen)
        {
            if (j+1 == numTextLen)
            {
                num1[0] =devno[j+1];
                num[1] = 0;
                sprintf(tmp,"%s%s",tmp,num1);
            }
            break;
        }
    }
    sprintf(temp,"%s",tmp);
    return temp;
}

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
uint32 get_dev_description(DEVICE_TYPE_E DevType, char * DevStr, char * DevStrOut, uint32 StrOutLen)
{
	int32 nlen = strlen(DevStr);
 	int32 number = atoi(DevStr);
	
	PFULL_DEVICE_NO fulldevno;
	char DevNo[100] = {0};
	uint8 StairNoLen, CellNoLen, RoomNoLen, UseCellNo;
	uint16 TextID = 0;
	//uint32 OutStrLen = 0;
		
	if (DevStrOut == NULL || DevStr == NULL)
	{
		log_printf("get_dev_description : input param is NULL\n");
    	return 0;
    }

	memset(DevStrOut, 0, sizeof(DevStrOut));
   
	fulldevno = storage_get_devparam();
	StairNoLen = fulldevno->Rule.StairNoLen;
	CellNoLen = fulldevno->Rule.CellNoLen;
	RoomNoLen = fulldevno->Rule.RoomNoLen;
	UseCellNo = fulldevno->Rule.UseCellNo;
	
	switch(DevType)
	{
		case DEVICE_TYPE_MANAGER:					// ����Ա��
			TextID = SID_DevManager;
			if (nlen != 0 && number > MANAGER_NUM)
			{
				sprintf(DevNo, "%d", number-MANAGER_NUM);
			}
			break;
			
		case DEVICE_TYPE_AREA:						// ���ڻ�
			TextID = SID_DevArea;
			sprintf(DevNo, "%d", number);
			break;
			
		case DEVICE_TYPE_STAIR:						// �ݿڻ�
		{
			int32 LastNo = atoi(DevStr+StairNoLen);	
			TextID = SID_DevStair;
			sprintf(DevNo, "%d", LastNo+1);			
			break;
		}
		
		case DEVICE_TYPE_DOOR_NET:					// ��ǰ��(����)
		{
			char dev = DevStr[nlen-1];
			if (dev == '1')
			{
				TextID = SID_DevDoorNet;								
				sprintf(DevNo, "%d", 1);
			}
			else if (dev == '2')
			{
				TextID = SID_DevDoorNet;
				sprintf(DevNo, "%d", 2);
			}
			else
			{
				return 0;
			}
			break;
		}

		case DEVICE_TYPE_DOOR_PHONE:				// ��ǰ��(ģ��)
		{
			char dev = DevStr[nlen-1];
			if (dev == '1')
			{
				TextID = SID_DevDoorPhone;		
				sprintf(DevNo, "%d", 1);
			}
			else if (dev == '2')
			{
				TextID = SID_DevDoorPhone;
				sprintf(DevNo, "%d", 2);
			}
			else
			{
				return 0;
			}
			break;
		}

		case DEVICE_TYPE_IPCAMERA:
			TextID = SID_DevIPCamera;
			sprintf(DevNo, "%s", DevStr);
			break;	
		
		case DEVICE_TYPE_ROOM:						// ���ڻ�			
			get_houseno_desc(DevStr, DevNo);
			strcpy(DevStrOut, DevNo);
			#if 0
			Gbk2Unicode(DevStrOut, DevNo);
			OutStrLen = MeasureStringPixLen(DevStrOut, Font16X16);
			if (OutStrLen%2 != 0)
			{
				OutStrLen++;
			}
		    return OutStrLen;	
			#endif
			return 0;

		case DEVICE_TYPE_FENJI_NET:
			if (nlen == 1)
			{
				if (DevStr && DevStr[0] == '0')
				{
					TextID = SID_DevMaster;					
				}
				else
				{
					TextID = SID_DevFenJi;	
					sprintf(DevNo, "%s", DevStr);
				}
			}
			else
			{
				return 0;
			}
			break;
			
		default:
			return 0;
	}

	strcpy(DevStrOut, get_str(TextID));
	strcat(DevStrOut, DevNo);
	#if 0
	OutStrLen = MeasureStringPixLen(DevStrOut, Font16X16);
	if (OutStrLen%2 != 0)
	{
		OutStrLen++;
	}
    return OutStrLen;
	#endif 

	return 0;
}

/*************************************************
  Function:		OnPaintBack
  Description: 	����ɫ����
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
void OnPaintBack(HWND hDlg)
{	
	HDC hdc;

	InvalidateRect(hDlg, NULL, FALSE);
	hdc = BeginPaint(hDlg);
	SetBrushColor(hdc, PAGE_BK_COLOR);
	FillBox(hdc, 0, 0, 640, 480);
	EndPaint(hDlg, hdc);
	log_printf("OnPaintBack end!!!\n");
}

/*************************************************
  Function:		OnPaintWhite
  Description: 	����ɫ����
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
void OnPaintWhite(HWND hDlg)
{	
	HDC hdc;

	InvalidateRect(hDlg, NULL, FALSE);
	hdc = BeginPaint(hDlg);
	DrawBmpID(hdc, 0, 0, 0, 0, BID_Set_BK);
	EndPaint(hDlg, hdc);
	log_printf("OnPaintWhite end!!!\n");
}

#ifdef _TIMER_REBOOT_NO_LCD_
/*************************************************
  Function:     timer_reboot_control
  Description:  ��ʱ��������������л�
  Input:        
    1.flag       1: ��Ƭ������������ 
                 0: N32926����������
  Output:       ��
  Return:       ��
  Others:   
  ҹ������ʱ���������������쿪������
  �������û�����쳣��
*************************************************/
void timer_reboot_control(uint8 flag)
{	
    if(flag == TRUE)
    {
    	storage_set_openscreen(1);
    }
    else
    {
    	storage_set_openscreen(0);
		sys_close_lcd();
		// Ϊ�˱�֤����оƬģ����������������
		sleep(2); 
    }
	hw_set_lcd_pwm0(flag);
}
#endif

#if 0
/*************************************************
  Function:		OnPaintBack
  Description: 	����ɫ����
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
void OnPaintBack(HWND hDlg)
{	
	HDC hdc;

	InvalidateRect(hDlg, NULL, FALSE);
	hdc = BeginPaint(hDlg);
	SetBrushColor(hdc, PAGE_BK_COLOR);
	FillBox(hdc, 0, 0, 640, 480);
	EndPaint(hDlg, hdc);
	log_printf("OnPaintBack end!!!\n");
}

/*************************************************
  Function:		OnPaintWhite
  Description: 	����ɫ����
  Input: 		
	1.hDlg		���
  Output:		��
  Return:		��
  Others:
*************************************************/
void OnPaintWhite(HWND hDlg)
{	
	HDC hdc;

	InvalidateRect(hDlg, NULL, FALSE);
	hdc = BeginPaint(hDlg);
	DrawBmpID(hdc, 0, 0, 0, 0, BID_Set_BK);
	EndPaint(hDlg, hdc);
	log_printf("OnPaintWhite end!!!\n");
}
#endif
#if 0
/*************************************************
  Function:			show_qwerty_keypad
  Description:  	����Ӣ�ļ���
  Input:		
  	1.win			����
  	2.ID			ID
  	3.InputMaxLen	�����������ĸ����
  	4.ShowMaxLen	����ʾ�����ĸ����
  Output:			��
  Return:			��
  Others:
*************************************************/
WINDOW* show_qwerty_keypad(WINDOW* win, WIN_ID ID, uint16 InputMaxLen, InputStyle style)
{
	WINDOW * CtrlWin = NULL;
	QwertyKeyPadInfo info;
	memset(&info, 0, sizeof(QwertyKeyPadInfo));
	info.LetterInputMax = InputMaxLen;
	info.style = style;
	
	CtrlWin = WindowCreate(win ,
				WS_ACTIVE|WS_NOTIFYPARENTCLOSED|WS_Transp|WS_FULLSCREEN,
				ID,
				0,0,
				LCD_W,LCD_H,
				0,
				0,
				0,
				NULL,
				WinQwertyKeyPadCtrlMap,
				&info);
	return CtrlWin;
}
#endif

