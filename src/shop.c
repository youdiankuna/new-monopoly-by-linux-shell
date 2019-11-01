#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "shop.h"

void List_Sort_Add(singly_list head, singly_list new);
singly_list List_Create(datatype data, datatype num);
singly_list List_Init(void);
int List_delete(singly_list head,int tmp);
void List_Show(singly_list head);
bool List_Null(singly_list head);
singly_list shop();

singly_list shop()
{
	// 1.初始化空链表
	// 有头结点-空链表
	singly_list head = List_Init();	
	// 2.创建新节点
	singly_list new = List_Create(1,5);
	// 3.插入节点
	List_Sort_Add(head, new);
	singly_list new1 = List_Create(2,8);
	List_Sort_Add(head, new1);
    singly_list new2 = List_Create(3,10);
	List_Sort_Add(head, new2);	
	//List_Show(head);
    return head;
}
//顺序添加
void List_Sort_Add(singly_list head, singly_list new)
{
	singly_list p = head;
	// 判断是否为空链表
	if(List_Null(head))
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
singly_list List_Init(void)
{
	// 有头结点的-空链表
	singly_list head = malloc(sizeof(listmenu));
	head->next = NULL;
	
	return head;
}
//初始化新节点
singly_list List_Create(datatype data, datatype num)
{
	// 有头结点的-空链表
	singly_list new = malloc(sizeof(listmenu));
	new->next = NULL;
	new->data = data;
	new->num = num;
	return new;
}
//删除
int List_delete(singly_list head,int tmp)
{
	singly_list p = head->next;//设置一个p指针指向目标节点
	while(p->next != NULL)
	{
		singly_list q = p;//设置一个q指针指向目标节点的上一个节点
		if(p->next->data==-tmp)
		{
			
			p=p->next;
			if(p==NULL)
			{
				q->next=NULL;
				free(p);
				p=NULL;
				return 1;
			}
			else
			{
				q->next=p->next;
				p->next=NULL;
				free(p);
				p=NULL;
				return 1;
				
			}
		}
		p=p->next;
	}
	
	return -1;
}
//show
void List_Show(singly_list head)
{
	singly_list p = head->next;
	
	// 循环找到链表尾
	while(p != NULL)
	{
		printf("%d-->", p->data);
		
		p = p->next;
	}
	printf("\n");
	
}
bool List_Null(singly_list head)
{
	return head->next == NULL;
}