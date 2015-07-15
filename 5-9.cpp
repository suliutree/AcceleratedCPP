#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool hasUppercase(const string& word)
{
	for (string::size_type i = 0; i < word.length(); ++i)
		if (isupper(word[i]))
			return true;
	return false;
}

int main()
{
	string s;
	vector<string> upperCase;
	vector<string> noUppercase;

	while (cin >> s)
	{
		if (hasUppercase(s))
			upperCase.push_back(s);
		else
			noUppercase.push_back(s);
	}

	cout << "No uppercase letters:" << endl;
	for (vector<string>::iterator it = noUppercase.begin(); it != noUppercase.end(); ++it)
		cout << *it << endl;

	cout << "Uppercase letters:" << endl;
	for (vector<string>::iterator it = upperCase.begin(); it != upperCase.end(); ++it)
		cout << *it << endl;

	system("pause");
	return 0;
}
