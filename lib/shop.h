#ifndef _SHOP_H_
#define _SHOP_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
//�����ṹ��
typedef struct menu//���ݵ���ѭ���������ڴ洢�̵��Լ��ĳ�������
{
	datatype num;//ӵ�еĸ���
	datatype data;//�˵���
	struct menu *next; // ָ��ڵ��ָ��
}listmenu, *singly_list;

void List_Sort_Add(singly_list head, singly_list new);
singly_list List_Create(datatype data, datatype num);
singly_list List_Init(void);
int List_delete(singly_list head,int tmp);
void List_Show(singly_list head);
bool List_Null(singly_list head);
singly_list shop();


#endif