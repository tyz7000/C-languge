#include <stdio.h>
int main(void)
{
	int an=0,sn=0,i=0;

	printf("��1+3+5+7+��+555 �ĺ�\n\n");
	while(an < 555)
	{
	an = 2*i+1;
	sn += an;
	i++;
	}
	printf("1+3+5+7+��+555 �ĺ�Ϊ %d\n\n",sn);

	return 0;
}