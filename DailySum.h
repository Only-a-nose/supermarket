//
// Created by SGNY on 2020/5/9.
//
//ÿ���̵�
#ifndef SUPER_V1_DAILYSUM_H
#define SUPER_V1_DAILYSUM_H

#include "structandfx.h"

void DailySumMain(in_Goods *IG_Head, out_Goods *OG_Head, VIP *V_Head);    //���̵�������
void DailySumMenu();   //���̵����˵�
void totalSum(in_Goods *TodayIG, out_Goods *TodayOG, VIP *TodayV);       //�������̵�
void InSum(in_Goods *TodayIG);         //��������̵�
void OutSum(out_Goods *TodayOG);        //���ճ����̵�
VIP* GetTodayVIP(Date today, VIP* V_Head);   //��ȡ����ע���Ա
in_Goods* GetTodayIG(Date today, in_Goods *IG_Head);  //��ȡ�������
out_Goods* GetTodayOG(Date today, out_Goods *OG_Head);//��ȡ���ճ���
double SUM;           //��������ˮ
double EARN;          //��������
double expense;           //����ָ��
#endif //SUPER_V1_DAILYSUM_H
