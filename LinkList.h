#include <stdio.h>
#include <stdlib.h>

//定义链表结构体类型
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

//typedef 关键字将自定义类型 struct LNode 起别名 LNode。
//将自定义类型 struct LNode* 起别名LinkList

//接下来是一些链表初始化，建表，插入，删除，查表，求表长等基础操作函数的实现


//尾插法创建链表不包含初始化函数
LinkList Creat_LinkList()
{

	LNode* s=NULL;//s用于标记插入结点
	int input=0;
	LinkList L=(LNode*)malloc(sizeof(LNode));
	LNode* rear=L;//建立尾指针指向链表最后一个元素
	printf("请输入整型数据，回车确认，输入-1完成链表创建：\n");
	scanf("%d",&input);
	while(input!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=input;
		rear->next=s;
		rear=s;
		scanf("%d",&input);
	}
	rear->next=NULL;
	printf("链表建立成功!\n");

	return L;

}

//初始化链表LinkList()
LinkList Init_LinkList()
{
	LinkList ll=(LNode*)malloc(sizeof(LNode));
	ll->next=NULL;
	return ll;
}
//建表，一般有头插法，尾插法建表，具体用哪个看需求

//头插法建表,所建表与输入相逆，输入 1,2,3 链表顺序 3,2,1
LinkList Creat_LinkList_HeadInsert()
{
	LNode* s=NULL;//s用于标记插入结点
	int x=0;
	LinkList L=Init_LinkList();//初始化链表
	LNode* head=L;//建立头结点
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}

	return L;
}

///尾插法建表,所建表与输入相同，输入 1,2,3 链表顺序 1,2,3
LinkList Creat_LinkList_TailInsert()
{

	LNode* s=NULL;//s用于标记插入结点
	int x=0;
	LinkList L=Init_LinkList();
	LNode* rear=L;//建立尾指针指向链表最后一个元素
	printf("请输入整型数据，回车确认，输入-1完成链表创建：\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		rear->next=s;
		rear=s;
		scanf("%d",&x);
	}
	rear->next=NULL;
	printf("链表建立成功!\n");

	return L;

}
//删除表中指定data值的结点

void Delete_LinkList_Bydata(LinkList L,int x)  
{
	int count=0;
	LNode* pre=L;
	LNode* p=L->next;
	while(p)  //当p不为空的时候
	{
		if(p->data==x)
		{
			pre->next=p->next;
			free(p);
			p=pre->next;
			count++;
		}
		else
		{
			pre=p;
			p=p->next;
		}
	}
	if(count==0)
	{
		printf("链表中没有值为%d的结点\n",x);
	}
	printf("处理完毕...\n");
}

//按照序号，删除链表中第n个结点
void Delete_LinkList_Byorder(LinkList L,int n)
{
	LNode* pre=L;
	LNode* p=pre->next;
	int i=0;
	while(i<n-1&&p->next) //p移动到第n个结点处
	{
		pre=p;
		p=p->next;
		++i;
	}
	if(i>=n-1)
	{
		pre->next=p->next;
		free(p);
		p=pre->next;
	}else
	{
		printf("输入值超过链表长度\n");
	}
	printf("处理完毕，已删除第%d个结点\n",n);

}

//求链表表长的函数（不包含头结点）
int ListLength(LinkList L)
{
	int len=0;
	LNode* p=L;
	while(p)
	{
		p=p->next;
		len++;
	}

	return len-1;
}

//查看传入链表的结点值情况

void ShowList(LinkList L)
{
	LNode* p=L->next;

	while(p)
		{
			if(p->next)
			{
				printf("%d->",p->data);
			}
			else
			{
				printf("%d",p->data);
			}
			p=p->next;
		}
	printf("\n");
}

//删除有序链表中重复的元素，使得各元素互异

void Delete_LinkList_Same(LinkList L)
{
	LNode*	pre=L->next;
	LNode*  p=pre->next;
	
	while(p)
	{
		if(pre->data!=p->data)
		{
			pre=p;
			p=p->next;
		}
		else
		{
			pre->next=p->next;
			free(p);
			p=pre->next;
		}
	}
	
}

//将两个有序链表合并为一个新的有序链表
LinkList MergeorderList(LinkList L1,LinkList L2)
{
	LNode* p=L1->next;
	LNode* q=L2->next;
	LinkList L=(LNode*)malloc(sizeof(LNode));
	LNode* k=L;//k作为链表尾指针，方便插入结点
	while(p&&q)//若p,q均不为空
	{
		LNode* s=(LNode*)malloc(sizeof(LNode));
		if(p->data<q->data)
		{
			s->data=p->data;
			p=p->next;
		}
		else
		{
			s->data=q->data;
			q=q->next;
		}
		
		k->next=s;
		k=s;
		k->next=NULL;
	}
	while(p)//当p非空时，即L1中还有关键字的时候，将L1剩余的元素全部赋值到L中
	{
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->data=p->data;
		k->next=s;
		k=s;
		k->next=NULL;
		p=p->next;
	}
	while(q)
	{
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->data=q->data;
		k->next=s;
		k=s;
		k->next=NULL;
		q=q->next;
	}

	return L;
}
