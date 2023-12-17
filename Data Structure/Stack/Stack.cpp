#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1

void StackInit(Stack* ps)		//��ʼ��
{
	assert(ps);
	STDataType* p = (STDataType*)malloc(4 * sizeof(STDataType)); //��ʼ������4�����ݴ�С�Ķ�̬�ڴ�ռ�
	if (p == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	ps->data = p;
	ps->_top = 0;
	ps->_capacity = 4;
}

void StackPush(Stack* ps, STDataType x)		//��ջ
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		STDataType* p = (STDataType*)realloc(ps->data, ps->_capacity * 2 * sizeof(STDataType));
		//ע�⣬realloc�ڶ������������ݺ��������������ֵΪ��������Ƕ������ռ���׵�ַ
		if (p == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		ps->data = p;
		ps->_capacity = ps->_capacity * 2;
	}
	ps->data[ps->_top] = x;
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
	return(ps->data[ps->_top - 1]);		//ע��top-1
}

void StackDestroy(Stack* ps)		//����ջ��ָ��ջ���������㣬��ˣ������ͷ����鼴��
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}