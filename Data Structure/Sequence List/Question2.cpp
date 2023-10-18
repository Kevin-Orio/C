//设计一个高效算法, 将顺序表L的所有元素逆置, 要求算法的空间复杂度为O(1)。
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
//为了使空间复杂度为常数，每次将一个元素放到最后，该元素后面的元素向前挪动一次