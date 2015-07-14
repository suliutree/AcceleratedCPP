#include<iomanip>
#include<ios>
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades:";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	int count = 0;
	double sum = 0;

	double x;
	while (cin >> x) 
	{
		++count;
		sum += x;
	}

	double homework_grade = (count > 0) ? sum / count: 0.0;

	streamsize prec =cout.precision();
	cout <<"Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * homework_grade
		<< setprecision(prec) << endl;

	system("pause");
	return 0;
}
