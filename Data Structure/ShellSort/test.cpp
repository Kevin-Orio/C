#include "SortFunction.h"
#include <time.h>
#define length 10

void main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	int array[length];
	while (i < length)
	{
		array[i] = rand() % 100;
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	
	BubbleSort(array, length);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
}