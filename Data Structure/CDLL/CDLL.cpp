#include "CDLL.h"
//带头结点循环双链表
CDLLNode* BuyCDLLNode(CDLLDataType x)
{
	CDLLNode* temp = (CDLLNode*)malloc(sizeof(CDLLNode));
	if (temp = NULL)
	{
		perror("malloc");
	}
	temp->data = x;
	return temp;
}

//头结点，单链表是头指针
CDLLNode* CDLLCreate()
{
	CDLLNode* head = BuyCDLLNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

void CDLLPrint(CDLLNode* phead)
{
	assert(phead);
	CDLLNode* temp = phead->next;
	while (temp != phead)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("head\n");
}

void CDLLPushBack(CDLLNode* phead, CDLLDataType x)
{
	assert(phead);
	CDLLNode* newnode = BuyCDLLNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

void CDLLPopBack(CDLLNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	CDLLNode* tail = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(tail);
}

//头插：插在头结点的后面
void CDLLPushFront(CDLLNode* phead, CDLLDataType x)
{
	assert(phead);
	CDLLNode* newnode = BuyCDLLNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

void CDLLPopFront(CDLLNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	CDLLNode* oldnode = phead->next;
	oldnode->next->prev = phead;
	phead->next = oldnode->next;
	free(oldnode);
}

CDLLNode* CDLLFind(CDLLNode* phead, CDLLDataType x)
{
	assert(phead);
	CDLLNode* temp = phead->next;
	while (temp != phead)
	{
		if (temp->data == x)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

//在pos结点前插入
void CDLLInsert(CDLLNode* pos, CDLLDataType x)
{
	assert(pos);
	CDLLNode* newnode = BuyCDLLNode(x);

}
