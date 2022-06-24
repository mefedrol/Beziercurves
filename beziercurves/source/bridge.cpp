#include "beziercurve.h"
#include "bridge.h"
#include <string>


//----------------------------------------------------------------------------------------
// разделение строки
// ---  
std::vector<std::string> split(std::string s, std::string delimiter = " ")
{
    std::vector<std::string> div_str;
    size_t start = 0;
    size_t end = s.find(delimiter);
    while (end != std::string::npos)
    {
        if ((end - start > 1) || (start == 0))
        {
            div_str.push_back(s.substr(start, end-start));
        }
        start = end;
        end = s.find(delimiter, start+1);      
    }
    if (s.length() - start > 1)
    {
        div_str.push_back(s.substr(start));
    }
    return div_str;
}


//----------------------------------------------------------------------------------------
// Получение указателя на кривую Безье
// ---
void* bezier_functions::CreateBezierCurve(const char* dots)
{
    std::string str = dots;
    std::vector<std::string> div_str = split(str);
    if (div_str.size() % 2 == 0)
    {
        std::vector<Point> control_dots;
        for (int i = 0; i <= div_str.size() - 1; i += 2)
        {
            control_dots.emplace_back(atof(div_str[i].c_str()), atof(div_str[i + 1].c_str()));
        }
        return new BezierCurve(control_dots);
    }
    return nullptr;
}



//----------------------------------------------------------------------------------------
// получение точек кривой по ее указателю
// ---
const char* bezier_functions::PolyLine(void* pntr)
{
    const double delta = 0.01;
	BezierCurve* Bezier = static_cast<BezierCurve*>(pntr);
    std::vector<Point> dots = Bezier->GetPolyLine(delta);
    std::string* str = new std::string("");
    for (int i = 0; i < dots.size(); i++)
    {
        if (dots.size() - i > 1)
            *str += std::to_string(dots[i].x) + " " + std::to_string(dots[i].y) + " ";
        else 
            *str += std::to_string(dots[i].x) + " " + std::to_string(dots[i].y);
    }
    
    const char* a = str->c_str();

    return a;
}

