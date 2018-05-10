#include <stdlib.h>
#include <stdio.h>

void quit(void)
{
	printf("error!\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	FILE *in;
	FILE *out;
	FILE *tryout;
	char c = 0;
	
	if (argc >= 2)  //����Ҫ����2�ſ��Խ��и���
	{
		in = fopen(argv[1], "r");
		if (in == NULL)
		{
			printf(argv[1]);
			printf(" �ļ�������\n");
			quit();
		}
		else 
		{
			tryout = fopen(argv[2], "r");
			if (tryout != NULL)
			{
				//Ŀ���ļ����ڣ�
				printf(argv[2]);
				printf("�ļ�����!���Ƿ񸲸� y/n? ");
				fflush(stdin);
				fclose(tryout);  //��ʱ�ر�
				c = getchar();
				if (!(c == 'Y' || c == 'y'))
				{
					exit(0);
				}
			}

			out = fopen(argv[2], "w");
			if (out != NULL)
			{
				//����ascll�ļ�
				while (1)
				{
					c = fgetc(in);
					if (c == EOF) break;
					fputc(c, out);
				}
				fclose(in);
				fclose(out);
				printf("���Ƴɹ���\n");
			}
			else quit();
		}
	}
	else quit();
	
	return 0;
}
/*
��DOS���������
����copy test.txt d:\out.txt
-----------------------------
�鿴ԭ�ļ��ڲ���
�鿴Ŀ���ļ���û������
�ſ�ʼ�����ļ�
*/