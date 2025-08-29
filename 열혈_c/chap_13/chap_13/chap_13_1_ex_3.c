#include <stdio.h>

int main(void)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int i = 0;
	int j = 0;
	int sum = 0;

	while (i < 5)
	{
		int * ptr = &arr[i];
		* ptr -= 2;
		printf("ptr = %d\n", *ptr);
		i++;
	}
	
	sum = arr[j] + arr[j+1] + arr[j + 2] + arr[j + 3] + arr[j + 4];



	printf("Sum of array elements = %d\n", sum);
	return 0;
}
	/*
	int* ptr1 = &arr[0];
	*ptr1 += 2;
	printf("ptr1 = %d\n", *ptr1);

	int* ptr2 = &arr[1];
	*ptr2 += 2;
	printf("ptr2 = %d\n", *ptr2);

	int* ptr3 = &arr[2];
	*ptr3 += 2;
	printf("ptr3 = %d\n", *ptr3);

	int* ptr4 = &arr[3];
	*ptr4 += 2;
	printf("ptr4 = %d\n", *ptr4);

	int* ptr5 = &arr[4];
	*ptr5 += 2;
	printf("ptr5 = %d\n", *ptr5);
	*/