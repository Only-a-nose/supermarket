///*1.5.4
//�Ż��˲����߼����û�����
//�޸�����֪bug*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include <math.h>

void Search_This(in_Goods *inGoods_Head, int a, int b[]) {
    in_Goods *existence = inGoods_Head->next;
    while (existence != NULL) {
        if (a == existence->goods_id) {
            if (existence->P_num != 0) {
                b[0] += existence->P_num;
                b[1]++;
            }
        }
        existence = existence->next;
    }
}

int New_kind_of_good(Goods *G_Head)
{
    system("cls");
    SetPos(titleX + 0, titleY + 0);
    printf("��������Ʒ��Ϣ��");
    SetPos(titleX + 0, titleY + 1);
    printf("���ƣ�");
    SetPos(titleX + 0, titleY + 2);
    printf("���ţ�");
    SetPos(titleX + 0, titleY + 3);
    printf("���ң�");
    SetPos(titleX + 0, titleY + 4);
    printf("������:      ��    ��    ��");
    SetPos(titleX + 0, titleY + 5);
    printf("��λ��");
    SetPos(titleX + 0, titleY + 6);
    printf("�ۻ����ۣ�      .  Ԫ");
    SetPos(titleX + 0, titleY + 7);
    printf("��Ʒ���");
    SetPos(titleX + 0, titleY + 8);
    printf("������ޣ�");
    int Max = 0;
    int id = 0, isnum = 2, isfive = 0;
    char c;
    double pri = 0;
    char nam[20], manufacturer[20], uni[20], kin[20], temp[50];
    Date tim;
    tim.year = tim.month = tim.day = 0;

    SetPos(titleX + 9, titleY + 1);//�������� char
    while (1) {
        SetPos(titleX + 9, titleY + 1);
        memset(temp, 0, sizeof(temp));
        s_get(temp,50);
        if (strlen(temp) >= name_size || strlen(temp) < 1) {
            SetPos(titleX + 9, titleY + 1);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(titleX + 9, titleY + 1);
            printf("�Ƿ�����:����������        ");
            Sleep(1000);
            SetPos(titleX + 9, titleY + 1);
            printf("                               ");
        }
        else {
            strcpy(nam, temp);
            break;
        }
    }

    SetPos(titleX + 9, titleY + 2);//������� int
    while (1)
    {
        SetPos(titleX + 9, titleY + 2);
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
            SetPos(titleX + 9, titleY + 2);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 9, titleY + 2);
            printf("�Ƿ�����:����������                             ");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 2);
            printf("���ţ�                                                                          ");
        }
        else { break; }
    }
    Goods* position = FindByID_2(id, G_Head);
    if (position)
    {
        system("cls");
        SetPos(titleX + 0, titleY +0);
        printf("�Ѵ��ڸû�����Ʒ����������½���Ʒ��");
        SetPos(titleX + 0, titleY +1);
        system("pause");
        return 0;
    }

    SetPos(titleX + 9, titleY + 3);//���볧�� char
    while (1) {
        SetPos(titleX + 9, titleY + 3);
        memset(temp, 0, sizeof(temp));
        s_get(temp,50);
        if (strlen(temp) >= name_size || strlen(temp) < 1) {
            SetPos(titleX + 9, titleY + 3);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(titleX + 9, titleY + 3);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 9, titleY + 3);
            printf("                          ");
        }
        else {
            strcpy(manufacturer, temp);
            break;
        }
    }

    SetPos(titleX + 9, titleY + 4);//���뱣���ڣ��� int
    while (1)
    {
        SetPos(titleX + 9, titleY + 4);
        tim.year = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { tim.year = tim.year * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 4 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 9, titleY + 4);
            int i;
            for (i = 0; i < isfive; i++)printf("   ");
            SetPos(titleX + 9, titleY + 4);
            printf("�Ƿ�����:����������         ");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 4);
            printf("������:      ��    ��    ��                              ");
        }
        else { break; }
    }

    SetPos(titleX + 17, titleY + 4);//���뱣���ڣ��� int
    while (1)
    {
        SetPos(titleX + 17, titleY + 4);
        tim.month = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { tim.month = tim.month * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 17, titleY + 4);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 15, titleY + 4);
            printf("�Ƿ�����:����������        ");
            Sleep(1000);
            SetPos(titleX + 15, titleY + 4);
            printf("    ��    ��                          ");
        }
        else { break; }
    }

    SetPos(titleX + 23, titleY + 4);//���뱣���ڣ��� int
    while (1)
    {
        SetPos(titleX + 23, titleY + 4);
        tim.day = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { tim.day = tim.day * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 23, titleY + 4);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 23, titleY + 4);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 21, titleY + 4);
            printf("    ��                 ");
        }
        else { break; }
    }

    SetPos(titleX + 9, titleY + 5);//���뵥λ char
    while (1) {
        SetPos(titleX + 9, titleY + 5);
        memset(temp, 0, sizeof(temp));
        s_get(temp,50);
        if (strlen(temp) >= name_size || strlen(temp) < 1) {
            SetPos(titleX + 9, titleY + 5);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(titleX + 9, titleY + 5);
            printf("�Ƿ�����:����������                      ");
            Sleep(1000);
            SetPos(titleX + 9, titleY + 5);
            printf("                                           ");
        }
        else {
            strcpy(uni, temp);
            break;
        }
    }

    SetPos(titleX + 11, titleY + 6);//����۸� double��С����ǰ��
    while (1)
    {
        SetPos(titleX + 11, titleY + 6);
        pri = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { pri = pri * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isnum != 0 || isfive == 0||isfive>5) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 11, titleY + 6);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 11, titleY + 6);
            printf("�Ƿ�����:���������벻������λ��     ");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 6);
            printf("�ۻ����ۣ�      .  Ԫ                                 ");
        }
        else { break; }
    }

    SetPos(titleX + 17, titleY + 6);//����۸� double��С�����
    while (1)
    {
        SetPos(titleX + 17, titleY + 6);
        float s = 0;
        isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') //С��������ִ�����
            {
                float  i = 0;
                for (i = 0; i < isfive + 1; i++)s = s + (c - '0') / pow(10, isfive + 1);

            }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive != 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 17, titleY + 6);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 17, titleY + 6);
            printf("�Ƿ�����:������С�������λ        ");
            Sleep(1000);
            SetPos(titleX + 17, titleY + 6);
            printf("  Ԫ                                                        ");
        }
        else {
            pri = pri + s;
            break;
        }
    }

    SetPos(titleX + 11, titleY + 7);//�������� char
    while (1) {
        SetPos(titleX + 11, titleY + 7);
        memset(temp, 0, sizeof(temp));
        s_get(temp,50);
        if (strlen(temp) >= name_size || strlen(temp) < 1) {
            SetPos(titleX + 11, titleY + 7);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(titleX + 11, titleY + 7);
            printf("�Ƿ�����:����������    ");
            Sleep(1000);
            SetPos(titleX + 11, titleY + 7);
            printf("                                ");
        }
        else {
            strcpy(kin, temp);
            break;
        }
    }

    SetPos(titleX + 11, titleY + 8);//��������� int
    while (1)
    {
        SetPos(titleX + 11, titleY + 8);
        Max = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9')
            {
                Max = Max * 10 + c - '0';
            }
            else { isnum = 1; }
            isfive++;
        }
        if (isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 11, titleY + 8);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 11, titleY + 8);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 8);
            printf("������ޣ�                              ");
        }
        else { break; }
    }

    SetPos(titleX, titleY + 9);
    printf("��������Y/N");
    char t;//����Y��N
    SetPos(titleX + 15, titleY + 9);
    while (1) {
        SetPos(titleX + 15, titleY + 9);
        isfive = isnum = 0;

        while ((t = getchar()) != '\n') {
            c = t;
        }
        if (c != 'N' && c != 'Y' && c != 'n' && c != 'y')//���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 15, titleY + 9);
            printf("�Ƿ�����:����������                                 ");
            Sleep(1000);
            SetPos(titleX + 15, titleY + 9);
            printf("                                                                   ");
        }
        else { break; }
    }
    if (c == 'N' || c == 'n')
    {
        SetPos(titleX + 0, titleY + 10);
        printf("��ȡ��������Ʒ������");
        Sleep(2000);
        return 0;
    }

    position = (Goods*)malloc(sizeof(Goods));
    Goods* Cur = G_Head;
    while (Cur->next)
    {
        Cur = Cur->next;
    }
    strcpy(position->name, nam);
    position->goods_id = id;
    strcpy(position->Manufacturer, manufacturer);
    position->Q_G_period = tim;                              //��ֵ
    strcpy(position->unit, uni);
    position->S_price = pri;
    position->MaximumNum = Max;
    strcpy(position->kind, kin);
    position->sales_volume = 0;
    position->avg_time = 0;
    position->discount = 10;
    position->total_num = 0;
    Cur->next = position;
    position->next = NULL;
    WriteGoods(G_Head);
    SetPos(titleX + 0 ,titleY + 10);
    printf("��Ʒ�½��ɹ���");
    SetPos(titleX + 0 ,titleY + 11);
    system("pause");
    return 0;
}

void Inputmenu()
{
    SetPos(titleX, titleY);
    printf("�� �� �� ��");
    SetPos(menuX, menuY);
    printf("1 ���");
    SetPos(menuX, menuY + 1);
    printf("2 �½���Ʒ��Ϣ");
    SetPos(menuX, menuY + 2);
    printf("0 �������˵�");
    SetPos(menuX, menuY + 3);
    printf("����������ѡ��");
}

int New_shipment(Admin* administer, Goods* G_Head, in_Goods* inGoods_Head)
{
    int id = 0, isnum = 2, isfive = 0;
    char c;

    system("cls");
    SetPos(titleX + 0, titleY + 1);
    printf("�����������Ʒ�Ļ��ţ�");

    SetPos(titleX + 25, titleY + 1);              //������
    while (1)
    {
        SetPos(titleX + 25, titleY + 1);
        isfive = isnum = 0;
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
            SetPos(titleX + 25, titleY + 1);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 25, titleY + 1);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 25, titleY + 1);
            printf("                                   ");
        }
        else { break; }
    }

    Goods* position = FindByID_2(id, G_Head);
    if (position == NULL)
    {
        system("cls");
        SetPos(titleX,titleY);
        printf("δ���ڸ���Ʒ����ǰȥ������Ʒ��Ϣ��");
        SetPos(titleX,titleY+1);
        system("pause");
        return 0;
    }
    else
    {
        SetPos(titleX + 0, titleY + 2);
        printf("���ڽ�����Ʒ %s �����", position->name);
        Sleep(2000);
    }

    system("cls");
    SetPos(titleX + 0, titleY + 0);
    printf("����������Σ�");
    SetPos(titleX + 0, titleY + 1);
    printf("�������ۣ�      .  Ԫ");
    SetPos(titleX + 0, titleY + 2);
    printf("����������");
    SetPos(titleX + 0, titleY + 3);
    printf("�������ڣ�      ��    ��    ��");
    int price = 0, num = 0;
    Date productime;
    productime.year = productime.month = productime.day = 0;

    SetPos(titleX + 11, titleY + 1);//��������μ۸� double��С����ǰ��
    while (1)
    {
        SetPos(titleX + 11, titleY + 1);
        price = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { price = price * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isnum != 0 || isfive == 0||isfive>5) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 11, titleY + 1);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 11, titleY + 1);
            printf("�Ƿ�����:���������벻������λ��");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 1);
            printf("�������ۣ�      .  Ԫ                                    ");
        }
        else { break; }
    }

    SetPos(titleX + 17, titleY + 1);//����۸� double��С�����
    while (1)
    {
        SetPos(titleX + 17, titleY + 1);
        float s = 0;
        isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') //С��������ִ�����
            {
                float  i = 0;
                for (i = 0; i < isfive + 1; i++)s = s + (c - '0') / pow(10, isfive + 1);

            }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive != 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 17, titleY + 1);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 17, titleY + 1);
            printf("�Ƿ�����:������С�������λ");
            Sleep(1000);
            SetPos(titleX + 17, titleY + 1);
            printf("  Ԫ                                                  ");
        }
        else {
            price = price + s;
            break;
        }
    }

    SetPos(titleX + 11, titleY + 2);   //����������
    while (1)
    {
        SetPos(titleX + 11, titleY + 2);
        num = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9')
            {
                num = num * 10 + c - '0';
            }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 5 || isnum != 0 || isfive == 0||num==0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 11, titleY + 2);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 11, titleY + 2);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 11, titleY + 2);
            printf("                                 ");
        }
        else { break; }
    }

    SetPos(titleX + 12, titleY + 3);      //��������
    while (1)
    {
        SetPos(titleX + 12, titleY + 3);
        productime.year = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { productime.year = productime.year * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive != 4 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 12, titleY + 3);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 12, titleY + 3);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 3);
            printf("�������ڣ�      ��    ��    ��                 ");
        }
        else { break; }
    }

    SetPos(titleX + 20, titleY + 3);      //��
    while (1)
    {
        SetPos(titleX + 20, titleY + 3);
        productime.month = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { productime.month = productime.month * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 20, titleY + 3);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 20, titleY + 3);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 18, titleY + 3);
            printf("    ��    ��               ");
        }
        else { break; }
    }

    SetPos(titleX + 26, titleY + 3);       //��
    while (1)
    {
        SetPos(titleX + 26, titleY + 3);
        productime.day = isfive = isnum = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9') { productime.day = productime.day * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isfive > 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 26, titleY + 3);
            int i;
            for (i = 0; i < isfive; i++)printf("  ");
            SetPos(titleX + 26, titleY + 3);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 24, titleY + 3);
            printf("    ��                     ");
        }
        else { break; }
    }

    SetPos(titleX, titleY + 4);
    printf("���ڽ��� %s %05d ������������������Y/N",position->name,position->goods_id);
    char t;//����Y��N
    SetPos(titleX+0, titleY + 5);
    while (1) {
        SetPos(titleX + 0, titleY + 5);
        isfive = isnum = 0;

        while ((t = getchar()) != '\n') {
            c = t;
        }
        if (c != 'N' && c != 'Y'&&c!='n'&&c!='y')//���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 50, titleY + 5);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 5);
            printf("                              ");
        }
        else { break; }
    }
    if (c == 'N'||c=='n')
    {
        SetPos(titleX + 0, titleY + 6);
        printf("��ȡ����������");
        Sleep(2000);
        return 0;
    }

    in_Goods* cur = inGoods_Head;
    in_Goods* New = NULL;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    New = (in_Goods*)malloc(sizeof(in_Goods));
    New->goods_id = position->goods_id;
    strcpy(New->name, position->name);
    New->P_num = New->P_In_num = num;
    position->total_num += num;
    strcpy(New->unit, position->unit);
    New->P_price = price;
    New->P_date = productime;
    New->In_date = GetTodayDate();
    strcpy(New->kind, position->kind);
    strcpy(New->admin, administer->name);
    cur->next = New;
    New->next = NULL;
    WriteGoods(G_Head);
    WriteInGoods(inGoods_Head);
    //}
    int b[2] = { 0, 0 };
    Search_This(inGoods_Head, id, b);
    SetPos(titleX + 0, titleY + 5);
    printf("��ǰ��Ʒ %s %05d �ڲֿ��й��ƴ��� %d ����%d ���Ρ�", position->name, id, b[0], b[1]);
    SetPos(titleX + 0, titleY + 6);
    system("pause");
    if (b[0] >= 0.9 * position->MaximumNum) {
        SetPos(titleX + 0, titleY + 7);
        printf("����Ʒ��ǰ�����ӽ�����棬��ע�⡣");
        SetPos(titleX + 0, titleY + 8);
        system("pause");
    }
    return 0;
}

void InputMain(Admin* administer, Goods* G_Head, in_Goods* inGoods_Head)
{
    int choice = 1;
    while (choice) {
        system("cls");
        choice = 0;
        Inputmenu();
        choice = GetChoice();
        switch (choice) {
        case 1:
            New_shipment( administer, G_Head,  inGoods_Head);
            break;
        case 2:
            New_kind_of_good( G_Head);
            break;
        case 0:
            break;
        }
    }
}