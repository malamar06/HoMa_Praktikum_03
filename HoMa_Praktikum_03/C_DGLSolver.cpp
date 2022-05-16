#include "C_DGLSolver.h"



C_DGLSolver::C_DGLSolver (CMyVektor(*f_DGL_System)(CMyVektor y, double x))
{
	hoehereOrdnung = false;
	funk = f_DGL_System;
}

C_DGLSolver::C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x))
{
	hoehereOrdnung = true;
	funkhochord = f_DGL_nterOrdnung;
}

