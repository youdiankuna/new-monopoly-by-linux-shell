#ifndef _CAS_H_
#define _CAS_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
//�����ṹ��
typedef struct menu1//���ݵ���ѭ���������ڴ洢�̵��Լ��ĳ�������
{
	datatype data;//�˵���
	datatype save_money;//��Ǯ��
	datatype loan;//����
	struct menu1 *next; // ָ��ڵ��ָ��
}listmenu1, *singly_list1;

singly_list1 List_Create1(datatype save_money, datatype data, datatype loan);
void List_Sort_Add1(singly_list1 head, singly_list1 new);
singly_list1 List_Init1(void);
void List_Show1(singly_list1 head);
bool List_Null1(singly_list1 head);
singly_list1 casino();


#endif