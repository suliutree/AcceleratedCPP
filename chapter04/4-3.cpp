#include <iostream>
#include <iomanip>

using namespace std;

int get_width(int n)
{
	return log(n*1.0) + 1;
}

int main()
{
	cout << "Enter the range min to max: ";
	int min, max;
	cin >> min >> max;
	for (int i = min; i <= max; ++i)
	{
		cout << setw(get_width(max)) << i << setw(get_width(max*max)) << i*i << endl;
	}

	system("pause");
	return 0;
}

