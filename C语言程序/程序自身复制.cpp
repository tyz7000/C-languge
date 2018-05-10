#include <stdio.h>
#define SIZE 1024

bool exist(char *filepath)  //�ļ����ڷ�
{
	FILE *test = NULL;
	
	test = fopen(filepath, "rb");
	if (test == NULL) return false;
	else 
	{
		fclose(test);
		return true;
	}
}

int main(int argc, char *argv[])
{
#define PATH argv[0]
	FILE *in = NULL;
	FILE *out = NULL;
	char buf[SIZE] = {0};
	int i, times = 0;
	int num;
	char outpath[100] = {0};
	
	if (argc > 0)
	{
		in = fopen(PATH, "rb");
		if (in != NULL)
		{
			for (i=0; i<200; i++)
			{
				sprintf(outpath, "cpp%d.exe", i);
				if ( exist(outpath) ) continue;
				else 
				{
					out = fopen(outpath, "wb");
					if (out != NULL)
					{
						while (1)
						{
							num = fread(buf, 1, SIZE, in);
							if (num == 0) break;
							fwrite(buf, 1, num, out);
						}
						fclose(out);
						rewind(in);  //inҪ������ȡ������Ҫ�������ָ��
						times++;
					}
				}
				if (times > 10) break;
			}
			fclose(in);
		}
	}
	return 0;
}