#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	char invert[100];


	//문자 입력
	printf("Enter a string: ");
	scanf_s("%s", str, sizeof(str));

	int i = 0;
	int length = 0;

	//array 저장 개수 출력
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
	invert[i] = '\0'; // 문자열의 끝을 표시

	printf("invert= %s\n", invert);

	return 0;

}