#include <stdio.h>

void ShowAllData(const int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main(void)
{
	ShowAllData((int[]) { 1, 2, 3, 4, 5 }, 5);
}