#define _CRT_SECURE_NO_WARNINGS 1
#include"SLL.h"
//nullָ��ʲô��û�У�Ҳ����˵null������data��next
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

//β��
void SLLPushBack(SLLNode** pphead, SLLDataType x)
//����ʹ��һ��ָ��ָ��phead���Ӷ������ں������޸�pheadֵ��������ֱ�ӽ�phead���뺯���������õ�����ʵ��phead�ĸ������μ��βδ��ݡ�
{
	if (*pphead == NULL) //pphead�洢����phead��ַ�����*pphead=phead��ֵ
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

//ͷ��
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

//βɾ
void SLLPopBack(SLLNode** pphead)
{
	SLLNode* p = *pphead;
	if (*pphead == 0)
	{
		printf("The sinked list is empty.");		//�����
		return;
	}
	/*if (p->next == NULL) free(p);*/		//����ֻ��һ�����
	else     //�����������������
	{
		while (p->next->next)
		{
			p = p->next;
		}
		free(p->next);
		p->next = NULL;
	}
}

//ͷɾ
void SLLPopFront(SLLNode** pphead)
{
	SLLNode* p = *pphead;
	if (*pphead == 0) printf("The sinked list is empty.");
	else
	{
		*pphead = p->next;// *pphead= *pphead -> next ����д���Ǵ���ġ�*ppheadֻ��һ����ַ��ֵ�������ǽṹ��pointer��������->
		free(p);
	}
}

//����
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
		return p;*/ //����д���޷�ʶ��x����ssl�е����
		while (p)
		{
			if (p->data == x) return p;
			else p = p->next;
		}
		return NULL;
	}
}

//��ĳԪ�غ����һ����Ԫ��
void SLLInsertAfter(SLLNode* pos, SLLDataType x)
{
	assert(pos);
	SLLNode* newnode = BuySLLNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��ĳԪ�غ��һ��Ԫ��
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

//��������
void SLLDestroy(SLLNode** pphead)	//
{
	if (*pphead == 0) printf("The sinked list has already been empty.");		//�����
	while (*pphead)
	{
		SLLNode* p = (*pphead)->next;
		free(*pphead);
		*pphead = p;

	}
}
