// ForKatya.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <fstream>

using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
	ifstream in("in.txt");
	int lx, ly, l, r, x, y;
	in >> lx >> ly;
	point rmax{ 0,0 };
	point lmax{ 0, 0 };
	r = 0;
	l = -1;

	while (!in.eof())
	{
		in >> x >> y;
		int d = x * ly - y * lx;
		if (d >= r) {
			r = d;
			rmax.x = x;
			rmax.y = y;

		}
		if (d <= l) {
			l = d;
			lmax.x = x;
			lmax.y = y;
		}
	}

	cout << "Leftmost: " << lmax.x << ' ' << lmax.y << endl;
	cout << "Rightmost: " << rmax.x << ' ' << rmax.y << endl;

	return 0;
}
