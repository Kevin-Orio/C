#include "SortFunction.h"
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

void ShellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //Knuth's increment
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = array[end + gap];
			while (end >= 0)
			{
				if (temp < array[end])
				{
					array[end + gap] = array[end];
				}
				else { break; }
				end = end - gap;
			}
			array[end + gap] = temp;
		}
	}
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void SelectSort(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (array[i] < array[min])
			{
				min = i;
			}
			if (array[i] > array[max])
			{
				max = i;
			}
		}
		swap(&array[begin], &array[min]);
		if (begin == max)
		{
			max = min;
		}
		swap(&array[end], &array[max]);
		begin++;
		end--;
	}
}

void BubbleSort(int* array, int n)
{
	for (int i = n; i--; i > 0)
	{
		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) { break; }
	}
}
