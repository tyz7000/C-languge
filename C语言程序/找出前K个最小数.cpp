#include <stdio.h>
int main(void)
{
	int i, k, a[8], flag, temp;

	printf("���ǰ3����С����\n������8������\n");
	for(i=0;i<=7;i++) scanf("%d",&a[i]);

	printf("ԭ����\t");
	for(i=0;i<=7;i++) printf("%4d",a[i]);
	putchar('\n');

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
	printf("��С��ǰ3������\t");
	for(i=0;i<=2;i++) printf("%4d",a[i]);
	putchar('\n');

return 0;
}
/*
�Ͽν����㷨�����ˣ�
������ð������Ȼ��ѡ��ǰ3����С�ģ�
���ӶȲ�֪���ǲ���O(nlog n)
*/