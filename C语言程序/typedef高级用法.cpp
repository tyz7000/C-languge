#include <stdio.h>

#define MAX 100

// string ��һ�������ͣ���char [MAX + 1]
// string s;  �൱��  char s[MAX + 1]
// �൱�ڰ� string �滻�� s
typedef char string[MAX + 1];

// ͬ������ָ�룬
// func p;
// �൱�ڰ� func �滻�� p
typedef int (*func)(int a, int b);


int main(void)
{
	int i;
	string s;
	func p;

	return 0;
}