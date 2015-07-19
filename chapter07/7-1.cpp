#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	map<string, int> counters;
	map<int, vector<string> > wordsFreq;

	string str;
	while (cin >> str)
		counters[str]++;

	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it)
	{
		wordsFreq[it->second].push_back(it->first);
	}

	for (map<int, vector<string> >::const_iterator it = wordsFreq.begin();
		it != wordsFreq.end(); ++it)
	{
		cout << "Frequency " << it->first << endl;

		for (vector<string>::const_iterator iter = it->second.begin();
			iter != it->second.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}