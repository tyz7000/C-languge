#include <iostream>
#include <iomanip>		// ������ͷ�ļ�

using namespace std;

// �Զ��� out ������
ostream &out(ostream &oc)
{
	oc << setw(20);
	oc << setiosflags(ios::right | ios::uppercase);
	oc << setfill('*') << dec;
	return oc;
}

// һ��Ҫ����һ������ &&&&&in
istream &in(istream &i)
{
	i >> hex;
	cout << "������һ��16������";
	return i;
}

int main()
{
	// ʹ�� ios ��Ա�������и�ʽ����
	cout.width(20);
	cout.setf(ios::right);
	cout << "wujiaying" << endl;
	cout.unsetf(ios::right);	// ȡ���Ҷ�������

	cout.width(30);		// �����޸Ŀ��
	cout.fill('*');		// ����
	cout.setf(ios::left);
	cout << "wujiaying" << endl;
	cout.unsetf(ios::left);

	cout.fill(' ');
	cout.width(50);
	cout.setf(ios::right);
	cout << "test" << endl;
	cout.unsetf(ios::right);

	// ������ʾ + ��
	cout.width(20);
	cout.setf(ios::showpos | ios::right);	// �ָ������ж������
	cout.precision(5);		// ��ʾ n ������
	double pi = 3.14159265358979;
	cout << pi << endl;
	cout.precision(0);
	cout.unsetf(ios::showpos | ios::right);


	// ʹ�ò��������и�ʽ����
	int t = 126;
	cout << setw(20) << dec << t << endl;
	cout << setiosflags(ios::uppercase) << hex << t << endl;
	cout << resetiosflags(ios::uppercase) << hex << t << endl;
	cout << out << t << endl;		// �Զ��� oc ��ʽ���������
	cin >> in >> t;					// �Զ��� in ��ʽ���������
	cout << "��Ӧ��10�����ǣ�" << t << endl;

	return 0;
}
