//从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。
//空出的位置由最后一个元素填补, 若顺序表为空, 则显示出错信息并退出运行
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