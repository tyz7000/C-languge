#include <iostream>
#include <fstream>
using namespace std;

// �������ļ������д
// �����ļ���С

int main()
{
	// д���ļ�
	ofstream out("c:\\123.dat", ios::binary | ios::out);
	if (!out) abort();
	double p[3] = {5,2,0};
	out.write((char *)p, 3 * sizeof(double));
	out.close();

	ifstream in("c:\\123.dat", ios::binary | ios::in);
	if (!in) abort();

	// �����ļ���С
	__int64 an;
	in.seekg(0, ios::end);		// 0 ��λ������ios::endȥ���ļ����
	an = in.tellg();
	cout << "�ļ���С: " << an  << " �ֽ�" << endl;

	// �����ȡһ��
	in.seekg(sizeof(double), ios::beg);	// seekg(�ƶ����ֽ��������λ��)
	double a;
	in.read((char *)&a, sizeof(double));	// д�� &a �����ַ��
	cout << a << endl;
	in.close();

	return 0;
}