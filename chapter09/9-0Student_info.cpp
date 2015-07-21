#include <iostream>
#include <vector>

#include "9-0grade.h"
#include "9-0Student_info.h"

using namespace std;

Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		// 清除之前的内容
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		// 清除流以使正确处理下一个学生
		in.clear();
	}
	return in;
}

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double Student_info::grade() const
{
	// ::grade表示所使用的grade版本不能为任何事物的成员
	return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

