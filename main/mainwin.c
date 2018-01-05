/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	mainwin.c
  Author:     	chenbh
  Version:    	2.0
  Date: 		2014-08-30
  Description:  
*************************************************/
#include "storage_include.h"
#include "logic_include.h"
#include "gui_include.h"

/*************************************************
  Function:		MiniGUIMain
  Description: 	ϵͳmain����
  Input: 		��
  Output:		��
  Return:		��
  Others:
*************************************************/
int MiniGUIMain (int argc, const char* argv[])
{	
	#if defined(_LITE_VERSION)
	if (JoinLayer(argv[0], 0, 0) == INV_LAYER_HANDLE) 
	{
    	printf ("JoinLayer: invalid layer handle.\n");
		exit (1);
	}
	#endif

	logic_init();				// ��ʼ���߼�
	InitGui();					// ��ʼ��GUI
	InitScreenTimer();
	form_showmodal(&FrmMain);

	FreeGUI();
	return 0;
}

