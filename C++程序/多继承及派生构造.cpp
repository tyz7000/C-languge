#include <iostream>
#include <string>

using namespace std;

class person
{
public:
	person(string n="NULL", int s=0);
	~person();
	string name;
	int sex;
	void show();
};

class grade
{
public:
	grade(int m=0, int e=0, int c=0);
	~grade();
	int ch;
	int math;
	int eng;
	void show();
};

class d
{
public:
	d(int y=0, int m=0, int d=0);
	~d();
	int year;
	int mouth;
	int day;
	void show();
};


class student: public person, public grade
{
public:
	student(string nu, 
		string n, int s, 
		int m, int e, int ch,
		int y, int mou, int da);
	string num;
	d date;
	void show();
};

// �û���������Ĺ��캯����ʼ����
student::student(string nu, 
		string n, int s, 
		int m, int e, int ch,
		int y, int mou, int da)
:person(n, s), grade(m, e, ch), date(y, mou, da)
{
	num = nu;
}

void student::show()
{
	cout << endl;
	cout << "ѧ�ţ�" << num << endl;
	person::show();		// ���࣬���� show ����������
	grade::show();		// ����Ҫ��::��˵�����ĸ���show
	date.show();
	cout << endl;
}

// -----person------
person::person(string n, int s)
{
	name = n;
	sex = s;
	cout << "person �ഴ��" << endl;
}

person::~person()
{
	cout << "person ���ͷ�" << endl;
}

void person::show()
{
	cout << "������" << name << endl;
	if (sex)
		cout << "�Ա���" << endl;
	else 
		cout << "�Ա�Ů" << endl;
}

// -----grade-----
grade::grade(int m, int e, int c)
{
	ch = c;
	math = m;
	eng = e;
	cout << "grade �ഴ��" << endl;
}

grade::~grade()
{
	cout << "grade ���ͷ�" << endl;
}

void grade::show()
{
	cout << "���ģ�" << ch << endl;
	cout << "��ѧ��" << math << endl;
	cout << "Ӣ�" << eng << endl;
}

// ------d--------
d::d(int a, int b, int c)
{
	year = a;
	mouth = b;
	day = c;
	cout << "���� date ����" << endl;
}

d::~d()
{
	cout << "���� date �ͷ�" << endl;
}

void d::show()
{
	cout << "���ڣ�";
	cout << year << "," << mouth << "," << day << endl;
}

int main(void)
{
	student s("11020204", "ӱ" ,0,98, 96,88,2012, 4 ,3);

	s.math = 59;
	s.show();
	s.date.show();
	s.grade::show();   // ˵������˭��show
	cout << endl;

	return 0;
}