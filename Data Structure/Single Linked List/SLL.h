#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLLDataType;		//single acyclic linked list, SL for short

typedef struct SLLNode
{
	SLLDataType data;		//int data
	struct SLLNode* next;
}SLLNode;

// ��̬����һ���ڵ�
SLLNode* BuySLLNode(SLLDataType x);
// �������ӡ
void SLLPrint(SLLNode* phead);
// ������β��
void SLLPushBack(SLLNode** pphead, SLLDataType x);
// �������βɾ
void SLLPopBack(SLLNode** pphead);
// �������ͷ��
void SLLPushFront(SLLNode** pphead, SLLDataType x);
// ������ͷɾ
void SLLPopFront(SLLNode** pphead);
// ���������
SLLNode* SLLFind(SLLNode* phead, SLLDataType x);
// ��������posλ��֮�����x
void SLLInsertAfter(SLLNode* pos, SLLDataType x);
// ������ɾ��posλ��֮���ֵ
void SLLEraseAfter(SLLNode* pos);
// �����������
void SLLDestroy(SLLNode** pphead);
