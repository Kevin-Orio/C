#include <stdio.h>
#include <stdlib.h>

void InsertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = array[end + 1];
		while (end >= 0)
		{
			if (temp < array[end])
			{
				array[end + 1] = array[end];
			}
			else { break; }
			end--;
		}
		array[end + 1] = temp;
	}
}

void main()
{
	int array[] = { 6, 4, 3, 5, 7 };
	InsertSort(array,5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d",array[i]);
	}
}