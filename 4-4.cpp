#include<iostream>
#include<iomanip>
#include<math.h> 

using namespace std;

int get_width(double n)
{
	return log10(n) + 1;
}

int main()
{
	cout << "Enter the range min to max: ";
	double min, max;
	cin >> min >> max;
	for (double i = min;i <= max; ++i) 
	{
		cout << setw(get_width(max)) << i << setw(get_width(max*max)) << i*i << endl;
	}

	system("pause");
	return 0;
}
