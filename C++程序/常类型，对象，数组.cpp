#include <iostream>
using namespace std;

class student
{
public:
	student::student(int a=0, int b=0, int c=0);
	void input(int a, int b, int c);
	void show();
	void show(student &s) const;	// ������
	int updata;
	void test();
	void test2() const;
private:
	float ch;
	float eng;
	float math;
	const int num;
};

student::student(int a, int b, int c)
:ch(a), eng(b), math(c),
num(ch + eng + math)
{
	// �ȳ�ʼ������� ch... ����ʼ num;
	// ���߰���Ա�б��˳������ʼ
//	ch = a;
///	eng = b;
//	math = c;
}

void student::test2() const
{
	cout << "���ǳ�����" << endl;
//	test():		// ���������ܵ�����ͨ����
//	updata = 100;	// Ҳ���ܸ������ݳ�Ա
} 

void student::test()
{
	cout << "�������ܵ�����" << endl;
	test2();	// ��ͨ�������Ե��ó�����
}

void student::input(int a, int b, int c)
{
	ch = a;
	eng = b;
	math = c;
}

void student::show()
{
	cout << ch << ", " 
		 << eng << ", " 
		 << math << ", " 
		 << num << endl;
	cout << "show����ͨ����" << endl;
}

void student::show(student &s) const
{
	cout << ch << ", " 
		 << eng << ", " 
		 << math << ", " 
		 << num << endl;
	cout << "show�ĳ�����" << endl;
//	ch = 100; // �������ﲻ���޸����ݳ�Ա
	s.input(10,20,30);	// ���Ե��ñ�ĺ���
}

int main(void)
{
	student s(100,80,90);

	s.show();
	s.test2();	// ��ͨ��Ա���Ե��ó�����

	const student t(10,10,10);

	t.show(s);	// show�ǳ�����
	s.show();

// ����������ݲ��ܸ�, ��ͨ����Ҳ���ܵ���
//	t.test();	
//	t.input(10,10,10);
//	t.updata = 100;  

	student a[10] = {student(10,10,10), student(20,20,20)};

	a[1].show();

	return 0;
}