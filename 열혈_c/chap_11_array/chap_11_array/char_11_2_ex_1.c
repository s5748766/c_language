#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];


	//���� �Է�
	printf("Enter a string: ");
	scanf_s("%s", str, sizeof(str));

	int i = 0;
	int length = 0;

	//array ���� ���� ���
	for(i=0; str[i] != '\0'; i++)
	{
		length++;
	}

	printf("string length = %d\n", length);
	
	return 0;

}