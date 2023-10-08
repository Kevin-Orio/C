#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLLDataType;		//single acyclic linked list, SL for short

typedef struct SLLNode
{
	SLLDataType data;		//int data
	struct SLLNode* next;
}SLLNode;

// 动态申请一个节点
SLLNode* BuySLLNode(SLLDataType x);
// 单链表打印
void SLLPrint(SLLNode* phead);
// 单链表尾插
void SLLPushBack(SLLNode** pphead, SLLDataType x);
// 单链表的尾删
void SLLPopBack(SLLNode** pphead);
// 单链表的头插
void SLLPushFront(SLLNode** pphead, SLLDataType x);
// 单链表头删
void SLLPopFront(SLLNode** pphead);
// 单链表查找
SLLNode* SLLFind(SLLNode* phead, SLLDataType x);
// 单链表在pos位置之后插入x
void SLLInsertAfter(SLLNode* pos, SLLDataType x);
// 单链表删除pos位置之后的值
void SLLEraseAfter(SLLNode* pos);
// 单链表的销毁
void SLLDestroy(SLLNode** pphead);
