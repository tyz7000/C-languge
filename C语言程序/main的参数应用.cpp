#include <stdio.h>
int main(int argc, char *argv[])
{
	int i; 
	for (i=0; i<argc; i++)
	{
		printf("���� %d��",i);
		printf(argv[i]);
		printf("\n");
	}
	printf("success! \n");

	return 0;
}
/*
��DOS�� ���� cpp1 ����1 ����2
����0�Ǳ�������ļ���
����ʵ�ֳ�������Ҹ���
*/