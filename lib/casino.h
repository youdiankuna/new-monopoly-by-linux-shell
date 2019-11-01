#ifndef _CAS_H_
#define _CAS_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
//建筑结构体
typedef struct menu1//数据单向循环链表用于存储商店以及赌场的数据
{
	datatype data;//菜单号
	datatype save_money;//存钱数
	datatype loan;//贷款
	struct menu1 *next; // 指向节点的指针
}listmenu1, *singly_list1;

singly_list1 List_Create1(datatype save_money, datatype data, datatype loan);
void List_Sort_Add1(singly_list1 head, singly_list1 new);
singly_list1 List_Init1(void);
void List_Show1(singly_list1 head);
bool List_Null1(singly_list1 head);
singly_list1 casino();


#endif