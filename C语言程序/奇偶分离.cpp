#include <stdio.h>
int main(void)
{
	int a[10], i, k, j, k1=0, j1=9, temp;
	int *p1, *p2;

	printf("������ǰ��ż���ź�\n����10������");

	for (i=0;i<=9;i++) scanf("%d",&a[i]);

	printf("δ��ǰ\t");
	for(i=0;i<=9;i++) printf("%3d",a[i]);
	putchar('\n');

	do {
		for(k=k1;k<=4;k++)      //p1ָ���ǰ���
		{
		p1 = &a[k];
		if (*p1%2==0) {k1=k;break;}
		};

		for(j=j1;j>=5;j--)      //p2ָ��Ӻ���ǰ
		{
		p2 = &a[j];       
		if (*p2%2==1) {j1=j;break;}
		};
		if (j1==j && k1==k)     //����������ż��ͬ
		{
		temp = a[k];
		a[k] = a[j];
		a[j] = temp;
		}
	} while(k!=5 && j!=4);      //ֱ������ָ�붼�����м�

	printf("\n�ź�\t");
	for(i=0;i<=9;i++) printf("%4d",a[i]);

	putchar('\n');

return 0;
}
/*
һ��ָ��p1��ǰ��һ��p2�ں�
���м俿����������ż��ͬ�ͶԵ���
���Ӷ� O(n)
*/