//
// Created by SGNY on 2020/5/8.
//
//�����ṹ��͹��õĺ���
#ifndef SUPER_V1_STRUCTANDFX_H
#define SUPER_V1_STRUCTANDFX_H

#define    name_size  20
#define    titleX     80       //�˵�����λ��
#define    titleY     15        //�˵�����λ��
#define    menuX      80       //�˵�ѡ��λ��
#define    menuY      17        //�˵�ѡ��λ��

#include <stdlib.h>
#include <windows.h>
#include <string.h>

//���ڽṹ��
typedef struct date {
    int year, month, day;
} Date;
//������û���ṹ��
typedef struct in_goods {
    int    goods_id;                      //����
    char   name[name_size];               //��������
    int    P_num;                         //��������䣩
    int    P_In_num;                      //������������䣩
    char   unit[name_size];               //������λ
    double P_price;                       //��������
    Date   P_date;                        //��������
    Date   In_date;                       //�������
    char   kind[name_size];               //����
    char   admin[name_size];              //������
    struct in_goods *next;
} in_Goods;
//���ܻ���ṹ��
typedef struct goods {
    int    goods_id;                      //����
    char   name[name_size];               //��Ʒ����
    double S_price;                       //�ۻ�����
    char   kind[name_size];               //����
    int    total_num;                     //�û�������
    Date   Q_G_period;                    //������
    int    sales_volume;                  //����
    char   unit[name_size];               //������λ
    char   Manufacturer[name_size];       //��������
    double avg_time;                      //ƽ���ڿ�ʱ��
    double discount;                      //�ۿ�
    int    MaximumNum;                     //���������
    struct goods *next;
} Goods;
//�������ýṹ��
typedef struct out_goods {
    int    goods_id;                       //����
    char   name[name_size];                //��������
    int    Out_num;                        //��������
    double S_price;                        //��������
    double discount;                       //�ۿ�
    char   remark[name_size];              //��ע
    Date   P_date;                         //��������
    Date   Out_date;                       //��������
    char   admin[name_size];               //������
    struct out_goods *next;
} out_Goods;
//����Ա
typedef struct admin {
    char admin_id[name_size];              //����
    char name[name_size];                  //����
    char pwd[name_size];              //����
    char phone[name_size];                 //�ֻ���
    char qu[name_size];              //�ܱ�����
    char ans[name_size];                //��
    struct admin *next;
} Admin;

//��Ա
typedef struct vip {
    char name[name_size];                  //����
    char phone[11];                        //�ֻ���
    Date RegTime;                          //ע��ʱ��
    struct vip *next;
} VIP;

//���˵�
void MainMenu();
//���ù��λ��
void SetPos(int x, int y);
//��ȡ�ַ���
char* s_get(char* st, int n);
//ѡ��˵���ȡ�û�ѡ����
int GetChoice();

//��ȡ��ǰʱ��
Date GetTodayDate();

//�ڻ�����ͨ��������ѯ
Goods* FindByName_2(char *name, Goods *G_Head);
//�ڻ�����ͨ��id��ѯ
Goods* FindByID_2(int id, Goods *G_Head);

//�������ʱ��
int GetRelativeTime(Date day);

//���ļ���д�ļ�
//����Ա����
Admin* ReadAdmin();
void WriteAdmin(Admin *A_Head);
//�������
in_Goods* ReadInGoods();
void WriteInGoods(in_Goods *inGoods_Head);
//��������
out_Goods* ReadOutGoods();
void WriteOutGoods(out_Goods *outGoods_Head);
//��������
Goods* ReadGoods();
void WriteGoods(Goods *G_Head);
//VIP
VIP* ReadVIP();
void WriteVIP(VIP *V_Head);



void FreeInGoodsNode(in_Goods *IG_Head);
void FreeOutGoodsNode(out_Goods *OG_Head);
void FreeGoodsNode(Goods *G_Head);

#endif //SUPER_V1_STRUCTANDFX_H