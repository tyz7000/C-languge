#include <iostream>
using namespace std;

class com
{
public:
	// com����,,��Ĭ�ϲ���Ҳ��ʵ�����Ч��
	com();
	com(float, float, int, float &);
	void input(float, float);
	void show();
private:
	float real;
	float imag;
	const int max;
	float &m;
};


class test
{
public:
	// Ĭ�ϲ����� 0�� ʵ�ֵ�ʱ����Բ���д
	test(int a=0, int b=0);
	void show(void);
private:
	int a;
	int b;
	
};


test::test(int x,int y)
{
	a = x; 
	b = y;
}

com::com():max(100), m(real)
{
	real = 0;
	imag = 0;
}

// ��Ա�б�ֵ
com::com(float a, float b, int t, float &tmp):max(t), m(tmp)
{
	real = a;
	imag = b;
}

void com::input(float a, float b)
{
	real = a;
	imag = b;
}

void com::show()
{
	cout << "max = " << max << endl;
	cout << real << endl;
	cout << imag << endl;
	cout << max << endl;
	cout << m << endl;
}

int main(void)
{	
	int x, y;
	float f = 0.3;
	com c(12, 13, 1000, f);
	com d;
	// ����Ĭ��ֵ
	test t1;
	test t2(10);
	test t3(10, 12);

//	cin >> x >> y;
//	c.input(x, y);
	c.show();

	return 0;
}
