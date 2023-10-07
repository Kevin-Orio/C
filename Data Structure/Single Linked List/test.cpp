#include "SLL.h"

void menu()
{
	printf("*******************************\n");
	printf("****1.尾部插入  2.尾部删除 ****\n");
	printf("****3.头部插入  4.头部删除 ****\n");
	printf("****5.中间插入  6.中间删除 ****\n");
	printf("****7.打印      0.退出     ****\n");
	printf("*******************************\n");

}

int main()
{
	menu();
	SLLNode* Phead = NULL;
	int input;
	do
	{
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入数字：");
			SLLDateType i;
			scanf("%d", &i);
			SListPushBack(&Phead, i);
			break;
		case 2:
			SListPopBack(&Phead);
			break;
		case 3:
			printf("请输入要写入的数字：");
			SLTDateType a;
			scanf("%d", &a);
			SListPushFront(&Phead, a);
			break;
		case 4:
			SListPopFront(&Phead);
			break;
		case 5:
			printf("会将数据插入进输入数字之后的位置\n");
			printf("请输入要插入位置的数字及要插入的数字：");
			SLTDateType b, j;
			scanf("%d %d", &b, &j);
			SListNode* ret1 = SListFind(Phead, b);
			if (ret1 != NULL)
			{
				SListInsertAfter(ret1, j);
			}
			else
			{
				printf("该数字不存在");
			}
			break;
		case 6:
			printf("请输入要删除的数字之前的数字:");
			SLTDateType c;
			scanf("%d", &c);
			SListNode* ret2 = SListFind(Phead, c);
			if (ret2 != NULL)
			{
				SListEraseAfter(ret2);
			}
			else
			{
				printf("未找到该数字");
			}
			break;
		case 7:
			SListPrint(Phead);
			break;
		case 0:
			printf("退出");
			SListDestroy(&Phead);
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}

	} while (input);

	return 0;
}