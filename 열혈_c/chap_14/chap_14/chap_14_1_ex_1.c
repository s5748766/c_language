#include <stdio.h>

void SquareByValue(int n1)
{
	n1 = n1 * n1;
	printf("Square of the number(val) is: %d\n", n1);
}

void SquareByReference(int* n2)
{
	*n2 = (*n2) * (*n2);
	printf("Square of the number(ref) is: %d\n", *n2);
}
int main() 
{
	int num;
	int temp;
	printf("Enter a number: ");
	scanf_s("%d", &num);
	SquareByValue(num);
	temp = num; // Store original value for reference
	SquareByReference(&temp);
	return 0;
} 