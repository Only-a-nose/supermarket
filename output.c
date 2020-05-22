#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "VIP.h"
#include <string.h>
#include "output.h"

void Search_This_1(in_Goods *inGoods_Head, int a, int b[]) {
    in_Goods *existence;
    existence = inGoods_Head;
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


void OutPutMenu() {
    system("cls");
    SetPos(titleX, titleY);
    printf("���ǵ���Ʒӵ�б����ڣ��뱣֤���ȳ����������Ρ�");
    SetPos(menuX, menuY);
    printf("1 ��������");
    SetPos(menuX, menuY + 1);
    printf("2 �˻�");
    SetPos(menuX, menuY + 2);
    printf("0 �������˵�");
    SetPos(menuX, menuY + 3);
    printf("������ѡ��");
}

int Sale(out_Goods *outGoods_Head, in_Goods *inGoods_Head, Goods *G_Head, Admin *administer, VIP *V_Head) {
    system("cls");

    int id = 0, coun = 0, isnum = 2, isfive = 0;
    char c;
    out_Goods *Newout;
    out_Goods *outcur = outGoods_Head;
    in_Goods *in = inGoods_Head;

    SetPos(titleX, titleY);
    printf("��������Ʒ���ţ�");
    SetPos(titleX, titleY + 1);
    printf("�������۳�������");

    SetPos(titleX + 19, titleY + 0);//������� int
    while (1) {
        SetPos(titleX + 19, titleY + 0);
        id = isfive = isnum = 0;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') {
                id = id * 10 + c - '0';
            } else { isnum = 1; }
            isfive++;
        }
        if (isfive > 5 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 19, titleY + 0);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 9, titleY + 0);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 0);
            printf("��������Ʒ���ţ�                            ");
        } else { break; }
    }

    SetPos(titleX + 19, titleY + 1);//�������� int
    while (1) {
        SetPos(titleX + 19, titleY + 1);
        coun = isfive = isnum = 0;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') {
                coun = coun * 10 + c - '0';
            } else { isnum = 1; }
            isfive++;
        }
        if (isfive > 5 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 19, titleY + 1);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 19, titleY + 1);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 1);
            printf("�������۳�������                           ");
        } else { break; }
    }

    SetPos(titleX + 0, titleY + 2);//���ų���
    Goods *position = FindByID_2(id, G_Head);
    if (position == NULL) {
        printf("δ�и���Ʒ");
        SetPos(titleX + 0, titleY + 3);
        system("pause");
        return 0;
    }

    SetPos(titleX + 0, titleY + 2);//��������
    if (coun > position->total_num) {
        printf("�����������ڿ��������������Ż����������");
        SetPos(titleX + 0, titleY + 3);
        system("pause");
        return 0;
    }

    SetPos(titleX + 0, titleY + 2);
    if (position->discount == 10) {
        printf("����Ʒ�ۼ۹���%.2lfԪ", position->S_price*coun);
    } else {
        printf("����Ʒ�ۼ۹���%.2lfԪ����%.1lf��", position->S_price * position->discount / 10*coun, position->discount);
    }

    SetPos(titleX + 0, titleY + 3);
    printf("�Ƿ��л�Ա��Y/N��");
    SetPos(titleX + 19, titleY + 3);
    char t;//����Y��N
    while (1) {
        SetPos(titleX + 19, titleY + 3);
        isfive = isnum = 0;

        while ((t = getchar()) != '\n') {
            c = t;
        }
        if (c != 'N' && c != 'Y' && c != 'n' && c != 'y')//���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 19, titleY + 3);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 19, titleY + 3);
            printf("                              ");
        }
        else { break; }
    }

    if (c == 'N'||c=='n') {
        SetPos(titleX + 0, titleY + 4);
        printf("�Ƿ�ע���ԱY/N��");//�Ƿ�ע��
        while (1) {
            SetPos(titleX + 19, titleY + 4);
            isfive = isnum = 0;
            while ((t = getchar()) != '\n') {
                c = t;
            }
            if (c != 'N' && c != 'Y' && c != 'n' && c != 'y')//���Ƴ������Ƿ�Ϊ����
            {
                SetPos(titleX + 19, titleY + 4);
                printf("�Ƿ�����:����������");
                Sleep(1000);
                SetPos(titleX + 19, titleY + 4);
                printf("                              ");
            }
            else { break; }
        }

        //ע���Ա����
        if (c == 'Y'||c=='y') {
            RegisterVIP(V_Head);             //ע���Ա

            SetPos(titleX, titleY + 3);
            printf("��Ա���ۣ�ʵ�ʹ���%.2lfԪ��", position->S_price* position->discount / 10 * 0.9*coun);
            while (outcur->next) {
                outcur = outcur->next;
            }
            Newout = (out_Goods *) malloc(sizeof(out_Goods));
            Newout->goods_id = position->goods_id;
            strcpy(Newout->name, position->name);
            Newout->Out_num = coun;
            Newout->S_price = position->S_price * position->discount / 10*0.9;
            Newout->discount = position->discount;
            strcpy(Newout->remark, "��Ա");
            Newout->Out_date = GetTodayDate();
            Newout->P_date.year = Newout->P_date.month = Newout->P_date.day = 0;
            strcpy(Newout->admin, administer->name);
            outcur->next = Newout;
            outcur = Newout;
            outcur->next = NULL;
            position->total_num -= coun;

            while (in)   //�ӿ���м�ȥ
            {
                if (in->goods_id == id && in->P_num != 0) {
                    if (in->P_num > coun) {
                        in->P_num -= coun;
                        position->sales_volume += coun;
                        coun = 0;
                    } else {
                        coun -= in->P_num;
                        position->sales_volume += in->P_num;
                        in->P_num = 0;
                    }
                }
                if (coun == 0)break;
                in = in->next;
            }
            WriteGoods(G_Head);
            WriteInGoods(inGoods_Head);
            WriteOutGoods(outGoods_Head);

            SetPos(titleX, titleY + 4);
            system("pause");

        }
            //�ǻ�Ա����
        else  {
            while (outcur->next) {
                outcur = outcur->next;
            }
            Newout = malloc(sizeof(out_Goods));
            Newout->goods_id = position->goods_id;
            strcpy(Newout->name, position->name);
            Newout->Out_num = coun;
            Newout->S_price = position->S_price * position->discount / 10;
            Newout->discount = position->discount;
            strcpy(Newout->remark, "�ǻ�Ա");
            Newout->Out_date = GetTodayDate();
            Newout->P_date.year = Newout->P_date.month = Newout->P_date.day = 0;
            strcpy(Newout->admin, administer->name);
            outcur->next = Newout;
            outcur = Newout;
            outcur->next = NULL;
            position->total_num -= coun;

            while (in)   //�ӿ���м�ȥ
            {
                if (in->goods_id == id && in->P_num != 0) {
                    if (in->P_num > coun) {
                        in->P_num -= coun;
                        position->sales_volume += coun;
                        coun = 0;
                    } else {
                        coun -= in->P_num;
                        position->sales_volume += in->P_num;
                        in->P_num = 0;
                    }
                }
                if (coun == 0)break;
                in = in->next;
            }
            WriteGoods(G_Head);
            WriteInGoods(inGoods_Head);
            WriteOutGoods(outGoods_Head);
        }
    }

        //���л�Ա����
    else  {
        VIP *isvip = FindVIP(V_Head);
        if (isvip == V_Head) {
            SetPos(titleX + 0, titleY + 4);
            printf("ȡ��ȷ�ϻ�Ա�����������½��г��⡣");
            SetPos(titleX + 0, titleY + 5);
            system("pause");
            return 0;
        }

        SetPos(titleX, titleY + 3);
        printf("��Ա���ۣ�ʵ�ʹ���%.2lfԪ��", position->S_price* position->discount / 10 * 0.9*coun);

        while (outcur->next) {
            outcur = outcur->next;
        }
        Newout = malloc(sizeof(out_Goods));
        Newout->goods_id = position->goods_id;
        strcpy(Newout->name, position->name);
        Newout->Out_num = coun;
        Newout->S_price = position->S_price * position->discount / 10*0.9;
        Newout->discount = position->discount;
        strcpy(Newout->remark, "��Ա");
        Newout->Out_date = GetTodayDate();
        Newout->P_date.year = Newout->P_date.month = Newout->P_date.day = 0;
        strcpy(Newout->admin, administer->name);
        outcur->next = Newout;
        outcur = Newout;
        outcur->next = NULL;
        position->total_num -= coun;

        while (in)   //�ӿ���м�ȥ
        {
            if (in->goods_id == id && in->P_num != 0) {
                if (in->P_num > coun) {
                    in->P_num -= coun;
                    position->sales_volume += coun;
                    coun = 0;
                } else {
                    coun -= in->P_num;
                    position->sales_volume += in->P_num;
                    in->P_num = 0;
                }
            }
            if (coun == 0)break;
            in = in->next;
        }
        WriteGoods(G_Head);
        WriteInGoods(inGoods_Head);
        WriteOutGoods(outGoods_Head);

        SetPos(titleX, titleY + 4);
        system("pause");

    }
    SetPos(titleX + 0, titleY + 6);
    printf("����ɹ���");
    Sleep(2000);
    return 0;
}

int Return(out_Goods *outGoods_Head, in_Goods *inGoods_Head, Goods *G_Head, Admin *administer) {
    system("cls");        //�˻�
    int id = 0, coun = 0, isnum = 2, isfive = 0;
    double pri = 0;
    char c;
    out_Goods *Newout;
    out_Goods *returncur = outGoods_Head;
    in_Goods *in = inGoods_Head;

    SetPos(titleX + 0, titleY + 0);
    printf("��������ţ�");
    SetPos(titleX + 0, titleY + 1);
    printf("�˻����ۣ�      .  Ԫ");
    SetPos(titleX, titleY + 2);
    printf("������������");


    SetPos(titleX + 14, titleY + 0);//����
    while (1) {
        SetPos(titleX + 14, titleY + 0);
        id = isfive = isnum = 0;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') {
                id = id * 10 + c - '0';
            } else { isnum = 1; }
            isfive++;
        }
        if (isfive > 5 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 14, titleY + 0);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 14, titleY + 0);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 0);
            printf("��������ţ�                            ");
        } else { break; }
    }

    SetPos(titleX + 11, titleY + 1);//   С����ǰ
    while (1) {
        SetPos(titleX + 11, titleY + 1);
        pri = isfive = isnum = 0;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') { pri = pri * 10 + c - '0'; }
            else { isnum = 1; }
            isfive++;
        }
        if (isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 11, titleY + 1);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 11, titleY + 1);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 1);
            printf("�˻����ۣ�      .  Ԫ                 ");
        } else { break; }
    }

    SetPos(titleX + 17, titleY + 1);//    С�����
    while (1) {
        SetPos(titleX + 17, titleY + 1);
        float s = 0;
        isfive = isnum = 0;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') //С��������ִ�����
            {
                float i = 0;
                for (i = 0; i < isfive + 1; i++)s = s + (c - '0') / pow(10, isfive + 1);

            } 
            else { isnum = 1; }
            isfive++;
        }
        if (isfive != 2 || isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 17, titleY + 1);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 17, titleY + 1);
            printf("�Ƿ�����:������С�������λ");
            Sleep(1000);
            SetPos(titleX + 17, titleY + 1);
            printf("  Ԫ                         ");
        } else {
            pri = pri + s;
            break;
        }
    }

    SetPos(titleX + 14, titleY + 2);//   ���� int
    while (1) {
        SetPos(titleX + 14, titleY + 2);
        isfive = isnum = 0;
        while ((c = getchar()) != '\n') {
            if (c >= '0' && c <= '9') {
                coun = coun * 10 + c - '0';
            } else { isnum = 1; }
            isfive++;
        }
        if (isnum != 0 || isfive == 0) //���Ƴ������Ƿ�Ϊ����
        {
            SetPos(titleX + 14, titleY + 2);
            int i;
            for (i = 0; i < isfive; i++)printf(" ");
            SetPos(titleX + 14, titleY + 2);
            printf("�Ƿ�����:����������");
            Sleep(1000);
            SetPos(titleX + 0, titleY + 2);
            printf("������������                            ");
        } else { break; }
    }

    Goods *position;
    position = FindByID_2(id, G_Head);
    SetPos(titleX + 0, titleY + 3);

    if (position == NULL) {
        SetPos(titleX + 0, titleY + 3);
        printf("δ�и���Ʒ���֤������");
        SetPos(titleX + 0, titleY + 4);
        system("pause");
        return 0;
    }

    if (coun > position->total_num) {
        SetPos(titleX + 0, titleY + 3);
        printf("�����������ڿ��������������Ż����������");
        SetPos(titleX + 0, titleY + 4);
        system("pause");
        return 0;
    }

    while (returncur->next) {
        returncur = returncur->next;
    }
    Newout = malloc(sizeof(out_Goods));
    Newout->goods_id = position->goods_id;
    strcpy(Newout->name, position->name);
    Newout->Out_num = coun;
    Newout->S_price = pri;
    Newout->discount = position->discount;
    strcpy(Newout->remark, "�˻�");
    Newout->Out_date = GetTodayDate();
    strcpy(Newout->admin, administer->name);
    returncur->next = Newout;
    returncur = Newout;
    returncur->next = NULL;
    position->total_num -= coun;

    while (in)   //�ӿ���м�ȥ
    {
        if (in->goods_id == id && in->P_num != 0) {
            if (in->P_num > coun) {
                in->P_num -= coun;
                coun = 0;
            } else {
                coun -= in->P_num;
                in->P_num = 0;
            }
        }
        if (coun == 0)break;
        in = in->next;
    }
    WriteGoods(G_Head);
    WriteInGoods(inGoods_Head);

    int b[2] = {0, 0};
    Search_This_1(inGoods_Head, id, b);
    SetPos(titleX + 0, titleY + 3);
    printf("��ǰ��Ʒ%s%d�ڲֿ��й��ƴ���%d����%d���Ρ�", position->name, id, b[0], b[1]);
    if (b[0] <= 0.1 * position->MaximumNum) {
        SetPos(titleX + 0, titleY + 4);
        printf("����Ʒ��ǰ�������٣���ע�⡣");
    }
    SetPos(titleX + 0, titleY + 5);
    system("pause");
    return 0;
}

void OutPutMain(out_Goods *outGoods_Head, in_Goods *inGoods_Head, Goods *G_Head, Admin *administer, VIP *V_Head) {
    int choice = 1;
    while (choice) {
        system("cls");
        choice = 0;
        OutPutMenu();
        choice = GetChoice();
        switch (choice) {
            case 1:
                Sale(outGoods_Head, inGoods_Head, G_Head, administer, V_Head);
                break;
            case 2:
                Return(outGoods_Head, inGoods_Head, G_Head, administer);
                break;
            case 0:
                break;
        }
    }
}
