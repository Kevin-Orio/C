#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;		//该指针指向为栈开辟的一段连续内存
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps, int x)		//初始化
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

void StackPush(Stack* ps, STDataType x)		//入栈
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		STDataType* p = (STDataType  *)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		//注意，realloc第二个参数是扩容后的总容量
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

void StackPop(Stack* ps)		//出栈
{
	assert(ps);
	assert(StackEmpty(ps));
	ps->_top--;		//无需清空数组中top的数据，只需将其当作垃圾值即可
}

bool StackEmpty(Stack* ps)		//判断栈是否为空
{
	assert(ps);
	return ps->_top;
}

STDataType StackTop(Stack* ps)		//取栈顶元素
{
	assert(ps);
	assert(StackEmpty);
	return(ps->_a[ps->_top-1]);		//注意top-1
}

void StackDestroy(Stack* ps)		//销毁栈是指将栈的容量归零，因此，仅仅释放数组即可
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
