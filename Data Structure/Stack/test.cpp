#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

void menu()
{
	printf("*******************************\n");
	printf("****1.����һ��ջ  2.Ԫ����ջ ****\n");
	printf("****3.Ԫ�س�ջ    4.ȡջ��Ԫ�� ***\n");
	printf("****5.ջԪ�ظ���             ****\n");
	printf("*��ջ���洢�����������ǣ�����*\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			
			StackInit(&st);
			printf("ջ��ʼ�����\n");
			break;
		}
		case 2:
		{
			STDataType x;
			printf("������һ����ջԪ��\n");
			scanf("%d", &x);
			StackPush(&st, x);
			break;
		}
		case 3:
		{
			StackPop(&st);
			printf("ջ��Ԫ���ѳ�ջ\n");
			break;
		}
		case 4:
		{
			printf("ջ��Ԫ��Ϊ��%d\n", StackTop(&st));
			break;
		}
		case 5:
		{
			printf("ջ��Ԫ�ظ���Ϊ��%d\n", StackSize(&st));
			break;
		}
		}
	} while (input);
}