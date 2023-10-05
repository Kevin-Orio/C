#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq) //pointer queue
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	if (pq->head == NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
		pq->head = pq->tail = newnode;
		pq->size++;
	}

	else {
		newnode->data = x;
		newnode->next = NULL;
		pq->tail->next = newnode;
		pq->tail = newnode;
		pq->size++;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(QueueEmpty(pq));
	QNode* p = pq->head->next;
	free(pq->head);
	pq->head = p;
	pq->size--;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head && pq->tail;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(QueueEmpty);
	return pq->head->data;
}

QDataType QueueTail(Queue* pq)
{
	assert(pq);
	assert(QueueEmpty);
	return pq->tail->data;
}

QDataType QueueSize(Queue* pq)
{
	assert(pq);
	assert(QueueEmpty);
	return pq->size;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	while (pq)
	{
		QNode* p = pq->head->next;
		free(pq);
		pq->head = p;
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}
