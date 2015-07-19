#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> counters;

	string str;
	while (cin >> str)
		counters[str]++;

	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it)
	{
		cout << it->first << '\t' << it->second << endl; 
	}

	system("pause");
	return 0;
}