#include "FindGoods.h"
#include <stdio.h>
#include "ChangeGoodsInfo.h"

void FindMain(Goods *G_Head, in_Goods *inGoods_Head) {
    int choice;
    while (1) {
        system("cls");
        SetPos(titleX, titleY);
        printf("��Ʒ��ѯ�˵�");
        SetPos(menuX, menuY);
        printf("1.����Ʒ���Ʋ�ѯ");
        SetPos(menuX, menuY + 1);
        printf("2.����Ʒ���Ų�ѯ");
        SetPos(menuX, menuY + 2);
        printf("3.����Ʒ���Ҳ�ѯ");
        SetPos(menuX, menuY + 3);
        printf("4.����Ʒ����ѯ");
        SetPos(menuX, menuY + 4);
        printf("5.ģ����ѯ");
        SetPos(menuX, menuY + 5);
        printf("6.��Ʒ�����볧����ϲ�ѯ");
        SetPos(menuX, menuY + 6);
        printf("0.�˳�ϵͳ");
        SetPos(menuX, menuY + 7);
        printf("����������ѡ��:");
        choice = 0;
        choice = GetChoice();
        switch (choice) {
            case 0:
                break;
            case 1:
                find_1(G_Head, inGoods_Head);
                break;
            case 2:
                find_2(G_Head, inGoods_Head);
                break;
            case 3:
                find_3(G_Head);
                break;
            case 4:
                find_4(G_Head);
                break;
            case 5:
                find_5(G_Head);
                break;
            case 6:
                find_6(G_Head);
            default:
                break;
        }
        if (choice == 0) break;
    }
}

//�������Ʋ�ѯ
void find_1(Goods *G_Head, in_Goods *inGoods_Head) {
    system("cls");
    int j = 1;
    int i = 0;
    char name[50];
    char temp[50];
    int a[50];
    SetPos(menuX, menuY);
    printf("��������Ҫ��ѯ��Ʒ������:");
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 30, menuY);
        s_get(temp, 50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 30, titleY + 2);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(menuX + 30, titleY + 2);
            printf("�Ƿ�:\t�����������������������     ");
            Sleep(1000);
            SetPos(menuX + 30, titleY + 2);
            printf("                                                                       ");
        } else {
            strcpy(name, temp);
            break;
        }
    }
    system("cls");
    Goods *p;//�ڻ��������в�ѯ
    p = FindByName_2(name, G_Head);
    if (p == NULL) {
        SetPos(menuX, menuY + 2);
        printf("�޸���Ʒ");
        SetPos(menuX, menuY + 3);
        system("pause");
    } else {
        printf("����\t��Ʒ����\t����\t����\t������\t�������\t��������\t��������\t��������\t�ۻ�����\t������(��/��/��)\t����\t����\t�ۿ�\t\n");
        in_Goods *q;//����������в�ѯ
        q = inGoods_Head->next;
        while (q != NULL) {
            if (strcmp(q->name, name) == 0) {
                if (q->P_num != 0) {
                    printf("%05d\t%-16s%05d\t%-8s%-8s%-16d%d/%d/%-10d%-15.2f%-16s%-16.2f%d/%d/%-19d%-8d%-8d%.2f\n", j,
                           q->name, q->goods_id, q->kind, q->admin, q->P_In_num, q->P_date.year, q->P_date.month,
                           q->P_date.day, q->P_price, p->Manufacturer, p->S_price, p->Q_G_period.year,
                           p->Q_G_period.month, p->Q_G_period.day, p->sales_volume, p->total_num, p->discount);
                    j++;

                }
                q = q->next;
            } else q = q->next;
        }
        Goods *k;
        k = G_Head->next;
        while (k != NULL) {
            if (strcmp(k->name, name) == 0) {
                i++;
            }
            k = k->next;
        }
        printf("����%s����Ʒһ����%d��\n", name, i);
        system("pause");
    }
}

void find_2(Goods *G_Head, in_Goods *inGoods_Head) {
    system("cls");
    int i = 1;
    int j = 0;
    int id;

    while (1) {
        SetPos(menuX, menuY);
        printf("��������Ҫ��ѯ��Ʒ�Ļ���:");
        id = GetId();
        if (id == -1 || id == -2) {
            SetPos(menuX, menuY);
            printf("��������Ҫ��ѯ��Ʒ�Ļ���:�����ʽ��������������                                                           ");
            Sleep(800);
            SetPos(menuX, menuY);
            printf("                                                                                         ");
        } else
            break;
    }
    system("cls");
    Goods *p;//�ڻ��������в�ѯ
    p = FindByID_2(id, G_Head);
    if (p == NULL) {
        SetPos(menuX, menuY + 2);
        printf("�޸���Ʒ\n");
        SetPos(menuX, menuY + 3);
        system("pause");
    } else {
        printf("����\t��Ʒ����\t����\t����\t������\t�������\t��������\t��������\t��������\t�ۻ�����\t������(��/��/��)\t����\t���\t�ۿ�\t\n");
        in_Goods *q;//����������в�ѯ
        q = inGoods_Head->next;
        while (q != NULL) {
            if (q->goods_id == id) {
                if (q->P_num != 0) {
                    printf("%05d\t%-16s%05d\t%-8s%-8s%-16d%d/%d/%-10d%-15.2f%-16s%-16.2f%d/%d/%-19d%-8d%-8d%.2f\n", i,
                           q->name, q->goods_id, q->kind, q->admin, q->P_In_num, q->P_date.year, q->P_date.month,
                           q->P_date.day, q->P_price, p->Manufacturer, p->S_price, p->Q_G_period.year,
                           p->Q_G_period.month, p->Q_G_period.day, p->sales_volume, p->total_num, p->discount);
                    i++;
                    j++;
                    q = q->next;
                } else q = q->next;
            } else q = q->next;
        }
        printf("ͳ�ƣ�%s��Ʒ��һ�����%d�������%d\n", p->name, j, p->total_num);
        system("pause");
    }
}

void find_3(Goods *G_Head) {
    system("cls");
    int j = 0;
    int i = 0;
    char facture[50];
    char temp[50];
    SetPos(menuX, menuY);
    printf("��������Ҫ��ѯ����������:");
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 30, menuY);
        s_get(temp, 50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 30, titleY + 2);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(menuX + 30, titleY + 2);
            printf("�Ƿ�:\t�������������������");
            Sleep(1000);
            SetPos(menuX + 30, titleY + 2);
            printf("                                                                       ");
        } else {
            strcpy(facture, temp);
            break;
        }
    }
    system("cls");
    Goods *q;//�ڻ��������в�ѯ
    q = G_Head->next;
    printf("��Ʒ����\t����\t��Ʒ����\t�ۻ�����\t������(��/��/��)\t����\t���\t�ۿ�\t\n");
    while (q != NULL) {
        if (strcmp(q->Manufacturer, facture) == 0) {
            printf("%-16s%05d\t%-16s%-16.2f%d/%d/%-19d%-8d%-8d%.2f\n", q->name, q->goods_id, q->kind, q->S_price,
                   q->Q_G_period.year, q->Q_G_period.month, q->Q_G_period.day, q->sales_volume, q->total_num,
                   q->discount);
            j = 1;
            i++;
            q = q->next;
        } else q = q->next;
    }
    if (j == 0) {
        SetPos(menuX, menuY + 2);
        printf("δ�ҵ�����������\n");
        SetPos(menuX, menuY + 3);
        system("pause");
        return;
    } else {
        printf("ͳ�ƣ�%s���ң�һ��%d����Ʒ\n", facture, i);
    }
    system("pause");
}


void find_4(Goods *G_Head) {
    system("cls");
    int j = 0;
    int i = 0;
    char kind[50];
    char temp[50];
    SetPos(menuX, menuY);
    printf("��������Ҫ��ѯ����Ʒ����:");
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 30, menuY);
        s_get(temp, 50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 30, titleY + 2);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(menuX + 30, titleY + 2);
            printf("�Ƿ�:\t�������������������");
            Sleep(1000);
            SetPos(menuX + 30, titleY + 2);
            printf("                                                            ");
        } else {
            strcpy(kind, temp);
            break;
        }
    }
    system("cls");
    Goods *q;//�ڻ��������в�ѯ
    q = G_Head->next;
    printf("��Ʒ����\t����\t��������\t�ۻ�����\t������(��/��/��)\t����\t���\t�ۿ�\t\n");
    while (q != NULL) {
        if (strcmp(q->kind, kind) == 0) {
            printf("%-16s%05d\t%-16s%-16.2f%d/%d/%-19d%-8d%-8d%.2f\n", q->name, q->goods_id, q->Manufacturer,
                   q->S_price, q->Q_G_period.year, q->Q_G_period.month, q->Q_G_period.day, q->sales_volume,
                   q->total_num, q->discount);
            j = 1;
            i++;
            q = q->next;
        } else q = q->next;
    }
    if (j == 0) {
        SetPos(menuX, menuY + 2);
        printf("�޸�����Ʒ\n");
        SetPos(menuX, menuY + 3);
        system("pause");
        return;
    } else {
        printf("ͳ�ƣ�%s�����Ʒ��һ��%d��\n", kind, i);
    }
    system("pause");
}

void find_5(Goods *G_Head) {
    system("cls");
    int j = 0;
    char words[50];
    char temp[50];
    SetPos(menuX, menuY);
    printf("������ģ���ʻ�:");
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX+15, menuY);
        s_get(temp, 50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 15, titleY + 2);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(menuX + 15, titleY + 2);
            printf("�Ƿ�:\t�������������������");
            Sleep(1000);
            SetPos(menuX + 15, titleY + 2);
            printf("                                                                       ");
        } else {
            strcpy(words, temp);
            break;
        }
    }
    system("cls");
    Goods *q;//�ڻ��������в�ѯ
    q = G_Head->next;
    printf("��Ʒ����\t����\t��������\t�ۻ�����\t������(��/��/��)\t����\t���\t�ۿ�\t\n");
    while (q != NULL) {
        if (compare(q->name, words) == 0) {
            printf("%-16s%05d\t%-16s%-16.2f%d/%d/%-19d%-8d%-8d%.2f\n", q->name, q->goods_id, q->Manufacturer,
                   q->S_price, q->Q_G_period.year, q->Q_G_period.month, q->Q_G_period.day, q->sales_volume,
                   q->total_num, q->discount);
            j = 1;
            printf("%s������%s\n", words, q->name);
            q = q->next;
        } else q = q->next;
    }
    if (j == 0) {
        SetPos(menuX, menuY + 2);
        printf("�޸���Ʒ\n");
        SetPos(menuX, menuY + 3);
        system("pause");
        return;
    }
    system("pause");
}

void find_6(Goods *G_Head) {
    system("cls");
    int j = 0;
    char facture[50];
    char name[50];
    char temp[50];
    SetPos(menuX, menuY);
    printf("��������Ҫ��ѯ����������:");
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 30, menuY);
        s_get(temp, 50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 30, titleY + 2);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(menuX + 30, titleY + 2);
            printf("�Ƿ�:\t�������������������");
            Sleep(1000);
            SetPos(menuX + 30, titleY + 2);
            printf("                                                      ");
        } else {
            strcpy(facture, temp);
            break;
        }
    }
    SetPos(menuX, menuY + 2);
    printf("��������Ҫ��ѯ��Ʒ������:");
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 30, menuY + 2);
        s_get(temp, 50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 30, titleY + 4);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf("   ");
            SetPos(menuX + 30, titleY + 4);
            printf("�Ƿ�:\t�����������������������");
            Sleep(1000);
            SetPos(menuX + 30, titleY + 4);
            printf("                                                      ");
        } else {
            strcpy(name, temp);
            break;
        }
    }
    system("cls");
    Goods *q;//�ڻ��������в�ѯ
    q = G_Head->next;
    printf("��Ʒ����\t����\t��Ʒ����\t�ۻ�����\t������(��/��/��)\t����\t���\t�ۿ�\t\n");
    while (q != NULL) {
        if (strcmp(q->Manufacturer, facture) == 0 && strcmp(q->name, name) == 0) {
            printf("%-16s%05d\t%-16s%-16.2f%d/%d/%-19d%-8d%-8d%.2f\n", q->name, q->goods_id, q->kind, q->S_price,
                   q->Q_G_period.year, q->Q_G_period.month, q->Q_G_period.day, q->sales_volume, q->total_num,
                   q->discount);
            j = 1;
            printf("ͳ�ƣ�%s���ҵ�%s��Ʒ�Ŀ��Ϊ%d\n", facture, name, q->total_num);
            q = q->next;
        } else q = q->next;
    }
    if (j == 0) {
        SetPos(menuX, menuY + 2);
        printf("δ�ҵ�������������Ʒ\n");
        SetPos(menuX, menuY + 3);
        system("pause");
        return;
    }
    system("pause");
}

int compare(char a[], char b[]) {
    int i = 0, j = 0;
    while (a[i] != '\0') {
        if (a[i] == b[j]) {
            i++;
            j++;
            if (b[j] == '\0') {
                return (0);
            }
        } else {
            if (a[i + 1] == '\0') {
                return (1);
            }
            i++;
        }
    }
}

