#include <stdio.h>
int main(void)
{
	int x, y, z;

	printf("��Ԫ�ټ�����\n");
	for (x=0; x<=100; x++)
	{
		for (y=0; y<=100; y++)
		{
			z = 100 - x - y;
			if (x + y + z == 100 
				&& 5*x + 3*y + (1.0/3.0)*z == 100.0)
			{
			printf("������ %d ֻ��ĸ���� %d ֻ��С���� %d ֻ",x,y,z);
			putchar('\n');
			}
		}
	}

return 0;
}