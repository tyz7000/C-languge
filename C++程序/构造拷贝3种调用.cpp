// ��ָ��ʵ��
#include <iostream>
using namespace std;

class test
{
public:
	test(const test &m);
	test(int a=0, int b=0);
	~test();
	void input(int, int);
	void show();
private:
	int x;
	int y;
};

void test::show()
{
	cout << x << endl;
	cout << y << endl;
}

void test::input(int a, int b)
{
	x = a;
	y = b;
}

test::~test()
{
	cout << "����������.." << endl;
}

test::test(int a, int b)
{
	x = a;
	y = b;
	cout << "��������ͨ����.." << endl;
}

test::test(const test &m)
{
	x = m.x;	// ˽�г�Ա�ڿ�����������Է���
	y = m.y;
	cout << "�����˿�������.." << endl;
}

void fun(test p)
{
	cout << "���뵽fun����..." << endl;
}

test fun2(void)
{
	test k(100, 100);
	return k;
}

int main(void)
{
	test t;
	t.show();

	test t2(1,1);
	t2.show();

	// ��ֵ����
	test t3(t2);
	t3.show();

	// ʵ��ʱ����
	cout << "׼������fun����..." << endl;
	fun(t3);

	// ����ʱ����
	test d;
	cout << "׼��ִ��fun2..." << endl;
	d = fun2();
	cout << "�˳���fun2..." << endl;

	return 0;
}