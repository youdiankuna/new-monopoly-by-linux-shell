#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "casino.h"

singly_list1 List_Create1(datatype save_money, datatype data, datatype loan);
void List_Sort_Add1(singly_list1 head, singly_list1 new);
singly_list1 List_Init1(void);
void List_Show1(singly_list1 head);
bool List_Null1(singly_list1 head);
singly_list1 casino();

singly_list1 casino()
{
	// 1.初始化空链表
	// 有头结点-空链表
	singly_list1 head = List_Init1();	
	// 2.创建新节点
	singly_list1 new = List_Create1(0,1,2000);
	// 3.插入节点
	List_Sort_Add1(head, new);
	singly_list1 new1 = List_Create1(0,2,2000);
	List_Sort_Add1(head, new1);
	//List_Show1(head);
    return head;
}
//顺序添加
void List_Sort_Add1(singly_list1 head, singly_list1 new)
{
	singly_list1 p = head;
	// 判断是否为空链表
	if(List_Null1(head))
	{
		//printf("链表为空\n");
		head->next = new;
		
		return;
	}
	
	while(p->next != NULL)
	{
		if(p->next->data > new->data) // 插入位置在中间
		{
			new->next = p->next;
			p->next = new;
			return;
		}
		
		p = p->next;
	}
	
	// 插入位置在最后
	p->next = new;
	
}
//初始化头节点
singly_list1 List_Init1(void)
{
	// 有头结点的-空链表
	singly_list1 head = malloc(sizeof(listmenu1));
	head->next = NULL;
	
	return head;
}
//初始化新节点
singly_list1 List_Create1(datatype save_money, datatype data, datatype loan)
{
	// 有头结点的-空链表
	singly_list1 new = malloc(sizeof(listmenu1));
	new->next = NULL;
	new->save_money = save_money;
	new->data = data;
	new->loan= loan;
	return new;
}
//show
void List_Show1(singly_list1 head)
{
	singly_list1 p = head->next;
	
	// 循环找到链表尾
	while(p != NULL)
	{
		printf("%d-->", p->data);
		
		p = p->next;
	}
	printf("\n");
	
}
bool List_Null1(singly_list1 head)
{
	return head->next == NULL;
}