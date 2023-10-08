#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "SLL.h"

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

int main()
{
	menu();
	SLLNode* Phead = NULL;
	int input;
	do
	{
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("�������½���ֵ��");
			SLLDataType i;
			scanf("%d", &i);
			SLLPushBack(&Phead, i);
			break;
		}

		case 2:
			SLLPopBack(&Phead);
			break;
		case 3:
		{
			printf("�������½���ֵ��");
			SLLDataType a;
			scanf("%d", &a);
			SLLPushFront(&Phead, a);
			break;
		}
		case 4:
			SLLPopFront(&Phead);
			break;
		case 5:
		{
		SLLDataType b, j;
		printf("�Ὣ���ݲ������������֮���λ��\n");
		printf("������Ҫ����λ�õ����ּ�Ҫ��������֣�");
		
		scanf("%d %d", &b, &j);
		SLLNode* ret1 = SLLFind(Phead, b);
		if (ret1 != NULL)
		{
			SLLInsertAfter(ret1, j);
		}
		else
		{
			printf("�����ֲ�����");
		}
		break;
		}
		case 6:
		{
			printf("������Ҫɾ��������֮ǰ������:");
			SLLDataType c;
			scanf("%d", &c);
			SLLNode* ret2 = SLLFind(Phead, c);
			if (ret2 != NULL)
			{
				SLLEraseAfter(ret2);
			}
			else
			{
				printf("δ�ҵ�������");
			}
			break;
		}
		case 7:
			SLLPrint(Phead);
			break;
		case 0:
			printf("�˳�");
			SLLDestroy(&Phead);
			break;
		default:
			printf("�����������������");
			break;
		}

	} while (input);

	return 0;
}