#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
typedef int CDLLDataType;
typedef struct CDLLNode
{
	CDLLDataType data;
	struct CDLLNode* next;
	struct CDLLNode* prev;
}CDLLNode;
