#include <stdio.h>

int main(void)
{
    int test[10],i,k,j,temp,flag;

	printf("ð�����򷨣���С����\n");
	printf("������ʮ������\n");

	for(i=0; i<10; i++)
	{
	printf("�� %d ��  ",i+1);
	scanf("%d",&test[i]);
	getchar();     //���ն���س���
	}

	for(k=0; k<=9; k++)
	{
	flag = 1;
	for(i=0; i<9; i++)
	{
		if (test[i] > test[i+1])
		{
		temp = test[i];
		test[i] = test[i+1];
		test[i+1] = temp;
		flag = 0;         //�鿴�Ƿ����˽���
		}
	}
	printf("�� %d ������Ľ��",k+1);
	for(j=0; j<10; j++) printf("%5d",test[j]);
	putchar('\n');
	if (flag==1) break;
	}

return 0;
}