#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num;

int ran(void)    //����[5,35]�����
{
	int r;
	r = rand()%31+5;
	return r;
}

void cls(void)   //����
{
	system("cls");
}

void win(void)
{
	printf("\nʯ�ӱ�ȡ���ˣ���һ�ʤ��\n\n");
	num=0;
}

void lose(void)
{
	printf("\nʯ�ӱ�ȡ���ˣ����Ի�ʤ��\n\n");
	num=0;
}

int main(void)
{
	int b1=0, b2=1, player_num, comp_num;

	srand((unsigned)time(NULL));
	system("color 0a");
	num = ran();
	printf("\nʯ����Ϸ\n\n������ %d ��ʯ��",num);
	printf("\nÿ��ֻ��ȡ 1 �� 2 ��Ŷ��");

	while(num!=0) 
	{
	do
	{
		if (b2) {printf("\n\n����ҿ�ʼȡʯ��___");}
		if (b1) {cls(); printf("\n�������,ÿ��ֻ��ȡ 1 �� 2 ��Ŷ\n����������___");}
		scanf("%d",&player_num);
		getchar();          //���ջس���
		b1 = 1; 
		b2 = 0;
	}
	while ((player_num != 1) && (player_num != 2));
    
	b1 = 0;   //�رտ���
	b2 = 1;
	if (player_num < num)
	{
	num = num - player_num;
	printf("\n���ȡ�� %d ������ʣ %d ��\n",player_num, num);
	}
		else if (player_num = num)
		{
		win();
		}
			else
			{
			begin :printf("\nû����ô��ʯ����Ŷ������������___");
			scanf("%d",&player_num);
			if (player_num != 1) goto begin;
			win();
			};

	computer :comp_num = rand()%2+1;

	if (num == 2 || num == 1) 
	{
		printf("\n���Կ�ʼȡʯ��...\n����ȡ�� %d ��", comp_num);
		num = 0;
		lose();
	}
	if (comp_num < num) {
	printf("\n���Կ�ʼȡʯ��...\n����ȡ�� %d ��", comp_num);
	num = num - comp_num;
	printf(",���ڻ�ʣ %d ��",num);
						}
		else if (comp_num = num)
		{
		printf("\n���Կ�ʼȡʯ��...\n����ȡ�� %d ��", comp_num);
		num = 0;
		lose();
		}
		else goto computer;
	}


return 0;
}
