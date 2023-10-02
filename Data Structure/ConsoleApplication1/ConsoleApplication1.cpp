#include<stdio.h>
#include<stdlib.h>

typedef int SLLDataType;		//single acyclic linked list, SL for short

typedef struct SLLNode
{
	SLLDataType data;		//int data
	struct SLLNode* next;
};

void SLLPrint(SLLNode* phead)		//head pointer, phead for short
{
	SLLNode* p = phead;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
}

SLLNode* BuySLLNode(SLLDataType x)
{
	SLLNode* newnode = (SLLNode*)malloc(sizeof(SLLNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;;
	return newnode;
}

void SLLPushBack(SLLNode** pphead, SLLDataType x)	//尾插 
//这里使用一个指针指向phead，从而可以在函数中修改phead值。否则，若直接将phead传入函数，函数得到的其实是phead的副本，参见形参传递。
{
	if (*pphead == NULL) *pphead = BuySLLNode(x);
	else 
	{
		SLLNode* p = *pphead;	//这里将
		while(*p->data)
		{
			*pphead = *pphead->next;
		}
	}
}
