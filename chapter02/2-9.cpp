#include<iostream>

using namespace std;

int main()
{
	int m, n;
	cout << "please enter two numbers: ";
	cin >> m;
	cin >> n;
	if (m == n) 
	{
		cout << m << " equals " << n;
	}
	else if (m > n) 
	{
		cout << m << " > " << n;
	}
	else 
	{
		cout << m << " < " << n;
	}

	system("pause");
	return 0;
}
