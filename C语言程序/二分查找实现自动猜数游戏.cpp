#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int ran, mid; 
	int count = 0;
	int left, right;

	printf("������Ϸ\n������1��100֮������\n");
	srand(time(NULL));
	ran = rand()%100+1;
	left = 0;
	right = 100;
	//���ķ�Χ��[0, 100]

	while(1)
	{
		mid = (left + right) / 2;
		count++;
		if (mid < ran)
		{
			printf("\n�Ҳ�  %d\nWrong!������С��\n",mid);
			left = mid + 1;
		}
		if (mid > ran)
		{
			printf("\n�Ҳ�  %d\nWrong!�����´���\n",mid);
			right = mid - 1;
		}
		if (mid == ran)
		{
			printf("\n�Ҳ�  %d\nRight!����ϲ�����¶���!\n\n", mid);
			break;
		}
		//sleep(1000);
	}
	printf("�ܹ����� %d ��\n\n",count);
	getchar();

return 0;
}
