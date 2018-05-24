#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream infile("16-1.cpp");

	string s;
	while (getline(infile, s))
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}

// do some change