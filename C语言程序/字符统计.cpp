#include <stdio.h>
int main(void)
{
	char str[60] = {0};
	int i, flag = 0, count = 0;
	
	printf("����ͳ��\n������һ���ַ�\n");
	gets(str);

	for (i=0; str[i]!=0; i++)
	{
		if (((str[i]>='a') && (str[i]<='z'))
			|| ((str[i]>='A') && (str[i]<='Z')))
		{
			if (flag == 0) count++;
			//flag=0˵��ǰһ��������ĸ�����������ˣ�
			flag = 1;
		}
		else flag = 0;
	}
	printf("\n������ %d\n",count);

return 0;
}