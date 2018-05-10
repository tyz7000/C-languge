#include <stdio.h>
#define BUF 1024
int main(void)
{
	FILE *in  = NULL;
	FILE *out = NULL;
	char buf[BUF] = {0};  //��������Ҳ���Զ�̬����
	int size = 0;
	int num = 0;  // �ɹ���ȡ���ֽ���

	in = fopen("c:\\cpp1.exe", "rb");
	out = fopen("c:\\cpp2.exe", "wb");
	if (in != NULL && out != NULL)
	{
		fseek(in, 0, SEEK_END);  //�����ָ���Ƶ��ļ�β��
		size = ftell(in);        //���ߵ�ǰλ�ã����ļ���С
		rewind(in);              //�����ָ���Ƶ��ļ���

		while (1)
		{
			num = fread(buf, 1, BUF, in);
			if (num == 0) break;
			fwrite(buf, 1, num, out);
		}

		fclose(in);
		fclose(out);
	}

	return 0;
}
/*
	num = fread(buf, 1, BUF, in);
	// num Ϊ�ɹ��� BUF (1024) �гɹ���ȡ�����ֽ���
	// 1 Ϊÿ�ζ�ȡ 1�ֽڣ�����BUF��

	fwrite(buf, 1, num, out);
	// ����ȡ�����ֽ�д�룬�ɹ���ȡ��num�ֽڣ�
	// ÿ��ֻд��һ���ֽ�

	�� in �������Ƶ� buffer ��������
	��������С BUF = 1024 �ֽ�
	�ٰѻ����������ݸ��Ƶ� out ��
*/
