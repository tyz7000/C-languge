#include <stdio.h>

int n;

void print(int n, char style, char flag)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		if (style == 'c') 
		{
		printf("\n");
		if (flag == 'r') 
		{
			for (j=0; j<n+1; j++)
			  printf(" ");		  
		}
		printf("*");
		}
		if (style == 'r') printf("*");
	}
}

int main(void)
{
	printf("�������С:");
	scanf("%d",&n);

	print(n, 'r','l');
	print(n-2, 'c','l');
	putchar('\n');
	print(n, 'r','l');
	print(n-2, 'c','r');
	putchar('\n');
	print(n, 'r','l');
	putchar('\n');

	return 0;
}

/*
print(int n, char style, char flag)

n ��ʾ��д�ĳ��ȣ�
style ��ʾ r(raw)����д�� c(colnmn)����д��
flag ��ʾд�����l(left) �����ұ�r(right)
*/