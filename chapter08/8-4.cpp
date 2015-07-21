#include <iostream>
#include <string>

using namespace std;

template <class Type>
void my_swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;
}

template <class Bi>
void my_reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
			my_swap(*begin++, *end);
	}
}

int main()
{
	string str = "kindle";
	my_reverse(str.begin(), str.end());
	cout << str << endl;

	system("pause");
	return 0;
}


