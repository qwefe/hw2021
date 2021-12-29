#include <iostream>
#include <cmath>

#include <fstream>
#include <vector>
using namespace std;

struct Wall
{
    double x;
    double h;
};

int main(int argc, char** argv)
{
    if (argc == 2) {

        double x, h, H, vx, vy;
        vector<Wall> walls;
        ifstream in(argv[1]);
        in >> h;
        in >> vx >> vy;
        walls.push_back(Wall{0,0});
        while (in >> x >> H)
        {
            Wall w{ x, H };
            walls.push_back(w);
        }

        const double g = 9.81;
        double fallpoint;

        bool right = true;
        bool fallen = false;
        bool hit = false;
        int last = 0;
        while (!fallen)
        {
            if (right)
            {
                for (int i = last + 1; i < walls.size(); i++)
                {
                    if (!hit)
                    {
                        double v0 = vx * vx + vy * vy;
                        double tan = vy / vx;
                        double x0 = walls[last].x;
                        double x = walls[i].x;

                        double H = h + (x - x0) * tan - (g * (x - x0) * (x - x0)) / (2 * v0) * (tan * tan + 1);
                        
                        if (H <= walls[i].h && H >= 0)
                        {
                            hit = true;
                            right = !right;
                            h = H;
                            vy = vy - g *(walls[i].x - walls[last].x) / vx;
                            vx = -vx;
                            last = i;
                        }
                    }

                }
            }
            else {
                for (int i = last - 1; i >= 1; i--)
                {
                    if (!hit)
                    {
                        double v0 = vx * vx + vy * vy;
                        double tan = vy / vx;
                        double x0 = walls[last].x;
                        double x = walls[i].x;
                        double H = h + (x - x0) * tan - (g * (x - x0) * (x - x0)) / (2 * v0) * (tan * tan + 1);

                        if (H <= walls[i].h && H >= 0)
                        {
                            hit = true;
                            right = !right;
                            h = H;
                            vy = vy - g * (walls[i].x - walls[last].x) / vx;
                            vx = -vx;
                            last = i;
                        }
                    }
                }
            }
            if (!hit)
            {
                fallen = true;
                double v0 = vx * vx + vy * vy;
                double tan = vy / vx;
                double a = -g / (2 * v0) * (tan * tan + 1);
                double b = tan;
                double c = h;
                double m = walls[last].x;
                double D = sqrt(b * b - 4 * a * c);
                if (right)
                    fallpoint = (-b - D) / (2 * a) + m;
                else
                    fallpoint = (-b + D) / (2 * a) + m;

            }
            else hit = false;
        }
        //cout << fallpoint << endl;
        
        for (int i = 0; i < walls.size() - 1; i++)
            if (fallpoint > walls[i].x && fallpoint < walls[i + 1].x)
            {
                cout << i << endl;
            }
        if (fallpoint > walls[walls.size() - 1].x) cout << walls.size() - 1 << endl;
        if (fallpoint <= 0) cout << 0 << endl;

        return 0;
    }
    else
    {
        return 1;
    }
}
