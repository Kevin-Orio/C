#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
};

void StackInit(Stack* ps)
{
	assert(ps);
	
}