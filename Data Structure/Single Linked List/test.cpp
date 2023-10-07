#include "SLL.h"

void menu()
{
	printf("*******************************\n");
	printf("****1.β������  2.β��ɾ�� ****\n");
	printf("****3.ͷ������  4.ͷ��ɾ�� ****\n");
	printf("****5.�м����  6.�м�ɾ�� ****\n");
	printf("****7.��ӡ      0.�˳�     ****\n");
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
			printf("���������֣�");
			SLLDateType i;
			scanf("%d", &i);
			SListPushBack(&Phead, i);
			break;
		case 2:
			SListPopBack(&Phead);
			break;
		case 3:
			printf("������Ҫд������֣�");
			SLTDateType a;
			scanf("%d", &a);
			SListPushFront(&Phead, a);
			break;
		case 4:
			SListPopFront(&Phead);
			break;
		case 5:
			printf("�Ὣ���ݲ������������֮���λ��\n");
			printf("������Ҫ����λ�õ����ּ�Ҫ��������֣�");
			SLTDateType b, j;
			scanf("%d %d", &b, &j);
			SListNode* ret1 = SListFind(Phead, b);
			if (ret1 != NULL)
			{
				SListInsertAfter(ret1, j);
			}
			else
			{
				printf("�����ֲ�����");
			}
			break;
		case 6:
			printf("������Ҫɾ��������֮ǰ������:");
			SLTDateType c;
			scanf("%d", &c);
			SListNode* ret2 = SListFind(Phead, c);
			if (ret2 != NULL)
			{
				SListEraseAfter(ret2);
			}
			else
			{
				printf("δ�ҵ�������");
			}
			break;
		case 7:
			SListPrint(Phead);
			break;
		case 0:
			printf("�˳�");
			SListDestroy(&Phead);
			break;
		default:
			printf("�����������������");
			break;
		}

	} while (input);

	return 0;
}