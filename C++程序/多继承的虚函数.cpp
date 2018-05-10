#include <iostream>
using namespace std;

class base1
{
public:
	virtual void show()		// �麯��show
	{ cout << "base1" << endl; }
};

class base2
{
public:
	void show()		// ��ͨ����show
	{ cout << "base2" << endl; }
};

class son: public base1, public base2
{
public:
	virtual void show()
	{ cout << "son" << endl; }
};

int main(void)
{
	base1 *p1;
	base2 *p2;
	son s;

	p1 = &s;   p1->show();   // �麯����̬����
	p2 = &s;   p2->show();   // �����show�����Σ�ָ������show

	return 0;
}