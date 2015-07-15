#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
	cout << "Enter numbers: ";

	vector<double> numbers;

	double num;
	while (cin >> num) 
	{
		numbers.push_back(num);
	}
	// accumulate头两个形参指定要累加的元素范围，第三个形参则是累加的初值（0.0表示累加结果是double）
	cout << "Average: "
		 << accumulate(numbers.begin(),numbers.end(), 0.0)/numbers.size();

	system("pause");
	return 0;
}
