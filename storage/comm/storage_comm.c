/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	storage_comm.c
  Author:    	luofl
  Version:   	2.0
  Date: 		2014-11-03
  Description:  �洢ģ�鹫���ӿ�
  				�洢ģ��Ҫ�õ��Ĺ����ӿڶ�����ʵ��
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#include "storage_include.h"
//#include "storage_path.h"

static uint8 ModelFlag[FLAG_COUNT];

/**************************************************************************/
/*								 ����Ƶsdp����							  */	
/**************************************************************************/
#define  VIDEO_FILE_NAME  "D:\\video_param.dat"	
#define  AUDIO_FILE_NAME  "D:\\audio_param.dat"	

/**************************************************************************/
/*								����ע��ɹ��豸���					  */	
/**************************************************************************/
//#define	PRE_DEVNO_FILENAME	"D:\\pre_devno.dat"

/*************************************************
  Function:		DelayMs_nops
  Description: 	
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void DelayMs_nops(uint32 count)
{
	usleep(count*1000);
	return;
}

/*************************************************
  Function:     is_fileexist
  Description:  �ж�ָ��·���ļ��Ƿ����
  Input:       	
   	1.path		ָ���ļ���·��
  Output:       ��
  Return:
				�ļ�����:TRUE
				�ļ�������:FALSE
  Others:
*************************************************/
int32 is_fileexist(char * path)
{
	struct stat buf;
	int32 ret;
	
	if (NULL == path)
	{
		return FALSE;
	}
	ret = stat((const char *)path, &buf);
	if (-1 == ret)
	{
		if (errno == ENOENT)
		{
			return FALSE;
		}
	}
		
	return TRUE;	
}

/*************************************************
  Function:		IsHaveFile
  Description: 	�Ƿ��и��ļ�
  Input:		
  	1.Filename	�ļ���
  Output:		��
  Return:		ECHO_VALUE (OK ERR)
  Others:
*************************************************/
ECHO_STORAGE IsHaveFile (char* Filename)
{
	ECHO_STORAGE ret = ECHO_STORAGE_ERR;
	FILE* fPListFile = NULL;	
	
	if (Filename)
	{
		fPListFile = fopen(Filename, "r");
		if (fPListFile != NULL)
		{
			fclose(fPListFile);
			ret = ECHO_STORAGE_OK;
		}
	}
	return ret;
}

/*************************************************
  Function:		get_size
  Description: 	����ļ��д�С
  Input:		
  	1.Filename	�ļ�����
  Output:		��
  Return:		SIZE
  Others:
*************************************************/
int get_size (char* srcname)
{
	#if 0
	FILE* fPListFile = NULL;	
	uint32 size = 0;
	
	if (NULL != srcname)
	{
		fPListFile = fopen(srcname, "r");
		if (fPListFile != NULL)
		{
			size = fPListFile->_bufsiz;
			fclose(fPListFile);
		}
	}
	return size;
	#else
	struct stat buf;
	int32 ret;
	
	if (NULL == srcname)
	{
	   	printf(" not find \n");
	   	return 0;
	}

	log_printf("file: %s\n", srcname);
	ret = stat(srcname, &buf);
	log_printf("fie ret: %d\n", ret);
	if (ret == -1)
	{
		return 0;
	}
    log_printf("buf.st_size: %d \n", (int)buf.st_size);
	return buf.st_size;
	#endif
}

/*************************************************
  Function:     	FSFlush
  Description:  	
  Input:       	
  Output:           ��
  Return:
  Others:			�ļ�����д�����
*************************************************/
void FSFlush(FILE* pFile)
{
	fflush(pFile);
	fsync(fileno(pFile));
}

/*************************************************
  Function:     	FSCheckSpareSpace
  Description:  	
  Input:       	
  Output:           
  Return:
  	freeDisk		���ÿռ� ��λB
  Others:			���̿ռ�
  cat /proc/mounts ���Բ鿴�ļ�ϵͳ���м���������
*************************************************/
uint64 FSCheckSpareSpace(const char* dir)
{

	char dirname[32];
	struct statfs diskInfo;

	if(strstr(dir, "nand") != NULL)
		strcpy(dirname, "/nand/");
	else if(strstr(dir, "tmp")!=NULL)
		strcpy(dirname, "/tmp/");

	statfs(dirname, &diskInfo);
	unsigned long long totalsize = diskInfo.f_bsize * diskInfo.f_blocks;		//�ܵ��ֽ�����f_blocksΪblock����Ŀ
	unsigned long long freeDisk = diskInfo.f_bfree * diskInfo.f_bsize;			//ʣ��ռ�Ĵ�С
	printf("total = %llu KB Free =  %llu KB \n", totalsize>>10, freeDisk>>10);
		
	// С��200Kʱ����� fopen fail, ����Ԥ��200K�Ŀռ�
	if(freeDisk > 204800)
		freeDisk -= 204800;
	else
		freeDisk = 0;

	return (uint64)freeDisk;
}

/*************************************************
  Function:    		FSFileDelete
  Description: 		ɾ��ָ�����ļ�
  Input: 
  	1.path			�ļ�·����
  Output:     		��
  Return:
					�ɹ�0:ʧ�ܷ��ش����
					�������  EROFS �ļ�������ֻ���ļ�ϵͳ��
					EFAULT ����pathnameָ�볬���ɴ�ȡ�ڴ�ռ�
					ENAMETOOLONG ����pathname̫��
					ENOMEM �����ڴ治��
					ELOOP ����pathname �й��������������
					EIO I/O ��ȡ����
  others:
*************************************************/
int32 FSFileDelete(char * path)
{	
	DIR * dir;
	struct dirent * ptr;
	char filepath[100];
	int32 ret;
	
	if (NULL == path)
	{
		return FALSE;
	}
	if (IsHaveFile(path) != ECHO_STORAGE_OK)
	{
		return FALSE;
	}
	
	if (path[strlen(path) - 1] == '/')
	{
		dir = opendir(path);
		while ((ptr = readdir(dir)) != NULL)
		{
			if ((strcmp(ptr->d_name,".") != 0) && (strcmp(ptr->d_name,"..") != 0))	
			{
				#if 0
				sprintf(filepath, "%s%s", path, ptr->d_name);
				printf("del_file filepath:%s\n",filepath);
				remove(filepath);
				#else
				memset(filepath, 0, sizeof(filepath));
				sprintf(filepath, "rm -rvf %s%s", path, ptr->d_name);
				system(filepath);
				system("sync");
				#endif
			}						
		}		
		return TRUE;
	}
	else
	{	
		#if 0
		ret = remove(path);
		if (0 != ret)
		{
			return FALSE;
		}
		#else
		memset(filepath, 0, sizeof(filepath));
		sprintf(filepath, "rm -rvf  %s ", path);
		log_printf("filepath: %s\n", filepath);
		system(filepath);
		system("sync");
		#endif
	}
	
	return TRUE;		
}

/*************************************************
  Function:		Fwrite_common
  Description: 	д����
  Input:		
  	1.Filename	��¼����
  	2.Data		�豸����
  	3.DataSize	���ݽṹ��С
  	4.DataNum	���ݸ���
  Output:		��
  Return:		ECHO_VALUE
  Others:
*************************************************/
//#define SMALL_BLOCK_SIZE		64
ECHO_STORAGE Fwrite_common (char * Filename, void * Data, int DataSize, int DataNum)
{	
	FILE* fPListFile = NULL;
	ECHO_STORAGE ret = ECHO_STORAGE_ERR;
	uint32 size = 0;
	uint32 maxsize = DataSize * DataNum;

	if (Filename == NULL || Data == NULL)
	{
		return ECHO_STORAGE_NOFILE;
	}
	
    fPListFile = fopen(Filename, "w+");
	if (maxsize == 0)
	{
		if (fPListFile != NULL )
		{
			fclose(fPListFile);
	   		fPListFile = NULL;
			ret = ECHO_STORAGE_OK;
		}		
		return ret;
	}
	
	if (fPListFile != NULL )
	{
		#if 0
		if (maxsize <= SMALL_BLOCK_SIZE)
		{
			size = fwrite((char *)Data, maxsize, 1, fPListFile);
			if (size == maxsize)
			{
				ret = ECHO_STORAGE_OK;
			}
		}
		else
		{	
			while (maxsize != size)
			{
				size = fwrite((char *)Data, maxsize, 1, fPListFile);
				maxsize -= size;
				size = 0;
			}
			ret = ECHO_STORAGE_OK;
		}
		#else
		size = fwrite((char *)Data, 1, maxsize, fPListFile);
		if (size == maxsize)
		{
			ret = ECHO_STORAGE_OK;
		}
		log_printf("Write Size  %d\n", size);
		FSFlush(fPListFile);
		#endif
		fclose(fPListFile);
	   	fPListFile = NULL;
	}	
	
	return ret;
}

#if 0
/*************************************************
  Function:    		get_filesize
  Description: 		���ָ��·���ļ��Ĵ�С
  Input:                  
  	1.filepath		�ļ�·��
  Output:			��
  Return:			�ɹ�:ָ���ļ��Ĵ�С(��λ�ֽ�)
					���ɹ�:FALSE
  Others:
*************************************************/
int32 get_filesize(int8 *filepath)
{
	struct stat buf;
	int32 ret;
	
	if (NULL == filepath)
	{
	   	printf(" not find \n");
	   	return -1;
	}

	ret = stat(filepath,&buf);
	if (ret == -1)
	{
		return -1;
	}
    printf("buf.st_size: %d \n", (int)buf.st_size);
	return buf.st_size;
}
#endif

/*************************************************
  Function:		Fread_common
  Description: 	������
  Input:		
  	1.Filename	��¼����
  	2.Data		�豸����
  	3.DataSize	���ݽṹ��С
  	4.DataMaxNum ���ݸ���
  Output:		��
  Return:		���ݸ���
  Others:
*************************************************/
uint32 Fread_common (char* Filename, void* Data, int DataSize, int DataMaxNum)
{	
	#if 1
	FILE * fPListFile = NULL;
	int Num = 0;
	int Size = 0;
	
	if (Data == NULL)
	{
		return 0;
	}
	
	memset(Data, 0, DataSize*DataMaxNum);
    fPListFile = fopen(Filename, "r");
	if (fPListFile != NULL)
	{
		Size = get_size(Filename);
		if (Size > 0)
		{
			Num = Size/DataSize;
			if (Num > DataMaxNum)
			{
				Num = DataMaxNum;
			}
		}
	
		if (Num > 0)
		{
			fread(Data, DataSize*Num, 1, fPListFile);
		}
		fclose(fPListFile);
	   	fPListFile = NULL;
	}
	
	log_printf("Fread_common Num:  %d read size: %d DataSize: %d DataMaxNum: %d\n", 
		Num, Size, DataSize, DataMaxNum);
	return Num;
	#else
	int32 ret = 0;
	FILE * fPListFile = NULL;
	
	if (Data == NULL)
	{
		return 0;
	}
	
	memset(Data, 0, DataSize*DataMaxNum);
    fPListFile = fopen(Filename, "r");
	if (fPListFile != NULL)
	{
		ret = fread(Data, 1, DataSize*DataMaxNum, fPListFile);
	}
	log_printf("Fread_common ret:  %d DataSize*DataMaxNum = %d\n", ret, DataSize*DataMaxNum);
	
	return ret;
	#endif
}

/*************************************************
  Function:		storage_set_save_flag
  Description: 	���ô洢��־
  Input:		
  	1.Flag		����
  	2.state		״̬(TURE -- ��ʱ�洢 FALSE -- ����洢)
  Output:		��
  Return:		��
  Others:
*************************************************/
void storage_set_save_flag (FLAG_STORAGE Flag, uint8 state)
{
	if (Flag < FLAG_COUNT)
	{
		ModelFlag[Flag] = state;
	}
}

/*************************************************
  Function:		storage_get_save_flag
  Description: 	��ȡ�洢��־
  Input:		
  	1.Flag		����
  Output:		��
  Return:		״̬
  Others:
*************************************************/
uint8 storage_get_save_flag (FLAG_STORAGE Flag)
{
	if (Flag < FLAG_COUNT)
	{
		return ModelFlag[Flag];
	}
	else
	{
		return FALSE;
	}
}

/*************************************************
  Function:		storage_comm_model_save
  Description: 	������ʱ�洢
  Input:		��
  Output:		��
  Return:		��
  Others:		����ģ��Ķ�ʱ�洢������
*************************************************/
void storage_comm_model_save(void)
{
	// ����ģ�鶨ʱ�洢
	 storage_af_timer_save();

	// ��Ϣģ�鶨ʱ�洢
}

/*********************************************************/
/*						��������						 */	
/*********************************************************/

/*************************************************
  Function:		stroage_get_language
  Description: 	��ȡ����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
LANGUAGE_E storage_get_language(void)
{
	return gpSysParam->Language;
}

/*************************************************
  Function:		stroage_init_language
  Description: 	��ʼ������
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
static void storage_init_language(LANGUAGE_E language)
{
	switch (language)
	{
		case CHNBIG5:
			g_China = 1;
			g_Big5 = 1;
			break;

		case ENGLISH:
			g_China = 0;
			g_Big5 = 0;
			break;

		case CHINESE:
		default:
			g_China = 1;
			g_Big5 = 0;
			break;
	}
}

/*************************************************
  Function:		stroage_set_language
  Description: 	��������
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void storage_set_language(LANGUAGE_E language)
{
	if (language > ENGLISH)
	{
		language = CHINESE;
	}
	log_printf("language: %d\n", language);
	gpSysParam->Language = language;
	storage_init_language(language);
	storage_init_get_dev_desc(gpSysParam->DevDesc, language);
	log_printf("gpSysConfig->SysFlashData.Language %d\n", gpSysConfig->SysFlashData.Language);
	SaveRegInfo();
	
	return;
}

/*************************************************
  Function:		storage_get_openscreen
  Description: 	��ȡ����״̬
  Input:		��
  Output:		��
  Return:		0���� 1����
  Others:
*************************************************/
uint8 storage_get_openscreen(void)
{
	return gpSysParam->OpenScreen;
}

/*************************************************
  Function:		stroage_set_openscreen
  Description: 	���ù���״̬
  Input:		��
  Output:		��
  Return:		0���� 1����
  Others:
*************************************************/
void storage_set_openscreen(uint8 state)
{
	if (gpSysParam->OpenScreen != state)
	{
		gpSysParam->OpenScreen = state;
		SaveRegInfo();
	}
	
	return;
}

/*********************************************************/
/*						�ⲿģ������					 */	
/*********************************************************/

/*************************************************
  Function:		storage_get_extmode
  Description: 	��ȡ�ⲿģ��
  Input:		��
  Output:		��
  Return:		TRUE ���� FALSE ������
  Others:
*************************************************/
uint32 storage_get_extmode(EXT_MODE_TYPE type)
{
	return gpSysParam->Extparam[type];
}

/*************************************************
  Function:		storage_set_extmode
  Description: 	�����ⲿģ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_extmode(uint8 save, EXT_MODE_TYPE type, uint8 state)
{
	gpSysParam->Extparam[type] = state;
	if (save)
	{
		SaveRegInfo();
	}
	return TRUE;	
}

/*********************************************************/
/*						 ��������						 */	
/*********************************************************/

/*************************************************
  Function:		storage_get_bright
  Description: 	��ȡ����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_get_bright(void)
{
	return gpSysParam->Bright;
}

/*************************************************
  Function:		storage_set_bright
  Description: 	���ñ���
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_bright(uint8 save, uint8 Bright)
{
	if (gpSysParam->Bright != Bright)
	{
		gpSysParam->Bright = Bright;
		if (save)
		{
			SaveRegInfo();
		}
	}
	return TRUE;	
}

/*********************************************************/
/*						 ��������						 */	
/*********************************************************/

/*************************************************
  Function:		storage_get_desk
  Description: 	��ȡ����ID
  Input:		��
  Output:		��
  Return:		����ID
  Others:
*************************************************/
uint32 storage_get_desk(void)
{
	return gpSysParam->DeskId;
}

/*************************************************
  Function:		storage_set_desk
  Description: 	��������ID
  Input:		��
  Output:		��
  Return:		��ȷ���
  Others:
*************************************************/
uint32 storage_set_desk(uint8 save, uint8 ID)
{
	if (gpSysParam->DeskId != ID)
	{
		gpSysParam->DeskId = ID;
		if (save)
		{
			SaveRegInfo();
		}
	}
	return TRUE;	
}

/*********************************************************/
/*					 MAC���ַ����						 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_mac
  Description: 	��ȡMAC
  Input:		
  	1.type		MAC����
  Output:		��
  Return:		MAC��
  Others:
*************************************************/
uint8 * storage_get_mac(MAC_TYPE type)
{
	switch (type)
	{
		case HOUSE_MAC:								// ���ڻ�MAC
			return gpSysParam->MacAddr.HouseMac;
			
		case DOOR1_MAC:								// ������ǰ��1MAC
			return gpSysParam->MacAddr.Door1Mac;
			
		case DOOR2_MAC:								// ������ǰ��2MAC
			return gpSysParam->MacAddr.Door2Mac;

		default:
			break;
	}
	return NULL;
}

/*************************************************
  Function:		storage_set_mac
  Description: 	����MAC
  Input:		
  	1.type		MAC����
  	2.data		MAC��
  Output:		��
  Return:		TRUE��FALSE
  Others:
*************************************************/
uint32 storage_set_mac(MAC_TYPE type, char* data)
{
	if (data == NULL)
	{
		return FALSE;
	}

	switch (type)
	{
		case HOUSE_MAC:
			memset(gpSysParam->MacAddr.HouseMac, 0, sizeof(gpSysParam->MacAddr.HouseMac));
			memcpy(gpSysParam->MacAddr.HouseMac, data, sizeof(gpSysParam->MacAddr.HouseMac));
			break;

		case DOOR1_MAC:
			memset(gpSysParam->MacAddr.Door1Mac, 0, sizeof(gpSysParam->MacAddr.Door1Mac));
			memcpy(gpSysParam->MacAddr.Door1Mac, data, sizeof(gpSysParam->MacAddr.Door1Mac));
			break;

		case DOOR2_MAC:
			memset(gpSysParam->MacAddr.Door2Mac, 0, sizeof(gpSysParam->MacAddr.Door2Mac));
			memcpy(gpSysParam->MacAddr.Door2Mac, data, sizeof(gpSysParam->MacAddr.Door2Mac));
			break;

		default:
			return FALSE;
	}

	
	SaveRegInfo();
	return TRUE;
}

/*********************************************************/
/*					 	��������						 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_pass
  Description: 	��ȡ����
  Input:		
  	1.type		��������
  Output:		��
  Return:		����
  Others:
*************************************************/
uint8 * storage_get_pass(PASS_TYPE type)
{
	switch (type)
	{
		case PASS_TYPE_ADMIN:					// ����Ա����
			return gpSysParam->Passparam.admin;
			
		case PASS_TYPE_USER:					// �û�����
			return gpSysParam->Passparam.user;
			
		case PASS_TYPE_DOOR_USER:				// �û���������
			return gpSysParam->Passparam.door_user;
			
		case PASS_TYPE_DOOR_SERVER:				// ������������	
			return gpSysParam->Passparam.door_server;
			
		case PASS_TYPE_SERVER:				    // ��������	
			return gpSysParam->Passparam.user_server;

		default:
			return NULL;
	}
}

/*************************************************
  Function:		storage_get_pass
  Description: 	��ȡ����
  Input:		
  	1.type		��������
  	2.data		����
  Output:		��
  Return:		����
  Others:
*************************************************/
uint32 storage_set_pass(PASS_TYPE type, char* data)
{
	int nlen = 0;
	int maxlen[PASS_TYPE_MAX] ={MAX_ADMIN_LEN,MAX_USER_LEN,MAX_DOOR_USER_LEN,MAX_DOOR_SERVER_LEN, MAX_DOOR_SERVER_LEN};
	
	if (NULL != data)
	{
		nlen = strlen(data);
		if (nlen > maxlen[type])
		{
			nlen = maxlen[type];
		}
		switch (type)
		{
			case PASS_TYPE_ADMIN:					// ����Ա����
				memset(gpSysParam->Passparam.admin,0,sizeof(gpSysParam->Passparam.admin));
				memcpy(gpSysParam->Passparam.admin, data, nlen);
				gpSysParam->Passparam.admin[nlen] = 0;
				break;
				
			case PASS_TYPE_USER:					// �û�����
				memset(gpSysParam->Passparam.user,0,sizeof(gpSysParam->Passparam.user));
				memcpy( gpSysParam->Passparam.user, data, nlen);
				gpSysParam->Passparam.user[nlen] = 0;	
				break;
				
			case PASS_TYPE_DOOR_USER:				// �û���������
				memset(gpSysParam->Passparam.door_user,0,sizeof(gpSysParam->Passparam.door_user));
				memcpy(gpSysParam->Passparam.door_user, data, nlen);
				gpSysParam->Passparam.door_user[nlen] = 0;	
				break;
				
			case PASS_TYPE_DOOR_SERVER:				// ������������	
				memset(gpSysParam->Passparam.door_server,0,sizeof(gpSysParam->Passparam.door_server));
				memcpy(gpSysParam->Passparam.door_server, data, nlen);
				gpSysParam->Passparam.door_server[nlen] = 0;	
				gpSysParam->Passparam.doorserverEnable = 1;
				break;
				
			case PASS_TYPE_SERVER:				    // ��������	
				memset(gpSysParam->Passparam.user_server,0,sizeof(gpSysParam->Passparam.user_server));
				memcpy(gpSysParam->Passparam.user_server, data, nlen);
				gpSysParam->Passparam.user_server[nlen] = 0;	
				gpSysParam->Passparam.userserverenb = 1;
				break;

			default:
				break;
		}
		SaveRegInfo();
		return TRUE;
	}

	return FALSE;
}

/*************************************************
  Function:		storage_get_doorserver
  Description: 	��ȡ��������������Ч
  Input:		��
  Output:		��
  Return:		
  Others:
*************************************************/
uint8 storage_get_doorserver(uint8 pass_type)
{
	if (1 == pass_type)
	{
		return gpSysParam->Passparam.doorserverEnable;
	}
	else
	{
		return gpSysParam->Passparam.userserverenb;
	}
}

/*************************************************
  Function:		storage_set_doorserver
  Description: 	���ü�������������Ч
  Input:		
  	1.enable
  Output:		��
  Return:		
  Others:
*************************************************/
uint32 storage_set_doorserver(uint8 enable, uint8 pass_type)
{
	if (1 == pass_type)
	{
		if (gpSysParam->Passparam.doorserverEnable != enable)
		{
			gpSysParam->Passparam.doorserverEnable = enable;
			SaveRegInfo();
		}
	}
	else
	{
		if (gpSysParam->Passparam.userserverenb!= enable)
		{
			gpSysParam->Passparam.userserverenb = enable;
			SaveRegInfo();
		}
	}
	return TRUE;
}

/*********************************************************/
/*					 	��������						 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_ringvolume
  Description: 	��ȡ������С
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_ringvolume(void)
{
	return gpSysParam->RingVolume;
}

/*************************************************
  Function:		storage_get_talkvolume
  Description: 	��ȡͨ����С
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_talkvolume(void)
{
	return gpSysParam->TalkVolume;
}

/*************************************************
  Function:		storage_get_keykeep
  Description: 	��ȡ������
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_keykeep(void)
{
	return gpSysParam->KeyBeep;
}

/*************************************************
  Function:		storage_set_volume
  Description: 	����������С
  Input:		
  	1.ring
  	2.talk
  	3.key
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_volume(uint8 ring, uint8 talk, uint8 key)
{
	gpSysParam->RingVolume = ring;
	gpSysParam->TalkVolume = talk;
	gpSysParam->KeyBeep = key;

	if (gpSysParam->RingVolume > MAX_RING_VOLUME)
	{
		gpSysParam->RingVolume = MAX_RING_VOLUME;
	}

	if (gpSysParam->TalkVolume > MAX_TALK_VOLUME)
	{
		gpSysParam->TalkVolume = MAX_TALK_VOLUME;
	}
	SaveRegInfo();
	
	return TRUE;
}

/*************************************************
  Function:		storage_get_micvolume
  Description: 	��ȡ��ͷ�����С
  Input:		��
  Output:		��
  Return:		��
  Others:		add by luowf 2011.12.2  ��ͷ����
*************************************************/ 			
uint8 storage_get_micvolume(void)
{
	return gpSysParam->MicVolume;
}

/*************************************************
  Function:		storage_set_micvolume
  Description: 	������ͷ������С
  Input:		��
  Output:		��
  Return:		��
  Others:		add by luowf 2011.12.2  ��ͷ����
*************************************************/
uint8 storage_set_micvolume(uint8 mic)
{
	gpSysParam->MicVolume = mic;
	if (gpSysParam->MicVolume > MAX_MIC_VOLUME)
	{
		gpSysParam->MicVolume = MAX_MIC_VOLUME;
	}
	SaveRegInfo();
	return TRUE;
}

/*********************************************************/
/*					 	���������						 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_noface
  Description: 	�����״̬
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_noface(void)
{
	return gpSysParam->Nofaceparam.noface;
}

/*************************************************
  Function:		storage_set_noface_enable
  Description: 	���������״̬
  Input:		
  	1.enable
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_set_noface_enable(uint8 enable)
{
	gpSysParam->Nofaceparam.noface = enable;
//	SaveRegInfo();
	return TRUE;
}

/*************************************************
  Function:		storage_get_noface_index
  Description: 	�����ʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_noface_index(void)
{
	return gpSysParam->Nofaceparam.time;
}

/*************************************************
  Function:		storage_get_noface_time
  Description: 	�����ʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_get_noface_time(void)
{
	uint32 time = 30;
	switch (gpSysParam->Nofaceparam.time)
	{
		case NOFACE_TIME_30:
			time = 30;
			break;
			
		case NOFACE_TIME_60:
			time = 60;
			break;
			
		case NOFACE_TIME_120:
			time = 120;
			break;
			
		case NOFACE_TIME_180:
			time = 180;
			break;
			
		case NOFACE_TIME_300:
			time = 300;
			break;
			
		case NOFACE_TIME_480:
			time = 480;
			break;

		default:
			break;
	}

	return (time*60);
}

/*************************************************
  Function:		storage_set_noface
  Description: 	���������״̬
  Input:		
  	1.enable
  	2.index
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_noface(uint8 enable, uint8 index)
{
	gpSysParam->Nofaceparam.noface = enable;
	gpSysParam->Nofaceparam.time = index;
	if (gpSysParam->Nofaceparam.time > NOFACE_TIME_480)
	{
		gpSysParam->Nofaceparam.time = NOFACE_TIME_480;
	}
	SaveRegInfo();
	
	return TRUE;
}

/*********************************************************/
/*					 ������ʾ������						 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_ring_id
  Description: 	��ȡ����ID
  Input:		
  	1.index		(�ݿ� ���� �ſ� ���� ס�� �ֻ� ��Ϣ Ԥ��)
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_ring_id(uint8 index)
{
	return gpSysParam->RingID[index];
}

/*************************************************
  Function:		storage_get_ring_id
  Description: 	��ȡ����ID
  Input:		
  	1.index		(�ݿ� ���� �ſ� ���� ס�� �ֻ� ��Ϣ Ԥ��)
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_ring_id(uint8 index, uint8 id)
{
	gpSysParam->RingID[index] = id;
	SaveRegInfo();
	return TRUE;
}

/*************************************************
  Function:		storage_get_ring_by_id
  Description: 	��ȡ����ȫ��·��
  Input:		
  	1.id		
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_ring_by_id(uint8 id)
{
#if 1
	switch(id)
	{
		case 0:
			return CALL_RING1_PATH;

		case 1:
			return CALL_RING2_PATH;	

		case 2:
			return CALL_RING3_PATH;	

		case 3:
			return CALL_RING4_PATH;	

		case 4:
			return CALL_RING5_PATH;	

		case 5:
			return CALL_RING6_PATH;	

		case 6:
			return CALL_RING7_PATH;	

		case 7:
			return CALL_RING8_PATH;		

		default:
			return CALL_RING1_PATH;
	}
#else // ����������ͬһ������
return CALL_RING1_PATH;
#endif
}

/*************************************************
  Function:		storage_get_ring_by_devtype
  Description: 	��ȡ����ȫ��·��
  Input:		
  	1.type		�豸����
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_ring_by_devtype(DEVICE_TYPE_E type)
{
	uint8 index = 0;
	switch(type)
	{
		case DEVICE_TYPE_STAIR:
			index = 0;
			break;

		case DEVICE_TYPE_AREA:
			index = 1;
			break;

		case DEVICE_TYPE_DOOR_PHONE:
		case DEVICE_TYPE_DOOR_NET:
			index = 2;
			break;

		case DEVICE_TYPE_MANAGER:
			index = 3;
			break;

		case DEVICE_TYPE_ROOM:
			index = 4;
			break;

		case DEVICE_TYPE_FENJI_NET:
			index = 5;
			break;

		default:
			break;
	}
	
	return storage_get_ring_by_id(gpSysParam->RingID[index]);
}

/*************************************************
  Function:		storage_get_ring_fenji
  Description: 	��ȡ�ֻ�����ȫ��·��
  Input:		
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_ring_fenji(void)
{
	return storage_get_ring_by_id(gpSysParam->RingID[5]); 
}

/*************************************************
  Function:		storage_get_ring_out
  Description: 	��ȡ������ȫ��·��
  Input:		
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_ring_out(void)
{
	return CALL_RINGOUT_PATH;
}

/*************************************************
  Function:		storage_get_yj_path_byID
  Description: 	��ȡԤ����ȫ��·��
  Input:		
  	1.type		�豸����
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_yj_path_byID(uint8 id)
{
	switch(id)
	{
		case 0:
			return AF_YJ1_PATH;

		case 1:
			return AF_YJ2_PATH;	

		case 2:
			return AF_YJ3_PATH;	

		case 3:
			return AF_YJ4_PATH;	

		default:
			return AF_YJ1_PATH;
	}
}

/*************************************************
  Function:		storage_get_yj_path
  Description: 	��ȡԤ����ȫ��·��
  Input:		
  	1.type		�豸����
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_yj_path(void)
{
	switch(gpSysParam->RingID[7])
	{
		case 0:
			return AF_YJ1_PATH;

		case 1:
			return AF_YJ2_PATH;	

		case 2:
			return AF_YJ3_PATH;	

		case 3:
			return AF_YJ4_PATH;	

		default:
			return AF_YJ1_PATH;
	}
}

/*************************************************
  Function:		storage_get_msg_hit_byID
  Description: 	��ȡ��Ϣ��ʾ��ȫ��·��
  Input:		
  	1.type		�豸����
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_msg_hit_byID(uint8 id)
{
	switch(id)
	{
		case 0:
			return MSG_HIT1_PATH;

		case 1:
			return MSG_HIT2_PATH;	

		case 2:
			return MSG_HIT3_PATH;	

		case 3:
			return MSG_HIT4_PATH;	

		default:
			return MSG_HIT1_PATH;
	}
}

/*************************************************
  Function:		storage_get_msg_hit
  Description: 	��ȡ��Ϣ��ʾ��ȫ��·��
  Input:		
  	1.type		�豸����
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_msg_hit(void)
{
	switch(gpSysParam->RingID[6])
	{
		case 0:
			return MSG_HIT1_PATH;

		case 1:
			return MSG_HIT2_PATH;	

		case 2:
			return MSG_HIT3_PATH;	

		case 3:
			return MSG_HIT4_PATH;	

		default:
			return MSG_HIT1_PATH;
	}
}

/*********************************************************/
/*					 ��Ӱ��������						 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_lyly_param
  Description: 	��ȡLYLYʹ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
PLYLY_PARAM storage_get_lyly_param(void)
{
	return &(gpSysParam->Lylyparam);
}

/*************************************************
  Function:		storage_get_lyly_param
  Description: 	����LYLYʹ��
  Input:		
  	1.param		�ṹ
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_lyly_param(PLYLY_PARAM param)
{
	if (param)
	{
		memcpy(&gpSysParam->Lylyparam,param,sizeof(LYLY_PARAM));
		SaveRegInfo();
		return TRUE;
	}
	return FALSE;
}

/*************************************************
  Function:		storage_get_lyly_mode
  Description: 	��ȡLYLYģʽ
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
LYLY_TYPE storage_get_lyly_mode(void)
{
	return gpSysParam->Lylyparam.Mode;
}

/*************************************************
  Function:		storage_get_lyly_enable
  Description: 	��ȡLYLYʹ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_lyly_enable(void)
{
	return gpSysParam->Lylyparam.Enable;
}

/*************************************************
  Function:		storage_get_lyly_Linkmode
  Description: 	��ȡLYLY����״̬
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_lyly_Linkmode(LYLY_LINK_TYPE type)
{
	return gpSysParam->Lylyparam.Link[type];
}

/*************************************************
  Function:		storage_get_lyly_tip
  Description: 	��ȡLYLY��ʾ��״̬
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_lyly_tip(void)
{
	return gpSysParam->Lylyparam.default_tip;
}

/*************************************************
  Function:		storage_set_lyly_tip
  Description: 	����LYLY��ʾ��״̬
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_set_lyly_tip(uint8 tip)
{
	gpSysParam->Lylyparam.default_tip = tip;
	SaveRegInfo();
	return TRUE;
}

/*************************************************
  Function:		storage_get_lyly_tip_path_bytip
  Description: 	��ȡLYLY��ʾ��·��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_lyly_tip_path_bytip(void)
{
	if(ENGLISH == storage_get_language())
	{
		return LYLY_HIT_EN_PATH;
	}
	else
	{
		return LYLY_HIT_CN_PATH;
	}
}

/*************************************************
  Function:		storage_get_lyly_tip_path
  Description: 	��ȡLYLY��ʾ��·��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
char* storage_get_lyly_tip_path(void)
{
	if (0 == gpSysParam->Lylyparam.default_tip)
	{
		return storage_get_lyly_tip_path_bytip();
	}
	else
	{
		return LYLY_HIT_RE_PATH;
	}
}

/*********************************************************/
/*						��Ļ��������					 */	
/*********************************************************/
/*************************************************
  Function:		storage_get_screenparam
  Description: 	�����Ļ��������
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
PEPHOTO_PARAM storage_get_screenparam(void)
{
	return &(gpSysParam->Ephotoparam);
}

/*************************************************
  Function:		storage_set_screenparam
  Description: 	������Ļ��������
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_set_screenparam(PEPHOTO_PARAM param)
{
	memcpy(&(gpSysParam->Ephotoparam), param, sizeof(EPHOTO_PARAM));
	SaveRegInfo();
	return TRUE;
}

/*************************************************
  Function:		storage_get_screen_enable
  Description: 	��Ļ����ʹ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_get_screen_enable(void)
{
	return gpSysParam->Ephotoparam.used;
}

/*************************************************
  Function:		storage_get_screen_intime
  Description: 	������Ļ����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_get_screen_intime(void)
{
	switch(gpSysParam->Ephotoparam.intime)
	{
		case EPHOTO_TIME_HALF:
			return 30;
			
		case EPHOTO_TIME_1:
			return 60;
			
		case EPHOTO_TIME_3:
			return (60*3);
			
		case EPHOTO_TIME_5:
			return (60*5);
			
		case EPHOTO_TIME_10:
			return (60*10);
			
		case EPHOTO_TIME_30:
			return (60*30);

		case EPHOTO_TIME_60:
		default:
			return (60*60);
	}
}

/*************************************************
  Function:		storage_get_closelcd_time
  Description: 	����Ļʱ��
  Input:		��
  Output:		��
  Return:		��
  Others:		�˺����򻯰�ĺ;��ð�ķ���ֵ��ͬ
*************************************************/
uint32 storage_get_closelcd_time(void)
{
	switch(gpSysParam->Ephotoparam.holdtime)
	{
		case EPHOTO_TIME_HALF:
			return 30;
			
		case EPHOTO_TIME_1:
			return 60;
			
		case EPHOTO_TIME_3:
			return (60*3);
			
		case EPHOTO_TIME_5:
			return 5;
			
		case EPHOTO_TIME_10:
			return 10;

		case EPHOTO_TIME_15:
			return 15;
			
		case EPHOTO_TIME_30:
			return 30;
			
		case EPHOTO_TIME_60:
			return 60;

		case EPHOTO_TIME_120:
			return 120;
			
		default:
			return (60*60);
	}
}

/*************************************************
  Function:		storage_get_regcode
  Description: 	���ƽ̨ע����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint32 storage_get_regcode(void)
{
	return gpSysParam->RegCode;
}

/*************************************************
  Function:		storage_get_regcode
  Description: 	����ƽ̨ע����
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
uint8 storage_set_regcode(uint32 code)
{
	gpSysParam->RegCode = code;
	SaveRegInfo();
	return TRUE;
}

#ifdef _USE_NEW_CENTER_

/*************************************************
  Function:			storage_set_predevno
  Description:		��ȡע��ɹ��豸���
  Input: 	
  Output:			��
  Return:			�ɹ����, TRUE/FALSE
  Others:	
*************************************************/
DEVICE_NO storage_get_predevno(void)
{
	FILE *fp;
	char path[50];
	DEVICE_NO pre_devno;
	
	memset(path, 0, sizeof(path));
	memset(&pre_devno, 0, sizeof(DEVICE_NO));
	memcpy(path, PRE_DEVNO_FILENAME, sizeof(PRE_DEVNO_FILENAME));
	fp = fopen(path, "r+");
	if (fp != NULL)
	{
		fread(&pre_devno, sizeof(DEVICE_NO), 1, fp);
		fclose(fp);
	}
	
	return pre_devno;
}

/*************************************************
  Function:			storage_set_predevno
  Description:		����ע��ɹ��豸���
  Input: 	
  Output:			��
  Return:			�ɹ����, TRUE/FALSE
  Others:	
*************************************************/
int storage_set_predevno(PDEVICE_NO DeviceNo)
{
	FILE *fp;
	char path[50];
	DEVICE_NO pre_devno = {0};
	
	memset(path, 0, sizeof(path));
	memset(&pre_devno, 0, sizeof(DEVICE_NO));
	memcpy(path, PRE_DEVNO_FILENAME, sizeof(PRE_DEVNO_FILENAME));
	fp = fopen(path, "w+");
	if(fp == NULL)
	{
		return FALSE;
	}
	if (DeviceNo != 0)
	{
		memcpy(&pre_devno, DeviceNo, sizeof(DEVICE_NO));
	}
	fwrite(&pre_devno, sizeof(DEVICE_NO), 1, fp);
	FSFlush(fp);
	fclose(fp);
}
#endif

/*************************************************
  Function:    		UlongtoIP
  Description:		��long��IP��ַת��ΪIP��ַ�ַ���
  Input:
  	1.uIp			unsigned long��IP��ַ
  Output:			
  Return:			ת������ַ���ָ��
  Others:			
*************************************************/
static char* UlongtoIP1(uint32 uIp)
{
	static char strIp[20];
	char temp[20];
	int32 i;
	uint32 t;
	
	memset(strIp, 0, 20);
	for (i = 3; i >= 0; i--)
	{
		t = uIp >> (i * 8);
		t = t & 0xFF;
		sprintf(temp, "%d", (uint32)t);
		strcat(strIp, temp);
		if (i != 0)
		{
			strcat(strIp, ".");
		}
	}
	
	return strIp;
}

/*************************************************
Function:   	 	storage_set_ipaddr
Description: 		��ʼ��ip
Input:              ��
Output:				��
Return:				�ɹ���ture ʧ�ܣ�false
Others:
*************************************************/
uint32 storage_set_ipaddr(void)
{
	char buf[255];	
	PNET_PARAM NetParam = &gpSysParam->Netparam;

	system("ifconfig eth0 down");

	// ����MAC��
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "ifconfig eth0 hw ether %02x:%02x:%02x:%02x:%02x:%02x",
		gpSysParam->MacAddr.HouseMac[0], gpSysParam->MacAddr.HouseMac[1],
		gpSysParam->MacAddr.HouseMac[2], gpSysParam->MacAddr.HouseMac[3],
		gpSysParam->MacAddr.HouseMac[4], gpSysParam->MacAddr.HouseMac[5]);
	log_printf("storage_set_ipaddr MAC:%s\n", buf);
	system(buf);

	#ifdef _ETHERNET_DHCP_
	log_printf("Enter Ethernet DHCP.........\n");
	if (storage_get_ethernetdhcp_enable())
	{
		//system("kill -15 $(pidof udhcpc)");	// ϵͳû��pidof����
		system("udhcpc -i eth0 -b");
	}
	else
	#endif
	{
		// ����IP��ַ
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "ifconfig %s %s ", "eth0", UlongtoIP1(NetParam->IP));
		log_printf("storage_set_ipaddr IP:%s\n", buf);
		system(buf);

		// ������������
		memset(buf, 0, sizeof(buf));
		sprintf(buf,"ifconfig %s netmask %s ","eth0", UlongtoIP1(NetParam->SubNet));	
		log_printf("storage_set_ipaddr NETMASK:%s\n", buf);
		system(buf);

		// ��������
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "route add default gw  %s ", UlongtoIP1(NetParam->DefaultGateway));	
		log_printf("storage_set_ipaddr GW:%s\n", buf);	
		system(buf);
	}

	system("ifconfig eth0 up");
	return 0;
}

/*************************************************
Function:   	 	storage_netdoor_set_ipaddr
Description: 		��ʼ��ip
Input:              ��
Output:				��
Return:				�ɹ���ture ʧ�ܣ�false
Others:
*************************************************/
uint32 storage_netdoor_set_ipaddr(uint32 ip, uint32 netmack, uint32 gateway)
{
	char buf[255];	
	PNET_PARAM NetParam = &gpSysParam->Netparam;

	system("ifconfig eth0 down");

	// ����MAC��
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "ifconfig eth0 hw ether %02x:%02x:%02x:%02x:%02x:%02x",
		gpSysParam->MacAddr.HouseMac[0], gpSysParam->MacAddr.HouseMac[1],
		gpSysParam->MacAddr.HouseMac[2], gpSysParam->MacAddr.HouseMac[3],
		gpSysParam->MacAddr.HouseMac[4], gpSysParam->MacAddr.HouseMac[5]);
	log_printf("storage_set_ipaddr MAC:%s\n", buf);
	system(buf);

	// ����IP��ַ
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "ifconfig %s %s ", "eth0", UlongtoIP1(ip));
	log_printf("storage_set_ipaddr IP:%s\n", buf);
	system(buf);

	// ������������
	memset(buf, 0, sizeof(buf));
	sprintf(buf,"ifconfig %s netmask %s ","eth0", UlongtoIP1(netmack));	
	log_printf("storage_set_ipaddr NETMASK:%s\n", buf);
	system(buf);

	// ��������
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "route add default gw  %s ", UlongtoIP1(gateway));	
	log_printf("storage_set_ipaddr GW:%s\n", buf);	
	system(buf);

	system("ifconfig eth0 up");
	return 0;
}

/*************************************************
  Function:		storage_init_video_param
  Description: 	
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void storage_init_video_param(void)
{
	if(FALSE == is_fileexist(VIDEO_PARAM_PATH))
	{	
		// 3��Ƶ���� 4��Ƶ�Աȶ� 5��Ƶ���Ͷ� 6��Ƶɫ�ʶ�
		write_ini(VIDEO_PARAM_PATH, "����˵��", "����", "0 - 63");
		write_ini(VIDEO_PARAM_PATH, "����˵��", "�Աȶ�", "0 - 63");
		write_ini(VIDEO_PARAM_PATH, "����˵��", "���Ͷ�", "0 - 63");
		write_ini(VIDEO_PARAM_PATH, "����˵��", "ɫ�ʶ�", "0 - 100");
		
		write_ini(VIDEO_PARAM_PATH, "��Ƶ����", "����", "32");
		write_ini(VIDEO_PARAM_PATH, "��Ƶ����", "�Աȶ�", "32");
		write_ini(VIDEO_PARAM_PATH, "��Ƶ����", "���Ͷ�", "32");
		write_ini(VIDEO_PARAM_PATH, "��Ƶ����", "ɫ�ʶ�", "50");
	}
}

/*************************************************
  Function:		storage_init
  Description: 	�洢��ʼ��
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
void storage_init(void)
{
	LANGUAGE_E lang;

	// ��ʼ��ϵͳ����
	storage_init_sysconfig();
	
	// ��ʼ������
	lang = storage_get_language();
	storage_init_language(lang);

	// ����IP
	storage_set_ipaddr();

	// ��ʼ���Խ�ģ��洢
	storage_call_init();

	// ��ʼ������ģ��洢
	storage_af_init();

	// ��ʼ���ҵ�ģ��洢
	storage_jd_init();

	#ifdef _YUYUE_MODE_
	// ��ʼ��ԤԼģ��洢
	storage_yuyue_init();
	#endif

	// ��ʼ����Ƶ����
	storage_init_video_param();
}

