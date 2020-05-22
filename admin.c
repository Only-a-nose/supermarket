//
// Created by SGNY on 2020/5/8.
//
#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
Admin* AdminMain(Admin *A_Head){
    system("cls");
    Admin *administer = NULL;
    while(1) {
        AdminMenu();//��ʾ�˵�
        int choice = GetChoice();//��ȡѡ��
        switch (choice){
            case 1:
                administer = SignIn(A_Head);
                break;
            case 2:
                ForgetPwd(A_Head);
                break;
            case 3:
                ChangePwd(A_Head);
                break;
            default:
                break;
        }
        if(choice == 0) {   //�����0�˳�
            WriteAdmin(A_Head);
            FreeAdminNode(A_Head);
            return NULL;
        }
        if(administer != NULL) {
            WriteAdmin(A_Head);
            return administer;
        }
    }

}
//��ӡ��ʼ�˵�
void AdminMenu(){
    system("cls");
    SetPos(titleX-13,titleY-2);
    printf("*******������Ʒ�����Ϣ����ϵͳ*******");
    int i = 0;
    for(i = 1;i <= 10;i++){
        SetPos(titleX-13,titleY-2+i);
        printf("*");
        SetPos(titleX+24,titleY-2+i);
        printf("*");
    }
    for(i = 1;i <= 36;i++){
        SetPos(titleX-13+i,titleY-2+10);
        printf("*");
    }
    SetPos(titleX,titleY);
    printf("�� ʼ �� ��");
    SetPos(menuX,menuY);
    printf("1 �˺ŵ�½");
    SetPos(menuX,menuY+1);
    printf("2 ��������");
    SetPos(menuX,menuY+2);
    printf("3 �޸�����");
    SetPos(menuX,menuY+3);
    printf("0 �˳�ϵͳ");
    SetPos(menuX,menuY+4);
    printf("����������ѡ�� ");
}

//�˺ŵ�½
Admin* SignIn(Admin *A_Head){
    int isExist = 0;       //�˺��Ƿ����
    int isCorrect = 0;     //�����Ƿ���ȷ
    int inCorrect = 0;     //���벻��ȷ����
    char acc[50];
    while(!isCorrect) {
        system("cls");
        SetPos(titleX,titleY);
        printf("  �� ½");
        SetPos(titleX, titleY + 1);
        printf("�˺�:\t");
        SetPos(titleX, titleY + 2);
        printf("����:\t");

        memset(acc,0,sizeof(acc));
        int size = 0;
        char c;
        SetPos(titleX+6, titleY + 1);
        while ((c = getchar()) != '\n') {
            acc[size++] = c;
            if (size == name_size - 1)
                break;
        }
        acc[size] = '\0';
        isExist = CheckAcc(acc,A_Head);
        if(isExist == 0) {
            SetPos(titleX, titleY + 3);
            printf("�˺Ų�����\n");
            SetPos(titleX, titleY + 4);
            system("pause");
            return 0;  //��½ʧ��
        }
        size = 0;
        SetPos(titleX+6, titleY + 2);
        char pwd[50];
        memset(pwd,0,sizeof(pwd));
        while (1) {//��������  ��������
            c = getch();
            if(c == '\b') {
                if(size > 0) {
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    size--;
                    continue;
                }else{
                    continue;
                }
            }
            if (size == 12||c == '\r')
                break;
            putch('*');
            pwd[size++] = c;
        }
        pwd[size] = '\0';
        isCorrect =  CheckAccPwd(acc,pwd,A_Head);
        if(isCorrect == 0) {
            SetPos(titleX, titleY + 3);
            printf("�˺Ż��������\n");
            Sleep(500);
            inCorrect++;
        }
        if(inCorrect == 5) {
            SetPos(titleX, titleY + 3);
            printf("���Ѿ�5��������룬������������\n");
            SetPos(titleX, titleY + 4);
            system("pause");
            return NULL;//��½ʧ��
        }
    }
    SetPos(titleX, titleY + 3);
    printf("��½�ɹ�\n");
    Sleep(1000);
    return FindAdmin(acc,A_Head);//��½�ɹ�
}
//����˺��Ƿ����
int  CheckAcc(char *acc, Admin *A_Head){
    Admin *cur = A_Head->next;
    while(cur != NULL){
        if(strcmp(acc,cur->admin_id) == 0){
            return 1; //����
        }
        cur = cur->next;
    }
    return 0; //������
}
//����˺������Ƿ�ƥ��
int  CheckAccPwd(char *acc, char *pwd,Admin *A_Head){
    Admin *cur = A_Head->next;
    while(cur != NULL){
        if(strcmp(acc,cur->admin_id) == 0){
            if(strcmp(pwd,cur->pwd) == 0)
              return 1; //ƥ��
            else
                return 0;
        }
        cur = cur->next;
    }
}
//���ص�½����Աָ��
Admin* FindAdmin(char *acc, Admin *A_Head){
    Admin *cur = A_Head->next;
    while(cur != NULL){
        if(strcmp(acc,cur->admin_id) == 0){
            return cur; //����
        }
        cur = cur->next;
    }
}
//�û�ע��
void Register(Admin *A_Head){
    int choice = 1;
    Admin *p = (Admin *) malloc(sizeof(Admin));
    while (1) {
        system("cls");
        SetPos(titleX, titleY);
        printf("  ע ��");
        system("cls");
        SetPos(titleX, titleY + 1);
        printf("��  ��:\t");
        SetPos(titleX, titleY + 2);
        printf("��  ��:\t");
        SetPos(titleX, titleY + 3);
        printf("�ֻ���:\t");
        SetPos(titleX, titleY + 4);
        printf("����:\t");
        SetPos(titleX, titleY + 5);
        printf("ȷ������:\t");
        SetPos(titleX, titleY + 6);
        printf("�ܱ�����:\t");
        SetPos(titleX, titleY + 7);
        printf("��:\t");
        SetPos(titleX, titleY + 8);
        printf("(������Ϊ��½�˺�)");
        char temp[50];
        while (1) {
            memset(temp, 0, sizeof(temp));
            SetPos(titleX + 9, titleY + 1);
            s_get(temp,50);
            if (strlen(temp) >= name_size) {      //�ж������Ƿ��������
                SetPos(titleX + 9, titleY + 1);
                int i;
                for (i = 0; i < strlen(temp); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 1);
                printf("�Ƿ�:\t�����������������������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 1);
                printf("                                 ");
            } else {
                strcpy(p->name, temp);
                break;
            }
        }
        while (1) {
            memset(temp, 0, sizeof(temp));
            SetPos(titleX + 9, titleY + 2);
            s_get(temp,50);
            if (strlen(temp) >= name_size) {      //�жϹ����Ƿ��������
                SetPos(titleX + 9, titleY + 2);
                int i;
                for (i = 0; i < strlen(temp); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 2);
                printf("�Ƿ�:\t�����������������������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 2);
                printf("                                     ");
            } else {
                int isHave = CheckAcc(temp,A_Head);//����Ƿ�����˺�
                if(isHave == 1){
                    SetPos(titleX + 9, titleY + 2);
                    int i;
                    for (i = 0; i < strlen(temp); i++)
                        printf("   ");
                    SetPos(titleX + 9, titleY + 2);
                    printf("�˺��Ѵ��ڣ�����ע�� ");
                    system("pause");
                    return ;
                }
                strcpy(p->admin_id, temp);
                break;
            }
        }
        while (1) {
            memset(temp, 0, sizeof(temp));
            SetPos(titleX + 9, titleY + 3);
            s_get(temp,50);
            if (strlen(temp) != 11) {      //�ж��ֻ���λ���Ƿ���ȷ
                SetPos(titleX + 9, titleY + 3);
                int i;
                for (i = 0; i < strlen(temp); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 3);
                printf("�Ƿ�:\t�ֻ�������Ƿ�������������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 3);
                printf("                                          ");
            } else {
                int i = 0;
                for (i = 0; i < 11; i++) {
                    if (!isdigit(temp[i]))
                        break;
                }
                if (i == 11) {
                    strcpy(p->phone, temp);
                    break;
                }
                SetPos(titleX + 9, titleY + 3);
                printf("�ֻ��ź��з�����,����������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 3);
                printf("                                   ");
            }
        }
        char pwd1[50], pwd2[50];
        int isSame = 1;
        while (isSame != 0) {
            while (1) {
                memset(pwd1, 0, sizeof(pwd1));
                SetPos(titleX + 9, titleY + 4);
                s_get(pwd1,50);
                if (strlen(pwd1) < 6 || strlen(pwd1) > 12) {  //�ж����볤���Ƿ�Ϸ�
                    SetPos(titleX + 9, titleY + 4);
                    int i;
                    for (i = 0; i < strlen(pwd1); i++)
                        printf("   ");
                    SetPos(titleX + 9, titleY + 4);
                    printf("���볤��ӦΪ6-12���ַ�,����������");
                    Sleep(1000);
                    SetPos(titleX + 9, titleY + 4);
                    printf("                                            ");
                } else {
                    break;
                }
            }
            while (1) {
                memset(pwd2, 0, sizeof(pwd2));
                SetPos(titleX + 9, titleY + 5);
                s_get(pwd2,50);
                isSame = strcmp(pwd1, pwd2);
                if (isSame != 0) {
                    SetPos(titleX + 9, titleY + 5);
                    int i;
                    for (i = 0; i < strlen(pwd1); i++)
                        printf("   ");
                    SetPos(titleX + 9, titleY + 5);
                    printf("�����������벻һ�£�����������");
                    Sleep(1000);
                    SetPos(titleX + 9, titleY + 5);
                    printf("                                         ");
                    SetPos(titleX + 9, titleY + 4);
                    printf("                                        ");
                    break;
                } else {
                    break;
                }
            }
        }
        strcpy(p->pwd, pwd1);
        while (1) {
            memset(temp, 0, sizeof(temp));
            SetPos(titleX + 9, titleY + 6);
            s_get(temp,50);
            if (strlen(temp) >= name_size) {      //�ж��ܱ������Ƿ��������
                SetPos(titleX + 9, titleY + 6);
                int i;
                for (i = 0; i < strlen(temp); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 6);
                printf("�Ƿ�:\t�ܱ������������������������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 6);
                printf("                                              ");
            } else {
                strcpy(p->qu, temp);
                break;
            }
        }
        while (1) {
            memset(temp, 0, sizeof(temp));
            SetPos(titleX + 9, titleY + 7);
            s_get(temp,50);
            if (strlen(temp) >= name_size) {      //�жϴ��Ƿ��������
                SetPos(titleX + 9, titleY + 7);
                int i;
                for (i = 0; i < strlen(temp); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 7);
                printf("�Ƿ�:\t���������������������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 7);
                printf("                                      ");
            } else {
                strcpy(p->ans, temp);
                break;
            }
        }
        OutPutInfo(p);
        //while (1) {
            SetPos(titleX, titleY + 8);
            printf("1 ��Ϣ����ȷ��ע��");
            SetPos(titleX, titleY + 9);
            printf("0 ��Ϣ����");
            while(1) {
                SetPos(titleX, titleY + 10);
                printf("����������ѡ��:\t");
                choice = GetChoice();
                if (choice == 1||choice == 0)
                    break;
                SetPos(titleX, titleY + 10);
                printf("                                     ");
            }
            if(choice == 1){
                break;
            }else {
                system("cls");
                SetPos(titleX, titleY + 1);
                printf("1 ����ע��");
                SetPos(titleX, titleY + 2);
                printf("0 �˳�");
                while(1) {
                    SetPos(titleX, titleY + 3);
                    printf("����������ѡ��:\t");
                    choice = GetChoice();
                    if (choice == 1||choice == 0)
                        break;
                    SetPos(titleX, titleY + 3);
                    printf("                                     ");
                }
            }
            if(choice == 1){
                continue;
            }
            if (choice == 0) {
                free(p);
                return;
            }
        //}
    }
    Admin *cur = A_Head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = p;
    p->next = NULL;
    WriteAdmin(A_Head);
    system("cls");
    SetPos(titleX, titleY + 1);
    printf("ע��ɹ���");
    Sleep(1000);
}
//��������
void ForgetPwd(Admin *A_Head){
    int isExist = 0;       //�˺��Ƿ����
    int isCorrect = 0;     //���Ƿ���ȷ
    char acc[50];
    while(!isCorrect) {
        memset(acc,0,sizeof(acc));
        system("cls");
        SetPos(titleX,titleY);
        printf("�� �� �� ��");
        SetPos(titleX, titleY + 1);
        printf("�˺�:\t");
        char c;
        int size = 0;
        while ((c = getchar()) != '\n') {
            acc[size++] = c;
            if (size == name_size - 1)
                break;
        }
        acc[size] = '\0';
        isExist = CheckAcc(acc,A_Head);
        SetPos(titleX, titleY + 2);
        if(isExist == 0) {
            printf("�˺Ų�����\n");
            SetPos(titleX, titleY + 3);
            system("pause");
            return;
        }
        OutPutQu(acc,A_Head);
        SetPos(titleX, titleY + 3);
        printf("��    ��:");
        char ans[50];
        memset(ans,0,sizeof(ans));
        size = 0;
        while ((c = getchar()) != '\n') {
            ans[size++] = c;
            if (size == name_size - 1)
                break;
        }
        ans[size] = '\0';
        isCorrect = CheckQuAns(acc,ans,A_Head);
        if(isCorrect){
            SetPos(titleX, titleY + 4);
            printf("��    ��:\t");
            SetPos(titleX, titleY + 5);
            printf("ȷ������:\t");
            char pwd1[50], pwd2[50];
            int isSame = 1;
            while (isSame != 0) {
                while (1) {
                    memset(pwd1, 0, sizeof(pwd1));
                    SetPos(titleX + 9, titleY + 4);
                    s_get(pwd1,50);
                    if (strlen(pwd1) < 6 || strlen(pwd1) > 12) {  //�ж����볤���Ƿ�Ϸ�
                        SetPos(titleX + 9, titleY + 4);
                        int i;
                        for (i = 0; i < strlen(pwd1); i++)
                            printf("   ");
                        SetPos(titleX + 9, titleY + 4);
                        printf("���볤��ӦΪ6-12���ַ�,����������");
                        Sleep(1000);
                        SetPos(titleX + 9, titleY + 4);
                        printf("                                            ");
                    } else {
                        break;
                    }
                }
                while (1) {
                    memset(pwd2, 0, sizeof(pwd2));
                    SetPos(titleX + 9, titleY + 5);
                    s_get(pwd2,50);
                    isSame = strcmp(pwd1, pwd2);
                    if (isSame != 0) {
                        SetPos(titleX + 9, titleY + 5);
                        int i;
                        for (i = 0; i < strlen(pwd1); i++)
                            printf("   ");
                        SetPos(titleX + 9, titleY + 5);
                        printf("�����������벻һ�£�����������");
                        Sleep(1000);
                        SetPos(titleX + 9, titleY + 5);
                        printf("                                         ");
                        SetPos(titleX + 9, titleY + 4);
                        printf("                                        ");
                        break;
                    } else {
                        break;
                    }
                }
            }
            Admin *cur = A_Head->next;
            while(cur != NULL){
                if(strcmp(acc,cur->admin_id) == 0){
                    memset(cur->pwd,0, sizeof(cur->pwd));
                    strcpy(cur->pwd,pwd1);
                    break;
                }
                cur = cur->next;
            }
        }else{
            SetPos(titleX, titleY + 4);
            printf("�𰸴���");
            SetPos(titleX, titleY + 5);
            system("pause");
        }
    }
    WriteAdmin(A_Head);
}
//����ܱ�����
void OutPutQu(char *acc,Admin *A_Head){
    SetPos(titleX, titleY + 2);
    printf("�ܱ�����:");
    Admin *cur = A_Head->next;
    while(cur != NULL){
        if(strcmp(acc,cur->admin_id) == 0){
            printf("%s",cur->qu);
            return;
        }
        cur = cur->next;
    }
}
//����ܱ�����ʹ��Ƿ�ƥ��
int  CheckQuAns(char *acc,char *ans,Admin *A_Head){
    Admin *cur = A_Head->next;
    while(cur != NULL){
        if(strcmp(acc,cur->admin_id) == 0){
            if(strcmp(ans,cur->ans) == 0)
                return 1;//ƥ��
        }
        cur = cur->next;
    }
    return 0;//��ƥ��
}
//�޸�����
void ChangePwd(Admin *A_Head) {
    int isExist = 0;       //�˺��Ƿ����
    int isCorrect = 0;     //�����Ƿ���ȷ
    int inCorrect = 0;     //���벻��ȷ����
    char acc[50];
    while (!isCorrect) {
        system("cls");
        SetPos(titleX, titleY);
        printf("�� �� �� ��");
        SetPos(titleX, titleY + 1);
        printf("�˺�:\t");
        SetPos(titleX, titleY + 2);
        printf("����:\t");

        memset(acc, 0, sizeof(acc));
        int size = 0;
        char c;
        SetPos(titleX + 6, titleY + 1);
        while ((c = getchar()) != '\n') {
            acc[size++] = c;
            if (size == name_size - 1)
                break;
        }
        acc[size] = '\0';
        isExist = CheckAcc(acc, A_Head);
        if (isExist == 0) {
            SetPos(titleX, titleY + 3);
            printf("�˺Ų�����...\n");
            SetPos(titleX, titleY + 4);
            system("pause");
            return;  //��½ʧ��
        }
        size = 0;
        SetPos(titleX + 6, titleY + 2);
        char pwd[50];
        memset(pwd, 0, sizeof(pwd));
        while ((c = getchar()) != '\n') {
            pwd[size++] = c;
            if (size == 11)
                break;
        }
        pwd[size] = '\0';
        isCorrect = CheckAccPwd(acc, pwd, A_Head);
        if (isCorrect == 0) {
            SetPos(titleX, titleY + 3);
            printf("�˺Ż��������\n");
            Sleep(500);
            inCorrect++;
        }
        if (inCorrect == 5) {
            SetPos(titleX, titleY + 3);
            printf("���Ѿ�5��������룬������������\n");
            SetPos(titleX, titleY + 4);
            system("pause");
            return;//��½ʧ��
        }
    }
    SetPos(titleX, titleY + 4);
    printf("�� �� ��:\t");
    SetPos(titleX, titleY + 5);
    printf("ȷ������:\t");
    char pwd1[50], pwd2[50];
    int isSame = 1;
    while (isSame != 0) {
        while (1) {
            memset(pwd1, 0, sizeof(pwd1));
            SetPos(titleX + 9, titleY + 4);
            s_get(pwd1,50);
            if (strlen(pwd1) < 6 || strlen(pwd1) > 12) {  //�ж����볤���Ƿ�Ϸ�
                SetPos(titleX + 9, titleY + 4);
                int i;
                for (i = 0; i < strlen(pwd1); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 4);
                printf("���볤��ӦΪ6-12���ַ�,����������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 4);
                printf("                                            ");
            } else {
                break;
            }
        }
        while (1) {
            memset(pwd2, 0, sizeof(pwd2));
            SetPos(titleX + 9, titleY + 5);
            s_get(pwd2,50);
            isSame = strcmp(pwd1, pwd2);
            if (isSame != 0) {
                SetPos(titleX + 9, titleY + 5);
                int i;
                for (i = 0; i < strlen(pwd1); i++)
                    printf("   ");
                SetPos(titleX + 9, titleY + 5);
                printf("�����������벻һ�£�����������");
                Sleep(1000);
                SetPos(titleX + 9, titleY + 5);
                printf("                                         ");
                SetPos(titleX + 9, titleY + 4);
                printf("                                        ");
                break;
            } else {
                break;
            }
        }
    }
    Admin *cur = A_Head->next;
    while (cur != NULL) {
        if (strcmp(acc, cur->admin_id) == 0) {
            memset(cur->pwd, 0, sizeof(cur->pwd));
            strcpy(cur->pwd, pwd1);
            break;
        }
        cur = cur->next;
    }
    SetPos(titleX, titleY + 6);
    WriteAdmin(A_Head);
    printf("�޸�����ɹ���");
    Sleep(1000);
}
//����û�������Ϣ
void OutPutInfo(Admin *node){
    system("cls");
    SetPos(titleX,titleY+1);
    printf("��    ��:");
    printf("%s\n",node->name);
    SetPos(titleX,titleY+2);
    printf("��    ��:");
    printf("%s\n",node->admin_id);
    SetPos(titleX,titleY+3);
    printf("�� �� ��:");
    printf("%s\n",node->phone);
    SetPos(titleX,titleY+4);
    printf("��    ��:");
    printf("%s\n",node->pwd);
    SetPos(titleX,titleY+5);
    printf("�ܱ�����:");
    printf("%s\n",node->qu);
    SetPos(titleX,titleY+6);
    printf("��    ��:");
    printf("%s\n",node->ans);
}

void FreeAdminNode(Admin *A_Head){
    Admin *cur = A_Head->next;
    Admin *temp = cur;
    while(cur!=NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(A_Head);
    A_Head = NULL;
}
