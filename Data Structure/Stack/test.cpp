#include"Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

void menu()
{
	printf("*******************************\n");
	printf("****1.β������  2.β��ɾ�� ****\n");
	printf("****3.ͷ������  4.ͷ��ɾ�� ****\n");
	printf("****5.�м����  6.�м�ɾ�� ****\n");
	printf("****7.��ӡ      0.�˳�     ****\n");
	printf("*���������洢�����������ǣ�����*\n");
	printf("*******************************\n");

}

void main()
{
	Stack* ps = NULL;
	int input;
	do
	{
		printf("��ѡ��");
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