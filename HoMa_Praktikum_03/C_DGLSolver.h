#pragma once
#include "CMyVektor.h"


class C_DGLSolver
{
private:
	bool hoehereOrdnung;
	double (*funk)(double y, double x) = nullptr;
	double (*funkhochord)(CMyVektor y, double x) = nullptr;
	CMyVektor (*funkvektor)(CMyVektor y, double x) = nullptr;

public:

	C_DGLSolver(double (*f_DGL_System)(double y, double x));
	C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x));
	C_DGLSolver(CMyVektor (*f_DGL_System)(CMyVektor y, double x));

	void eulerVerfarhren(CMyVektor y, double x, double h, int schritt);
	void eulerVerfarhren_HOCH(CMyVektor y, double x, double h, int schritt);
	void heunVerfahren(CMyVektor y, double x, double h, int schritt);
	void heunVerfarhren_HOCH(CMyVektor y, double x, double h, int schritt);
	void heunVerfahren_vectorf(CMyVektor y, double x, double h, int schritt);
	void eulerVerfahren_vectorf(CMyVektor y, double x, double h, int schritt);
};
