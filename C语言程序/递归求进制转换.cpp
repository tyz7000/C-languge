#include <stdio.h>

char buf[100] = {0};
char *p;

char *fun(int n, int r)
{
	if (n/r == 0)
	{
		sprintf(p++ ,"%c", n%r >= 10 ? (n%r-10+'A'):(n%r+'0'));
		// �����������ִ�У�Ҫ��ָ�������һλ��
	}
	else 
	{
		fun(n/r, r);
		sprintf(p++ ,"%c", n%r >= 10 ? (n%r-10+'A'):(n%r+'0'));
		// p++ ���⸲��ǰ�������
	}
	
	return buf;
}

int main(void)
{
	char *n;
	int a, b, i;

	while (scanf("%d%d", &a,&b) != EOF)
	{
		p = buf;
		n = fun(a, b);
		puts(n);
		for (i=0; i<100; i++) buf[i] = 0;
	}
	return 0;
}