//
// Created by SGNY on 2020/5/9.
//
//ÿ���̵�
#include "DailySum.h"
#include <stdio.h>

void DailySumMain(in_Goods *IG_Head, out_Goods *OG_Head, VIP *V_Head){
    Date Today = GetTodayDate();
    VIP *TodayV = GetTodayVIP(Today, V_Head);
    in_Goods *TodayIG = GetTodayIG(Today, IG_Head);
    out_Goods *TodayOG = GetTodayOG(Today, OG_Head);
    int choice = 0;
    while(1){
        SUM = 0;
        EARN = 0;
        expense = 0;
        choice = 0;
        DailySumMenu();
        choice = GetChoice();
        switch (choice){
            case 1:
                totalSum(TodayIG, TodayOG, TodayV);
                break;
            case 2:
                InSum(TodayIG);
                break;
            case 3:
                OutSum(TodayOG);
                break;
            default:
                break;
        }
        if(choice == 0)
            break;
    }
}
//���̵����˵�
void DailySumMenu(){
    system("cls");
    SetPos(titleX,titleY);
    printf("�� �� �� ��");
    SetPos(menuX,menuY);
    printf("1 �������̵�");
    SetPos(menuX,menuY+1);
    printf("2 ��������̵�");
    SetPos(menuX,menuY+2);
    printf("3 ���ճ����̵�");
    SetPos(menuX,menuY+3);
    printf("0 ������һ��");
    SetPos(menuX,menuY+4);
    printf("����������ѡ��:\t");
}
//�������̵�
void totalSum(in_Goods *TodayIG, out_Goods *TodayOG, VIP *TodayV){
    system("cls");
    printf("����\t��Ʒ����\t����\t����\t��������\t������\t��ע\t�ϼ�\n");
    in_Goods *cur1 = TodayIG;
    int num = 0;
    while(cur1 != NULL){
        printf("%05d\t%-16s%-8d%-8.2f%d/%d/%-9d%-8s���%11.2fԪ\n",
               cur1->goods_id,cur1->name,cur1->P_In_num,cur1->P_price,
               cur1->In_date.year,cur1->In_date.month,cur1->In_date.day,
               cur1->admin,-1*cur1->P_In_num*cur1->P_price);

        SUM -= cur1->P_In_num*cur1->P_price;
        cur1 = cur1->next;
        num++;
    }
    out_Goods *cur = TodayOG;
    while(cur != NULL){
        printf("%05d\t%-16s%-8d%-8.2f%d/%d/%-9d%-8s����%11.2fԪ\n",
               cur->goods_id,cur->name,cur->Out_num,cur->S_price,
               cur->Out_date.year,cur->Out_date.month,cur->Out_date.day,
               cur->admin,cur->Out_num*cur->S_price*cur->discount*0.1);

        SUM += cur->Out_num*cur->S_price*cur->discount*0.1;
        cur = cur->next;
        num++;
    }
    VIP *cur3 = TodayV;
    while(cur3 != NULL){
        printf("\t\t\t\t\t\t\t\t���Ա\t88.00Ԫ\n");
        cur3 = cur3->next;
        SUM += 88;
        num++;
    }
    printf("�ϼ�: ���쵽Ŀǰ��ˮΪ:\t%.2fԪ\n",SUM);
    printf("���� %d ������\n",num);
    system("pause");
}
//��������̵�
void InSum(in_Goods *TodayIG){
    system("cls");
    printf("����\t��Ʒ����\t�������\t������λ\t��������\t��������\t�������\t����\t������\t�ϼ�\n");
    in_Goods *cur = TodayIG;
    int num = 0;
    while(cur != NULL){
        printf("%05d\t%-16s%-16d%-16s%-16.2f%d/%d/%-9d%d/%d/%-8d%-9s%-8s-%.2fԪ\n",
                cur->goods_id,cur->name,cur->P_In_num,cur->unit,cur->P_price,
                cur->P_date.year,cur->P_date.month,cur->P_date.day,
                cur->In_date.year,cur->In_date.month,cur->In_date.day,
                cur->kind,cur->admin,cur->P_In_num*cur->P_price);
        expense += cur->P_In_num*cur->P_price;
        cur = cur->next;
        num++;
    }
    printf("�ϼ�: ���쵽Ŀǰ֧��:\t%.2fԪ\n",expense);
    printf("���� %d ������\n",num);
    system("pause");
}
//���ճ����̵�
void OutSum(out_Goods *TodayOG){
    system("cls");
    printf("����\t��Ʒ����\t��������\t��������\t��������\t�ۿ�\t������\t��ע\t�ϼ�\n");
    out_Goods *cur = TodayOG;
    int num = 0;
    while(cur != NULL){
        printf("%05d\t%-16s%-16d%-16.2f%d/%d/%-9d%-8.1f%-8s%-8s%.2fԪ\n",
               cur->goods_id,cur->name,cur->Out_num,cur->S_price,
               cur->Out_date.year,cur->Out_date.month,cur->Out_date.day,
               cur->discount,cur->admin,cur->remark,cur->Out_num*cur->S_price*cur->discount*0.1);

        EARN += cur->Out_num*cur->S_price*cur->discount*0.1;
        cur = cur->next;
        num++;
    }
    printf("�ϼ�: ���쵽Ŀǰ��������:\t%.2fԪ\n",EARN);
    printf("���� %d ������\n",num);
    system("pause");
}
//��ȡ����ע���Ա
VIP* GetTodayVIP(Date today, VIP* V_Head){
    VIP *cur = V_Head->next;
    while(cur != NULL){
        if(today.year == cur->RegTime.year&&today.month == cur->RegTime.month&&today.day == cur->RegTime.day)
            return cur;
        cur = cur->next;
    }
    return cur;
}
//��ȡ�������
in_Goods* GetTodayIG(Date today, in_Goods *IG_Head){
    in_Goods *cur = IG_Head->next;
    while(cur != NULL){
        if(today.year == cur->In_date.year&&today.month == cur->In_date.month&&today.day == cur->In_date.day)
            return cur;
        cur = cur->next;
    }
    return cur;
}
//��ȡ���ճ���
out_Goods* GetTodayOG(Date today, out_Goods *OG_Head){
    out_Goods *cur = OG_Head->next;
    while(cur != NULL){
        if(today.year == cur->Out_date.year&&today.month == cur->Out_date.month&&today.day == cur->Out_date.day)
            return cur;
        cur = cur->next;
    }
    return cur;
}