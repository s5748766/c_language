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
#include <stdio.h> //표준 입출력 라이브러리(전처리기)



int sum(int a, int b) //int:정수형 return값이 있다는 뜻
{
	int c = a + b;
	return c; //return값이 있는 함수는 return문이 반드시 있어야 한다.
}

void screen_letter(void) //void main(void)에서 void는 return값이 없다는 뜻
{
	printf("hello world\n"); //실행코드, Break point 확인
}
//-----------------------------------------------------------------------------------//

int main(void)
{
	screen_letter();
	// printf("hello world\n"); //screen_letter 함수로 대체

//-----------------------------------------------------------------------------------//

	int result = 0;
	result = sum(3, 4); //함수 호출
	printf("sum = %d\n", result);
}
//-----------------------------------------------------------------------------------//
//#1주차 - 1단계 - 1

int main(void)
{
	int a = 3;
	double b = 4.5;
	printf("%d + %f = %f \n", a, b, a + b); //%d:Int > 4byte, %f:Double > 8byte
}
//-----------------------------------------------------------------------------------//
int main(void)
{
	printf("Input int 1 num and double 1 num : \n");
	scanf("%d %lf", &a, &b);
	printf("%d + %f = %f \n", a, b, a + b);
}
//-----------------------------------------------------------------------------------//
//#1주차 - 1단계 - 2
int main(void)
{
	printf("안녕 C언어\n");
	printf("이름 : \n");
}

//-----------------------------------------------------------------------------------//
//#1주차 - 3단계 - 1 구구단
int main(void)
{
	while (d < 10)
	{
		int a = 2;
		int d = 0;
		int e = 0;
		printf("%d * %d = \n", a, d);


	}
}

//-----------------------------------------------------------------------------------//
//#1주차 - 3단계 - 2

int main(void)
{
	int sum = 0;

	printf("1~10 add num : \n");

	sum = (1 + 10) * 5; //1~10 더하기 공식

	printf("%d\n", sum);
}

//-----------------------------------------------------------------------------------//
//#1주차 - 3단계 - 3

int main(void)
{
	printf("\tMenu\n");
	printf("┌─────────────────┐\n");
	printf("│                 │\n");
	printf("│  <1> 시  작     │\n");
	printf("│  <2> 도움말     │\n");
	printf("│  <3> 끝내기     │\n");
	printf("│                 │\n");
	printf("└─────────────────┘\n");
}

//-----------------------------------------------------------------------------------//
//#1주차 - 4단계 - 1
//변수 선언
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int op;
	int len;

	//입력
	printf("input int 2 number : ");
	scanf("%d %d", &num1, &num2);

	//연산
	len = (num2 - num1) / 2 + 1;
	op = (num1 + num2) * len;

	//출력
	printf("operation result = %d", op);
}
//-----------------------------------------------------------------------------------//
//#1주차 - 4단계 - 2
//변수 선언
int main(void)
{
	int num1, num2, and, or , xor;

	//입력
	printf("Input 2 integer number : ");

	//scanf 함수는 주소를 넣어줘야 한다.
	scanf("%d %d", &num1, &num2);

	//논리연산
	and = num1 && num2;
	or = num1 || num2;
	xor = num1 ^ num2;

	//출력
	printf("operation result and = %d\n", and);
	printf("operation result or  = %d\n", or );
	printf("operation result xor = %d\n", xor);
}
//-----------------------------------------------------------------------------------//
//2주차 - 1단계 - 1
//변수 선언
int main(void)
{
	int num1 = 10, num2 = 0xA, num3 = 012;

	//출력
	printf("%d %o %x \n", num1, num1, num1);
	printf("%d %o %x \n", num2, num2, num2);
	printf("%d %o %x \n", num3, num3, num3);
}
//-----------------------------------------------------------------------------------//
//2주차 - 1단계 - 2
//변수 선언
int main(void)
{
	int num1 = 5, num2 = 6, bitand, bitor , bitxor, bitnot, bsl, bsr; //bsl:비트 왼쪽 시프트, bsr:비트 오른쪽 시프트

	bitand = num1 & num2; //&:비트 논리곱
	bitor = num1 | num2; //|:비트 논리합
	bitxor = num1 ^ num2; //^:비트 배타적 논리합
	bitnot = ~num1; //~:비트 부정
	bsl = num1 << 2; //<<:비트 왼쪽 시프트
	bsr = num1 >> 1; //>>:비트 오른쪽 시프트

	//출력
	printf("num1 &  num2 = %d\n", bitand);
	printf("num1 |  num2 = %d\n", bitor );
	printf("num1 ^  num2 = %d\n", bitxor);
	printf("num1 ~       = %d\n", bitnot);
	printf("num1 << num2 = %d\n", bsl);
	printf("num1 >> num2 = %d\n", bsr);
}
//-----------------------------------------------------------------------------------//
//2주차 - 1단계 - 3
int main(void)
{
	int num1 = 15, num2 = num1 << 2, num3 = num2 >> 1; //bsl:비트 왼쪽 시프트, bsr:비트 오른쪽 시프트

	//출력
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);
}
//-----------------------------------------------------------------------------------//
//3주차 - 1단계 - 1		while문, do~while문, for문
int main(void)
{
	int num = 1;
	int sum = 0;

	while (num <= 1000)
	{
		sum += num;
		num++;
	}
	printf("final sum = %d\n", sum);
}

int main(void)
{
	//do~while문
	int sum = 0;
	int num = 0;

	do
	{
		num++;
		sum += num;
	} while (num < 1000);

	printf("final sum = %d\n", sum);
}

int main(void)
{
	//for문
	int sum = 0;

	for (int num = 1; num <= 1000; num++)
	{
		sum += num;
	}

	printf("final sum = %d\n", sum);
}
//-----------------------------------------------------------------------------------//
//3주차 - 1단계 - 2		if문, switch 문
int main(void)
{
	//if문	
	int num = 0;
	printf("Input integer number : ");
	scanf("%d", &num);
	if (num > 0)
	{
		printf("positive number\n");
	}
	else
	{
		if (num == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("negative number\n");
		}
	}
}

int main(void)
{
	//switch 문
	int num = 0;
	printf("Input integer number : ");
	scanf("%d", &num);
	switch (num)
	{
	case -1:
		printf("negative number\n");
		break;
	case 0:
		printf("0\n");
		break;
	case 1:
		printf("positive number\n");
		break;
	default:
		printf("unknown number\n");
		break;
	}
}

//-----------------------------------------------------------------------------------//
//3주차 - 1단계 - 3		continue, break
int main(void)
{

}
//-----------------------------------------------------------------------------------//
//3주차 - 3단계 - 1		2개의 정수 입력 후 구구단 출력

int main(void)
{
	int num1 = 0, num2 = 0;
	int count = 1;
	int op = 0;

	printf("Input 2 integer number : ");
	scanf("%d %d", &num1, &num2);


	if (1 < num1 < 10)
	{
		if (1 < num2 < 10)
		{
			if (num1 > num2)
			{
				while (num1 >= num2)
				{
					while (count < 10)
					{
						op = num2 * count;
						printf("%d * %d = %d\n", num2, count, op);
						count++;
					}
					count = 0;
					num2++;
				}
			}
			else if (num2 >= num1)
			{
				while (num1 <= num2)
				{
					while (count < 10)
					{
						op = num1 * count;
						printf("%d * %d = %d\n", num1, count, op);
						count++;
					}
					count = 0;
					num1++;
				}
			}
		}
		return 0;
	}
	//-----------------------------------------------------------------------------------//	
	return 0; //main 함수가 int형: return 0; 필수,  void형: return 0; 없어도 됨

}
