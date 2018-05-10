#include <iostream>
using namespace std;
// vc++6.0 ��Ҫ�� iostream.h

// �Զ��������
class node
{
public:
	node() 
	{ data = 0; }
	node(int r)
	{ data = r; }
	int data;
	int *next;
	friend ostream &operator << (ostream &out, node &p);
};

ostream &operator << (ostream &out, node &p)
{
	out << p.data;
	return out;
}


// ��ģ��
template <typename type>
class point
{
public:
	point()
	{ x = type(0);  y = type(0); }
	point(type a ,type b)
	{ x = a;   y = b; }
	void show()		// ���ڶ����Ա
	{
		cout << "(";
		cout << x << "," << y;
		cout << ")" << endl;
	}
private:
	type x;
	type y;
};

/* �����Ҫ���ⶨ�� point::show()
template <typename type>
void point<type>::show()
{
	// continue...
}*/

// ��ģ�岻�����أ����ǿ��Զ����������
// �������Ϳ��Բ�ȫ�����ϣ������������ typename type3
template <typename type1, typename type2>
class test
{
public:
	test();
	test(type1 a ,type2 b)
	{ x = a;   y = b; }
	void show();		// ���ⶨ���Ա
	type1 func(type1 a);
private:
	type1 x;
	type2 y;
};

// ���ⶨ���Ա��Ҫ����ģ������
template <typename t1, typename t2>
void test<t1, t2>::show()
{
	cout << "(";
	cout << x << "," << y;
	cout << ")" << endl;
}

// ����<��������...>::��Ա������(�����б�...)
template <typename type1, typename type2>
type1 test<type1, type2>::func(type1 a)
{
	cout << a << endl;
}

// ���ⶨ�幹�캯��
template <typename type1, typename type2>
test<type1, type2>::test()
{ x = type1(0);  y = type2(0); }


int main()
{
	// ������ point ����������������������int�������� 
	point<int>p1;
	point<int>p2(1, 2);
	p1.show();
	p2.show();

	point<double>p3(3.2, 5.6);
	p3.show();

	point<char>p4('c', 'k');
	p4.show();

	// ������Զ��������
	// Ҫ�Լ�д ����ת��������<< ���������
	point<node>n1(10, 13);
	n1.show();

	// ��������͵���ģ��
	test<float, char>p5(3.14f, 'w');
	p5.show();
	test<char*, int>p6("wujiaying", 3);
	p6.show();

	return 0;
}

