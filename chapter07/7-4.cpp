#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream> // 使用stringstream需要引用这个头文件

using namespace std;

#define LINE_LENGTH 30

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
		stringstream ss;

		// 将" occurs on lines: "装入到ss中
		ss << it->first << " occurs on lines: ";

		vector<int>::const_iterator line_it = it->second.begin();
		// 将第一次出现的行号装入到ss中
		ss << *line_it;
		++line_it;
		while (line_it != it->second.end())
		{
			ss << ", " << *line_it;
			++line_it;
		}

		string output = ss.str();

		for (string::size_type i = 0; i != output.size(); ++i)
		{
			cout << output[i];
			if ((i+1) % LINE_LENGTH == 0)
				cout << endl;
		}

		cout << endl;
	}

	system("pause");
	return 0;
}