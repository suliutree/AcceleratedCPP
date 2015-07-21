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
		// ���֮ǰ������
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		// �������ʹ��ȷ������һ��ѧ��
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
	// ::grade��ʾ��ʹ�õ�grade�汾����Ϊ�κ�����ĳ�Ա
	return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

