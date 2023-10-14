#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

void menu()
{
	printf("*******************************\n");
	printf("****1.创建一个栈  2.元素入栈 ****\n");
	printf("****3.元素出栈    4.取栈顶元素 ***\n");
	printf("****5.栈元素个数             ****\n");
	printf("*本栈所存储的数据类型是：整形*\n");
	printf("*******************************\n");

}

void main()
{
	menu();
	Stack st;
	int input;
	st.data = 0;
	st._capacity = 0;
	st._top = 0;
	do
	{
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			
			StackInit(&st);
			printf("栈初始化完成\n");
			break;
		}
		case 2:
		{
			STDataType x;
			printf("请输入一个入栈元素\n");
			scanf("%d", &x);
			StackPush(&st, x);
			break;
		}
		case 3:
		{
			StackPop(&st);
			printf("栈顶元素已出栈\n");
			break;
		}
		case 4:
		{
			printf("栈顶元素为：%d\n", StackTop(&st));
			break;
		}
		case 5:
		{
			printf("栈顶元素个数为：%d\n", StackSize(&st));
			break;
		}
		}
	} while (input);
}