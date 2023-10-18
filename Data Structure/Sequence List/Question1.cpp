//��˳�����ɾ��������Сֵ��Ԫ��(����Ψһ)���ɺ������ر�ɾԪ�ص�ֵ��
//�ճ���λ�������һ��Ԫ���, ��˳���Ϊ��, ����ʾ������Ϣ���˳�����
#include "SeqList.h"

struct value
{
	int pos;
	SLDateType e;
};

struct value FindMin(SeqList* ps)
{
	assert(ps);
	struct value v;
	v.e = ps->a[0];
	v.pos = 0;
	for (int i = 1; i < ps->size; i++)
	{
		if (ps->a[i] < v.e)
		{
			v.pos = i;
			v.e = ps->a[i];
		}
	}
	ps->a[v.pos] = ps->a[ps->size - 1];
	ps->size--;
	return v;
}

void main()
{
	SeqList L = A_Random_SeqList();
	SeqListPrint(&L);
	struct value value = FindMin(&L);
	printf("position : %d, value : %d\n",value.pos+1,value.e);
	SeqListPrint(&L);
}