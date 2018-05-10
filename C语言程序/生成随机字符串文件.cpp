#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �ڵ�ǰĿ¼���� num �����ʵ��ļ�
int create_str(char *name, int num)
{
	const int max = 60;
	int len;		// �������
	int i, j;
	FILE *out;
	char buf[max+2];

	out = fopen(name, "wt");
	if (!out) return 0;

	srand(time(NULL));
	for (i=0; i<num; i++)
	{
		len = rand() % max + 1;		// ������� <= 60
		for (j=0; j<len; j++)
			buf[j] = rand() % 26 + 'a';
		buf[len] = '\0';
		fputs(buf, out);
		fputc('\n', out);
	}
	getchar();
	getchar();
	fclose(out);
	return 1;
}

int main(void)
{
	int num;

	printf("�����뵥������: ");
	scanf("%d", &num);
	create_str("input.txt", num);

	return 0;
}