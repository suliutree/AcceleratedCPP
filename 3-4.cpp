#include<iostream>
#include<string>

using namespace std;

int main()
{
	typedef string::size_type str_sz;
	string longest;
	str_sz longest_size =0;
	string shortest;
	str_sz shortest_size= 0;

	cout <<"Enter words: ";
	string s;
	while (cin >> s) 
	{
		if (longest_size == 0 || s.size() > longest_size)
		{
			longest = s;
			longest_size =s.size();
		}

		if (shortest_size == 0 || s.size() < shortest_size)
		{
			shortest = s;
			shortest_size =s.size();
		}
	}

	cout << "Longest word is " << longest << " (" << longest_size << ")" <<endl;
	cout << "Shortest word is " << shortest << " (" << shortest_size << ")" << endl;

	system("pause");
	return 0;
}
