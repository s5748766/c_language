#include <stdio.h>

void ShowData(const int* ptr) // int* ptr�� ��������ͷ� �����
{
	int* rptr = ptr; // rptr�� ptr�� ����Ű�� �ּҸ� ����Ű�� �Ϲ� ������ << ���� �߻�!
	printf("%d\n", *rptr); // rptr�� ����Ű�� �ּ��� ���� ���
	*rptr = 20; // rptr�� ����Ű�� �ּ��� ���� 20���� ����
}

int main(void)
{
	int  num = 10;
	int* ptr = &num;
	ShowData(ptr);
	return 0;
}