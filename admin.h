//
// Created by SGNY on 2020/5/8.
//
//����Ա��½����
#ifndef SUPER_V1_ADMIN_H
#define SUPER_V1_ADMIN_H

#include "structandfx.h"
Admin* AdminMain(Admin *A_Head);
void AdminMenu();
//�˺ŵ�½
Admin* SignIn(Admin *A_Head);
int  CheckAcc(char *acc, Admin *A_Head);//����˺��Ƿ����
int  CheckAccPwd(char *acc, char *pwd, Admin *A_Head);//����˺������Ƿ�ƥ��
Admin* FindAdmin(char *acc, Admin *A_Head);//���ص�ǰ������Ա
//�û�ע��
void Register(Admin *A_Head);
void OutPutInfo(Admin *node);//����û�������Ϣ

//��������
void ForgetPwd(Admin *A_Head);
void OutPutQu(char *acc,Admin *A_Head);
int  CheckQuAns(char *acc,char *ans,Admin *A_Head);//����ܱ�����ʹ��Ƿ�ƥ��

//�޸�����
void ChangePwd(Admin *A_Head);

//�ͷ��ڴ�ռ�
void FreeAdminNode(Admin *A_Head);
#endif //SUPER_V1_ADMIN_H
