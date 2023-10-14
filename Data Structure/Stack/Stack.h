#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* data;		//该指针指向为栈开辟的一段连续内存
	int _top;
	int _capacity;
}Stack;
void StackInit(Stack* ps); //初始化
void StackPush(Stack* ps, STDataType x); //入栈
void StackPop(Stack* ps); //出栈
bool StackEmpty(Stack* ps);	//判断栈是否为空
STDataType StackTop(Stack* ps);	//取栈顶元素
void StackDestroy(Stack* ps); //销毁栈是指将栈的容量归零，因此，仅仅释放数组即可
int StackSize(Stack* ps);
