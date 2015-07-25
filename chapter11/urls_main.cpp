#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include "Vec.h"
#include "urls.h"

using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		Vec<string> v = find_urls(s);
		for (Vec<string>::const_iterator it = v.begin(); it != v.end(); ++it)
			cout << *it << endl;
	}

	system("pause");
	return 0;
}