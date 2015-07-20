#include <iostream>
#include <string>

#include "8-2.h"

using namespace std;

char transformString(char c)
{
	return ++c;
}

bool passes(char c)
{
	return c == 'T';
}

int main()
{
	string compare1 = "what";
	string compare2 = "what";
	cout << my_equal(compare1.begin(), compare1.end(), compare2.begin()) << endl;

	string sourceStr = "abcdef";
	string searchStr = "cd";
	cout << *my_search(sourceStr.begin(), sourceStr.end(), searchStr.begin(), searchStr.end()) << endl;

	string trans = "abc";
	my_transform(trans.begin(), trans.end(), trans.begin(), transformString);
	cout << trans << endl;

	string parti = "TFFTTTFFT";
	my_partition(parti.begin(), parti.end(), passes);
	cout << parti << endl;

	system("pause");
	return 0;
}