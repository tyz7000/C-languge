#include <iostream>

// ���ֿռ�Ҳ����Ƕ��, �����ļ�Ŀ¼��
// all::caokun::grade
// ������ˣ�using namespace all; �Ͳ���д all::
namespace all
{
	namespace caokun
	{
		int grade = 100;
	}
	namespace wu
	{
		int grade = 10;
	}
}

namespace test
{
	class point 
	{
	public:
		int x;
		int y;
	};
}
using namespace test;

// ȥ��ע�ͣ��Ϳ����ü� all:: ��
// using namespace all;

int main()
{
	// std �Ǳ�׼�����ֿռ�
	std::cout << "wujiaying" << std::endl;
	std::cout << all::caokun::grade << std::endl;
	std::cout << all::wu::grade << std::endl;

	point p;
	p.x = 4;
	p.y = 7;

	return 0;
}
