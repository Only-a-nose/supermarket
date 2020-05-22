#include "SoldOut.h"
#include <stdio.h>
#include "ChangeGoodsInfo.h"

void DeleteMain(Goods *G_Head)
{
	int choice;
    while (1)
	{
        system("cls");
        SetPos(titleX, titleY);
        printf("��Ʒ�¼ܲ˵�");
        SetPos(menuX, menuY);
        printf("1.�¼���Ʒ");
        SetPos(menuX, menuY + 1);
        printf("0.�˳�");
        SetPos(menuX, menuY + 2);
        printf("����������ѡ��");
        choice=GetChoice();
        if (choice == 1)
		{
			Delete_1(G_Head);
			WriteGoods(G_Head);
		}
        else if (choice == 0) break;
    }
}

void Delete_1(Goods *G_Head)
{
	system("cls");
    int k = 0;
    Goods *p;
    Goods *Bp;
    p = G_Head->next;
    Bp = G_Head;
	SetPos(titleX, titleY);
    printf("��������Ʒ����:");
    int id;
    id=GetId();
    while (p != NULL)
	{
        if (p->goods_id == id) {
			SetPos(menuX, menuY);
            printf("����Ʒ������:%s", p->name);
			SetPos(menuX, menuY+1);
            printf("����Ʒ�Ļ���:%05d", p->goods_id);
			SetPos(menuX, menuY+2);
            printf("����Ʒ���ۻ�����:%.2f", p->S_price);
			SetPos(menuX, menuY+3);
            printf("����Ʒ������:%d", p->total_num);
			SetPos(menuX, menuY+4);
            printf("����Ʒ������:%d", p->sales_volume);
			SetPos(menuX, menuY+5);
            printf("��ȷ���Ƿ�ɾ������Ʒ��ɾ���밴1�����������밴0��");
            k = 1;
            int j;
			while(1)
			{
			    j=GetChoice();
			    if(j==1)
                {
                    DeleteNode(Bp, p);
                    SetPos(menuX, menuY+6);
                    printf("��Ʒ�ѳɹ��¼�\n");
                    SetPos(menuX, menuY+7);
                    system("pause");
                    break;
                }
			    else if(j==0)
                {
                    SetPos(menuX, menuY+6);
					printf("����ɾ��\n");
					SetPos(menuX, menuY+7);
					system("pause");
					break;
                }
				else
				{
					SetPos(menuX, menuY+6);
					printf("�����������������");
				}
			}
			break;
        }
		else
		{
            p = p->next;
            Bp = Bp->next;
        }
    }
    if (0 == k)
	{
	    SetPos(menuX, menuY+3);
        printf("�޴���Ʒ\n");
        SetPos(menuX, menuY+4);
        system("pause");
    }
}

void DeleteNode(Goods *Bp, Goods *p)
{
    Bp->next = p->next;
    free(p);
}
