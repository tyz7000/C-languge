#include "student.h"
#include <iostream>
#include <string>

using namespace std;

// student ʵ�ֲ���

// ȫ��
string allmajor[10][6] = 
{
	"��������ѧ����","�������","����ý��","���繤��"," "," ",
	"�������","���̹���","�г�Ӫ��","��������","�� �� ѧ","���ʾ�����ó��",
	"��ѧרҵ","���⺺��"," "," "," "," ",
	"Ӣ��רҵ","����רҵ"," "," "," "," ",
	"��е���̼��Զ���","��ͨ����","��������","��е���ӹ���","�����붯��"," ",
	"΢ �� ��","�����Ϣ",
	"��ؼ���","�� �� ��","��Ϣ����"," ",
	"ͳ �� ѧ","��ѧ����","Ӧ����ѧ"," "," "," ",
	"�� �� ѧ","�������"," "," "," "," ",
	"��ҵ���","�������","��װ����빤��"," "," "," ",
	"��ѧ����","���Ϲ���","��������","���﹤��","Ӧ�û�ѧ","��ȫ����",
};

void student::show()
{
	cout << "ѧ�ţ�" << num << endl;
	cout << "������" << name << endl;
	cout << "�Ա�";
	print_sex(sex);
	cout << endl << "�꼶��";
	print_grade(grade);
	cout << endl << "ѧԺ��";
	print_xueyuan(xueyuan);
	cout << endl << "רҵ��";
	print_major(xueyuan, major);
	print_class(clas);
	cout << endl;
}

void student::print_xueyuan(short int n)
{
	switch (n)
	{
	case 0 : cout << "�����ѧԺ";		break;
	case 1 : cout << "�� ѧ Ժ";		break;
	case 2 : cout << "�ķ�ѧԺ";		break;
	case 3 : cout << "�����ѧԺ";		break;
	case 4 : cout << "����ѧԺ";		break;
	case 5 : cout << "��ϢѧԺ";		break;
	case 6 : cout << "����ѧԺ";		break;
	case 7 : cout << "����ѧԺ";		break;
	case 8 : cout << "���������ѧԺ";	break;
	case 9 : cout << "���������ѧԺ";	break;
	}
}

void student::print_grade(short int n)
{
	switch (n)
	{	
	case 1 : cout << "һ�꼶";	break;
	case 2 : cout << "���꼶";	break;
	case 3 : cout << "���꼶";	break;
	case 4 : cout << "���꼶";	break;
	}
}

void student::print_class(short int n)
{
	switch (n)
	{
	case 1 : cout << " 1 ��";	break;
	case 2 : cout << " 2 ��";	break;
	case 3 : cout << " 3 ��";	break;
	case 4 : cout << " 4 ��";	break;
	case 5 : cout << " 5 ��";	break;
	case 6 : cout << " 6 ��";	break;
	case 7 : cout << " 7 ��";	break;
	case 8 : cout << " 8 ��";	break;
	case 9 : cout << " 9 ��";	break;
	}
}

void student::print_sex(short int n)
{
	if (n == 0) cout << "��";
	else if (n == 1) cout << "Ů";
}

void student::print_major(short int x, short int n)
{
	cout << allmajor[x][n-1];
}
