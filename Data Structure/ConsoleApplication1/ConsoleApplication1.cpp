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

void SLLPushBack(SLLNode** phead, SLLDataType x)	//尾插
{
	if (*phead == NULL) *phead = BuySLLNode(x);
	else 
	{
		while(*phead->data)
		{
			*phead = *phead->next;
		}
	}
}
