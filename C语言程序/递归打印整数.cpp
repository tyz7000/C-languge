// �ݹ��ӡ����

#include <stdio.h>

// ������:
// n ֻ��һλ����ֱ�����
// n �ж�λ�������һλ
void show(int n)
{
	if (n >= 10) 
	{
		show(n / 10);
	}
	// ���ݵ�ʱ��ҲҪ�ѵ�ǰλ�����
	printf("%d", n % 10);
}

int main(void)
{
	show(123);
	printf("\n");

	return 0;
}