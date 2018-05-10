#include <iostream>
#include <fstream>
using namespace std;

// -------fstream ��֧������-------

int main()
{
	ofstream out;

	// ios::out ���, ios::app ׷�ӷ�ʽ
	out.open("C:\\123.txt", ios::out | ios::app);
	if (out)
	{
		char *s = "test";
		int i = 100;

		out << "caokun" << endl;
		out << s << endl;
		out << i << endl;
		out.close();
	}

	// �����ʱ�����ֱ�Ӵ�
	// ��ָ��λ�ã�Ĭ����ͬһ��Ŀ¼��
	ofstream out2("456.txt", ios::out);
	if (out2)
	{
		out2 << "123456" << endl;
		out2.close();
	}
	else cout << "open error!" << endl;


	// �ļ���ȡ��
	ifstream in;
	in.open("c:\\789.txt", ios::in);
	if (in)
	{
		char str[100];

		// ��ȡ�����ļ�
		while (1)
		{
			in >> str;
			if (!in) break;		// in Ϊ 0 �Ͷ�ȡ����
			cout << str << endl;
		}
		in.close();
	}
	else cout << "open error!" << endl;


	// ��ȡд��ϲ�
	fstream io("c:\\123.txt", ios::in | ios::out);
	if (io)
	{
		char str[100];
		// ��ȡ
		while (1)
		{
			io >> str;
			if (!io) break;
			cout << str << endl;
		}
	}
	else cout << "open error!" << endl;

	return 0;
}
