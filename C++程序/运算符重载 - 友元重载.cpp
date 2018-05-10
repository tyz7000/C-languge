#include <iostream.h>	// �� .h �Ĳ�֧����Ԫ����

// ����
class complex
{
public:
	complex(double x=0, double y=0)
		:real(x), imag(y) {}
	void show()
	{
		cout << real;
		if (imag < 0) cout << imag << "i" << endl;
		else cout << "+" << imag << "i" << endl;
	}
	// ���ⶨ�壬����Ԫ����
	friend complex operator + (complex &a, complex &b);
	friend complex operator - (complex &a, complex &b);   // ����
	friend complex operator - (complex &a);				// ����
	friend complex operator -- (complex &a);
	friend complex operator -- (complex &a, int);
private:
	double real;
	double imag;
};

complex operator + (complex &a, complex &b)
{
//  ��ͨ����
//	complex tmp;
//	tmp.real = a.real + b.real;
//	tmp.imag = a.imag + b.imag;
//	return tmp;

//  complex *p = new complex(1, 2);
//  ��Ч����, ����һ��������ʱ����
	return complex(a.real + b.real, a.imag + b.imag);
}

complex operator - (complex &a, complex &b)
{
	return complex(a.real - b.real, a.imag - b.imag);
}

// Ϊ��������д���ʽ�����Է���complex��������void
complex operator -- (complex &a)     // ǰ׺�� --c ����
{
	a.real = a.real - 1;
	a.imag = a.imag - 1;
	cout << "ǰ׺����--" << endl;
	return a;
}

// ��׺�� c--, ����Ҫ�Ӹ����õ� int ������
complex operator -- (complex &a, int)
{
	a.real = a.real - 1;
	a.imag = a.imag - 1;
	cout << "��׺����--" << endl;
	return a;
}

complex operator - (complex &a)
{
	a.imag = -a.imag;
	a.real = -a.real;
	return a;
}

int main(void)
{
	complex c1(1.2, 3.4);
	complex c2(3.4, -1.1);
	complex c3;

	cout << "c1 = ";   c1.show();
	cout << "c2 = ";   c2.show();
	cout << "c1 + c2 = ";
	c3 = c1 + c2;       c3.show();
	c3 = operator + (c1, c2);		// ��ʽ����
	cout << "c1 + c2 = ";  c3.show();

	cout << "c1 - c2 = ";
	c3 = c1 - c2;		c3.show();

	--c3;
	cout << "c3 = ";   c3.show();
	c3 = operator -- (c3);			// ��ʽ����
	cout << "c3 = ";   c3.show();

	c3--;
	cout << "c3 = ";   c3.show();
	c3 = operator -- (c3, 0);		// ��ʽ��׺����
	cout << "c3 = ";   c3.show();
	cout << endl;

	c3 = -c3;
	cout << "c3 = ";   c3.show();
	c3 = operator - (c3);
	cout << "c3 = ";   c3.show();

	complex a(2, 2);
	complex b(6, 6);
	complex c(-4, -4);
	complex sum;
	b--;
	sum = (-a) + b + c;   sum.show();

	return 0;
}
