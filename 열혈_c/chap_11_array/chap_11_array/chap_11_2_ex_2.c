#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	char invert[100];


	//���� �Է�
	printf("Enter a string: ");
	scanf_s("%s", str, sizeof(str));

	int i = 0;
	int length = 0;

	//array ���� ���� ���
	for (i = 0; str[i] != '\0'; i++)
	{
		length++;
	}

	printf("str= %s\n", str);

	i = 0;

	while (length > 0)
	{
		invert[i] = str[length - 1];
		
		length--;
		i++;
		
	}
	invert[i] = '\0'; // ���ڿ��� ���� ǥ��

	printf("invert= %s\n", invert);

	return 0;

}