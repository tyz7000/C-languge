#include <iostream>
using namespace std;

class point
{
public:
	point(int a=0, int b=0)
	{ x = a;   y = b; }
	point operator + (point &a);	// ���ⶨ��
	point operator - (point &a)
	{
		// ��Ч����
		return point(x - a.x, y - a.y);
	}
	// �������Ѷ�����++�����������Ԫ����++�������������
	point operator - ();		// ��Ŀ�����
	point operator ++ ();		// ǰ׺����
	point operator ++ (int);	// ��׺���ã���ǰ׺��������
	void show()
	{ cout << "(" << x << "," << y << ")" << endl; }
private:
	int x;
	int y;
};

point point::operator + (point &a)
{
	point tmp;
	tmp.x = x + a.x;
	tmp.y = y + a.y;
	return tmp;
}

// ���Լ�����
point point::operator - ()
{
	x = -x;
	y = -y;
	return *this;
}

point point::operator ++ ()
{
	// ����Ǿ��������������Ҫ�¿���ʱ������
	++x;
	++y;
	return *this;
}

point point::operator ++ (int)	// ��׺����
{
	x++;
	y++;
	return *this;
}

int main(void)
{
	point p1(2, 2);  cout << "p1 = ";  p1.show();
	point p2(4, 4);  cout << "p2 = ";  p2.show();
	point p3, p4;

	p3 = p1 + p2;	 cout << "p3 = ";  p3.show();
	p3 = p1.operator + (p2);	  // ��ʽ����
	cout << "p3 = ";  p3.show();
	p3 = -p3;   cout << "p3 = ";  p3.show();
	p3.operator - ();   p3.show();		// ��ʾ���õ�Ŀ

	p4 = p1 - p2;    cout << "p4 = ";  p4.show();
	p4 = p1.operator - (p2);
	cout << "p4 = ";  p4.show();
	p4 = p2.operator - (p1);
	cout << "p4 = ";  p4.show();

	p4++;                cout << "p4 = ";  p4.show();
	p4.operator ++ ();   cout << "p4 = ";  p4.show();
	++p4;                cout << "p4 = ";  p4.show();
	p4.operator ++ (0);  cout << "p4 = ";  p4.show();

	return 0;
}
