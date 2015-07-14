#include<iostream>
#include<string>

using namespace std;

int main()
{
	const int height = 5;

	int row;
	int col;

//*********************正方形**********************//
	row = 0;
	col = 0;

	while (col < height) 
	{
		cout << '*';
		++col;
	}

	cout << endl;
	++row;

	while (row < height - 1) 
	{
		col = 0;
		while (col < height) 
		{
			++col;
			if (col == 1)
				cout << '*';
			else 
			{
				if (col == height)
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << endl;
		++row;
	}

	col = 0;

	while (col < height) 
	{
		cout << '*';
		++col;
	}

////////////////////////////////////////////////////

	cout << endl;

	cout << endl;

//*********************长方形**********************//
	row = 0;
	col = 0;

	while (col < height * 2) 
	{
		cout << '*';
		++col;
	}

	cout << endl;
	++row;

	while (row < height - 1) 
	{
		col = 0;
		while (col <= height * 2) 
		{
			++col;
			if (col == 1)
				cout << '*';
			else 
			{
				if (col == height * 2)
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << endl;
		++row;
	}

	col = 0;

	while (col < height * 2)
	{
		cout << '*';
		++col;
	}

////////////////////////////////////////////////////
	cout << endl;

	cout << endl;

//*********************三角形**********************//
	row = 0;

	while (row < height - 1)
	{
		col = 0;
		while (col < height + row) 
		{
			++col;
			if (col == height - row)
				cout << '*';
			else 
			{
				if (col == height + row)
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << endl;
		++row;
	}

	col = 0;

	while (col < height * 2 - 1) 
	{
		cout <<'*';
		++col;
	}

////////////////////////////////////////////////////

	cout << endl;

	system("pause");
	return 0;
}
