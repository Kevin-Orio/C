//���һ����Ч�㷨, ��˳���L������Ԫ������, Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)��
#include "SeqList.h"

void Reverse(SeqList* ps)
{
	for (int i=ps->size-2; i>=0; i--)
	{
		ps->a[ps->size] = ps->a[i];
		for (int j = i; j<=ps->size-1; j++)
		{
			ps->a[j] = ps->a[j + 1];
		}
	}
}
void Reverse1(SeqList* ps)
{
	SLDateType temp;
	for (int i = 0; i < ps->size / 2; i++)
	{

	}
}


void main() 
{
	SeqList L = A_Random_SeqList();
	SeqListPrint(&L);
	Reverse(&L);
	SeqListPrint(&L);
}
//Ϊ��ʹ�ռ临�Ӷ�Ϊ������ÿ�ν�һ��Ԫ�طŵ���󣬸�Ԫ�غ����Ԫ����ǰŲ��һ��