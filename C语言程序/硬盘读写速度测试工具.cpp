#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define SIZE 1024
#define PPATH "c:\\~test2.tmp"
#define WPATH "c:\\~test.tmp"

int main(void)
{
	FILE *out = NULL;
	FILE *in  = NULL;
	char buffer[SIZE];  // ��ȡ���ݻ�����
	int i;
	char c = 0;         // �û�����
	char buf = 'f';     // д�������
	int sn = 0;         // һ��д��KB
	int t1, t2, now, beg;  // ��ʱ����
	int first = 1;
	float ave, pos, tmp;  // ���ݱ���
	int an, an2;          // ����ʱ���
	
	system("color 0a");
	printf("\nӲ�̶�д�ٶȲ��Թ���\tBy caokun\n\n");
	printf("���»س�����ʼ����");
	scanf("%c", &c);
	printf("\n");
	if (c == '\n')
	{
		out = fopen(WPATH, "wb");
		if (out != NULL)
		{
			printf("------��ʼ����д���ٶ�...\n\n");
			an = 0;
			beg = t1 = clock();
			for (i=0; i<(200*(SIZE)); i++)
			{
				sn += fwrite(&buf, sizeof(char), SIZE, out);
				// ��ʼд��,,������ʱ��,��С�ļ���
				now = clock();
				if ((now-beg > 400) || first || i == (200*SIZE)-1)
				{
					first = 0;
					tmp = (float)(now - beg)/1000;
					if (tmp < 0.000001) tmp = (float)0.000001;
					ave = ((float)(sn-an)/(SIZE*SIZE)) / tmp;
					pos = (float)sn / (SIZE*SIZE*2);
					printf("��ǰд���ٶȣ�%.2f MB/s \t���Խ��ȣ�%.2f%%    \r", ave, pos);
					beg = clock();
					an = sn;
				}
			}
			fclose(out);
			t2 = clock();
			ave = (sn/(SIZE*SIZE)) / ( (float)(t2 - t1)/1000 );
			printf("\n\nƽ��д���ٶȣ�%.2f MB/s\t��ʱ��%.2f��\n", ave, (t2-t1)/1000.0);
			
			// ��ʼ������
			out = NULL;
			an2 = an = sn = 0;
			first = 1;

			printf("\n\n------��ʼ���Զ�ȡ�ٶ�...\n\n");
			out = fopen(WPATH, "rb");
			in = fopen(PPATH, "wb");
			if (out != NULL && in != NULL)
			{
				beg = t1 = clock();
				for (i=0; ; i++)
				{
					sn += (an = fread(buffer, sizeof(char), SIZE, out));
					if (an != 0)
					{
						fwrite(buffer, sizeof(char), an, in);
					}
					now = clock();
					if ((now-beg > 400) || first || i == (200*SIZE)-1)
					{
						first = 0;
						tmp = (float)(now - beg)/1000;
						if (tmp < 0.000001) tmp = (float)0.000001;
						ave = ((sn-an2)/(SIZE*SIZE)) / tmp;
						pos = (float)sn / (SIZE*SIZE*2);
						printf("��ǰ��ȡ�ٶȣ�%.2f MB/s \t���Խ��ȣ�%.2f%%    \r", ave, pos);
						beg = clock();
						an2 = sn;
					}
					if (an == 0) break;
				}
				fclose(in);
				fclose(out);
				t2 = clock();
				ave = (sn/(SIZE*SIZE)) / ( (float)(t2 - t1)/1000 );
				printf("\n\nƽ����ȡ�ٶȣ�%.2f MB/s\t��ʱ��%.2f��\n", ave, (t2-t1)/1000.0);
			}
		}
		else
		{
			printf("\n��ȡ���󣬳��򽫹رգ�\n");
		}
	}
	remove(PPATH);
	remove(WPATH);
	printf("\n\n�������!\n");
	getchar();
	return 0;
}
