// ��������Ч��

#include <stdio.h>
#include <conio.h>
// conio.h �е� getch(); ��������ַ���

int main()
{
	char c = '\0';
	char hide = '*';		// �ַ�����
	char str[100] = {0};	// ���뻺����
	int cur = 0;			// ָʾ
	
	printf("���������룺");
	while(1)
	{
		c = getch();
		if (c == 13) break;
		else if (c == 8)	// �˸��
		{
			if (cur)
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				str[--cur] = '\0';
			}
		}
		else
		{
			putchar(hide);
			str[cur++] = c;
		}
	}
	printf("\n\n�������� %s\n\n", str);

	return 0;
}