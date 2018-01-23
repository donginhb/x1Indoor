/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name:  	au_language.h
  Author:     	luofl
  Version:    	2.0
  Date: 		2014-08-30
  Description:  
				GUI���Դ������ͷ�ļ�
  History:        
    1. Date:	
       Author:	
       Modification:
*************************************************/
#ifndef __AU_LANGUAGE_H__
#define __AU_LANGUAGE_H__

#ifdef __cplusplus
extern "C" {
#endif

//���Լ��õ����ַ����Ƶ���������
//�����������û����Ӧ���ַ���������������������ĩβ����ʽ���!

// ����������
#define	ESID_NULL						 (g_China ? (g_Big5 ? "���ַ� " : "���ַ� ") : "NULL")
#define	ESID_MainAlarm					 (g_China ? (g_Big5 ? "����" : "����") : "Security")
#define	ESID_MainCall					 (g_China ? (g_Big5 ? "�Խ�" : "�Խ�") : "Intercom")
#define ESID_MainInfo				     (g_China ? (g_Big5 ? "ѶϢ" : "��Ϣ") : "Information")
#define ESID_MainCenter                  (g_China ? (g_Big5 ? "��������" : "��������") : "CALL ADMIN")
#define ESID_MainMonitor			     (g_China ? (g_Big5 ? "����" : "����") : "Monitor")
#define ESID_MainRecord			         (g_China ? (g_Big5 ? "ͨ����¼" : "ͨ����¼") : "Calls Register")
#define ESID_MainLyLy		             (g_China ? (g_Big5 ? "��Ӱ����" : "��Ӱ����") : "MSG")
#define ESID_MainBianli					 (g_China ? (g_Big5 ? "��������" : "��������") : "Facility")
#define ESID_MainBianLi_Dianti           (g_China ? (g_Big5 ? "�����ٻ�" : "�����ٻ�") : "Elevator")
#define ESID_MainSet					 (g_China ? (g_Big5 ? "����" : "����") : "Settings")
#define ESID_MainEcontrol				 (g_China ? (g_Big5 ? "�ҵ����" : "�ҵ����") : "Automation")
#define ESID_MainMedia				     (g_China ? (g_Big5 ? "��ý��" : "��ý��") : "Media")

// ��������
#define ESID_Unregistered           	 (g_China ? (g_Big5 ? "δע��" : "δע��") : "Unregistered")
#define ESID_Registered           		 (g_China ? (g_Big5 ? "��ע��" : "��ע��") : "Registered")
#define ESID_Touch_Calibration           (g_China ? (g_Big5 ? "����ӫĻУ׼!" : "������У׼!") : "Screen Calibration")
#define ESID_Touch_Disp_Chk_Hit          (g_China ? (g_Big5 ? "�밴ס'+'����ֱ��'+'������һ��λ��" : "�밴ס'+'����ֱ��'+'������һ��λ��") : "Press and hold '+' until the '+' skip to the next")
#define ESID_clearscreenhit              (g_China ? (g_Big5 ? "��������������Ʒ����ӫĻ,ʣ��ʱ��:" : "��������������Ʒ������Ļ,ʣ��ʱ��:") : "Pls clean the screen. remaining time:")
#define ESID_Right_Add                   (g_China ? (g_Big5 ? "���" : "���") : "Add")
#define ESID_Right_Edit                  (g_China ? (g_Big5 ? "�༭" : "�༭") : "Edit")
#define ESID_Right_Del                   (g_China ? (g_Big5 ? "ɾ��" : "ɾ��") : "Delete")
#define ESID_Right_Clear                 (g_China ? (g_Big5 ? "���" : "���") : "Empty")
#define ESID_Right_Save                  (g_China ? (g_Big5 ? "����" : "����") : "Save")
#define ESID_Right_View                  (g_China ? (g_Big5 ? "�鿴" : "�鿴") : "View")
#define ESID_Right_Sure                  (g_China ? (g_Big5 ? "ȷ��" : "ȷ��") : "OK")
#define ESID_Right_desk                  (g_China ? (g_Big5 ? "��������" : "��������") : "Set")
#define ESID_Right_Rec                   (g_China ? (g_Big5 ? "¼��" : "¼��") : "Record")
#define ESID_Right_Listen                (g_China ? (g_Big5 ? "����" : "����") : "Audition")
#define ESID_Right_Play                  (g_China ? (g_Big5 ? "����" : "����") : "Play")
#define ESID_Right_Stop                  (g_China ? (g_Big5 ? "ֹͣ" : "ֹͣ") : "Stop")
#define ESID_Right_Pause                 (g_China ? (g_Big5 ? "��ͣ" : "��ͣ") : "Pause")
#define ESID_Right_Updata                (g_China ? (g_Big5 ? "ͬ��" : "ͬ��") : "Synchronize")
#define ESID_Right_Select                (g_China ? (g_Big5 ? "ѡ��" : "ѡ��") : "Select")
#define ESID_Right_Input                 (g_China ? (g_Big5 ? "����" : "����") : "Input")
#define ESID_Week_Sun                    (g_China ? (g_Big5 ? "������" : "������") : "Sun.")
#define ESID_Week_Mon                    (g_China ? (g_Big5 ? "����һ" : "����һ") : "Mon.")
#define ESID_Week_Tue                    (g_China ? (g_Big5 ? "���ڶ�" : "���ڶ�") : "Tues.")
#define ESID_Week_Wed                    (g_China ? (g_Big5 ? "������" : "������") : "Wed.")
#define ESID_Week_Thu                    (g_China ? (g_Big5 ? "������" : "������") : "Thur.")
#define ESID_Week_Fri                    (g_China ? (g_Big5 ? "������" : "������") : "Fri.")
#define ESID_Week_Sat                    (g_China ? (g_Big5 ? "������" : "������") : "Sat.")
#define ESID_Time_Sec                    (g_China ? (g_Big5 ? "��" : "��") : "Sec")
#define ESID_Time_Hour                   (g_China ? (g_Big5 ? "Сʱ" : "Сʱ") : "Hour")
#define ESID_Time_Min                    (g_China ? (g_Big5 ? "��" : "��") : "Min")
#define ESID_Time_Never					 (g_China ? (g_Big5 ? "�Ӳ�" : "�Ӳ�") : "Never")
#define ESID_Set_Time                    (g_China ? (g_Big5 ? "ʱ��:" : "ʱ��:") : "Duration")
#define ESID_Set_Mode                    (g_China ? (g_Big5 ? "ģʽ:" : "ģʽ:") : "Mode")
#define ESID_Set_Used                    (g_China ? (g_Big5 ? "����" : "����") : "Activate")
#define ESID_Save_OK                     (g_China ? (g_Big5 ? "�� �� �� ��!" : "�� �� �� ��!") : "OK!")
#define ESID_Save_ERR                    (g_China ? (g_Big5 ? "�� �� ʧ ��!" : "�� �� ʧ ��!") : "Failed!")
#define ESID_Msg_Yes                     (g_China ? (g_Big5 ? "��" : "��") : "Yes")
#define ESID_Msg_No                      (g_China ? (g_Big5 ? "��" : "��") : "No")
#define ESID_Msg_Format                  (g_China ? (g_Big5 ? "��ȷ���Ƿ��ʽ��?" : "��ȷ���Ƿ��ʽ��?") : "Sure to format disk?")
#define ESID_Oper_OK                     (g_China ? (g_Big5 ? "�� �� �� ��!" : "�� �� �� ��!") : "OK!")
#define ESID_Oper_ERR                    (g_China ? (g_Big5 ? "�� �� ʧ ��!" : "�� �� ʧ ��!") : "Failed!")
#define ESID_Msg_Calibration             (g_China ? (g_Big5 ? "�Ƿ���д���ӫĻУ׼?" : "�Ƿ���д�����У׼?") : "Are you sure to calibrate the screen?")
#define ESID_Msg_OldPass_Err             (g_China ? (g_Big5 ? "���������!" : "���������!") : "Wrong old PIN!")
#define ESID_Msg_SamePass_Err            (g_China ? (g_Big5 ? "������������벻��ͬ!" : "������������벻��ͬ!") : "Pls re-enter the same new PIN!")
#define ESID_Msg_InputBox_Psw_Err        (g_China ? (g_Big5 ? "�������,����������!" : "�������,����������!") : "Wrong Password!")
#define ESID_Msg_Jrly_rec_tmp            (g_China ? (g_Big5 ? "�Ƿ�ɾ����¼�Ƶ��ļ�?" : "�Ƿ�ɾ����¼�Ƶ��ļ�?") : "Sure to delete it?")
#define ESID_Msg_Jrly_rec_full           (g_China ? (g_Big5 ? "�������Կռ�����!" : "�������Կռ�����!") : "Memory Full!")
#define ESID_Msg_Connect_Outtime         (g_China ? (g_Big5 ? "���ӳ�ʱ" : "���ӳ�ʱ") : "Connection timeout!")
#define ESID_Msg_Alarm_Hit               (g_China ? (g_Big5 ? "��ע��,��ʱ��������!" : "��ע��,��ʱ��������!") : "Warning! alarm triggered!")
#define ESID_Msg_Info_Hit                (g_China ? (g_Big5 ? "����,���µ�ѶϢ!" : "����,���µ���Ϣ!") : "Hi,you have new message!")
#define ESID_Msg_CallIn_Hit              (g_China ? (g_Big5 ? "����,���µ�����!" : "����,���µ�����!") : "Hi,you have new call now!")
#define ESID_Msg_FactoryMode             (g_China ? (g_Big5 ? "�Ƿ�Ҫ�ָ���������?" : "�Ƿ�Ҫ�ָ���������?") : "Sure to restore factory settings?")
#define ESID_Msg_Cell_Err                (g_China ? (g_Big5 ? "��Ԫ���ȷǷ�" : "��Ԫ���ȷǷ�") : "Illegal Riser No.!")
#define ESID_Msg_Stair_Err               (g_China ? (g_Big5 ? "�ݺų��ȷǷ�" : "�ݺų��ȷǷ�") : "Illegal Stairway No.!")
#define ESID_Msg_Room_Err                (g_China ? (g_Big5 ? "���ų��ȷǷ�" : "���ų��ȷǷ�") : "Illegal Apartment No.!")
#define ESID_Msg_RuleAll_Err             (g_China ? (g_Big5 ? "�ܳ��Ȳ��ܴ���18" : "�ܳ��Ȳ��ܴ���18") : "Length should be less than 18")
#define ESID_Msg_Len_Err                 (g_China ? (g_Big5 ? "�豸��ų��ȷǷ�" : "�豸��ų��ȷǷ�") : "Illegal Length!")
#define ESID_Msg_RoomNo_Err              (g_China ? (g_Big5 ? "���Ŷ�ȫΪ0" : "���Ŷ�ȫΪ0") : "Room No. can not be all zero!")
#define ESID_Msg_Recover_OK              (g_China ? (g_Big5 ? "�����ɹ�,ϵͳ������!" : "�����ɹ�,ϵͳ������!") : "OK! The system will restart!")
#define ESID_Msg_Exit                    (g_China ? (g_Big5 ? "�˳� " : "�˳� ") : "Exit")
#define ESID_Msg_Dianti_Hit1             (g_China ? (g_Big5 ? "�����ǹ�����ʩ,Ϊ�˴���ܸ��õ�ʹ����," : "�����ǹ�����ʩ,Ϊ�˴���ܸ��õ�ʹ����,") : "In order to make better use of elevator")
#define ESID_Msg_Dianti_Hit2             (g_China ? (g_Big5 ? "������Ҫ�����ٻ�!" : "������Ҫ�����ٻ�!") : "Please do not arbitrarily call it!")
#define ESID_Msg_Reset                   (g_China ? (g_Big5 ? "ϵͳ������..." : "ϵͳ������...") : "System Reset...")
#define ESID_Msg_JD_Is_Updata            (g_China ? (g_Big5 ? "ͬ���󽫸���ԭѶϢ,�Ƿ�ͬ��?" : "ͬ���󽫸���ԭ��Ϣ,�Ƿ�ͬ��?") : "All data will be renewed.")
#define ESID_Msg_JD_Is_Updata1           (g_China ? (g_Big5 ? "ͬ���󽫸���ԭѶϢ,�Ƿ�ͬ��?" : "ͬ���󽫸���ԭ��Ϣ,�Ƿ�ͬ��?") : " Sure to synchronize? ")
#define ESID_Msg_JD_Updataing            (g_China ? (g_Big5 ? "ͬ���ҵ�ѶϢ��,���Ժ�..." : "ͬ���ҵ���Ϣ��,���Ժ�...") : "Settings data synchronizing...")
#define ESID_Msg_JD_Unbind               (g_China ? (g_Big5 ? "IPЭ��ת����δ��,����ͬ��!" : "IPЭ��ת����δ��,����ͬ��!") : "Cannot synchronize!")
#define ESID_Msg_Create_BindCode         (g_China ? (g_Big5 ? "��ȷ��Ҫ�����µİ�����?" : "��ȷ��Ҫ�����µİ�����?") : "Sure to generate new binding code")
#define ESID_IP_Unbind                   (g_China ? (g_Big5 ? "IPЭ��ת����δ��" : "IPЭ��ת����δ��") : "Not bound to IP converter yet.")
#define ESID_IP_Bind                     (g_China ? (g_Big5 ? "IPЭ��ת�����󶨳ɹ�!" : "IPЭ��ת�����󶨳ɹ�!") : "Bound to IP converter.")
#define ESID_Msg_Jd_State_Updata         (g_China ? (g_Big5 ? "�ҵ��豸״̬ͬ����,���Ժ�..." : "�ҵ��豸״̬ͬ����,���Ժ�...") : "Device status synchronizing...")
#define ESID_IP_Online                   (g_China ? (g_Big5 ? "IPЭ��ת��������" : "IPЭ��ת��������") : "IP Converter Online.")
#define ESID_IP_Unline                   (g_China ? (g_Big5 ? "IPЭ��ת����δ����" : "IPЭ��ת����δ����") : "IP Converter Offline.")
#define ESID_IP_Con_Addr                 (g_China ? (g_Big5 ? "IPЭ��ת������ַ" : "IPЭ��ת������ַ") : "IP Converter Address")
#define ESID_Jd_Deng1                    (g_China ? (g_Big5 ? "��1" : "��1") : "Light1")
#define ESID_Jd_Deng2                    (g_China ? (g_Big5 ? "��2" : "��2") : "Light2")
#define ESID_Jd_Deng3                    (g_China ? (g_Big5 ? "��3" : "��3") : "Light3")
#define ESID_Jd_Deng4                    (g_China ? (g_Big5 ? "��4" : "��4") : "Light4")
#define ESID_Jd_Deng5                    (g_China ? (g_Big5 ? "��5" : "��5") : "Light5")
#define ESID_Jd_Deng6                    (g_China ? (g_Big5 ? "��6" : "��6") : "Light6")
#define ESID_Jd_Deng7                    (g_China ? (g_Big5 ? "��7" : "��7") : "Light7")
#define ESID_Jd_Deng8                    (g_China ? (g_Big5 ? "��8" : "��8") : "Light8")
#define ESID_Jd_Deng9                    (g_China ? (g_Big5 ? "��9" : "��9") : "Light9")
#define ESID_Jd_Deng10                   (g_China ? (g_Big5 ? "��10" : "��10") : "Light10")
#define ESID_Jd_TiaoGuangDeng1           (g_China ? (g_Big5 ? "�����1" : "�����1") : "Dimming Lights1")
#define ESID_Jd_TiaoGuangDeng2           (g_China ? (g_Big5 ? "�����2" : "�����2") : "Dimming Lights2")
#define ESID_Jd_TiaoGuangDeng3           (g_China ? (g_Big5 ? "�����3" : "�����3") : "Dimming Lights3")
#define ESID_Jd_TiaoGuangDeng4           (g_China ? (g_Big5 ? "�����4" : "�����4") : "Dimming Lights4")
#define ESID_Jd_TiaoGuangDeng5           (g_China ? (g_Big5 ? "�����5" : "�����5") : "Dimming Lights5")
#define ESID_Jd_TiaoGuangDeng6           (g_China ? (g_Big5 ? "�����6" : "�����6") : "Dimming Lights6")
#define ESID_Jd_TiaoGuangDeng7           (g_China ? (g_Big5 ? "�����7" : "�����7") : "Dimming Lights7")
#define ESID_Jd_TiaoGuangDeng8           (g_China ? (g_Big5 ? "�����8" : "�����8") : "Dimming Lights8")
#define ESID_Jd_TiaoGuangDeng9           (g_China ? (g_Big5 ? "�����9" : "�����9") : "Dimming Lights9")
#define ESID_Jd_TiaoGuangDeng10          (g_China ? (g_Big5 ? "�����10" : "�����10") : "Dimming Lights10")
#define ESID_Jd_BaiChiDeng1              (g_China ? (g_Big5 ? "�׳��1" : "�׳��1") : "Incandescent Lamp1")
#define ESID_Jd_BaiChiDeng2              (g_China ? (g_Big5 ? "�׳��2" : "�׳��2") : "Incandescent Lamp2")
#define ESID_Jd_BaiChiDeng3              (g_China ? (g_Big5 ? "�׳��3" : "�׳��3") : "Incandescent Lamp3")
#define ESID_Jd_BaiChiDeng4              (g_China ? (g_Big5 ? "�׳��4" : "�׳��4") : "Incandescent Lamp4")
#define ESID_Jd_BaiChiDeng5              (g_China ? (g_Big5 ? "�׳��5" : "�׳��5") : "Incandescent Lamp5")
#define ESID_Jd_BaiChiDeng6              (g_China ? (g_Big5 ? "�׳��6" : "�׳��6") : "Incandescent Lamp6")
#define ESID_Jd_BaiChiDeng7              (g_China ? (g_Big5 ? "�׳��7" : "�׳��7") : "Incandescent Lamp7")
#define ESID_Jd_BaiChiDeng8              (g_China ? (g_Big5 ? "�׳��8" : "�׳��8") : "Incandescent Lamp8")
#define ESID_Jd_BaiChiDeng9              (g_China ? (g_Big5 ? "�׳��9" : "�׳��9") : "Incandescent Lamp9")
#define ESID_Jd_BaiChiDeng10             (g_China ? (g_Big5 ? "�׳��10" : "�׳��10") : "Incandescent Lamp10")
#define ESID_Jd_GuangGuan1               (g_China ? (g_Big5 ? "���1" : "���1") : "Lightpipe1")
#define ESID_Jd_GuangGuan2               (g_China ? (g_Big5 ? "���2" : "���2") : "Lightpipe2")
#define ESID_Jd_GuangGuan3               (g_China ? (g_Big5 ? "���3" : "���3") : "Lightpipe3")
#define ESID_Jd_GuangGuan4               (g_China ? (g_Big5 ? "���4" : "���4") : "Lightpipe4")
#define ESID_Jd_GuangGuan5               (g_China ? (g_Big5 ? "���5" : "���5") : "Lightpipe5")
#define ESID_Jd_GuangGuan6               (g_China ? (g_Big5 ? "���6" : "���6") : "Lightpipe6")
#define ESID_Jd_GuangGuan7               (g_China ? (g_Big5 ? "���7" : "���7") : "Lightpipe7")
#define ESID_Jd_GuangGuan8               (g_China ? (g_Big5 ? "���8" : "���8") : "Lightpipe8")
#define ESID_Jd_GuangGuan9               (g_China ? (g_Big5 ? "���9" : "���9") : "Lightpipe9")
#define ESID_Jd_GuangGuan10              (g_China ? (g_Big5 ? "���10" : "���10") : "Lightpipe10")
#define ESID_Jd_DiaoDeng1                (g_China ? (g_Big5 ? "����1" : "����1") : "Chandelier1")
#define ESID_Jd_DiaoDeng2                (g_China ? (g_Big5 ? "����2" : "����2") : "Chandelier2")
#define ESID_Jd_DiaoDeng3                (g_China ? (g_Big5 ? "����3" : "����3") : "Chandelier3")
#define ESID_Jd_DiaoDeng4                (g_China ? (g_Big5 ? "����4" : "����4") : "Chandelier4")
#define ESID_Jd_DiaoDeng5                (g_China ? (g_Big5 ? "����5" : "����5") : "Chandelier5")
#define ESID_Jd_DiaoDeng6                (g_China ? (g_Big5 ? "����6" : "����6") : "Chandelier6")
#define ESID_Jd_DiaoDeng7                (g_China ? (g_Big5 ? "����7" : "����7") : "Chandelier7")
#define ESID_Jd_DiaoDeng8                (g_China ? (g_Big5 ? "����8" : "����8") : "Chandelier8")
#define ESID_Jd_DiaoDeng9                (g_China ? (g_Big5 ? "����9" : "����9") : "Chandelier9")
#define ESID_Jd_DiaoDeng10               (g_China ? (g_Big5 ? "����10" : "����10") : "Chandelier10")
#define ESID_Jd_HuaDeng1                 (g_China ? (g_Big5 ? "����1" : "����1") : "Lantern1")
#define ESID_Jd_HuaDeng2                 (g_China ? (g_Big5 ? "����2" : "����2") : "Lantern2")
#define ESID_Jd_HuaDeng3                 (g_China ? (g_Big5 ? "����3" : "����3") : "Lantern3")
#define	ESID_Jd_HuaDeng4                 (g_China ? (g_Big5 ? "����4" : "����4") : "Lantern4")
#define ESID_Jd_HuaDeng5                 (g_China ? (g_Big5 ? "����5" : "����5") : "Lantern5")
#define ESID_Jd_HuaDeng6                 (g_China ? (g_Big5 ? "����6" : "����6") : "Lantern6")
#define ESID_Jd_HuaDeng7                 (g_China ? (g_Big5 ? "����7" : "����7") : "Lantern7")
#define ESID_Jd_HuaDeng8                 (g_China ? (g_Big5 ? "����8" : "����8") : "Lantern8")
#define ESID_Jd_HuaDeng9                 (g_China ? (g_Big5 ? "����9" : "����9") : "Lantern9")
#define ESID_Jd_HuaDeng10                (g_China ? (g_Big5 ? "����10" : "����10") : "Lantern10")
#define ESID_Jd_BiDeng1                  (g_China ? (g_Big5 ? "�ڵ�1" : "�ڵ�1") : "Wall Lamp1")
#define ESID_Jd_BiDeng2                  (g_China ? (g_Big5 ? "�ڵ�2" : "�ڵ�2") : "Wall Lamp2")
#define ESID_Jd_BiDeng3                  (g_China ? (g_Big5 ? "�ڵ�3" : "�ڵ�3") : "Wall Lamp3")
#define ESID_Jd_BiDeng4                  (g_China ? (g_Big5 ? "�ڵ�4" : "�ڵ�4") : "Wall Lamp4")
#define ESID_Jd_BiDeng5                  (g_China ? (g_Big5 ? "�ڵ�5" : "�ڵ�5") : "Wall Lamp5")
#define ESID_Jd_BiDeng6                  (g_China ? (g_Big5 ? "�ڵ�6" : "�ڵ�6") : "Wall Lamp6")
#define ESID_Jd_BiDeng7                  (g_China ? (g_Big5 ? "�ڵ�7" : "�ڵ�7") : "Wall Lamp7")
#define ESID_Jd_BiDeng8                  (g_China ? (g_Big5 ? "�ڵ�8" : "�ڵ�8") : "Wall Lamp8")
#define ESID_Jd_BiDeng9                  (g_China ? (g_Big5 ? "�ڵ�9" : "�ڵ�9") : "Wall Lamp9")
#define ESID_Jd_BiDeng10                 (g_China ? (g_Big5 ? "�ڵ�10" : "�ڵ�10") : "Wall Lamp10")
#define ESID_Jd_SheDeng1                 (g_China ? (g_Big5 ? "���1" : "���1") : "Spotlight1")
#define ESID_Jd_SheDeng2                 (g_China ? (g_Big5 ? "���2" : "���2") : "Spotlight2")
#define ESID_Jd_SheDeng3                 (g_China ? (g_Big5 ? "���3" : "���3") : "Spotlight3")
#define ESID_Jd_SheDeng4                 (g_China ? (g_Big5 ? "���4" : "���4") : "Spotlight4")
#define ESID_Jd_SheDeng5                 (g_China ? (g_Big5 ? "���5" : "���5") : "Spotlight5")
#define ESID_Jd_SheDeng6                 (g_China ? (g_Big5 ? "���6" : "���6") : "Spotlight6")
#define ESID_Jd_SheDeng7                 (g_China ? (g_Big5 ? "���7" : "���7") : "Spotlight7")
#define ESID_Jd_SheDeng8                 (g_China ? (g_Big5 ? "���8" : "���8") : "Spotlight8")
#define ESID_Jd_SheDeng9                 (g_China ? (g_Big5 ? "���9" : "���9") : "Spotlight9")
#define ESID_Jd_SheDeng10                (g_China ? (g_Big5 ? "���10" : "���10") : "Spotlight10")
#define ESID_Jd_TaiDeng1                 (g_China ? (g_Big5 ? "̨��1" : "̨��1") : "Table Lamp1")
#define ESID_Jd_TaiDeng2                 (g_China ? (g_Big5 ? "̨��2" : "̨��2") : "Table Lamp2")
#define ESID_Jd_TaiDeng3                 (g_China ? (g_Big5 ? "̨��3" : "̨��3") : "Table Lamp3")
#define ESID_Jd_TaiDeng4                 (g_China ? (g_Big5 ? "̨��4" : "̨��4") : "Table Lamp4")
#define ESID_Jd_TaiDeng5                 (g_China ? (g_Big5 ? "̨��5" : "̨��5") : "Table Lamp5")
#define ESID_Jd_TaiDeng6                 (g_China ? (g_Big5 ? "̨��6" : "̨��6") : "Table Lamp6")
#define ESID_Jd_TaiDeng7                 (g_China ? (g_Big5 ? "̨��7" : "̨��7") : "Table Lamp7")
#define ESID_Jd_TaiDeng8                 (g_China ? (g_Big5 ? "̨��8" : "̨��8") : "Table Lamp8")
#define ESID_Jd_TaiDeng9                 (g_China ? (g_Big5 ? "̨��9" : "̨��9") : "Table Lamp9")
#define ESID_Jd_TaiDeng10                (g_China ? (g_Big5 ? "̨��10" : "̨��10") : "Table Lamp10")
#define ESID_Jd_LouDiDeng1               (g_China ? (g_Big5 ? "��ص�1" : "��ص�1") : "Floor Lamp1")
#define ESID_Jd_LouDiDeng2               (g_China ? (g_Big5 ? "��ص�2" : "��ص�2") : "Floor Lamp2")
#define ESID_Jd_LouDiDeng3               (g_China ? (g_Big5 ? "��ص�3" : "��ص�3") : "Floor Lamp3")
#define ESID_Jd_LouDiDeng4               (g_China ? (g_Big5 ? "��ص�4" : "��ص�4") : "Floor Lamp4")
#define ESID_Jd_LouDiDeng5               (g_China ? (g_Big5 ? "��ص�5" : "��ص�5") : "Floor Lamp5")
#define ESID_Jd_LouDiDeng6               (g_China ? (g_Big5 ? "��ص�6" : "��ص�6") : "Floor Lamp6")
#define ESID_Jd_LouDiDeng7               (g_China ? (g_Big5 ? "��ص�7" : "��ص�7") : "Floor Lamp7")
#define ESID_Jd_LouDiDeng8               (g_China ? (g_Big5 ? "��ص�8" : "��ص�8") : "Floor Lamp8")
#define ESID_Jd_LouDiDeng9               (g_China ? (g_Big5 ? "��ص�9" : "��ص�9") : "Floor Lamp9")
#define ESID_Jd_LouDiDeng10              (g_China ? (g_Big5 ? "��ص�10" : "��ص�10") : "Floor Lamp10")
#define ESID_Jd_ZhaoMingDeng1            (g_China ? (g_Big5 ? "������1" : "������1") : "Lighting Lamp1")
#define ESID_Jd_ZhaoMingDeng2            (g_China ? (g_Big5 ? "������2" : "������2") : "Lighting Lamp2")
#define ESID_Jd_ZhaoMingDeng3            (g_China ? (g_Big5 ? "������3" : "������3") : "Lighting Lamp3")
#define ESID_Jd_ZhaoMingDeng4            (g_China ? (g_Big5 ? "������4" : "������4") : "Lighting Lamp4")
#define ESID_Jd_ZhaoMingDeng5            (g_China ? (g_Big5 ? "������5" : "������5") : "Lighting Lamp5")
#define ESID_Jd_ZhaoMingDeng6            (g_China ? (g_Big5 ? "������6" : "������6") : "Lighting Lamp6")
#define ESID_Jd_ZhaoMingDeng7            (g_China ? (g_Big5 ? "������7" : "������7") : "Lighting Lamp7")
#define ESID_Jd_ZhaoMingDeng8            (g_China ? (g_Big5 ? "������8" : "������8") : "Lighting Lamp8")
#define ESID_Jd_ZhaoMingDeng9            (g_China ? (g_Big5 ? "������9" : "������9") : "Lighting Lamp9")
#define ESID_Jd_ZhaoMingDeng10           (g_China ? (g_Big5 ? "������10" : "������10") : "Lighting Lamp10")
 #define ESID_Jd_ShiYingDeng1             (g_China ? (g_Big5 ? "ʯӢ��1" : "ʯӢ��1") : "Quartz Lamp1")
 #define ESID_Jd_ShiYingDeng2             (g_China ? (g_Big5 ? "ʯӢ��2" : "ʯӢ��2") : "Quartz Lamp2")
 #define ESID_Jd_ShiYingDeng3             (g_China ? (g_Big5 ? "ʯӢ��3" : "ʯӢ��3") : "Quartz Lamp3")
 #define ESID_Jd_ShiYingDeng4             (g_China ? (g_Big5 ? "ʯӢ��4" : "ʯӢ��4") : "Quartz Lamp4")
 #define ESID_Jd_ShiYingDeng5             (g_China ? (g_Big5 ? "ʯӢ��5" : "ʯӢ��5") : "Quartz Lamp5")
 #define ESID_Jd_ShiYingDeng6             (g_China ? (g_Big5 ? "ʯӢ��6" : "ʯӢ��6") : "Quartz Lamp6")
 #define ESID_Jd_ShiYingDeng7             (g_China ? (g_Big5 ? "ʯӢ��7" : "ʯӢ��7") : "Quartz Lamp7")
 #define ESID_Jd_ShiYingDeng8             (g_China ? (g_Big5 ? "ʯӢ��8" : "ʯӢ��8") : "Quartz Lamp8")
 #define ESID_Jd_ShiYingDeng9             (g_China ? (g_Big5 ? "ʯӢ��9" : "ʯӢ��9") : "Quartz Lamp9")
#define ESID_Jd_ShiYingDeng10            (g_China ? (g_Big5 ? "ʯӢ��10" : "ʯӢ��10") : "Quartz Lamp10")
#define ESID_Jd_YeDeng1                  (g_China ? (g_Big5 ? "ҹ��1" : "ҹ��1") : "Nightlights1")
#define ESID_Jd_YeDeng2                  (g_China ? (g_Big5 ? "ҹ��2" : "ҹ��2") : "Nightlights2")
#define ESID_Jd_YeDeng3                  (g_China ? (g_Big5 ? "ҹ��3" : "ҹ��3") : "Nightlights3")
#define ESID_Jd_YeDeng4                  (g_China ? (g_Big5 ? "ҹ��4" : "ҹ��4") : "Nightlights4")
#define ESID_Jd_YeDeng5                  (g_China ? (g_Big5 ? "ҹ��5" : "ҹ��5") : "Nightlights5")
#define ESID_Jd_YeDeng6                  (g_China ? (g_Big5 ? "ҹ��6" : "ҹ��6") : "Nightlights6")
#define ESID_Jd_YeDeng7                  (g_China ? (g_Big5 ? "ҹ��7" : "ҹ��7") : "Nightlights7")
#define ESID_Jd_YeDeng8                  (g_China ? (g_Big5 ? "ҹ��8" : "ҹ��8") : "Nightlights8")
#define ESID_Jd_YeDeng9                  (g_China ? (g_Big5 ? "ҹ��9" : "ҹ��9") : "Nightlights9")
#define ESID_Jd_YeDeng10                 (g_China ? (g_Big5 ? "ҹ��10" : "ҹ��10") : "Nightlights10")
#define ESID_Jd_ZhuanshiDEng1            (g_China ? (g_Big5 ? "װ�ε�1" : "װ�ε�1") : "Deco Lamp1")
#define ESID_Jd_ZhuanshiDEng2            (g_China ? (g_Big5 ? "װ�ε�2" : "װ�ε�2") : "Deco Lamp2")
#define ESID_Jd_ZhuanshiDEng3            (g_China ? (g_Big5 ? "װ�ε�3" : "װ�ε�3") : "Deco Lamp3")
#define ESID_Jd_ZhuanshiDEng4            (g_China ? (g_Big5 ? "װ�ε�4" : "װ�ε�4") : "Deco Lamp4")
#define ESID_Jd_ZhuanshiDEng5            (g_China ? (g_Big5 ? "װ�ε�5" : "װ�ε�5") : "Deco Lamp5")
#define ESID_Jd_ZhuanshiDEng6            (g_China ? (g_Big5 ? "װ�ε�6" : "װ�ε�6") : "Deco Lamp6")
#define ESID_Jd_ZhuanshiDEng7            (g_China ? (g_Big5 ? "װ�ε�7" : "װ�ε�7") : "Deco Lamp7")
#define ESID_Jd_ZhuanshiDEng8            (g_China ? (g_Big5 ? "װ�ε�8" : "װ�ε�8") : "Deco Lamp8")
#define ESID_Jd_ZhuanshiDEng9            (g_China ? (g_Big5 ? "װ�ε�9" : "װ�ε�9") : "Deco Lamp9")
#define ESID_Jd_ZhuanshiDEng10           (g_China ? (g_Big5 ? "װ�ε�10" : "װ�ε�10") : "Deco Lamp10")
#ifdef _AIR_VOLUME_MODE_
#define ESID_Jd_Air_Volume            	 (g_China ? (g_Big5 ? "����" : "����") : "Air")
#define ESID_Jd_Low_Wind                 (g_China ? (g_Big5 ? "�ͷ�" : "�ͷ�") : "Low")
#define ESID_Jd_Medium_Wind              (g_China ? (g_Big5 ? "�з�" : "�з�") : "Medium")
#define ESID_Jd_Hight_Wind               (g_China ? (g_Big5 ? "�߷�" : "�߷�") : "Hight")
#define ESID_Jd_Automatic                (g_China ? (g_Big5 ? "�Զ�" : "�Զ�") : "Automatic")
#endif

// ������
#define ESID_Set_Menu_System             (g_China ? (g_Big5 ? "ϵͳ����" : "ϵͳ����") : "System Settings")
#define ESID_Set_Menu_Project            (g_China ? (g_Big5 ? "��������" : "��������") : "Installer Settings")
#define ESID_Set_Menu_Alarm              (g_China ? (g_Big5 ? "��������" : "��������") : "Security Settings")
#define ESID_Set_Menu_User               (g_China ? (g_Big5 ? "�û�����" : "�û�����") : "User Settings")
#define ESID_Set_System_language         (g_China ? (g_Big5 ? "ϵͳ����" : "ϵͳ����") : "Language")
#define ESID_Set_System_Time             (g_China ? (g_Big5 ? "������ʱ��" : "������ʱ��") : "Time & Date")
#define ESID_Set_System_Desk             (g_China ? (g_Big5 ? "���汳��" : "���汳��") : "Desktop")
#define ESID_Set_System_Screen           (g_China ? (g_Big5 ? "ӫĻ����" : "��Ļ����") : "Screen Saver")
#define ESID_Set_System_Light            (g_China ? (g_Big5 ? "ӫĻ����" : "��Ļ����") : "Screen Brightness")
#define ESID_Set_System_Storage          (g_China ? (g_Big5 ? "�洢����" : "�洢����") : "Memory Management")
#define ESID_Set_System_Info             (g_China ? (g_Big5 ? "ϵͳѶϢ" : "ϵͳ��Ϣ") : "System Info.")
#define ESID_Set_Prj_Pass                (g_China ? (g_Big5 ? "������������" : "������������") : "Installer Password")
#define ESID_Set_Prj_Alarm               (g_China ? (g_Big5 ? "��������" : "��������") : "Defense Zones")
#define ESID_Set_Prj_Net                 (g_China ? (g_Big5 ? "��·����" : "�������") : "Network Parameters")
#define ESID_Set_Prj_ExtMode             (g_China ? (g_Big5 ? "�ⲿģ��" : "�ⲿģ��") : "External Modules")
#define ESID_Set_Prj_DevNo               (g_China ? (g_Big5 ? "�豸���" : "�豸���") : "Device No.")
#define ESID_Set_Prj_NetDoor             (g_China ? (g_Big5 ? "������ǰ��" : "������ǰ��") : "IP Camera")
#define ESID_Set_Prj_Default             (g_China ? (g_Big5 ? "�ָ���������" : "�ָ���������") : "Restore Factory Settings")
#define ESID_Set_Prj_JiaDian             (g_China ? (g_Big5 ? "�ҵ�����" : "�ҵ�����") : "Home Appliances")
#define ESID_Set_Prj_Mic                 (g_China ? (g_Big5 ? "��ͷ��������" : "��ͷ��������") : "Mic Gain Settings")
#define ESID_Set_Prj_Mic_Db              (g_China ? (g_Big5 ? "��ͷ����" : "��ͷ����") : "Mic Gain")
#define ESID_Set_Prj_Set_Rtsp            (g_China ? (g_Big5 ? "�������" : "�������") : "Monitor Settings")
#define ESID_Set_Prj_Set_IPModule        (g_China ? (g_Big5 ? "IPЭ��ת����" : "IPЭ��ת����") : "IP Converter")
#define ESID_Set_Alarm_UserPwd           (g_China ? (g_Big5 ? "�û�����" : "�û�����") : "User Password")
#define ESID_Set_Alarm_DoorPwd           (g_China ? (g_Big5 ? "��������" : "��������") : "Unlock Password")
#define ESID_Set_Alarm_AfLink            (g_China ? (g_Big5 ? "��������" : "��������") : "Security Interlocking")
#define ESID_Set_Alarm_AfGeLi            (g_China ? (g_Big5 ? "��������" : "��������") : "Bypass")
#define ESID_Set_Alarm_AfJuFang          (g_China ? (g_Big5 ? "�ַ���Ч" : "�ַ���Ч") : "Night Mode")
#define ESID_Set_UAlarm_Remote           (g_China ? (g_Big5 ? "Զ�̿���" : "Զ�̿���") : "Remote Control")
#define ESID_Set_Alarm_MsgNum            (g_China ? (g_Big5 ? "���ź�������" : "���ź�������") : "Alarm MSG No.")
#define ESID_Set_Alarm_TelNum            (g_China ? (g_Big5 ? "������������" : "������������") : "Alarm Call No.")
#define ESID_Set_User_Sound              (g_China ? (g_Big5 ? "��������" : "��������") : "Ringtone")
#define ESID_Set_User_Volume             (g_China ? (g_Big5 ? "��������" : "��������") : "Volume")
#define ESID_Set_User_NoFace             (g_China ? (g_Big5 ? "���������" : "���������") : "Do-Not-Disturb")
#define ESID_Set_User_LyLy               (g_China ? (g_Big5 ? "��Ӱ��������" : "��Ӱ��������") : "MSG")
#define ESID_Set_User_PT                 (g_China ? (g_Big5 ? "ƽ̨ע��" : "ƽ̨ע��") : "Registration")
#define ESID_Set_Unreg                   (g_China ? (g_Big5 ? "ƽ̨δע��" : "ƽ̨δע��") : "Device not registered on Aurine Platform yet!")
#define ESID_Set_Reg_Code                (g_China ? (g_Big5 ? "ƽ̨��֤��:" : "ƽ̨��֤��:") : "Verification Code:")
#define ESID_Set_Reging                  (g_China ? (g_Big5 ? "���ڽ���ƽ̨ע��,���Ժ�..." : "���ڽ���ƽ̨ע��,���Ժ�...") : "Registering...")
#define ESID_Set_Prj_Net_HostIP          (g_China ? (g_Big5 ? "����IP" : "����IP") : "Device IP")
#define ESID_Set_Prj_Net_HostNetMask     (g_China ? (g_Big5 ? "��������·����" : "������������") : "Subnet Mask")    
#define ESID_Set_Prj_Net_HostGateWay     (g_China ? (g_Big5 ? "������·�ѵ�" : "��������") : "Gateway") 
#define ESID_Set_Prj_Net_CenterSever     (g_China ? (g_Big5 ? "�����ŷ���IP" : "���ķ�����IP") : "Center Server")
#define ESID_Set_Prj_Net_ManageIP1       (g_China ? (g_Big5 ? "����Ա��һIP" : "����Ա��һIP") : "Admin Unit1")  
#define ESID_Set_Prj_Net_ManageIP2       (g_China ? (g_Big5 ? "����Ա����IP" : "����Ա����IP") : "Admin Unit2") 
#define ESID_Set_Prj_Net_ManageIP3       (g_China ? (g_Big5 ? "����Ա����IP" : "����Ա����IP") : "Admin Unit3")
#define ESID_Set_Prj_Net_AurineSever     (g_China ? (g_Big5 ? "ƽ̨�ŷ���IP" : "ƽ̨������IP") : "Platform Server")  
#define ESID_Set_Prj_Net_AurineElevator  (g_China ? (g_Big5 ? "���ݿ�����IP" : "���ݿ�����IP") : "Elevator Controller") 
#define ESID_Set_Prj_Net_Rtsp            (g_China ? (g_Big5 ? "��ý���ŷ���" : "��ý�������") : "RTSP Server") 
#define ESID_Set_Prj_Net_Stair           (g_China ? (g_Big5 ? "�ƶ˽�����IP" : "�ƶ˽�����IP") : "Cloud Access Device")
#define ESID_Set_Prj_Net_IPModule_IP     (g_China ? (g_Big5 ? "IPЭ��ת������ַ" : "IPЭ��ת������ַ") : "IP Address")    
#define ESID_Set_Prj_Net_IPModule_Code   (g_China ? (g_Big5 ? "IPЭ��ת��������" : "IPЭ��ת��������") : "Binding Code")      
#define ESID_Set_Dev_Rule                (g_China ? (g_Big5 ? "��Ź���" : "��Ź���") : "Number Rule")
#define ESID_Set_Dev_Stair_len           (g_China ? (g_Big5 ? "�ݺų���" : "�ݺų���") : "Stairway No.")
#define ESID_Set_Dev_Room_len            (g_China ? (g_Big5 ? "���ų���" : "���ų���") : "Apartment No.")
#define ESID_Set_Dev_Cell_len            (g_China ? (g_Big5 ? "��Ԫ�ų���" : "��Ԫ�ų���") : "Riser No.")
#define ESID_Set_Dev_UseCell             (g_China ? (g_Big5 ? "���õ�Ԫ��" : "���õ�Ԫ��") : "Enable Riser No.")
#define ESID_Set_Dev_BIT                 (g_China ? (g_Big5 ? "λ" : "λ") : "Digits")
#define ESID_Set_Ext_Alarm               (g_China ? (g_Big5 ? "����ģ��" : "����ģ��") : "Alarm Module")
#define ESID_Set_Ext_JiaDian             (g_China ? (g_Big5 ? "�ҵ�ģ��" : "�ҵ�ģ��") : "Home Automation Module")
#define ESID_Set_Ext_Stair               (g_China ? (g_Big5 ? "ͨ���ݿڻ�" : "ͨ���ݿڻ�") : "General Secondary Entry Station")
#define ESID_Set_Language                (g_China ? (g_Big5 ? "��ȷ���Ƿ񱣴�����?" : "��ȷ���Ƿ񱣴�����?") : "Save The Setting?")
#ifdef _TCPTO485_ELEVATOR_MODE_
#define ESID_Set_TCP485Elevator           (g_China ? (g_Big5 ? "TCPת485ģ��IP" : "TCPת485ģ��IP") : "TCP To 485 Addr")
#endif

// IPЭ��ת����
#define ESID_Set_binding_code        	 (g_China ? (g_Big5 ? "����:" : "����:") : "Binding Code:")
#define ESID_Set_binding_code1        	 (g_China ? (g_Big5 ? "����" : "����") : "Binding Code") 
#define ESID_Set_binding_status          (g_China ? (g_Big5 ? "��״̬:" : "��״̬:") : "Binding State:")
#define ESID_Set_extension_information   (g_China ? (g_Big5 ? "�ֻ�ѶϢ:" : "�ֻ���Ϣ:") : "EXT-INFO:")
#define ESID_Set_ip_ptcAddr				 (g_China ? (g_Big5 ? "Э��ת����IP:" : "Э��ת����IP:") : "IP Address:")
#define ESID_Set_generate_binding_code   (g_China ? (g_Big5 ? "���ɰ���" : "���ɰ���") : "Binding Code")
#define ESID_Set_binding  				 (g_China ? (g_Big5 ? "��" : "��") : "Binding")
#define ESID_Set_get_extension			 (g_China ? (g_Big5 ? "��ȡ�ֻ�" : "��ȡ�ֻ�") : "Extension")
#define ESID_Set_bounded  				 (g_China ? (g_Big5 ? "�Ѱ�" : "�Ѱ�") : "Binding")
#define ESID_Set_unbounded				 (g_China ? (g_Big5 ? "δ��" : "δ��") : "Unbounded")
#define ESID_Set_ExtenNo 				 (g_China ? (g_Big5 ? "�ֻ�" : "�ֻ�") : "EXT")
#define ESID_Set_ExtenState				 (g_China ? (g_Big5 ? "״̬" : "״̬") : "Status")
#define ESID_Set_Online				     (g_China ? (g_Big5 ? "����" : "����") : "OnLine")
#define ESID_Set_Offline 				 (g_China ? (g_Big5 ? "����" : "����") : "UnLine")
#define ESID_Set_Bind_OK				 (g_China ? (g_Big5 ? "�󶨳ɹ�" : "�󶨳ɹ�") : "OK")
#define ESID_Set_Bind_Fail				 (g_China ? (g_Big5 ? "��ʧ��" : "��ʧ��") : "Failed")

// ������ǰ������
#define ESID_Net_Door_First_R            (g_China ? (g_Big5 ? "��ǰ��һ" : "��ǰ��һ") : "Camera 1")
#define ESID_Net_Door_Second_R           (g_China ? (g_Big5 ? "��ǰ����" : "��ǰ����") : "Camera 2")
#define ESID_Net_Door_First_A            (g_China ? (g_Big5 ? "ģ����ǰ��һ" : "ģ����ǰ��һ") : "Analog Camera 1")
#define ESID_Net_Door_Second_A           (g_China ? (g_Big5 ? "ģ����ǰ����" : "ģ����ǰ����") : "Analog Camera 2")
#define ESID_Net_Door             		 (g_China ? (g_Big5 ? "������ǰ��" : "������ǰ��") : "IP Camera")
#define ESID_Net_Door_First              (g_China ? (g_Big5 ? "������ǰ��һ" : "������ǰ��һ") : "IP Camera 1")
#define ESID_Net_Door_Second             (g_China ? (g_Big5 ? "������ǰ����" : "������ǰ����") : "IP Camera 2")
#define ESID_Net_Door_IP                 (g_China ? (g_Big5 ? "IP��ַ" : "IP��ַ") : "IP Address")
#define ESID_Net_Door_Sub                (g_China ? (g_Big5 ? "����·����" : "��������") : "Subnet Mask")
#define ESID_Net_Door_GateWay            (g_China ? (g_Big5 ? "��·�ѵ�" : "����") : "Gateway")
#define ESID_Net_Door_GetMAC             (g_China ? (g_Big5 ? "��MAC��" : "��MAC��") : "Obtain MAC")
#define ESID_Net_Door_MAC                (g_China ? (g_Big5 ? "MAC" : "MAC") : "MAC")
#define ESID_Net_Door_NetParam           (g_China ? (g_Big5 ? "��·����" : "�������") : "Network Parameters")
#define ESID_Net_Door_LockType           (g_China ? (g_Big5 ? "����������" : "����������") : "Lock")
#define ESID_Net_Door_CardMan            (g_China ? (g_Big5 ? "������" : "������") : "IC Card")
#define ESID_Net_Door_SysInfo            (g_China ? (g_Big5 ? "ϵͳѶϢ" : "ϵͳ��Ϣ") : "System Info.")
#define ESID_Net_Door_Other_Set          (g_China ? (g_Big5 ? "��������" : "��������") : "Other Settings")
#define ESID_Net_Door_Open               (g_China ? (g_Big5 ? "����" : "����") : "N/O")
#define ESID_Net_Door_Close              (g_China ? (g_Big5 ? "����" : "����") : "N/C")
#define ESID_Net_Door_LTime_Mh           (g_China ? (g_Big5 ? "����ʱ��:" : "����ʱ��:") : "Unlock Time:")
#define ESID_Net_Door_LockTime           (g_China ? (g_Big5 ? "����ʱ��" : "����ʱ��") : "Unlock Time")
#define ESID_Net_Door_Pic_Up             (g_China ? (g_Big5 ? "�����ϴ�" : "�����ϴ�") : "Snapshot Upload")
#define ESID_Net_Door_Remote_Moniter     (g_China ? (g_Big5 ? "Զ�̼���" : "Զ�̼���") : "Remote Monitoring")
#define ESID_Net_Door_Add_Card           (g_China ? (g_Big5 ? "���ӿ�" : "���ӿ�") : "Add Card")
#define ESID_Net_Door_Del_Card           (g_China ? (g_Big5 ? "ɾ����" : "ɾ����") : "Del Card")
#define ESID_Net_Door_Unused_First       (g_China ? (g_Big5 ? "δ����������ǰ��һ!" : "δ����������ǰ��һ!") : "IP Camera 1 Inactivated!")
#define ESID_Net_Door_Unused_Second      (g_China ? (g_Big5 ? "δ����������ǰ����!" : "δ����������ǰ����!") : "IP Camera 2 Inactivated!")
#define ESID_Net_Door_Pls_Add_Card       (g_China ? (g_Big5 ? "��ˢ������Ҫ���ӵĿ�!" : "��ˢ������Ҫ���ӵĿ�!") : "Please add the card!")
#define ESID_Net_Door_Sure_Del_Card      (g_China ? (g_Big5 ? "�Ƿ�ɾ�����еĿ�?" : "�Ƿ�ɾ�����еĿ�?") : "Sure to delete all cards?")
#define ESID_Net_Door_Video_Fmt          (g_China ? (g_Big5 ? "��ͨ��Ƶ����" : "��ͨ��Ƶ����") : "Standard Video Quality")
#define ESID_Set_Info_HW                 (g_China ? (g_Big5 ? "Ӳ��汾" : "Ӳ���汾") : "Hardware Ver")
#define ESID_Set_Info_SF                 (g_China ? (g_Big5 ? "����汾" : "����汾") : "Software Ver")
#define ESID_Set_Info_SDK                (g_China ? (g_Big5 ? "SDK�汾" : "SDK�汾") : "SDK Ver")
#define ESID_Set_Info_HostMAC            (g_China ? (g_Big5 ? "����MAC" : "����MAC") : "MAC")
#define ESID_Set_Info_Room               (g_China ? (g_Big5 ? "��������" : "��������") : "Device No.")
#define ESID_Set_Timer_Wanl              (g_China ? (g_Big5 ? "������" : "������") : "Calendar")
#define ESID_Storage_Format              (g_China ? (g_Big5 ? "��ʽ��" : "��ʽ��") : "Format")
#define ESID_Storage_Pic                 (g_China ? (g_Big5 ? "ͼƬ" : "ͼƬ") : "Picture")
#define ESID_Set_Pass_Server             (g_China ? (g_Big5 ? "�ܼ�����" : "��������") : "Servant Password")
#define ESID_Set_Pass_DoorUser           (g_China ? (g_Big5 ? "ס����������" : "ס����������") : "Household Password")
#define ESID_Set_Pass_DoorServer         (g_China ? (g_Big5 ? "�ܼҿ�������" : "������������") : "Servant Password")
#define ESID_Set_Pass_Old                (g_China ? (g_Big5 ? "������" : "������") : "Old:")
#define ESID_Set_Pass_New                (g_China ? (g_Big5 ? "������" : "������") : "New:")
#define ESID_Set_Pass_Query              (g_China ? (g_Big5 ? "ȷ������" : "ȷ������") : "Re-enter:")
#define ESID_Set_volume_ring             (g_China ? (g_Big5 ? "��������" : "��������") : "Ringing Volume")
#define ESID_Set_volume_talk             (g_China ? (g_Big5 ? "ͨ������" : "ͨ������") : "Talk Volume")
#define ESID_Set_volume_key              (g_China ? (g_Big5 ? "���ð�����" : "���ð�����") : "Keypad Tone")
#define ESID_Set_ring_Stair              (g_China ? (g_Big5 ? "�ݿ���������" : "�ݿ���������") : "Sec.Entry")
#define ESID_Set_ring_Area               (g_China ? (g_Big5 ? "������������" : "������������") : "Prim.Entry")
#define ESID_Set_ring_Door               (g_China ? (g_Big5 ? "��ǰ��������" : "��ǰ��������") : "Doorway")
#define ESID_Set_ring_Center             (g_China ? (g_Big5 ? "������������" : "������������") : "Admin")
#define ESID_Set_ring_Room               (g_China ? (g_Big5 ? "ס����������" : "ס����������") : "Resident")
#define ESID_Set_ring_fenji              (g_China ? (g_Big5 ? "�ֻ���������" : "�ֻ���������") : "Extension")
#define ESID_Set_ring_Info               (g_China ? (g_Big5 ? "ѶϢ��ʾ��" : "��Ϣ��ʾ��") : "New Message")
#define ESID_Set_ring_alarm              (g_China ? (g_Big5 ? "Ԥ����ʾ��" : "Ԥ����ʾ��") : "Exit Delay Alert")
#define ESID_Set_ring                    (g_China ? (g_Big5 ? "����" : "����") : "Ringtone")
#define ESID_Set_hit                     (g_China ? (g_Big5 ? "��ʾ��" : "��ʾ��") : "Tip Sound")
#define ESID_Set_Lyly_Mode_Audio         (g_China ? (g_Big5 ? "������ģʽ" : "������ģʽ") : "Voice MSG")
#define ESID_Set_Lyly_Mode_Both          (g_China ? (g_Big5 ? "������Ƭģʽ" : "������Ƭģʽ") : "Voice MSG & Image")
#define ESID_Set_Lyly_Mode_Video         (g_China ? (g_Big5 ? "��Ӱ����ģʽ" : "��Ӱ����ģʽ") : "Video MSG")
#define ESID_Set_Lyly_Link1              (g_China ? (g_Big5 ? "���״̬��������Ӱ����" : "���״̬��������Ӱ����") : "Activate MSG under the AWAY mode")
#define ESID_Set_Lyly_Link2              (g_China ? (g_Big5 ? "ҹ��״̬��������Ӱ����" : "ҹ��״̬��������Ӱ����") : "Activate MSG under the NIGHT mode")
#define ESID_Set_Lyly_Link3              (g_China ? (g_Big5 ? "�����״̬��������Ӱ����" : "�����״̬��������Ӱ����") : "Enable MSG under the Do-Not-Disturb mode")
#define ESID_Set_Lyly_default_tip        (g_China ? (g_Big5 ? "Ԥ����ʾ��" : "Ĭ����ʾ��") : "Default")
#define ESID_Set_Lyly_record_tip         (g_China ? (g_Big5 ? "¼����ʾ��" : "¼����ʾ��") : "Customized")
#define ESID_Set_Screen_InTime           (g_China ? (g_Big5 ? "����ӫĻ����ʱ��" : "��������ʱ��") : "Starts In")
#define ESID_Set_Screen_Lcd              (g_China ? (g_Big5 ? "����ʱ��" : "����ʱ��") : "Turn off Display")
#define ESID_Set_Query_Del_All        	 (g_China ? (g_Big5 ? "ȷ���Ƿ����?" : "ȷ���Ƿ����?") : "Sure to delete all?")
#define ESID_Set_Tips_Fail				 (g_China ? (g_Big5 ? "δ¼����ʾ��" : "δ¼����ʾ��") : "No Recording Tips")	

// �ҵ���������
#define ESID_Jd_Set_Light                (g_China ? (g_Big5 ? "�ƹ�����" : "�ƹ�����") : "Light")
#define ESID_Jd_Set_Window               (g_China ? (g_Big5 ? "��������" : "��������") : "Curtain")
#define ESID_Jd_Set_Kongtiao             (g_China ? (g_Big5 ? "�յ�����" : "�յ�����") : "A/C")
#define ESID_Jd_Set_Dianyuan             (g_China ? (g_Big5 ? "��Դ����" : "��Դ����") : "Socket")
#define ESID_Jd_Set_Gas                  (g_China ? (g_Big5 ? "ú������" : "ú������") : "Gas")
#define ESID_Jd_Set_Adrress              (g_China ? (g_Big5 ? "��ַ" : "��ַ") : "Address")
#define ESID_Jd_Set_OpenAddr             (g_China ? (g_Big5 ? "����ַ" : "����ַ") : "Starting Address")
#define ESID_Jd_Set_CloseAddr            (g_China ? (g_Big5 ? "�ص�ַ" : "�ص�ַ") : "Closing Address")
#define ESID_Jd_Set_Dev_Name1            (g_China ? (g_Big5 ? "�豸λ��" : "�豸λ��") : "Address")
#define ESID_Jd_Set_Dev_Name2            (g_China ? (g_Big5 ? "�豸����" : "�豸����") : "Type")
#define ESID_Jd_Open_All                 (g_China ? (g_Big5 ? "ȫ��" : "ȫ��") : "ALL ON")
#define ESID_Jd_Close_All                (g_China ? (g_Big5 ? "ȫ��" : "ȫ��") : "ALL OFF")
#define ESID_Jd_Qingjing                 (g_China ? (g_Big5 ? "�龰ģʽ" : "�龰ģʽ") : "Scene Mode")
#define ESID_Jd_Light                    (g_China ? (g_Big5 ? "�ƹ�" : "�ƹ�") : "Light")
#define ESID_Jd_KongTiao                 (g_China ? (g_Big5 ? "�յ�" : "�յ�") : "A/C")
#define ESID_Jd_Dianyuan                 (g_China ? (g_Big5 ? "��Դ" : "��Դ") : "Socket")
#define ESID_Jd_Meiqi                    (g_China ? (g_Big5 ? "ú��" : "ú��") : "Gas")
#define ESID_Jd_Control_Mode             (g_China ? (g_Big5 ? "���Ʒ�ʽ" : "���Ʒ�ʽ") : "Control")
#define ESID_Jd_Signal_Control           (g_China ? (g_Big5 ? "����" : "����") : "Single")
#define ESID_Jd_Multi_Control            (g_China ? (g_Big5 ? "���" : "���") : "Group")
#define ESID_Jd_Group_No                 (g_China ? (g_Big5 ? "���" : "���") : "Group No.")
#define ESID_Jd_Dev_Set_Attr             (g_China ? (g_Big5 ? "����" : "����") : "Property")
#define ESID_Jd_Dev_Set_Adjust           (g_China ? (g_Big5 ? "�ɵ�" : "�ɵ�") : "Adjustable")
#define ESID_Jd_Dev_Set_UnAdjust         (g_China ? (g_Big5 ? "���ɵ�" : "���ɵ�") : "Unadjustable")
#define ESID_Jd_Dev_Set_Light            (g_China ? (g_Big5 ? "����" : "����") : "Brightness")
#define ESID_Jd_Dev_Set_Temp             (g_China ? (g_Big5 ? "�¶�" : "�¶�") : "Temperature")
#define ESID_Jd_Dev_Set_NoDev            (g_China ? (g_Big5 ? "���豸" : "���豸") : "None")
#define ESID_Jd_Dev_Name                 (g_China ? (g_Big5 ? "����" : "����") : "Description")
#define ESID_Jd_KongTiao_Learn           (g_China ? (g_Big5 ? "����ѧϰ" : "����ѧϰ") : "IR Study")
#define ESID_Jd_KongTiao_Cold            (g_China ? (g_Big5 ? "����ѧϰ" : "����ѧϰ") : "Cool")
#define ESID_Jd_KongTiao_Hot             (g_China ? (g_Big5 ? "��ůѧϰ" : "��ůѧϰ") : "Heat")
#define ESID_Jd_KongTiao_Mode            (g_China ? (g_Big5 ? "ģʽѧϰ" : "ģʽѧϰ") : "Mode")
#define ESID_Jd_Learn                    (g_China ? (g_Big5 ? "��ʼѧϰ" : "��ʼѧϰ") : "Start")
#define ESID_Jd_Test                     (g_China ? (g_Big5 ? "����" : "����") : "Test")
#define ESID_Jd_KongTiao_Refre           (g_China ? (g_Big5 ? "��ˬ" : "��ˬ") : "Fresh")
#define ESID_Jd_KongTiao_Warm            (g_China ? (g_Big5 ? "��ů" : "��ů") : "Warm")
#define ESID_Jd_KongTiao_Leisure         (g_China ? (g_Big5 ? "����" : "����") : "Casual")
#define ESID_Jd_KongTiao_Sleep           (g_China ? (g_Big5 ? "˯��" : "˯��") : "Sleep")
#define ESID_Jd_KongTiao_Close           (g_China ? (g_Big5 ? "�ر�" : "�ر�") : "OFF")
#define ESID_Jd_Button_Cold              (g_China ? (g_Big5 ? "����" : "����") : "Cool")
#define ESID_Jd_Button_Warm              (g_China ? (g_Big5 ? "��ů" : "��ů") : "Heat")
#define ESID_Jd_Button_Mode              (g_China ? (g_Big5 ? "ģʽ" : "ģʽ") : "Mode")
#define ESID_Jd_Window_Stop              (g_China ? (g_Big5 ? "ֹͣ" : "ֹͣ") : "Stop")
#define ESID_Jd_Lamp                     (g_China ? (g_Big5 ? "�ƹ�" : "�ƹ�") : "Lamp")
#define ESID_Jd_Qingjing1                (g_China ? (g_Big5 ? "�龰ģʽ" : "�龰ģʽ") : "Scene")
#define ESID_Jd_Set_Name_Err             (g_China ? (g_Big5 ? "�����ظ�,����ʧ��!" : "�����ظ�,����ʧ��!") : "Description Repeated!")
#define ESID_Jd_Set_Adr_Err              (g_China ? (g_Big5 ? "��ַ�ظ�,��������!" : "��ַ�ظ�,��������!") : "Address Repeated!")
#define ESID_Jd_Set_OpAdr_Err            (g_China ? (g_Big5 ? "����ַ�ظ�,��������!" : "����ַ�ظ�,��������!") : "Same Starting Address")
#define ESID_Jd_Set_ClAdr_Err            (g_China ? (g_Big5 ? "�ص�ַ�ظ�,��������!" : "�ص�ַ�ظ�,��������!") : "Same Closing Address")
#define ESID_Jd_Set_Dev_Failed           (g_China ? (g_Big5 ? "�豸����ʧ��!" : "�豸����ʧ��!") : "Failed!")
#define ESID_Jd_Set_Dev_Noname           (g_China ? (g_Big5 ? "����������!" : "����������!") : "Please enter the device name!")
#define ESID_Jd_Adress_Set_Warning       (g_China ? (g_Big5 ? "�����뷶Χ��0-255�ĵ�ַ" : "�����뷶Χ��0-255�ĵ�ַ") : "Address shall be within 0-255.")
#define ESID_Jd_Set_Scene_Noname         (g_China ? (g_Big5 ? "����������!" : "����������!") : "Please enter the scene name!")
#define ESID_Jd_Set_KtLearn_Err          (g_China ? (g_Big5 ? "ѧϰʧ��,������ѧϰ!" : "ѧϰʧ��,������ѧϰ!") : "Failed! Pls try it again.")
#define ESID_Jd_Set_KtLearn_Ok           (g_China ? (g_Big5 ? "ѧϰ�ɹ�!" : "ѧϰ�ɹ�!") : "OK!")
#define ESID_Jd_Set_Adr_Wrong            (g_China ? (g_Big5 ? "�����뷶Χ��16-254�ĵ�ַ" : "�����뷶Χ��16-254�ĵ�ַ") : "Address shall be within 16-254.")
#define ESID_Jd_Sence_Adr                (g_China ? (g_Big5 ? "(��ַ��ΧΪ16-254)" : "(��ַ��ΧΪ16-254)") : "(Address shall be within 16-254)")
#define ESID_Jd_Aurine_Adress_Set_Warning  (g_China ? (g_Big5 ? "�����뷶Χ��0-254�ĵ�ַ" : "�����뷶Χ��0-254�ĵ�ַ") : "Address shall be within 0-254.")
#define ESID_Jd_Kongtiao_Learning        (g_China ? (g_Big5 ? "ѧϰ��,���Ժ�..." : "ѧϰ��,���Ժ�...") : "Studying, pls wait...")
#define ESID_Jd_Set_Scene                (g_China ? (g_Big5 ? "�龰����" : "�龰����") : "Scene Mode")
#define ESID_Jd_Mode_Huike               (g_China ? (g_Big5 ? "���ģʽ" : "���ģʽ") : "Meeting")
#define ESID_Jd_Mode_Jiucan              (g_China ? (g_Big5 ? "�Ͳ�ģʽ" : "�Ͳ�ģʽ") : "Dining")
#define ESID_Jd_Mode_Yejian              (g_China ? (g_Big5 ? "ҹ��ģʽ" : "ҹ��ģʽ") : "Night")
#define ESID_Jd_Mode_Jiedian             (g_China ? (g_Big5 ? "�ڵ�ģʽ" : "�ڵ�ģʽ") : "Saving")
#define ESID_Jd_Mode_Putong              (g_China ? (g_Big5 ? "��ͨģʽ" : "��ͨģʽ") : "Regular")
#define ESID_Jd_Mode_Self                (g_China ? (g_Big5 ? "�龰ģʽ" : "�龰ģʽ") : "Scene Mode")
#define ESID_Jd_Mode_Set_Name1           (g_China ? (g_Big5 ? "�龰����" : "�龰����") : "Scene Name")
#define ESID_Jd_Mode_Set_Name2           (g_China ? (g_Big5 ? "�龰����" : "�龰����") : "Scene Type")
#define ESID_Jd_Mode_Out                 (g_China ? (g_Big5 ? "���" : "���") : "Away")
#define ESID_Jd_Mode_Cook                (g_China ? (g_Big5 ? "���" : "���") : "Cooking")
#define ESID_Jd_Mode_first               (g_China ? (g_Big5 ? "���" : "���") : "Breakfast")
#define ESID_Jd_Mode_Afater              (g_China ? (g_Big5 ? "���" : "���") : "Lunch")
#define ESID_Jd_Mode_Night               (g_China ? (g_Big5 ? "����" : "����") : "Supper")
#define ESID_Jd_Mode_Bed                 (g_China ? (g_Big5 ? "����" : "����") : "Bed")
#define ESID_Jd_Mode_QiYe                (g_China ? (g_Big5 ? "��ҹ" : "��ҹ") : "Mid-night")
#define ESID_Jd_Mode_Up                  (g_China ? (g_Big5 ? "��" : "��") : "Wake-up")
#define ESID_Jd_Mode_Muyu                (g_China ? (g_Big5 ? "��ԡ" : "��ԡ") : "Bath")
#define ESID_Jd_Mode_Tea                 (g_China ? (g_Big5 ? "Ʒ��" : "Ʒ��") : "Tea")
#define ESID_Jd_Mode_Drink               (g_China ? (g_Big5 ? "����" : "����") : "Bibulous")
#define ESID_Jd_Mode_Read                (g_China ? (g_Big5 ? "�Ķ�" : "�Ķ�") : "Reading")
#define ESID_Jd_Mode_Work                (g_China ? (g_Big5 ? "����" : "����") : "Working")
#define ESID_Jd_Mode_Juhui               (g_China ? (g_Big5 ? "�ۻ�" : "�ۻ�") : "Party")
#define ESID_Jd_Mode_Play                (g_China ? (g_Big5 ? "����" : "����") : "Chess&Cards")
#define ESID_Jd_Mode_Film                (g_China ? (g_Big5 ? "ӰԺ" : "ӰԺ") : "Theatre")
#define ESID_Jd_Mode_Sing                (g_China ? (g_Big5 ? "����" : "����") : "Carolling")
#define ESID_Jd_Mode_Storang             (g_China ? (g_Big5 ? "����" : "����") : "Exercising")
#define ESID_Jd_Mode_Wenxi               (g_China ? (g_Big5 ? "��ܰ" : "��ܰ") : "Cozy")
#define ESID_Jd_Mode_Langman             (g_China ? (g_Big5 ? "����" : "����") : "Romatic")
#define ESID_Jd_Mode_Jiqing              (g_China ? (g_Big5 ? "����" : "����") : "Passionate")
#define ESID_Jd_Mode_Dianya              (g_China ? (g_Big5 ? "����" : "����") : "Elegant")
#define ESID_Jd_Mode_Chlid               (g_China ? (g_Big5 ? "ͯȤ" : "ͯȤ") : "Childish")
#define ESID_Jd_Mode_Chenwen             (g_China ? (g_Big5 ? "����" : "����") : "Sedate")
#define ESID_Jd_Mode_Think               (g_China ? (g_Big5 ? "��˼" : "��˼") : "Calm")
#define ESID_Jd_Mode_Cool                (g_China ? (g_Big5 ? "����" : "����") : "Cool")
#define ESID_Jd_Mode_Warm                (g_China ? (g_Big5 ? "��ů" : "��ů") : "Warm")
#define ESID_Jd_Mode_Mode                (g_China ? (g_Big5 ? "ģʽ" : "ģʽ") : "Mode")
#define ESID_Jd_Mode_Sence               (g_China ? (g_Big5 ? "�龰" : "�龰") : "Scene")
#define ESID_Jd_Mode_Qingdiao            (g_China ? (g_Big5 ? "���" : "���") : "Sentiment")
#define ESID_Jd_Mode_Fenwei              (g_China ? (g_Big5 ? "��Χ" : "��Χ") : "Atmosphere")
#define ESID_Jd_Mode_Time                (g_China ? (g_Big5 ? "ʱ��" : "ʱ��") : "Time")
#define ESID_Jd_Mode_Changjing           (g_China ? (g_Big5 ? "����" : "����") : "Occasion")
#define ESID_Jd_LouShang                 (g_China ? (g_Big5 ? "¥��" : "¥��") : "Upstairs")
#define ESID_Jd_LouXia                   (g_China ? (g_Big5 ? "¥��" : "¥��") : "Downstairs")
#define ESID_Jd_WuNei                    (g_China ? (g_Big5 ? "����" : "����") : "Indoor")
#define ESID_Jd_WuWai                    (g_China ? (g_Big5 ? "����" : "����") : "Outdoor")
#define ESID_Jd_TianTai                  (g_China ? (g_Big5 ? "��̨" : "��̨") : "Roof")
#define ESID_Jd_GeLou                    (g_China ? (g_Big5 ? "��¥" : "��¥") : "Attic")
#define ESID_Jd_HuaYuan                  (g_China ? (g_Big5 ? "��԰" : "��԰") : "Garden")
#define ESID_Jd_DiJiao                   (g_China ? (g_Big5 ? "�ؽ�" : "�ؽ�") : "Cellar")
#define ESID_Jd_TianJin                  (g_China ? (g_Big5 ? "�쾮" : "�쾮") : "Patio")
#define ESID_Jd_WuYan                    (g_China ? (g_Big5 ? "����" : "����") : "Roof")
#define ESID_Jd_QianTing                 (g_China ? (g_Big5 ? "ǰͥ" : "ǰͥ") : "Vestibule")
#define ESID_Jd_HouYuan                  (g_China ? (g_Big5 ? "��Ժ" : "��Ժ") : "Backyard")
#define ESID_Jd_DianTiJian               (g_China ? (g_Big5 ? "���ݼ�" : "���ݼ�") : "Elevator")
#define ESID_Jd_TingCheFang              (g_China ? (g_Big5 ? "ͣ����" : "ͣ����") : "Parking Room")
#define ESID_Jd_DaMen                    (g_China ? (g_Big5 ? "����" : "����") : "Gate")
#define ESID_Jd_QianMen                  (g_China ? (g_Big5 ? "ǰ��" : "ǰ��") : "Front Door")
#define ESID_Jd_ZhongMen                 (g_China ? (g_Big5 ? "����" : "����") : "MidDoor")
#define ESID_Jd_PangMen                  (g_China ? (g_Big5 ? "����" : "����") : "Side Door")
#define ESID_Jd_HouMen                   (g_China ? (g_Big5 ? "����" : "����") : "Backdoor")
#define ESID_Jd_CeMen                    (g_China ? (g_Big5 ? "����" : "����") : "Side gate")
#define ESID_Jd_BianMen                  (g_China ? (g_Big5 ? "����" : "����") : "Wicket")
#define ESID_Jd_HenMen                   (g_China ? (g_Big5 ? "����" : "����") : "Fence Door")
#define ESID_Jd_YanTai                   (g_China ? (g_Big5 ? "��̨" : "��̨") : "Balcony")
#define ESID_Jd_Zhoulan                  (g_China ? (g_Big5 ? "����" : "����") : "Corridor")
#define ESID_Jd_GuoDao                   (g_China ? (g_Big5 ? "����" : "����") : "Aisle")
#define ESID_Jd_LouTi                    (g_China ? (g_Big5 ? "¥��" : "¥��") : "Stairs")
#define ESID_Jd_TiKou                    (g_China ? (g_Big5 ? "�ݿ�" : "�ݿ�") : "Stairway")
#define ESID_Jd_TiJian                   (g_China ? (g_Big5 ? "�ݼ�" : "�ݼ�") : "Staircase")
#define ESID_Jd_TiXia                    (g_China ? (g_Big5 ? "����" : "����") : "Down the Ladder")
#define ESID_Jd_KeTing                   (g_China ? (g_Big5 ? "����" : "����") : "Drawing Room")
#define ESID_Jd_DaTing                   (g_China ? (g_Big5 ? "����" : "����") : "Hall")
#define ESID_Jd_ZhuTing                  (g_China ? (g_Big5 ? "����" : "����") : "Main Hall")
#define ESID_Jd_CanTing                  (g_China ? (g_Big5 ? "����" : "����") : "Restaurants")
#define ESID_Jd_FanTing                  (g_China ? (g_Big5 ? "����" : "����") : "Dining Hall")
#define ESID_Jd_MenTing                  (g_China ? (g_Big5 ? "����" : "����") : "Foyer")
#define ESID_Jd_ZhuWoShi                 (g_China ? (g_Big5 ? "������" : "������") : "Master Bedroom")
#define ESID_Jd_ZhuRenFang               (g_China ? (g_Big5 ? "���˷�" : "���˷�") : "Host Room")
#define ESID_Jd_WoShi                    (g_China ? (g_Big5 ? "����" : "����") : "Bedroom")
#define ESID_Jd_ShuiFang                 (g_China ? (g_Big5 ? "˯��" : "˯��") : "Bedroom")
#define ESID_Jd_FangJianA                (g_China ? (g_Big5 ? "����A" : "����A") : "RoomA")
#define ESID_Jd_FangJianB                (g_China ? (g_Big5 ? "����B" : "����B") : "RoomB")
#define ESID_Jd_FangJianC                (g_China ? (g_Big5 ? "����C" : "����C") : "RoomC")
#define ESID_Jd_FangJianD                (g_China ? (g_Big5 ? "����D" : "����D") : "RoomD")
#define ESID_Jd_FangJianE                (g_China ? (g_Big5 ? "����E" : "����E") : "RoomE")
#define ESID_Jd_ChuFang                  (g_China ? (g_Big5 ? "����" : "����") : "Kitchen")
#define ESID_Jd_ShuFang                  (g_China ? (g_Big5 ? "�鷿" : "�鷿") : "Study")
#define ESID_Jd_KeFang                   (g_China ? (g_Big5 ? "�ͷ�" : "�ͷ�") : "Rooms")
#define ESID_Jd_ZhuYuShi                 (g_China ? (g_Big5 ? "��ԡ��" : "��ԡ��") : "Master Bathroom")
#define ESID_Jd_YuShi                    (g_China ? (g_Big5 ? "ԡ��" : "ԡ��") : "Bathroom")
#define ESID_Jd_ErTongFang               (g_China ? (g_Big5 ? "��ͯ��" : "��ͯ��") : "Children Room")
#define ESID_Jd_GongRenFang              (g_China ? (g_Big5 ? "���˷�" : "���˷�") : "Servant Room")
#define ESID_Jd_DuoYongTuJian            (g_China ? (g_Big5 ? "����;��" : "����;��") : "Multi-purpose rooms")
#define ESID_Jd_QiJuShi                  (g_China ? (g_Big5 ? "�����" : "�����") : "Living Room")
#define ESID_Jd_YouLeShi                 (g_China ? (g_Big5 ? "������" : "������") : "Playroom")
#define ESID_Jd_ShuXiShi                 (g_China ? (g_Big5 ? "��ϴ��" : "��ϴ��") : "Toilet Room")
#define ESID_Jd_WeiShengJian             (g_China ? (g_Big5 ? "������" : "������") : "Toilet")
#define ESID_Jd_XieMaoJian               (g_China ? (g_Big5 ? "Ьñ��" : "Ьñ��") : "Home Locker Room")
#define ESID_Jd_GongZuoJian              (g_China ? (g_Big5 ? "������" : "������") : "Workplace")
#define ESID_Jd_DiXiaShi                 (g_China ? (g_Big5 ? "������" : "������") : "Basement")
#define ESID_Jd_None                     (g_China ? (g_Big5 ? "��" : "��") : "None")
#define ESID_Jd_Deng                     (g_China ? (g_Big5 ? "��" : "��") : "Light")
#define ESID_Jd_TiaoGuangDeng            (g_China ? (g_Big5 ? "�����" : "�����") : "Dimming Lights")
#define ESID_Jd_BaiChiDeng               (g_China ? (g_Big5 ? "�׳��" : "�׳��") : "Incandescent Lamp")
#define ESID_Jd_GuangGuan                (g_China ? (g_Big5 ? "���" : "���") : "Lightpipe")
#define ESID_Jd_DiaoDeng                 (g_China ? (g_Big5 ? "����" : "����") : "Chandelier")
#define ESID_Jd_HuaDeng                  (g_China ? (g_Big5 ? "����" : "����") : "Lantern")
#define ESID_Jd_BiDeng                   (g_China ? (g_Big5 ? "�ڵ�" : "�ڵ�") : "Wall Lamp")
#define ESID_Jd_SheDeng                  (g_China ? (g_Big5 ? "���" : "���") : "Spotlight")
#define ESID_Jd_TaiDeng                  (g_China ? (g_Big5 ? "̨��" : "̨��") : "Table Lamp")
#define ESID_Jd_LouDiDeng                (g_China ? (g_Big5 ? "��ص�" : "��ص�") : "Floor Lamp")
#define ESID_Jd_ZhaoMingDeng             (g_China ? (g_Big5 ? "������" : "������") : "Lighting Lamp")
#define ESID_Jd_ShiYingDeng              (g_China ? (g_Big5 ? "ʯӢ��" : "ʯӢ��") : "Quartz Lamp")
#define ESID_Jd_YeDeng                   (g_China ? (g_Big5 ? "ҹ��" : "ҹ��") : "Nightlights")
#define ESID_Jd_ZhuanshiDEng             (g_China ? (g_Big5 ? "װ�ε�" : "װ�ε�") : "Deco Lamp")
#define ESID_Jd_DianZhiSuo               (g_China ? (g_Big5 ? "������" : "������") : "E-Lock")
#define ESID_Jd_XiaoduWanGui             (g_China ? (g_Big5 ? "�������" : "�������") : "Sterilizer")
#define ESID_Jd_KongQiJinHua             (g_China ? (g_Big5 ? "��������" : "��������") : "Air Purifier")
#define ESID_Jd_YinShuiJi                (g_China ? (g_Big5 ? "��ˮ��" : "��ˮ��") : "Water Dispenser")
#define ESID_Jd_KongTiaoJi               (g_China ? (g_Big5 ? "�յ���" : "�յ���") : "A/C 1")
#define ESID_Jd_LenQiJi                  (g_China ? (g_Big5 ? "������" : "������") : "A/C 2")
#define ESID_Jd_CouYouJi                 (g_China ? (g_Big5 ? "���ͻ�" : "���ͻ�") : "A/C 3")
#define ESID_Jd_NuanFenJi                (g_China ? (g_Big5 ? "ů���" : "ů���") : "A/C 4")
#define ESID_Jd_DianReTan                (g_China ? (g_Big5 ? "����̺" : "����̺") : "Electric Blanket")
#define ESID_Jd_ReShuiLu                 (g_China ? (g_Big5 ? "��ˮ¯" : "��ˮ¯") : "Water Heater")
#define ESID_Jd_DianFanBao               (g_China ? (g_Big5 ? "�緹��" : "�緹��") : "Rice Cooker")
#define ESID_Jd_DianZhiWaGuo             (g_China ? (g_Big5 ? "�����߹�" : "�����߹�") : "Electric Stewpot")
#define ESID_Jd_WeiBoLu                  (g_China ? (g_Big5 ? "΢��¯" : "΢��¯") : "Microwave Oven")
#define ESID_Jd_XiYiJi                   (g_China ? (g_Big5 ? "ϴ�»�" : "ϴ�»�") : "Socket 6")
#define ESID_Jd_DianShiJi                (g_China ? (g_Big5 ? "���ӻ�" : "���ӻ�") : "Socket 1")
#define ESID_Jd_LuXiangJi                (g_China ? (g_Big5 ? "¼Ӱ��" : "¼���") : "VCR")
#define ESID_Jd_YingXiang                (g_China ? (g_Big5 ? "����" : "����") : "Stereo")
#define ESID_Jd_DianNao                  (g_China ? (g_Big5 ? "����" : "����") : "PC")
#define ESID_Jd_FengShan                 (g_China ? (g_Big5 ? "����" : "����") : "Fan")
#define ESID_Jd_CD                       (g_China ? (g_Big5 ? "CD" : "CD") : "CD")
#define ESID_Jd_LD                       (g_China ? (g_Big5 ? "LD" : "LD") : "LD")
#define ESID_Jd_VCD                      (g_China ? (g_Big5 ? "VCD" : "VCD") : "VCD")
#define ESID_Jd_DVD                      (g_China ? (g_Big5 ? "DVD" : "DVD") : "DVD")
#define ESID_Jd_ChaZuo1                  (g_China ? (g_Big5 ? "����1" : "����1") : "Socket 1")
#define ESID_Jd_ChaZuo2                  (g_China ? (g_Big5 ? "����2" : "����2") : "Socket 2")
#define ESID_Jd_ChaZuo3                  (g_China ? (g_Big5 ? "����3" : "����3") : "Socket 3")
#define ESID_Jd_ChaZuo4                  (g_China ? (g_Big5 ? "����4" : "����4") : "Socket 4")
#define ESID_Jd_ChaZuo5                  (g_China ? (g_Big5 ? "����5" : "����5") : "Socket 5")
#define ESID_Jd_XiaoDuSheBe              (g_China ? (g_Big5 ? "�����豸" : "�����豸") : "Disinfectant Apparatus")
#define ESID_Jd_SettingMusic             (g_China ? (g_Big5 ? "��������" : "��������") : "Background Music")
#define ESID_Jd_ChuangLian               (g_China ? (g_Big5 ? "����" : "����") : "Curtain")
#define ESID_Jd_JuanLian                 (g_China ? (g_Big5 ? "����" : "����") : "Shutter")
#define ESID_Jd_DianDongBuLian           (g_China ? (g_Big5 ? "�綯����" : "�綯����") : "Electric Curtain")
#define ESID_Jd_DianDongShaLian          (g_China ? (g_Big5 ? "�綯ɴ��" : "�綯ɴ��") : "Electric Gauze")
#define ESID_Jd_SceneNameSet             (g_China ? (g_Big5 ? "��������" : "��������") : "Scene Name")
#define ESID_Jd_SceneActionSet           (g_China ? (g_Big5 ? "��Ϊ����" : "��Ϊ����") : "Scene Action")
 
// �Խ���
#define ESID_MainCall_User				 (g_China ? (g_Big5 ? "����ס��" : "����ס��") : "Resident")
#define ESID_MainCall_FengJi			 (g_China ? (g_Big5 ? "���зֻ�" : "���зֻ�") : "Sub-terminal")
#define ESID_MainCenter_1				 (g_China ? (g_Big5 ? "��������1" : "��������1") : "CALL ADMIN1")
#define ESID_MainCenter_2				 (g_China ? (g_Big5 ? "��������2" : "��������2") : "CALL ADMIN2")
#define ESID_MainCenter_3				 (g_China ? (g_Big5 ? "��������3" : "��������3") : "CALL ADMIN3")
#define ESID_MainMonitor_Door			 (g_China ? (g_Big5 ? "������ǰ" : "������ǰ") : "Doorway")
#define ESID_MainMonitor_Stair			 (g_China ? (g_Big5 ? "�����ݿ�" : "�����ݿ�") : "Sec.Entry")
#define ESID_MainMonitor_Area			 (g_China ? (g_Big5 ? "��������" : "��������") : "Prim.Entry")
#define ESID_MainMonitor_Camera			 (g_China ? (g_Big5 ? "��������" : "��������") : "Monitor Community")
#define ESID_MainMonitor_Room			 (g_China ? (g_Big5 ? "�ҾӼ���" : "�ҾӼ���") : "RoomCamera")
#define ESID_DevManager                  (g_China ? (g_Big5 ? "����Ա��" : "����Ա��") : "Admin")
#define ESID_DevArea                     (g_China ? (g_Big5 ? "���ڻ�" : "���ڻ�") : "Prim.Entry")
#define ESID_DevStair                    (g_China ? (g_Big5 ? "�ݿڻ�" : "�ݿڻ�") : "Sec.Entry")
#define ESID_DevRoom                     (g_China ? (g_Big5 ? "���ڻ�" : "���ڻ�") : "Indoor Terminal")
#define ESID_DevPhone                    (g_China ? (g_Big5 ? "��ͨ�绰" : "��ͨ�绰") : "Phone")
#define ESID_DevDoorPhone                (g_China ? (g_Big5 ? "��ǰ��" : "��ǰ��") : "Camera")
#define ESID_DevDoorNet                  (g_China ? (g_Big5 ? "������ǰ��" : "������ǰ��") : "IP Camera")
#define ESID_DevGateWay                  (g_China ? (g_Big5 ? "��ͥ��·�ѵ�" : "��ͥ����") : "Gateway")
#define ESID_DevIPCamera                 (g_China ? (g_Big5 ? "IP Camera" : "IP Camera") : "IP Camera")
#define ESID_DevFenJi                    (g_China ? (g_Big5 ? "�ֻ�" : "�ֻ�") : "Extension")
#define ESID_DevMaster                   (g_China ? (g_Big5 ? "����" : "����") : "Main Phone")
#define ESID_RecordMiss                  (g_China ? (g_Big5 ? "δ��" : "δ��") : "Missed")
#define ESID_RecordIn                    (g_China ? (g_Big5 ? "�ѽ�" : "�ѽ�") : "Received")
#define ESID_RecordOut                   (g_China ? (g_Big5 ? "�Ѳ�" : "�Ѳ�") : "Dialled")
#define ESID_Right_Full                  (g_China ? (g_Big5 ? "ȫ��" : "ȫ��") : "Full Screen")
#define ESID_Inter_HangUP                (g_China ? (g_Big5 ? "�һ�" : "�һ�") : "Hang Up")
#define ESID_Inter_Answer                (g_China ? (g_Big5 ? "����" : "����") : "Answer")
#define ESID_Inter_Unlock                (g_China ? (g_Big5 ? "����" : "����") : "Open")
#define ESID_Inter_ReDial                (g_China ? (g_Big5 ? "�ز�" : "�ز�") : "Redial")
#define ESID_Right_Call                  (g_China ? (g_Big5 ? "����" : "����") : "Call")
#define ESID_Inter_Capture               (g_China ? (g_Big5 ? "����" : "ץ��") : "Capture")
#define ESID_Inter_Volume                (g_China ? (g_Big5 ? "����" : "����") : "Volume")
#define ESID_Inter_Next                  (g_China ? (g_Big5 ? "��һ��" : "��һ��") : "Next")
#define ESID_Inter_Talk                  (g_China ? (g_Big5 ? "ͨ��" : "ͨ��") : "Talk")
#define ESID_Inter_GetList               (g_China ? (g_Big5 ? "��ȡ�б�" : "��ȡ�б�") : "Obtain")
#define ESID_Inter_Snap                  (g_China ? (g_Big5 ? "����" : "����") : "Snap")
#define ESID_Inter_AudioAdd              (g_China ? (g_Big5 ? "����+" : "����+") : "Audio Add")
#define ESID_Inter_AudioDel              (g_China ? (g_Big5 ? "����-" : "����-") : "Audio Del")
#define ESID_Inter_StopMonitor           (g_China ? (g_Big5 ? "ֹͣ����" : "ֹͣ����") : "Stop")
#define ESID_Input_OK                    (g_China ? (g_Big5 ? "����" : "����") : "Enter")
#define ESID_Inter_EnterUserNo           (g_China ? (g_Big5 ? "������ס������" : "������ס������") : "Pls enter a number")
#define ESID_Inter_EnterFJNo             (g_China ? (g_Big5 ? "������1λ�ֻ�����" : "������1λ�ֻ�����") : "Pls enter a number")
#define ESID_Inter_WrongNo               (g_China ? (g_Big5 ? "����������!" : "����������!") : "Wrong number!")
#define ESID_Inter_NoNotFound            (g_China ? (g_Big5 ? "���޴˺�!" : "���޴˺�!") : "Number not found!")
#define ESID_Inter_Connecting            (g_China ? (g_Big5 ? "������..." : "������...") : "Connecting...")
#define ESID_Inter_BeCalling             (g_China ? (g_Big5 ? "������..." : "������...") : "Calling from...")
#define ESID_Inter_Calling               (g_China ? (g_Big5 ? "������..." : "������...") : "Calling...")
#define ESID_Inter_Talking               (g_China ? (g_Big5 ? "ͨ����..." : "ͨ����...") : "Talking...")
#define ESID_Inter_RecordHinting         (g_China ? (g_Big5 ? "������ʾ��..." : "������ʾ��...") : "Record Prompting...")
#define ESID_Inter_Recording             (g_China ? (g_Big5 ? "������..." : "������...") : "Recording...")
#define ESID_Inter_UnlockSuccess         (g_China ? (g_Big5 ? "�� �� �� ��!" : "�� �� �� ��!") : "Door Unlocked!")
#define ESID_Inter_UnlockFailed          (g_China ? (g_Big5 ? "�� �� ʧ ��!" : "�� �� ʧ ��!") : "Failed!")
#define ESID_Inter_CaptureSuccess        (g_China ? (g_Big5 ? "���� �� ��!" : "ץ �� �� ��!") : "OK!")
#define ESID_Inter_CaptureFailed         (g_China ? (g_Big5 ? "���� ʧ ��!" : "ץ �� ʧ ��!") : "Failed!")
#define ESID_Inter_ManagerNoSet          (g_China ? (g_Big5 ? "������δ����!" : "������δ����!") : "The admin unit IP not set yet!")
#define ESID_Inter_Search                (g_China ? (g_Big5 ? "������,���Ժ�..." : "������,���Ժ�...") : "Searching...")
#define ESID_Inter_Monitor               (g_China ? (g_Big5 ? "������..." : "������...") : "Monitoring...")
#define ESID_Inter_busy                  (g_China ? (g_Big5 ? "�Է�æ!" : "�Է�æ!") : "Busy Line!")
#define ESID_Inter_ConnFailed            (g_China ? (g_Big5 ? "����ʧ��!" : "����ʧ��!") : "Failed!")
#define ESID_Inter_SearchFailed          (g_China ? (g_Big5 ? "δ�������豸!" : "δ�������豸!") : "Failed!")
#define ESID_Inter_ElevAuthorize         (g_China ? (g_Big5 ? "���v" : "��Ȩ") : "Authorize")
#define ESID_Inter_ElevAuthOK            (g_China ? (g_Big5 ? "������Ȩ�ɹ�!" : "������Ȩ�ɹ�!") : "OK!")
#define ESID_Inter_ElevAuthFailed        (g_China ? (g_Big5 ? "������Ȩʧ��!" : "������Ȩʧ��!") : "Failed!")
#define ESID_Auto_Capture				 (g_China ? (g_Big5 ? "�Զ�����" : "�Զ�ץ��") : "Automatic capture")

// ��Ϣ����
#define ESID_Info_Sms                    (g_China ? (g_Big5 ? "����" : "����") : "Message")
#define ESID_Info_Centre_Des             (g_China ? (g_Big5 ? "�����ŷ���" : "���ķ�����") : "Center Server")
 
// ��������
#define ESID_Media_Lyly                  (g_China ? (g_Big5 ? "Ӱ��" : "Ӱ��") : "Video MSG")
#define ESID_Media_Snap                  (g_China ? (g_Big5 ? "��Ƭ" : "��Ƭ") : "Picture")
#define ESID_Media_Num                   (g_China ? (g_Big5 ? "�ܹ�" : "�ܹ�") : "Memory")
#define ESID_Media_Z                     (g_China ? (g_Big5 ? "��" : "��") : "Pcs")

// ��������
#define ESID_Bl_Jrly                     (g_China ? (g_Big5 ? "��������" : "��������") : "Recorder")
#define ESID_Bl_ClearScreen              (g_China ? (g_Big5 ? "���ӫĻ" : "�����Ļ") : "Clean Screen")

// �ҵ�����
#define ESID_Jd_Mode_Unused              (g_China ? (g_Big5 ? "δ���üҵ�ģ��" : "δ���üҵ�ģ��") : "Automation module inactivated")
#define ESID_Jd_Factory_Set              (g_China ? (g_Big5 ? "�ҵ糧������" : "�ҵ糧������") : "Brand Settings")
#define ESID_Jd_Factory                  (g_China ? (g_Big5 ? "�ҵ糧��" : "�ҵ糧��") : "Makers")
#define ESID_Jd_Factory_X10              (g_China ? (g_Big5 ? "X10" : "X10") : "X10")
#define ESID_Jd_Factory_Suobo            (g_China ? (g_Big5 ? "����" : "����") : "PLC-BUS")
#define ESID_Jd_Factory_ACBUS            (g_China ? (g_Big5 ? "TA-BUS" : "TA-BUS") : "TA-BUS")

// ��������
#define ESID_Bj_SOS                      (g_China ? (g_Big5 ? "��������" : "��������") : "SOS")
#define ESID_Bj_Fire                     (g_China ? (g_Big5 ? "����̽��" : "����̽��") : "Fire")
#define ESID_Bj_Gas                      (g_China ? (g_Big5 ? "��˹̽��" : "��˹̽��") : "Gas Leak")
#define ESID_Bj_Door                     (g_China ? (g_Big5 ? "��������" : "��������") : "Door")
#define ESID_Bj_Room                     (g_China ? (g_Big5 ? "����̽��" : "����̽��") : "Room")
#define ESID_Bj_Big_Window               (g_China ? (g_Big5 ? "����1����" : "����1����") : "Window1")
#define ESID_Bj_Window                   (g_China ? (g_Big5 ? "����2����" : "����2����") : "Window2")
#define ESID_Bj_Balcony                  (g_China ? (g_Big5 ? "��̨����" : "��̨����") : "Balcony")
#define ESID_Bj_Bf_Home                  (g_China ? (g_Big5 ? "�ڼ�" : "�ڼ�") : "Home")
#define ESID_Bj_Bf_Out                   (g_China ? (g_Big5 ? "���" : "���") : "Away")
#define ESID_Bj_Bf_Night                 (g_China ? (g_Big5 ? "ҹ��" : "ҹ��") : "Night")
#define ESID_Bj_Clean                    (g_China ? (g_Big5 ? "�����ʾ" : "�����ʾ") : "Reset")
#define ESID_Bj_Baojing_Record           (g_China ? (g_Big5 ? "������¼" : "������¼") : "Alarm Log")
#define ESID_Bj_Caozuo_Rec               (g_China ? (g_Big5 ? "������¼" : "������¼") : "Operation Log")
#define ESID_Bj_Alarm_Rec_Clear_F        (g_China ? (g_Big5 ? "��¼���ʧ��!" : "��¼���ʧ��!") : "Failed!")
#define ESID_Bj_Fangqu1					 (g_China ? (g_Big5 ? "����1" : "����1") : "Zone1")
#define ESID_Bj_Fangqu2					 (g_China ? (g_Big5 ? "����2" : "����2") : "Zone2")
#define ESID_Bj_Fangqu3					 (g_China ? (g_Big5 ? "����3" : "����3") : "Zone3")
#define ESID_Bj_Fangqu4					 (g_China ? (g_Big5 ? "����4" : "����4") : "Zone4")
#define ESID_Bj_Fangqu5					 (g_China ? (g_Big5 ? "����5" : "����5") : "Zone5")
#define ESID_Bj_Fangqu6					 (g_China ? (g_Big5 ? "����6" : "����6") : "Zone6")
#define ESID_Bj_Fangqu7					 (g_China ? (g_Big5 ? "����7" : "����7") : "Zone7")
#define ESID_Bj_Fangqu8					 (g_China ? (g_Big5 ? "����8" : "����8") : "Zone8")
#define ESID_Bj_Fangqu					 (g_China ? (g_Big5 ? "����" : "����") : "Zone")
#define ESID_Bj_Set_Err                  (g_China ? (g_Big5 ? "�����ڼ�ģʽ�½�������!" : "�����ڼ�ģʽ�½�������!") : "Please disarm the system first!")
#define ESID_Bj_Fangqu_Settings          (g_China ? (g_Big5 ? "��������" : "��������") : "Particular Parameters")
#define ESID_Bj_Security_Settings        (g_China ? (g_Big5 ? "��������" : "��������") : "Security Settings")
#define ESID_Bj_Security_Parameter       (g_China ? (g_Big5 ? "��������" : "��������") : "General Parameters") 
#define ESID_Bj_Tantou_Type              (g_China ? (g_Big5 ? "̽��������" : "̽ͷ����") : "Protection")
#define ESID_Bj_24Hour_Fangqu            (g_China ? (g_Big5 ? "24Сʱ����" : "24Сʱ����") : "24H Zone")
#define ESID_Bj_Normally_Open            (g_China ? (g_Big5 ? "̽��������" : "̽ͷ����") : "N/O")
#define ESID_Bj_Normally_Close           (g_China ? (g_Big5 ? "̽��������" : "̽ͷ����") : "N/C")
#define ESID_Bj_Alarm_Delay              (g_China ? (g_Big5 ? "�����ӳ�" : "�����ӳ�") : "Entry Delay")
#define ESID_Bj_None                     (g_China ? (g_Big5 ? "��" : "��") : "0 Sec")
#define ESID_Bj_Picture                  (g_China ? (g_Big5 ? "����" : "����") : "Picture")
#define ESID_Bj_Voice                    (g_China ? (g_Big5 ? "����" : "����") : "Sound")
#define ESID_Bj_Enable                   (g_China ? (g_Big5 ? "����" : "����") : "Activate")
#define ESID_Disable                     (g_China ? (g_Big5 ? "����" : "����") : "Deactivate")
#define ESID_Bj_30Seconds			     (g_China ? (g_Big5 ? "30��" : "30��") : "30Sec")
#define ESID_Bj_1Minute				     (g_China ? (g_Big5 ? "1��" : "1��") : "1Min")
#define ESID_Bj_2Minutes				 (g_China ? (g_Big5 ? "2��" : "2��") : "2Min")
#define ESID_Bj_3Minutes				 (g_China ? (g_Big5 ? "3��" : "3��") : "3Min")
#define ESID_Bj_4Minutes				 (g_China ? (g_Big5 ? "4��" : "4��") : "4Min")
#define ESID_Bj_5Minutes				 (g_China ? (g_Big5 ? "5��" : "5��") : "5Min")
#define ESID_Bj_10Minutes			     (g_China ? (g_Big5 ? "10��" : "10��") : "10Min")
#define ESID_Bj_15Minutes			     (g_China ? (g_Big5 ? "15��" : "15��") : "15Min")    
#define ESID_Bj_Alarm_Time               (g_China ? (g_Big5 ? "����ʱ��" : "����ʱ��") : "Alarm Duration")
#define ESID_Bj_Early_Warning_Time       (g_China ? (g_Big5 ? "Ԥ��ʱ��" : "Ԥ��ʱ��") : "Exit Delay")
#define ESID_Bj_Early_Warning_Voice      (g_China ? (g_Big5 ? "Ԥ����" : "Ԥ����") : "Exit Alert") 
#define ESID_Bj_Remote_sz                (g_China ? (g_Big5 ? "Զ������" : "Զ������") : "Remote Settings")
#define ESID_Bj_Remote_bf                (g_China ? (g_Big5 ? "Զ�̲���" : "Զ�̲���") : "Remote Arm(AWAY)")
#define ESID_Bj_Remote_cf                (g_China ? (g_Big5 ? "Զ�̳���" : "Զ�̳���") : "Remote Disarm(HOME)")
#define ESID_Bj_Remote_jf                (g_China ? (g_Big5 ? "Զ�ַ̾�" : "Զ�ַ̾�") : "Remote Arm(NIGHT)")
#define ESID_Bj_Already_Bufang           (g_China ? (g_Big5 ? "����Ӧ�ķ����ɽ��е�������" : "����Ӧ�ķ����ɽ��е�������") : "Tap a zone to arm it")
#define ESID_Bj_Report_Type_Chufa        (g_China ? (g_Big5 ? "��������" : "��������") : "Triggerred Alarm")
#define ESID_Bj_Report_Type_Qiuzhu       (g_China ? (g_Big5 ? "��������" : "��������") : "HELP")
#define ESID_Bj_Alarm                    (g_China ? (g_Big5 ? "����" : "����") : "Alarm")
#define ESID_Bj_Report_Type_Jinru        (g_China ? (g_Big5 ? "���뱨��" : "���뱨��") : "Alarm")
#define ESID_Bj_Fangquchufa              (g_China ? (g_Big5 ? "��������" : "��������") : "Zone Triggered!") 
#define ESID_Bj_Bengjikongzhi            (g_China ? (g_Big5 ? "��������" : "��������") : "Local Control") 
#define ESID_Bj_Fengjikongzhi            (g_China ? (g_Big5 ? "�ֻ�����" : "�ֻ�����") : "Sub-phone Control") 
#define ESID_Bj_Query_Del_Rec_One        (g_China ? (g_Big5 ? "ȷ��ɾ���ü�¼?" : "ȷ��ɾ���ü�¼?") : "Sure to delete it?")  
#define ESID_Bj_Query_Del_Rec_All        (g_China ? (g_Big5 ? "ȷ��������м�¼?" : "ȷ��������м�¼?") : "Sure to delete all?") 
#define ESID_Bj_Chufa                    (g_China ? (g_Big5 ? "����" : "����") : "Triggerred")
#define ESID_Bj_Cannot_Bufang            (g_China ? (g_Big5 ? "���ܲ���" : "���ܲ���") : "Cannot be armed!")
#define ESID_InputBox_Psw_Err            (g_China ? (g_Big5 ? "�������,����������" : "�������,����������") : "Wrong Password!")
#define ESID_Isolation                   (g_China ? (g_Big5 ? "����" : "����") : "Bypass")
#define ESID_AfJoint_Tk_Chefang          (g_China ? (g_Big5 ? "�ݿ�ˢ������" : "�ݿ�ˢ������") : "Disarm By Card(sec.entry)") 
#define ESID_AfJoint_Mk_Chefang          (g_China ? (g_Big5 ? "��ǰˢ������" : "��ǰˢ������") : "Disarm By Card(doorway)") 
#define ESID_AfJoint_DoorRing            (g_China ? (g_Big5 ? "�ڰ˷�������ǰ��" : "�ڰ˷�������ǰ��") : "Enable zone 8 to work as doorbell")
#define ESID_AfJoint_ScenBf              (g_China ? (g_Big5 ? "���������龰ģʽ" : "���������龰ģʽ") : "Activate scene mode X under the AWAY mode")
#define ESID_AfJoint_ScenCf              (g_China ? (g_Big5 ? "���������龰ģʽ" : "���������龰ģʽ") : "Activate scene mode X under the HOME mode")
#define ESID_Af_Tel_Num1                 (g_China ? (g_Big5 ? "��������1:" : "��������1:") : "Phone No.1")
#define ESID_Af_Tel_Num2                 (g_China ? (g_Big5 ? "��������2:" : "��������2:") : "Phone No.2")
#define ESID_Af_Msg_Num1                 (g_China ? (g_Big5 ? "���ź���1:" : "���ź���1:") : "MSG No.1")
#define ESID_Af_Msg_Num2                 (g_China ? (g_Big5 ? "���ź���2:" : "���ź���2:") : "MSG No.2")
#define ESID_Af_Mode_Unused              (g_China ? (g_Big5 ? "δ���ñ���ģ��" : "δ���ñ���ģ��") : "Alarm module inactivated!")
#define ESID_Af_Alarm_Cannot_Bf          (g_China ? (g_Big5 ? "���ڱ������ܲ���" : "���ڱ������ܲ���") : "Alarming now. Cannot arm!")
#define ESID_Af_Touch_Cannot_Bf          (g_China ? (g_Big5 ? "�����������ܲ���" : "�����������ܲ���") : "Zone triggerred.Cannot arm!")
#define ESID_Af_Alarm_Cannot_Qc          (g_China ? (g_Big5 ? "���ڱ������ܲ���" : "���ڱ������ܲ���") : "Zone triggerred.Cannot operate!")

// ԤԼ����
#define ESID_Jd_Yuyue                    (g_China ? (g_Big5 ? "ԤԼ" : "ԤԼ") : "Timer")
#define ESID_Jd_Yuyue_Manager            (g_China ? (g_Big5 ? "ԤԼ����" : "ԤԼ����") : "Timing Control")
#define ESID_Jd_Yuyue_All                (g_China ? (g_Big5 ? "ȫ��" : "ȫ��") : "All")
#define ESID_Jd_Yuyue_DelOne             (g_China ? (g_Big5 ? "ȷ��ɾ����ԤԼ?" : "ȷ��ɾ����ԤԼ?") : "Sure to delete it?")
#define ESID_Jd_Yuyue_Add_Err            (g_China ? (g_Big5 ? "ԤԼ���ܳ���20��!" : "ԤԼ���ܳ���20��!") : "Memory Full!")
#define ESID_Jd_Yuyue_EveryDay           (g_China ? (g_Big5 ? "ÿ��" : "ÿ��") : "Daily")
#define ESID_Jd_Yuyue_EveryWeek          (g_China ? (g_Big5 ? "ÿ��" : "ÿ��") : "Weekly")
#define ESID_Jd_Yuyue_EveryMonth         (g_China ? (g_Big5 ? "ÿ��" : "ÿ��") : "Monthly")
#define ESID_Jd_Yuyue_Day                (g_China ? (g_Big5 ? "��" : "��") : "Day")
#define ESID_Jd_Yuyue_Action_Open        (g_China ? (g_Big5 ? "��" : "��") : "ON")
#define ESID_Jd_Yuyue_Action_Close       (g_China ? (g_Big5 ? "��" : "��") : "OFF")
#define ESID_Jd_Yuyue_Type               (g_China ? (g_Big5 ? "����" : "����") : "Type")
#define ESID_Jd_Yuyue_Name               (g_China ? (g_Big5 ? "����" : "����") : "Name")
#define ESID_Jd_Yuyue_Status             (g_China ? (g_Big5 ? "״̬" : "״̬") : "Status")
#define ESID_Jd_Yuyue_Repeat             (g_China ? (g_Big5 ? "�ظ���ʽ" : "�ظ���ʽ") : "Repeat")
#define ESID_Jd_Yuyue_StartTime          (g_China ? (g_Big5 ? "��ʼʱ��" : "��ʼʱ��") : "Start Time")

// ������������
#define ESID_Rtsp_IPC                    (g_China ? (g_Big5 ? "��·IPC" : "����IPC") : "Net IPC")
#define ESID_Rtsp_Name                   (g_China ? (g_Big5 ? "�豸����" : "�豸����") : "Device Name")
#define ESID_Rtsp_Port                   (g_China ? (g_Big5 ? "PORT" : "PORT") : "PORT")
#define ESID_Rtsp_Channel                (g_China ? (g_Big5 ? "��Ƶͨ��" : "��Ƶͨ��") : "Video Channel")
#define ESID_Rtsp_User                   (g_China ? (g_Big5 ? "�û���" : "�û���") : "User")
#define ESID_Rtsp_Password               (g_China ? (g_Big5 ? "����" : "����") : "Password")
#define ESID_Rtsp_IP                 	 (g_China ? (g_Big5 ? "IP��ַ" : "IP��ַ") : "IP Address")
#define ESID_Rtsp_Factory                (g_China ? (g_Big5 ? "��������" : "��������") : "Manufacturer")

// �ҾӼ�������
#define ESID_Rtsp_Indoor_Camera          (g_China ? (g_Big5 ? "������Ӱ��" : "��������ͷ") : "Indoor Camera")
#define ESID_Rtsp_Enable_Indoor_Camera   (g_China ? (g_Big5 ? "����������Ӱ��" : "������������ͷ") : "Enable Indoor Camera")
#define ESID_Rtsp_PTZ                	 (g_China ? (g_Big5 ? "����PTZ����" : "����PTZ����") : "Enable PTZ Control")
#define ESID_Rtsp_Direc				 	 (g_China ? (g_Big5 ? "����" : "����") : "Direct")
#define ESID_Rtsp_Scaling				 (g_China ? (g_Big5 ? "����" : "����") : "Scaling")
#define ESID_Rtsp_Point				     (g_China ? (g_Big5 ? "Ԥ�õ�" : "Ԥ�õ�") : "Point")
#define ESID_Rtsp_Point1				 (g_China ? (g_Big5 ? "Ԥ�õ�1" : "Ԥ�õ�1") : "Point 1")
#define ESID_Rtsp_Point2				 (g_China ? (g_Big5 ? "Ԥ�õ�2" : "Ԥ�õ�2") : "Point 2")
#define ESID_Rtsp_Point3				 (g_China ? (g_Big5 ? "Ԥ�õ�3" : "Ԥ�õ�3") : "Point 3")
#define ESID_Rtsp_Point4				 (g_China ? (g_Big5 ? "Ԥ�õ�4" : "Ԥ�õ�4") : "Point 4")

//������ǰ������
#ifdef _ADD_BLUETOOTH_DOOR_
#define ESID_Ble_Door_Unused1       	 (g_China ? (g_Big5 ? "δ����������ǰ��һ!" : "δ����������ǰ��һ!") : "Bluetooth Camera 1 Inactivated!")
#define ESID_Ble_Door_Unused2       	 (g_China ? (g_Big5 ? "δ����������ǰ����!" : "δ����������ǰ����!") : "Bluetooth Camera 2 Inactivated!")
#define ESID_Ble_Door_First_Record 		 (g_China ? (g_Big5 ? "��ǰ��һ��¼" : "��ǰ��һ��¼") : "Camera 1 Register")
#define ESID_Ble_Door_Second_Record 	 (g_China ? (g_Big5 ? "��ǰ������¼" : "��ǰ������¼") : "Camera 2 Register")
#define ESID_Ble_Door_Operate_Record 	 (g_China ? (g_Big5 ? "������¼" : "������¼") : "Operation Log")
#define ESID_Ble_Door_Lock_Record  		 (g_China ? (g_Big5 ? "������¼" : "������¼") : "Unlock Log")
#define ESID_Ble_Door_24H_Record   		 (g_China ? (g_Big5 ? "24Сʱ��¼" : "24Сʱ��¼") : "24-hour Log")
#define ESID_Ble_Door_History_Record 	 (g_China ? (g_Big5 ? "��ʷ��¼" : "��ʷ��¼") : "History Log")
#define ESID_Ble_Door_Snap_Record	 	 (g_China ? (g_Big5 ? "���ռ�¼" : "���ռ�¼") : "Snapshot Log")
#define ESID_Ble_Door_First        		 (g_China ? (g_Big5 ? "������ǰ��һ" : "������ǰ��һ") : "Bluetooth Camera 1")
#define ESID_Ble_Door_Second       		 (g_China ? (g_Big5 ? "������ǰ����" : "������ǰ����") : "Bluetooth Camera 2")
#define ESID_Set_Unused              	 (g_China ? (g_Big5 ? "δ����" : "δ����") : "Not Enabled")
#define ESID_Ble_Door_Obtain       		 (g_China ? (g_Big5 ? "��ȡ��,���Ժ�..." : "��ȡ��,���Ժ�...") : "Obtain...")
#define ESID_Ble_Door_Obtain_Err   		 (g_China ? (g_Big5 ? "��ȡ��¼ʧ��" : "��ȡ��¼ʧ��") : "Obtain Register Error")
#define ESID_Ble_Door_Lock_Key  	 	 (g_China ? (g_Big5 ? "��е����" : "��е����") : "Mechanical unlocking")
#define ESID_Ble_Door_Lock_Pwd	 	 	 (g_China ? (g_Big5 ? "���뿪��" : "���뿪��") : "Password access")
#define ESID_Ble_Door_Lock_Card    		 (g_China ? (g_Big5 ? "ˢ������" : "ˢ������") : "Card access")
#define ESID_Ble_Door_Lock_Finger  		 (g_China ? (g_Big5 ? "ָ�ƿ���" : "ָ�ƿ���") : "Fingerprint recognition")
#define ESID_Ble_Door_Lock_Face    		 (g_China ? (g_Big5 ? "����ʶ����" : "����ʶ����") : "Face recognition")
#define ESID_Ble_Door_Lock_Guest   		 (g_China ? (g_Big5 ? "�ÿͿ���" : "�ÿͿ���") : "Unlock by pressing open key")
#define ESID_Ble_Door_Lock_Monitor 		 (g_China ? (g_Big5 ? "���ӿ���" : "���ӿ���") : "Unlock when monitoring")
#define ESID_Ble_Door_Lock_Photo   		 (g_China ? (g_Big5 ? "�ֻ�����" : "�ֻ�����") : "Unlock via mobile phone")
#define ESID_Ble_Door_Lock_Linshi  		 (g_China ? (g_Big5 ? "��ʱ��Ȩ����" : "��ʱ��Ȩ����") : "Temporary authorized access")
#define ESID_Ble_Door_Lock_Custom  		 (g_China ? (g_Big5 ? "�Զ���" : "�Զ���") : "Custom")
#define ESID_Ble_Door_Operate_Del  		 (g_China ? (g_Big5 ? "ɾ���û�" : "ɾ���û�") : "Delete user account")
#define ESID_Ble_Door_Operate_Open 		 (g_China ? (g_Big5 ? "�����ų���" : "�����ų���") : "N/O on")
#define ESID_Ble_Door_Operate_Unopen 	 (g_China ? (g_Big5 ? "ȡ���ų���" : "ȡ���ų���") : "N/O off")
#define ESID_Ble_Door_Operate_Ring 		 (g_China ? (g_Big5 ? "����" : "����") : "Ringtone")
#define ESID_Ble_Door_Dev_Host 		 	 (g_China ? (g_Big5 ? "����" : "����") : "Device")
#define ESID_Ble_Door_Dev_Door 	 		 (g_China ? (g_Big5 ? "��ǰ��" : "��ǰ��") : "Camera")
#define ESID_Ble_Door_Dev_Photo 		 (g_China ? (g_Big5 ? "�ֻ�" : "�ֻ�") : "Mobile phone")
#define ESID_Ble_Door_ManInduction 	     (g_China ? (g_Big5 ? "�����Ӧ����" : "�����Ӧ����") : "Snap by human induction")
#define ESID_Ble_Door_ThreeErr		 	 (g_China ? (g_Big5 ? "��β�����������" : "��β�����������") : "Five Times Operate Error Snap")
#define ESID_Ble_Door_TamperAlarm 	 	 (g_China ? (g_Big5 ? "���𱨾�����" : "���𱨾�����") : "Anti demolition alarm snap")
#define ESID_Ble_Door_Visitor 	 	 	 (g_China ? (g_Big5 ? "�ÿͺ�������" : "�ÿͺ�������") : "Visitors call snap")
#define ESID_Ble_Door1_Snap_Record 		 (g_China ? (g_Big5 ? "��ǰ��һ���ռ�¼" : "��ǰ��һ���ռ�¼") : "Camera 1 Snapshot Record")
#define ESID_Ble_Door2_Snap_Record 		 (g_China ? (g_Big5 ? "��ǰ�������ռ�¼" : "��ǰ�������ռ�¼") : "Camera 2 Snapshot Record")
#define ESID_Ble_Door1_Lock24h_Record 	 (g_China ? (g_Big5 ? "��ǰ��һ24Сʱ������¼" : "��ǰ��һ24Сʱ������¼") : "Camera 1 24H Unlock Record")
#define ESID_Ble_Door2_Lock24h_Record 	 (g_China ? (g_Big5 ? "��ǰ����24Сʱ������¼" : "��ǰ����24Сʱ������¼") : "Camera 2 24H Unlock Record")
#define ESID_Ble_Door1_LockHis_Record 	 (g_China ? (g_Big5 ? "��ǰ��һ��ʷ������¼" : "��ǰ��һ��ʷ������¼") : "Camera 1 Unlock Record")
#define ESID_Ble_Door2_LockHis_Record 	 (g_China ? (g_Big5 ? "��ǰ������ʷ������¼" : "��ǰ������ʷ������¼") : "Camera 2 Unlock Record")
#define ESID_Ble_Door1_Operate24h_Record (g_China ? (g_Big5 ? "��ǰ��һ24Сʱ������¼" : "��ǰ��һ24Сʱ������¼") : "Camera 1 24H Operate Record")
#define ESID_Ble_Door2_Operate24h_Record (g_China ? (g_Big5 ? "��ǰ����24Сʱ������¼" : "��ǰ����24Сʱ������¼") : "Camera 2 24H Operate Record")
#define ESID_Ble_Door1_OperateHis_Record (g_China ? (g_Big5 ? "��ǰ��һ��ʷ������¼" : "��ǰ��һ��ʷ������¼") : "Camera 1 Operate Record")
#define ESID_Ble_Door2_OperateHis_Record (g_China ? (g_Big5 ? "��ǰ������ʷ������¼" : "��ǰ������ʷ������¼") : "Camera 1 Operate Record")
#define ESID_Ble_Door_Room_List 		 (g_China ? (g_Big5 ? "���ڻ����б�" : "���ڻ����б�") : "Indoor Unit information list")
#define ESID_Ble_Door_DNS_Address 		 (g_China ? (g_Big5 ? "DNS��ַ" : "DNS��ַ") : "DNS Address")
#endif


typedef enum
{
	// �������ַ�ID
	SID_NULL = 1000,
	SID_MainAlarm,
	SID_MainCall,
	SID_MainInfo,
	SID_MainCenter,
	SID_MainMonitor,	
	SID_MainRecord,
	SID_MainLyLy,
	SID_MainBianli,	
    SID_MainBianLi_Dianti,
	SID_MainSet,
    SID_MainEcontrol,
    SID_MainMedia,

    // ���������ַ�ID
    SID_Unregistered,
    SID_Registered,
    SID_Touch_Calibration,          
    SID_Touch_Disp_Chk_Hit,          
    SID_clearscreenhit,            
    SID_Right_Add,                  
    SID_Right_Edit,                  
    SID_Right_Del,                  
    SID_Right_Clear,                 
    SID_Right_Save,                
    SID_Right_View,                
    SID_Right_Sure,                 
    SID_Right_desk,                 
    SID_Right_Rec,
    SID_Right_Listen,                
	SID_Right_Play,               
	SID_Right_Stop,                
	SID_Right_Pause,
	SID_Right_Updata,                
	SID_Right_Select,
	SID_Right_Input,
	SID_Week_Sun,                   
	SID_Week_Mon,                    
	SID_Week_Tue,                   
	SID_Week_Wed,                    
	SID_Week_Thu,
	SID_Week_Fri,          
	SID_Week_Sat,                
	SID_Time_Sec,                   
	SID_Time_Hour,                  
	SID_Time_Min, 
	SID_Time_Never,
	SID_Set_Time,                  
	SID_Set_Mode,                 
	SID_Set_Used,                   
	SID_Save_OK,                
	SID_Save_ERR, 
	SID_Msg_Yes,                     
	SID_Msg_No,                    
	SID_Msg_Format,            
	SID_Oper_OK,                  
	SID_Oper_ERR,                 
	SID_Msg_Calibration,             
	SID_Msg_OldPass_Err,             
	SID_Msg_SamePass_Err,            
	SID_Msg_InputBox_Psw_Err,       
	SID_Msg_Jrly_rec_tmp,
	SID_Msg_Jrly_rec_full,           
	SID_Msg_Connect_Outtime,         
	SID_Msg_Alarm_Hit,              
	SID_Msg_Info_Hit,               
	SID_Msg_CallIn_Hit,            
	SID_Msg_FactoryMode,             
	SID_Msg_Cell_Err,               
	SID_Msg_Stair_Err,             
	SID_Msg_Room_Err,                
	SID_Msg_RuleAll_Err,           
	SID_Msg_Len_Err,              
	SID_Msg_RoomNo_Err,              
	SID_Msg_Recover_OK,             
	SID_Msg_Exit,                   
	SID_Msg_Dianti_Hit1,            
	SID_Msg_Dianti_Hit2,            
	SID_Msg_Reset,                   
	SID_Msg_JD_Is_Updata,            
	SID_Msg_JD_Is_Updata1,           
	SID_Msg_JD_Updataing,
	SID_Msg_JD_Unbind,               
	SID_Msg_Create_BindCode,
	SID_IP_Unbind,
	SID_IP_Bind,                    
	SID_Msg_Jd_State_Updata,         
	SID_IP_Online,                   
	SID_IP_Unline,                  
	SID_IP_Con_Addr,                 
	SID_Jd_Deng1,                    
	SID_Jd_Deng2,                    
	SID_Jd_Deng3,                    
	SID_Jd_Deng4,                    
	SID_Jd_Deng5,                   
	SID_Jd_Deng6,                 
	SID_Jd_Deng7,                  
	SID_Jd_Deng8,                    
	SID_Jd_Deng9,                   
	SID_Jd_Deng10,                   
	SID_Jd_TiaoGuangDeng1,           
	SID_Jd_TiaoGuangDeng2,
	SID_Jd_TiaoGuangDeng3,           
	SID_Jd_TiaoGuangDeng4,           
	SID_Jd_TiaoGuangDeng5,          
	SID_Jd_TiaoGuangDeng6,           
	SID_Jd_TiaoGuangDeng7,          
	SID_Jd_TiaoGuangDeng8,          
	SID_Jd_TiaoGuangDeng9,           
	SID_Jd_TiaoGuangDeng10,          
	SID_Jd_BaiChiDeng1,              
	SID_Jd_BaiChiDeng2,             
	SID_Jd_BaiChiDeng3,             
	SID_Jd_BaiChiDeng4,             
	SID_Jd_BaiChiDeng5,             
	SID_Jd_BaiChiDeng6,              
	SID_Jd_BaiChiDeng7,           
	SID_Jd_BaiChiDeng8,            
	SID_Jd_BaiChiDeng9,              
	SID_Jd_BaiChiDeng10,
	SID_Jd_GuangGuan1,               
	SID_Jd_GuangGuan2,               
	SID_Jd_GuangGuan3,               
	SID_Jd_GuangGuan4,               
	SID_Jd_GuangGuan5,               
	SID_Jd_GuangGuan6,               
	SID_Jd_GuangGuan7,              
	SID_Jd_GuangGuan8,               
	SID_Jd_GuangGuan9,               
	SID_Jd_GuangGuan10,            
	SID_Jd_DiaoDeng1,                
	SID_Jd_DiaoDeng2,                
	SID_Jd_DiaoDeng3,                
	SID_Jd_DiaoDeng4,                
	SID_Jd_DiaoDeng5,               
	SID_Jd_DiaoDeng6,                
	SID_Jd_DiaoDeng7,                
	SID_Jd_DiaoDeng8,                
	SID_Jd_DiaoDeng9,                
	SID_Jd_DiaoDeng10,
	SID_Jd_HuaDeng1,               
	SID_Jd_HuaDeng2,                
	SID_Jd_HuaDeng3,                 
	SID_Jd_HuaDeng4,                
	SID_Jd_HuaDeng5,                 
	SID_Jd_HuaDeng6,                
	SID_Jd_HuaDeng7,               
	SID_Jd_HuaDeng8,                 
	SID_Jd_HuaDeng9,                 
	SID_Jd_HuaDeng10,                
	SID_Jd_BiDeng1,                  
	SID_Jd_BiDeng2,                  
	SID_Jd_BiDeng3,                  
	SID_Jd_BiDeng4,                  
	SID_Jd_BiDeng5,                 
	SID_Jd_BiDeng6,                  
	SID_Jd_BiDeng7,                 
	SID_Jd_BiDeng8,                  
	SID_Jd_BiDeng9,                  
	SID_Jd_BiDeng10,
	SID_Jd_SheDeng1,
	SID_Jd_SheDeng2,
	SID_Jd_SheDeng3,
	SID_Jd_SheDeng4,
	SID_Jd_SheDeng5,
	SID_Jd_SheDeng6,
	SID_Jd_SheDeng7,
	SID_Jd_SheDeng8,
	SID_Jd_SheDeng9,
	SID_Jd_SheDeng10,
	SID_Jd_TaiDeng1,
	SID_Jd_TaiDeng2,
	SID_Jd_TaiDeng3,
	SID_Jd_TaiDeng4,
	SID_Jd_TaiDeng5,
	SID_Jd_TaiDeng6,
	SID_Jd_TaiDeng7,
	SID_Jd_TaiDeng8,
	SID_Jd_TaiDeng9,
	SID_Jd_TaiDeng10,
	SID_Jd_LouDiDeng1,             
	SID_Jd_LouDiDeng2,               
	SID_Jd_LouDiDeng3,          
	SID_Jd_LouDiDeng4,              
	SID_Jd_LouDiDeng5,               
	SID_Jd_LouDiDeng6,               
	SID_Jd_LouDiDeng7,               
	SID_Jd_LouDiDeng8,             
	SID_Jd_LouDiDeng9,               
	SID_Jd_LouDiDeng10,            
	SID_Jd_ZhaoMingDeng1,           
	SID_Jd_ZhaoMingDeng2,           
	SID_Jd_ZhaoMingDeng3,         
	SID_Jd_ZhaoMingDeng4,           
	SID_Jd_ZhaoMingDeng5,            
	SID_Jd_ZhaoMingDeng6,           
	SID_Jd_ZhaoMingDeng7,            
	SID_Jd_ZhaoMingDeng8,           
	SID_Jd_ZhaoMingDeng9,
	SID_Jd_ZhaoMingDeng10,
	SID_Jd_ShiYingDeng1,             
	SID_Jd_ShiYingDeng2,             
	SID_Jd_ShiYingDeng3,            
	SID_Jd_ShiYingDeng4,             
	SID_Jd_ShiYingDeng5,       
	SID_Jd_ShiYingDeng6,             
	SID_Jd_ShiYingDeng7,           
	SID_Jd_ShiYingDeng8,             
	SID_Jd_ShiYingDeng9,            
	SID_Jd_ShiYingDeng10,           
	SID_Jd_YeDeng1,                  
	SID_Jd_YeDeng2,                 
	SID_Jd_YeDeng3,                  
	SID_Jd_YeDeng4,                  
	SID_Jd_YeDeng5,                 
	SID_Jd_YeDeng6,               
	SID_Jd_YeDeng7,                  
	SID_Jd_YeDeng8,                  
	SID_Jd_YeDeng9,                  
	SID_Jd_YeDeng10,
	SID_Jd_ZhuanshiDEng1,            
	SID_Jd_ZhuanshiDEng2,            
	SID_Jd_ZhuanshiDEng3,            
	SID_Jd_ZhuanshiDEng4,            
	SID_Jd_ZhuanshiDEng5,           
	SID_Jd_ZhuanshiDEng6,            
	SID_Jd_ZhuanshiDEng7,            
	SID_Jd_ZhuanshiDEng8,           
	SID_Jd_ZhuanshiDEng9,     
	SID_Jd_ZhuanshiDEng10,

	// �������ַ�ID
	SID_Set_Menu_System,             
	SID_Set_Menu_Project,           
	SID_Set_Menu_Alarm,              
	SID_Set_Menu_User,               
	SID_Set_System_language,         
	SID_Set_System_Time,           
	SID_Set_System_Desk,             
	SID_Set_System_Screen,          
	//SID_Set_System_Light,            
	SID_Set_System_Storage,          
	SID_Set_System_Info,             
	SID_Set_Prj_Pass,                
	SID_Set_Prj_Alarm,               
	SID_Set_Prj_Net,            
	SID_Set_Prj_ExtMode,            
	SID_Set_Prj_DevNo,            
	SID_Set_Prj_NetDoor,             
	SID_Set_Prj_Default,          
	SID_Set_Prj_JiaDian,            
	//SID_Set_Prj_Mic,
	//SID_Set_Prj_Mic_Db,             
	SID_Set_Prj_Set_Rtsp,            
	SID_Set_Prj_Set_IPModule,        
	SID_Set_Alarm_UserPwd,           
	SID_Set_Alarm_DoorPwd,          
	SID_Set_Alarm_AfLink,            
	SID_Set_Alarm_AfGeLi,           
	SID_Set_Alarm_AfJuFang,        
	SID_Set_UAlarm_Remote,           
	SID_Set_Alarm_MsgNum,           
	//SID_Set_Alarm_TelNum,           
	SID_Set_User_Sound,              
	SID_Set_User_Volume,            
	SID_Set_User_NoFace,             
	SID_Set_User_LyLy,               
	SID_Set_User_PT,                 
	SID_Set_Unreg,                   
	SID_Set_Reg_Code,                
	SID_Set_Reging,                  
	SID_Set_Prj_Net_HostIP,
	SID_Set_Prj_Net_HostNetMask,        
	SID_Set_Prj_Net_HostGateWay,     
	SID_Set_Prj_Net_CenterSever,     
	SID_Set_Prj_Net_ManageIP1,  
	SID_Set_Prj_Net_ManageIP2,       
	SID_Set_Prj_Net_ManageIP3,  
	SID_Set_Prj_Net_AurineSever, 
	SID_Set_Prj_Net_AurineElevator,   
	SID_Set_Prj_Net_Rtsp,  	
	SID_Set_Prj_Net_Stair,  
	SID_Set_Prj_Net_IPModule_IP,        
	SID_Set_Prj_Net_IPModule_Code,        
	SID_Set_Dev_Rule,                
	SID_Set_Dev_Stair_len,           
	SID_Set_Dev_Room_len,           
	SID_Set_Dev_Cell_len,           
	SID_Set_Dev_UseCell,             
	SID_Set_Dev_BIT,                 
	SID_Set_Ext_Alarm,              
	SID_Set_Ext_JiaDian,           
	SID_Set_Ext_Stair,
	SID_Set_Language,
	#ifdef _TCPTO485_ELEVATOR_MODE_
	SID_Set_TCP485Elevator,
	#endif
    
    // ������ǰ�������ַ�ID
    SID_Net_Door_First_R,
	SID_Net_Door_Second_R,
    SID_Net_Door_First_A,
	SID_Net_Door_Second_A,
	SID_Net_Door,
	SID_Net_Door_First,          
	SID_Net_Door_Second,           
	SID_Net_Door_IP,                 
	SID_Net_Door_Sub,                
	SID_Net_Door_GateWay, 
	SID_Net_Door_MAC,  
	SID_Net_Door_GetMAC,                          
	SID_Net_Door_NetParam,          
	SID_Net_Door_LockType,           
	SID_Net_Door_CardMan,            
	SID_Net_Door_SysInfo,          
	SID_Net_Door_Other_Set,        
	SID_Net_Door_Open,              
	SID_Net_Door_Close,            
	SID_Net_Door_LTime_Mh,          
	SID_Net_Door_LockTime,
	SID_Net_Door_Pic_Up,          
	SID_Net_Door_Remote_Moniter,    
	SID_Net_Door_Add_Card,           
	SID_Net_Door_Del_Card,           
	SID_Net_Door_Unused_First,      
	SID_Net_Door_Unused_Second,    
	SID_Net_Door_Pls_Add_Card,       
	SID_Net_Door_Sure_Del_Card,      
	SID_Net_Door_Video_Fmt,          
	SID_Set_Info_HW,                 
	SID_Set_Info_SF,                
	SID_Set_Info_SDK,              
	SID_Set_Info_HostMAC,           
	SID_Set_Info_Room,               
	SID_Set_Timer_Wanl,              
	SID_Storage_Format,              
	SID_Storage_Pic,                 
	SID_Set_Pass_Server,             
	SID_Set_Pass_DoorUser,          
	SID_Set_Pass_DoorServer, 
	SID_Set_Pass_Old,                
	SID_Set_Pass_New,               
	SID_Set_Pass_Query,              
	SID_Set_volume_ring,            
	SID_Set_volume_talk,             
	SID_Set_volume_key,              
	SID_Set_ring_Stair,              
	SID_Set_ring_Area,               
	SID_Set_ring_Door,              
	SID_Set_ring_Center,             
	SID_Set_ring_Room,               
	SID_Set_ring_fenji,              
	SID_Set_ring_Info,              
	SID_Set_ring_alarm,              
	SID_Set_ring,                   
	SID_Set_hit,                    
	SID_Set_Lyly_Mode_Audio,         
	SID_Set_Lyly_Mode_Both,         
	SID_Set_Lyly_Mode_Video,         
	SID_Set_Lyly_Link1,              
	SID_Set_Lyly_Link2,             
	SID_Set_Lyly_Link3,              
	SID_Set_Lyly_default_tip,        
	SID_Set_Lyly_record_tip,         
	SID_Set_Screen_InTime,           
	SID_Set_Screen_Lcd,
	SID_Set_Query_Del_All,
	SID_Set_Tips_Fail,
	
	// IPЭ��ת������
	SID_Set_binding_status,			//��״̬
	SID_Set_binding_code,			//����
	SID_Set_ip_ptcAddr,				//ipЭ��ת������ַ
	SID_Set_extension_information,	//�ֻ���Ϣ
	SID_Set_binding_code1,
	SID_Set_generate_binding_code,	//���ɰ���
	SID_Set_binding,				//��
	SID_Set_get_extension,			//��ȡ�ֻ�
	SID_Set_bounded,				//�Ѱ�
	SID_Set_unbounded,				//δ��
	SID_Set_ExtenNo,				//�ֻ���
	SID_Set_ExtenState,				//״̬
	SID_Set_Online,					//����
	SID_Set_Offline,				//����
	SID_Set_Bind_OK,
	SID_Set_Bind_Fail,

    // �ҵ����������ַ�ID
	SID_Jd_Set_Light,                
	SID_Jd_Set_Window,               
	SID_Jd_Set_Kongtiao,             
	SID_Jd_Set_Dianyuan,             
	SID_Jd_Set_Gas,                
	SID_Jd_Set_Adrress,              
	SID_Jd_Set_OpenAddr,             
	SID_Jd_Set_CloseAddr,           
	SID_Jd_Set_Dev_Name1,           
	SID_Jd_Set_Dev_Name2,           
	SID_Jd_Open_All,                
	SID_Jd_Close_All,                
	SID_Jd_Qingjing,                
	SID_Jd_Light,                   
	SID_Jd_KongTiao,                
	SID_Jd_Dianyuan,                 
	SID_Jd_Meiqi,                  
	SID_Jd_Control_Mode,          
	SID_Jd_Signal_Control,           
	SID_Jd_Multi_Control,            
	SID_Jd_Group_No,               
	SID_Jd_Dev_Set_Attr,
	SID_Jd_Dev_Set_Adjust,           
	SID_Jd_Dev_Set_UnAdjust,         
	SID_Jd_Dev_Set_Light,          
	SID_Jd_Dev_Set_Temp,             
	SID_Jd_Dev_Set_NoDev,           
	SID_Jd_Dev_Name,               
	SID_Jd_KongTiao_Learn,           
	SID_Jd_KongTiao_Cold,            
	SID_Jd_KongTiao_Hot,            
	SID_Jd_KongTiao_Mode,           
	SID_Jd_Learn,                    
	SID_Jd_Test,                     
	SID_Jd_KongTiao_Refre,          
	SID_Jd_KongTiao_Warm,          
	SID_Jd_KongTiao_Leisure,         
	SID_Jd_KongTiao_Sleep,          
	SID_Jd_KongTiao_Close,           
	SID_Jd_Button_Cold,             
	SID_Jd_Button_Warm,             
	SID_Jd_Button_Mode,
	SID_Jd_Window_Stop,              
	SID_Jd_Lamp,                    
	SID_Jd_Qingjing1,               
	SID_Jd_Set_Name_Err,          
	SID_Jd_Set_Adr_Err,            
	SID_Jd_Set_OpAdr_Err,           
	SID_Jd_Set_ClAdr_Err,            
	SID_Jd_Set_Dev_Failed,         
	SID_Jd_Set_Dev_Noname,          
	SID_Jd_Adress_Set_Warning,       
	SID_Jd_Set_Scene_Noname,        
	SID_Jd_Set_KtLearn_Err,         
	SID_Jd_Set_KtLearn_Ok,        
	SID_Jd_Set_Adr_Wrong,          
	SID_Jd_Sence_Adr,                
	SID_Jd_Aurine_Adress_Set_Warning,  
	SID_Jd_Kongtiao_Learning,        
	SID_Jd_Set_Scene,            
	SID_Jd_Mode_Huike,               
	SID_Jd_Mode_Jiucan,
	SID_Jd_Mode_Yejian,             
	SID_Jd_Mode_Jiedian,             
	SID_Jd_Mode_Putong,              
	SID_Jd_Mode_Self,               
	SID_Jd_Mode_Set_Name1,          
	SID_Jd_Mode_Set_Name2,        
	SID_Jd_Mode_Out,              
	SID_Jd_Mode_Cook,                
	SID_Jd_Mode_first,              
	SID_Jd_Mode_Afater,            
	SID_Jd_Mode_Night,               
	SID_Jd_Mode_Bed,                
	SID_Jd_Mode_QiYe,               
	SID_Jd_Mode_Up,                 
	SID_Jd_Mode_Muyu,             
	SID_Jd_Mode_Tea,            
	SID_Jd_Mode_Drink,              
	SID_Jd_Mode_Read,              
	SID_Jd_Mode_Work,                
	SID_Jd_Mode_Juhui,
	SID_Jd_Mode_Play,               
	SID_Jd_Mode_Film,                
	SID_Jd_Mode_Sing,                
	SID_Jd_Mode_Storang,             
	SID_Jd_Mode_Wenxi,            
	SID_Jd_Mode_Langman,             
	SID_Jd_Mode_Jiqing,              
	SID_Jd_Mode_Dianya,            
	SID_Jd_Mode_Chlid,               
	SID_Jd_Mode_Chenwen,             
	SID_Jd_Mode_Think,            
	SID_Jd_Mode_Cool,               
	SID_Jd_Mode_Warm,                
	SID_Jd_Mode_Mode,              
	SID_Jd_Mode_Sence,               
	SID_Jd_Mode_Qingdiao,            
	SID_Jd_Mode_Fenwei,            
	SID_Jd_Mode_Time,              
	SID_Jd_Mode_Changjing,      
	SID_Jd_LouShang,
	SID_Jd_LouXia,
	SID_Jd_WuNei,               
	SID_Jd_WuWai,                   
	SID_Jd_TianTai,                
	SID_Jd_GeLou,                  
	SID_Jd_HuaYuan,                  
	SID_Jd_DiJiao,                  
	SID_Jd_TianJin,                  
	SID_Jd_WuYan,                 
	SID_Jd_QianTing,                 
	SID_Jd_HouYuan,           
	SID_Jd_DianTiJian,           
	SID_Jd_TingCheFang,              
	SID_Jd_DaMen,                    
	SID_Jd_QianMen,                
	SID_Jd_ZhongMen,                
	SID_Jd_PangMen,                 
	SID_Jd_HouMen,                  
	SID_Jd_CeMen,                   
	SID_Jd_BianMen,
	SID_Jd_HenMen,                   
	SID_Jd_YanTai,                   
	SID_Jd_Zhoulan,                
	SID_Jd_GuoDao,                 
	SID_Jd_LouTi,                   
	SID_Jd_TiKou,                 
	SID_Jd_TiJian,         
	SID_Jd_TiXia,                   
	SID_Jd_KeTing,                   
	SID_Jd_DaTing,                
	SID_Jd_ZhuTing,               
	SID_Jd_CanTing,              
	SID_Jd_FanTing,   
	SID_Jd_MenTing,                
	SID_Jd_ZhuWoShi,                
	SID_Jd_ZhuRenFang,              
	SID_Jd_WoShi,                 
	SID_Jd_ShuiFang,               
	SID_Jd_FangJianA,             
	SID_Jd_FangJianB, 
	SID_Jd_FangJianC,                
	SID_Jd_FangJianD,        
	SID_Jd_FangJianE,                
	SID_Jd_ChuFang,                  
	SID_Jd_ShuFang,                  
	SID_Jd_KeFang,                   
	SID_Jd_ZhuYuShi,                 
	SID_Jd_YuShi,                  
	SID_Jd_ErTongFang,               
	SID_Jd_GongRenFang,          
	SID_Jd_DuoYongTuJian,            
	SID_Jd_QiJuShi,                  
	SID_Jd_YouLeShi,                 
	SID_Jd_ShuXiShi,               
	SID_Jd_WeiShengJian,            
	SID_Jd_XieMaoJian,              
	SID_Jd_GongZuoJian,              
	SID_Jd_DiXiaShi,                 
	SID_Jd_None,                   
	SID_Jd_Deng,
	SID_Jd_TiaoGuangDeng,           
	SID_Jd_BaiChiDeng,               
	SID_Jd_GuangGuan,               
	SID_Jd_DiaoDeng,                
	SID_Jd_HuaDeng,                  
	SID_Jd_BiDeng,                
	SID_Jd_SheDeng,                 
	SID_Jd_TaiDeng,                 
	SID_Jd_LouDiDeng,            
	SID_Jd_ZhaoMingDeng,            
	SID_Jd_ShiYingDeng,              
	SID_Jd_YeDeng,                   
	SID_Jd_ZhuanshiDEng,       
	SID_Jd_DianZhiSuo,               
	SID_Jd_XiaoduWanGui,           
	SID_Jd_KongQiJinHua,            
	SID_Jd_YinShuiJi,            
	SID_Jd_KongTiaoJi,              
	SID_Jd_LenQiJi,                  
	SID_Jd_CouYouJi,
	SID_Jd_NuanFenJi,               
	SID_Jd_DianReTan,                
	SID_Jd_ReShuiLu,                
	SID_Jd_DianFanBao,               
	SID_Jd_DianZhiWaGuo,             
	SID_Jd_WeiBoLu,                 
	SID_Jd_XiYiJi,               
	SID_Jd_DianShiJi,                
	SID_Jd_LuXiangJi,               
	SID_Jd_YingXiang,              
	SID_Jd_DianNao,                  
	SID_Jd_FengShan,             
	SID_Jd_CD,                  
	SID_Jd_LD,              
	SID_Jd_VCD,                    
	SID_Jd_DVD,                    
	SID_Jd_ChaZuo1,                  
	SID_Jd_ChaZuo2,                 
	SID_Jd_ChaZuo3,                 
	SID_Jd_ChaZuo4,
	SID_Jd_ChaZuo5,               
	SID_Jd_XiaoDuSheBe,             
	SID_Jd_SettingMusic,             
	SID_Jd_ChuangLian,              
	SID_Jd_JuanLian,                 
	SID_Jd_DianDongBuLian,        
	SID_Jd_DianDongShaLian,        
	SID_Jd_SceneNameSet,           
	SID_Jd_SceneActionSet,
	#ifdef _AIR_VOLUME_MODE_
	SID_Jd_Air_Volume,
	SID_Jd_Low_Wind,
	SID_Jd_Medium_Wind,
	SID_Jd_Hight_Wind,
	SID_Jd_Automatic,
	#endif

	// �Խ����ַ�ID
	SID_MainCall_User,				
	SID_MainCall_FengJi,				
	SID_MainCenter_1,				
	SID_MainCenter_2,				
	SID_MainCenter_3,				
	SID_MainMonitor_Door,			
	SID_MainMonitor_Stair,			
	SID_MainMonitor_Area,			
	SID_MainMonitor_Camera,
	SID_MainMonitor_Home,
	SID_DevManager,                 
	SID_DevArea,                    
	SID_DevStair,                 
	SID_DevRoom,                
	SID_DevPhone,                    
	SID_DevDoorPhone,             
	SID_DevDoorNet,                  
	SID_DevGateWay,                  
	SID_DevIPCamera,                 
	SID_DevFenJi,                    
	SID_DevMaster,                 
	SID_RecordMiss,                  
	SID_RecordIn,                   
	SID_RecordOut,               
	SID_Right_Full,                  
	SID_Inter_HangUP,                
	SID_Inter_Answer,                
	SID_Inter_Unlock,             
	SID_Inter_ReDial,               
	SID_Right_Call,
	SID_Inter_Capture,               
	SID_Inter_Volume,               
	SID_Inter_Next,                 
	SID_Inter_Talk,                  
	SID_Inter_GetList,             
	SID_Inter_Snap,                
	SID_Inter_AudioAdd,          
	SID_Inter_AudioDel,             
	SID_Inter_StopMonitor,           
	SID_Input_OK,                    
	SID_Inter_EnterUserNo,           
	SID_Inter_EnterFJNo,             
	SID_Inter_WrongNo,              
	SID_Inter_NoNotFound,           
	SID_Inter_Connecting,          
	SID_Inter_BeCalling,            
	SID_Inter_Calling,               
	SID_Inter_Talking,              
	SID_Inter_RecordHinting,         
	SID_Inter_Recording,
	SID_Inter_UnlockSuccess,        
	SID_Inter_UnlockFailed,          
	SID_Inter_CaptureSuccess,        
	SID_Inter_CaptureFailed,         
	SID_Inter_ManagerNoSet,          
	SID_Inter_Search,                
	SID_Inter_Monitor,               
	SID_Inter_busy,                 
	SID_Inter_ConnFailed,            
	SID_Inter_SearchFailed,          
	SID_Inter_ElevAuthorize,         
	SID_Inter_ElevAuthOK,           
	SID_Inter_ElevAuthFailed, 
	SID_Auto_Capture,

	// ��Ϣ�����ַ�ID
	SID_Info_Sms,                   
	SID_Info_Centre_Des,             
	 
	// ���������ַ�ID
	SID_Media_Lyly,                  
	SID_Media_Snap,                 
	SID_Media_Num,                  
	SID_Media_Z,                    

	// ���������ַ�ID
	SID_Bl_Jrly,                  
	SID_Bl_ClearScreen,
	
	// �ҵ������ַ�ID
	SID_Jd_Mode_Unused,              
	SID_Jd_Factory_Set,             
	SID_Jd_Factory,                  
	SID_Jd_Factory_X10,            
	SID_Jd_Factory_Suobo,            
	SID_Jd_Factory_ACBUS,           

	// ���������ַ�ID
	SID_Bj_SOS,                    
	SID_Bj_Fire,                     
	SID_Bj_Gas,                     
	SID_Bj_Door,                    
	SID_Bj_Room,                   
	SID_Bj_Big_Window,               
	SID_Bj_Window,                   
	SID_Bj_Balcony,                  
	SID_Bj_Bf_Home,                 
	SID_Bj_Bf_Out,                   
	SID_Bj_Bf_Night,              
	SID_Bj_Clean,                    
	SID_Bj_Baojing_Record,          
	SID_Bj_Caozuo_Rec,               
	SID_Bj_Alarm_Rec_Clear_F,        
	SID_Bj_Fangqu1,					
	SID_Bj_Fangqu2,					
	SID_Bj_Fangqu3,					
	SID_Bj_Fangqu4,					
	SID_Bj_Fangqu5,					
	SID_Bj_Fangqu6,					
	SID_Bj_Fangqu7,					
	SID_Bj_Fangqu8,
	SID_Bj_Fangqu,					
	SID_Bj_Set_Err,                 
	SID_Bj_Fangqu_Settings,          
	SID_Bj_Security_Settings,       
	SID_Bj_Security_Parameter,       
	SID_Bj_Tantou_Type,             
	SID_Bj_24Hour_Fangqu,            
	SID_Bj_Normally_Open,            
	SID_Bj_Normally_Close,          
	SID_Bj_Alarm_Delay,              
	SID_Bj_None,                     
	SID_Bj_Picture,             
	SID_Bj_Voice,                    
	SID_Bj_Enable,                   
	SID_Disable,                     
	SID_Bj_30Seconds,			    
	SID_Bj_1Minute,				    
	SID_Bj_2Minutes,				   
	SID_Bj_3Minutes,				   
	SID_Bj_4Minutes,
	SID_Bj_5Minutes,				   
	SID_Bj_10Minutes,			  
	SID_Bj_15Minutes,			     
	SID_Bj_Alarm_Time,              
	SID_Bj_Early_Warning_Time,       
	SID_Bj_Early_Warning_Voice,      
	SID_Bj_Remote_sz,             
	SID_Bj_Remote_bf,               
	SID_Bj_Remote_cf,               
	SID_Bj_Remote_jf,              
	SID_Bj_Already_Bufang,      
	SID_Bj_Report_Type_Chufa,        
	SID_Bj_Report_Type_Qiuzhu,      
	SID_Bj_Alarm,                   
	SID_Bj_Report_Type_Jinru,       
	SID_Bj_Fangquchufa,            
	SID_Bj_Bengjikongzhi,         
	SID_Bj_Fengjikongzhi,          
	SID_Bj_Query_Del_Rec_One,        
	SID_Bj_Query_Del_Rec_All,
	SID_Bj_Chufa,                    
	SID_Bj_Cannot_Bufang,            
	SID_InputBox_Psw_Err,            
	SID_Isolation,                
	SID_AfJoint_Tk_Chefang,          
	SID_AfJoint_Mk_Chefang,           
	SID_AfJoint_DoorRing,            
	SID_AfJoint_ScenBf,              
	SID_AfJoint_ScenCf,              
	SID_Af_Tel_Num1,                 
	SID_Af_Tel_Num2,                 
	SID_Af_Msg_Num1,                 
	SID_Af_Msg_Num2,                 
	SID_Af_Mode_Unused,           
	SID_Af_Alarm_Cannot_Bf,          
	SID_Af_Touch_Cannot_Bf,        
	SID_Af_Alarm_Cannot_Qc,

	// ԤԼ�����ַ�ID
	SID_Jd_Yuyue,                 
	SID_Jd_Yuyue_Manager,           
	SID_Jd_Yuyue_All,                
	SID_Jd_Yuyue_DelOne,             
	SID_Jd_Yuyue_Add_Err,            
	SID_Jd_Yuyue_EveryDay,          
	SID_Jd_Yuyue_EveryWeek,          
	SID_Jd_Yuyue_EveryMonth,         
	SID_Jd_Yuyue_Day,                
	SID_Jd_Yuyue_Action_Open,      
	SID_Jd_Yuyue_Action_Close,     
	SID_Jd_Yuyue_Type,            
	SID_Jd_Yuyue_Name,              
	SID_Jd_Yuyue_Status,             
	SID_Jd_Yuyue_Repeat,             
	SID_Jd_Yuyue_StartTime,

	// �������������ַ�ID
	SID_Rtsp_IPC,                    
	SID_Rtsp_Name,                   
	SID_Rtsp_Port,                  
	SID_Rtsp_Channel,               
	SID_Rtsp_User,                   
	SID_Rtsp_Password,              
	SID_Rtsp_IP,                     
	SID_Rtsp_Factory,

	// �ҾӼ��������ַ�ID
	SID_Rtsp_Indoor_Camera,
	SID_Rtsp_Enable_Indoor_Camera,
	SID_Rtsp_PTZ,
	SID_Rtsp_Direc,
	SID_Rtsp_Scaling,
	SID_Rtsp_Point,
	SID_Rtsp_Point1,
	SID_Rtsp_Point2,
	SID_Rtsp_Point3,
	SID_Rtsp_Point4,

	// ������ǰ�������ַ�ID
	#ifdef _ADD_BLUETOOTH_DOOR_
	SID_Ble_Door_Unused1,
	SID_Ble_Door_Unused2,
	SID_Ble_Door_First_Record,
	SID_Ble_Door_Second_Record,
	SID_Ble_Door_Operate_Record,	
	SID_Ble_Door_Lock_Record,
	SID_Ble_Door_24H_Record,
	SID_Ble_Door_History_Record, 
	SID_Ble_Door_Snap_Record,	
	SID_Ble_Door_First,
	SID_Ble_Door_Second,
	SID_Set_Unused,   
	SID_Ble_Door_Obtain,
	SID_Ble_Door_Obtain_Err,
	SID_Ble_Door_Lock_Key,
	SID_Ble_Door_Lock_Pwd,
	SID_Ble_Door_Lock_Card,
	SID_Ble_Door_Lock_Finger,
	SID_Ble_Door_Lock_Face,
	SID_Ble_Door_Lock_Guest,
	SID_Ble_Door_Lock_Monitor,
	SID_Ble_Door_Lock_Photo,
	SID_Ble_Door_Lock_Linshi,
	SID_Ble_Door_Lock_Custom,
	SID_Ble_Door_Operate_Del,
	SID_Ble_Door_Operate_Open,
	SID_Ble_Door_Operate_Unopen,
	SID_Ble_Door_Operate_Ring,
	SID_Ble_Door_Dev_Host,
	SID_Ble_Door_Dev_Door,
	SID_Ble_Door_Dev_Photo, 
	SID_Ble_Door_ManInduction,
	SID_Ble_Door_ThreeErr,	
	SID_Ble_Door_TamperAlarm,
	SID_Ble_Door_Visitor,
	SID_Ble_Door1_Snap_Record,
	SID_Ble_Door2_Snap_Record,
	SID_Ble_Door1_Lock24h_Record,
	SID_Ble_Door2_Lock24h_Record,
	SID_Ble_Door1_LockHis_Record,
	SID_Ble_Door2_LockHis_Record,
	SID_Ble_Door1_Operate24h_Record,
	SID_Ble_Door2_Operate24h_Record,
	SID_Ble_Door1_OperateHis_Record,
	SID_Ble_Door2_OperateHis_Record,
	SID_Ble_Door_Room_List,
	SID_Ble_Door_DNS_Address,
	#endif
	
	SID_MAX
}STRID_E;

/*************************************************
  Function:		get_str
  Description: 	�����ַ�ID��ȡ�ַ�
  Input: 		
	id			ͼƬID
  Output:		
  	filename	ͼƬ��·��
  Return:		��
  Others:
*************************************************/
char * get_str(STRID_E id);

#ifdef __cplusplus
}
#endif
#endif

