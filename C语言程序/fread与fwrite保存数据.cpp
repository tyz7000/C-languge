#include <stdio.h>
#include <string.h>
#define MAX 3

typedef struct st
{
	int num;
	int age;
	char name[10];
} STU;

void print(STU *ps)
{
	int i;

	for (i=0; i<MAX; i++)
	{
		printf("num = %d,  age = %d,  name = %s\n",
			ps->num, ps->age,  ps->name);
		ps++;
	}  //output
}

int main(void)
{
	int lenth = 0;
	FILE *in  = NULL;
	FILE *out = NULL;
	STU s[MAX];
	int i;

	memset(s, 0, MAX*sizeof(STU));
	
/*	//����ѧ����Ϣ
	for (i=0; i<MAX; i++)
	{
		s[i].age = i;
		s[i].num = i;
		sprintf(s[i].name, "���ӱ %d", i); 
	}

	//  ����ѧ���ɼ�����
	out = fopen("c:\\student.dat", "wb");
	if (out != NULL)
	{
		fwrite(s, sizeof(STU), MAX, out);
		fclose(out);
	}
*/
	//  ��ȡѧ���ɼ�����
	in = fopen("c:\\student.dat", "rb");
	if (in != NULL)
	{
		for (i=0; i<MAX; i++)
		{
		//	rewind(in);
		//	fseek(in, 0, SEEK_SET);
			fread(s+i, sizeof(STU), 1, in);
		}
		lenth = ftell(in);
		printf("lenth = %d Byte\n", lenth);
		fclose(in);
	}

	print(s);

	return 0;
}
/*
len = ftell(fp);
ftell() �ڲ�ָ�������ָ��Ĳ�ֵ���������ļ���ͷ�ľ��룬
���ǵ�ǰ����ʲô�ط��ˣ�

fseek(in, 0, SEEK_SET);
�൱��rewind(fp);
*/
