#include <iostream>
#include <string>

using namespace std;

class ui;
class file;
struct student;

const int BUFFER_SIZE = 500;	// ��д��������С
const int MAXPATH = 150;		// ·����С

// ������ɫ
typedef 
	enum {green, blue, red, purple, yellow, white} 
color;


// ------------------�ļ�������------------------

class file
{
public:
	file::file();
	file::~file();
	bool copyfile(string &oldpath, string &newpath);	// ����
	bool cutfile(string &oldpath, string &newpath);		// ���� 
	bool fileexist(string &path);					// �ж��ļ�����
	bool deletefile(string &path);					// ɾ���ļ�
	bool newname(string &oldpath, string &name);	// ������
	static void writetext(char *text);			// ��¼����
	string getpath();		// ��õ�ǰ·��
	string getdir();		// ��õ�ǰĿ¼
private:
	string filepath(void);	// �����ļ�·��
	string directory(void);	// ��������Ŀ¼·��
	string filepaths;		// ��¼·��
	string filedir;			// ��¼Ŀ¼
};


// ------------------������ʾ��------------------

class ui
{
public:
	ui::ui();
	ui::~ui();
	void display();		// ������
	int wait();			// �ȴ�����
protected:
	void exe_create();		// ����
	void exe_update();		// �޸�
	void exe_remove();		// ɾ��
	void exe_find();		// ��ѯ
	void exe_show();		// �鿴
	void exe_set();			// ����
	void exe_backup();		// ����
private:
	// strtochar ��ͨ��������ã���Ҫ��ɾ�̬��
	static void strtochar(string &s, char *buf);
	friend file;
	void show_major(short int n, int &a, int &b);
	bool write_student_data(student *addr, string &path);
	int find(student *addr, char *s);
	int findnum(char *s);		// ������ɫֵ
	void setcolor(int num);		// ������ɫ
	int check(int a, int b);	// �������
	string checkname();			// �������
	string checknum();			// ���ѧ��
	void print(int n);			// ����»���
	int  getnum(string &str);	// strתint
	inline void back();			// ��������
	inline void clear();		// ����
	void showxueyuan();			// ��ʾѧԺ
	void allmajor(short int n);	// ȫ��רҵ
	string filename;			// �ļ���
	string stu_path;			// ����·��
	string set_path;			// INI·��
	string dir;					// Ŀ¼
	student *addr;				// �������ݵ�ַ
	int cur;					// ���ø���
};


// -----------------ѧ����Ϣ���-----------------
// ��������� string ����ʹ�� new ����
// malloc ֻ�Ƿ���һ��ռ䣬�����й������
struct student
{
public:
	char num[20];		// ѧ��
	char name[20];		// ����
	short int sex;		// �Ա�	
	short int xueyuan;	// ѧԺ����
	short int major;	// רҵ����
	short int grade;	// �꼶
	short int clas;		// �༶
	bool used;			// ɾ�����

	void show();		// ���
	void print_xueyuan(short int n);
	void print_major(short int x, short int n);
	void print_grade(short int n);
	void print_class(short int n);
	void print_sex(short int n);
};
