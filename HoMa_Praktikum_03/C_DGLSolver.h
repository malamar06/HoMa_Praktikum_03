#pragma once
#include "CMyVektor.h"

class C_DGLSolver
{
private:
	bool hoehereOrdnung;
	CMyVektor (*funk)(CMyVektor y, double x) = nullptr;
	double (*funkhochord)(CMyVektor y, double x) = nullptr;
	CMyVektor ableitungen(CMyVektor y, double x)
	{
		 
		if (hoehereOrdnung)
		{
			CMyVektor rErgebnis(funkhochord(y, x), x);
			return rErgebnis;
		}
		else
		{
			CMyVektor rErgebnis(funkhochord(y, x), x);
			return rErgebnis;
		}
	}
public:
	C_DGLSolver(CMyVektor (*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x));

};
