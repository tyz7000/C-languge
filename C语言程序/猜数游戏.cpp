#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int ran, num, count = 0;

	printf("������Ϸ\n������1��100֮������__");
	srand(time(NULL));
	ran = rand()%100+1;

	while(1)
	{
		while(1)
		{
			count++;

			scanf("%d",&num);
			fflush(stdin);
			if ((num>=1) && (num<=100)) break;
			else printf("\n�������������������__");
		}
		if (count >= 11) 
		{
			printf("\n������10����δ���У�������Ϸ\n");
			break;
		}
		printf("\n�ܹ����� %d ��",count);
		if (num < ran) printf("\nWrong!������С��__");
		if (num > ran) printf("\nWrong!�����´���__");
		if (num == ran)
		{
			printf("\nRight!�����¶���!\n");
			break;
		}
	}
	getchar();

return 0;
}
