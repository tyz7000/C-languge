#include <iostream>
using namespace std;

//    ���ϵͼ
//      area
//     /  |  \
//   yuan san ju


// area ������
class area
{
public:
	// ������ɶ� gongshi() ���¶���
	virtual float gongshi() = 0;	// ��ʽ
	virtual void showarea() = 0;	// ������
	virtual void test(int n) = 0;	// ����һ���в�����
};

// ԰
class yuan: public area
{
public:
	yuan(float a=0)
		:PI(3.14159f)
	{ r = a; }
	virtual float gongshi()
	{ return PI*r*r; }
	virtual void showarea()
	{
		cout << "Բ�����" << gongshi() << endl;
	}
	virtual void test(int n)
	{
		cout << n << "��Բ" << endl << endl;
	}
private:
	float r;
	const float PI;
};

// ������
class san: public area
{
public:
	san(float c=0, float d=0)
	{ a = c;  b = d; }
	virtual float gongshi()
	{ return 0.5*a*b; }
	virtual void showarea()
	{
		cout << "�����������" << gongshi() << endl;
	}
	virtual void test(int n)
	{
		cout << n << "��������" << endl << endl;

	}
private:
	float a;
	float b;
};

// ����
class ju: public area
{
public:
	ju(float c=0, float d=0)
	{ a = c;  b = d; }
	virtual float gongshi()
	{ return a*b; }
	virtual void showarea()
	{
		cout << "���������" << gongshi() << endl;
	}
	virtual void test(int n)
	{
		cout << n << "������" << endl << endl;
	}
private:
	float a;
	float b;
};

int main(void)
{
	area *p;
	yuan y(2);
	san  s(2.1f, 2.1f);
	ju   j(2.1f, 2.1f);

	p = &y;   p->showarea();  p->test(10);
	p = &s;   p->showarea();  p->test(20);
	p = &j;   p->showarea();  p->test(30);
	cout << p->gongshi() << endl;

	return 0;
}