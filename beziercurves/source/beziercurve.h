#include <iostream>
#include <math.h>
#include <vector>


struct Vector;

//----------------------------------------------------------------------------------------
// Точка
// ---
struct Point
{
    double x; //координата х 
    double y; //координата у
public:
    Point() = default;
    Point(double _x, double _y);

    Vector operator - (const Point& p);    //разность
    Point  operator + (const Point& p);    //сумма
};

//----------------------------------------------------------------------------------------
// Вектор
// ---
struct Vector
{
    double x; //начало вектора
    double y; //конец вектора
public:

    double             Length();            //получение длинны вектора

    double operator | (const Vector& v);    //векторное произведения
    double operator * (const Vector& v);    //скалярное произведения
    Vector operator + (const Vector& v);    //сумма
    Vector operator - (const Vector& v);    //разность
    Vector operator * (const double& d);    //масштабирование
};



//----------------------------------------------------------------------------------------
// Кривая Безье
// Класс позволяет создать кривую по заданным точкам, вычислить кривизну в выбранной точке на кривой и изменить кривизну на желаемую
// ---
class BezierCurve
{
private:
    std::vector<Point> control_dots;          //вектор контрольных точек
public:
    BezierCurve( std::vector<Point> );         //констуктор
    ~BezierCurve() = default;                  //деструктор

    Point               D0(double t);          //получение координат обрабатываемой точки
    Vector              D1(double t);          //получение первой производной
    Vector              D2(double t);          //получение второй производной
    double              GetCurvature(double);  //получение кривизны в заданной точке на кривой

    std::vector<Point>  GetPolyLine(double);   //получение массива точек кривой безье (равномерный шаг) //
    std::vector<Point>  SetCurvature(
        double t,
        double curvature
    );      //todo изменение кривизны

private:
//общая формула кривой
    double GetBasis(
        int    n,    //Размерность кривой
        int    i,    //Итератор
        double t);   //Параметр прохождения кривой
};



