#include <stdio.h>
int main(void)
{
	int a, b, t;
	int r = 1;

	scanf("%d%d",&a, &b);
	if (a < b)
	{
		t = a; a = b; b = t;
	}
	while(r != 0)
	{	
		r = a%b;
		a = b;
		b = r;
	}
	printf("\n���Լ��Ϊ %d\n", a);

return 0;
}