#pragma once

struct bezier_functions
{
	static void* CreateBezierCurve(const char* dots);
	static const char* PolyLine(void* crv);
	/*static void* SetCurvature(void* crv, double t, double curvature);
	static double GetCurvature(void* crv, double t);*/
};

