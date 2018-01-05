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
#define	ESID_NULL						 (g_China ? (g_Big5 ? "�Ŧr��" : "���ַ� ") : "NULL")
#define	ESID_MainAlarm					 (g_China ? (g_Big5 ? "�w��" : "����") : "Security")
#define	ESID_MainCall					 (g_China ? (g_Big5 ? "����" : "�Խ�") : "Intercom")
#define ESID_MainInfo				     (g_China ? (g_Big5 ? "�T��" : "��Ϣ") : "Information")
#define ESID_MainCenter                  (g_China ? (g_Big5 ? "�I�s����" : "��������") : "CALL ADMIN")
#define ESID_MainMonitor			     (g_China ? (g_Big5 ? "�ʵ�" : "����") : "Monitor")
#define ESID_MainRecord			         (g_China ? (g_Big5 ? "�q�ܰO��" : "ͨ����¼") : "Calls Register")
#define ESID_MainLyLy		             (g_China ? (g_Big5 ? "�d�v�d��" : "��Ӱ����") : "MSG")
#define ESID_MainBianli					 (g_China ? (g_Big5 ? "�K�Q�\\��" : "��������") : "Facility")
#define ESID_MainBianLi_Dianti           (g_China ? (g_Big5 ? "�q��l��" : "�����ٻ�") : "Elevator")
#define ESID_MainSet					 (g_China ? (g_Big5 ? "�]�m" : "����") : "Settings")
#define ESID_MainEcontrol				 (g_China ? (g_Big5 ? "�a�q����" : "�ҵ����") : "Automation")
#define ESID_MainMedia				     (g_China ? (g_Big5 ? "�h�C��" : "��ý��") : "Media")

// ��������
#define ESID_Unregistered           	 (g_China ? (g_Big5 ? "�����U" : "δע��") : "Unregistered")
#define ESID_Registered           		 (g_China ? (g_Big5 ? "�w���U" : "��ע��") : "Registered")
#define ESID_Touch_Calibration           (g_China ? (g_Big5 ? "Ĳ���ë̮խ�!" : "������У׼!") : "Screen Calibration")
#define ESID_Touch_Disp_Chk_Hit          (g_China ? (g_Big5 ? "�Ы���'+'���ߪ���'+'����U�@�Ӧ�m" : "�밴ס'+'����ֱ��'+'������һ��λ��") : "Press and hold '+' until the '+' skip to the next")
#define ESID_clearscreenhit              (g_China ? (g_Big5 ? "�ХάX�n�M�䪺���~�����ù�,�Ѿl�ɶ�:" : "��������������Ʒ������Ļ,ʣ��ʱ��:") : "Pls clean the screen. remaining time:")
#define ESID_Right_Add                   (g_China ? (g_Big5 ? "�K�[" : "���") : "Add")
#define ESID_Right_Edit                  (g_China ? (g_Big5 ? "�s��" : "�༭") : "Edit")
#define ESID_Right_Del                   (g_China ? (g_Big5 ? "�R��" : "ɾ��") : "Delete")
#define ESID_Right_Clear                 (g_China ? (g_Big5 ? "�M��" : "���") : "Empty")
#define ESID_Right_Save                  (g_China ? (g_Big5 ? "�O�s" : "����") : "Save")
#define ESID_Right_View                  (g_China ? (g_Big5 ? "�d��" : "�鿴") : "View")
#define ESID_Right_Sure                  (g_China ? (g_Big5 ? "�T�{" : "ȷ��") : "OK")
#define ESID_Right_desk                  (g_China ? (g_Big5 ? "�]�m�ୱ" : "��������") : "Set")
#define ESID_Right_Rec                   (g_China ? (g_Big5 ? "���s" : "¼��") : "Record")
#define ESID_Right_Listen                (g_China ? (g_Big5 ? "��ť" : "����") : "Audition")
#define ESID_Right_Play                  (g_China ? (g_Big5 ? "����" : "����") : "Play")
#define ESID_Right_Stop                  (g_China ? (g_Big5 ? "����" : "ֹͣ") : "Stop")
#define ESID_Right_Pause                 (g_China ? (g_Big5 ? "�Ȱ�" : "��ͣ") : "Pause")
#define ESID_Right_Updata                (g_China ? (g_Big5 ? "�P�B" : "ͬ��") : "Synchronize")
#define ESID_Right_Select                (g_China ? (g_Big5 ? "���" : "ѡ��") : "Select")
#define ESID_Right_Input                 (g_China ? (g_Big5 ? "��J" : "����") : "Input")
#define ESID_Week_Sun                    (g_China ? (g_Big5 ? "�P����" : "������") : "Sun.")
#define ESID_Week_Mon                    (g_China ? (g_Big5 ? "�P���@" : "����һ") : "Mon.")
#define ESID_Week_Tue                    (g_China ? (g_Big5 ? "�P���G" : "���ڶ�") : "Tues.")
#define ESID_Week_Wed                    (g_China ? (g_Big5 ? "�P���T" : "������") : "Wed.")
#define ESID_Week_Thu                    (g_China ? (g_Big5 ? "�P���|" : "������") : "Thur.")
#define ESID_Week_Fri                    (g_China ? (g_Big5 ? "�P����" : "������") : "Fri.")
#define ESID_Week_Sat                    (g_China ? (g_Big5 ? "�P����" : "������") : "Sat.")
#define ESID_Time_Sec                    (g_China ? (g_Big5 ? "��" : "��") : "Sec")
#define ESID_Time_Hour                   (g_China ? (g_Big5 ? "�p��" : "Сʱ") : "Hour")
#define ESID_Time_Min                    (g_China ? (g_Big5 ? "��" : "��") : "Min")
#define ESID_Time_Never					 (g_China ? (g_Big5 ? "�q��" : "�Ӳ�") : "Never")
#define ESID_Set_Time                    (g_China ? (g_Big5 ? "�ɪ�:" : "ʱ��:") : "Duration")
#define ESID_Set_Mode                    (g_China ? (g_Big5 ? "�Ҧ�:" : "ģʽ:") : "Mode")
#define ESID_Set_Used                    (g_China ? (g_Big5 ? "�ҥ�" : "����") : "Activate")
#define ESID_Save_OK                     (g_China ? (g_Big5 ? "�O �s �� �\\!" : "�� �� �� ��!") : "OK!")
#define ESID_Save_ERR                    (g_China ? (g_Big5 ? "�O �s �� ��!" : "�� �� ʧ ��!") : "Failed!")
#define ESID_Msg_Yes                     (g_China ? (g_Big5 ? "�O" : "��") : "Yes")
#define ESID_Msg_No                      (g_China ? (g_Big5 ? "�_" : "��") : "No")
#define ESID_Msg_Format                  (g_China ? (g_Big5 ? "�нT�{�O�_�榡��?" : "��ȷ���Ƿ��ʽ��?") : "Sure to format disk?")
#define ESID_Oper_OK                     (g_China ? (g_Big5 ? "�� �@ �� �\\!" : "�� �� �� ��!") : "OK!")
#define ESID_Oper_ERR                    (g_China ? (g_Big5 ? "�� �@ �� ��!" : "�� �� ʧ ��!") : "Failed!")
#define ESID_Msg_Calibration             (g_China ? (g_Big5 ? "�O�_�i��Ĳ�N�̮շ�?" : "�Ƿ���д�����У׼?") : "Are you sure to calibrate the screen?")
#define ESID_Msg_OldPass_Err             (g_China ? (g_Big5 ? "�±K�X���~!" : "���������!") : "Wrong old PIN!")
#define ESID_Msg_SamePass_Err            (g_China ? (g_Big5 ? "�⦸��J���K�X���ۦP!" : "������������벻��ͬ!") : "Pls re-enter the same new PIN!")
#define ESID_Msg_InputBox_Psw_Err        (g_China ? (g_Big5 ? "�K�X���~,�Э��s��J!" : "�������,����������!") : "Wrong Password!")
#define ESID_Msg_Jrly_rec_tmp            (g_China ? (g_Big5 ? "�O�_�R���w���s�����?" : "�Ƿ�ɾ����¼�Ƶ��ļ�?") : "Sure to delete it?")
#define ESID_Msg_Jrly_rec_full           (g_China ? (g_Big5 ? "�a�H�d���Ŷ��w��!" : "�������Կռ�����!") : "Memory Full!")
#define ESID_Msg_Connect_Outtime         (g_China ? (g_Big5 ? "�s���W��" : "���ӳ�ʱ") : "Connection timeout!")
#define ESID_Msg_Alarm_Hit               (g_China ? (g_Big5 ? "�Ъ`�N,���ɨ���Ĳ�o!" : "��ע��,��ʱ��������!") : "Warning! alarm triggered!")
#define ESID_Msg_Info_Hit                (g_China ? (g_Big5 ? "�z�n,���s���T��!" : "����,���µ���Ϣ!") : "Hi,you have new message!")
#define ESID_Msg_CallIn_Hit              (g_China ? (g_Big5 ? "�z�n,���s���ӹq!" : "����,���µ�����!") : "Hi,you have new call now!")
#define ESID_Msg_FactoryMode             (g_China ? (g_Big5 ? "�O�_�n��_�X�t�]�m?" : "�Ƿ�Ҫ�ָ���������?") : "Sure to restore factory settings?")
#define ESID_Msg_Cell_Err                (g_China ? (g_Big5 ? "�椸���׫D�k" : "��Ԫ���ȷǷ�") : "Illegal Riser No.!")
#define ESID_Msg_Stair_Err               (g_China ? (g_Big5 ? "��f���׫D�k" : "�ݺų��ȷǷ�") : "Illegal Stairway No.!")
#define ESID_Msg_Room_Err                (g_China ? (g_Big5 ? "�и����׫D�k" : "���ų��ȷǷ�") : "Illegal Apartment No.!")
#define ESID_Msg_RuleAll_Err             (g_China ? (g_Big5 ? "�`���פ���j��18" : "�ܳ��Ȳ��ܴ���18") : "Length should be less than 18")
#define ESID_Msg_Len_Err                 (g_China ? (g_Big5 ? "�]�ƽs�����׫D�k" : "�豸��ų��ȷǷ�") : "Illegal Length!")
#define ESID_Msg_RoomNo_Err              (g_China ? (g_Big5 ? "�и��q����0" : "���Ŷ�ȫΪ0") : "Room No. can not be all zero!")
#define ESID_Msg_Recover_OK              (g_China ? (g_Big5 ? "�ާ@���\\,�t�αN����!" : "�����ɹ�,ϵͳ������!") : "OK! The system will restart!")
#define ESID_Msg_Exit                    (g_China ? (g_Big5 ? "�h�X" : "�˳� ") : "Exit")
#define ESID_Msg_Dianti_Hit1             (g_China ? (g_Big5 ? "�q��O���@�]�I,���F�j�a���n���ϥΥ�," : "�����ǹ�����ʩ,Ϊ�˴���ܸ��õ�ʹ����,") : "In order to make better use of elevator")
#define ESID_Msg_Dianti_Hit2             (g_China ? (g_Big5 ? "�бz���n�H�N�l��!" : "������Ҫ�����ٻ�!") : "Please do not arbitrarily call it!")
#define ESID_Msg_Reset                   (g_China ? (g_Big5 ? "�t�έ��Ҥ�..." : "ϵͳ������...") : "System Reset...")
#define ESID_Msg_JD_Is_Updata            (g_China ? (g_Big5 ? "�P�B��N��s��T��,�O�_�P�B?" : "ͬ���󽫸���ԭ��Ϣ,�Ƿ�ͬ��?") : "All data will be renewed.")
#define ESID_Msg_JD_Is_Updata1           (g_China ? (g_Big5 ? "�P�B��N��s��T��,�O�_�P�B?" : "ͬ���󽫸���ԭ��Ϣ,�Ƿ�ͬ��?") : " Sure to synchronize? ")
#define ESID_Msg_JD_Updataing            (g_China ? (g_Big5 ? "�P�B�a�q�T����,�еy��..." : "ͬ���ҵ���Ϣ��,���Ժ�...") : "Settings data synchronizing...")
#define ESID_Msg_JD_Unbind               (g_China ? (g_Big5 ? "IP��w�ഫ�����j�w,����P�B!" : "IPЭ��ת����δ��,����ͬ��!") : "Cannot synchronize!")
#define ESID_Msg_Create_BindCode         (g_China ? (g_Big5 ? "�z�T�w�n�ͦ��s���j�w��?" : "��ȷ��Ҫ�����µİ�����?") : "Sure to generate new binding code")
#define ESID_IP_Unbind                   (g_China ? (g_Big5 ? "IP��w�ഫ�����j�w" : "IPЭ��ת����δ��") : "Not bound to IP converter yet.")
#define ESID_IP_Bind                     (g_China ? (g_Big5 ? "IP��w�ഫ���j�w���\\!" : "IPЭ��ת�����󶨳ɹ�!") : "Bound to IP converter.")
#define ESID_Msg_Jd_State_Updata         (g_China ? (g_Big5 ? "�a�q���A�P�B��,�еy��..." : "�ҵ��豸״̬ͬ����,���Ժ�...") : "Device status synchronizing...")
#define ESID_IP_Online                   (g_China ? (g_Big5 ? "IP��w�ഫ���b�u" : "IPЭ��ת��������") : "IP Converter Online.")
#define ESID_IP_Unline                   (g_China ? (g_Big5 ? "IP��w�ഫ�����b�u" : "IPЭ��ת����δ����") : "IP Converter Offline.")
#define ESID_IP_Con_Addr                 (g_China ? (g_Big5 ? "IP��w�ഫ���a�}" : "IPЭ��ת������ַ") : "IP Converter Address")
#define ESID_Jd_Deng1                    (g_China ? (g_Big5 ? "�O1" : "��1") : "Light1")
#define ESID_Jd_Deng2                    (g_China ? (g_Big5 ? "�O2" : "��2") : "Light2")
#define ESID_Jd_Deng3                    (g_China ? (g_Big5 ? "�O3" : "��3") : "Light3")
#define ESID_Jd_Deng4                    (g_China ? (g_Big5 ? "�O4" : "��4") : "Light4")
#define ESID_Jd_Deng5                    (g_China ? (g_Big5 ? "�O5" : "��5") : "Light5")
#define ESID_Jd_Deng6                    (g_China ? (g_Big5 ? "�O6" : "��6") : "Light6")
#define ESID_Jd_Deng7                    (g_China ? (g_Big5 ? "�O7" : "��7") : "Light7")
#define ESID_Jd_Deng8                    (g_China ? (g_Big5 ? "�O8" : "��8") : "Light8")
#define ESID_Jd_Deng9                    (g_China ? (g_Big5 ? "�O9" : "��9") : "Light9")
#define ESID_Jd_Deng10                   (g_China ? (g_Big5 ? "�O10" : "��10") : "Light10")
#define ESID_Jd_TiaoGuangDeng1           (g_China ? (g_Big5 ? "�ե��O1" : "�����1") : "Dimming Lights1")
#define ESID_Jd_TiaoGuangDeng2           (g_China ? (g_Big5 ? "�ե��O2" : "�����2") : "Dimming Lights2")
#define ESID_Jd_TiaoGuangDeng3           (g_China ? (g_Big5 ? "�ե��O3" : "�����3") : "Dimming Lights3")
#define ESID_Jd_TiaoGuangDeng4           (g_China ? (g_Big5 ? "�ե��O4" : "�����4") : "Dimming Lights4")
#define ESID_Jd_TiaoGuangDeng5           (g_China ? (g_Big5 ? "�ե��O5" : "�����5") : "Dimming Lights5")
#define ESID_Jd_TiaoGuangDeng6           (g_China ? (g_Big5 ? "�ե��O6" : "�����6") : "Dimming Lights6")
#define ESID_Jd_TiaoGuangDeng7           (g_China ? (g_Big5 ? "�ե��O7" : "�����7") : "Dimming Lights7")
#define ESID_Jd_TiaoGuangDeng8           (g_China ? (g_Big5 ? "�ե��O8" : "�����8") : "Dimming Lights8")
#define ESID_Jd_TiaoGuangDeng9           (g_China ? (g_Big5 ? "�ե��O9" : "�����9") : "Dimming Lights9")
#define ESID_Jd_TiaoGuangDeng10          (g_China ? (g_Big5 ? "�ե��O10" : "�����10") : "Dimming Lights10")
#define ESID_Jd_BaiChiDeng1              (g_China ? (g_Big5 ? "�տK�O1" : "�׳��1") : "Incandescent Lamp1")
#define ESID_Jd_BaiChiDeng2              (g_China ? (g_Big5 ? "�տK�O2" : "�׳��2") : "Incandescent Lamp2")
#define ESID_Jd_BaiChiDeng3              (g_China ? (g_Big5 ? "�տK�O3" : "�׳��3") : "Incandescent Lamp3")
#define ESID_Jd_BaiChiDeng4              (g_China ? (g_Big5 ? "�տK�O4" : "�׳��4") : "Incandescent Lamp4")
#define ESID_Jd_BaiChiDeng5              (g_China ? (g_Big5 ? "�տK�O5" : "�׳��5") : "Incandescent Lamp5")
#define ESID_Jd_BaiChiDeng6              (g_China ? (g_Big5 ? "�տK�O6" : "�׳��6") : "Incandescent Lamp6")
#define ESID_Jd_BaiChiDeng7              (g_China ? (g_Big5 ? "�տK�O7" : "�׳��7") : "Incandescent Lamp7")
#define ESID_Jd_BaiChiDeng8              (g_China ? (g_Big5 ? "�տK�O8" : "�׳��8") : "Incandescent Lamp8")
#define ESID_Jd_BaiChiDeng9              (g_China ? (g_Big5 ? "�տK�O9" : "�׳��9") : "Incandescent Lamp9")
#define ESID_Jd_BaiChiDeng10             (g_China ? (g_Big5 ? "�տK�O10" : "�׳��10") : "Incandescent Lamp10")
#define ESID_Jd_GuangGuan1               (g_China ? (g_Big5 ? "����1" : "���1") : "Lightpipe1")
#define ESID_Jd_GuangGuan2               (g_China ? (g_Big5 ? "����2" : "���2") : "Lightpipe2")
#define ESID_Jd_GuangGuan3               (g_China ? (g_Big5 ? "����3" : "���3") : "Lightpipe3")
#define ESID_Jd_GuangGuan4               (g_China ? (g_Big5 ? "����4" : "���4") : "Lightpipe4")
#define ESID_Jd_GuangGuan5               (g_China ? (g_Big5 ? "����5" : "���5") : "Lightpipe5")
#define ESID_Jd_GuangGuan6               (g_China ? (g_Big5 ? "����6" : "���6") : "Lightpipe6")
#define ESID_Jd_GuangGuan7               (g_China ? (g_Big5 ? "����7" : "���7") : "Lightpipe7")
#define ESID_Jd_GuangGuan8               (g_China ? (g_Big5 ? "����8" : "���8") : "Lightpipe8")
#define ESID_Jd_GuangGuan9               (g_China ? (g_Big5 ? "����9" : "���9") : "Lightpipe9")
#define ESID_Jd_GuangGuan10              (g_China ? (g_Big5 ? "����10" : "���10") : "Lightpipe10")
#define ESID_Jd_DiaoDeng1                (g_China ? (g_Big5 ? "�Q�O1" : "����1") : "Chandelier1")
#define ESID_Jd_DiaoDeng2                (g_China ? (g_Big5 ? "�Q�O2" : "����2") : "Chandelier2")
#define ESID_Jd_DiaoDeng3                (g_China ? (g_Big5 ? "�Q�O3" : "����3") : "Chandelier3")
#define ESID_Jd_DiaoDeng4                (g_China ? (g_Big5 ? "�Q�O4" : "����4") : "Chandelier4")
#define ESID_Jd_DiaoDeng5                (g_China ? (g_Big5 ? "�Q�O5" : "����5") : "Chandelier5")
#define ESID_Jd_DiaoDeng6                (g_China ? (g_Big5 ? "�Q�O6" : "����6") : "Chandelier6")
#define ESID_Jd_DiaoDeng7                (g_China ? (g_Big5 ? "�Q�O7" : "����7") : "Chandelier7")
#define ESID_Jd_DiaoDeng8                (g_China ? (g_Big5 ? "�Q�O8" : "����8") : "Chandelier8")
#define ESID_Jd_DiaoDeng9                (g_China ? (g_Big5 ? "�Q�O9" : "����9") : "Chandelier9")
#define ESID_Jd_DiaoDeng10               (g_China ? (g_Big5 ? "�Q�O10" : "����10") : "Chandelier10")
#define ESID_Jd_HuaDeng1                 (g_China ? (g_Big5 ? "��O1" : "����1") : "Lantern1")
#define ESID_Jd_HuaDeng2                 (g_China ? (g_Big5 ? "��O2" : "����2") : "Lantern2")
#define ESID_Jd_HuaDeng3                 (g_China ? (g_Big5 ? "��O3" : "����3") : "Lantern3")
#define	ESID_Jd_HuaDeng4                 (g_China ? (g_Big5 ? "��O4" : "����4") : "Lantern4")
#define ESID_Jd_HuaDeng5                 (g_China ? (g_Big5 ? "��O5" : "����5") : "Lantern5")
#define ESID_Jd_HuaDeng6                 (g_China ? (g_Big5 ? "��O6" : "����6") : "Lantern6")
#define ESID_Jd_HuaDeng7                 (g_China ? (g_Big5 ? "��O7" : "����7") : "Lantern7")
#define ESID_Jd_HuaDeng8                 (g_China ? (g_Big5 ? "��O8" : "����8") : "Lantern8")
#define ESID_Jd_HuaDeng9                 (g_China ? (g_Big5 ? "��O9" : "����9") : "Lantern9")
#define ESID_Jd_HuaDeng10                (g_China ? (g_Big5 ? "��O10" : "����10") : "Lantern10")
#define ESID_Jd_BiDeng1                  (g_China ? (g_Big5 ? "���O1" : "�ڵ�1") : "Wall Lamp1")
#define ESID_Jd_BiDeng2                  (g_China ? (g_Big5 ? "���O2" : "�ڵ�2") : "Wall Lamp2")
#define ESID_Jd_BiDeng3                  (g_China ? (g_Big5 ? "���O3" : "�ڵ�3") : "Wall Lamp3")
#define ESID_Jd_BiDeng4                  (g_China ? (g_Big5 ? "���O4" : "�ڵ�4") : "Wall Lamp4")
#define ESID_Jd_BiDeng5                  (g_China ? (g_Big5 ? "���O5" : "�ڵ�5") : "Wall Lamp5")
#define ESID_Jd_BiDeng6                  (g_China ? (g_Big5 ? "���O6" : "�ڵ�6") : "Wall Lamp6")
#define ESID_Jd_BiDeng7                  (g_China ? (g_Big5 ? "���O7" : "�ڵ�7") : "Wall Lamp7")
#define ESID_Jd_BiDeng8                  (g_China ? (g_Big5 ? "���O8" : "�ڵ�8") : "Wall Lamp8")
#define ESID_Jd_BiDeng9                  (g_China ? (g_Big5 ? "���O9" : "�ڵ�9") : "Wall Lamp9")
#define ESID_Jd_BiDeng10                 (g_China ? (g_Big5 ? "���O10" : "�ڵ�10") : "Wall Lamp10")
#define ESID_Jd_SheDeng1                 (g_China ? (g_Big5 ? "�g�O1" : "���1") : "Spotlight1")
#define ESID_Jd_SheDeng2                 (g_China ? (g_Big5 ? "�g�O2" : "���2") : "Spotlight2")
#define ESID_Jd_SheDeng3                 (g_China ? (g_Big5 ? "�g�O3" : "���3") : "Spotlight3")
#define ESID_Jd_SheDeng4                 (g_China ? (g_Big5 ? "�g�O4" : "���4") : "Spotlight4")
#define ESID_Jd_SheDeng5                 (g_China ? (g_Big5 ? "�g�O5" : "���5") : "Spotlight5")
#define ESID_Jd_SheDeng6                 (g_China ? (g_Big5 ? "�g�O6" : "���6") : "Spotlight6")
#define ESID_Jd_SheDeng7                 (g_China ? (g_Big5 ? "�g�O7" : "���7") : "Spotlight7")
#define ESID_Jd_SheDeng8                 (g_China ? (g_Big5 ? "�g�O8" : "���8") : "Spotlight8")
#define ESID_Jd_SheDeng9                 (g_China ? (g_Big5 ? "�g�O9" : "���9") : "Spotlight9")
#define ESID_Jd_SheDeng10                (g_China ? (g_Big5 ? "�g�O10" : "���10") : "Spotlight10")
#define ESID_Jd_TaiDeng1                 (g_China ? (g_Big5 ? "�O�O1" : "̨��1") : "Table Lamp1")
#define ESID_Jd_TaiDeng2                 (g_China ? (g_Big5 ? "�O�O2" : "̨��2") : "Table Lamp2")
#define ESID_Jd_TaiDeng3                 (g_China ? (g_Big5 ? "�O�O3" : "̨��3") : "Table Lamp3")
#define ESID_Jd_TaiDeng4                 (g_China ? (g_Big5 ? "�O�O4" : "̨��4") : "Table Lamp4")
#define ESID_Jd_TaiDeng5                 (g_China ? (g_Big5 ? "�O�O5" : "̨��5") : "Table Lamp5")
#define ESID_Jd_TaiDeng6                 (g_China ? (g_Big5 ? "�O�O6" : "̨��6") : "Table Lamp6")
#define ESID_Jd_TaiDeng7                 (g_China ? (g_Big5 ? "�O�O7" : "̨��7") : "Table Lamp7")
#define ESID_Jd_TaiDeng8                 (g_China ? (g_Big5 ? "�O�O8" : "̨��8") : "Table Lamp8")
#define ESID_Jd_TaiDeng9                 (g_China ? (g_Big5 ? "�O�O9" : "̨��9") : "Table Lamp9")
#define ESID_Jd_TaiDeng10                (g_China ? (g_Big5 ? "�O�O10" : "̨��10") : "Table Lamp10")
#define ESID_Jd_LouDiDeng1               (g_China ? (g_Big5 ? "���a�O1" : "��ص�1") : "Floor Lamp1")
#define ESID_Jd_LouDiDeng2               (g_China ? (g_Big5 ? "���a�O2" : "��ص�2") : "Floor Lamp2")
#define ESID_Jd_LouDiDeng3               (g_China ? (g_Big5 ? "���a�O3" : "��ص�3") : "Floor Lamp3")
#define ESID_Jd_LouDiDeng4               (g_China ? (g_Big5 ? "���a�O4" : "��ص�4") : "Floor Lamp4")
#define ESID_Jd_LouDiDeng5               (g_China ? (g_Big5 ? "���a�O5" : "��ص�5") : "Floor Lamp5")
#define ESID_Jd_LouDiDeng6               (g_China ? (g_Big5 ? "���a�O6" : "��ص�6") : "Floor Lamp6")
#define ESID_Jd_LouDiDeng7               (g_China ? (g_Big5 ? "���a�O7" : "��ص�7") : "Floor Lamp7")
#define ESID_Jd_LouDiDeng8               (g_China ? (g_Big5 ? "���a�O8" : "��ص�8") : "Floor Lamp8")
#define ESID_Jd_LouDiDeng9               (g_China ? (g_Big5 ? "���a�O9" : "��ص�9") : "Floor Lamp9")
#define ESID_Jd_LouDiDeng10              (g_China ? (g_Big5 ? "���a�O10" : "��ص�10") : "Floor Lamp10")
#define ESID_Jd_ZhaoMingDeng1            (g_China ? (g_Big5 ? "�ө��O1" : "������1") : "Lighting Lamp1")
#define ESID_Jd_ZhaoMingDeng2            (g_China ? (g_Big5 ? "�ө��O2" : "������2") : "Lighting Lamp2")
#define ESID_Jd_ZhaoMingDeng3            (g_China ? (g_Big5 ? "�ө��O3" : "������3") : "Lighting Lamp3")
#define ESID_Jd_ZhaoMingDeng4            (g_China ? (g_Big5 ? "�ө��O4" : "������4") : "Lighting Lamp4")
#define ESID_Jd_ZhaoMingDeng5            (g_China ? (g_Big5 ? "�ө��O5" : "������5") : "Lighting Lamp5")
#define ESID_Jd_ZhaoMingDeng6            (g_China ? (g_Big5 ? "�ө��O6" : "������6") : "Lighting Lamp6")
#define ESID_Jd_ZhaoMingDeng7            (g_China ? (g_Big5 ? "�ө��O7" : "������7") : "Lighting Lamp7")
#define ESID_Jd_ZhaoMingDeng8            (g_China ? (g_Big5 ? "�ө��O8" : "������8") : "Lighting Lamp8")
#define ESID_Jd_ZhaoMingDeng9            (g_China ? (g_Big5 ? "�ө��O9" : "������9") : "Lighting Lamp9")
#define ESID_Jd_ZhaoMingDeng10           (g_China ? (g_Big5 ? "�ө��O10" : "������10") : "Lighting Lamp10")
#define ESID_Jd_ShiYingDeng1             (g_China ? (g_Big5 ? "�ۭ^�O1" : "ʯӢ��1") : "Quartz Lamp1")
#define ESID_Jd_ShiYingDeng2             (g_China ? (g_Big5 ? "�ۭ^�O2" : "ʯӢ��2") : "Quartz Lamp2")
#define ESID_Jd_ShiYingDeng3             (g_China ? (g_Big5 ? "�ۭ^�O3" : "ʯӢ��3") : "Quartz Lamp3")
#define ESID_Jd_ShiYingDeng4             (g_China ? (g_Big5 ? "�ۭ^�O4" : "ʯӢ��4") : "Quartz Lamp4")
#define ESID_Jd_ShiYingDeng5             (g_China ? (g_Big5 ? "�ۭ^�O5" : "ʯӢ��5") : "Quartz Lamp5")
#define ESID_Jd_ShiYingDeng6             (g_China ? (g_Big5 ? "�ۭ^�O6" : "ʯӢ��6") : "Quartz Lamp6")
#define ESID_Jd_ShiYingDeng7             (g_China ? (g_Big5 ? "�ۭ^�O7" : "ʯӢ��7") : "Quartz Lamp7")
#define ESID_Jd_ShiYingDeng8             (g_China ? (g_Big5 ? "�ۭ^�O8" : "ʯӢ��8") : "Quartz Lamp8")
#define ESID_Jd_ShiYingDeng9             (g_China ? (g_Big5 ? "�ۭ^�O9" : "ʯӢ��9") : "Quartz Lamp9")
#define ESID_Jd_ShiYingDeng10            (g_China ? (g_Big5 ? "�ۭ^�O10" : "ʯӢ��10") : "Quartz Lamp10")
#define ESID_Jd_YeDeng1                  (g_China ? (g_Big5 ? "�]�O1" : "ҹ��1") : "Nightlights1")
#define ESID_Jd_YeDeng2                  (g_China ? (g_Big5 ? "�]�O2" : "ҹ��2") : "Nightlights2")
#define ESID_Jd_YeDeng3                  (g_China ? (g_Big5 ? "�]�O3" : "ҹ��3") : "Nightlights3")
#define ESID_Jd_YeDeng4                  (g_China ? (g_Big5 ? "�]�O4" : "ҹ��4") : "Nightlights4")
#define ESID_Jd_YeDeng5                  (g_China ? (g_Big5 ? "�]�O5" : "ҹ��5") : "Nightlights5")
#define ESID_Jd_YeDeng6                  (g_China ? (g_Big5 ? "�]�O6" : "ҹ��6") : "Nightlights6")
#define ESID_Jd_YeDeng7                  (g_China ? (g_Big5 ? "�]�O7" : "ҹ��7") : "Nightlights7")
#define ESID_Jd_YeDeng8                  (g_China ? (g_Big5 ? "�]�O8" : "ҹ��8") : "Nightlights8")
#define ESID_Jd_YeDeng9                  (g_China ? (g_Big5 ? "�]�O9" : "ҹ��9") : "Nightlights9")
#define ESID_Jd_YeDeng10                 (g_China ? (g_Big5 ? "�]�O10" : "ҹ��10") : "Nightlights10")
#define ESID_Jd_ZhuanshiDEng1            (g_China ? (g_Big5 ? "�˹��O1" : "װ�ε�1") : "Deco Lamp1")
#define ESID_Jd_ZhuanshiDEng2            (g_China ? (g_Big5 ? "�˹��O2" : "װ�ε�2") : "Deco Lamp2")
#define ESID_Jd_ZhuanshiDEng3            (g_China ? (g_Big5 ? "�˹��O3" : "װ�ε�3") : "Deco Lamp3")
#define ESID_Jd_ZhuanshiDEng4            (g_China ? (g_Big5 ? "�˹��O4" : "װ�ε�4") : "Deco Lamp4")
#define ESID_Jd_ZhuanshiDEng5            (g_China ? (g_Big5 ? "�˹��O5" : "װ�ε�5") : "Deco Lamp5")
#define ESID_Jd_ZhuanshiDEng6            (g_China ? (g_Big5 ? "�˹��O6" : "װ�ε�6") : "Deco Lamp6")
#define ESID_Jd_ZhuanshiDEng7            (g_China ? (g_Big5 ? "�˹��O7" : "װ�ε�7") : "Deco Lamp7")
#define ESID_Jd_ZhuanshiDEng8            (g_China ? (g_Big5 ? "�˹��O8" : "װ�ε�8") : "Deco Lamp8")
#define ESID_Jd_ZhuanshiDEng9            (g_China ? (g_Big5 ? "�˹��O9" : "װ�ε�9") : "Deco Lamp9")
#define ESID_Jd_ZhuanshiDEng10           (g_China ? (g_Big5 ? "�˹��O10" : "װ�ε�10") : "Deco Lamp10")
#ifdef _AIR_VOLUME_MODE_
#define ESID_Jd_Air_Volume            	 (g_China ? (g_Big5 ? "���q" : "����") : "Air")
#define ESID_Jd_Low_Wind                 (g_China ? (g_Big5 ? "�C��" : "�ͷ�") : "Low")
#define ESID_Jd_Medium_Wind              (g_China ? (g_Big5 ? "����" : "�з�") : "Medium")
#define ESID_Jd_Hight_Wind               (g_China ? (g_Big5 ? "����" : "�߷�") : "Hight")
#define ESID_Jd_Automatic                (g_China ? (g_Big5 ? "�۰�" : "�Զ�") : "Automatic")
#endif

// ������
#define ESID_Set_Menu_System             (g_China ? (g_Big5 ? "�t�γ]�m" : "ϵͳ����") : "System Settings")
#define ESID_Set_Menu_Project            (g_China ? (g_Big5 ? "�u�{�]�m" : "��������") : "Installer Settings")
#define ESID_Set_Menu_Alarm              (g_China ? (g_Big5 ? "�w���]�m" : "��������") : "Security Settings")
#define ESID_Set_Menu_User               (g_China ? (g_Big5 ? "�Τ�]�m" : "�û�����") : "User Settings")
#define ESID_Set_System_language         (g_China ? (g_Big5 ? "�t�λy��" : "ϵͳ����") : "Language")
#define ESID_Set_System_Time             (g_China ? (g_Big5 ? "����P�ɶ�" : "������ʱ��") : "Time & Date")
#define ESID_Set_System_Desk             (g_China ? (g_Big5 ? "�ୱ�I��" : "���汳��") : "Desktop")
#define ESID_Set_System_Screen           (g_China ? (g_Big5 ? "�ù��O�@" : "��Ļ����") : "Screen Saver")
#define ESID_Set_System_Light            (g_China ? (g_Big5 ? "�ù��G��" : "��Ļ����") : "Screen Brightness")
#define ESID_Set_System_Storage          (g_China ? (g_Big5 ? "�s�x�޲z" : "�洢����") : "Memory Management")
#define ESID_Set_System_Info             (g_China ? (g_Big5 ? "�t�ΰT��" : "ϵͳ��Ϣ") : "System Info.")
#define ESID_Set_Prj_Pass                (g_China ? (g_Big5 ? "�u�{�K�X�]�m" : "������������") : "Installer Password")
#define ESID_Set_Prj_Alarm               (g_China ? (g_Big5 ? "�����ݩ�" : "��������") : "Defense Zones")
#define ESID_Set_Prj_Net                 (g_China ? (g_Big5 ? "�����Ѽ�" : "�������") : "Network Parameters")
#define ESID_Set_Prj_ExtMode             (g_China ? (g_Big5 ? "�~���Ҳ�" : "�ⲿģ��") : "External Modules")
#define ESID_Set_Prj_DevNo               (g_China ? (g_Big5 ? "�]�ƽs��" : "�豸���") : "Device No.")
#define ESID_Set_Prj_NetDoor             (g_China ? (g_Big5 ? "�������e��" : "������ǰ��") : "IP Camera")
#define ESID_Set_Prj_Default             (g_China ? (g_Big5 ? "��_�X�t�]�m" : "�ָ���������") : "Restore Factory Settings")
#define ESID_Set_Prj_JiaDian             (g_China ? (g_Big5 ? "�a�q�]�m" : "�ҵ�����") : "Home Appliances")
#define ESID_Set_Prj_Mic                 (g_China ? (g_Big5 ? "�}�Y�W�q�]�m" : "��ͷ��������") : "Mic Gain Settings")
#define ESID_Set_Prj_Mic_Db              (g_China ? (g_Big5 ? "�}�Y�W�q" : "��ͷ����") : "Mic Gain")
#define ESID_Set_Prj_Set_Rtsp            (g_China ? (g_Big5 ? "�ʱ��]�m" : "�������") : "Monitor Settings")
#define ESID_Set_Prj_Set_IPModule        (g_China ? (g_Big5 ? "IP��w�ഫ��" : "IPЭ��ת����") : "IP Converter")
#define ESID_Set_Alarm_UserPwd           (g_China ? (g_Big5 ? "�Τ�K�X" : "�û�����") : "User Password")
#define ESID_Set_Alarm_DoorPwd           (g_China ? (g_Big5 ? "�}���K�X" : "��������") : "Unlock Password")
#define ESID_Set_Alarm_AfLink            (g_China ? (g_Big5 ? "�w���p��" : "��������") : "Security Interlocking")
#define ESID_Set_Alarm_AfGeLi            (g_China ? (g_Big5 ? "���Ϲj��" : "��������") : "Bypass")
#define ESID_Set_Alarm_AfJuFang          (g_China ? (g_Big5 ? "��������" : "�ַ���Ч") : "Night Mode")
#define ESID_Set_UAlarm_Remote           (g_China ? (g_Big5 ? "���{����" : "Զ�̿���") : "Remote Control")
#define ESID_Set_Alarm_MsgNum            (g_China ? (g_Big5 ? "�u�H���X�]�m" : "���ź�������") : "Alarm MSG No.")
#define ESID_Set_Alarm_TelNum            (g_China ? (g_Big5 ? "��ĵ���X�]�m" : "������������") : "Alarm Call No.")
#define ESID_Set_User_Sound              (g_China ? (g_Big5 ? "�a�n�]�m" : "��������") : "Ringtone")
#define ESID_Set_User_Volume             (g_China ? (g_Big5 ? "���q�]�m" : "��������") : "Volume")
#define ESID_Set_User_NoFace             (g_China ? (g_Big5 ? "�K���Z�]�m" : "���������") : "Do-Not-Disturb")
#define ESID_Set_User_LyLy               (g_China ? (g_Big5 ? "�d�v�d���]�m" : "��Ӱ��������") : "MSG")
#define ESID_Set_User_PT                 (g_China ? (g_Big5 ? "���O���U" : "ƽ̨ע��") : "Registration")
#define ESID_Set_Unreg                   (g_China ? (g_Big5 ? "���O�����U" : "ƽ̨δע��") : "Device not registered on Aurine Platform yet!")
#define ESID_Set_Reg_Code                (g_China ? (g_Big5 ? "���O���ҽX:" : "ƽ̨��֤��:") : "Verification Code:")
#define ESID_Set_Reging                  (g_China ? (g_Big5 ? "���b�i�業�O���U,�еy��..." : "���ڽ���ƽ̨ע��,���Ժ�...") : "Registering...")
#define ESID_Set_Prj_Net_HostIP          (g_China ? (g_Big5 ? "����IP" : "����IP") : "Device IP")
#define ESID_Set_Prj_Net_HostNetMask     (g_China ? (g_Big5 ? "�����l�����B�n" : "������������") : "Subnet Mask")    
#define ESID_Set_Prj_Net_HostGateWay     (g_China ? (g_Big5 ? "���������`�D" : "��������") : "Gateway") 
#define ESID_Set_Prj_Net_CenterSever     (g_China ? (g_Big5 ? "���ߦ��A��IP" : "���ķ�����IP") : "Center Server")
#define ESID_Set_Prj_Net_ManageIP1       (g_China ? (g_Big5 ? "�޲z�����@IP" : "����Ա��һIP") : "Admin Unit1")  
#define ESID_Set_Prj_Net_ManageIP2       (g_China ? (g_Big5 ? "�޲z�����GIP" : "����Ա����IP") : "Admin Unit2") 
#define ESID_Set_Prj_Net_ManageIP3       (g_China ? (g_Big5 ? "�޲z�����TIP" : "����Ա����IP") : "Admin Unit3")
#define ESID_Set_Prj_Net_AurineSever     (g_China ? (g_Big5 ? "���O���A��IP" : "ƽ̨������IP") : "Platform Server")  
#define ESID_Set_Prj_Net_AurineElevator  (g_China ? (g_Big5 ? "�q�豱�IP" : "���ݿ�����IP") : "Elevator Controller") 
#define ESID_Set_Prj_Net_Rtsp            (g_China ? (g_Big5 ? "�y�C����A��" : "��ý�������") : "RTSP Server") 
#define ESID_Set_Prj_Net_Stair           (g_China ? (g_Big5 ? "���ݱ��J��IP" : "�ƶ˽�����IP") : "Cloud Access Device")
#define ESID_Set_Prj_Net_IPModule_IP     (g_China ? (g_Big5 ? "IP��w�ഫ���a�}" : "IPЭ��ת������ַ") : "IP Address")    
#define ESID_Set_Prj_Net_IPModule_Code   (g_China ? (g_Big5 ? "IP��w�ഫ���j�w�X" : "IPЭ��ת��������") : "Binding Code")      
#define ESID_Set_Dev_Rule                (g_China ? (g_Big5 ? "�s���W�h" : "��Ź���") : "Number Rule")
#define ESID_Set_Dev_Stair_len           (g_China ? (g_Big5 ? "�踹����" : "�ݺų���") : "Stairway No.")
#define ESID_Set_Dev_Room_len            (g_China ? (g_Big5 ? "�и�����" : "���ų���") : "Apartment No.")
#define ESID_Set_Dev_Cell_len            (g_China ? (g_Big5 ? "�椸������" : "��Ԫ�ų���") : "Riser No.")
#define ESID_Set_Dev_UseCell             (g_China ? (g_Big5 ? "�ҥγ椸��" : "���õ�Ԫ��") : "Enable Riser No.")
#define ESID_Set_Dev_BIT                 (g_China ? (g_Big5 ? "��" : "λ") : "Digits")
#define ESID_Set_Ext_Alarm               (g_China ? (g_Big5 ? "�w���Ҳ�" : "����ģ��") : "Alarm Module")
#define ESID_Set_Ext_JiaDian             (g_China ? (g_Big5 ? "�a�q�Ҳ�" : "�ҵ�ģ��") : "Home Automation Module")
#define ESID_Set_Ext_Stair               (g_China ? (g_Big5 ? "�q�α�f��" : "ͨ���ݿڻ�") : "General Secondary Entry Station")
#define ESID_Set_Language                (g_China ? (g_Big5 ? "�нT�{�O�_�O�s�]�m?" : "��ȷ���Ƿ񱣴�����?") : "Save The Setting?")
#ifdef _TCPTO485_ELEVATOR_MODE_
#define ESID_Set_TCP485Elevator           (g_China ? (g_Big5 ? "TCP��485�Ҳ�IP" : "TCPת485ģ��IP") : "TCP To 485 Addr")
#endif

// IPЭ��ת����
#define ESID_Set_binding_code        	 (g_China ? (g_Big5 ? "�j�w�X:" : "����:") : "Binding Code:")
#define ESID_Set_binding_code1        	 (g_China ? (g_Big5 ? "�j�w�X" : "����") : "Binding Code") 
#define ESID_Set_binding_status          (g_China ? (g_Big5 ? "�j�w���A:" : "��״̬:") : "Binding State:")
#define ESID_Set_extension_information   (g_China ? (g_Big5 ? "�����H��:" : "�ֻ���Ϣ:") : "EXT-INFO:")
#define ESID_Set_ip_ptcAddr				 (g_China ? (g_Big5 ? "��w�ഫ��IP:" : "Э��ת����IP:") : "IP Address:")
#define ESID_Set_generate_binding_code   (g_China ? (g_Big5 ? "�ͦ��j�w�X" : "���ɰ���") : "Binding Code")
#define ESID_Set_binding  				 (g_China ? (g_Big5 ? "�j�w" : "��") : "Binding")
#define ESID_Set_get_extension			 (g_China ? (g_Big5 ? "�������" : "��ȡ�ֻ�") : "Extension")
#define ESID_Set_bounded  				 (g_China ? (g_Big5 ? "�w�j�w" : "�Ѱ�") : "Binding")
#define ESID_Set_unbounded				 (g_China ? (g_Big5 ? "���j�w" : "δ��") : "Unbounded")
#define ESID_Set_ExtenNo 				 (g_China ? (g_Big5 ? "����" : "�ֻ�") : "EXT")
#define ESID_Set_ExtenState				 (g_China ? (g_Big5 ? "���A" : "״̬") : "Status")
#define ESID_Set_Online				     (g_China ? (g_Big5 ? "�b�u" : "����") : "OnLine")
#define ESID_Set_Offline 				 (g_China ? (g_Big5 ? "���u" : "����") : "UnLine")
#define ESID_Set_Bind_OK				 (g_China ? (g_Big5 ? "�j�w���\\" : "�󶨳ɹ�") : "OK")
#define ESID_Set_Bind_Fail				 (g_China ? (g_Big5 ? "�j�w����" : "��ʧ��") : "Failed")

// ������ǰ������
#define ESID_Net_Door_First_R            (g_China ? (g_Big5 ? "���e���@" : "��ǰ��һ") : "Camera 1")
#define ESID_Net_Door_Second_R           (g_China ? (g_Big5 ? "���e���G" : "��ǰ����") : "Camera 2")
#define ESID_Net_Door_First_A            (g_China ? (g_Big5 ? "�������e���@" : "ģ����ǰ��һ") : "Analog Camera 1")
#define ESID_Net_Door_Second_A           (g_China ? (g_Big5 ? "�������e���G" : "ģ����ǰ����") : "Analog Camera 2")
#define ESID_Net_Door             		 (g_China ? (g_Big5 ? "�������e��" : "������ǰ��") : "IP Camera")
#define ESID_Net_Door_First              (g_China ? (g_Big5 ? "�������e���@" : "������ǰ��һ") : "IP Camera 1")
#define ESID_Net_Door_Second             (g_China ? (g_Big5 ? "�������e���G" : "������ǰ����") : "IP Camera 2")
#define ESID_Net_Door_IP                 (g_China ? (g_Big5 ? "IP�a�}" : "IP��ַ") : "IP Address")
#define ESID_Net_Door_Sub                (g_China ? (g_Big5 ? "�l�����B�n" : "��������") : "Subnet Mask")
#define ESID_Net_Door_GateWay            (g_China ? (g_Big5 ? "�����`�D" : "����") : "Gateway")
#define ESID_Net_Door_GetMAC             (g_China ? (g_Big5 ? "ŪMAC�X" : "��MAC��") : "Obtain MAC")
#define ESID_Net_Door_MAC                (g_China ? (g_Big5 ? "MAC" : "MAC") : "MAC")
#define ESID_Net_Door_NetParam           (g_China ? (g_Big5 ? "�����Ѽ�" : "�������") : "Network Parameters")
#define ESID_Net_Door_LockType           (g_China ? (g_Big5 ? "�������]�m" : "����������") : "Lock")
#define ESID_Net_Door_CardMan            (g_China ? (g_Big5 ? "�d�޲z" : "������") : "IC Card")
#define ESID_Net_Door_SysInfo            (g_China ? (g_Big5 ? "�t�ΰT��" : "ϵͳ��Ϣ") : "System Info.")
#define ESID_Net_Door_Other_Set          (g_China ? (g_Big5 ? "��L�]�m" : "��������") : "Other Settings")
#define ESID_Net_Door_Open               (g_China ? (g_Big5 ? "�`�}" : "����") : "N/O")
#define ESID_Net_Door_Close              (g_China ? (g_Big5 ? "�`��" : "����") : "N/C")
#define ESID_Net_Door_LTime_Mh           (g_China ? (g_Big5 ? "�}��ɪ�" : "����ʱ��:") : "Unlock Time:")
#define ESID_Net_Door_LockTime           (g_China ? (g_Big5 ? "�}��ɪ�" : "����ʱ��") : "Unlock Time")
#define ESID_Net_Door_Pic_Up             (g_China ? (g_Big5 ? "��ӤW��" : "�����ϴ�") : "Snapshot Upload")
#define ESID_Net_Door_Remote_Moniter     (g_China ? (g_Big5 ? "���{�ʵ�" : "Զ�̼���") : "Remote Monitoring")
#define ESID_Net_Door_Add_Card           (g_China ? (g_Big5 ? "�W�[�d" : "���ӿ�") : "Add Card")
#define ESID_Net_Door_Del_Card           (g_China ? (g_Big5 ? "�R���d" : "ɾ����") : "Del Card")
#define ESID_Net_Door_Unused_First       (g_China ? (g_Big5 ? "���ҥκ������e���@!" : "δ����������ǰ��һ!") : "IP Camera 1 Inactivated!")
#define ESID_Net_Door_Unused_Second      (g_China ? (g_Big5 ? "���ҥκ������e���G!" : "δ����������ǰ����!") : "IP Camera 2 Inactivated!")
#define ESID_Net_Door_Pls_Add_Card       (g_China ? (g_Big5 ? "�Ш�z�һݭn�W�[���d!" : "��ˢ������Ҫ���ӵĿ�!") : "Please add the card!")
#define ESID_Net_Door_Sure_Del_Card      (g_China ? (g_Big5 ? "�O�_�R���Ҧ����d?" : "�Ƿ�ɾ�����еĿ�?") : "Sure to delete all cards?")
#define ESID_Net_Door_Video_Fmt          (g_China ? (g_Big5 ? "���q���W��q" : "��ͨ��Ƶ����") : "Standard Video Quality")
#define ESID_Set_Info_HW                 (g_China ? (g_Big5 ? "�w�骩��" : "Ӳ���汾") : "Hardware Ver")
#define ESID_Set_Info_SF                 (g_China ? (g_Big5 ? "�n�骩��" : "����汾") : "Software Ver")
#define ESID_Set_Info_SDK                (g_China ? (g_Big5 ? "SDK����" : "SDK�汾") : "SDK Ver")
#define ESID_Set_Info_HostMAC            (g_China ? (g_Big5 ? "����MAC" : "����MAC") : "MAC")
#define ESID_Set_Info_Room               (g_China ? (g_Big5 ? "�����и�" : "��������") : "Device No.")
#define ESID_Set_Timer_Wanl              (g_China ? (g_Big5 ? "�U�~��" : "������") : "Calendar")
#define ESID_Storage_Format              (g_China ? (g_Big5 ? "�榡��" : "��ʽ��") : "Format")
#define ESID_Storage_Pic                 (g_China ? (g_Big5 ? "�Ϥ�" : "ͼƬ") : "Picture")
#define ESID_Set_Pass_Server             (g_China ? (g_Big5 ? "�ޮa�K�X" : "��������") : "Servant Password")
#define ESID_Set_Pass_DoorUser           (g_China ? (g_Big5 ? "���}���K�X" : "ס����������") : "Household Password")
#define ESID_Set_Pass_DoorServer         (g_China ? (g_Big5 ? "�ޮa�}���K�X" : "������������") : "Servant Password")
#define ESID_Set_Pass_Old                (g_China ? (g_Big5 ? "�±K�X" : "������") : "Old:")
#define ESID_Set_Pass_New                (g_China ? (g_Big5 ? "�s�K�X" : "������") : "New:")
#define ESID_Set_Pass_Query              (g_China ? (g_Big5 ? "�T�{�K�X" : "ȷ������") : "Re-enter:")
#define ESID_Set_volume_ring             (g_China ? (g_Big5 ? "�a�n���q" : "��������") : "Ringing Volume")
#define ESID_Set_volume_talk             (g_China ? (g_Big5 ? "�q�ܭ��q" : "ͨ������") : "Talk Volume")
#define ESID_Set_volume_key              (g_China ? (g_Big5 ? "�ҥΫ��䭵" : "���ð�����") : "Keypad Tone")
#define ESID_Set_ring_Stair              (g_China ? (g_Big5 ? "��f�ӹq�a�n" : "�ݿ���������") : "Sec.Entry")
#define ESID_Set_ring_Area               (g_China ? (g_Big5 ? "�Ϥf�ӹq�a�n" : "������������") : "Prim.Entry")
#define ESID_Set_ring_Door               (g_China ? (g_Big5 ? "���e�ӹq�a�n" : "��ǰ��������") : "Doorway")
#define ESID_Set_ring_Center             (g_China ? (g_Big5 ? "���ߨӹq�a�n" : "������������") : "Admin")
#define ESID_Set_ring_Room               (g_China ? (g_Big5 ? "���ӹq�a�n" : "ס����������") : "Resident")
#define ESID_Set_ring_fenji              (g_China ? (g_Big5 ? "�����ӹq�a�n" : "�ֻ���������") : "Extension")
#define ESID_Set_ring_Info               (g_China ? (g_Big5 ? "�T�����ܭ�" : "��Ϣ��ʾ��") : "New Message")
#define ESID_Set_ring_alarm              (g_China ? (g_Big5 ? "�wĵ���ܭ�" : "Ԥ����ʾ��") : "Exit Delay Alert")
#define ESID_Set_ring                    (g_China ? (g_Big5 ? "�a�n" : "����") : "Ringtone")
#define ESID_Set_hit                     (g_China ? (g_Big5 ? "���ܭ�" : "��ʾ��") : "Tip Sound")
#define ESID_Set_Lyly_Mode_Audio         (g_China ? (g_Big5 ? "�¯d���Ҧ�" : "������ģʽ") : "Voice MSG")
#define ESID_Set_Lyly_Mode_Both          (g_China ? (g_Big5 ? "�d���Ӥ��Ҧ�" : "������Ƭģʽ") : "Voice MSG & Image")
#define ESID_Set_Lyly_Mode_Video         (g_China ? (g_Big5 ? "�d�v�d���Ҧ�" : "��Ӱ����ģʽ") : "Video MSG")
#define ESID_Set_Lyly_Link1              (g_China ? (g_Big5 ? "�~�X���A�U�p�ʯd�v�d��" : "���״̬��������Ӱ����") : "Activate MSG under the AWAY mode")
#define ESID_Set_Lyly_Link2              (g_China ? (g_Big5 ? "�]�����A�U�p�ʯd�v�d��" : "ҹ��״̬��������Ӱ����") : "Activate MSG under the NIGHT mode")
#define ESID_Set_Lyly_Link3              (g_China ? (g_Big5 ? "�K���Z���A�U�p�ʯd�v�d��" : "�����״̬��������Ӱ����") : "Enable MSG under the Do-Not-Disturb mode")
#define ESID_Set_Lyly_default_tip        (g_China ? (g_Big5 ? "�w�]���ܭ�" : "Ĭ����ʾ��") : "Default")
#define ESID_Set_Lyly_record_tip         (g_China ? (g_Big5 ? "���s���ܭ�" : "¼����ʾ��") : "Customized")
#define ESID_Set_Screen_InTime           (g_China ? (g_Big5 ? "�i�J�ù��O�@�ɶ�" : "��������ʱ��") : "Starts In")
#define ESID_Set_Screen_Lcd              (g_China ? (g_Big5 ? "���̮ɶ�" : "����ʱ��") : "Turn off Display")
#define ESID_Set_Query_Del_All        	 (g_China ? (g_Big5 ? "�T�w�O�_�M��?" : "ȷ���Ƿ����?") : "Sure to delete all?")
#define ESID_Set_Tips_Fail				 (g_China ? (g_Big5 ? "�����s���ܭ�" : "δ¼����ʾ��") : "No Recording Tips")	

// �ҵ���������
#define ESID_Jd_Set_Light                (g_China ? (g_Big5 ? "�O���]�m" : "�ƹ�����") : "Light")
#define ESID_Jd_Set_Window               (g_China ? (g_Big5 ? "��î�]�m" : "��������") : "Curtain")
#define ESID_Jd_Set_Kongtiao             (g_China ? (g_Big5 ? "�Žճ]�m" : "�յ�����") : "A/C")
#define ESID_Jd_Set_Dianyuan             (g_China ? (g_Big5 ? "�q���]�m" : "��Դ����") : "Socket")
#define ESID_Jd_Set_Gas                  (g_China ? (g_Big5 ? "�Ѯ�]�m" : "ú������") : "Gas")
#define ESID_Jd_Set_Adrress              (g_China ? (g_Big5 ? "�a�}" : "��ַ") : "Address")
#define ESID_Jd_Set_OpenAddr             (g_China ? (g_Big5 ? "�}�a�}" : "����ַ") : "Starting Address")
#define ESID_Jd_Set_CloseAddr            (g_China ? (g_Big5 ? "���a�}" : "�ص�ַ") : "Closing Address")
#define ESID_Jd_Set_Dev_Name1            (g_China ? (g_Big5 ? "�]�Ʀ�m" : "�豸λ��") : "Address")
#define ESID_Jd_Set_Dev_Name2            (g_China ? (g_Big5 ? "�]������" : "�豸����") : "Type")
#define ESID_Jd_Open_All                 (g_China ? (g_Big5 ? "���}" : "ȫ��") : "ALL ON")
#define ESID_Jd_Close_All                (g_China ? (g_Big5 ? "����" : "ȫ��") : "ALL OFF")
#define ESID_Jd_Qingjing                 (g_China ? (g_Big5 ? "�����Ҧ�" : "�龰ģʽ") : "Scene Mode")
#define ESID_Jd_Light                    (g_China ? (g_Big5 ? "�O��" : "�ƹ�") : "Light")
#define ESID_Jd_KongTiao                 (g_China ? (g_Big5 ? "�Ž�" : "�յ�") : "A/C")
#define ESID_Jd_Dianyuan                 (g_China ? (g_Big5 ? "�q��" : "��Դ") : "Socket")
#define ESID_Jd_Meiqi                    (g_China ? (g_Big5 ? "�Ѯ�" : "ú��") : "Gas")
#define ESID_Jd_Control_Mode             (g_China ? (g_Big5 ? "����覡" : "���Ʒ�ʽ") : "Control")
#define ESID_Jd_Signal_Control           (g_China ? (g_Big5 ? "�汱" : "����") : "Single")
#define ESID_Jd_Multi_Control            (g_China ? (g_Big5 ? "�ձ�" : "���") : "Group")
#define ESID_Jd_Group_No                 (g_China ? (g_Big5 ? "�ո�" : "���") : "Group No.")
#define ESID_Jd_Dev_Set_Attr             (g_China ? (g_Big5 ? "�ݩ�" : "����") : "Property")
#define ESID_Jd_Dev_Set_Adjust           (g_China ? (g_Big5 ? "�i��" : "�ɵ�") : "Adjustable")
#define ESID_Jd_Dev_Set_UnAdjust         (g_China ? (g_Big5 ? "���i��" : "���ɵ�") : "Unadjustable")
#define ESID_Jd_Dev_Set_Light            (g_China ? (g_Big5 ? "�G��" : "����") : "Brightness")
#define ESID_Jd_Dev_Set_Temp             (g_China ? (g_Big5 ? "�ū�" : "�¶�") : "Temperature")
#define ESID_Jd_Dev_Set_NoDev            (g_China ? (g_Big5 ? "�L�]��" : "���豸") : "None")
#define ESID_Jd_Dev_Name                 (g_China ? (g_Big5 ? "�W��" : "����") : "Description")
#define ESID_Jd_KongTiao_Learn           (g_China ? (g_Big5 ? "���~�ǲ�" : "����ѧϰ") : "IR Study")
#define ESID_Jd_KongTiao_Cold            (g_China ? (g_Big5 ? "�s�N�ǲ�" : "����ѧϰ") : "Cool")
#define ESID_Jd_KongTiao_Hot             (g_China ? (g_Big5 ? "��x�ǲ�" : "��ůѧϰ") : "Heat")
#define ESID_Jd_KongTiao_Mode            (g_China ? (g_Big5 ? "�Ҧ��ǲ�" : "ģʽѧϰ") : "Mode")
#define ESID_Jd_Learn                    (g_China ? (g_Big5 ? "�}�l�ǲ�" : "��ʼѧϰ") : "Start")
#define ESID_Jd_Test                     (g_China ? (g_Big5 ? "����" : "����") : "Test")
#define ESID_Jd_KongTiao_Refre           (g_China ? (g_Big5 ? "�M�n" : "��ˬ") : "Fresh")
#define ESID_Jd_KongTiao_Warm            (g_China ? (g_Big5 ? "�ŷx" : "��ů") : "Warm")
#define ESID_Jd_KongTiao_Leisure         (g_China ? (g_Big5 ? "��~" : "����") : "Casual")
#define ESID_Jd_KongTiao_Sleep           (g_China ? (g_Big5 ? "�ίv" : "˯��") : "Sleep")
#define ESID_Jd_KongTiao_Close           (g_China ? (g_Big5 ? "����" : "�ر�") : "OFF")
#define ESID_Jd_Button_Cold              (g_China ? (g_Big5 ? "�s�N" : "����") : "Cool")
#define ESID_Jd_Button_Warm              (g_China ? (g_Big5 ? "��x" : "��ů") : "Heat")
#define ESID_Jd_Button_Mode              (g_China ? (g_Big5 ? "�Ҧ�" : "ģʽ") : "Mode")
#define ESID_Jd_Window_Stop              (g_China ? (g_Big5 ? "����" : "ֹͣ") : "Stop")
#define ESID_Jd_Lamp                     (g_China ? (g_Big5 ? "�O��" : "�ƹ�") : "Lamp")
#define ESID_Jd_Qingjing1                (g_China ? (g_Big5 ? "�����Ҧ�" : "�龰ģʽ") : "Scene")
#define ESID_Jd_Set_Name_Err             (g_China ? (g_Big5 ? "�W�٭���,�O�s����!" : "�����ظ�,����ʧ��!") : "Description Repeated!")
#define ESID_Jd_Set_Adr_Err              (g_China ? (g_Big5 ? "�a�}����,����]�m!" : "��ַ�ظ�,��������!") : "Address Repeated!")
#define ESID_Jd_Set_OpAdr_Err            (g_China ? (g_Big5 ? "�}�a�}����,����]�m!" : "����ַ�ظ�,��������!") : "Same Starting Address")
#define ESID_Jd_Set_ClAdr_Err            (g_China ? (g_Big5 ? "���a�}����,����]�m!" : "�ص�ַ�ظ�,��������!") : "Same Closing Address")
#define ESID_Jd_Set_Dev_Failed           (g_China ? (g_Big5 ? "�]�Ƴ]�m����!" : "�豸����ʧ��!") : "Failed!")
#define ESID_Jd_Set_Dev_Noname           (g_China ? (g_Big5 ? "�г]�m�W��!" : "����������!") : "Please enter the device name!")
#define ESID_Jd_Adress_Set_Warning       (g_China ? (g_Big5 ? "�п�J�d��O0-255���a�}" : "�����뷶Χ��0-255�ĵ�ַ") : "Address shall be within 0-255.")
#define ESID_Jd_Set_Scene_Noname         (g_China ? (g_Big5 ? "�г]�m�W��!" : "����������!") : "Please enter the scene name!")
#define ESID_Jd_Set_KtLearn_Err          (g_China ? (g_Big5 ? "�ǲߥ���,�Э��s�ǲ�!" : "ѧϰʧ��,������ѧϰ!") : "Failed! Pls try it again.")
#define ESID_Jd_Set_KtLearn_Ok           (g_China ? (g_Big5 ? "�ǲߦ��\\!" : "ѧϰ�ɹ�!") : "OK!")
#define ESID_Jd_Set_Adr_Wrong            (g_China ? (g_Big5 ? "�п�J�d��O16-254���a�}" : "�����뷶Χ��16-254�ĵ�ַ") : "Address shall be within 16-254.")
#define ESID_Jd_Sence_Adr                (g_China ? (g_Big5 ? "(�a�}�d��16-254)" : "(��ַ��ΧΪ16-254)") : "(Address shall be within 16-254)")
#define ESID_Jd_Aurine_Adress_Set_Warning  (g_China ? (g_Big5 ? "�п�J�d��O0-254���a�}" : "�����뷶Χ��0-254�ĵ�ַ") : "Address shall be within 0-254.")
#define ESID_Jd_Kongtiao_Learning        (g_China ? (g_Big5 ? "�ǲߤ�,�еy��..." : "ѧϰ��,���Ժ�...") : "Studying, pls wait...")
#define ESID_Jd_Set_Scene                (g_China ? (g_Big5 ? "�����]�m" : "�龰����") : "Scene Mode")
#define ESID_Jd_Mode_Huike               (g_China ? (g_Big5 ? "�|�ȼҦ�" : "���ģʽ") : "Meeting")
#define ESID_Jd_Mode_Jiucan              (g_China ? (g_Big5 ? "�N�\\�Ҧ�" : "�Ͳ�ģʽ") : "Dining")
#define ESID_Jd_Mode_Yejian              (g_China ? (g_Big5 ? "�]���Ҧ�" : "ҹ��ģʽ") : "Night")
#define ESID_Jd_Mode_Jiedian             (g_China ? (g_Big5 ? "�`�q�Ҧ�" : "�ڵ�ģʽ") : "Saving")
#define ESID_Jd_Mode_Putong              (g_China ? (g_Big5 ? "���q�Ҧ�" : "��ͨģʽ") : "Regular")
#define ESID_Jd_Mode_Self                (g_China ? (g_Big5 ? "�����Ҧ�" : "�龰ģʽ") : "Scene Mode")
#define ESID_Jd_Mode_Set_Name1           (g_China ? (g_Big5 ? "�����W�r" : "�龰����") : "Scene Name")
#define ESID_Jd_Mode_Set_Name2           (g_China ? (g_Big5 ? "��������" : "�龰����") : "Scene Type")
#define ESID_Jd_Mode_Out                 (g_China ? (g_Big5 ? "�~�X" : "���") : "Away")
#define ESID_Jd_Mode_Cook                (g_China ? (g_Big5 ? "�i��" : "���") : "Cooking")
#define ESID_Jd_Mode_first               (g_China ? (g_Big5 ? "����" : "���") : "Breakfast")
#define ESID_Jd_Mode_Afater              (g_China ? (g_Big5 ? "���\\" : "���") : "Lunch")
#define ESID_Jd_Mode_Night               (g_China ? (g_Big5 ? "�߮b" : "����") : "Supper")
#define ESID_Jd_Mode_Bed                 (g_China ? (g_Big5 ? "�N��" : "����") : "Bed")
#define ESID_Jd_Mode_QiYe                (g_China ? (g_Big5 ? "�_�]" : "��ҹ") : "Mid-night")
#define ESID_Jd_Mode_Up                  (g_China ? (g_Big5 ? "�_��" : "��") : "Wake-up")
#define ESID_Jd_Mode_Muyu                (g_China ? (g_Big5 ? "�N�D" : "��ԡ") : "Bath")
#define ESID_Jd_Mode_Tea                 (g_China ? (g_Big5 ? "�~��" : "Ʒ��") : "Tea")
#define ESID_Jd_Mode_Drink               (g_China ? (g_Big5 ? "���s" : "����") : "Bibulous")
#define ESID_Jd_Mode_Read                (g_China ? (g_Big5 ? "�\\Ū" : "�Ķ�") : "Reading")
#define ESID_Jd_Mode_Work                (g_China ? (g_Big5 ? "�u�@" : "����") : "Working")
#define ESID_Jd_Mode_Juhui               (g_China ? (g_Big5 ? "�E�|" : "�ۻ�") : "Party")
#define ESID_Jd_Mode_Play                (g_China ? (g_Big5 ? "�ѵP" : "����") : "Chess&Cards")
#define ESID_Jd_Mode_Film                (g_China ? (g_Big5 ? "�v�|" : "ӰԺ") : "Theatre")
#define ESID_Jd_Mode_Sing                (g_China ? (g_Big5 ? "�w��" : "����") : "Carolling")
#define ESID_Jd_Mode_Storang             (g_China ? (g_Big5 ? "����" : "����") : "Exercising")
#define ESID_Jd_Mode_Wenxi               (g_China ? (g_Big5 ? "����" : "��ܰ") : "Cozy")
#define ESID_Jd_Mode_Langman             (g_China ? (g_Big5 ? "����" : "����") : "Romatic")
#define ESID_Jd_Mode_Jiqing              (g_China ? (g_Big5 ? "�E��" : "����") : "Passionate")
#define ESID_Jd_Mode_Dianya              (g_China ? (g_Big5 ? "�嶮" : "����") : "Elegant")
#define ESID_Jd_Mode_Chlid               (g_China ? (g_Big5 ? "����" : "ͯȤ") : "Childish")
#define ESID_Jd_Mode_Chenwen             (g_China ? (g_Big5 ? "�Ií" : "����") : "Sedate")
#define ESID_Jd_Mode_Think               (g_China ? (g_Big5 ? "�R��" : "��˼") : "Calm")
#define ESID_Jd_Mode_Cool                (g_China ? (g_Big5 ? "�M�D" : "����") : "Cool")
#define ESID_Jd_Mode_Warm                (g_China ? (g_Big5 ? "�ŷx" : "��ů") : "Warm")
#define ESID_Jd_Mode_Mode                (g_China ? (g_Big5 ? "�Ҧ�" : "ģʽ") : "Mode")
#define ESID_Jd_Mode_Sence               (g_China ? (g_Big5 ? "����" : "�龰") : "Scene")
#define ESID_Jd_Mode_Qingdiao            (g_China ? (g_Big5 ? "����" : "���") : "Sentiment")
#define ESID_Jd_Mode_Fenwei              (g_China ? (g_Big5 ? "�^��" : "��Χ") : "Atmosphere")
#define ESID_Jd_Mode_Time                (g_China ? (g_Big5 ? "�ɥ�" : "ʱ��") : "Time")
#define ESID_Jd_Mode_Changjing           (g_China ? (g_Big5 ? "����" : "����") : "Occasion")
#define ESID_Jd_LouShang                 (g_China ? (g_Big5 ? "�ӤW" : "¥��") : "Upstairs")
#define ESID_Jd_LouXia                   (g_China ? (g_Big5 ? "�ӤU" : "¥��") : "Downstairs")
#define ESID_Jd_WuNei                    (g_China ? (g_Big5 ? "�Τ�" : "����") : "Indoor")
#define ESID_Jd_WuWai                    (g_China ? (g_Big5 ? "�Υ~" : "����") : "Outdoor")
#define ESID_Jd_TianTai                  (g_China ? (g_Big5 ? "�ѻO" : "��̨") : "Roof")
#define ESID_Jd_GeLou                    (g_China ? (g_Big5 ? "�ռ�" : "��¥") : "Attic")
#define ESID_Jd_HuaYuan                  (g_China ? (g_Big5 ? "���" : "��԰") : "Garden")
#define ESID_Jd_DiJiao                   (g_China ? (g_Big5 ? "�a��" : "�ؽ�") : "Cellar")
#define ESID_Jd_TianJin                  (g_China ? (g_Big5 ? "�Ѥ�" : "�쾮") : "Patio")
#define ESID_Jd_WuYan                    (g_China ? (g_Big5 ? "����" : "����") : "Roof")
#define ESID_Jd_QianTing                 (g_China ? (g_Big5 ? "�e�x" : "ǰͥ") : "Vestibule")
#define ESID_Jd_HouYuan                  (g_China ? (g_Big5 ? "��|" : "��Ժ") : "Backyard")
#define ESID_Jd_DianTiJian               (g_China ? (g_Big5 ? "�q�趡" : "���ݼ�") : "Elevator")
#define ESID_Jd_TingCheFang              (g_China ? (g_Big5 ? "������" : "ͣ����") : "Parking Room")
#define ESID_Jd_DaMen                    (g_China ? (g_Big5 ? "�j��" : "����") : "Gate")
#define ESID_Jd_QianMen                  (g_China ? (g_Big5 ? "�e��" : "ǰ��") : "Front Door")
#define ESID_Jd_ZhongMen                 (g_China ? (g_Big5 ? "����" : "����") : "MidDoor")
#define ESID_Jd_PangMen                  (g_China ? (g_Big5 ? "�Ǫ�" : "����") : "Side Door")
#define ESID_Jd_HouMen                   (g_China ? (g_Big5 ? "���" : "����") : "Backdoor")
#define ESID_Jd_CeMen                    (g_China ? (g_Big5 ? "����" : "����") : "Side gate")
#define ESID_Jd_BianMen                  (g_China ? (g_Big5 ? "���" : "����") : "Wicket")
#define ESID_Jd_HenMen                   (g_China ? (g_Big5 ? "���" : "����") : "Fence Door")
#define ESID_Jd_YanTai                   (g_China ? (g_Big5 ? "���O" : "��̨") : "Balcony")
#define ESID_Jd_Zhoulan                  (g_China ? (g_Big5 ? "���Y" : "����") : "Corridor")
#define ESID_Jd_GuoDao                   (g_China ? (g_Big5 ? "�L�D" : "����") : "Aisle")
#define ESID_Jd_LouTi                    (g_China ? (g_Big5 ? "�ӱ�" : "¥��") : "Stairs")
#define ESID_Jd_TiKou                    (g_China ? (g_Big5 ? "��f" : "�ݿ�") : "Stairway")
#define ESID_Jd_TiJian                   (g_China ? (g_Big5 ? "�趡" : "�ݼ�") : "Staircase")
#define ESID_Jd_TiXia                    (g_China ? (g_Big5 ? "��U" : "����") : "Down the Ladder")
#define ESID_Jd_KeTing                   (g_China ? (g_Big5 ? "���U" : "����") : "Drawing Room")
#define ESID_Jd_DaTing                   (g_China ? (g_Big5 ? "�j�U" : "����") : "Hall")
#define ESID_Jd_ZhuTing                  (g_China ? (g_Big5 ? "�D�U" : "����") : "Main Hall")
#define ESID_Jd_CanTing                  (g_China ? (g_Big5 ? "�\\�U" : "����") : "Restaurants")
#define ESID_Jd_FanTing                  (g_China ? (g_Big5 ? "���U" : "����") : "Dining Hall")
#define ESID_Jd_MenTing                  (g_China ? (g_Big5 ? "���U" : "����") : "Foyer")
#define ESID_Jd_ZhuWoShi                 (g_China ? (g_Big5 ? "�D�׫�" : "������") : "Master Bedroom")
#define ESID_Jd_ZhuRenFang               (g_China ? (g_Big5 ? "�D�H��" : "���˷�") : "Host Room")
#define ESID_Jd_WoShi                    (g_China ? (g_Big5 ? "�׫�" : "����") : "Bedroom")
#define ESID_Jd_ShuiFang                 (g_China ? (g_Big5 ? "�Ω�" : "˯��") : "Bedroom")
#define ESID_Jd_FangJianA                (g_China ? (g_Big5 ? "�ж�A" : "����A") : "RoomA")
#define ESID_Jd_FangJianB                (g_China ? (g_Big5 ? "�ж�B" : "����B") : "RoomB")
#define ESID_Jd_FangJianC                (g_China ? (g_Big5 ? "�ж�C" : "����C") : "RoomC")
#define ESID_Jd_FangJianD                (g_China ? (g_Big5 ? "�ж�D" : "����D") : "RoomD")
#define ESID_Jd_FangJianE                (g_China ? (g_Big5 ? "�ж�E" : "����E") : "RoomE")
#define ESID_Jd_ChuFang                  (g_China ? (g_Big5 ? "�p��" : "����") : "Kitchen")
#define ESID_Jd_ShuFang                  (g_China ? (g_Big5 ? "�ѩ�" : "�鷿") : "Study")
#define ESID_Jd_KeFang                   (g_China ? (g_Big5 ? "�ȩ�" : "�ͷ�") : "Rooms")
#define ESID_Jd_ZhuYuShi                 (g_China ? (g_Big5 ? "�D�D��" : "��ԡ��") : "Master Bathroom")
#define ESID_Jd_YuShi                    (g_China ? (g_Big5 ? "�D��" : "ԡ��") : "Bathroom")
#define ESID_Jd_ErTongFang               (g_China ? (g_Big5 ? "�ൣ��" : "��ͯ��") : "Children Room")
#define ESID_Jd_GongRenFang              (g_China ? (g_Big5 ? "�u�H��" : "���˷�") : "Servant Room")
#define ESID_Jd_DuoYongTuJian            (g_China ? (g_Big5 ? "�h�γ~��" : "����;��") : "Multi-purpose rooms")
#define ESID_Jd_QiJuShi                  (g_China ? (g_Big5 ? "�_�~��" : "�����") : "Living Room")
#define ESID_Jd_YouLeShi                 (g_China ? (g_Big5 ? "�C�֫�" : "������") : "Playroom")
#define ESID_Jd_ShuXiShi                 (g_China ? (g_Big5 ? "�ެ~��" : "��ϴ��") : "Toilet Room")
#define ESID_Jd_WeiShengJian             (g_China ? (g_Big5 ? "�åͶ�" : "������") : "Toilet")
#define ESID_Jd_XieMaoJian               (g_China ? (g_Big5 ? "�c�U��" : "Ьñ��") : "Home Locker Room")
#define ESID_Jd_GongZuoJian              (g_China ? (g_Big5 ? "�u�@��" : "������") : "Workplace")
#define ESID_Jd_DiXiaShi                 (g_China ? (g_Big5 ? "�a�U��" : "������") : "Basement")
#define ESID_Jd_None                     (g_China ? (g_Big5 ? "�L" : "��") : "None")
#define ESID_Jd_Deng                     (g_China ? (g_Big5 ? "�O" : "��") : "Light")
#define ESID_Jd_TiaoGuangDeng            (g_China ? (g_Big5 ? "�ե��O" : "�����") : "Dimming Lights")
#define ESID_Jd_BaiChiDeng               (g_China ? (g_Big5 ? "�տK�O" : "�׳��") : "Incandescent Lamp")
#define ESID_Jd_GuangGuan                (g_China ? (g_Big5 ? "����" : "���") : "Lightpipe")
#define ESID_Jd_DiaoDeng                 (g_China ? (g_Big5 ? "�Q�O" : "����") : "Chandelier")
#define ESID_Jd_HuaDeng                  (g_China ? (g_Big5 ? "��O" : "����") : "Lantern")
#define ESID_Jd_BiDeng                   (g_China ? (g_Big5 ? "���O" : "�ڵ�") : "Wall Lamp")
#define ESID_Jd_SheDeng                  (g_China ? (g_Big5 ? "�g�O" : "���") : "Spotlight")
#define ESID_Jd_TaiDeng                  (g_China ? (g_Big5 ? "�O�O" : "̨��") : "Table Lamp")
#define ESID_Jd_LouDiDeng                (g_China ? (g_Big5 ? "���a�O" : "��ص�") : "Floor Lamp")
#define ESID_Jd_ZhaoMingDeng             (g_China ? (g_Big5 ? "�ө��O" : "������") : "Lighting Lamp")
#define ESID_Jd_ShiYingDeng              (g_China ? (g_Big5 ? "�ۭ^�O" : "ʯӢ��") : "Quartz Lamp")
#define ESID_Jd_YeDeng                   (g_China ? (g_Big5 ? "�]�O" : "ҹ��") : "Nightlights")
#define ESID_Jd_ZhuanshiDEng             (g_China ? (g_Big5 ? "�˹��O" : "װ�ε�") : "Deco Lamp")
#define ESID_Jd_DianZhiSuo               (g_China ? (g_Big5 ? "�q�l��" : "������") : "E-Lock")
#define ESID_Jd_XiaoduWanGui             (g_China ? (g_Big5 ? "���r�J�d" : "�������") : "Sterilizer")
#define ESID_Jd_KongQiJinHua             (g_China ? (g_Big5 ? "�Ů�b��" : "��������") : "Air Purifier")
#define ESID_Jd_YinShuiJi                (g_China ? (g_Big5 ? "������" : "��ˮ��") : "Water Dispenser")
#define ESID_Jd_KongTiaoJi               (g_China ? (g_Big5 ? "�Žվ�" : "�յ���") : "A/C 1")
#define ESID_Jd_LenQiJi                  (g_China ? (g_Big5 ? "�N���" : "������") : "A/C 2")
#define ESID_Jd_CouYouJi                 (g_China ? (g_Big5 ? "��o��" : "���ͻ�") : "A/C 3")
#define ESID_Jd_NuanFenJi                (g_China ? (g_Big5 ? "�x����" : "ů���") : "A/C 4")
#define ESID_Jd_DianReTan                (g_China ? (g_Big5 ? "�q����" : "����̺") : "Electric Blanket")
#define ESID_Jd_ReShuiLu                 (g_China ? (g_Big5 ? "�����l" : "��ˮ¯") : "Water Heater")
#define ESID_Jd_DianFanBao               (g_China ? (g_Big5 ? "�q���s" : "�緹��") : "Rice Cooker")
#define ESID_Jd_DianZhiWaGuo             (g_China ? (g_Big5 ? "�q�l����" : "�����߹�") : "Electric Stewpot")
#define ESID_Jd_WeiBoLu                  (g_China ? (g_Big5 ? "�L�i�l" : "΢��¯") : "Microwave Oven")
#define ESID_Jd_XiYiJi                   (g_China ? (g_Big5 ? "�~���" : "ϴ�»�") : "Socket 6")
#define ESID_Jd_DianShiJi                (g_China ? (g_Big5 ? "�q����" : "���ӻ�") : "Socket 1")
#define ESID_Jd_LuXiangJi                (g_China ? (g_Big5 ? "���v��" : "¼���") : "VCR")
#define ESID_Jd_YingXiang                (g_China ? (g_Big5 ? "���T" : "����") : "Stereo")
#define ESID_Jd_DianNao                  (g_China ? (g_Big5 ? "�q��" : "����") : "PC")
#define ESID_Jd_FengShan                 (g_China ? (g_Big5 ? "����" : "����") : "Fan")
#define ESID_Jd_CD                       (g_China ? (g_Big5 ? "CD" : "CD") : "CD")
#define ESID_Jd_LD                       (g_China ? (g_Big5 ? "LD" : "LD") : "LD")
#define ESID_Jd_VCD                      (g_China ? (g_Big5 ? "VCD" : "VCD") : "VCD")
#define ESID_Jd_DVD                      (g_China ? (g_Big5 ? "DVD" : "DVD") : "DVD")
#define ESID_Jd_ChaZuo1                  (g_China ? (g_Big5 ? "���y1" : "����1") : "Socket 1")
#define ESID_Jd_ChaZuo2                  (g_China ? (g_Big5 ? "���y2" : "����2") : "Socket 2")
#define ESID_Jd_ChaZuo3                  (g_China ? (g_Big5 ? "���y3" : "����3") : "Socket 3")
#define ESID_Jd_ChaZuo4                  (g_China ? (g_Big5 ? "���y4" : "����4") : "Socket 4")
#define ESID_Jd_ChaZuo5                  (g_China ? (g_Big5 ? "���y5" : "����5") : "Socket 5")
#define ESID_Jd_XiaoDuSheBe              (g_China ? (g_Big5 ? "���r�]��" : "�����豸") : "Disinfectant Apparatus")
#define ESID_Jd_SettingMusic             (g_China ? (g_Big5 ? "�I������" : "��������") : "Background Music")
#define ESID_Jd_ChuangLian               (g_China ? (g_Big5 ? "��î" : "����") : "Curtain")
#define ESID_Jd_JuanLian                 (g_China ? (g_Big5 ? "��î" : "����") : "Shutter")
#define ESID_Jd_DianDongBuLian           (g_China ? (g_Big5 ? "�q�ʥ�î" : "�綯����") : "Electric Curtain")
#define ESID_Jd_DianDongShaLian          (g_China ? (g_Big5 ? "�q�ʯ�î" : "�綯ɴ��") : "Electric Gauze")
#define ESID_Jd_SceneNameSet             (g_China ? (g_Big5 ? "�W�ٳ]�m" : "��������") : "Scene Name")
#define ESID_Jd_SceneActionSet           (g_China ? (g_Big5 ? "�欰�]�m" : "��Ϊ����") : "Scene Action")
 
// �Խ���
#define ESID_MainCall_User				 (g_China ? (g_Big5 ? "�I�s���" : "����ס��") : "Resident")
#define ESID_MainCall_FengJi			 (g_China ? (g_Big5 ? "�I�s����" : "���зֻ�") : "Sub-terminal")
#define ESID_MainCenter_1				 (g_China ? (g_Big5 ? "�I�s����1" : "��������1") : "CALL ADMIN1")
#define ESID_MainCenter_2				 (g_China ? (g_Big5 ? "�I�s����2" : "��������2") : "CALL ADMIN2")
#define ESID_MainCenter_3				 (g_China ? (g_Big5 ? "�I�s����3" : "��������3") : "CALL ADMIN3")
#define ESID_MainMonitor_Door			 (g_China ? (g_Big5 ? "�ʵ����e" : "������ǰ") : "Doorway")
#define ESID_MainMonitor_Stair			 (g_China ? (g_Big5 ? "�ʵ���f" : "�����ݿ�") : "Sec.Entry")
#define ESID_MainMonitor_Area			 (g_China ? (g_Big5 ? "�ʵ��Ϥf" : "��������") : "Prim.Entry")
#define ESID_MainMonitor_Camera			 (g_China ? (g_Big5 ? "�ʵ�����" : "��������") : "Monitor Community")
#define ESID_MainMonitor_Room			 (g_China ? (g_Big5 ? "�a�~�ʵ�" : "�ҾӼ���") : "RoomCamera")
#define ESID_DevManager                  (g_China ? (g_Big5 ? "�޲z����" : "����Ա��") : "Admin")
#define ESID_DevArea                     (g_China ? (g_Big5 ? "�Ϥf��" : "���ڻ�") : "Prim.Entry")
#define ESID_DevStair                    (g_China ? (g_Big5 ? "��f��" : "�ݿڻ�") : "Sec.Entry")
#define ESID_DevRoom                     (g_China ? (g_Big5 ? "�Ǥ���" : "���ڻ�") : "Indoor Terminal")
#define ESID_DevPhone                    (g_China ? (g_Big5 ? "���q�q��" : "��ͨ�绰") : "Phone")
#define ESID_DevDoorPhone                (g_China ? (g_Big5 ? "���e��" : "��ǰ��") : "Camera")
#define ESID_DevDoorNet                  (g_China ? (g_Big5 ? "�������e��" : "������ǰ��") : "IP Camera")
#define ESID_DevGateWay                  (g_China ? (g_Big5 ? "�a�x����" : "��ͥ����") : "Gateway")
#define ESID_DevIPCamera                 (g_China ? (g_Big5 ? "IP Camera" : "IP Camera") : "IP Camera")
#define ESID_DevFenJi                    (g_China ? (g_Big5 ? "����" : "�ֻ�") : "Extension")
#define ESID_DevMaster                   (g_China ? (g_Big5 ? "�D��" : "����") : "Main Phone")
#define ESID_RecordMiss                  (g_China ? (g_Big5 ? "����" : "δ��") : "Missed")
#define ESID_RecordIn                    (g_China ? (g_Big5 ? "�w��" : "�ѽ�") : "Received")
#define ESID_RecordOut                   (g_China ? (g_Big5 ? "�w��" : "�Ѳ�") : "Dialled")
#define ESID_Right_Full                  (g_China ? (g_Big5 ? "����" : "ȫ��") : "Full Screen")
#define ESID_Inter_HangUP                (g_China ? (g_Big5 ? "����" : "�һ�") : "Hang Up")
#define ESID_Inter_Answer                (g_China ? (g_Big5 ? "��ť" : "����") : "Answer")
#define ESID_Inter_Unlock                (g_China ? (g_Big5 ? "�}��" : "����") : "Open")
#define ESID_Inter_ReDial                (g_China ? (g_Big5 ? "����" : "�ز�") : "Redial")
#define ESID_Right_Call                  (g_China ? (g_Big5 ? "�I�s" : "����") : "Call")
#define ESID_Inter_Capture               (g_China ? (g_Big5 ? "���" : "ץ��") : "Capture")
#define ESID_Inter_Volume                (g_China ? (g_Big5 ? "���q" : "����") : "Volume")
#define ESID_Inter_Next                  (g_China ? (g_Big5 ? "�U�@��" : "��һ��") : "Next")
#define ESID_Inter_Talk                  (g_China ? (g_Big5 ? "�q��" : "ͨ��") : "Talk")
#define ESID_Inter_GetList               (g_China ? (g_Big5 ? "����C��" : "��ȡ�б�") : "Obtain")
#define ESID_Inter_Snap                  (g_China ? (g_Big5 ? "���" : "����") : "Snap")
#define ESID_Inter_AudioAdd              (g_China ? (g_Big5 ? "���q+" : "����+") : "Audio Add")
#define ESID_Inter_AudioDel              (g_China ? (g_Big5 ? "���q-" : "����-") : "Audio Del")
#define ESID_Inter_StopMonitor           (g_China ? (g_Big5 ? "����ʵ�" : "ֹͣ����") : "Stop")
#define ESID_Input_OK                    (g_China ? (g_Big5 ? "��J" : "����") : "Enter")
#define ESID_Inter_EnterUserNo           (g_China ? (g_Big5 ? "�п�J��ḹ�X" : "������ס������") : "Pls enter a number")
#define ESID_Inter_EnterFJNo             (g_China ? (g_Big5 ? "�п�J1��������X" : "������1λ�ֻ�����") : "Pls enter a number")
#define ESID_Inter_WrongNo               (g_China ? (g_Big5 ? "��J���X���~!" : "����������!") : "Wrong number!")
#define ESID_Inter_NoNotFound            (g_China ? (g_Big5 ? "�d�L����!" : "���޴˺�!") : "Number not found!")
#define ESID_Inter_Connecting            (g_China ? (g_Big5 ? "�s����..." : "������...") : "Connecting...")
#define ESID_Inter_BeCalling             (g_China ? (g_Big5 ? "�ӹq��..." : "������...") : "Calling from...")
#define ESID_Inter_Calling               (g_China ? (g_Big5 ? "�I�s��..." : "������...") : "Calling...")
#define ESID_Inter_Talking               (g_China ? (g_Big5 ? "�q�ܤ�..." : "ͨ����...") : "Talking...")
#define ESID_Inter_RecordHinting         (g_China ? (g_Big5 ? "�d�����ܤ�..." : "������ʾ��...") : "Record Prompting...")
#define ESID_Inter_Recording             (g_China ? (g_Big5 ? "�d����..." : "������...") : "Recording...")
#define ESID_Inter_UnlockSuccess         (g_China ? (g_Big5 ? "�} �� �� �\\!" : "�� �� �� ��!") : "Door Unlocked!")
#define ESID_Inter_UnlockFailed          (g_China ? (g_Big5 ? "�} �� �� ��!" : "�� �� ʧ ��!") : "Failed!")
#define ESID_Inter_CaptureSuccess        (g_China ? (g_Big5 ? "��Ӧ��\\!" : "ץ �� �� ��!") : "OK!")
#define ESID_Inter_CaptureFailed         (g_China ? (g_Big5 ? "��ӥ���!" : "ץ �� ʧ ��!") : "Failed!")
#define ESID_Inter_ManagerNoSet          (g_China ? (g_Big5 ? "�����ߥ��]�m!" : "������δ����!") : "The admin unit IP not set yet!")
#define ESID_Inter_Search                (g_China ? (g_Big5 ? "�j����,�еy��..." : "������,���Ժ�...") : "Searching...")
#define ESID_Inter_Monitor               (g_China ? (g_Big5 ? "�ʵ���..." : "������...") : "Monitoring...")
#define ESID_Inter_busy                  (g_China ? (g_Big5 ? "��覣!" : "�Է�æ!") : "Busy Line!")
#define ESID_Inter_ConnFailed            (g_China ? (g_Big5 ? "�s������!" : "����ʧ��!") : "Failed!")
#define ESID_Inter_SearchFailed          (g_China ? (g_Big5 ? "���j����]��!" : "δ�������豸!") : "Failed!")
#define ESID_Inter_ElevAuthorize         (g_China ? (g_Big5 ? "���v" : "��Ȩ") : "Authorize")
#define ESID_Inter_ElevAuthOK            (g_China ? (g_Big5 ? "�q����v���\\!" : "������Ȩ�ɹ�!") : "OK!")
#define ESID_Inter_ElevAuthFailed        (g_China ? (g_Big5 ? "�q����v����!" : "������Ȩʧ��!") : "Failed!")
#define ESID_Auto_Capture				 (g_China ? (g_Big5 ? "�۰ʩ��" : "�Զ�ץ��") : "Automatic capture")

// ��Ϣ����
#define ESID_Info_Sms                    (g_China ? (g_Big5 ? "�u�H" : "����") : "Message")
#define ESID_Info_Centre_Des             (g_China ? (g_Big5 ? "���ߦ��A��" : "���ķ�����") : "Center Server")
 
// ��������
#define ESID_Media_Lyly                  (g_China ? (g_Big5 ? "�v��" : "Ӱ��") : "Video MSG")
#define ESID_Media_Snap                  (g_China ? (g_Big5 ? "�Ӥ�" : "��Ƭ") : "Picture")
#define ESID_Media_Num                   (g_China ? (g_Big5 ? "�`�@" : "�ܹ�") : "Memory")
#define ESID_Media_Z                     (g_China ? (g_Big5 ? "�i" : "��") : "Pcs")

// ��������
#define ESID_Bl_Jrly                     (g_China ? (g_Big5 ? "�a�H�d��" : "��������") : "Recorder")
#define ESID_Bl_ClearScreen              (g_China ? (g_Big5 ? "�M��ù�" : "�����Ļ") : "Clean Screen")

// �ҵ�����
#define ESID_Jd_Mode_Unused              (g_China ? (g_Big5 ? "���ҥήa�q�Ҳ�" : "δ���üҵ�ģ��") : "Automation module inactivated")
#define ESID_Jd_Factory_Set              (g_China ? (g_Big5 ? "�a�q�t�ӳ]�m" : "�ҵ糧������") : "Brand Settings")
#define ESID_Jd_Factory                  (g_China ? (g_Big5 ? "�a�q�t��" : "�ҵ糧��") : "Makers")
#define ESID_Jd_Factory_X10              (g_China ? (g_Big5 ? "X10" : "X10") : "X10")
#define ESID_Jd_Factory_Suobo            (g_China ? (g_Big5 ? "����" : "����") : "PLC-BUS")
#define ESID_Jd_Factory_ACBUS            (g_China ? (g_Big5 ? "TA-BUS" : "TA-BUS") : "TA-BUS")

// ��������
#define ESID_Bj_SOS                      (g_China ? (g_Big5 ? "����ĵ" : "��������") : "SOS")
#define ESID_Bj_Fire                     (g_China ? (g_Big5 ? "���a����" : "����̽��") : "Fire")
#define ESID_Bj_Gas                      (g_China ? (g_Big5 ? "�˴�����" : "��˹̽��") : "Gas Leak")
#define ESID_Bj_Door                     (g_China ? (g_Big5 ? "�j���J�I" : "��������") : "Door")
#define ESID_Bj_Room                     (g_China ? (g_Big5 ? "���U����" : "����̽��") : "Room")
#define ESID_Bj_Big_Window               (g_China ? (g_Big5 ? "����1�J�I" : "����1����") : "Window1")
#define ESID_Bj_Window                   (g_China ? (g_Big5 ? "����2�J�I" : "����2����") : "Window2")
#define ESID_Bj_Balcony                  (g_China ? (g_Big5 ? "���O�J�I" : "��̨����") : "Balcony")
#define ESID_Bj_Bf_Home                  (g_China ? (g_Big5 ? "�b�a" : "�ڼ�") : "Home")
#define ESID_Bj_Bf_Out                   (g_China ? (g_Big5 ? "�~�X" : "���") : "Away")
#define ESID_Bj_Bf_Night                 (g_China ? (g_Big5 ? "�]��" : "ҹ��") : "Night")
#define ESID_Bj_Clean                    (g_China ? (g_Big5 ? "�M��ĵ��" : "�����ʾ") : "Reset")
#define ESID_Bj_Baojing_Record           (g_China ? (g_Big5 ? "��ĵ�O��" : "������¼") : "Alarm Log")
#define ESID_Bj_Caozuo_Rec               (g_China ? (g_Big5 ? "�ާ@�O��" : "������¼") : "Operation Log")
#define ESID_Bj_Alarm_Rec_Clear_F        (g_China ? (g_Big5 ? "�O���M������!" : "��¼���ʧ��!") : "Failed!")
#define ESID_Bj_Fangqu1					 (g_China ? (g_Big5 ? "����1" : "����1") : "Zone1")
#define ESID_Bj_Fangqu2					 (g_China ? (g_Big5 ? "����2" : "����2") : "Zone2")
#define ESID_Bj_Fangqu3					 (g_China ? (g_Big5 ? "����3" : "����3") : "Zone3")
#define ESID_Bj_Fangqu4					 (g_China ? (g_Big5 ? "����4" : "����4") : "Zone4")
#define ESID_Bj_Fangqu5					 (g_China ? (g_Big5 ? "����5" : "����5") : "Zone5")
#define ESID_Bj_Fangqu6					 (g_China ? (g_Big5 ? "����6" : "����6") : "Zone6")
#define ESID_Bj_Fangqu7					 (g_China ? (g_Big5 ? "����7" : "����7") : "Zone7")
#define ESID_Bj_Fangqu8					 (g_China ? (g_Big5 ? "����8" : "����8") : "Zone8")
#define ESID_Bj_Fangqu					 (g_China ? (g_Big5 ? "����" : "����") : "Zone")
#define ESID_Bj_Set_Err                  (g_China ? (g_Big5 ? "�Цb�b�a�Ҧ��U�i��]�m!" : "�����ڼ�ģʽ�½�������!") : "Please disarm the system first!")
#define ESID_Bj_Fangqu_Settings          (g_China ? (g_Big5 ? "���ϳ]�m" : "��������") : "Particular Parameters")
#define ESID_Bj_Security_Settings        (g_China ? (g_Big5 ? "�w���]�m" : "��������") : "Security Settings")
#define ESID_Bj_Security_Parameter       (g_China ? (g_Big5 ? "�w���Ѽ�" : "��������") : "General Parameters") 
#define ESID_Bj_Tantou_Type              (g_China ? (g_Big5 ? "����������" : "̽ͷ����") : "Protection")
#define ESID_Bj_24Hour_Fangqu            (g_China ? (g_Big5 ? "24�p�ɨ���" : "24Сʱ����") : "24H Zone")
#define ESID_Bj_Normally_Open            (g_China ? (g_Big5 ? "�������`�}" : "̽ͷ����") : "N/O")
#define ESID_Bj_Normally_Close           (g_China ? (g_Big5 ? "�������`��" : "̽ͷ����") : "N/C")
#define ESID_Bj_Alarm_Delay              (g_China ? (g_Big5 ? "��ĵ����" : "�����ӳ�") : "Entry Delay")
#define ESID_Bj_None                     (g_China ? (g_Big5 ? "�L" : "��") : "0 Sec")
#define ESID_Bj_Picture                  (g_China ? (g_Big5 ? "�e��" : "����") : "Picture")
#define ESID_Bj_Voice                    (g_China ? (g_Big5 ? "�n��" : "����") : "Sound")
#define ESID_Bj_Enable                   (g_China ? (g_Big5 ? "�ҥ�" : "����") : "Activate")
#define ESID_Disable                     (g_China ? (g_Big5 ? "�T��" : "����") : "Deactivate")
#define ESID_Bj_30Seconds			     (g_China ? (g_Big5 ? "30��" : "30��") : "30Sec")
#define ESID_Bj_1Minute				     (g_China ? (g_Big5 ? "1��" : "1��") : "1Min")
#define ESID_Bj_2Minutes				 (g_China ? (g_Big5 ? "2��" : "2��") : "2Min")
#define ESID_Bj_3Minutes				 (g_China ? (g_Big5 ? "3��" : "3��") : "3Min")
#define ESID_Bj_4Minutes				 (g_China ? (g_Big5 ? "4��" : "4��") : "4Min")
#define ESID_Bj_5Minutes				 (g_China ? (g_Big5 ? "5��" : "5��") : "5Min")
#define ESID_Bj_10Minutes			     (g_China ? (g_Big5 ? "10��" : "10��") : "10Min")
#define ESID_Bj_15Minutes			     (g_China ? (g_Big5 ? "15��" : "15��") : "15Min")    
#define ESID_Bj_Alarm_Time               (g_China ? (g_Big5 ? "ĵ�a�ɪ�" : "����ʱ��") : "Alarm Duration")
#define ESID_Bj_Early_Warning_Time       (g_China ? (g_Big5 ? "�wĵ�ɶ�" : "Ԥ��ʱ��") : "Exit Delay")
#define ESID_Bj_Early_Warning_Voice      (g_China ? (g_Big5 ? "�wĵ�n" : "Ԥ����") : "Exit Alert") 
#define ESID_Bj_Remote_sz                (g_China ? (g_Big5 ? "���{�]�m" : "Զ������") : "Remote Settings")
#define ESID_Bj_Remote_bf                (g_China ? (g_Big5 ? "���{�G��" : "Զ�̲���") : "Remote Arm(AWAY)")
#define ESID_Bj_Remote_cf                (g_China ? (g_Big5 ? "���{�M��" : "Զ�̳���") : "Remote Disarm(HOME)")
#define ESID_Bj_Remote_jf                (g_China ? (g_Big5 ? "���{����" : "Զ�ַ̾�") : "Remote Arm(NIGHT)")
#define ESID_Bj_Already_Bufang           (g_China ? (g_Big5 ? "�����������ϥi�i���W�G��" : "����Ӧ�ķ����ɽ��е�������") : "Tap a zone to arm it")
#define ESID_Bj_Report_Type_Chufa        (g_China ? (g_Big5 ? "Ĳ�o��ĵ" : "��������") : "Triggerred Alarm")
#define ESID_Bj_Report_Type_Qiuzhu       (g_China ? (g_Big5 ? "�D�U��ĵ" : "��������") : "HELP")
#define ESID_Bj_Alarm                    (g_China ? (g_Big5 ? "��ĵ" : "����") : "Alarm")
#define ESID_Bj_Report_Type_Jinru        (g_China ? (g_Big5 ? "�i�J��ĵ" : "���뱨��") : "Alarm")
#define ESID_Bj_Fangquchufa              (g_China ? (g_Big5 ? "����Ĳ�o" : "��������") : "Zone Triggered!") 
#define ESID_Bj_Bengjikongzhi            (g_China ? (g_Big5 ? "��������" : "��������") : "Local Control") 
#define ESID_Bj_Fengjikongzhi            (g_China ? (g_Big5 ? "��������" : "�ֻ�����") : "Sub-phone Control") 
#define ESID_Bj_Query_Del_Rec_One        (g_China ? (g_Big5 ? "�T�w�R���ӰO��?" : "ȷ��ɾ���ü�¼?") : "Sure to delete it?")  
#define ESID_Bj_Query_Del_Rec_All        (g_China ? (g_Big5 ? "�T�w�M�ũҦ��O��?" : "ȷ��������м�¼?") : "Sure to delete all?") 
#define ESID_Bj_Chufa                    (g_China ? (g_Big5 ? "Ĳ�o" : "����") : "Triggerred")
#define ESID_Bj_Cannot_Bufang            (g_China ? (g_Big5 ? "����G��" : "���ܲ���") : "Cannot be armed!")
#define ESID_InputBox_Psw_Err            (g_China ? (g_Big5 ? "�K�X���~,�Э��s��J" : "�������,����������") : "Wrong Password!")
#define ESID_Isolation                   (g_China ? (g_Big5 ? "�j��" : "����") : "Bypass")
#define ESID_AfJoint_Tk_Chefang          (g_China ? (g_Big5 ? "��f��d�M��" : "�ݿ�ˢ������") : "Disarm By Card(sec.entry)") 
#define ESID_AfJoint_Mk_Chefang          (g_China ? (g_Big5 ? "���e��d�M��" : "��ǰˢ������") : "Disarm By Card(doorway)") 
#define ESID_AfJoint_DoorRing            (g_China ? (g_Big5 ? "�ĤK���Ϸ���e�a" : "�ڰ˷�������ǰ��") : "Enable zone 8 to work as doorbell")
#define ESID_AfJoint_ScenBf              (g_China ? (g_Big5 ? "�G���p�ʱ����Ҧ�" : "���������龰ģʽ") : "Activate scene mode X under the AWAY mode")
#define ESID_AfJoint_ScenCf              (g_China ? (g_Big5 ? "�M���p�ʱ����Ҧ�" : "���������龰ģʽ") : "Activate scene mode X under the HOME mode")
#define ESID_Af_Tel_Num1                 (g_China ? (g_Big5 ? "��ĵ���X1:" : "��������1:") : "Phone No.1")
#define ESID_Af_Tel_Num2                 (g_China ? (g_Big5 ? "��ĵ���X2:" : "��������2:") : "Phone No.2")
#define ESID_Af_Msg_Num1                 (g_China ? (g_Big5 ? "�u�H���X1:" : "���ź���1:") : "MSG No.1")
#define ESID_Af_Msg_Num2                 (g_China ? (g_Big5 ? "�u�H���X2:" : "���ź���2:") : "MSG No.2")
#define ESID_Af_Mode_Unused              (g_China ? (g_Big5 ? "���ҥγ�ĵ�Ҳ�" : "δ���ñ���ģ��") : "Alarm module inactivated!")
#define ESID_Af_Alarm_Cannot_Bf          (g_China ? (g_Big5 ? "���b��ĵ����G��" : "���ڱ������ܲ���") : "Alarming now. Cannot arm!")
#define ESID_Af_Touch_Cannot_Bf          (g_China ? (g_Big5 ? "����Ĳ�o����G��" : "�����������ܲ���") : "Zone triggerred.Cannot arm!")
#define ESID_Af_Alarm_Cannot_Qc          (g_China ? (g_Big5 ? "���b��ĵ����ާ@" : "���ڱ������ܲ���") : "Zone triggerred.Cannot operate!")

// ԤԼ����
#define ESID_Jd_Yuyue                    (g_China ? (g_Big5 ? "�w��" : "ԤԼ") : "Timer")
#define ESID_Jd_Yuyue_Manager            (g_China ? (g_Big5 ? "�w���޲z" : "ԤԼ����") : "Timing Control")
#define ESID_Jd_Yuyue_All                (g_China ? (g_Big5 ? "����" : "ȫ��") : "All")
#define ESID_Jd_Yuyue_DelOne             (g_China ? (g_Big5 ? "�T�w�R���ӹw��?" : "ȷ��ɾ����ԤԼ?") : "Sure to delete it?")
#define ESID_Jd_Yuyue_Add_Err            (g_China ? (g_Big5 ? "�w������W�L20��!" : "ԤԼ���ܳ���20��!") : "Memory Full!")
#define ESID_Jd_Yuyue_EveryDay           (g_China ? (g_Big5 ? "�C��" : "ÿ��") : "Daily")
#define ESID_Jd_Yuyue_EveryWeek          (g_China ? (g_Big5 ? "�C�P" : "ÿ��") : "Weekly")
#define ESID_Jd_Yuyue_EveryMonth         (g_China ? (g_Big5 ? "�C��" : "ÿ��") : "Monthly")
#define ESID_Jd_Yuyue_Day                (g_China ? (g_Big5 ? "��" : "��") : "Day")
#define ESID_Jd_Yuyue_Action_Open        (g_China ? (g_Big5 ? "�}" : "��") : "ON")
#define ESID_Jd_Yuyue_Action_Close       (g_China ? (g_Big5 ? "��" : "��") : "OFF")
#define ESID_Jd_Yuyue_Type               (g_China ? (g_Big5 ? "����" : "����") : "Type")
#define ESID_Jd_Yuyue_Name               (g_China ? (g_Big5 ? "�W��" : "����") : "Name")
#define ESID_Jd_Yuyue_Status             (g_China ? (g_Big5 ? "���A" : "״̬") : "Status")
#define ESID_Jd_Yuyue_Repeat             (g_China ? (g_Big5 ? "���Ƥ覡" : "�ظ���ʽ") : "Repeat")
#define ESID_Jd_Yuyue_StartTime          (g_China ? (g_Big5 ? "�}�l�ɶ�" : "��ʼʱ��") : "Start Time")

// ������������
#define ESID_Rtsp_IPC                    (g_China ? (g_Big5 ? "����IPC" : "����IPC") : "Net IPC")
#define ESID_Rtsp_Name                   (g_China ? (g_Big5 ? "�]�ƦW��" : "�豸����") : "Device Name")
#define ESID_Rtsp_Port                   (g_China ? (g_Big5 ? "PORT" : "PORT") : "PORT")
#define ESID_Rtsp_Channel                (g_China ? (g_Big5 ? "���W�q�D" : "��Ƶͨ��") : "Video Channel")
#define ESID_Rtsp_User                   (g_China ? (g_Big5 ? "�Τ�W" : "�û���") : "User")
#define ESID_Rtsp_Password               (g_China ? (g_Big5 ? "�K�X" : "����") : "Password")
#define ESID_Rtsp_IP                 	 (g_China ? (g_Big5 ? "IP�a�}" : "IP��ַ") : "IP Address")
#define ESID_Rtsp_Factory                (g_China ? (g_Big5 ? "�t�ӦW��" : "��������") : "Manufacturer")

// �ҾӼ�������
#define ESID_Rtsp_Indoor_Camera          (g_China ? (g_Big5 ? "�Ǥ���v��" : "��������ͷ") : "Indoor Camera")
#define ESID_Rtsp_Enable_Indoor_Camera   (g_China ? (g_Big5 ? "�ҥΫǤ���v��" : "������������ͷ") : "Enable Indoor Camera")
#define ESID_Rtsp_PTZ                	 (g_China ? (g_Big5 ? "�ҥ�PTZ����" : "����PTZ����") : "Enable PTZ Control")
#define ESID_Rtsp_Direc				 	 (g_China ? (g_Big5 ? "��V" : "����") : "Direct")
#define ESID_Rtsp_Scaling				 (g_China ? (g_Big5 ? "�Y��" : "����") : "Scaling")
#define ESID_Rtsp_Point				     (g_China ? (g_Big5 ? "�w�m�I" : "Ԥ�õ�") : "Point")
#define ESID_Rtsp_Point1				 (g_China ? (g_Big5 ? "�w�m�I1" : "Ԥ�õ�1") : "Point 1")
#define ESID_Rtsp_Point2				 (g_China ? (g_Big5 ? "�w�m�I2" : "Ԥ�õ�2") : "Point 2")
#define ESID_Rtsp_Point3				 (g_China ? (g_Big5 ? "�w�m�I3" : "Ԥ�õ�3") : "Point 3")
#define ESID_Rtsp_Point4				 (g_China ? (g_Big5 ? "�w�m�I4" : "Ԥ�õ�4") : "Point 4")

//������ǰ������
#ifdef _ADD_BLUETOOTH_DOOR_
#define ESID_Ble_Door_Unused1       	 (g_China ? (g_Big5 ? "���ҥ��Ť����e���@!" : "δ����������ǰ��һ!") : "Bluetooth Camera 1 Inactivated!")
#define ESID_Ble_Door_Unused2       	 (g_China ? (g_Big5 ? "���ҥ��Ť����e���G!" : "δ����������ǰ����!") : "Bluetooth Camera 2 Inactivated!")
#define ESID_Ble_Door_First_Record 		 (g_China ? (g_Big5 ? "���e���@�O��" : "��ǰ��һ��¼") : "Camera 1 Register")
#define ESID_Ble_Door_Second_Record 	 (g_China ? (g_Big5 ? "���e���G�O��" : "��ǰ������¼") : "Camera 2 Register")
#define ESID_Ble_Door_Operate_Record 	 (g_China ? (g_Big5 ? "�ާ@�O��" : "������¼") : "Operation Log")
#define ESID_Ble_Door_Lock_Record  		 (g_China ? (g_Big5 ? "�}��O��" : "������¼") : "Unlock Log")
#define ESID_Ble_Door_24H_Record   		 (g_China ? (g_Big5 ? "24�p�ɰO��" : "24Сʱ��¼") : "24-hour Log")
#define ESID_Ble_Door_History_Record 	 (g_China ? (g_Big5 ? "���v�O��" : "��ʷ��¼") : "History Log")
#define ESID_Ble_Door_Snap_Record	 	 (g_China ? (g_Big5 ? "��ӰO��" : "���ռ�¼") : "Snapshot Log")
#define ESID_Ble_Door_First        		 (g_China ? (g_Big5 ? "�Ť����e���@" : "������ǰ��һ") : "Bluetooth Camera 1")
#define ESID_Ble_Door_Second       		 (g_China ? (g_Big5 ? "�Ť����e���G" : "������ǰ����") : "Bluetooth Camera 2")
#define ESID_Set_Unused              	 (g_China ? (g_Big5 ? "���ҥ�" : "δ����") : "Not Enabled")
#define ESID_Ble_Door_Obtain       		 (g_China ? (g_Big5 ? "�����,�е���..." : "��ȡ��,���Ժ�...") : "Obtain...")
#define ESID_Ble_Door_Obtain_Err   		 (g_China ? (g_Big5 ? "����O������" : "��ȡ��¼ʧ��") : "Obtain Register Error")
#define ESID_Ble_Door_Lock_Key  	 	 (g_China ? (g_Big5 ? "����}��" : "��е����") : "Mechanical unlocking")
#define ESID_Ble_Door_Lock_Pwd	 	 	 (g_China ? (g_Big5 ? "�K�X�}��" : "���뿪��") : "Password access")
#define ESID_Ble_Door_Lock_Card    		 (g_China ? (g_Big5 ? "��d�}��" : "ˢ������") : "Card access")
#define ESID_Ble_Door_Lock_Finger  		 (g_China ? (g_Big5 ? "�����}��" : "ָ�ƿ���") : "Fingerprint recognition")
#define ESID_Ble_Door_Lock_Face    		 (g_China ? (g_Big5 ? "�H�y�ѧO�}��" : "����ʶ����") : "Face recognition")
#define ESID_Ble_Door_Lock_Guest   		 (g_China ? (g_Big5 ? "�X�ȶ}��" : "�ÿͿ���") : "Unlock by pressing open key")
#define ESID_Ble_Door_Lock_Monitor 		 (g_China ? (g_Big5 ? "�ʵ��}��" : "���ӿ���") : "Unlock when monitoring")
#define ESID_Ble_Door_Lock_Photo   		 (g_China ? (g_Big5 ? "����}��" : "�ֻ�����") : "Unlock via mobile phone")
#define ESID_Ble_Door_Lock_Linshi  		 (g_China ? (g_Big5 ? "�{�ɱ��v�}��" : "��ʱ��Ȩ����") : "Temporary authorized access")
#define ESID_Ble_Door_Lock_Custom  		 (g_China ? (g_Big5 ? "�۩w�q" : "�Զ���") : "Custom")
#define ESID_Ble_Door_Operate_Del  		 (g_China ? (g_Big5 ? "�R���Τ�" : "ɾ���û�") : "Delete user account")
#define ESID_Ble_Door_Operate_Open 		 (g_China ? (g_Big5 ? "�]�m���`�}" : "�����ų���") : "N/O on")
#define ESID_Ble_Door_Operate_Unopen 	 (g_China ? (g_Big5 ? "�������`�}" : "ȡ���ų���") : "N/O off")
#define ESID_Ble_Door_Operate_Ring 		 (g_China ? (g_Big5 ? "���a" : "����") : "Ringtone")
#define ESID_Ble_Door_Dev_Host 		 	 (g_China ? (g_Big5 ? "����" : "����") : "Device")
#define ESID_Ble_Door_Dev_Door 	 		 (g_China ? (g_Big5 ? "���e��" : "��ǰ��") : "Camera")
#define ESID_Ble_Door_Dev_Photo 		 (g_China ? (g_Big5 ? "���" : "�ֻ�") : "Mobile phone")
#define ESID_Ble_Door_ManInduction 	     (g_China ? (g_Big5 ? "�H��P�����" : "�����Ӧ����") : "Snap by human induction")
#define ESID_Ble_Door_ThreeErr		 	 (g_China ? (g_Big5 ? "�����ާ@���~���" : "��β�����������") : "Five Times Operate Error Snap")
#define ESID_Ble_Door_TamperAlarm 	 	 (g_China ? (g_Big5 ? "�����ĵ���" : "���𱨾�����") : "Anti demolition alarm snap")
#define ESID_Ble_Door_Visitor 	 	 	 (g_China ? (g_Big5 ? "�X�ȩI�s���" : "�ÿͺ�������") : "Visitors call snap")
#define ESID_Ble_Door1_Snap_Record 		 (g_China ? (g_Big5 ? "���e���@��ӰO��" : "��ǰ��һ���ռ�¼") : "Camera 1 Snapshot Record")
#define ESID_Ble_Door2_Snap_Record 		 (g_China ? (g_Big5 ? "���e���G��ӰO��" : "��ǰ�������ռ�¼") : "Camera 2 Snapshot Record")
#define ESID_Ble_Door1_Lock24h_Record 	 (g_China ? (g_Big5 ? "���e���@24�p�ɶ}��O��" : "��ǰ��һ24Сʱ������¼") : "Camera 1 24H Unlock Record")
#define ESID_Ble_Door2_Lock24h_Record 	 (g_China ? (g_Big5 ? "���e���G24�p�ɶ}��O��" : "��ǰ����24Сʱ������¼") : "Camera 2 24H Unlock Record")
#define ESID_Ble_Door1_LockHis_Record 	 (g_China ? (g_Big5 ? "���e���@���v�}��O��" : "��ǰ��һ��ʷ������¼") : "Camera 1 Unlock Record")
#define ESID_Ble_Door2_LockHis_Record 	 (g_China ? (g_Big5 ? "���e���G���v�}��O��" : "��ǰ������ʷ������¼") : "Camera 2 Unlock Record")
#define ESID_Ble_Door1_Operate24h_Record (g_China ? (g_Big5 ? "���e���@24�p�ɾާ@�O��" : "��ǰ��һ24Сʱ������¼") : "Camera 1 24H Operate Record")
#define ESID_Ble_Door2_Operate24h_Record (g_China ? (g_Big5 ? "���e���G24�p�ɾާ@�O��" : "��ǰ����24Сʱ������¼") : "Camera 2 24H Operate Record")
#define ESID_Ble_Door1_OperateHis_Record (g_China ? (g_Big5 ? "���e���@���v�ާ@�O��" : "��ǰ��һ��ʷ������¼") : "Camera 1 Operate Record")
#define ESID_Ble_Door2_OperateHis_Record (g_China ? (g_Big5 ? "���e���G���v�ާ@�O��" : "��ǰ������ʷ������¼") : "Camera 1 Operate Record")
#define ESID_Ble_Door_Room_List 		 (g_China ? (g_Big5 ? "�Ǥ����j�w�C��" : "���ڻ����б�") : "Indoor Unit information list")
#define ESID_Ble_Door_DNS_Address 		 (g_China ? (g_Big5 ? "DNS�a�}" : "DNS��ַ") : "DNS Address")
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

typedef enum _FontType
{
    Font12X12 = 12, 
    Font16X16 = 16,
    Font20X20 = 20,
    Font24X24 = 24
}FontType;

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

