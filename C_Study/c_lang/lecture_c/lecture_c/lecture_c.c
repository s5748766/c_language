/*
name : SHIN HONGMIN
date : 2025-08-27
content : Data Structures and Algorithms Basics

Do not copy this code.
*/

//��ó���������Ϧ���ũ������
//  ������������릡��������

//���� �����ϴ� �Լ��� main�Լ����� ���� �־�� �Ѵ�.
//main �Լ��� �������� ����ȴ�.
//main �Լ��� ������ �ϳ��� �־�� �Ѵ�.


#define _CRT_SECURE_NO_WARNINGS //scanf ��� ����
#include <stdio.h> //ǥ�� ����� ���̺귯��(��ó����)



int sum(int a, int b) //int:������ return���� �ִٴ� ��
{
	int c = a + b;
	return c; //return���� �ִ� �Լ��� return���� �ݵ�� �־�� �Ѵ�.
}

void screen_letter(void) //void main(void)���� void�� return���� ���ٴ� ��
{
	printf("hello world\n"); //�����ڵ�, Break point Ȯ��
}
//-----------------------------------------------------------------------------------//

int main(void)
{
	screen_letter();
	// printf("hello world\n"); //screen_letter �Լ��� ��ü

//-----------------------------------------------------------------------------------//

	int result = 0;
	result = sum(3, 4); //�Լ� ȣ��
	printf("sum = %d\n", result);
}
//-----------------------------------------------------------------------------------//
//#1���� - 1�ܰ� - 1

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
//#1���� - 1�ܰ� - 2
int main(void)
{
	printf("�ȳ� C���\n");
	printf("�̸� : \n");
}

//-----------------------------------------------------------------------------------//
//#1���� - 3�ܰ� - 1 ������
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
//#1���� - 3�ܰ� - 2

int main(void)
{
	int sum = 0;

	printf("1~10 add num : \n");

	sum = (1 + 10) * 5; //1~10 ���ϱ� ����

	printf("%d\n", sum);
}

//-----------------------------------------------------------------------------------//
//#1���� - 3�ܰ� - 3

int main(void)
{
	printf("\tMenu\n");
	printf("��������������������������������������\n");
	printf("��                 ��\n");
	printf("��  <1> ��  ��     ��\n");
	printf("��  <2> ����     ��\n");
	printf("��  <3> ������     ��\n");
	printf("��                 ��\n");
	printf("��������������������������������������\n");
}

//-----------------------------------------------------------------------------------//
//#1���� - 4�ܰ� - 1
//���� ����
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int op;
	int len;

	//�Է�
	printf("input int 2 number : ");
	scanf("%d %d", &num1, &num2);

	//����
	len = (num2 - num1) / 2 + 1;
	op = (num1 + num2) * len;

	//���
	printf("operation result = %d", op);
}
//-----------------------------------------------------------------------------------//
//#1���� - 4�ܰ� - 2
//���� ����
int main(void)
{
	int num1, num2, and, or , xor;

	//�Է�
	printf("Input 2 integer number : ");

	//scanf �Լ��� �ּҸ� �־���� �Ѵ�.
	scanf("%d %d", &num1, &num2);

	//������
	and = num1 && num2;
	or = num1 || num2;
	xor = num1 ^ num2;

	//���
	printf("operation result and = %d\n", and);
	printf("operation result or  = %d\n", or );
	printf("operation result xor = %d\n", xor);
}
//-----------------------------------------------------------------------------------//
//2���� - 1�ܰ� - 1
//���� ����
int main(void)
{
	int num1 = 10, num2 = 0xA, num3 = 012;

	//���
	printf("%d %o %x \n", num1, num1, num1);
	printf("%d %o %x \n", num2, num2, num2);
	printf("%d %o %x \n", num3, num3, num3);
}
//-----------------------------------------------------------------------------------//
//2���� - 1�ܰ� - 2
//���� ����
int main(void)
{
	int num1 = 5, num2 = 6, bitand, bitor , bitxor, bitnot, bsl, bsr; //bsl:��Ʈ ���� ����Ʈ, bsr:��Ʈ ������ ����Ʈ

	bitand = num1 & num2; //&:��Ʈ ����
	bitor = num1 | num2; //|:��Ʈ ����
	bitxor = num1 ^ num2; //^:��Ʈ ��Ÿ�� ����
	bitnot = ~num1; //~:��Ʈ ����
	bsl = num1 << 2; //<<:��Ʈ ���� ����Ʈ
	bsr = num1 >> 1; //>>:��Ʈ ������ ����Ʈ

	//���
	printf("num1 &  num2 = %d\n", bitand);
	printf("num1 |  num2 = %d\n", bitor );
	printf("num1 ^  num2 = %d\n", bitxor);
	printf("num1 ~       = %d\n", bitnot);
	printf("num1 << num2 = %d\n", bsl);
	printf("num1 >> num2 = %d\n", bsr);
}
//-----------------------------------------------------------------------------------//
//2���� - 1�ܰ� - 3
int main(void)
{
	int num1 = 15, num2 = num1 << 2, num3 = num2 >> 1; //bsl:��Ʈ ���� ����Ʈ, bsr:��Ʈ ������ ����Ʈ

	//���
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);
}
//-----------------------------------------------------------------------------------//
//3���� - 1�ܰ� - 1		while��, do~while��, for��
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
	//do~while��
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
	//for��
	int sum = 0;

	for (int num = 1; num <= 1000; num++)
	{
		sum += num;
	}

	printf("final sum = %d\n", sum);
}
//-----------------------------------------------------------------------------------//
//3���� - 1�ܰ� - 2		if��, switch ��
int main(void)
{
	//if��	
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
	//switch ��
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
//3���� - 1�ܰ� - 3		continue, break
int main(void)
{

}
//-----------------------------------------------------------------------------------//
//3���� - 3�ܰ� - 1		2���� ���� �Է� �� ������ ���

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
	return 0; //main �Լ��� int��: return 0; �ʼ�,  void��: return 0; ��� ��

}
