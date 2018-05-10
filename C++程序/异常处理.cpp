#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-100;	// ���

double chu(double a, double b)
{
	if (fabs(b - 0) < EPS) throw b;
	return a / b;
}

int main()
{
	// tyr-catch �ṹ����Ƕ��
	try
	{
		cout << chu(10, 3) << endl;
		cout << chu(10, 0) << endl;		// ��������ֱ���˳� try
		cout << chu(10, 4) << endl;		// ����� try ����ִ��
		cout << chu(11, 0) << endl;
	}
	catch (int)
	{
		cout << "int ��������Ϊ 0" << endl;
	}
	catch (double)
	{
		cout << "double ��������Ϊ 0" << endl;
	}
	catch (...)		// ���������쳣��Ϣ
	{ cout << "����" << endl; }

	cout << "continue..." << endl;	// ����ִ�к������

	return 0;
}
