#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;		//��ָ��ָ��Ϊջ���ٵ�һ�������ڴ�
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps, int x)		//��ʼ��
{
	assert(ps);
	STDataType* p = (STDataType*)malloc(x * sizeof(STDataType));
	if (p == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	ps->_a = p;
	ps->_top = 0;
	ps->_capacity = x;
}

void StackPush(Stack* ps, STDataType x)		//��ջ
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		STDataType* p = (STDataType  *)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		//ע�⣬realloc�ڶ������������ݺ��������
		if (p == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		ps->_a = p;
		ps->_capacity = ps->_capacity * 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)		//��ջ
{
	assert(ps);
	assert(StackEmpty(ps));
	ps->_top--;		//�������������top�����ݣ�ֻ�轫�䵱������ֵ����
}

bool StackEmpty(Stack* ps)		//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	return ps->_top;
}

STDataType StackTop(Stack* ps)		//ȡջ��Ԫ��
{
	assert(ps);
	assert(StackEmpty);
	return(ps->_a[ps->_top-1]);		//ע��top-1
}

void StackDestroy(Stack* ps)		//����ջ��ָ��ջ���������㣬��ˣ������ͷ����鼴��
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
