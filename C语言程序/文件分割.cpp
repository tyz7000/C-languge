#include <stdio.h>

// ���ָ���ļ� name.txt, �ʹ�С size
// ��һ��, дһ��, fread() ÿ��������Ĵ�С����
// �ֶ�ζ�ȡ, ֱ������ size ��С, ���¿�һ���ļ�
int create_file(char *name, int size)
{
	FILE *in;
	FILE *out;
	int s = 0;		// s = [0..size]
	int an = 0;
	int file_num = 1;	// ���ļ����
	char file_name[100];
	char buffer[1024];		// ��ʱ���ݻ�����(1KB)
	int inc;

	in = fopen(name, "rb");
	if (!in) return 0;

	sprintf(file_name, "%d_%s", file_num++, name);
	out = fopen(file_name, "wb");
	while (1)
	{
		an = fread(buffer, 1, 1024, in);
		if (an == 0) break;
		s += an;			// �ۼӱ���
		if (s > size)		// һ���ļ�����
		{
			s -= an;
			inc = size - s;
			fwrite(buffer, 1, inc, out);
			an -= inc;
			fclose(out);

			while (an > size)		// ������ж� 
			{
				sprintf(file_name, "%d_%s", file_num++, name);
				out = fopen(file_name, "wb");
				
				fwrite(buffer + inc, 1, size, out);
				fclose(out);
				an -= size;
				inc += size;
			}
			if (an > 0)
			{
				sprintf(file_name, "%d_%s", file_num++, name);
				out = fopen(file_name, "wb");

				fwrite(buffer + inc, 1, an, out);
				s = an;
			}
		}
		else fwrite(buffer, 1, an, out);
	}
	if (out) fclose(out);
	fclose(in);
	return 1;
}

int main(void)
{
	long int size;
	char name[100] = "input.txt";

	printf("������Ҫ�ָ��ļ���: ");
	scanf("%s", name);
	printf("������ÿ���ļ���Ĵ�С(Byte): ");
	scanf("%d", &size);
	if (create_file(name, size)) printf("\n�ָ����!\n");
	else printf("\n�ָ�ʧ��, �ļ����ܲ�����\n");

	return 0;
}
