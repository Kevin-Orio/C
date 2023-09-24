#include<stdlib.h>
int rollem(int sides)
{
	int roll;
	roll = rand() % sides + 1;
	return roll;
}