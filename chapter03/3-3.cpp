#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> words;
	vector<int> counts;

	typedef vector<string>::size_type vec_sz;

	cout << "Enter words: ";
	string str;
	while (cin >> str)
	{
		bool found = false;
		for (vec_sz i = 0; i < words.size(); ++i)
		{
			if (str == words[i])
			{
				counts[i]++;
				found = true;
			}
		}

		if (!found)
		{
			words.push_back(str);
			counts.push_back(1);
		}
	}

	for (vec_sz i = 0; i < words.size(); ++i)
	{
		cout << words[i] << " appears " << counts[i] << " times! " << endl;
	}

	system("pause");
	return 0;
}
