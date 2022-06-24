#include "beziercurve.h"
#include <math.h>

//----------------------------------------------------------------------------------------
// ���������
// ---
int Factorial(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

//----------------------------------------------------------------------------------------
// �����������
// ---
BezierCurve::BezierCurve(std::vector<Point> dots) :control_dots(dots)
{
    control_dots.reserve(dots.size());
}


Point::Point(double _x, double _y): x(_x),y(_y)
{

}


//----------------------------------------------------------------------------------------
// ������������� ����������
// ---
double BinominalCoefficient(int n, int i)
{
    return Factorial(n) / (Factorial(i) * Factorial(n - i));
}


//----------------------------------------------------------------------------------------
// ����� ������� ������
// ---
double BezierCurve::GetBasis(int n, int i, double t)
{
    return BinominalCoefficient(n, i) * pow(t, i) * pow(1 - t, n - i);
}


//----------------------------------------------------------------------------------------
// ��������� ����� �� ������
// ---
Point BezierCurve::D0( double t)
{
    Point p{0,0};
    int n = control_dots.size();
    for (int i = 0; i < n; i++)
    {
        double basis = GetBasis(n-1, i, t);
        p.x += control_dots[i].x * basis;
        p.y += control_dots[i].y * basis;
    }

    return p;
}


//----------------------------------------------------------------------------------------
// ����������� ������� �������
// ---
Vector BezierCurve::D1(double t)
{
    Vector basis{ 0,0 };
    int n = control_dots.size();
    for (int i = 0; i < n-1; i++)
    {
        basis = basis + (control_dots[i + 1] - control_dots[i]) * GetBasis(n - 2, i, t);
    }
    basis = basis * (n-1);
    return basis;
}

//----------------------------------------------------------------------------------------
// ����������� ������� �������
// ---
Vector BezierCurve::D2(double t)
{
    Vector basis{ 0,0 };
    double temp;
    int n = control_dots.size();
    for (int i = 0; i < n-2; i++)
    {
        basis = basis + (control_dots[i + 2] - control_dots[i + 1]) - (control_dots[i + 1] - control_dots[i]) * GetBasis(n - 3, i, t);
    }
    basis = basis * (n-1) * (n-2);
    return basis;
}

//----------------------------------------------------------------------------------------
// ���������� � ������ ����� ������ �����
// ---
std::vector<Point>  BezierCurve::GetPolyLine(double delta)
{
    std::vector<Point> points_of_bezier;
    for (double t = 0; t < 1; t += delta)
    {
        points_of_bezier.push_back(D0(t));
    }
    return points_of_bezier;
}

//----------------------------------------------------------------------------------------
// ��������� ��������
// ---
double BezierCurve::GetCurvature(double t)
{
    return fabs(D1(t) | D2(t)) / (D1(t).Length() * D1(t).Length() * D1(t).Length());
}

//----------------------------------------------------------------------------------------
// ��������� ��������
// ---
std::vector<Point> BezierCurve::SetCurvature(double t, double curv)
{
    return BezierCurve::GetPolyLine(t);
}

//----------------------------------------------------------------------------------------
// �������� �����
// ---
Vector Point::operator- (const Point& p) 
{
    Vector difference;
    difference.x = x - p.x;
    difference.y = y - p.y;
    return difference;
}    


//----------------------------------------------------------------------------------------
// ����� �����
// ---
Point  Point::operator+ (const Point& p)
{
    Point sum;
    sum.x = x + p.x;
    sum.y = y + p.y;
    return sum;
}

//----------------------------------------------------------------------------------------
//��������� ������������ ��������
// ---
double Vector::operator * (const Vector& v)
{
    return x * v.x + y * v.y;
}


//----------------------------------------------------------------------------------------
//��������� ������������ ��������
// ---
double Vector::operator | (const Vector& v)
{
    return x * v.y - y * v.x;
}


//----------------------------------------------------------------------------------------
//����� ��������
// ---
Vector Vector::operator + (const Vector& v)
{
    Vector sum;
    sum.x = x + v.x;
    sum.y = y + v.y;
    return sum;
}

//----------------------------------------------------------------------------------------
//�������� ��������
// ---
Vector Vector::operator - (const Vector& v)
{
    Vector difference;
    difference.x = x - v.x;
    difference.y = y - v.y;
    return difference;
}


//----------------------------------------------------------------------------------------
//���������������
// ---
Vector Vector::operator * (const double& d) 
{
    Vector v;
    v.x = x * d;
    v.y = y * d;
    return v;
}

//----------------------------------------------------------------------------------------
//��������� ������ �������
// ---
double Vector::Length()
{
    return sqrt(x * x + y * y);
}

;
