#include <stdio.h>
int main(void)
{
	int i, k, a[8]={1,2,3,4,5,6,7,8}, temp, flag, num;
	int *p1, *p2;

	printf("�������в��Һ�Ϊ����ֵ����������\n\n");
	printf("������8������\n");
	for(k=0; k<=7; k++) scanf("%d",&a[k]);

	printf("\n������һ����ֵ___");
	scanf("%d",&num);

	for(k=0; k<=7; k++)
	{
	flag = 1;
	for(i=0; i<7; i++)
	{
		if (a[i] > a[i+1])
		{
		temp = a[i];
		a[i] = a[i+1];
		a[i+1] = temp;
		flag = 0;         
		}
	}
	if (flag==1) break;
	}

	p1 = &a[0];
	p2 = &a[7];

	do {
		if (*p1 + *p2 < num) p1++;
		if (*p1 + *p2 > num) p2--;
	}
	while (*p1 + *p2 != num && *p1 < *p2);

	if (*p1 + *p2 == num)
		printf("\n%d + %d = %d\n\n",*p1, *p2, num);
	else printf("δ�ҵ�������������\n");

return 0;
}
/*
�ȴ�С������������ʼλ��һ��ָ��p1��ĩλ��һ��ָ��p2
����ָ�룬������У�ֱ���������ʺϵ�����
���Ӷȣ���֪����
*/