#include <iostream>

using namespace std;

int main()
{
	cout << "wu" << endl;
	cerr << "caokun" << endl;	// ����������
	clog << "jiaying" << endl;	// ��������

	cout.put('a');		// �ȼ��� cout << 'a';
	cout.put('\n');
	
	char a;
	cin.get(a);
	cout << a << endl;

	char buf[100];
	cin >> buf;		// ������ո�ȵ�...
	cout << buf << endl;

	char buf2[20];
	cin.get(buf2, 5, 'q');	// ����ո�,�ȵ�
	cout << buf2 << endl;	

	cin.ignore(5, 'q');		// ���� 5 ���ַ�

	return 0;
}