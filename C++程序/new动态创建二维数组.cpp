#include <iostream>
using namespace std;

int main(void)
{
	int **p = new int *[10];
	int num = 0;

	for (int i=0; i<10; i++)
	{
		p[i] = new int[10];
	}

	for (int j=0; j<10; j++)
	{
		for (int k=0; k<10; k++)
		{
			p[j][k] = num++;
		}
	}

	for (j=0; j<10; j++)
	{
		for (int k=0; k<10; k++)
		{
			printf("%4d", p[j][k]);
		}
		cout << endl;
	}

	for (i=0; i<10; i++)
	{
		delete [] p[i];    
		// p[i] ��һ��ָ���ַ��Ҫ��[]
	}
	delete [] p;

	return 0;
}