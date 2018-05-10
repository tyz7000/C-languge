#include <iostream>
using namespace std;

class student;

class Tgrade
{
public:
	Tgrade::Tgrade(int a=0,int b=0,int c=0);
	Tgrade::~Tgrade();
	float chinese;
	float english;
	float math;
	friend student;
private:
	float sum;	// �����ܷ��ܲ��ܷ���
};

class student
{
public:
	student::student(int a=0,int b=0,int c=0);
	// student �ж� Tgrade ���г�ʼ��
	student::~student();
	void showgrade();
	char *name;
private:
	Tgrade grade;
	bool sex;
};

// ������grade����Ĺ��캯����Ҳ������grade.math = ...;
student::student(int a,int b,int c):grade(a, b, c)
{
	cout << "student constructor\n";
}

Tgrade::Tgrade(int a,int b,int c)
{
	cout << "grade constructor\n";
	chinese = a;
	english = b;
	math = c;
	sum = chinese + english + math;
}

void student::showgrade()	// studentҪ����Tgrade�е�˽��
{
	cout << grade.chinese << endl
		 << grade.english << endl
		 << grade.math << endl;
	cout << grade.sum << endl;
}

Tgrade::~Tgrade()
{
	cout << "Tgrade destory\n";
}

student::~student()
{
	cout << "student destory\n";
}

int main(void)
{
	student s(1,2,3);

	s.showgrade();

	return 0;
}