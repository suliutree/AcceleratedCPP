#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "please enter your name: ";
	string name;
	cin >> name;

	const string greeting = "hello, " + name + "!";

	const string spaces(greeting.size(), ' ');
	const string second = "*" + spaces + "*";
	const string first(second.size(), '*');

	cout << first << endl;
	cout << second << endl;
	cout << "*" << greeting << "*" << endl;
	cout << second << endl;
	cout << first << endl;

	system("pause");
	return 0;
}
