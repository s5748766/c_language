/*
name : SHIN HONGMIN
date : 2025-08-27
content : Data Structures and Algorithms Basics

Do not copy this code.
*/

//전처리─컴파일─링크─실행
//  └───디버깅────┘

//내가 정의하는 함수는 main함수보다 위에 있어야 한다.
//main 함수는 마지막에 실행된다.
//main 함수는 무조건 하나만 있어야 한다.


#define _CRT_SECURE_NO_WARNINGS //scanf 경고 무시
#define KEY_ESC 27 //ESC 키
#define KEY_UP (256 + 72) //Up arrow key //72:키보드 값, 256:확장키
#define KEY_DOWN (256 + 80) //Down arrow key
#define KEY_LEFT (256 + 75) //Left arrow key
#define KEY_RIGHT (256 + 77) //Right arrow key
#include <stdio.h> //표준 입출력 라이브러리(전처리기)
#include <stdlib.h> //표준 라이브러리(전처리기)
#include <time.h> //시간 라이브러리(전처리기)
#include <conio.h> //콘솔 입출력 라이브러리(전처리기)



//int sum(int a, int b) //int:정수형 return값이 있다는 뜻
//{
//	int c = a + b;
//	return c; //return값이 있는 함수는 return문이 반드시 있어야 한다.
//}
//
//void screen_letter(void) //void main(void)에서 void는 return값이 없다는 뜻
//{
//	printf("hello world\n"); //실행코드, Break point 확인
//}
////-----------------------------------------------------------------------------------//
//
//int main(void)
//{
//	screen_letter();
//	// printf("hello world\n"); //screen_letter 함수로 대체
//
////-----------------------------------------------------------------------------------//
//
//	int result = 0;
//	result = sum(3, 4); //함수 호출
//	printf("sum = %d\n", result);
//}
////-----------------------------------------------------------------------------------//
////#1주차 - 1단계 - 1
//
//int main(void)
//{
//	int a = 3;
//	double b = 4.5;
//	printf("%d + %f = %f \n", a, b, a + b); //%d:Int > 4byte, %f:Double > 8byte
//}
////-----------------------------------------------------------------------------------//
//int main(void)
//{
//	printf("Input int 1 num and double 1 num : \n");
//	scanf("%d %lf", &a, &b);
//	printf("%d + %f = %f \n", a, b, a + b);
//}
////-----------------------------------------------------------------------------------//
////#1주차 - 1단계 - 2
//int main(void)
//{
//	printf("안녕 C언어\n");
//	printf("이름 : \n");
//}
//
////-----------------------------------------------------------------------------------//
////#1주차 - 3단계 - 1 구구단
//int main(void)
//{
//	while (d < 10)
//	{
//		int a = 2;
//		int d = 0;
//		int e = 0;
//		printf("%d * %d = \n", a, d);
//
//
//	}
//}
//
////-----------------------------------------------------------------------------------//
////#1주차 - 3단계 - 2
//
//int main(void)
//{
//	int sum = 0;
//
//	printf("1~10 add num : \n");
//
//	sum = (1 + 10) * 5; //1~10 더하기 공식
//
//	printf("%d\n", sum);
//}
//
////-----------------------------------------------------------------------------------//
////#1주차 - 3단계 - 3
//
//int main(void)
//{
//	printf("\tMenu\n");
//	printf("┌─────────────────┐\n");
//	printf("│                 │\n");
//	printf("│  <1> 시  작     │\n");
//	printf("│  <2> 도움말     │\n");
//	printf("│  <3> 끝내기     │\n");
//	printf("│                 │\n");
//	printf("└─────────────────┘\n");
//}
//
////-----------------------------------------------------------------------------------//
////#1주차 - 4단계 - 1
////변수 선언
//int main(void)
//{
//	int num1 = 0;
//	int num2 = 0;
//	int op;
//	int len;
//
//	//입력
//	printf("input int 2 number : ");
//	scanf("%d %d", &num1, &num2);
//
//	//연산
//	len = (num2 - num1) / 2 + 1;
//	op = (num1 + num2) * len;
//
//	//출력
//	printf("operation result = %d", op);
//}
////-----------------------------------------------------------------------------------//
////#1주차 - 4단계 - 2
////변수 선언
//int main(void)
//{
//	int num1, num2, and, or , xor;
//
//	//입력
//	printf("Input 2 integer number : ");
//
//	//scanf 함수는 주소를 넣어줘야 한다.
//	scanf("%d %d", &num1, &num2);
//
//	//논리연산
//	and = num1 && num2;
//	or = num1 || num2;
//	xor = num1 ^ num2;
//
//	//출력
//	printf("operation result and = %d\n", and);
//	printf("operation result or  = %d\n", or );
//	printf("operation result xor = %d\n", xor);
//}
////-----------------------------------------------------------------------------------//
////2주차 - 1단계 - 1
////변수 선언
//int main(void)
//{
//	int num1 = 10, num2 = 0xA, num3 = 012;
//
//	//출력
//	printf("%d %o %x \n", num1, num1, num1);
//	printf("%d %o %x \n", num2, num2, num2);
//	printf("%d %o %x \n", num3, num3, num3);
//}
////-----------------------------------------------------------------------------------//
////2주차 - 1단계 - 2
////변수 선언
//int main(void)
//{
//	int num1 = 5, num2 = 6, bitand, bitor , bitxor, bitnot, bsl, bsr; //bsl:비트 왼쪽 시프트, bsr:비트 오른쪽 시프트
//
//	bitand = num1 & num2; //&:비트 논리곱
//	bitor = num1 | num2; //|:비트 논리합
//	bitxor = num1 ^ num2; //^:비트 배타적 논리합
//	bitnot = ~num1; //~:비트 부정
//	bsl = num1 << 2; //<<:비트 왼쪽 시프트
//	bsr = num1 >> 1; //>>:비트 오른쪽 시프트
//
//	//출력
//	printf("num1 &  num2 = %d\n", bitand);
//	printf("num1 |  num2 = %d\n", bitor );
//	printf("num1 ^  num2 = %d\n", bitxor);
//	printf("num1 ~       = %d\n", bitnot);
//	printf("num1 << num2 = %d\n", bsl);
//	printf("num1 >> num2 = %d\n", bsr);
//}
////-----------------------------------------------------------------------------------//
////2주차 - 1단계 - 3
//int main(void)
//{
//	int num1 = 15, num2 = num1 << 2, num3 = num2 >> 1; //bsl:비트 왼쪽 시프트, bsr:비트 오른쪽 시프트
//
//	//출력
//	printf("num1 = %d\n", num1);
//	printf("num2 = %d\n", num2);
//	printf("num3 = %d\n", num3);
//}
////-----------------------------------------------------------------------------------//
////3주차 - 1단계 - 1		while문, do~while문, for문
//int main(void)
//{
//	int num = 1;
//	int sum = 0;
//
//	while (num <= 1000)
//	{
//		sum += num;
//		num++;
//	}
//	printf("final sum = %d\n", sum);
//}
//
//int main(void)
//{
//	//do~while문
//	int sum = 0;
//	int num = 0;
//
//	do
//	{
//		num++;
//		sum += num;
//	} while (num < 1000);
//
//	printf("final sum = %d\n", sum);
//}
//
//int main(void)
//{
//	//for문
//	int sum = 0;
//
//	for (int num = 1; num <= 1000; num++)
//	{
//		sum += num;
//	}
//
//	printf("final sum = %d\n", sum);
//}
////-----------------------------------------------------------------------------------//
////3주차 - 1단계 - 2		if문, switch 문
//int main(void)
//{
//	//if문	
//	int num = 0;
//	printf("Input integer number : ");
//	scanf("%d", &num);
//	if (num > 0)
//	{
//		printf("positive number\n");
//	}
//	else
//	{
//		if (num == 0)
//		{
//			printf("0\n");
//		}
//		else
//		{
//			printf("negative number\n");
//		}
//	}
//}
//
//int main(void)
//{
//	//switch 문
//	int num = 0;
//	printf("Input integer number : ");
//	scanf("%d", &num);
//	switch (num)
//	{
//	case -1:
//		printf("negative number\n");
//		break;
//	case 0:
//		printf("0\n");
//		break;
//	case 1:
//		printf("positive number\n");
//		break;
//	default:
//		printf("unknown number\n");
//		break;
//	}
//}
//
////-----------------------------------------------------------------------------------//
////3주차 - 1단계 - 3		continue, break
//int main(void)
//{
//
//}
////-----------------------------------------------------------------------------------//
////3주차 - 3단계 - 1		2개의 정수 입력 후 구구단 출력
//
//int main(void)
//{
//	int num1 = 0, num2 = 0;
//	int count = 1;
//	int op = 0;
//
//	printf("Input 2 integer number : ");
//	scanf("%d %d", &num1, &num2);
//
//
//	if (1 < num1 < 10)
//	{
//		if (1 < num2 < 10)
//		{
//			if (num1 > num2)
//			{
//				while (num1 >= num2)
//				{
//					while (count < 10)
//					{
//						op = num2 * count;
//						printf("%d * %d = %d\n", num2, count, op);
//						count++;
//					}
//					count = 0;
//					num2++;
//				}
//			}
//			else if (num2 >= num1)
//			{
//				while (num1 <= num2)
//				{
//					while (count < 10)
//					{
//						op = num1 * count;
//						printf("%d * %d = %d\n", num1, count, op);
//						count++;
//					}
//					count = 0;
//					num1++;
//				}
//			}
//		}
//		return 0;
//	}
//	//-----------------------------------------------------------------------------------//	
//	return 0; //main 함수가 int형: return 0; 필수,  void형: return 0; 없어도 됨
//
//}
//  //-----------------------------------------------------------------------------------//
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
//
// //-----------------------------------------------------------------------------------//
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
// //-----------------------------------------------------------------------------------//
////아래 정수 3개 바이너리 파일 쓰기
//int main(void)
//{
//	int num[3] = { 100, 3, 15 };
//	FILE* fp = fopen("data.txt", "wb");
//	fwrite(num, sizeof(int), 3, fp);
//	printf("data.txt 파일에 정수 3개를 저장했습니다.\n");
//	fclose(fp);
//}
// //-----------------------------------------------------------------------------------//
//1~100까지 타이머 (1초마다 증가, p키 누르면 일시정지/재개)
//int main(void)
//{
//	clock_t initial_clock = clock(); //초기 clock 값 저장
//	int i = 1;
//	int go = 1;
//
//	system("cls"); //화면 지우기
//	printf("%d", i);
//
//	while (i < 100)
//	{
//		if (go == 1)
//		{
//			clock_t current_clock = clock(); //현재 clock 값 저장
//			if(current_clock - initial_clock >= 1000) //1000밀리초(1초)마다
//			{
//				i++;
//				system("cls"); //화면 지우기
//				printf("%d", i);
//				initial_clock = clock; //초기 clock 값 갱신
//			}
//		}
//		if (_kbhit()) //키보드 입력이 있으면
//		{
//			if(_getch() =='p')
//			{
//				go = (go + 1) % 2;//go가 1이면 0, 0이면 1 (0이면 멈춤, 1이면 진행)
//			}
//		}
//	}
//}
//-----------------------------------------------------------------------------------//
//방향키 입력 처리
int GetKey(void)
{
	int ch = _getch();

	if (ch == 0 || ch == 224) //특수키 처리
	{
		//방향키의 경우 0 또는 224의 값이 먼저 입력됨
		ch = 256 + _getch();
		//그 다음에 해당 방향키에 따라 72(), 75(left), 77(right), 80(down) 값이 입력됨
		return ch;
	}
}

int main(void)
{
	int ch;
	while ((ch = GetKey()) != KEY_ESC)
	{
		switch (ch)
		{
			case KEY_UP:
				printf("[UP]\n");
				break;
			case KEY_DOWN:
				printf("[DOWN]\n");
				break;
			case KEY_LEFT:
				printf("[LEFT]\n");
				break;
			case KEY_RIGHT:
				printf("[RIGHT]\n");
				break;
		}
	}
}
//-----------------------------------------------------------------------------------//