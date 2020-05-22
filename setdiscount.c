#include <stdio.h>
#include <stdlib.h>
#include "setdiscount.h"
#include <math.h>


void SetDiscountMenu() {
    SetPos(titleX, titleY);
    printf("�� �� �� ��");
    SetPos(menuX, menuY);
    printf("1 �����ۿ�");
    SetPos(menuX, menuY + 1);
    printf("2 ���������ۿ�");
    SetPos(menuX, menuY + 2);
    printf("0 �������˵�");
    SetPos(menuX, menuY + 3);
    printf("������ѡ��");
}

void InDiscount(Goods *G_Head) {
    system("cls");

    SetPos(titleX, titleY);
    printf("������Ҫ�����ۿ۵���Ʒ�������ۿ�");
    SetPos(titleX, titleY+1);
    printf("����12345  8.5�⼴������Ϊ12345����Ʒ����Ϊ������");
    SetPos(titleX, titleY + 2);
    printf("���ţ�");
    SetPos(titleX, titleY + 3);
    printf("�ۿۣ�  . ��");

    int id = 0, isnum = 2, isfive = 0;
    char c;
    double dis = 0;

    SetPos(titleX+8, titleY+2);//������� int
    while (1)
    {
        SetPos(titleX + 8, titleY + 2);
        id = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9')
            {
                id = id * 10 + c - '0';
            }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 5 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 8, titleY + 2);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 8, titleY + 2);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 2);
            printf("���ţ�                              ");
        }
        else { break; }
    }

    SetPos(titleX+7, titleY+3);//�����ۿ� С����ǰ
    while (1)
    {
        SetPos(titleX + 7, titleY + 3);
        dis = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { dis = dis * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isnum != 0 || isfive != 1) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 7, titleY + 3);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 7, titleY + 3);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 3);
            printf("�ۿۣ�  . ��                      ");
        }
        else { break; }
    }

    SetPos(titleX + 9, titleY + 3);//�����ۿ� С�����
    while (1)
    {
        SetPos(titleX + 9, titleY + 3);
        float s = 0;
        isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') //С��������ִ�����
            {
                float  i = 0;
                for (i = 0; i < isfive + 1; i++)s = s + (c - '0') / pow(10,isfive+1);

            }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive != 1 || isnum != 0 || isfive != 1) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 9, titleY + 3);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 9, titleY + 3);
            printf("�Ƿ�����:������С�����һλ");
            Sleep(1000);
            SetPos(titleX + 9, titleY + 3);
            printf("  ��                         ");
        }
        else {
            dis = dis + s;
            break;
        }
    }

    Goods *temp;
    temp = FindByID_2(id, G_Head);
    SetPos(titleX + 0, titleY + 4);
    if (temp == NULL)
    {
        printf("δ���ڸ���Ʒ��������š�");
    }
    else
    { 
        temp->discount = dis;
        printf("��Ʒ %s ������Ϊ%.1f�ۡ�", temp->name, dis);
    }
    Sleep(2000);
    WriteGoods(G_Head);
}

void DeleteDiscount(Goods *G_Head) {
    system("cls");
    int isfive, isnum;
    char t, c;
    SetPos(titleX, titleY);
    printf("ȷ��Ҫ��������ۿ���?Y/N");
    SetPos(titleX + 25, titleY);//����Y/N
    while (1) {
        SetPos(titleX + 25, titleY + 0);
        isfive = isnum = 0;

        while ((t = getchar()) != '\n') {
            c = t;
        }
        if (c != 'N' && c != 'Y'&&c!='n'&&c!='y')//���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 25, titleY + 0);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 25, titleY + 0);
            printf("                              ");
        }
        else { break; }
    }
    if (c == 'N'||c=='n')
    {
        SetPos(titleX, titleY+1);
        printf("��ȡ������ۿ۲�����");
        Sleep(2000);
        return ;
    }
    else
    {
        Goods *temp = G_Head;
        while (temp) {
            temp->discount = 10;
            temp = temp->next;
        }
        WriteGoods(G_Head);
        SetPos(titleX, titleY+1);
        printf("����ۿ۲����ɹ���");
        Sleep(2000);
    }
    
}

void SetDiscountMain(Goods *G_Head) {
    int choice = 1;
    while (choice) {
        system("cls");
        choice = 0;
        SetDiscountMenu();
        choice = GetChoice();
        switch (choice) {
            case 1:
                InDiscount(G_Head);
                break;
            case 2:
                DeleteDiscount(G_Head);
                break;
            case 0:
                break;
        }//�˳�����
    }
}