/* --------------------
ѧ���ɼ�����ϵͳ
�������� WIN XP VC++6.0 �±���ͨ��
---------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ѧ����Ϣ�ṹ��
typedef struct
{
	char num[20];		// ѧ��
	char name[10];		// ����
	short int sex;		// �Ա�
	float chinese;		// ����
	float math;			// ��ѧ
	float english;		// Ӣ��
	float pe;			// ����
	float ave;			// ƽ���ɼ�
	float sum;			// �ܳɼ�
}student;


void display()	// ������ʾ����
{
	system("color 0e");		// ��仰�ǽ�����ɫ��
	printf("\n---------ѧ���ɼ�����ϵͳ\n\n");

	printf("--- 1. ����ѧ����Ϣ\n\n");
	printf("--- 2. ������ѧ����Ϣ\n\n");
	printf("--- 3. ���򲢲鿴\n\n");
	printf("--- 4. ����\n\n");
	printf("--- 5. ɾ��\n\n");
	printf("--- 6. ���\n\n");
	printf("--- ������ţ�ִ�в���\n");
	printf("--- ����exit���˳�����");
}

void back()		// ���������溯��
{
	fflush(stdin);
	printf("\n\n--- ���»س�������������");
	getchar();
	system("cls");		// ϵͳ��������
	display();
}

void num_sort(student s[], int *cur)	// ��ѧ������
{
	int i, j;
	int flag;
	student temp;

	for (i=0; i<*cur-1; i++)
	{
		flag = 1;
		for (j=0; j<*cur-1; j++)
		{
			if (strcmp(s[j].num, s[j+1].num) > 0)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 0;
			}
		}
		if (flag) break;
	}
}

void sum_sort(student s[], int *cur)	// ���ܳɼ�����
{
	int i, j;
	int flag;
	student temp;

	for (i=0; i<*cur-1; i++)
	{
		flag = 1;
		for (j=0; j<*cur-1; j++)
		{
			if (s[j].sum > s[j+1].sum)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 0;
			}
		}
		if (flag) break;
	}
}

int find_num(student s[], char *num, int cur)
{
	int i; 
	
	for (i=0; i<cur; i++)
		if (!strcmp(s[i].num, num))
			return i;
	return -1;
}

int find_name(student s[], char *name, int cur)
{
	int i; 
	
	for (i=0; i<cur; i++)
		if (!strcmp(s[i].name, name))
			return i;
	return -1;
}

void input_each(student s[], int i)	// ����ÿһ��ѧ��
{
		printf("\n������� %d ��ѧ����Ϣ\n\n", i+1);
		printf("ѧ��: ");
		gets(s[i].num);
		printf("����: ");
		gets(s[i].name);
		printf("�Ա�: (0 ��ʾ��, 1 ��ʾŮ)");
		scanf("%d", &s[i].sex);
		printf("���ĳɼ�: ");
		scanf("%f", &s[i].chinese);
		printf("��ѧ�ɼ�: ");
		scanf("%f", &s[i].math);
		printf("Ӣ��ɼ�: ");
		scanf("%f", &s[i].english);
		printf("�����ɼ�: ");
		scanf("%f", &s[i].pe);
		// �����ܳɼ�, ƽ���ɼ�
		s[i].sum = s[i].chinese + s[i].math + s[i].english + s[i].pe;
		s[i].ave = s[i].sum / 4.0;
}

void input(student s[], int *cur)		// ����10��
{
	int i;

	system("cls");
	for (i=0; i<10; i++)
	{
		printf("\n--- ���� 10 ��ѧ����Ϣ\n");
		fflush(stdin);
		input_each(s, i);
		(*cur)++;
		system("cls");
	}
	num_sort(s, cur);		// ��ѧ��������
	back();
}

void insert(student s[], int *cur)	// ����
{
	system("cls");
	input_each(s, *cur);
	(*cur)++;
	num_sort(s, cur);	// ����Ч�ʿ�����������
	back();
}


void print_each(student s[], int i)		// �������ѧ��
{
	printf("%s\t", s[i].num);
	printf("%s\t", s[i].name);
	printf("%s\t", s[i].sex == 1 ? "Ů" : "��");
	printf("%.1f\t", s[i].chinese);
	printf("%.1f\t", s[i].math);
	printf("%.1f\t", s[i].english);
	printf("%.1f\t", s[i].pe);
	printf("%.1f\t", s[i].ave);
	printf("%.1f\n", s[i].sum);
}

void find(student s[], int cur)		// ����
{
	int flag;
	char buf[20];
	int addr;

	system("cls");
	printf("\n--- ����ѧ����Ϣ\n");
	printf("\n--- 1. ��ѧ�Ų���\n");
	printf("\n--- 2. ����������\n");
	printf("\n--- 3. ��������\n");
	while (1)
	{
		printf("\n--- ������Ҫִ�еĲ���: ");
		fflush(stdin);
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("\n������ѧ��: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_num(s, buf, cur);
			if (addr == -1) printf("\n--- û���ҵ�!\n");
			else 
			{
				printf("\nѧ��\t����\t�Ա�\t����\t��ѧ\tӢ��\t����\tƽ����\t�ܳɼ�\n");
				print_each(s, addr);
			}
		}
		else if (flag == 2)
		{
			printf("\n����������: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_name(s, buf, cur);
			if (addr == -1) printf("\n--- û���ҵ�!\n");
			else 
			{
				printf("\nѧ��\t����\t�Ա�\t����\t��ѧ\tӢ��\t����\tƽ����\t�ܳɼ�\n");
				print_each(s, addr);
			}
		}
		else if (flag == 3) break;
		else printf("\nXXX �������");
	}
	back();
}

void del(student s[], int *cur)		// ɾ��
{
	int flag;
	int addr;
	int i;
	char buf[20];

	system("cls");
	printf("\n--- ɾ��ѧ����Ϣ\n");
	printf("\n--- 1. ��ѧ��ɾ��\n");
	printf("\n--- 2. ������ɾ��\n");
	printf("\n--- 3. ��������\n");
	while (1)
	{
		printf("\n--- ������Ҫִ�еĲ���: ");
		fflush(stdin);
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("\n������ѧ��: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_num(s, buf, *cur);
			if (addr == -1) printf("\n--- û���ҵ�!\n");
			else 
			{
				for (i=addr; i<*cur; i++)
					s[i] = s[i+1];
				(*cur)--;
				printf("\nɾ���ɹ�!\n");
			}
		}
		else if (flag == 2)
		{
			printf("\n����������: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_name(s, buf, *cur);
			if (addr == -1) printf("\n--- û���ҵ�!\n");
			else 
			{
				for (i=addr; i<*cur; i++)
					s[i] = s[i+1];
				(*cur)--;
				printf("\nɾ���ɹ�!\n");
			}
		}
		else if (flag == 3) break;
		else printf("\nXXX �������");
	}
	back();
}

void output(student s[], int *cur)	// ���
{
	int i;

	system("cls");
	printf("\n --- ȫ��ѧ����Ϣ:\n\n");
	printf("ѧ��\t����\t�Ա�\t����\t��ѧ\tӢ��\t����\tƽ����\t�ܳɼ�\n");
	for (i=0; i<*cur; i++)
		print_each(s, i);
	
	back();
}

void sort(student s[], int *cur)		// ����
{
	int flag;

	system("cls");
	printf("\n--- 1. ��ѧ������\n");
	printf("\n--- 2. ���ܳɼ�����\n");
	fflush(stdin);
	printf("\n--- ������Ҫִ�еĲ���: ");
	scanf("%d", &flag);
	if (flag == 1)
	{
		num_sort(s, cur);
		output(s, cur);
	}
	else if (flag == 2)
	{
		sum_sort(s, cur);
		output(s, cur);
	}
	else 
	{
		printf("\n --- �������! \n");
		back();
	}
}

int getnum(char str[])	// �����麯��
{
	int buf;
	char s[10] = "exit";

	if (str[0] >= '0' && str[0] <= '9')
	{
		sscanf(str, "%d", &buf);
		return buf;
	}
	else if (!strcmp(str, s)) return -2;
	else return -1;
}

void wait(student s[], int *cur)	// �ȴ��û���������
{
	char str[10];
	int op;
	
	while (1)
	{
		memset(str, 0, 10*sizeof(char));
		fflush(stdin);
		scanf("%8s", str);
		fflush(stdin);
		op = getnum(str);
		if (op>=1 && op<=6)
		{
			switch (op)
			{
			case 1 : input(s, cur);		break;	// ����
			case 2 : insert(s, cur);	break;	// ����
			case 3 : sort(s, cur);		break;	// ����
			case 4 : find(s, *cur);		break;	// ����
			case 5 : del(s, cur);		break;	// ɾ��
			case 6 : output(s, cur);	break;	// ���
			}
		}
		else if (op == -2) exit(0);
		else printf("XXX ����������������룺");
	}
}

int main(void)
{
	student s[30];	// �� 30 ��ѧ��
	int cur = 0;	// 0 ��ʹ����

	memset(s, 0, sizeof(s));	// ��ʼ��
	display();		// ��ʾ������
	wait(s, &cur);	// �ȴ��û�����

	return 0;
}

