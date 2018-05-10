#include <iostream>
using namespace std;

//   �̳й�ϵͼ
//
//     first
//       |
//      base    base2   base
//      /  \    /       /
// father  mother    other
//      \  /          /
//     child ---------

class first
{
public:
	first::first()
	{ cout << "first ����" << endl; }
	first::~first()
	{ cout << "first ����" << endl; }
};

class base: public first
{
public:
	// ��������, ����ʹ��Ĭ�ϲ�����
	// �� father �п��Բ�д base() �Ĺ���
	base::base(int n)
	{
		cout << "base ���� ";
		data = n;
		cout << " data = " << data << endl;
	}
	base::~base()
	{ cout << "base ����" << endl; }
protected:
	int data;
};

class base2
{
public:
	base2::base2(int n)
	{ cout << "base2 ����" << endl; }
	base2::~base2()
	{ cout << "base2 ����" << endl; }
};

// ʹ�� virtual ��ʾ���������� virtual ������
// ���๫��һ���ռ䣬Ҳ���� mother �и��� data = 100
// father ��Ҳ���ˣ�
// ȥ�� virtual �ɿ�����

class father: protected virtual base
{
public:
	father::father(int n): base(n+10) // ������Զ�����๹�죬����base(n+10)
	{ cout << "father ����" << endl; }
	father::~father()
	{ cout << "father ����" << endl; }
	void set_data()
	{
		data = 10;
	}
};

// base2 ��������࣬���Թ�������� base������ base2
// ��ʹ base2 ��ǰ������Ҳ�ȹ��� base
class mother: public base2, virtual protected base
{
public:
	mother::mother(int n): base2(100), base(n+100)
	{ cout << "mother ����" << endl; }
	mother::~mother()
	{ cout << "mother ����" << endl; }
	void set_data()
	{
		data = 100;
	}
};

class other: public base
{
public:
	other::other(int n): base(n)
	{ cout << "other ����" << endl; }
	other::~other()
	{ cout << "other ����" << endl; }
};

class child: protected father, protected mother, protected other
{
public:
	// base(1) �����ֻ������Զ����������
	child::child(): base(1), father(10), mother(100), other(123)
	{ cout << "child ����" << endl; }
	child::~child()
	{ cout << "child ����" << endl; }
	void show_data()
	{
		father::set_data();
		mother::set_data();
		cout << "father.data = " << father::data << endl;
		cout << "father.data = " << mother::data << endl;
		cout << "other.data = " << other::data << endl;
	}
};

int main(void)
{
	child c;
	cout << endl;

	c.show_data();

	cout << endl;
	return 0;
}

