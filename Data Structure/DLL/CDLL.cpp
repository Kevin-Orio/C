#include "CDLL.h"
//��ͷ���ѭ��˫����
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

//ͷ��㣬��������ͷָ��
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

void CDLLPushFront(CDLLNode* phead)
{
	assert(phead);
	
}

