#include <stdio.h>

float ave(int n)
{
	int num, i=1, sum=0;
	float a = 0.0f;

	while(n>=i)
	{
	printf("������� %d ����___",i);
	scanf("%d",&num);
	getchar();
	if (num>0)
	{
	sum += num;
	}
		else
		{ 
			printf("\n�������\n����������\n");	
			continue;
		}
		i++;
	}
	a = (float)sum/n;

	return a;
}

int main(void)
{
	int k=1;

	printf("����n������������ƽ��ֵ");
	be : printf("\n������Ҫ�󼸸����ĺͣ�__");
	scanf("%d",&k);
	if (k>0)
		printf("\nƽ��ֵ�ǣ�%.3f\n\n", ave(k));
	else 
	{
	printf("\n�������\n");
	goto be;
	}

return 0;
}