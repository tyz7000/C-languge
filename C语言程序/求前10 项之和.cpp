#include <stdio.h>

int main(void)
{
	int i=1, a=0, b=1;
	float an, sn=0.0f;
		
	printf("��2/1��3/2��5/3��8/5����ǰ10 ��֮��\n");
	while(i<=10)
	{
	a = a+b;
	b = b+a;
	an = (float)b/a;
	sn += an; 
	printf("ǰ %d ���Ϊ %f\n",i,sn);
	i++;
	}

return 0;
}