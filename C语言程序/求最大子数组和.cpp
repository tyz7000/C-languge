#include <stdio.h>
int main(void)
{
	int temp=0, b[9], i, max;
	int a[8];

	printf("�ҳ�������͵����ֵ\n������8������\n");
	for(i=0;i<=7;i++) scanf("%d",&a[i]);

	printf("ԭ����\t");
	for(i=0;i<=7;i++) printf("%4d",a[i]);
	putchar('\n');

	b[0]=a[0];        //�������к�
	for(i=1;i<=8;i++)
		b[i] = b[i-1] + a[i];
	

	for(i=1;i<=8;i++)    //�ҳ�����
		if (b[i-1]<b[i]) max=b[i];

	printf("������������� %d\n",max);

return 0;
}
/*
˼·����������������ͣ����浽b[9]��Ȼ���ҳ����ģ�
��֪�����Ӷ��ǲ���O(n^2)
*/