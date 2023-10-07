#include"SLL.h"

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

//β��
void SLLPushBack(SLLNode** pphead, SLLDataType x)
//����ʹ��һ��ָ��ָ��phead���Ӷ������ں������޸�pheadֵ��������ֱ�ӽ�phead���뺯���������õ�����ʵ��phead�ĸ������μ��βδ��ݡ�
{
	if (*pphead == NULL) *pphead = BuySLLNode(x);
	else
	{
		SLLNode* phead = *pphead;	//���ｫpphead�����õõ�pheadֵ������phead��ĵ�ַֻ��һ��ֵ����Ҫ���丳��һ��pointer�Ա�ʹ��
		while (phead->data)
		{
			phead = phead->next;
		}
		phead->data = x;
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
	if (*pphead == 0) printf("The sinked list is empty.");		//�����
	if (p->next == NULL) free(p);		//����ֻ��һ�����
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
	if (p == 0) printf("The sinked list is empty.");
	else
	{
		/*while (p->data != x)
		{p = p->next;}
		return p;*/ //����д���޷�ʶ��x����ssl�е����
		while (p->data)
		{
			if (p->data == x) return p;
			else p = p->next;
		}
		return NULL;
	}
}

//��ĳԪ�غ����һ����Ԫ��
void SLLInsertAfter(SLLDataType x, SLLNode* pos)
{
	if (pos == 0) printf("The position of sinked list is empty.");
	SLLNode* newnode = BuySLLNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��ĳԪ�غ��һ��Ԫ��
void SLLEraseAfter(SLLNode* pos)
{
	if (pos == 0) printf("The position of sinked list is empty.");
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
