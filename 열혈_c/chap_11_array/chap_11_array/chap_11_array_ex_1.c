#include <stdio.h>

int main(void)
{
    int num[5];
    int i = 0;
    int j = 1;
    int sum;
	int max = 0; // Minimum value for an int
	int min = 2147483647; // Maximum value for an int


    for (j = 1; j < 6; j++)
    {
        printf("input num %d : ", j);
        scanf_s("%d", &num[i]);
        i++;
    }
    printf("\n");

    i = 0;
    j = 1;

    for (j = 1; j < 6; j++)
    {
        printf("output num %d : ", j);
        printf("%d\n", num[i]);
		i++;
    }

    printf("\n");


    sum = num[0] + num[1] + num[2] + num[3] + num[4];

    printf("sum = %d\n\n", sum);

    for (i = 0; i < 5; i++)
    {
		// Check if the current number is greater than the current maximum
        if (num[i] > max)
        {
            max = num[i];
        }
		// Check if the current number is less than the current minimum 
        if (num[i] < min)
        {
            min = num[i];
        }

    }

	printf("max = %d\n\n", max);
	
    printf("min = %d\n\n", min);

    return 0;
}