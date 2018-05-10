#include "student.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// file ��ʵ�ֲ���

file::file()
{
	filepaths = filepath();
	if (filepaths[0] == '0') exit(0);

	filedir = directory();
	if (filedir[0] == '0') exit(0);
}

file::~file()
{
	// to be continued...
}

// ��ó���·��
string file::filepath(void)
{
	char buffer[MAX_PATH];

	if (GetModuleFileName(NULL, buffer, MAX_PATH))
	{
		string s = buffer;
		return s;
	}
	else return NULL;
}

// ��ó���Ŀ¼
string file::directory(void)
{
	char buffer[MAX_PATH];

	if (GetCurrentDirectory(MAX_PATH, buffer))
	{
		string s = buffer;
		return s;
	}
	else return NULL;

}

string file::getpath()
{
	return filepaths;
}

string file::getdir()
{
	return filedir;
}

// �ж��ļ�����
bool file::fileexist(string &path)
{
	FILE *fp = NULL;
	char f[200];
	int i = 0;

	// string ת char
	ui::strtochar(path, f);

	fp = fopen(f, "rb");
	if (fp)
	{
		fclose(fp);
		return true;
	}
	else return false;
}

// ���� old �� new
bool file::copyfile(string &oldpath, string &newpath)
{
	char c_old[MAXPATH] = {0};
	char c_new[MAXPATH] = {0};
	FILE *in = NULL;
	FILE *out = NULL;

	ui::strtochar(oldpath, c_old);   // ������ʾ����
	ui::strtochar(newpath, c_new);

	if (!fileexist(oldpath)) return false;
	in = fopen(c_old, "rb");
	if (in)
	{
		out = fopen(c_new, "wb");
		if (out)
		{
			// ��д������
			char buffer[BUFFER_SIZE];
			int an;

			// ��ʼ����
			while (1)
			{
				an = fread(buffer, 1, BUFFER_SIZE, in);
				if (an == 0) break;
				fwrite(buffer, 1, an, out);
			}
			fclose(out);
		}
		fclose(in);
	}
	return true;
}

// ɾ���ļ�
bool file::deletefile(string &path)
{
	if (fileexist(path))
	{
		char buf[MAXPATH] = {0};

		ui::strtochar(path, buf);
		remove(buf);
		return true;
	}
	return false;
}

// ���� old �� new
bool file::cutfile(string &oldpath, string &newpath)
{
	if (copyfile(oldpath, newpath)) 
	{
		deletefile(oldpath);
		return true;
	}
	return false;
}

// ������
bool file::newname(string &oldpath, string &name)
{
	if (fileexist(oldpath))
	{
		char buf[MAXPATH] = {0};
		char dir[MAXPATH] = {0};	// ��ǰĿ¼
		char n[50] = {0};
		int len = 0;

		ui::strtochar(oldpath, buf);
		ui::strtochar(oldpath, dir);
		ui::strtochar(name, n);

		// ��ȡĿ¼
		while (dir[len] != '\0') len++;
		while (dir[len] != '\\')
		{
			dir[len] = '\0';
			len--;
		}
		
		// dir ����������
		int len2 = 0;
		while (n[len2] != '\0')
		{
			dir[++len] = n[len2++];
		}
		
		if (rename(buf, dir)) return true;
	}
	return false;
}

void file::writetext(char *text)
{
	char buffer[MAX_PATH];

	// ���Ŀ¼
	if (GetCurrentDirectory(MAX_PATH, buffer))
	{
		int len = 0;
		int i = 0;
		char name[] = "\\recond.txt";
		while (buffer[len] != '\0') len++;
		while (name[i] != '\0')
			buffer[len++] = name[i++];
		buffer[len] = '\0';

		// ���ļ�
		FILE *out = NULL;
		out = fopen(buffer, "a");
		if (out)
		{
			// ���ϵͳʱ��
			struct tm *tmp;
			time_t second;
			int h, m, s;
			time(&second);
			tmp = localtime(&second);
			h = tmp->tm_hour;
			m = tmp->tm_min;
			s = tmp->tm_sec;
			// д��ʱ��
			fprintf(out, "[%02d:%02d:%02d] ", h,m,s);
			// д���¼�
			fprintf(out, "%s\n", text);
			fclose(out);
		}
	}
}
