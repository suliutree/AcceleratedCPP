#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> center(const vector<string>& picture)
{
	vector<string> new_picture;
	vector<string>::size_type max_length = 0;

	for (vector<string>::const_iterator it = picture.begin();
		it != picture.end(); ++it)
	{
		if (it->size() > max_length)
			max_length = it->size();
	}

	for (vector<string>::const_iterator it = picture.begin();
		it != picture.end(); ++it)
	{
		vector<string>::size_type padding = (max_length - it->size()) / 2;
		string new_line(padding, ' ');
		new_line += *it;
		new_picture.push_back(new_line);
	}

	return new_picture;
}

int main()
{
	vector<string> picture;

	picture.push_back("*");
	picture.push_back("***");
	picture.push_back("*****");
	picture.push_back("*");
	picture.push_back("***");
	picture.push_back("*******");

	vector<string> new_picture = center(picture);

	for (vector<string>::const_iterator it = new_picture.begin();
		it != new_picture.end(); ++it)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
