
#include <iostream>
#include "beziercurve.h"
#include "bridge.h"


void console_app()
{
    const int n = 4;
    double delta = 0.01;
    int k = 0;
    Point temp;
    std::vector<Point> ttemp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp.x >> temp.y;
        ttemp.push_back(temp);
    }

    BezierCurve bezier_coordinats(ttemp);
    std::cout << "\n";

    ttemp = bezier_coordinats.GetPolyLine(delta);
    double curv;


    for (double t = 0; t < 1; t += delta)
    {
        curv = bezier_coordinats.GetCurvature(t);

        std::cout << ttemp[k].x << " " << ttemp[k].y << " curvature = " << curv << "\n";
        k++;
    }
}

int main()
{
    std::string s = "-100 -70 -80 50 80 -50 100 70";
    const char* test = s.c_str();

    const char* c = bezier_functions::PolyLine(bezier_functions::CreateBezierCurve(test));

    std::cout << c;

    console_app();

}