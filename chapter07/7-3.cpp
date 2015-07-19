#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))
			i++;

		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
			j++;

		if (j != i)
		{
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return ret;
}

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while (getline(in, line))
	{
		++line_number;

		vector<string> words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); 
			it != words.end(); ++it)
		{
			// 只需增加这一行
			if (find(ret[*it].begin(), ret[*it].end(), line_number) == ret[*it].end())
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
		cout << it->first << " occurs on lines: ";

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