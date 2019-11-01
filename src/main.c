#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "list.h"
#include "shop.h"
#include "casino.h"
#include "show.h"

typedef int datatype;
// 地图大结构体
typedef struct node
{
	datatype data;  // 整型
	struct list_head alist; // 小结构体
	char name;// 字符型
    singly_list service;
	singly_list1 service1;
}listnode, *kernel_list;
// 人物大结构体
typedef struct role
{
	datatype home;//拥有的房屋个数
	datatype aggressivity;//攻击力
	datatype assets;	// 资产
	datatype data;//在地图的位置
	struct list_head *alist; // 小结构体指针
	char name;// 名字
}listrole, *role_list;

void head ();//游戏初始界面
void head2 ();//游戏副页面
kernel_list list_init(void);//初始化头节点
kernel_list list_node_create(int tmp,  char name, singly_list service,singly_list1 service1);//创建新节点
void list_show(kernel_list head);
role_list role_init(char name);//初始化人物角色
void bank_interest(kernel_list head);
void role_information(role_list role1, role_list role2);//人物财富显示
void space();//空格

void main ()
{
	int tmp;
	int dice;
	int x,  b, c = 20, d, e, f, g;
	char rol1;
	char rol2;
	int fre;
	int sj;
	srand((unsigned)time(NULL));
	x=rand()%18+2;//给建筑单位随机的地址
	d=rand()%18+2;
	f=rand()%18+2;
	e=rand()%18+2;
	g=rand()%18+2;
	b=rand()%18+2;
	head();//展示初始页面head
	kernel_list head = list_init();// 初始化一个有头结点的空链表
	for(tmp = 1; tmp < 21; tmp++)//建立大富翁地图（1-20格）
	{
		kernel_list new = list_node_create(tmp, 0, NULL, NULL); 
		if(tmp == x)// 初始化了一个新的节点
		    new = list_node_create(tmp, 'S', shop(), NULL);
		else if(tmp == b)
			new = list_node_create(tmp, 'S', shop(), NULL);
		else if(tmp == d)
			new = list_node_create(tmp, 'C', NULL, NULL);
		else if(tmp == e)
			new = list_node_create(tmp, 'C', NULL, NULL);
		else if(tmp == f)
			new = list_node_create(tmp, 'H', NULL, NULL);
		else if(tmp == g)
			new = list_node_create(tmp, 'H', NULL, NULL);
		else if(tmp == 20)
			new = list_node_create(tmp, 'B', NULL, casino());
		else
		    new = list_node_create(tmp, 0, NULL, NULL); 
	    list_add_tail(&new->alist, &head->alist); // 添加节点
	}
	//list_show(head);//地图内核链表显示
	head2 ();
	printf("输入玩家1的姓名:\n");
	scanf("%s",&rol1);
	printf("输入玩家2的姓名:\n");
	scanf("%s",&rol2);
	role_list role1=role_init(rol1);
	role1->alist = head->alist.next;
	kernel_list p = list_entry(role1->alist, listnode, alist);
	role1->data = p->data;
	printf("%d\n",role1->data);
	role_list role2=role_init(rol2);
	role2->alist = head->alist.next;
	role2->data = p->data;
	role_information(role1, role2);
	show (x, b, 20, d, e, f, g, role1->data, role2->data );
	//p = NULL;
	//free(p);
	getchar();
	for(fre= 1;1;fre++)
	{   
        getchar();
        if(fre%2 == 1)
		{
	        printf("玩家1点击空格摇动骰子");
	        getchar();
	        dice = rand()%4+1;
	        switch(dice)
	        {
			    case 1:role1->alist = role1->alist->next;
				       if(role1->alist == &head->alist)
						   role1->alist = role1->alist->next;
					   p = list_entry(role1->alist, listnode, alist);
					   role1->data = p->data;
					   printf("到达:%d\n",role1->data);
			           break;
			    case 2:printf("摇到了:%d\n",dice);
				       for(tmp = 1; tmp < 3; tmp++)
					   {
						   role1->alist = role1->alist->next;
						   if(role1->alist == &head->alist)
							   role1->alist = role1->alist->next;
					   }
					   p = list_entry(role1->alist, listnode, alist);
					   role1->data = p->data;
					   printf("到达:%d\n",role1->data);
			           break;
			    case 3:printf("摇到了:%d\n",dice);
				       for(tmp = 1; tmp < 4; tmp++)
					   {
						   role1->alist = role1->alist->next;
						   if(role1->alist == &head->alist)
							   role1->alist = role1->alist->next;
					   }
					   p = list_entry(role1->alist, listnode, alist);
					   role1->data = p->data;
					   printf("到达:%d\n",role1->data);
			           break;
			    case 4:printf("摇到了:%d\n",dice);
				       for(tmp = 1; tmp < 5; tmp++)
					   {
						   role1->alist = role1->alist->next;
						   if(role1->alist == &head->alist)
							   role1->alist = role1->alist->next;
					   }
					   p = list_entry(role1->alist, listnode, alist);
					   role1->data = p->data;
					   printf("到达:%d\n",role1->data);
			           break;
	        }
		}
		if(fre%2 == 0)
		{
	        printf("玩家2点击空格摇动骰子");
	        getchar();
	        dice = rand()%4+1;
		    printf("摇到了:%d\n",dice);
	        switch(dice)
	        {
			    case 1:role2->alist = role2->alist->next;
				       if(role2->alist == &head->alist)
						   role2->alist = role2->alist->next;
					   p = list_entry(role2->alist, listnode, alist);
					   role2->data = p->data;
					   printf("到达:%d\n",role2->data);
			           break;
			    case 2:printf("摇到了:%d\n",dice);
				       for(tmp = 1; tmp < 3; tmp++)
					   {
						   role2->alist = role2->alist->next;
						   if(role2->alist == &head->alist)
							   role2->alist = role2->alist->next;
					   }
					   p = list_entry(role2->alist, listnode, alist);
					   role2->data = p->data;
					   printf("到达:%d\n",role2->data);
			           break;
			    case 3:printf("摇到了:%d\n",dice);
				       for(tmp = 1; tmp < 4; tmp++)
					   {
						   role2->alist = role2->alist->next;
						   if(role2->alist == &head->alist)
							   role2->alist = role2->alist->next;
					   }
					   p = list_entry(role2->alist, listnode, alist);
					   role2->data = p->data;
					   printf("到达:%d\n",role2->data);
			           break;
			    case 4:printf("摇到了:%d\n",dice);
				       for(tmp = 1; tmp < 5; tmp++)
					   {
						   role2->alist = role2->alist->next;
						   if(role2->alist == &head->alist)
							   role2->alist = role2->alist->next;
					   }
					   p = list_entry(role2->alist, listnode, alist);
					   role2->data = p->data;
					   printf("到达:%d\n",role2->data);
			           break;
	        }
		}
		if(fre%2 == 1)
		{
		if(role1->data == x && p->name == 'S')
		{
			printf("进到商店\n");
			printf("选择一个购买\n");
			printf("1.大力丸 -200元\n");
			printf("2.金条   -400元\n");
			printf("3.博彩   -200元\n");
			printf("4.什么都不买\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role1->assets = role1->assets - 200;
				role1->aggressivity =  role1->aggressivity + 5;
				p->service->next->num = p->service->next->num -1;
			}
			if(tmp == 2)
			{
				role1->assets = role1->assets - 400;
				sj = rand()%20+1;
				if(sj > 10)
				{
					role1->assets = role1->assets + 600;
					printf("金价上涨赚200元");
				}	
				else
				{
					role1->assets = role1->assets + 200;
					printf("金价下跌亏200元");
				}
				p->service->next->next->num = p->service->next->next->num -1;
			}
			if(tmp == 3)
			{
				role1->assets = role1->assets - 200;
				sj = rand()%20+1;
				if(sj > 16)
				{
					role1->assets = role1->assets + 1000;
					printf("中奖+1000元");
				}
				else
				{
					printf("没有中奖");
				}	
				p->service->next->next->num = p->service->next->next->num -1;
			}
		}
		if(role1->data == b && p->name == 'S')
		{
			printf("进到商店\n");
			printf("选择一个购买\n");
			printf("1.大力丸 -200元\n");
			printf("2.金条   -400元\n");
			printf("3.博彩   -200元\n");
			printf("4.什么都不买\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role1->assets = role1->assets - 200;
				role1->aggressivity =  role1->aggressivity + 5;
				p->service->next->num = p->service->next->num -1;
			}
			if(tmp == 2)
			{
				role1->assets = role1->assets - 400;
				sj = rand()%20+1;
				if(sj > 10)
				{
					role1->assets = role1->assets + 600;
					printf("金价上涨赚200元");
				}	
				else
				{
					role1->assets = role1->assets + 200;
					printf("金价下跌亏200元");
				}
				p->service->next->next->num = p->service->next->next->num -1;
			}
			if(tmp == 3)
			{
				role1->assets = role1->assets - 200;
				sj = rand()%20+1;
				if(sj > 16)
				{
					role1->assets = role1->assets + 1000;
					printf("中奖+1000元");
				}
				else
				{
					printf("没有中奖");
				}	
				p->service->next->next->num = p->service->next->next->num -1;
			}
		}
		if(role1->data == d && p->name == 'C')
		{
			printf("进到赌场\n");
			printf("选择一个选项\n");
			printf("1.随机摸金,赢取3倍底金\n");
			printf("2.当保镖赚点小费\n");
			printf("3.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				printf("选择金额下注\n");
				printf("输入你的金额,不得少于200元:");
				scanf("%d",&tmp);
				if(tmp < 200)
					tmp = 0;
				role1->assets = role1->assets - tmp;
				sj = rand()%60+1;
				if(sj > 55)
				{
					printf("手气巨好,赢取3倍底金\n");
					role1->assets = role1->assets + (tmp*3);
				}
				else
					printf("血本无归\n");
			}
			if(tmp == 2)
			{
				printf("当保镖赚取300小费\n");
				role1->assets = role1->assets + 300;
			}
			if(tmp == 3);
		}
		if(role1->data == e && p->name == 'C')
		{
			printf("进到赌场\n");
			printf("选择一个选项\n");
			printf("1.随机摸金,赢取3倍底金\n");
			printf("2.当保镖赚点小费\n");
			printf("3.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				printf("选择金额下注\n");
				printf("输入你的金额,不得少于200元:");
				scanf("%d",&tmp);
				if(tmp < 200)
				{
					printf("滚蛋这么点钱还来赌场,被赶出赌场");
					tmp = 0;
				}	
				role1->assets = role1->assets - tmp;
				sj = rand()%60+1;
				if(sj > 55)
				{
					printf("手气巨好,赢取3倍底金\n");
					role1->assets = role1->assets + (tmp*3);
				}
				else
					printf("血本无归\n");
			}
			if(tmp == 2)
			{
				printf("当保镖赚取300小费\n");
				role1->assets = role1->assets + 300;
			}
			if(tmp == 3);
		}
		if(role1->data == f && p->name == 'H')
		{
			printf("将进到住房区\n");
			printf("选择一个选项\n");
			printf("1.买房变成地头蛇收过路费 -150元\n");
			printf("2.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role1->assets = role1->assets -150;
				p->name = 'a';
				printf("购房并更名为a的房间\n");
				role1->home++;
			}
			if(tmp == 2)
				printf("默默离开\n");
				
		}
		if(role1->data == g && p->name == 'H')
		{
			printf("将进到住房区\n");
			printf("选择一个选项\n");
			printf("1.买房变成地头蛇收过路费 -150元\n");
			printf("2.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role1->assets = role1->assets -150;
				p->name = 'a';
				printf("购房并更名为a的房间\n");
				role1->home++;
			}
			if(tmp == 2)
				printf("默默离开\n");
		}
		if(role1->data == 20 && p->name == 'B')
		{
			printf("将进到银行\n");
			printf("选择一个选项\n");
			printf("1.存钱\n");
			printf("2.取钱\n");
			printf("3.贷款\n");
			printf("4.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				while(tmp < 50)
				{
					loop:
				    printf("输入需要存储的金额,不低于50元:");
				    scanf("%d",&tmp);
				    if(tmp < 50)
					    goto loop;
				    role1->assets = role1->assets - tmp;
				    p->service1->next->save_money = p->service1->next->save_money + tmp;
					
				}
				printf("\n");
			}
			if(tmp == 2)
			{
				printf("输入需要取出的金额:");
				scanf("%d",&tmp);
				if(tmp <= p->service1->next->save_money)
				{
				    role1->assets = role1->assets + tmp;
				    p->service1->next->save_money = p->service1->next->save_money - tmp;
                }
				else
					printf("取款失败,金额错误，卡被吞了，等待下次再来取款\n");
			}
			if(tmp == 3)
			{
				printf("输入需要贷款的金额,不低于50元:");
				scanf("%d",&tmp);
				if(tmp <= p->service1->next->loan)
				{
				    role1->assets = role1->assets + tmp;
				    p->service1->next->loan = p->service1->next->loan - tmp;
                }
				else
					printf("贷款失败,穷逼还想贷这么多滚蛋吧,被踢出银行\n");
			}
			if(tmp == 4);
		}
		}
		if(fre%2 == 0)
		{
		if(role2->data == x && p->name == 'S')
		{
			printf("进到商店\n");
			printf("选择一个购买\n");
			printf("1.大力丸 -200元\n");
			printf("2.金条   -400元\n");
			printf("3.博彩   -200元\n");
			printf("4.什么都不买\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role2->assets = role2->assets - 200;
				role2->aggressivity =  role2->aggressivity + 5;
				p->service->next->num = p->service->next->num -1;
			}
			if(tmp == 2)
			{
				role2->assets = role2->assets - 400;
				sj = rand()%20+1;
				if(sj > 10)
				{
					role2->assets = role2->assets + 600;
					printf("金价上涨赚200元");
				}	
				else
				{
					role2->assets = role2->assets + 200;
					printf("金价下跌亏200元");
				}
				p->service->next->next->num = p->service->next->next->num -1;
			}
			if(tmp == 3)
			{
				role2->assets = role2->assets - 200;
				sj = rand()%20+1;
				if(sj > 16)
				{
					role2->assets = role2->assets + 1000;
					printf("中奖+1000元");
				}
				else
				{
					printf("没有中奖");
				}	
				p->service->next->next->num = p->service->next->next->num -1;
			}
		}
		if(role2->data == b && p->name == 'S')
		{
			printf("进到商店\n");
			printf("选择一个购买\n");
			printf("1.大力丸 -200元\n");
			printf("2.金条   -400元\n");
			printf("3.博彩   -200元\n");
			printf("4.什么都不买\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role2->assets = role2->assets - 200;
				role2->aggressivity =  role2->aggressivity + 5;
				p->service->next->num = p->service->next->num -1;
			}
			if(tmp == 2)
			{
				role2->assets = role2->assets - 400;
				sj = rand()%20+1;
				if(sj > 10)
				{
					role2->assets = role2->assets + 600;
					printf("金价上涨赚200元");
				}	
				else
				{
					role2->assets = role2->assets + 200;
					printf("金价下跌亏200元");
				}
				p->service->next->next->num = p->service->next->next->num -1;
			}
			if(tmp == 3)
			{
				role2->assets = role2->assets - 200;
				sj = rand()%20+1;
				if(sj > 16)
				{
					role2->assets = role2->assets + 1000;
					printf("中奖+1000元");
				}
				else
				{
					printf("没有中奖");
				}	
				p->service->next->next->num = p->service->next->next->num -1;
			}
		}
		if(role2->data == d && p->name == 'C')
		{
			printf("进到赌场\n");
			printf("选择一个选项\n");
			printf("1.随机摸金,赢取3倍底金\n");
			printf("2.当保镖赚点小费\n");
			printf("3.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				printf("选择金额下注\n");
				printf("输入你的金额,不得少于200元:");
				scanf("%d",&tmp);
				if(tmp < 200)
					tmp = 0;
				role2->assets = role2->assets - tmp;
				sj = rand()%60+1;
				if(sj > 55)
				{
					printf("手气巨好,赢取3倍底金\n");
					role2->assets = role2->assets + (tmp*3);
				}
				else
					printf("血本无归\n");
			}
			if(tmp == 2)
			{
				printf("当保镖赚取300小费\n");
				role2->assets = role2->assets + 300;
			}
			if(tmp == 3);
		}
		if(role2->data == e && p->name == 'C')
		{
			printf("进到赌场\n");
			printf("选择一个选项\n");
			printf("1.随机摸金,赢取3倍底金\n");
			printf("2.当保镖赚点小费\n");
			printf("3.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				printf("选择金额下注\n");
				printf("输入你的金额,不得少于200元:");
				scanf("%d",&tmp);
				if(tmp < 200)
				{
					printf("滚蛋这么点钱还来赌场,被赶出赌场");
					tmp = 0;
				}	
				role2->assets = role2->assets - tmp;
				sj = rand()%60+1;
				if(sj > 55)
				{
					printf("手气巨好,赢取3倍底金\n");
					role2->assets = role2->assets + (tmp*3);
				}
				else
					printf("血本无归\n");
			}
			if(tmp == 2)
			{
				printf("当保镖赚取300小费\n");
				role2->assets = role2->assets + 300;
			}
			if(tmp == 3);
		}
		if(role2->data == f && p->name == 'H')
		{
			printf("将进到住房区\n");
			printf("选择一个选项\n");
			printf("1.买房变成地头蛇收过路费 -150元\n");
			printf("2.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role2->assets = role2->assets -150;
				p->name = 'b';
				printf("购房并更名为b的房间\n");
				role2->home++;
			}
			if(tmp == 2)
				printf("默默离开\n");
		}
		if(role2->data == g && p->name == 'H')
		{
			printf("将进到住房区\n");
			printf("选择一个选项\n");
			printf("1.买房变成地头蛇收过路费 -150元\n");
			printf("2.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				role2->assets = role2->assets -150;
				p->name = 'b';
				printf("购房并更名为b的房间\n");
				role2->home++;
			}
			if(tmp == 2)
				printf("默默离开\n");
		}
		if(role2->data == 20 && p->name == 'B')
		{
			printf("将进到银行\n");
			printf("选择一个选项\n");
			printf("1.存钱\n");
			printf("2.取钱\n");
			printf("3.贷款\n");
			printf("4.转身离开\n");
			printf("输入你的选项:");
			scanf("%d",&tmp);
			if(tmp == 1)
			{
				while(tmp < 50)
				{
					hip:
				    printf("输入需要存储的金额,不低于50元:");
				    scanf("%d",&tmp);
				    if(tmp < 50)
					    goto hip;
				    role2->assets = role2->assets - tmp;
				    p->service1->next->next->save_money = p->service1->next->next->save_money + tmp;
					
				}
				printf("\n");
			}
			if(tmp == 2)
			{
				printf("输入需要取出的金额:");
				scanf("%d",&tmp);
				if(tmp <= p->service1->next->next->save_money)
				{
				    role2->assets = role2->assets + tmp;
				    p->service1->next->next->save_money = p->service1->next->next->save_money - tmp;
                }
				else
					printf("取款失败,金额错误，卡被吞了，等待下次再来取款\n");
			}
			if(tmp == 3)
			{
				printf("输入需要贷款的金额,不低于50元:");
				scanf("%d",&tmp);
				if(tmp <= p->service1->next->next->loan)
				{
				    role2->assets = role2->assets + tmp;
				    p->service1->next->next->loan = p->service1->next->next->loan - tmp;
                }
				else
					printf("贷款失败,穷逼还想贷这么多滚蛋吧,被踢出银行\n");
			}
			if(tmp == 4);
		}
		}
		if(fre%2 == 1)
		{
			if(role2->data == role1->data)
		    {
			    printf("玩家相遇\n");
				printf("1.挑衅玩家2,进行决斗\n");
				printf("2.离得远远的\n");
				printf("输入的选项:");
				scanf("%d",&tmp);
				if(tmp == 1)
				{
					if(role2->aggressivity > role1->aggressivity)
					{
						printf("被打倒,被迫给300元保护费\n");
						role2->assets = role2->assets + 300;
					    role1->assets = role1->assets - 300;
					}
					else if(role2->aggressivity == role1->aggressivity)
					{
						printf("力量相等,实力不分伯仲,没有损失\n");
					}
					else
					{
						printf("打赢,难免受点小伤收取医药费300元\n");
						role2->assets = role2->assets - 300;
					    role1->assets = role1->assets + 300;
					}	
				}
				if(tmp == 2)
					printf("溜之大吉\n");
		    }
		}
		if(fre%2 == 0)
		{
			if(role2->data == role1->data)
		    {
			    printf("玩家相遇\n");
				printf("1.挑衅玩家1,进行决斗\n");
				printf("2.离得远远的\n");
				printf("输入的选项:");
				scanf("%d",&tmp);
				if(tmp == 1)
				{
					if(role2->aggressivity > role1->aggressivity)
					{
						printf("打赢,难免受点小伤收取医药费300元\n");
						role2->assets = role2->assets + 300;
					    role1->assets = role1->assets - 300;
					}
					else if(role2->aggressivity == role1->aggressivity)
					{
						printf("力量相等,实力不分伯仲,没有损失\n");
					}
                    else
					{
						printf("被打倒,被迫给300元保护费\n");
						role2->assets = role2->assets - 300;
					    role1->assets = role1->assets + 300;
					}						
				}
				if(tmp == 2)
					printf("溜之大吉\n");
		    }
		}
		if(fre%2 == 1)
		{
			if(p->name == 'b')
			{
				printf("进入玩家2的地盘,玩家2露出地头蛇本性强行收过路费 -300元\n");
				role1->assets = role1->assets - 300;
				if(role2->data == role1->data)
					printf("看见玩家2在家,算了下次在找你麻烦\n");
				else
				{
					printf("看见玩家2不在家,想要收购他的地盘\n");
					printf("1.收购他的地盘\n");
				    printf("2.离得远远的\n");
				    printf("输入的选项:");
				    scanf("%d",&tmp);
					if(tmp == 1)
					{
						printf("购得地盘改名为a  -150元\n");
						role1->assets = role1->assets - 150;
						p->name = 'a';
						role2->home--;
					}
					if(tmp == 2)
					{
						printf("溜之大吉\n");
					}
				}	
     				
			}
		}
		if(fre%2 == 0)
		{
			if(p->name == 'a')
			{
				printf("进入玩家1的地盘,玩家1露出地头蛇本性强行收过路费 -300元\n");
				role2->assets = role2->assets - 300;
				if(role2->data == role1->data)
					printf("看见玩家1在家,算了下次在找你麻烦\n");
				else
				{
					printf("看见玩家1不在家,想要收购他的地盘\n");
					printf("1.收购他的地盘\n");
				    printf("2.离得远远的\n");
				    printf("输入的选项:");
				    scanf("%d",&tmp);
					if(tmp == 1)
					{
						printf("购得地盘改名为b  -150元\n");
						role2->assets = role2->assets - 150;
						p->name = 'b';
						role1->home--;
					}
					if(tmp == 2)
					{
						printf("溜之大吉\n");
					}
				}	
     				
			}
		}
		role_information(role1, role2);
		printf("\n");
		bank_interest(head);//银行存钱吃利息

		if(role1->assets <= 0)
		{
			printf("玩家1没有钱了失去游戏资格,玩家2胜利,撒花");
		}
		if(role2->assets <= 0)
		{
			printf("玩家2没有钱了失去游戏资格,玩家1胜利,撒花");
		}
		show (x, b, 20, d, e, f, g, role1->data, role2->data );
		printf("\n");
	}
	
}
//初始化头节点
kernel_list list_init(void)
{
	// 有头结点的-空链表
	kernel_list head = malloc(sizeof(listnode));
	memset(head, 0, sizeof(listnode));
	
	// 让小结构体的前后指针指向自己
	INIT_LIST_HEAD(&head->alist);
	
	return head;
	
}
//创建新节点
kernel_list list_node_create(int tmp, char name, singly_list service,singly_list1 service1)
{
	// 有头结点的-空链表
	kernel_list new = malloc(sizeof(listnode));
	memset(new, 0, sizeof(listnode));
	
	// 让小结构体的前后指针指向自己
	INIT_LIST_HEAD(&new->alist);
	
	new->data = tmp;
	new->name = name;
	new->service = service;
	new->service1 = service1;
	return new;
	
}
//初始化人物角色
role_list role_init(char name)
{
	// 有头结点的-空链表
	role_list head = malloc(sizeof(listrole));
	memset(head, 0, sizeof(listrole));
	head->home = 0;
	head->aggressivity = 10;
	head->assets = 4000;
	head->name = name;
	head->data = 0;
	head->alist = NULL;
	
	return head;
	
}
void list_show(kernel_list head)
{
	kernel_list tmp;
	struct list_head *pos;
	for(pos = head->alist.next; pos !=  &(head->alist); pos = pos->next)
	{
		tmp = list_entry(pos, listnode, alist);
		
		printf("%d-->", tmp->data);
	}
		printf("\n");
	for(pos = head->alist.next; pos !=  &(head->alist); pos = pos->next)
	{
		tmp = list_entry(pos, listnode, alist);
		printf("%c-->", tmp->name);
	}
	tmp = NULL;
	free(tmp);
	pos = NULL;
	free(pos);
	printf("\n");
}
void bank_interest(kernel_list head)
{
	kernel_list tmp;
	struct list_head *pos;
	for(pos = head->alist.next; pos !=  &(head->alist); pos = pos->next)
	{
		tmp = list_entry(pos, listnode, alist);
		if(tmp->name == 'B' && tmp->data == 20)
		{
			if(tmp->service1->next->save_money != 0)
			{
				tmp->service1->next->save_money=tmp->service1->next->save_money+(tmp->service1->next->save_money/20);
			}
			if(tmp->service1->next->next->save_money != 0)
			{
				tmp->service1->next->next->save_money=tmp->service1->next->next->save_money+(tmp->service1->next->next->save_money/30);
			}
			printf("玩家1的银行存款:%d\n",tmp->service1->next->save_money);
			printf("玩家2的银行存款:%d\n",tmp->service1->next->next->save_money);
		}
	}
}
//人物信息显示
void role_information(role_list role1, role_list role2)
{
	//printf("玩家1的名字:%s\n",role1->name);
	printf("玩家1的财富:%d元\n",role1->assets);
	printf("玩家1的攻击力:%d\n",role1->aggressivity);
	printf("玩家1的房屋数:%d\n",role1->home);
	printf("玩家1的位置:%d\n",role1->data);
	//printf("玩家2的名字:%s\n",role2->name);
	printf("玩家2的财富:%d元\n",role2->assets);
	printf("玩家2的攻击力:%d\n",role2->aggressivity);
	printf("玩家2的房屋数:%d\n",role2->home);
	printf("玩家2的位置:%d\n",role2->data);
}
void space()
{
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
}