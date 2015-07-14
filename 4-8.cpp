#include<iostream>

using namespace std;

double *f()
{
	static double value[]= {1.1, 2.2, 3.3, 4.4, 5.5};
	return value;
}
int main ()
{
	int n = 2;
	double d = f() [n];
	cout << "d = " << d <<'\n';
	system("pause");
	return 0;
}
/*
输出结果为：d = 3.3
*/
