#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		cout << argv[1];
		for (int i = 2; i != argc; ++i)
			cout << " " << argv[i];
	}
	cout << endl;
	system("pause");
	return 0;
}