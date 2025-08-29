#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];


	//문자 입력
	printf("Enter a string: ");
	scanf_s("%s", str, sizeof(str));

	int i = 0;
	int length = 0;

	//array 저장 개수 출력
	for(i=0; str[i] != '\0'; i++)
	{
		length++;
	}

	printf("string length = %d\n", length);
	
	return 0;

}