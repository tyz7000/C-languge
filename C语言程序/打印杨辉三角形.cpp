#include <stdio.h>
int main(void)
{
	int tri[25][25] = {0};
	int i, j, n;

	printf("��������������εĴ�С");
	scanf("%d",&n);
	i = j = 0;
	for (i=0; i<n; i++)
	{
		j=0; 
		tri[i][j] = 1;   //��һ����Ϊ1
		printf("%5d", tri[i][j]);

		for (j=1; j<=i; j++)   //�ӵ�2�п�ʼ
		{
			tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
			printf("%5d", tri[i][j]); 
		}
		putchar('\n');
	}

return 0;
}