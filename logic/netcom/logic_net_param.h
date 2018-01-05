/*************************************************
  Copyright (C), 2006-2010, Aurine
  File name:  	logic_net_param.h
  Author:     	xiewr
  Version:    	1.0
  Date: 
  Description:  ��ȡ����IP��Ϣͷ�ļ�
  
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#ifndef _NET_GET_PARAM_H_
#define _NET_GET_PARAM_H_

#if 0
#include "typedef.h"
#include "net_comm_types.h"
#include "storage_types.h"
#endif
#include "logic_include.h"

/*************************************************
  Function:    		net_set_net_param
  Description:		����ͨѶ�������
  Input: 			
  	1.NetParam		�������ָ��
  Output:			��
  Return:			��
  Others:
*************************************************/
void net_set_net_param(PNET_PARAM NetParam);

/*************************************************
  Function:    		net_set_local_param
  Description:		���ñ����������
  Input: 			
  	1.NetParam		�������ָ��
  Output:			��
  Return:			��
  Others:
*************************************************/
void net_set_local_param(PNET_PARAM NetParam);

/*************************************************
  Function:    		net_set_local_mac
  Description:		����MAC
  Input: 			
  	1.mac			MAC
  Output:			��
  Return:			��
  Others:			TRUE / FALSE
*************************************************/
uint32 net_set_local_mac(uint8 *mac);

/*************************************************
  Function:    		net_get_local_ipaddress
  Description:		���IP��ַ
  Input: 			��
  Output:			��
  Return:			�ɹ����, TRUE/FALSE
  Others:
*************************************************/
uint32 net_get_local_ipaddress(void);

/*************************************************
  Function:    		net_get_netmask_address
  Description:		��������ַ
  Input: 			��
  Output:			��
  Return:			�����ַ
  Others:
*************************************************/
uint32 net_get_netmask_address(void);

/*************************************************
  Function:    		net_get_local_mac
  Description:		�������Ӳ����ַ
  Input: 
  Output:			��
	1.HWaddr		��õ�Ӳ����ַ
  Return:			�ɹ����, TRUE/FALSE
  Others:
*************************************************/
int32 net_get_local_mac(unsigned char *HWaddr);

/*************************************************
  Function:    		net_get_net_status
  Description:		���ָ�������豸����������״̬
  Input: 
	1.ifname		�豸����, ifname=null��ȡeth0״̬
  Output:			��
  Return:			0�����ӳɹ� 1�����ӶϿ� 2��δ֪
  Others:
*************************************************/
int net_get_net_status(char * ifname);

/*************************************************
  Function:    		net_get_center_ip
  Description:		������ķ�����IP
  Input: 			��
  Output:			��
  Return:			���ķ�����IP��ַ
  Others:
*************************************************/
uint32 net_get_center_ip(void);

/*************************************************
  Function:    		net_get_manager1_ip
  Description:		��ù���Ա��IP
  Input: 			
  	1.NO			����Ա����� 1-3
  Output:			��
  Return:			��Ա��IP
  Others:
*************************************************/
uint32 net_get_manager_ip(uint8 NO);

/*************************************************
  Function:    		net_get_aurine_ip
  Description:		��ù��ַ�����IP
  Input: 			��
  Output:			��
  Return:			����IP
  Others:
*************************************************/
uint32 net_get_aurine_ip(void);

/*************************************************
  Function:    		net_get_aurine_stun_ip
  Description:		��ù���StunIP
  Input: 			��
  Output:			��
  Return:			����Stun������IP
  Others:
*************************************************/
uint32 net_get_aurine_stun_ip(void);

/*************************************************
  Function:    		net_get_sip_proxy_ip
  Description:		���sip���������IP
  Input: 			��
  Output:			��
  Return:			sip���������IP
  Others:
*************************************************/
uint32 net_get_sip_proxy_ip(void);

/*************************************************
  Function:    		IPtoUlong
  Description:		��IP��ַ�ַ���ת��Ϊlong��IP��ַ
  Input:
  	1.ip			IP��ַ�ַ���
  Output:			
  Return:			ת�����unsigned long��IP��ַ
  Others:			
*************************************************/
uint32 IPtoUlong(char* ip);

#endif

