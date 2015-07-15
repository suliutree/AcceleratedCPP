#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string ascenders = "bdfhklt";
const string descenders = "gjpqy";

bool has_chars(const string& word, const string& chars)
{
	for (string::size_type i = 0; i != word.length(); ++i)
		for (string::size_type j = 0; j != chars.length(); ++j)
		{
			if (word[i] == chars[j])
				return true;
		}
	return false;
}

int main()
{
	vector<string> hasAscOrDsc;
	string longestNoAscOrDsc;

	cout << "Enter words:" << endl;
	string str;
	while (cin >> str)
	{
		if (has_chars(str, ascenders) || has_chars(str, descenders))
			hasAscOrDsc.push_back(str);
		else if (str.length() > longestNoAscOrDsc.length())
			longestNoAscOrDsc = str;
	}

	cout << "Has ascenders or descenders: " << endl;
	for (vector<string>::iterator it = hasAscOrDsc.begin(); it != hasAscOrDsc.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "Longest word without ascenders or descenders: " << longestNoAscOrDsc << endl;

	system("pause");
	return 0;
}
