#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "split.h"
#include "urls.h"

using namespace std;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
	map<string, vector<int> > ret;
	int line_number = 0;
	string line;

	while (getline(in, line))
	{
		++line_number;

		vector<string> words = find_urls(line);

		for (vector<string>::const_iterator it = words.begin();
			it != words.end(); ++it)
		{
			ret[*it].push_back(line_number);
		}
	}

	return ret;
}

int main()
{
	map<string, vector<int> > ret = xref(cin);

	for (map<string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it)
	{
		cout << it->first << " occust on lines: ";

		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}

		cout << endl;
	}

	system("pause");
	return 0;
}