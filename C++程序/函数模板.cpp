#include <iostream.h>

class point
{
public:
	point(double a, double b)
	{ x = a;   y = b; }
	friend ostream &operator << (ostream &out, point &p);
	friend bool operator > (point &p1, point &p2);
private:
	double x;
	double y;
};

// �� &operator << ����һ������
ostream &operator << (ostream &oc, point &p)
{
	oc << "(";
	oc << p.x << "," << p.y;
	oc << ")";
	return oc;
}

// ģ���������ʵ��ȫ����Ҫ��ͷ�ļ���
// Ҳ���� template <class type>
template <typename type>
type max(type &a, type &b)
{
	return a > b ? a : b;
}

// �����������, �β����������ͱ���ȫ������
template <typename type1, typename type2, typename type3>
type1 test(type1 a, type2 b, type3 c)
{
	cout << a << "-" << b << "-" << c;
	return a;
}

// ģ����ģ�������
template <typename type>
type max(type &a, type &b, type &c)
{
	bool flag1 = true;
	bool flag2 = true;
	type tmp;

	// ����������м��Ǹ�
	while (flag1 || flag2)
	{
		if (a > b) {tmp = a; a = b; b = tmp;}
		else flag1 = false;
		if (b > c) {tmp = c; c = b; b = tmp;}
		else flag2 = false;
	}
	return b;
}

// ģ������ͨ����������
float max(float a, float b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 9;
	int b = 4;
	int a1 = 4;
	cout << max(a, b) << endl;
	cout << max(a, b, a1) << endl;	// ������һ��ģ��

	double c = 1.2;
	double d = 1.3;
	cout << max(c, d) << endl;

	char e = 'e';
	char f = 'f';
	cout << max(e, f) << endl;

	point g(1.2, 3);
	point h(1.6, 4);
	cout << max(g, h) << endl;		// �Զ�������

	float q = 3.1f;
	float w = 3.2f;
	cout << max(q, w) << endl;		// ����ͨ��������

	char *str = "abcdefg";
	int s = 12;
	double s2 = 3.456;
	cout << test (s, s2, str) << endl;
	// �����������

	return 0;
}

// ���� >
bool operator > (point &p1, point &p2)
{
	if (p1.x > p2.x) return true;
	else return false;
}
