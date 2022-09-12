#pragma once
#include <iostream>
#include<iomanip>
using namespace std;

class CoutHelper
{
public:
	void DrawLine(int col0, int col1, int col2, int col3, int col4,
		string text0, string text1, string text2, string text3, string text4, bool with_endl = true)
	{
		cout << left
			<< char(186) << setw(col0 - 1) << text0
			<< char(186) << setw(col1 - 1) << text1
			<< char(186) << setw(col2 - 1) << text2
			<< char(186) << setw(col3 - 1) << text3
			<< char(186) << setw(col4 - 1) << text4 << char(186);
		if (with_endl)
		{
			cout << endl;
		}
	}

	void Header(int col0, int col1, int col2, int col3, int col4,
		        string text0, string text1, string text2, string text3, string text4, int height = 4)
	{
		int width = col0 + col1 + col2 + col3 + col4;
		for (int x = 0; x <= height; x++)
		{
			if (x == 2)
			{
				DrawLine(col0, col1, col2, col3, col4,
						 text0, text1, text2, text3, text4, false);
			}
			else
			{
				for (int y = 0; y <= width; y++)
				{
					if (y == 0 && x == 0)
					{
						cout << char(201);
					}
					else if (x == 0 && y == width)
					{
						cout << char(187);
					}
					else if (x == height && y == 0)
					{
						cout << char(204);
					}
					else if (x == height && y == width)
					{
						cout << char(185);
					}
					else if (y == 0 ||
						y == col0 ||
						y == col0 + col1 ||
						y == col0 + col1 + col2 ||
						y == col0 + col1 + col2 + col3 ||
						y == col0 + col1 + col2 + col3 + col4)
					{
						if (x == 0)
						{
							cout << char(203);
						}
						else if (x == height)
						{
							cout << char(206);
						}
						else
						{
							cout << char(186);
						}
					}
					else if (x == 0 || x == height)
					{
						cout << char(205);
					}
					else
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}


	void Footer(int col0, int col1, int col2, int col3, int col4, int height = 2)
	{
		int width = col0 + col1 + col2 + col3 + col4;
		for (int x = 0; x <= height; x++)
		{
			for (int y = 0; y <= width; y++)
			{
				if (y == 0 && x == 0)
				{
					cout << char(204);
				}
				else if (x == 0 && y == width)
				{
					cout << char(185);
				}
				else if (x == height && y == 0)
				{
					cout << char(200);
				}
				else if (x == height && y == width)
				{
					cout << char(188);
				}
				else if (y == 0 ||
					y == col0 ||
					y == col0 + col1 ||
					y == col0 + col1 + col2 ||
					y == col0 + col1 + col2 + col3 ||
					y == col0 + col1 + col2 + col3 + col4)
				{
					if (x == 0)
					{
						cout << char(206);
					}
					else if (x == height)
					{
						cout << char(202);
					}
					else
					{
						cout << char(186);
					}
				}
				else if (x == 0 || x == height)
				{
					cout << char(205);
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}
};