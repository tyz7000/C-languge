#include <iostream>

using namespace std;

// char * &p ָ�������, �����޸�p�������޸�main�е�p
// �����Ǽ򵥵İ� p ��ֵ���ƹ���
// char &p = i;
void test(char * &p)
{
	p = new char('H');
}

int main(void)
{
	char *p;

	p = new char('k');
	cout << *p << endl;

	test(p);
	cout << *p << endl;

	delete p;

	return 0;
}