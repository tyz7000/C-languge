#include <iostream>
using namespace std;

// ���û���ָ�붯̬�����������
// �ͷ�ʱ������û�б��ͷ�
// �����������������������Խ��������
// һ�����

class base
{
public:
	base()
	{ cout << "base ����" << endl; }
	virtual ~base()
	{ cout << "base �ͷ�" << endl; }
private:
	// to be continue...
};

class son: public base
{
public:
	son()
	{ cout << "son ����" << endl; }
	virtual ~son()
	{ cout << "son �ͷ�" << endl; }
private:
	// to be continue...
};

int main(void)
{
//	son *p;  // ������ָ������
//	p = new son;
//	delete p; 

	// �û���ָ�룬new����������󣬽�����
	base *q = new son;
	delete q;    // ����û�б��ͷţ����������������ɽ��

	return 0;
}
