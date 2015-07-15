#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& word)
{
	string reversed;
	reverse_copy(word.begin(), word.end(), back_inserter(reversed));
	return word == reversed;
}

int main()
{
	vector<string> palindromes;
	string longestPalindromes;

	cout << "Enter words: " << endl;
	string s;
	while (cin >> s)
	{
		if (isPalindrome(s))
			palindromes.push_back(s);

		if (s.length() > longestPalindromes.length())
			longestPalindromes = s;
	}

	cout << "Palindromes:" << endl;
	for (vector<string>::iterator it = palindromes.begin(); it != palindromes.end(); ++it)
		cout << *it << endl;

	cout << "Longest Palindromes: " << longestPalindromes << endl;

	system("pause");
	return 0;
}
