#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "SLL.h"

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
		{
			printf("请输入新结点的值：");
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
			printf("请输入新结点的值：");
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
		printf("会将数据插入进输入数字之后的位置\n");
		printf("请输入要插入位置的数字及要插入的数字：");
		
		scanf("%d %d", &b, &j);
		SLLNode* ret1 = SLLFind(Phead, b);
		if (ret1 != NULL)
		{
			SLLInsertAfter(ret1, j);
		}
		else
		{
			printf("该数字不存在");
		}
		break;
		}
		case 6:
		{
			printf("请输入要删除的数字之前的数字:");
			SLLDataType c;
			scanf("%d", &c);
			SLLNode* ret2 = SLLFind(Phead, c);
			if (ret2 != NULL)
			{
				SLLEraseAfter(ret2);
			}
			else
			{
				printf("未找到该数字");
			}
			break;
		}
		case 7:
			SLLPrint(Phead);
			break;
		case 0:
			printf("退出");
			SLLDestroy(&Phead);
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}

	} while (input);

	return 0;
}