#include <stdio.h>

typedef struct
{
	int h;
	int m;
	int s;
} time;

time fun(time k)
{
	k.h += 10;
	k.m += 10;
	k.s += 10;

	return k;
	// kֵ���غ�k�ͷ�
	// �˷�ռ�ÿռ�̫��
}

time *fun2(time *k)
{
	k->h += 10;
	k->m += 10;
	k->s += 10;

	return k;
	// ָ�뷨
}

int main(void)
{
	time t1, t2, t3;
	
	t1.h = 10;
	t1.m = 9;
	t1.s = 8;

	t2 = fun(t1);
	t3 = t2;

	fun2(&t3);

	printf("h = %d\nm = %d\ns = %d\n", t3.h, t3.m, t3.s);

	return 0;
}