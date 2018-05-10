#include <iostream.h>

class complex
{
public:
	complex()
	{ real = 0;  imag = 0; }
	complex(double r)
	{ real = r;   imag = 0; }
	complex(double a, double b)
	{ real = a;  imag = b; }
	friend ostream &operator << (ostream &out, complex &a);
	// ����ת�������������� תΪ ��������������
	operator double()   // ת double ��
	{
		return real;	// ����һ��double��
	}
	// ���ƿ��� operator int() { return int(real); }
private:
	double real;
	double imag;
};

ostream &operator << (ostream &out, complex &a)
{
	out << a.real;
	if (a.imag >= 0) out << "+";
	cout << a.imag << "i";
	return out;
}

int main()
{
	complex c1(4.2, 5);
	complex c2(2.3, 1);
	cout << c1 << endl;

	double d;
	d = c1;				// ��ʽת��
	cout << d << endl;
	d = double(c1);		// ��ʾת��
	cout << d << endl;

	int i;
	i = int(c1);   cout << i << endl;

	complex c3;
	c3 = c1 + c2;
	cout << c3 << endl;
	// ���� operator + (), �Ҳ���
	// �� c1 c2 ͨ�� operator double() תΪ double ��
	// ��ͨ�� complex(double) תΪ complex ���� c3

	return 0;
}
