// ������ a1, a2, ... an
// ���� [1..n] �Ѿ��ź���
// �� n+1 �ŵ� [1..n]�е�ǡ��λ��

#include <stdio.h>

void show(int a[])
{
	int i;

	for (i=0; i<10; i++) 
		printf("%d, ", a[i]);
	printf("\n");
}

int main(void)
{
	int a[10] = {1,6,4,3,5,9,8,7,2,0};
	int i; 
	int j;
	int data;

	show(a);
	for (i=1; i<10; i++)
	{
		data = a[i];	// �������Ԫ��
		j = i-1;
		// [] [] [j] [data]
		while (j>=0 && data < a[j])	 // ����
		{
			a[j+1] = a[j];
			j--;
		}
// �˳�whileʱ��j==-1 �� data��С��a[j], ���Բ嵽a[j+1]��
		a[j+1] = data;
	}
	show(a);

	return 0;
}