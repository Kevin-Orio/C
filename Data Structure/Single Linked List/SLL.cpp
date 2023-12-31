#define _CRT_SECURE_NO_WARNINGS 1
#include"SLL.h"
//null指针什么都没有，也就是说null不存在data和next
void SLLPrint(SLLNode* phead)
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
	SLLNode* newnode = (SLLNode *)malloc(sizeof(SLLNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;;
	return newnode;
}

//尾插
void SLLPushBack(SLLNode** pphead, SLLDataType x)
//这里使用一个指针指向phead，从而可以在函数中修改phead值。否则，若直接将phead传入函数，函数得到的其实是phead的副本，参见形参传递。
{
	if (*pphead == NULL) //pphead存储的是phead地址，因此*pphead=phead的值
	{
		*pphead = BuySLLNode(x);
		return;
	}
	else
	{
		SLLNode* phead = *pphead;
		while (phead->next)
		{
			phead = phead->next;
		}
		phead->next = BuySLLNode(x);
	}
}

//头插
void SLLPushFront(SLLNode** pphead, SLLDataType x)
{
	if (*pphead == NULL) *pphead = BuySLLNode(x);
	else
	{
		SLLNode* newnode = BuySLLNode(x);
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//尾删
void SLLPopBack(SLLNode** pphead)
{
	SLLNode* p = *pphead;
	if (*pphead == 0)
	{
		printf("The sinked list is empty.");		//链表空
		return;
	}
	/*if (p->next == NULL) free(p);*/		//链表只有一个结点
	else     //链表有至少两个结点
	{
		while (p->next->next)
		{
			p = p->next;
		}
		free(p->next);
		p->next = NULL;
	}
}

//头删
void SLLPopFront(SLLNode** pphead)
{
	SLLNode* p = *pphead;
	if (*pphead == 0) printf("The sinked list is empty.");
	else
	{
		*pphead = p->next;// *pphead= *pphead -> next 这种写法是错误的。*pphead只是一个地址（值），不是结构体pointer，不能用->
		free(p);
	}
}

//查找
SLLNode* SLLFind(SLLNode* phead, SLLDataType x)
{
	SLLNode* p = phead;
	if (p == 0)
	{
		printf("The sinked list is empty.");
		return NULL;
	}
	else
	{
		/*while (p->data != x)
		{p = p->next;}
		return p;*/ //这种写法无法识别x不在ssl中的情况
		while (p)
		{
			if (p->data == x) return p;
			else p = p->next;
		}
		return NULL;
	}
}

//在某元素后插入一个新元素
void SLLInsertAfter(SLLNode* pos, SLLDataType x)
{
	assert(pos);
	SLLNode* newnode = BuySLLNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除某元素后的一个元素
void SLLEraseAfter(SLLNode* pos)
{
	if (pos == 0)
	{
		printf("The position of sinked list is empty.");
		return;
	}
	if (pos->next == NULL) return;
	SLLNode* p = pos->next;
	pos->next = p->next;
	free(p);
}

//销毁链表
void SLLDestroy(SLLNode** pphead)	//
{
	if (*pphead == 0) printf("The sinked list has already been empty.");		//链表空
	while (*pphead)
	{
		SLLNode* p = (*pphead)->next;
		free(*pphead);
		*pphead = p;

	}
}
