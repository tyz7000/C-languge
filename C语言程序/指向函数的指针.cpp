#include <stdio.h>

int max(int a, int b)
{
	//  ��� b ��, ��ôfind�������Ĳ���
	if (a < b) return 1;
	else return 0;
}

//  ָ������ָ��   char (*p)(�βα�)
int find(int a[], int (*p)(int a, int b) ) 
{
	int j = *(a);
	int i;
	for(i=0; i<4; i++)
	{
		//  ʹ�ø�ָ��  (*p)(ʵ��ֵ)
		//  �൱��      max(ʵ��ֵ)
		if ((*p)( *(a+i), *(a+i+1) ))
		{
			// ��ô���� *(a+i+1) �� j
			j = *(a+i+1);
		}
	}
	return j;
}

int main(void)
{
	int (*f)(int a[], int (*p)(int a, int b)); 
	// ָ������ָ��
	int a[5] = {1,2,3,4,5};

	f = find;
	printf("max = %d\n", (*f)(a, max));
//�������ȼ��� 	printf("max = %d\n", find(a, max));

	return 0;
}
