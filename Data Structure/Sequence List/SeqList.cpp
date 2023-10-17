#include"SeqList.h"

//��׼��ʼ��
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}
//˳���ṹ���SLDateType*ֻ��һ��ָ�룬Ϊ�����ڴ�������Զ��忪���ڴ�����ʹ���Զ���ָ����Ҫ���ڴ��С����

//��׼˳�������
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//��malloc���٣����ã����ڴ�ռ�����ǵ��ͷţ���������ϵͳ��
//����ָ��ÿռ��ָ��ǵ��ÿգ��Է�����Ƿ������Ѿ��ͷŵĿռ䡣


//��׼˳����ӡ
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//->��������[]�����ȼ�һ�£�������ѭ�����ҵļ���˳��

//��׼˳���β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	//������麯�����������������������
	SeqListCheckCapacity(ps);
	//��ʼβ��
	ps->a[ps->size] = x;
	ps->size++;
}
//���Ѿ�������ڴ�ռ�����ʱ��Ҫʹ��realloc�����������������ֱ���ԭ��ַ��ϣ�����ݵ��ڴ��С����λ���ֽڣ���
// ע��reallocҲ�п��ܿ���ʧ�ܣ�����Ҫ���ڴ�̫��ʱ��������Ҫ���ñ���׼��
//��Ϊ����Ҫ����������������˳������Ľṹ�����Ե���ָ����ָ�ռ�ĺ����ڴ�ռ䲻��ʱ��������Ѱ
//�㹻�ռ��λ�ÿ��٣�Ҳ������ν��������ݣ���ʱָ���λ�øı䣬��Ҫ����һ����ʱָ����������ɡ�


//��׼˳���βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}


// ��׼��˳���ͷ��
//ͷ��ͷɾ��˳�����ʱ�临�Ӷ���O(N),����Ч��
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	//������麯��
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
//ͷ��Ҳ��Ҫ����

//��Ȼ�Ѿ����߽�Ҫ���ݶ�Σ���ô���罫���ݲ�����װ��һ������SeqListCheckCapacity��
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * 2 * ps->capacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;

		ps->capacity *= 2;
		printf("���ݳɹ���");
	}

}

//��׼��˳���ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}


//��׼˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	int pos = -1;//���û�ҵ�x���ͷ���-1
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			pos = i;
			return pos;
		}
	}
	return pos;
}


//��׼˳���ָ��λ�ò���
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size - 1);
	SeqListCheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->size++;
	ps->a[pos] = x;
}

//��׼��˳���ָ��λ��ɾ��
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size - 1);
	for (int i = pos; i <= ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

