#include <iostream>
#include "mylist.h"   // ���� C++ ���к�ջ��ʹ�÷���

using namespace std;

class point 
{
public:
	point(int a=0, int b=0) 
	{x = a;  y = b;}
	int x, y;
};

int main()
{
	char i;
	char ch;
	queue<char> q;		// ���в���
	
	for (i='a'; i<='z'; i++)  q.push(i);
	cout << "���д�С: " << q.size() << endl;
	while (!q.empty())
	{
		ch = q.front();
		cout << ch;
		q.pop();
	}
	cout << endl;
	
	// �Զ�����Ĳ���
	queue<point> q2;
	point tmp, p[3] = {point(1,2), point(3,4), point(5,6)};
	for (i=0; i<3; i++) q2.push(p[i]);
	cout << "���д�С: " << q2.size() << endl;
	while (!q2.empty())
	{
		tmp = q2.front();
		cout << tmp.x << "," << tmp.y << endl;
		q2.pop();
	}
	cout << endl;

	// ջ����
	stack<char> s;
	for (i='a'; i<='z'; i++)  s.push(i);
	cout << "ջ��С: " << s.size() << endl;
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;

	stack<point> s2;	// �Զ�����Ĳ���
	for (i=0; i<3; i++) s2.push(p[i]);
	cout << "ջ��С: " << s2.size() << endl;
	while (!s2.empty())
	{
		cout << s2.top().x << "," << s2.top().y << endl;
		s2.pop();
	}
	return 0;
}
