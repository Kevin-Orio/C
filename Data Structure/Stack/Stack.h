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
void StackInit(Stack* ps, int x); //��ʼ��
void StackPush(Stack* ps, STDataType x); //��ջ
void StackPop(Stack* ps); //��ջ
bool StackEmpty(Stack* ps);	//�ж�ջ�Ƿ�Ϊ��
STDataType StackTop(Stack* ps);	//ȡջ��Ԫ��
void StackDestroy(Stack* ps); //����ջ��ָ��ջ���������㣬��ˣ������ͷ����鼴��
