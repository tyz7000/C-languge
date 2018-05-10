#include <iostream>
#include <string>
#include <stdlib.h>
#include "student.h"

using namespace std;

// ui ��ʵ�ֲ���

ui::ui()
{
	file f;
	FILE *fp = NULL;
	char buf[200];
	int i = 0;

	file::writetext("����ʼ����...");
	// ��ʼ����Ա
	addr = NULL;
	cur = 0;

	// �����ļ��� filename
	filename = "stu_data.dat";
	dir = f.getdir() + "\\";
	stu_path = dir + filename;
	strtochar(stu_path, buf);

	// ����ѧ�������ļ�
	file::writetext("���Լ��������ļ� stu_data.dat");
	if (f.fileexist(stu_path))
	{
		// ���������ļ�
		// ����ļ���С
		fp = fopen(buf, "rb");
		if (!fp) goto NEXT;
		fseek(fp, 0, SEEK_END);
		int size = ftell(fp);
		int each = sizeof(student);
		rewind(fp);
		
		if (size)
		{
			// �������ݿռ�
			cur = size / each;
			addr = (student *)malloc((cur+1) * sizeof(student));
			if (!addr) exit(0);
			
			// ��ʼ��ȡ�� addr
			fread(addr, each, cur, fp);
			fclose(fp);
			fp = NULL;
		}
		file::writetext("���سɹ���");
	}
	else 
	{
NEXT:
		// ������,�������ļ�
		fp = fopen(buf, "wb");
		fseek(fp, 0, SEEK_END);
		if (fp) fclose(fp);
		fp = NULL;
		file::writetext("����ʧ�ܣ������� stu_path.dat");
	}

	// ����Ƥ����ɫ
	file::writetext("�� color.ini �м���Ƥ����ɫ");
	FILE *set = NULL;
	set_path = dir + "set.ini";
	strtochar(set_path, buf);
	if (f.fileexist(set_path))
	{
		// ��ȡ��ɫ����
		char buffer[MAXPATH] = {0};		// ������

		set = fopen(buf, "rb");
		if (!set) goto NO;
		int an = 1;
		while (an)
			an = fread(buffer, 1, 99, set);
		fclose(set);
		set = NULL;
		setcolor( findnum(buffer) );
		file::writetext("���سɹ���");
	}
	else 
	{
NO:		// ʹ��Ĭ����ɫ
		setcolor(-1);

		// INI�ļ���¼
		fp = fopen(buf, "wt");
		if (fp) 
		{
			fprintf(fp, "[info]\ncolor=4\n");
			fclose(fp);
			fp = NULL;
		}
		file::writetext("����ʧ�ܣ�ʹ��Ĭ����ɫ");
	}
}

ui::~ui()
{
	// ������д�ظ�����
	write_student_data(addr, stu_path);
	file::writetext("���������ļ�");

	// �ͷŸ��ٻ����е����ݿռ�
	if (addr) free(addr);
	addr = NULL;
	file::writetext("���������");
}

bool ui::write_student_data(student *addr, string &path)
{
	file f;
	char buf[MAXPATH] = {0};
	FILE *out = NULL;
	
	// �ȸĳ�stu_data.dat1
	string path1 = path + "1";
	f.newname(path, path1);

	// д�� stu_data.dat
	strtochar(path, buf);
	out = fopen(buf, "wb");
	if (out)
	{
		int s = sizeof(student);
		for (int i=0; i<cur; i++)
		{
			if (addr[i].used)
				fwrite(&(addr[i]), 1, s, out);
		}
		fclose(out);
	}
	else
	{
		// д��ʧ���ٸĻ���
		f.newname(path1, path);
		return false;
	}
	// ɾ����ʱ studata.dat1
	f.deletefile(path1);
	return true;
}

// ������ɫ
void ui::setcolor(int num)
{
	switch (num)
	{
	case green : system("color 0A");
		break;
	case blue : system("color 0B");
		break;
	case red : system("color 0C");
		break;
	case purple : system("color 0D");
		break;
	case yellow : system("color 0E");
		break;
	case white : system("color 0F");
		break;
	default : system("color 0E");
	}
}

int ui::findnum(char *s)
{
	int i;
	int res;

	for (i=0; s[i]!='\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			sscanf(s+i, "%d", &res);
			return res;
		}
	}
	return -1;
}

// string ת char
void ui::strtochar(string &s, char *buf)
{
	int i = 0;

	if (!buf) return ;
	while (s[i] != '\0')
		buf[i++] = s[i];
	buf[i] = '\0';
}

void ui::print(int n)
{
	if (n>0)
	{
		for (int i=0; i<n; i++)
			cout << "-";
	}
}

void ui::clear()
{
	system("cls");
}

void ui::back()
{
	fflush(stdin);
	cout << endl << endl;
	print(3);
	cout << " ���»س�������������" << endl;
	getchar();
	clear();
	display();
}

void ui::display()
{
	cout << endl;
	print(25);
	cout << "ѧ����Ϣ����ϵͳ";
	print(25);
	cout << endl << endl;

	print(3);
	cout << " 1, ����ѧ����Ϣ";
	cout << "     2, �޸�ѧ����Ϣ";
	cout << "     3, ɾ��ѧ����Ϣ";
	cout << endl << endl;
	print(3);
	cout << " 4, ��ѯѧ����Ϣ";
	cout << "     5, �鿴����ѧ����Ϣ";
	cout << endl << endl;

	print(3);
	cout << " 6, ϵͳ����";
	cout << "         7, ���� / ����ѧ�������ļ�";
	cout << endl << endl << endl;

	print(3);
	cout << " 0. ���沢�˳�" << endl << endl;
	print(3);
	cout << " ��ѡ��Ҫִ�еĲ�����";
}

int ui::getnum(string &str)
{
	if (str.length() == 1 
		&& str[0] >= '0' 
		&& str[0] <= '9')
	{
		return str[0] - '0';
	}
	else 
		return -1;
}

int ui::wait()
{
	string str;
	int op;
	
	file::writetext("�ȴ��û�����...");
	while (1)
	{
		cin >> str;
		fflush(stdin);
		op = getnum(str);
		if (op>=0 && op<=7)
		{
			switch (op)
			{
			case 1 : exe_create();	break;
			case 2 : exe_update();	break;
			case 3 : exe_remove();	break;
			case 4 : exe_find();	break;
			case 5 : exe_show();	break;
			case 6 : exe_set();		break;
			case 7 : exe_backup();	break;
			case 0 : return 0;
			}
		}
		else printf("XXX ����������������룺");
	}
}

int ui::check(int a, int b)
{
	while (1)
	{
		string buf;
		cin >> buf;
		if (buf.length() == 1) 
			if (buf[0]-'0' >= a && buf[0]-'0' <= b)
			{
				fflush(stdin);
				return buf[0] - '0';
			}
		cout << "XXX ����������������룺";
	}
}

void ui::allmajor(short int n)
{
	switch (n)
	{
	case 0 : 
		cout << "1. ��������ѧ����   2. �������   3. ����ý��   4. ���繤��";
		cout << endl;
		break;
	case 1 : 
		cout << "1. �������   2. ���̹���   3. �г�Ӫ��   4. ��������";
		cout << endl;
		cout << "5. ���ѧ     6. ���ʾ�����ó��" << endl;
		break;
	case 2 : 
		cout << "1. ��ѧרҵ   2. ���⺺��" << endl;
		break;
	case 3 : 
		cout << "1. Ӣ��רҵ   2. ����רҵ" << endl;
		break;
	case 4 : 
		cout << "1. ��е���̼��Զ���   2. ��ͨ����   3. ��������" << endl;
		cout << "4. ��е���ӹ���       5. �����붯��" << endl;
		break;
	case 5 : 
		cout << "1. ���ӿ�ѧ����(΢���ӷ���)   2. ���ӿ�ѧ����(�����Ϣ����)";
		cout << endl;
		cout << "3. ��ؼ���     4. �Զ���     5. ��Ϣ����" << endl;
		break;			 
	case 6 : 
		cout << "1. ͳ��ѧ   2. ��ѧ����   3. Ӧ����ѧ" << endl;
		break;
	case 7 : 
		cout << "1. ���ѧ   2. �������" << endl;
		break;
	case 8 : 
		cout << "1. ��ҵ���   2. �������   3. ��װ����빤��" << endl;
		break;
	case 9 : 
		cout << "1. ��ѧ����   2. ���Ϲ���   3. ��������" << endl;
		cout << "4. ���﹤��   5. Ӧ�û�ѧ   6. ��ȫ����" << endl;
		break;
	}
}

// ���רҵ
void ui::show_major(short int n, int &a, int &b)
{
	a = 1;
	switch (n)
	{
	case 0 : 
		allmajor(0);  b = 4;  break;
	case 1 : 
		allmajor(1);  b = 6;  break;
	case 2 : 
		allmajor(2);  b = 2;  break;
	case 3 : 
		allmajor(3);  b = 2;  break;
	case 4 : 
		allmajor(4);  b = 5;  break;
	case 5 : 
		allmajor(5);  b = 5;  break;			 
	case 6 : 
		allmajor(6);  b = 3;  break;
	case 7 : 
		allmajor(7);  b = 2;  break;
	case 8 : 
		allmajor(8);  b = 3;  break;
	case 9 : 
		allmajor(9);  b = 6;  break;
	}
	fflush(stdin);
}

// ��ʾȫ��ѧԺ
void ui::showxueyuan()
{
	cout << "0. �����ѧԺ   1. ��ѧԺ     2. �ķ�ѧԺ   3. �����ѧԺ" << endl;
	cout << "4. ����ѧԺ     5. ��ϢѧԺ   6. ����ѧԺ   7. ����ѧԺ" << endl;
	cout << "8. ���������ѧԺ             9. ���������ѧԺ" << endl << endl;
}

string ui::checkname()
{
	string tmp;

	while (1)
	{
		cin >> tmp;
		int len = tmp.length();
		if (len < 10)
		{
			if (len >= 4)
			{
				int error = 0;
				for (int i=0; i<len; i++)
				{
					// ֻ����Ӣ�ĺͺ���
					if (tmp[i] < 0) continue;
					if (!((tmp[i] >= 'a' && tmp[i] <= 'z') 
						|| (tmp[i] >= 'A' && tmp[i] <= 'Z')))
					{
						error = 1;
						break;
					}
				}
				if (error) cout << "XXX �����к��зǷ��ַ�";
				else break;
			}
			else cout << "XXX ����: ���ֹ���";
		}
		else cout << "XXX ����: ���ֹ���";
		cout << "�����������룺";
	}
	return tmp;
}

string ui::checknum()
{
	string tmp;

	while (1)
	{
		cin >> tmp;
		int len = tmp.length();
		if (len == 12)
		{		
			int error = 0;
			for (int i=0; i<len; i++)
			{
				// ֻ��������
				if (!(tmp[i] >= '0' && tmp[i] <= '9'))
				{
					error = 1;
					break;
				}
			}
			if (error) cout << "XXX ѧ���к��зǷ��ַ�";
			else
			{
				// �����ͬѧ��
				error = 0;
				for (i=0; i<cur; i++)
				{
					char buf[15] = {0};
					strtochar(tmp, buf);
					if (strcmp(buf, addr[i].num) == 0)
					{
						error = 1;
						break;
					}
				}
				if (error) cout << "XXX ��ѧ����ʹ��";
				else break;
			}
		}
		else cout << "XXX ѧ��λ������(12λ)";
		cout << "�����������룺";
	}
	return tmp;
}

void ui::exe_create()	// ����
{
	student *n;

	clear();
	// ����ռ�������, һ�������һЩ
	// ����̫С���ͷŵ�ʱ����ָ�����ִ���
	if (addr)
	{
		n = (student *)realloc(addr, 
			(cur+2) * sizeof(student));
		if (!n) exit(0);
		addr[cur].used = false;
		addr[cur+1].used = false;
		cur++;
		addr = n;
	}
	else 
	{
		addr = (student *)malloc(sizeof(student));
		if (!addr) exit(0);
		cur = 1;
	}
	file::writetext("����ѧ����Ϣ");
	cout << endl;
	print(3);
	cout << " ����ѧ������:" << endl << endl;
	cout << "������ѧ��������";
	string tmp;
	tmp = checkname();
	strtochar(tmp, addr[cur-1].name);
	
	cout << endl;
	cout << "������ѧ�ţ�";
	fflush(stdin);
	string tmp2;
	tmp2 = checknum();
	strtochar(tmp2, addr[cur-1].num);

	cout << endl;
	cout << "0. ��    1. Ů" << endl << endl;
	print(3);
	cout << " �������Ա�";
	addr[cur-1].sex = check(0, 1);

	cout << endl;
	showxueyuan();
	print(3);
	cout << " ������ѧԺ���ţ�";
	addr[cur-1].xueyuan = check(0, 9);

	cout << endl;
	int a, b;
	show_major(addr[cur-1].xueyuan, a, b);
	cout << endl << "������רҵ���ţ�";
	addr[cur-1].major = check(a, b);

	cout << endl;
	print(3);
	cout << " �������꼶(1 �� 4)��";
	addr[cur-1].grade = check(1, 4);

	cout << endl;
	print(3);
	cout << " ������༶����(1 �� 9)��";
	addr[cur-1].clas = check(1, 9);

	addr[cur-1].used = true;	// ɾ�����
	cout << endl << "����ɹ���";
	back();
}

int ui::find(student *addr, char *s)
{
	int pos = -1;

	for (int i=0; i<cur; i++)
	{
		if (!strcmp(s, addr[i].num))
		{
			pos = i;
			break;
		}
	}
	return pos;
}

void ui::exe_update()	// �޸�
{
	clear();
	file::writetext("�޸�ѧ����Ϣ");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "û��ѧ�����ݣ��޷��޸�" << endl;
	else
	{
		cout << " �޸�ѧ������:" << endl << endl;
		print(3);
		cout << " �������������� 0 " << endl << endl;
		print(3);
		cout << " ��������޸�ѧ��ѧ�ţ�";
		char s[20];
INPUT:
		cin >> s;
		if (s[0] == '0' && s[1] == '\0') goto BACK;
		int pos = find(addr, s);
		if (pos == -1) 
		{
			cout << endl << "�Ҳ�����ѧ�������������룺";
			goto INPUT;
		}
		else
		{
			cout << endl;
			addr[pos].show();
			cout << endl;
			cout << "1. ����   2. �Ա�   3. �꼶   4. �༶";
			cout << endl << "5. ѧԺ   6. רҵ   7. ȫ���޸�";
			cout << endl << endl;;
			print(3);
			cout << " ����Ҫ�޸ģ�";
			int op;
			string str;
			string tmp;
			while (1)
			{
				cin >> str;
				fflush(stdin);
				op = getnum(str);
				if (op>=1 && op <= 7)
				{
					switch (op)
					{
					case 7 : 
					case 1 : 
						cout << endl;
						print(3);
						cout << " ��������������";
						tmp = checkname();
						strtochar(tmp, addr[pos].name);
						fflush(stdin);
						if (op != 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					case 2 :
						cout << endl;
						cout << "0. ��    1. Ů" << endl << endl;
						print(3);
						cout << " ���������Ա�";
						addr[pos].sex = check(0, 1);
						if (op != 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					case 3:
						cout << endl;
						print(3);
						cout << " �������꼶(1 �� 4)��";
						addr[pos].grade = check(1, 4);
						if (op != 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					case 4:
						cout << endl;
						print(3);
						cout << " ������༶����(1 �� 9)��";
						addr[pos].clas = check(1, 9);
						if (op != 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					case 5:
						cout << endl;
						showxueyuan();
						print(3);
						cout << " ������ѧԺ���ţ�";
						addr[pos].xueyuan = check(0, 9);
						if (op != 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					case 6:
						cout << endl;
						int a, b;
						show_major(addr[pos].xueyuan, a, b);
						cout << endl << "������רҵ���ţ�";
						addr[pos].major = check(a, b);
						if (op != 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					default : 
						if (op == 7)
						{
							cout << endl << "�޸ĳɹ���" << endl;
							goto BACK;
						}
					}
				}
				else cout << "XXX ����������������룺";
			}
			file::writetext("�޸ĳɹ���");
		}
	}
BACK:
	back();
}

void ui::exe_remove()	// ɾ��
{
	clear();
	file::writetext("ɾ��ѧ����Ϣ");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "û��ѧ�����ݣ��޷�ɾ��" << endl;
	else
	{
		cout << " ɾ��ѧ������:" << endl << endl;
		print(3);
		cout << " �������������� 0 " << endl << endl;
		print(3);
		cout << " �������ɾ��ѧ��ѧ�ţ�";
		char s[20];
DEL_INPUT:
		cin >> s;
		if (s[0] == '0' && s[1] == '\0') goto DEL_BACK;
		int pos = find(addr, s);
		if (pos == -1) 
		{
			cout << endl << "�Ҳ�����ѧ�������������룺";
			goto DEL_INPUT;
		}
		else 
		{
			addr[pos].used = false;
			cout << endl <<"ɾ���ɹ���" << endl;
		}
	}
DEL_BACK:
	back();
}

void ui::exe_find()		// ��ѯ
{
	clear();
	file::writetext("��ѯѧ����Ϣ");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "û�и�ѧ�ţ��޷���ѯ" << endl;
	else
	{
		cout << " ��ѯѧ������:" << endl << endl;
		print(3);
		cout << " �������������� 0 " << endl << endl;
		print(3);
		cout << " ���������ѯѧ��ѧ�ţ�";
		char s[20];
FIND_INPUT:
		cin >> s;
		if (s[0] == '0' && s[1] == '\0') goto FIND_BACK;
		int pos = find(addr, s);
		if (pos == -1) 
		{
			cout << endl << "�Ҳ�����ѧ�������������룺";
			goto FIND_INPUT;
		}
		else 
		{
			cout << endl << "��ѧ����Ϣ��" << endl << endl;
			addr[pos].show();
		}
	}
FIND_BACK:
	back();
}

void ui::exe_show()		// �鿴
{
	clear();
	file::writetext("�鿴ѧ����Ϣ");
	cout << endl;
	print(3);
	if (cur == 0)
		cout << "û��ѧ�����ݣ��޷��鿴" << endl;
	else
	{
		cout << " ȫ��ѧ������:" << endl << endl;
		cout << "ѧ��\t\t����\t�Ա�\t�꼶\tѧԺ\t\tרҵ\t      �༶";
		cout << endl;
		print(79);
		cout << endl;
		for (int i=0; i<cur; i++)
		{
			if (addr[i].used)
			{
				cout << addr[i].num << "\t" << addr[i].name << "\t";
				addr[i].print_sex(addr[i].sex);
				cout << "\t";
				addr[i].print_grade(addr[i].grade);
				cout << "\t";
				addr[i].print_xueyuan(addr[i].xueyuan);
				cout << "\t";
				addr[i].print_major(addr[i].xueyuan, addr[i].major);
				cout << "     ";
				addr[i].print_class(addr[i].clas);
				cout << endl;
			}
		}
	}
	back();
}

void ui::exe_set()		// ����
{
	clear();
	file::writetext("������ɫ");
	cout << endl;
	print(3);
	cout << " ϵͳ���ã�" << endl << endl;
	cout << "1. ��ɫ   2. ��ɫ   3. ��ɫ   4. ��ɫ   5. ��ɫ   6. ��ɫ";
	cout << endl << endl;
	cout << "���ý�����ɫ��";
	string str;
	int op;
	while (1)
	{
		fflush(stdin);
		cin >> str;
		op = getnum(str);
		if (op >= 1 && op <= 6)
		{
			switch (op)
			{
			case 1 : setcolor(0); break;
			case 2 : setcolor(1); break;
			case 3 : setcolor(2); break;
			case 4 : setcolor(3); break;
			case 5 : setcolor(4); break;
			case 6 : setcolor(5); break;
			}
			// д�� INI �ļ�
			char buf[MAXPATH];
			strtochar(set_path, buf);
			FILE *fp = NULL;
			fp = fopen(buf, "wt");
			if (fp) 
			{
				fprintf(fp, "[info]\ncolor=%d\n", op-1);
				fclose(fp);
				fp = NULL;
			}
			cout << endl << "���óɹ���" << endl;
			break;
		}
		else cout << "XXX ����������������룺";
	}
	back();
}

void ui::exe_backup()	// ����
{
	clear();

	// ������д�ص�������,׼������
	write_student_data(addr, stu_path);

	// ��ʼ
	file::writetext("��ʼ���������ļ�");
	cout << endl;
	cout << "1. ����ѧ�������ļ���...    2. �����µ�ѧ�������ļ�" << endl << endl;
	print(3);
	cout << " ��ѡ��Ҫִ�еĲ�����";
	int op;
	string str;
	int len = 0, i = 0;
	while (1)
	{
		cin >> str;
		fflush(stdin);
		op = getnum(str);
		if (op>=1 && op <= 2)
		{
			string newpath;
			file copy;
			switch (op)
			{
			case 1 : 
				cout << endl;
				print(3);
				cout << " ��������·����(�磺c:\\student\\)";
				cin >> newpath;
				// �����ļ���
				newpath += filename;

				// ��ʼ����
				if (copy.copyfile(stu_path, newpath))
				{
					cout << endl << "���ݳɹ���" << endl;
					file::writetext("���ݳɹ���");
				}
				else 
				{
					cout << endl << "����ʧ�ܣ�" << endl;
					file::writetext("����ʧ��");
				}
				goto BACK2;
			case 2 : 
				file::writetext("��ʼ��ԭ�����ļ�");
				cout << endl;
				cout << "ע�⣺�˲������Ḳ��ԭ�е�����!" << endl << endl;
				print(3);
				cout << " ������ѧ�������ļ���·����(�磺c:\\student\\stu.dat)";
				cout << endl;
				cin >> newpath;
				if (copy.fileexist(newpath))
				{
					copy.deletefile(stu_path);
					copy.copyfile(newpath, stu_path);
					copy.newname(stu_path, filename);

					// ˢ���ڴ��е�����
					FILE *fp = NULL;
					char buf[MAXPATH] = {0};
					strtochar(stu_path, buf);

					if (addr) free(addr);
					fp = fopen(buf, "rb");
					if (!fp) goto NEXT2;
					fseek(fp, 0, SEEK_END);
					int size = ftell(fp);
					int each = sizeof(student);
					rewind(fp);
					if (size)
					{
						// �������ݿռ�
						cur = size / each;
						addr = (student *)malloc((cur+1) * sizeof(student));
						if (!addr) exit(0);
						
						// ��ʼ��ȡ�� addr
						fread(addr, each, cur, fp);
						fclose(fp);
						fp = NULL;
					}				
					cout << endl << "����ɹ���" << endl;
					file::writetext("����ɹ���");
				}
				else
				{
NEXT2:
					cout << endl << "����ʧ�ܣ��Ҳ��� "<< newpath << endl;
					file::writetext("����ʧ�ܣ��Ҳ��������ļ�");
				}
				goto BACK2;
			}
		}
		else cout << "XXX ����������������룺"; 
	}
BACK2:
	back();
}
