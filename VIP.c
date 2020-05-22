//
// Created by SGNY on 2020/5/9.
//

#include "VIP.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "admin.h"
#include "BackupRestore.h"
void VIPMain(Admin *A_Head, in_Goods *inGoods_Head, out_Goods *outGoods_Head,
             Goods *G_Head, VIP *V_Head){
    int choice;
    VIP *tp = NULL;
    while(1){
        choice = 0;
        VIPMenu();
        choice = GetChoice();
        switch (choice){
            case 1:
                SeeAll(V_Head); //�鿴��Ա
                break;
            case 2:
                RegisterVIP(V_Head);//ע���Ա
                break;
            case 3:
                tp = FindVIP(V_Head);//��ѯ��Ա
                SetPos(menuX,menuY);
                if(tp == NULL){
                    SetPos(menuX,menuY+1);
                    printf("���޴˻�Ա          ");
                }else if(tp != V_Head){
                    SetPos(menuX,menuY+1);
                    printf("����:%s",tp->name);
                    SetPos(menuX,menuY+2);
                    printf("�ֻ���:%s",tp->phone);
                    SetPos(menuX,menuY+3);
                    printf("ע��ʱ��(��/��/��):%d/%d/%d",tp->RegTime.year,tp->RegTime.month,tp->RegTime.day);
                }
                SetPos(menuX,menuY+4);
                system("pause");
                break;
            case 4:
                ChangeVIPInfo(V_Head);//�޸Ļ�Ա��Ϣ
                break;
            case 5:
                Register(A_Head);
                break;
            case 6:
                BandR(A_Head,inGoods_Head,outGoods_Head,G_Head,V_Head);
                break;
            default:
                break;
        }
        if(choice == 0){
            break;
        }
    }
}
//��Ա�˵�
void VIPMenu(){
    system("cls");
    SetPos(titleX,titleY);
    printf(" ����Ա����");
    SetPos(menuX,menuY);
    printf("1 �鿴��Ա");
    SetPos(menuX,menuY+1);
    printf("2 ע���Ա");
    SetPos(menuX,menuY+2);
    printf("3 ��ѯ��Ա");
    SetPos(menuX,menuY+3);
    printf("4 �޸Ļ�Ա��Ϣ");
    SetPos(menuX,menuY+4);
    printf("5 ע�����Ա");
    SetPos(menuX,menuY+5);
    printf("6 ���ݱ�����ָ�");
    SetPos(menuX,menuY+6);
    printf("0 ������һ��");
    SetPos(menuX,menuY+8);
    printf("����������ѡ�� ");
}
//�鿴��Ա
void SeeAll(VIP *V_Head){
    system("cls");
    printf("����\t\t�ֻ���\t\tע��ʱ��(��/��/��)\t\t\n");
    VIP *cur = V_Head->next;
    int flag = 0;
    while(cur != NULL){
        flag ++;
        printf("%-16s%-20s%d/%d/%d\n",cur->name,cur->phone,cur->RegTime.year,cur->RegTime.month,cur->RegTime.day);
        cur = cur->next;
    }
    printf("��Ա����:%d\n",flag);
    system("pause");
}
//ע���Ա
void RegisterVIP(VIP *V_Head){
    system("cls");
    VIP *p = (VIP*)malloc(sizeof(VIP));
    SetPos(titleX,titleY);
    printf("��Աע��");
    SetPos(menuX,menuY);
    printf("��  ��:\t");
    SetPos(menuX,menuY+1);
    printf("�ֻ���:\t");
    char temp[50];
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 9, menuY);
        s_get(temp,50);
        if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
            SetPos(menuX + 9, titleY + 1);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf(" ");
            SetPos(menuX + 9, titleY + 1);
            printf("�Ƿ�:\t�����������������������");
            Sleep(1000);
            SetPos(menuX + 9, titleY + 1);
            printf("                 ");
        } else {
            strcpy(p->name, temp);
            break;
        }
    }
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX + 9, menuY + 1);
        s_get(temp,50);
        if (strlen(temp) != 11) {      //�ж��ֻ���λ���Ƿ���ȷ
            SetPos(menuX + 9, menuY + 1);
            int i;
            for (i = 0; i < strlen(temp); i++)
                printf(" ");
            SetPos(menuX + 9, menuY + 1);
            printf("�Ƿ�:\t�ֻ�������Ƿ�������������");
            Sleep(1000);
            SetPos(menuX + 9, menuY + 1);
            printf("                                          ");
        } else {
            int i = 0;
            for (i = 0; i < 11; i++) {
                if (!isdigit(temp[i]))
                    break;
            }
            if (i == 11) {
                strcpy(p->phone,temp);
                break;
            }
            SetPos(menuX + 9, titleY + 3);
            printf("�ֻ��ź��з�����,����������");
            Sleep(1000);
            SetPos(menuX + 9, titleY + 3);
            printf("                                   ");
        }
    }
    SetPos(menuX,menuY+2);
    printf("�Ƿ�ע��  1��  0��");
    int choice = 0;
    while(1) {
        SetPos(menuX, menuY + 3);
        printf("����������ѡ��:\t");
        choice = GetChoice();
        if(choice == 1||choice == 0){
            Date today = GetTodayDate();
            p->RegTime = today;
            break;
        }
        SetPos(menuX, menuY + 3);
        printf("                                 ");
    }
    if(choice == 1){
        VIP* cur = V_Head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = p;
        p->next = NULL;
        WriteVIP(V_Head);
        system("cls");
        SetPos(titleX, titleY + 1);
        printf("ע��ɹ���");
        Sleep(1000);
        return;
    }else{
        free(p);
        return ;
    }
}
//��ѯ��Ա
VIP* FindVIP(VIP *V_Head){
    system("cls");
    SetPos(titleX,titleY);
    printf("��ѯ��Ա");
    SetPos(menuX,menuY);
    printf("�������Ա�ֻ���:");
    SetPos(menuX,menuY+1);
    printf("(����q�˳�)");
    char temp[50];
    while (1) {
        memset(temp, 0, sizeof(temp));
        SetPos(menuX,menuY);
        printf("�������Ա�ֻ���:");
        s_get(temp,50);
        if (strlen(temp) != 11) {      //�ж��ֻ���λ���Ƿ���ȷ
            SetPos(menuX, menuY);
            int i;
            printf("�������Ա�ֻ���:");
            if(strlen(temp) == 1&&(temp[0] == 'q'||temp[0] == 'Q')){
                return V_Head;
            }
            for (i = 0; i < strlen(temp); i++)
                printf(" ");
            SetPos(menuX, menuY);
            printf("�������Ա�ֻ���:�Ƿ�:�ֻ�������Ƿ�������������                  ");
            Sleep(800);
            SetPos(menuX,menuY);
            printf("�������Ա�ֻ���:                               ");
        } else {
            int i = 0;
            for (i = 0; i < 11; i++) {
                if (!isdigit(temp[i]))
                    break;
            }
            if (i == 11) {
                break;
            }
            SetPos(menuX+9, titleY);
            printf("�������Ա�ֻ���:�ֻ��ź��з�����,����������                    ");
            Sleep(800);
            SetPos(menuX,menuY);
            printf("�������Ա�ֻ���:                               ");
        }
    }
    VIP *cur = V_Head->next;
    while(cur != NULL){
        if(strcmp(cur->phone, temp) == 0){
            return cur;
        }
        cur = cur->next;
    }
    return cur;
}
//�޸Ļ�Ա��Ϣ
void ChangeVIPInfo(VIP *V_Head){
    VIP *NeedToCh = FindVIP(V_Head);
    SetPos(menuX,menuY);
    if(NeedToCh == NULL){
        SetPos(menuX,menuY+1);
        printf("���޴˻�Ա          ");
    }else if(NeedToCh != V_Head){
        SetPos(menuX,menuY+1);
        printf("����:%s",NeedToCh ->name);
        SetPos(menuX,menuY+2);
        printf("�ֻ���:%s",NeedToCh ->phone);
        SetPos(menuX,menuY+3);
        printf("ע��ʱ��(��/��/��):%d/%d/%d",NeedToCh ->RegTime.year,NeedToCh ->RegTime.month,NeedToCh ->RegTime.day);
    }
    if(NeedToCh == V_Head){
        return;
    }
    while(1) {
        SetPos(menuX, menuY + 4);
        printf("�����޸ĵ�ѡ��:  1����  2�ֻ���   0�˳�");
        SetPos(menuX, menuY + 5);
        printf("��������Ҫ�޸ĵ�ѡ��: ");
        int choice = GetChoice();
        switch (choice){
            case 1:
                SetPos(menuX, menuY + 4);
                printf("                                                ");
                SetPos(menuX, menuY + 5);
                printf("                                                ");
                SetPos(menuX, menuY + 4);
                printf("�������޸ĺ������: ");
                char temp[50];
                while (1) {
                    memset(temp, 0, sizeof(temp));
                    SetPos(menuX, menuY + 4);
                    printf("�������޸ĺ������: ");
                    s_get(temp,50);
                    if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
                        SetPos(menuX, menuY + 4);
                        printf("�������޸ĺ������: ");
                        int i;
                        for (i = 0; i < strlen(temp); i++)
                            printf(" ");
                        SetPos(menuX, menuY + 4);
                        printf("�������޸ĺ������: ERROR���������ֹ���");
                        Sleep(1000);
                        SetPos(menuX, menuY + 4);
                        printf("�������޸ĺ������:                                       ");
                    } else {
                        strcpy(NeedToCh->name, temp);
                        break;
                    }
                }
                WriteVIP(V_Head);
                break;
                case 2:
                SetPos(menuX, menuY + 4);
                printf("                                                ");
                SetPos(menuX, menuY + 5);
                printf("                                                ");
                SetPos(menuX, menuY + 4);
                printf("�������޸ĺ���ֻ���: ");
                while (1) {
                    memset(temp, 0, sizeof(temp));
                    SetPos(menuX, menuY + 4);
                    printf("�������޸ĺ���ֻ���: ");
                    s_get(temp,50);
                    if (strlen(temp) != 11) {      //�ж��ֻ���λ���Ƿ���ȷ
                        SetPos(menuX, menuY + 4);
                        printf("�������޸ĺ���ֻ���: ");
                        int i;
                        for (i = 0; i < strlen(temp); i++)
                            printf(" ");
                        SetPos(menuX, menuY + 4);
                        printf("�������޸ĺ���ֻ���: �Ƿ�:\t�ֻ�������Ƿ�������������");
                        Sleep(1000);
                        SetPos(menuX, menuY + 4);
                        printf("�������޸ĺ���ֻ���:                                     ");
                    } else {
                        int i = 0;
                        for (i = 0; i < 11; i++) {
                            if (!isdigit(temp[i]))
                                break;
                        }
                        if (i == 11) {
                            strcpy(NeedToCh->phone,temp);
                            break;
                        }
                        SetPos(menuX, titleY + 4);
                        printf("�������޸ĺ���ֻ���: �ֻ��ź��з�����,����������");
                        Sleep(1000);
                        SetPos(menuX, titleY + 4);
                        printf("�������޸ĺ���ֻ���:                                     ");
                    }
                }
                WriteVIP(V_Head);
                break;
            default:
                break;
        }
        if(0 == choice)
            break;
    }
}
//ɾ������
void FreeVIPNode(VIP *V_Head){
    VIP *cur = V_Head->next;
    VIP *temp = cur;
    while(cur!=NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(V_Head);
    V_Head = NULL;
}
//����Ա�Ƿ����,�����Զ�ɾ��
void DeleteIfOutDate(VIP *V_Head){
    VIP *cur = V_Head->next;
    VIP *B_cur = V_Head;
    VIP *temp = NULL;
    while(cur != NULL){
        if(GetRelativeTime(GetTodayDate())-GetRelativeTime(cur->RegTime) >= 365){
            temp = cur;
            B_cur->next = cur->next;
            cur = cur->next;
            free(temp);
            continue;
        }
        cur = cur->next;
        B_cur = B_cur->next;
    }
    WriteVIP(V_Head);
}
void BandR(Admin *A_Head, in_Goods *inGoods_Head, out_Goods *outGoods_Head,
           Goods *G_Head, VIP *V_Head){
    int choice = 0;
    while(1) {
        system("cls");
        SetPos(titleX,titleY);
        printf(" ���ݱ�����ָ�");
        SetPos(menuX,menuY);
        printf("1 ���ݱ���");
        SetPos(menuX,menuY+1);
        printf("2 ���ݻָ�");
        SetPos(menuX,menuY+2);
        printf("0 ������һ��");
        SetPos(menuX, menuY + 3);
        printf("����������ѡ��: ");
        choice = GetChoice();
        switch (choice){
            case 1:
                Backup(A_Head,inGoods_Head,outGoods_Head,G_Head,V_Head);
                SetPos(menuX, menuY + 4);
                printf("���ݱ��ݳɹ�");
                SetPos(menuX, menuY + 5);
                system("pause");
                break;
            case 2:
                Restore(A_Head,inGoods_Head,outGoods_Head,G_Head,V_Head);
                SetPos(menuX, menuY + 4);
                printf("���ݻָ��ɹ�");
                SetPos(menuX, menuY + 5);
                system("pause");
                break;
        }
        if(choice == 0){
            return ;
        }
    }
}