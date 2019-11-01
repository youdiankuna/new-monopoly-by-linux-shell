#ifndef _SHOP_H_
#define _SHOP_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
//建筑结构体
typedef struct menu//数据单向循环链表用于存储商店以及赌场的数据
{
	datatype num;//拥有的个数
	datatype data;//菜单号
	struct menu *next; // 指向节点的指针
}listmenu, *singly_list;

void List_Sort_Add(singly_list head, singly_list new);
singly_list List_Create(datatype data, datatype num);
singly_list List_Init(void);
int List_delete(singly_list head,int tmp);
void List_Show(singly_list head);
bool List_Null(singly_list head);
singly_list shop();


#endif