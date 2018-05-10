#include <iostream>
using namespace std;

class teacher;
class student;

class teacher
{
public:
	void input(int n);
	friend void show(teacher &m);
	// ��Ԫ����,�����ڶ�����ﶨ��
	int getstore(student &m);
private:
	int num;
	void test();
};

class student
{
public:
	student();
	void input(int n);
	friend void show(student &m);
	// ��Ԫ����
	friend int teacher::getstore(student &m);
	// ������������ʸ���ĳ�Ա
	friend teacher;
	// ��ʦ���е����к������ɷ���˽�г�Ա
private:
	int store;
};

student::student()
{
	store = 0;
}

int teacher::getstore(student &m)
{
	return m.store;	// ˽�е�����
}

void teacher::input(int n)
{
	num = n;
}

void student::input(int n)
{
	store = n;
}

void show(student &m)
{
	cout << m.store << endl;
	// ��Ԫ ���Է���˽�г�Ա
}

void show(teacher &m)	// show ����
{
	cout << m.num << endl;
	m.input(10);
	m.test();	// ��Ԫ�������Ե���˽�к���
}

void teacher::test()
{
	cout << "˽�к���" << endl;
}

int main(void)
{
	student s;
	s.input(100);

	teacher t;
	t.input(10);

	show(s);
	show(t);
	// ��Ԫ��������ͨ��������ʣ�
	// ֱ�ӵ��ü���
	
	cout << t.getstore(s) << endl;
	// ���� s ͬѧ�ķ���

	return 0;
}
