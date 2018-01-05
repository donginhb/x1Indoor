/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	storage_netdoor.h
  Author:    	zxc
  Version:   	2.0
  Date: 		2014-11-06
  Description:	������ǰ�洢
  
  History:                    
    1. Date:		 
       Author:		 
       Modification: 
    2. ...
*********************************************************/
#ifndef _STORAGE_NETDOOR_H_
#define _STORAGE_NETDOOR_H_

#include "storage_include.h"

#ifdef _ADD_BLUETOOTH_DOOR_

#define MAX_BLEDOOR_PIC_NUM				10					// ��ǰץ��ͼƬ���10��

#if 0
//ץ������
typedef enum
{
	SNAP_BODY_INDUCTION		= 1,		// �����Ӧ����
	SNAP_OPERATE_ERR3		= 2,		// ���β���ʧ������
	SNAP_TAMPER_ALARM		= 3,		// ���𱨾�����
	SNAP_VISITOR			= 4,		// �ÿͺ�������
}SNAP_TYPE_E;
#endif

//ץ��¼������
typedef enum
{
	ACTION_BODY_INDUCTION	= 1,		// �����Ӧ
	ACTION_OPERATE_ERR3		= 2,		// ��β���ʧ��
}SNAP_RECORD_TYPE_E;


// �����ϴ�ͼƬ�ṹ��
typedef struct
{
	uint8 is_unread;								// 0 - �Ѷ���1 - δ����־	
	uint32 ID;
	ZONE_DATE_TIME ourtime;								// ʱ��
	uint8 time[24];									// ʱ��
	SNAP_RECORD_TYPE_E event_type;					// �¼�����
}BLEDOOR_PIC_DATA, * PBLEDOOR_PIC_DATA;

// �����ϴ�ͼƬ�б�
typedef struct
{
	uint8 ncount;
	BLEDOOR_PIC_DATA pinfo_data[MAX_BLEDOOR_PIC_NUM];
}BLEDOOR_PIC_LIST, * PBLEDOOR_PIC_LIST;


/*************************************************
  Function:    		storage_set_bledoor_pic_readed
  Description:		�����Ѷ�������δ����־
  Input:
  	1.index			ͼƬ����
  Output:			
  Return:			���óɹ�TRUE,ʧ��FALSE
  Others:			
*************************************************/
ECHO_STORAGE storage_set_bledoor_pic_readed(uint8 index, uint8 door_index);

/*************************************************
  Function:			storage_read_bledoor_pic_data
  Description: 		��ȡͼƬ����
  Input:
  	1.pmsg_data		�ṹ��
  	2.index			����
  Output:		
  Return:			ͼƬ�ļ���
  Others:
*************************************************/ 
char * storage_read_bledoor_pic_data(BLEDOOR_PIC_DATA *pmsg_data, uint8 index, uint8 doorindex);

/*************************************************
  Function:			storage_read_bledoor_pic_list
  Description: 		��ȡͼƬ�б�
  Input:			��
  Output:			��
  Return:			BLEDOOR_PIC_LIST	�ṹָ��
  Others:			�ɵ������ͷ�
*************************************************/ 
BLEDOOR_PIC_LIST * storage_read_bledoor_pic_list(uint8 doorindex);

/*************************************************
  Function:			storage_write_bledoor_pic
  Description: 		д����ǰ�����ϴ�ͼƬ
  Input:		
  Output:		   
  Return:		    
  Others:
*************************************************/
ECHO_STORAGE storage_write_bledoor_pic(uint32 ID, uint8 * data, int size, char doorindex);

/*************************************************
  Function:    		storage_delete_bledoor_pic
  Description:		ɾ������ͼƬ
  Input:
  	1.index			ͼƬ����
  Output:			��
  Return:			ɾ���ɹ�TRUE, ʧ��FALSE
  Others:			
*************************************************/
ECHO_STORAGE storage_delete_bledoor_pic(uint8 index, uint8 doorindex);

/*************************************************
  Function:			storage_clear_bledoor_pic
  Description: 		���ͼƬ
  Input:			��
  Output:		 	��
  Return:			TRUE/FALSE
  Others:
*************************************************/
ECHO_STORAGE storage_clear_bledoor_pic(uint8 doorindex);

/*************************************************
  Function:			storage_get_msg_state
  Description: 		��ȡͼƬ�Ƿ���δ����ʾ
  Input:			��
  Output:			��
  Return:			TRUE:��δ�� FALSE:��δ��
  Others:
*************************************************/
uint8 storage_get_bledoor_pic_state(uint8 doorindex);

/*************************************************
  Function:			storage_get_bledoor_pic_allsize
  Description: 		��ȡ������ǰץ���ϴ�ͼƬ�ܴ�С
  Input:			��
  Output:		 	��
  Return:			������
  Others:
*************************************************/
int storage_get_bledoor_pic_allsize(uint8 doorindex);
#endif

#endif

