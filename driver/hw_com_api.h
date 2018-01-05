/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	hw_com_api.c
  Author:    	luofl
  Version:   	2.0
  Date: 		2014-09-30
  Description:  ������������
  				����1---���ڵ��Ժ��뵥Ƭ��ͨ�Ź���
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/
#ifndef __HW_COMM_API_H__
#define __HW_COMM_API_H__

//#include "au_types.h"
#define COM1_BOUND				9600				// ����1������9600bps
#define COM2_BOUND				9600				// ����2������9600bps

typedef	void (* AlarmCallBack)(uint8 PortStatus);
typedef	void (* JdCallBack)(uint8 * buf);;

// ���ڽṹ
typedef struct
{
	char	prompt;									// prompt after reciving data
	int32 	baudrate;								// baudrate
	char	databit;								// data bits, 5, 6, 7, 8
	char 	debug;									// debug mode, 0: none, 1: debug
	char 	echo;									// echo mode, 0: none, 1: echo
	char	fctl;									// flow control, 0: none, 1: hardware, 2: software
	char 	tty;									// tty: 0, 1, 2, 3, 4, 5, 6, 7
	char	parity;									// parity 0: none, 1: odd, 2: even
	char	stopbit;								// stop bits, 1, 2
	const 	int32 reserved;							// reserved, must be zero
}PORTINFO_T, * PPORTINFO_T;

/*************************************************
  Function:		port1_init
  Description: 	�˿�1��ʼ��
  Input:		�� 
  Output:		��
  Return:		-1:ʧ�� 0:�ɹ�
  Others:
*************************************************/
extern int32 port1_init(void);

/*************************************************
  Function:		port1_send
  Description: 	����1����
  Input: 
	1.data		����������
	2.datalen	���ݳ���
  Output:		��
  Return:		-1: ʧ�� �ɹ�: ʵ�ʷ��ͳ���
  Others:
*************************************************/
extern int32 port1_send(char * data, int32 datalen);

/*************************************************
  Function:		port1_recv
  Description: 	����1����
  Input: 
	1.datalen:	��������ݳ���
	2.baudrate:	������
  Output:
	1.data		���յ�������
  Return:		-1: ʧ�� �ɹ�: ʵ�ʽ��ճ���
  Others:
*************************************************/
extern int32 port1_recv(char * data, int32 datalen);

/*************************************************
  Function:		port1_close
  Description: 	�رն˿�1
  Input:		��
  Output:		��
  Return:		��
  Others:
*************************************************/
extern void port1_close(void);

/*************************************************
  Function:		hw_start_monitor_dog
  Description: 	�������ӿ��Ź�
  Input: 		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
extern void hw_start_monitor_dog(void);

/*************************************************
  Function:		hw_stop_monitor_dog
  Description: 	ֹͣ���ӿ��Ź�
  Input: 		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
extern void hw_stop_monitor_dog(void);

/*************************************************
  Function:		hw_clr_monitor_dog
  Description: 	������ӿ��Ź�����
  Input: 		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
extern void hw_clr_monitor_dog(void);

/*************************************************
  Function:		hw_monitor_dog
  Description: 	���ӿ��Ź�,�ڹ̶�ʱ����û�������־
  				��ǿ������
  Input: 		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
extern void hw_monitor_dog(void);

/*************************************************
  Function:		hw_start_com_dog
  Description: 	��������ι��
  Input: 		��
  Output:		��
  Return:		��
  Others:		
*************************************************/
extern void hw_start_com_dog(void);

/*************************************************
  Function:    		hw_stop_feet_dog
  Description:		ֹͣι��
  Input: 			��
  Output:			��
  Return:			��
  Others:
*************************************************/
extern void hw_stop_feet_dog(void);

/*************************************************
  Function:		init_alarm_callback
  Description:	��ʼ�������ص�����
  Input: 
	1.func		�����ص�����ָ��
  Output:
  Return:		�ɹ� = 0������ֵʧ��
  Others:		����8�������˿�״̬�ص�,
  	�����˿�״̬�б仯ʱ,��Ƭ�����ϱ�
*************************************************/
extern int32 init_alarm_callback(AlarmCallBack func);

/*************************************************
  Function:		send_485_pack
  Description: 	����һ֡���ݵ�485
  Input: 
	1.			����������
	2.			���ݳ���
  Output:		��
  Return:		ʵ�ʷ��ͳ���
  Others:
*************************************************/
extern int8 send_485_pack(char * data, uint8 len);

/*************************************************
  Function:		jd_callback_init
  Description:	��ʼ���ҵ�ص�����
  Input: 
	1.func		�ҵ�ص�����ָ��
  Output:
  Return:		�ɹ� = 0������ֵʧ��
  Others:		
*************************************************/
extern int32 jd_callback_init(JdCallBack func);

#ifdef _TIMER_REBOOT_NO_LCD_
/*************************************************
  Function:     hw_set_lcd_pwm0
  Description:  ���õ�Ƭ���ӹ����������
  Input:       	
  	1.flag: 	TRUE: ���� FALSE: ����				
  Output:       ��
  Return:       ��
  Others:
*************************************************/
void hw_set_lcd_pwm0(uint8 flag);
#endif
#endif

