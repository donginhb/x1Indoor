/*********************************************************
  Copyright (C), 2009-2012
  File name:	ui_procress_ctrl.h
  Author:   	zhengxc
  Version:   	1.0
  Date: 		15.7.15
  Description:  ���ȿؼ�ͷ�ļ�
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef __UI_PROCRESS_CTRL_H__
#define __UI_PROCRESS_CTRL_H__

/********************************************************/
/*						�ؼ��ṹ						*/
/********************************************************/

typedef struct 
{
	uint8 proc;										// ��ǰ����
	uint8 allproc;									// �ܽ���
	uint32 ImageBK;								// ͼƬID	
	uint32 Image[2];								// ����ͼƬID		
	uint32 ImageProc;								// ͼƬ����
}PROCRESS_CTRL,*PPROCRESS_CTRL;

#endif /* __UI_PROCRESS_CTRL_H__ */



