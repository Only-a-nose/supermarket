//
// Created by SGNY on 2020/5/9.
//
//����̵�
#ifndef SUPER_V1_STOCKTAKING_H
#define SUPER_V1_STOCKTAKING_H

#include "structandfx.h"
void StockTakingMain(Goods *G_Head, in_Goods *IG_Head);            //����̵�������
void STMenu();                                  //����̵�˵�
int GetNumOfGoods(Goods *G_Head);               //��ȡ�������Ʒ����
Goods* BuildArray(int Num, Goods *G_Head);      //������̬��Ʒ����
void STBySalesVol(Goods *room, int l, int r);   //����������
void STByInNum(Goods *room, int l, int r);      //�������������
void STById(Goods *room, int l, int r);         //����������
void STByName(Goods *room, int l, int r);       //����������
void STByAvgTime(Goods *room, int l, int r);    //��ƽ���ڿ�ʱ������
void STBYKind(Goods *room, int l, int r);       //����������
void mySwap(Goods* g1, Goods* g2);              //��������
void GetAvgTime(Goods *room, in_Goods *IG_Head, int Num);//����ĳ����Ʒ��ƽ���ڿ�ʱ��
void Order(int Num, Goods *room);    //ѡ��������
#endif //SUPER_V1_STOCKTAKING_H
