#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	// copy(u.begin(), u.end(), back_inserter(v));
	copy(u.begin(), u.end(), inserter(v, v.begin()));


	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}