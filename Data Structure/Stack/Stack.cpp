#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1

void StackInit(Stack* ps)		//初始化
{
	assert(ps);
	STDataType* p = (STDataType*)malloc(4 * sizeof(STDataType)); //初始化开辟4个数据大小的动态内存空间
	if (p == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	ps->data = p;
	ps->_top = 0;
	ps->_capacity = 4;
}

void StackPush(Stack* ps, STDataType x)		//入栈
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		STDataType* p = (STDataType*)realloc(ps->data, ps->_capacity * 2 * sizeof(STDataType));
		//注意，realloc第二个参数是扩容后的总容量，返回值为调整后的那段连续空间的首地址
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
	return(ps->data[ps->_top - 1]);		//注意top-1
}

void StackDestroy(Stack* ps)		//销毁栈是指将栈的容量归零，因此，仅仅释放数组即可
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