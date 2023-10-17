#include"SeqList.h"

//标准初始化
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}
//顺序表结构体里，SLDateType*只是一个指针，为它在内存堆区里自定义开辟内存区域（使其自定义指向想要的内存大小）。

//标准顺序表销毁
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//对malloc开辟（借用）的内存空间用完记得释放（还给操作系统）
//而对指向该空间的指针记得置空，以防意外非法访问已经释放的空间。


//标准顺序表打印
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//->操作符和[]的优先级一致，所以遵循从左到右的计算顺序。

//标准顺序表尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	//容量检查函数，检查容量，已满则扩容
	SeqListCheckCapacity(ps);
	//开始尾插
	ps->a[ps->size] = x;
	ps->size++;
}
//对已经申请的内存空间扩容时，要使用realloc函数，它两个参数分别是原地址和希望扩容的内存大小（单位是字节），
// 注意realloc也有可能开辟失败（当需要的内存太大时），所以要做好报错准备
//因为它需要保持像数组那样的顺序连贯的结构，所以当其指针所指空间的后面内存空间不足时，它会另寻
//足够空间的位置开辟，也就是所谓的异地扩容，此时指针的位置改变，需要另外一个临时指针变量做过渡。


//标准顺序表尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}


// 标准的顺序表头插
//头插头删在顺序表里时间复杂度是O(N),不高效。
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	//容量检查函数
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
//头插也需要扩容

//既然已经或者将要扩容多次，那么不如将扩容操作封装成一个函数SeqListCheckCapacity。
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * 2 * ps->capacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;

		ps->capacity *= 2;
		printf("扩容成功！");
	}

}

//标准的顺序表头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}


//标准顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	int pos = -1;//如果没找到x，就返回-1
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			pos = i;
			return pos;
		}
	}
	return pos;
}


//标准顺序表指定位置插入
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size - 1);
	SeqListCheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->size++;
	ps->a[pos] = x;
}

//标准的顺序表指定位置删除
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size - 1);
	for (int i = pos; i <= ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

