#include <stdio.h>

// �� x^n һ�㷽���ǽ��� n-1 �ε��Գ�, ���Ӷ�O(n)
// �����ø�Ч�ĵݹ��㷨, �ɽ����ӶȽ��� O(log n)
// ��ʽ: x��ż��: x^n = x^(n/2) * x^(n/2)
// x ������ x^n = x^((n-1)/2) * x^((n-1)/2) * x

int count;		// ��¼�˷�����

// ����ֻʵ�� double ��, �����������������������
double pow(int x, int n)
{
	count++;			// ������, ʵ�ʿ���ɾ��
	if (n == 0) return 1;		// x^0 == 1
	else if (n == 1) return x;	// x^1 == x
	else if (n % 2 == 0)		// ż��
		return pow(x * x, n / 2);
	else return pow(x * x, n / 2) * x;
}

int main(void)
{
	int x, n;

	count = 0;
	printf("�����������ָ��: ");
	scanf("%d %d", &x, &n);
	printf("���: %0.lf\n", pow(x, n));
	printf("ִ���� %d �γ˷�\n", count);

	return 0;
}