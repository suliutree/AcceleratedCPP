//#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

string letter_grade(double grade)
{
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	for (size_t i = 0; i < ngrades; ++i)
	{
		if (grade >= numbers[i])
			return letters[i];
	}

	// 如果没有找到一个合适的字母成绩，意味着用户提供的是一个负数成绩，用?\?\?表示???
	return "?\?\?";
}

int main()
{
	double grade = 0;
	while (grade != -1)
	{
		cout << "Input a grade: ";
		cin >> grade;
		cout << letter_grade(grade) << endl;
	}

	system("pause");
	return 0;
}