#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

void menu()
{
	printf("*******************************\n");
	printf("****1.尾部插入  2.尾部删除 ****\n");
	printf("****3.头部插入  4.头部删除 ****\n");
	printf("****5.中间插入  6.中间删除 ****\n");
	printf("****7.打印      0.退出     ****\n");
	printf("*本链表所存储的数据类型是：整形*\n");
	printf("*******************************\n");

}

void main()
{
	Stack* ps = NULL;
	int input;
	do
	{
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			int capacity;
			scanf("%d", &capacity);
			StackInit(ps, capacity);

		}
		}
	} while (input);
}