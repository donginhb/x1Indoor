/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	storage_netdoor.c
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
#include "storage_include.h"

#ifdef _ADD_BLUETOOTH_DOOR_
/*************************************************
  Function:    		storage_set_bledoor_pic_readed
  Description:		�����Ѷ�������δ����־
  Input:
  	1.index			ͼƬ����
  Output:			
  Return:			���óɹ�TRUE,ʧ��FALSE
  Others:			
*************************************************/
ECHO_STORAGE storage_set_bledoor_pic_readed(uint8 index, uint8 door_index)
{
	FILE* fPListFile = NULL;
	char path[50] = {0};
	BLEDOOR_PIC_LIST infolist;

	if (1 == door_index)
	{
		memcpy(path, DOOR_PIC_1_PATH, sizeof(DOOR_PIC_1_PATH));
	}
	else
	{
		memcpy(path, DOOR_PIC_2_PATH, sizeof(DOOR_PIC_2_PATH));
	}
	
	fPListFile = fopen(path, "r+");
	if (fPListFile == NULL)
    {
		return ECHO_STORAGE_NOFILE;
    }
	else
	{
		fread((char*)&infolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
		infolist.pinfo_data[index].is_unread = 0;
		
		fclose(fPListFile);
		fPListFile = NULL;
		fPListFile = fopen(path, "w");
		if (NULL != fPListFile)
		{
			fwrite((char*)&infolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
		}
	}
	
	if (fPListFile)
	{
		FSFlush(fPListFile);
		fclose(fPListFile);
    	fPListFile = NULL;
	}

	return ECHO_STORAGE_OK;
}


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
char * storage_read_bledoor_pic_data(BLEDOOR_PIC_DATA *pmsg_data, uint8 index, uint8 doorindex)
{
	char path[50] = {0};
	//FILE* fPListFile = NULL;
	char * data = NULL;
	uint32 size = 0;
	
	if (NULL == pmsg_data)
	{
		log_printf("storage_read_msg_data  NULL == pmsg_data \n");
		return NULL;
	}
	
	memset(path, 0, sizeof(path));
	sprintf(path, "%s/%d-%d-%d-%d-%d-%d-%d.jpg", DOOR_PIC_DIR_PATH, pmsg_data->ourtime.year, pmsg_data->ourtime.month, \
						pmsg_data->ourtime.day, pmsg_data->ourtime.hour, pmsg_data->ourtime.min, pmsg_data->ourtime.sec, pmsg_data->ID);
	data = malloc(sizeof(path));
	memcpy(data, path, sizeof(path));
	//log_printf("0 != pmsg_data->Head.ImageLen \n");
	
	if (1 == pmsg_data->is_unread)
	{
		storage_set_bledoor_pic_readed(index, doorindex);
	}
	
	return data;
}

/*************************************************
  Function:			storage_read_bledoor_pic_list
  Description: 		��ȡͼƬ�б�
  Input:			��
  Output:			��
  Return:			BLEDOOR_PIC_LIST	�ṹָ��
  Others:			�ɵ������ͷ�
*************************************************/ 
BLEDOOR_PIC_LIST * storage_read_bledoor_pic_list(uint8 doorindex)
{
	FILE* fPListFile = NULL;
	char path[50] = {0};
	
	BLEDOOR_PIC_LIST * pinfolist = (BLEDOOR_PIC_LIST *)malloc(sizeof(BLEDOOR_PIC_LIST));
	if (NULL == pinfolist)
	{
		log_printf("storage_read_msg_list NULL == pinfolist \n");
		return NULL;
	}
	if (1 == doorindex)
	{
		memcpy(path, DOOR_PIC_1_PATH, sizeof(DOOR_PIC_1_PATH));
	}
	else
	{
		memcpy(path, DOOR_PIC_2_PATH, sizeof(DOOR_PIC_2_PATH));
	}
	
	fPListFile = fopen(path, "r+");
	if (NULL == fPListFile)
    {
    	free(pinfolist);
		return NULL;
    }
	else
	{
		fread(pinfolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
	}
	
	if (fPListFile)
	{
		fclose(fPListFile);
    	fPListFile = NULL;
	}

	return pinfolist;
}

/*************************************************
  Function:    		storage_delete_bledoor_pic_data
  Description:		ɾ��ĳ��ͼƬ������
  Input:
  	1.ppic_data		ͼƬ�ṹ
  Output:			
  Return:			ɾ���ɹ�TRUE, ʧ��FALSE
  Others:			
*************************************************/
static void storage_delete_bledoor_pic_data(BLEDOOR_PIC_DATA *ppic_data)
{
	char path[50];
	BLEDOOR_PIC_DATA pic_data;
	pic_data = *ppic_data;
	
	memset(path, 0, sizeof(path));
	// ɾ��ͼƬ�ļ�
	
	sprintf(path, "%s/%d-%d-%d-%d-%d-%d-%d.jpg", DOOR_PIC_DIR_PATH, pic_data.ourtime.year, pic_data.ourtime.month, \
						pic_data.ourtime.day, pic_data.ourtime.hour, pic_data.ourtime.min, pic_data.ourtime.sec, pic_data.ID);
	
	//log_printf("delete iamge content path:%s \n", path);
	if (ECHO_STORAGE_OK == IsHaveFile(path))
	{
		FSFileDelete(path);
		log_printf("after iamge FSFileDelete \n");
	}
}

/*************************************************
  Function:			storage_write_bledoor_pic
  Description: 		д����ǰ�����ϴ�ͼƬ
  Input:		
  Output:		   
  Return:		    
  Others:
*************************************************/
ECHO_STORAGE storage_write_bledoor_pic(uint32 ID, uint8 * data, int size, char doorindex)
{
	size_t count = 0;
	uint32 len;
	FILE* fPListFile = NULL;
	char path[100] = {0};
	int8 i;
	BLEDOOR_PIC_DATA pic_data;
	uint8 size1 = 0;

	BLEDOOR_PIC_LIST *pinfolist = (BLEDOOR_PIC_LIST *)malloc(sizeof(BLEDOOR_PIC_LIST));
	
	if (NULL == pinfolist)
	{
		log_printf("storage_write_msg NULL == pinfolist\n");
		return ECHO_STORAGE_ERR;
	}
	log_printf("storage_write_msg begin\n");
	memset(&pic_data, 0, sizeof(BLEDOOR_PIC_DATA));

	if (1 == doorindex)
	{
		memcpy(path, DOOR_PIC_1_PATH, sizeof(DOOR_PIC_1_PATH));
	}
	else
	{
		memcpy(path, DOOR_PIC_2_PATH, sizeof(DOOR_PIC_2_PATH));
	}
	

	memcpy(pic_data.time, data, 24);
	pic_data.event_type = *(uint8 *)(data+24);
	pic_data.is_unread = 1;							// ��δ����־
	pic_data.ID = ID;

	memcpy((char*)&pic_data.ourtime, &size1, sizeof(DATE_TIME));
	get_timer(&pic_data.ourtime);

	#if 1
	fPListFile = fopen(path, "r+");
	
	// һ����д��10�����ȵĽṹ
	if (fPListFile == NULL)
    {
        fPListFile = fopen(path, "w");
		log_printf("first writh msg  \n");
		if (NULL == fPListFile)
		{
			free(pinfolist);
			log_printf("storage_write_msg NULL == fPListFile \n");
			return ECHO_STORAGE_NOFILE;
		}
		pinfolist->ncount = 1;
		pinfolist->pinfo_data[0] = pic_data;
		count = fwrite(pinfolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
    }
	else
	{
		fread((char*)pinfolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
		log_printf("infolist.ncount:%d \n", pinfolist->ncount);
		if (MAX_BLEDOOR_PIC_NUM >  pinfolist->ncount)
		{
			i = pinfolist->ncount-1;
			do 
			{
				log_printf("infolist.ncount; %d why \n", pinfolist->ncount);
				memcpy((char *)&pinfolist->pinfo_data[i+1], (char *)&pinfolist->pinfo_data[i], sizeof(BLEDOOR_PIC_DATA));
				i--;
			}while(i > -1);
			pinfolist->ncount = pinfolist->ncount+1;
		}
		else
		{
			pinfolist->ncount = MAX_MSG_NUM;
			// ɾ�����һ��
			storage_delete_bledoor_pic_data(&pinfolist->pinfo_data[MAX_BLEDOOR_PIC_NUM-1]);
			for (i = pinfolist->ncount-2; i > -1; i--)
			{
				memcpy((char *)&pinfolist->pinfo_data[i+1], (char *)&pinfolist->pinfo_data[i], sizeof(BLEDOOR_PIC_DATA));
			}
		}
		pinfolist->pinfo_data[0] = pic_data;
		fclose(fPListFile);
		fPListFile = NULL;
		fPListFile = fopen(path, "w");
		if (NULL != fPListFile)
		{
			count = fwrite((char*)pinfolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
			log_printf("storage_write_msg count: %d, sizeof(BLEDOOR_PIC_LIST): %d \n", count, sizeof(BLEDOOR_PIC_LIST));
		}
	}
	free(pinfolist);
	if (fPListFile)
	{
		fclose(fPListFile);
    	fPListFile = NULL;
	}
	#endif
	
	#if 1
	// ͼƬ������
	memset(path, 0, sizeof(path));
	sprintf(path, "%s/%d-%d-%d-%d-%d-%d-%d.jpg", DOOR_PIC_DIR_PATH, pic_data.ourtime.year, pic_data.ourtime.month, \
						pic_data.ourtime.day, pic_data.ourtime.hour, pic_data.ourtime.min, pic_data.ourtime.sec, pic_data.ID);

	fPListFile = fopen(path, "w");
	if (NULL == fPListFile)
	{
		log_printf("NULL == fPListFile msg content\n");
		return ECHO_STORAGE_NOFILE;
	}
	count = fwrite(data+25, size-25, 1, fPListFile);
	log_printf("count: %d \n", count);
	
	if (fPListFile)
	{
		FSFlush(fPListFile);
		fclose(fPListFile);
    	fPListFile = NULL;
	}
	
	#endif
	log_printf("storage_write_msg end\n");
	
	return ECHO_STORAGE_OK;
}

/*************************************************
  Function:    		storage_delete_bledoor_pic
  Description:		ɾ������ͼƬ
  Input:
  	1.index			ͼƬ����
  Output:			��
  Return:			ɾ���ɹ�TRUE, ʧ��FALSE
  Others:			
*************************************************/
ECHO_STORAGE storage_delete_bledoor_pic(uint8 index, uint8 doorindex)
{
	FILE* fPListFile = NULL;
	char path[50] = {0};
	//int ret = 0;
	BLEDOOR_PIC_LIST infolist;
	BLEDOOR_PIC_DATA pic_data;

	memset(&pic_data, 0, sizeof(BLEDOOR_PIC_DATA));
	if (1 == doorindex)
	{
		memcpy(path, DOOR_PIC_1_PATH, sizeof(DOOR_PIC_1_PATH));
	}
	else
	{
		memcpy(path, DOOR_PIC_2_PATH, sizeof(DOOR_PIC_2_PATH));
	}

	fPListFile = fopen(path, "r+");
	if (NULL != fPListFile)
	{
		fread(&infolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
		pic_data = infolist.pinfo_data[index];
		if (index > (infolist.ncount - 1))
		{
			fclose(fPListFile);
			return ECHO_STORAGE_ERR;
		}
		if (0 != (infolist.ncount-index-1))
		{
			memcpy((char*)&infolist.pinfo_data[index], (char*)&infolist.pinfo_data[index+1], sizeof(BLEDOOR_PIC_DATA)*(infolist.ncount-index-1));
		}
		else
		{
			memset((char*)&infolist.pinfo_data[index], 0, sizeof(BLEDOOR_PIC_DATA));
		}
		//log_printf("storage_delete_msg infolist.ncount:%d \n", infolist.ncount);
		infolist.ncount--;
		fseek(fPListFile, 0, SEEK_SET);
		fwrite((char*)&infolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
	}
	else
	{
		return ECHO_STORAGE_NOFILE;
	}
	if (fPListFile)
	{
		fclose(fPListFile);
    	fPListFile = NULL;
	}
	storage_delete_bledoor_pic_data(&pic_data);
	
	return ECHO_STORAGE_OK;
}

/*************************************************
  Function:			storage_clear_bledoor_pic
  Description: 		���ͼƬ
  Input:			��
  Output:		 	��
  Return:			TRUE/FALSE
  Others:
*************************************************/
ECHO_STORAGE storage_clear_bledoor_pic(uint8 doorindex)
{
	FILE* fPListFile = NULL;
	char path[50] = {0};
	//int ret = 0;
	uint8 i;
	BLEDOOR_PIC_LIST infolist;
	BLEDOOR_PIC_DATA pic_data;

	if (1 == doorindex)
	{
		memcpy(path, DOOR_PIC_1_PATH, sizeof(DOOR_PIC_1_PATH));
	}
	else
	{
		memcpy(path, DOOR_PIC_2_PATH, sizeof(DOOR_PIC_2_PATH));
	}
	
	fPListFile = fopen(path, "r+");
	if (NULL != fPListFile)
	{
		fread(&infolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
	}
	else
	{
		return ECHO_STORAGE_NOFILE;
	}
	if (fPListFile)
	{
		fclose(fPListFile);
    	fPListFile = NULL;
	}
	memset(path, 0, sizeof(path));
	
	for (i = 0; i < infolist.ncount; i++)
	{
		pic_data = infolist.pinfo_data[i];
		storage_delete_bledoor_pic_data(&pic_data);
	}
	
	if (1 == doorindex)
	{
		FSFileDelete(DOOR_PIC_1_PATH);
	}
	else
	{
		FSFileDelete(DOOR_PIC_2_PATH);
	}
	log_printf("clean delect end\n");
	return ECHO_STORAGE_OK;
}

/*************************************************
  Function:			storage_get_bledoor_pic_state
  Description: 		��ȡͼƬ�Ƿ���δ����ʾ
  Input:			��
  Output:			��
  Return:			TRUE:��δ�� FALSE:��δ��
  Others:
*************************************************/
uint8 storage_get_bledoor_pic_state(uint8 doorindex)
{
	uint8 i,unread_num = 0;
	BLEDOOR_PIC_LIST *pinfolist = storage_read_bledoor_pic_list(doorindex);
	
	if (NULL == pinfolist)
	{
		return unread_num;
	}
	for (i = 0; i < pinfolist->ncount; i++)
	{
		if (1 == pinfolist->pinfo_data[i].is_unread)
		{
			unread_num ++;
		}
	}
	free(pinfolist);
	return unread_num;
}

/*************************************************
  Function:    		storage_get_bledoor_pic_onesize
  Description:		��ȡ����ͼƬ�Ĵ�С
  Input:
  	1.pmsg_data		�ṹ
  Output:			��
  Return:			������Ϣ����
  Others:			
*************************************************/
static int storage_get_bledoor_pic_onesize(BLEDOOR_PIC_DATA * ppic_data)
{
	char path[50];
	BLEDOOR_PIC_DATA pic_data;
	int size = 0;
	pic_data = *ppic_data;
	
	memset(path, 0, sizeof(path));
	// ���ֻ�ͼƬ�ļ���С
	{
		sprintf(path, "%s/%d-%d-%d-%d-%d-%d-%d.jpg", DOOR_PIC_DIR_PATH, pic_data.ourtime.year, pic_data.ourtime.month, \
						pic_data.ourtime.day, pic_data.ourtime.hour, pic_data.ourtime.min, pic_data.ourtime.sec, pic_data.ID);
	
		if (ECHO_STORAGE_OK == IsHaveFile(path))
		{
			size = get_size(path);
		}
	}

	//log_printf("path:%s, size: %d \n", path, size);
	return size;
}

/*************************************************
  Function:			storage_get_bledoor_pic_allsize
  Description: 		��ȡ������ǰץ���ϴ�ͼƬ�ܴ�С
  Input:			��
  Output:		 	��
  Return:			������
  Others:
*************************************************/
int storage_get_bledoor_pic_allsize(uint8 doorindex)
{
	FILE* fPListFile = NULL;
	char path[50] = {0};
	uint8 i;
	int size = 0;
	BLEDOOR_PIC_LIST infolist;
	BLEDOOR_PIC_DATA pic_data;

	if (1 == doorindex)
	{
		memcpy(path, DOOR_PIC_1_PATH, sizeof(DOOR_PIC_1_PATH));
	}
	else
	{
		memcpy(path, DOOR_PIC_2_PATH, sizeof(DOOR_PIC_2_PATH));
	}
	
	size = get_size(path);
	fPListFile = fopen(path, "r+");
	
	if (NULL != fPListFile)
	{
		fread(&infolist, sizeof(BLEDOOR_PIC_LIST), 1, fPListFile);
	}
	else
	{
		return ECHO_STORAGE_NOFILE;
	}
	if (fPListFile)
	{
		fclose(fPListFile);
    	fPListFile = NULL;
	}
	memset(path, 0, sizeof(path));
	
	for (i = 0; i < infolist.ncount; i++)
	{
		pic_data = infolist.pinfo_data[i];
		size += storage_get_bledoor_pic_onesize(&pic_data);
	}
	//log_printf("storage_get_msg_allsize size: %d \n", size);

	return size;
}
#endif

