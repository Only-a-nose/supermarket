//
// Created by SGNY on 2020/5/9.
//
//��Ա����


#ifndef SUPER_V1_VIP_H
#define SUPER_V1_VIP_H

#include "structandfx.h"
#include "BackupRestore.h"
void VIPMain(Admin *A_Head, in_Goods *inGoods_Head, out_Goods *outGoods_Head,
             Goods *G_Head, VIP *V_Head);
//��Ա�˵�
void VIPMenu();
//�鿴��Ա
void SeeAll(VIP *V_Head);
//ע���Ա
void RegisterVIP(VIP *V_Head);
//��ѯ��Ա
VIP* FindVIP(VIP *V_Head);
//���ݱ�����ָ�
void BandR(Admin *A_Head, in_Goods *inGoods_Head, out_Goods *outGoods_Head,
           Goods *G_Head, VIP *V_Head);

//�޸Ļ�Ա��Ϣ
void ChangeVIPInfo(VIP *V_Head);
//ɾ������
void FreeVIPNode(VIP *V_Head);

//����Ա�Ƿ����,�����Զ�ɾ��
void DeleteIfOutDate(VIP *V_Head);
#endif //SUPER_V1_VIP_H
