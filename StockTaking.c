//
// Created by SGNY on 2020/5/9.
//
#include "StockTaking.h"
#include <stdio.h>
//����̵�
//����̵�������
void StockTakingMain(Goods *G_Head, in_Goods *IG_Head) {
    int Num = GetNumOfGoods(G_Head);      //��ȡ������Ʒ����
    Goods *GoodsArray = NULL;
    if (Num != 0) {          //����д���Ʒ
        GoodsArray = BuildArray(Num, G_Head); //������̬����
        GetAvgTime(GoodsArray, IG_Head, Num); //��ȡÿ����Ʒ�ڿ�ƽ��ʱ��
        int choice;
        while (1) {
            choice = 0;
            STMenu();
            choice = GetChoice();
            switch (choice) {
                case 1:
                    STBySalesVol(GoodsArray, 0, Num-1);
                    Order(Num, GoodsArray);
                    break;
                case 2:
                    STByInNum(GoodsArray, 0, Num-1);
                    Order(Num, GoodsArray);
                    break;
                case 3:
                    STById(GoodsArray, 0, Num-1);
                    Order(Num, GoodsArray);
                    break;
                case 4:
                    STByName(GoodsArray, 0, Num-1);
                    Order(Num, GoodsArray);
                    break;
                case 5:
                    STByAvgTime(GoodsArray, 0, Num-1);
                    Order(Num, GoodsArray);
                    break;
                case 6:
                    STBYKind(GoodsArray, 0, Num-1);
                    Order(Num, GoodsArray);
                    break;
                default:
                    break;
            }
            if (choice == 0) {
                free(GoodsArray);
                break;
            }
        }
    } else {
        system("cls");
        SetPos(titleX, titleY);
        printf("����ǿյ�\n");
        system("pause");
    }
}

//����̵�˵�
void STMenu() {
    system("cls");
    SetPos(titleX, titleY);
    printf("�� �� �� ��");
    SetPos(menuX, menuY);
    printf("1 �������̵�");
    SetPos(menuX, menuY + 1);
    printf("2 ����������̵�");
    SetPos(menuX, menuY + 2);
    printf("3 �������̵�");
    SetPos(menuX, menuY + 3);
    printf("4 �������̵�");
    SetPos(menuX, menuY + 4);
    printf("5 ��ƽ���ڿ�ʱ���̵�");
    SetPos(menuX, menuY + 5);
    printf("6 �������̵�");
    SetPos(menuX, menuY + 6);
    printf("0 �������˵�");
    SetPos(menuX, menuY + 7);
    printf("����������ѡ��:\t");
}

//��ȡ�������Ʒ����
int GetNumOfGoods(Goods *G_Head) {
    Goods *cur = G_Head->next;
    int num = 0;
    while (cur != NULL) {
        num++;
        cur = cur->next;
    }
    return num;
}

//������̬��Ʒ����
Goods *BuildArray(int Num, Goods *G_Head) {
    Goods *room = (Goods *) malloc(Num * sizeof(Goods));
    Goods *cur = G_Head->next;
    int i = 0;
    while (cur != NULL) {
        room[i].goods_id = cur->goods_id;
        strcpy(room[i].name, cur->name);
        room[i].S_price = cur->S_price;
        strcpy(room[i].kind, cur->kind);
        room[i].total_num = cur->total_num;
        room[i].Q_G_period = cur->Q_G_period;
        room[i].sales_volume = cur->sales_volume;
        strcpy(room[i].unit, cur->unit);
        strcpy(room[i].Manufacturer, cur->Manufacturer);
        room[i].avg_time = 0;
        room[i].discount = cur->discount;
        cur = cur->next;
        i++;
    }
    return room;
}

//����������
void STBySalesVol(Goods *room, int l, int r) {
    int mid = room[(l + r) / 2].sales_volume;      //ȡ�м�һ��������ֵ
    int i = l, j = r;
    while (i <= j) {
        while (room[i].sales_volume < mid) i++; //���С���м�ֵ���м�ֵ����ߣ�λ�ò���
        while (room[j].sales_volume > mid) j--;//��������м�ֵ���м�ֵ���ұߣ�λ�ò���
        if (i <= j) {
            mySwap(&room[i], &room[j]);
            i++;
            j--;
        }
    }
    if (l < j) STBySalesVol(room, l, j);
    if (i < r) STBySalesVol(room, i, r);
}

//�������������
void STByInNum(Goods *room, int l, int r) {
    int mid = room[(l + r) / 2].total_num;      //ȡ�м�һ�����������ֵ
    int i = l, j = r;
    while (i <= j) {
        while (room[i].total_num < mid) i++; //���С���м�ֵ���м�ֵ����ߣ�λ�ò���
        while (room[j].total_num > mid) j--;//��������м�ֵ���м�ֵ���ұߣ�λ�ò���
        if (i <= j) {
            mySwap(&room[i], &room[j]);
            i++;
            j--;
        }
    }
    if (l < j) STByInNum(room, l, j);
    if (i < r) STByInNum(room, i, r);
}

//����������
void STById(Goods *room, int l, int r) {
    int mid = room[(l + r) / 2].goods_id;      //ȡ�м�һ�����ŵ�ֵ
    int i = l, j = r;
    while (i <= j) {
        while (room[i].goods_id < mid) i++; //���С���м�ֵ���м�ֵ����ߣ�λ�ò���
        while (room[j].goods_id > mid) j--;//��������м�ֵ���м�ֵ���ұߣ�λ�ò���
        if (i <= j) {
            mySwap(&room[i], &room[j]);
            i++;
            j--;
        }
    }
    if (l < j) STById(room, l, j);
    if (i < r) STById(room, i, r);
}

//����������
void STByName(Goods *room, int l, int r) {
    char *mid = (char*)malloc(50*sizeof(char));
    strcpy(mid, room[(l + r) / 2].name);
    int i = l, j = r;
    while (i <= j) {
        while (strcmp(room[i].name, mid) < 0) i++; //���С���м�ֵ���м�ֵ����ߣ�λ�ò���
        while (strcmp(room[j].name, mid) > 0) j--; //��������м�ֵ���м�ֵ���ұߣ�λ�ò���
        if (i <= j) {
            mySwap(&room[i], &room[j]);
            i++;
            j--;
        }
    }
    free(mid);
    if (l < j) STByName(room, l, j);
    if (i < r) STByName(room, i, r);
}

//��ƽ���ڿ�ʱ������
void STByAvgTime(Goods *room, int l, int r) {
    double mid = room[(l + r) / 2].avg_time;      //ȡ�м�һ�����ŵ�ֵ
    int i = l, j = r;
    while (i <= j) {
        while (room[i].avg_time < mid) i++; //���С���м�ֵ���м�ֵ����ߣ�λ�ò���
        while (room[j].avg_time > mid) j--;//��������м�ֵ���м�ֵ���ұߣ�λ�ò���
        if (i <= j) {
            mySwap(&room[i], &room[j]);
            i++;
            j--;
        }
    }
    if (l < j) STByAvgTime(room, l, j);
    if (i < r) STByAvgTime(room, i, r);
}

//����������
void STBYKind(Goods *room, int l, int r) {
    char *mid = (char*)malloc(50*sizeof(char));
    strcpy(mid, room[(l + r) / 2].kind);
    int i = l, j = r;
    while (i <= j) {
        while (strcmp(room[i].kind, mid) < 0) i++; //���С���м�ֵ���м�ֵ����ߣ�λ�ò���
        while (strcmp(room[j].kind, mid) > 0) j--;//��������м�ֵ���м�ֵ���ұߣ�λ�ò���
        if (i <= j) {
            mySwap(&room[i], &room[j]);
            i++;
            j--;
        }
    }
    free(mid);
    if (l < j) STByName(room, l, j);
    if (i < r) STByName(room, i, r);
}

//��������
void mySwap(Goods *g1, Goods *g2) {
    Goods temp;
    temp.goods_id = g1->goods_id;
    strcpy(temp.name, g1->name);
    temp.S_price = g1->S_price;
    strcpy(temp.kind, g1->kind);
    temp.total_num = g1->total_num;
    temp.Q_G_period = g1->Q_G_period;
    temp.sales_volume = g1->sales_volume;
    strcpy(temp.unit, g1->unit);
    strcpy(temp.Manufacturer, g1->Manufacturer);
    temp.avg_time = g1->avg_time;
    temp.discount = g1->discount;
    g1->goods_id = g2->goods_id;
    strcpy(g1->name, g2->name);
    g1->S_price = g2->S_price;
    strcpy(g1->kind, g2->kind);
    g1->total_num = g2->total_num;
    g1->Q_G_period = g2->Q_G_period;
    g1->sales_volume = g2->sales_volume;
    strcpy(g1->unit, g2->unit);
    strcpy(g1->Manufacturer, g2->Manufacturer);
    g1->avg_time = g2->avg_time;
    g1->discount = g2->discount;
    g2->goods_id = temp.goods_id;
    strcpy(g2->name, temp.name);
    g2->S_price = temp.S_price;
    strcpy(g2->kind, temp.kind);
    g2->total_num = temp.total_num;
    g2->Q_G_period = temp.Q_G_period;
    g2->sales_volume = temp.sales_volume;
    strcpy(g2->unit, temp.unit);
    strcpy(g2->Manufacturer, temp.Manufacturer);
    g2->avg_time = temp.avg_time;
    g2->discount = temp.discount;
}

//����ĳ����Ʒ��ƽ���ڿ�ʱ��
void GetAvgTime(Goods *room, in_Goods *IG_Head, int Num) {
    int i = 0;
    in_Goods *cur = IG_Head->next;
    in_Goods *tp = NULL;
    while (cur != NULL&& cur->P_num == 0 ) {  //�ҵ���һ�������������Σ���û�з���NULL
        cur = cur->next;
    }
    double sum = 0;
    int day = 0;
    for (i = 0; i < Num; i++) {
        tp = cur;
        sum = 0;
        day = 0;
        while (tp != NULL&& tp!=IG_Head) {
            if (tp->goods_id == room[i].goods_id) {
                day = GetRelativeTime(GetTodayDate()) - GetRelativeTime(tp->In_date);
                sum += day * tp->P_num;
            }
            tp = tp->next;
        }
        if (room[i].total_num != 0)
            room[i].avg_time = (sum*1.0) / room[i].total_num;
        else
            room[i].avg_time = 0;
    }
}

//ѡ��������
void Order(int Num, Goods *room) {
    int choice = 0;
    while (1) {
        system("cls");
        SetPos(titleX, titleY);
        printf("��ѡ������ʽ: 1 ���� 2 ���� 0 ������һ��");
        SetPos(titleX, titleY + 1);
        printf("����������ѡ��:\t");
        choice = GetChoice();
        switch (choice) {
            case 1: {//��С����
                system("cls");
                printf("����\t��Ʒ����\t�ۻ�����\t����\t�û�������\t������\t\t����\t������λ\t��������\tƽ���ڿ�ʱ��\t�ۿ�\t\n");
                int i = 0;
                for (i = 0; i < Num; i++) {
                    printf("%05d\t%-18s%-14.2f%-12s%-10d%d��%d��%d��  \t%-10d%-14s%-18s%-14.5f%.1f\n",
                           room[i].goods_id, room[i].name, room[i].S_price, room[i].kind, room[i].total_num,
                           room[i].Q_G_period.year,
                           room[i].Q_G_period.month, room[i].Q_G_period.day, room[i].sales_volume, room[i].unit,
                           room[i].Manufacturer,
                           room[i].avg_time, room[i].discount);
                }
                printf("\n���� %d ������\n",i);
                system("pause");
                break;
            }
            case 2: {//�Ӵ�С
                system("cls");
                printf("����\t��Ʒ����\t�ۻ�����\t����\t�û�������\t������\t\t����\t������λ\t��������\tƽ���ڿ�ʱ��\t�ۿ�\t\n");
                int i = 0;
                int j = 0;
                for (i = Num - 1; i >= 0; i--) {
                    printf("%05d\t%-18s%-14.2f%-12s%-10d%d��%d��%d��  \t%-10d%-14s%-18s%-14.5f%.1f\n",
                           room[i].goods_id, room[i].name, room[i].S_price, room[i].kind, room[i].total_num,
                           room[i].Q_G_period.year,
                           room[i].Q_G_period.month, room[i].Q_G_period.day, room[i].sales_volume, room[i].unit,
                           room[i].Manufacturer,
                           room[i].avg_time, room[i].discount);
                    j++;
                }
                printf("\n���� %d ������\n",j);
                system("pause");
                break;
            }
            default:
                break;
        }
        if (choice == 0)
            break;
    }
}