#include <stdio.h>

void Swap3(int *a, int *b, int *c) 
{
	int temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
	printf("After swapping: \n");
	printf("a = %d\n", *a);
	printf("b = %d\n", *b);
	printf("c = %d\n", *c);
	printf("temp = %d\n", temp);
}


int main(void)
{
	int num1, num2, num3;
	printf("Enter number1: ");
	scanf_s("%d", & num1);
	printf("\n");
	printf("Enter number2: ");
	scanf_s("%d", & num2);
	printf("\n");
	printf("Enter number3: ");
	scanf_s("%d", & num3);
	printf("\n");
	Swap3(&num1, &num2, &num3);

	return 0;
}