#include <stdio.h>

void ShowData(const int* ptr) // int* ptr이 상수포인터로 변경됨
{
	int* rptr = ptr; // rptr은 ptr이 가리키는 주소를 가리키는 일반 포인터 << 에러 발생!
	printf("%d\n", *rptr); // rptr이 가리키는 주소의 값을 출력
	*rptr = 20; // rptr이 가리키는 주소의 값을 20으로 변경
}

int main(void)
{
	int  num = 10;
	int* ptr = &num;
	ShowData(ptr);
	return 0;
}