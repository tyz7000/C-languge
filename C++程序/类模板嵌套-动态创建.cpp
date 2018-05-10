#include <iostream>
using namespace std;

// ��ģ���Ƕ��, ��̬����

template <typename type>
class math
{
public:
	math(type t=0);
	type max(type &a, type &b);
	void show()
	{ cout << "data = " << data << endl; }
private:
	type data;
};

// ���ⶨ�� max(), math()
template <typename type>
type math<type>::max(type &a, type &b)
{
	return a > b ? a : b;
}

template <typename type>
math<type>::math(type t)
{ data = t; }


template <typename type>
class test: public math<type>	// �̳���ģ��
{
public:
	test(type a, type b): math<type>(b)	// ���๹��ʱҲҪ math<type>
	{ data = a; }
	void show();
	math<type> obj1;		// ��ģ���Ƕ��
private:
	type data;
};

template <typename type>
void test<type>::show()
{
	cout << "data = " << data << endl;
}

int main()
{
	// ����ǰ���ʹ��һ����ֻ�����е� math ��� math<int> 
	// �� math<...> ���� math ����
	math<int> *p = new math<int> (55);
	p->show();
	delete p;

	test<char> t('c', 'k');
	t.show();				// c
	t.math<char>::show();	// k
	t.obj1.show();			// NULL
	// �����show�������show������������ʾ���� math<char>::show()

	test<double> t2(3.14, 1.23);
	t2.show();				  // c
	t2.math<double>::show();  // k
	t2.obj1.show();			  // NULL

	return 0;
}
