#include <iostream>

using namespace std;

int main()
{
	int ret = 1;
	for (int i = 1; i < 10; ++i)
	{
		ret *= i;
	}
	cout << ret << endl;
	system("pause");
	return 0;
}
