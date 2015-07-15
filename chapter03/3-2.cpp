#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> integers;

	cout << "Input integers: ";
	int x;
	while (cin >> x)
		integers.push_back(x);

	if (integers.size() == 0)
	{
		cout << "No integers!" << endl;
		return 1;
	}

	sort(integers.rbegin(), integers.rend());
	typedef vector<int>::size_type vec_sz;

	cout << "first quartile:" << endl;
	for (vec_sz i = 0; i < integers.size() / 4; ++i)
		cout << integers[i] << endl;

	cout << "second quartile:" << endl;
	for (vec_sz i = integers.size() / 4; i < integers.size() / 2; ++i)
		cout << integers[i] << endl;

	cout << "third quartile:" << endl;
	for (vec_sz i = integers.size() / 2; i < integers.size() * 3 / 4; ++i)
		cout << integers[i] << endl;

	cout << "fourth quarttile:" << endl;
	for (vec_sz i = integers.size() * 3 / 4; i < integers.size(); ++i)
		cout << integers[i] << endl;

	system("pause");
	return 0;
}
