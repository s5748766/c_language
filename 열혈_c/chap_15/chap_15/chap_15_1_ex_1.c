#include <stdio.h>

void oddnum(int * odd)
{
	int a = 0;
	for (a = 0; a < 10; a++)
	{
		if (*(odd + a) % 2 != 0)
		{
			printf("odd number is  : %d\n", *(odd + a));
		}
	}
}

void evennum(int * even)
{
	int b = 0;
	for (b = 0; b < 10; b++)
	{
		if (*(even + b) % 2 != 0)
		{
			printf("odd number is  : %d\n", * (even + b));
		}
	}
}

int main(void)
{
	int num[10];
	int* ptr;
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("Enter number %d: ", j + 1);
		scanf_s("%d \n", &num[i]);
		ptr = &num[i];
		j++;
	}
	oddnum(ptr);
	evennum(ptr);

	return 0;
}