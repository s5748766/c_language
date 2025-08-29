#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////아래 문자 텍스트 파일 쓰기
//int main(void)
//{
//	FILE* fp = fopen("text.txt", "w");
//	fprintf(fp, "Hello, World!\n");
//	fputc('C', fp);
//	fputc('\n', fp);
//	fputs("C Programming \n", fp);
//	fclose(fp);
//}


////1~5까지 텍스트 파일 읽기
//int main(void)
//{
//	int num;
//	FILE* fp = fopen("text2.txt", "r");
//	for (int i = 0; i < 5; i++)
//	{
//		fscanf(fp, "%d", &num);
//		printf("%d \n", num);
//	}
//	fclose(fp);
//}

int main(void)
{
	int num[3] = {100, 3, 15};
	FILE *fp = fopen("data.txt", "wb");
	fwrite(num, sizeof(int), 3, fp);
	printf("data.txt 파일에 정수 3개를 저장했습니다.\n");
	fclose(fp);
}