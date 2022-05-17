#include <iostream>
#include "CMyVektor.h"
#include <assert.h>
#include "C_DGLSolver.h"
using namespace std;

double testFunkDGL2(CMyVektor y, double x)// y''' = 2xy^4y' + x^3y'y'';
{
	assert(y.get_dim() == 3);
	double rErgebnis = 0;
	rErgebnis += 2 * x * y[0] * y[0] * y[0] * y[0] * y[1];
	rErgebnis += x * x * x * y[1] * y[2];
	return rErgebnis;
}

double testFunkDGL1(double y, double x)//y'= -2x + 4y + 4
{
	double rErgebnis = 0;
	rErgebnis += -2 * x;
	rErgebnis += 4 * y;
	rErgebnis += 4;
	return rErgebnis;
}

double testFunkDGL3(CMyVektor y, double x)//Aufgabe 4 funkt Y''' = 2xy'y'' + 2y^2y'
{
	assert(y.get_dim() == 3);
	double rErgebnis = 0;
	rErgebnis += 2 * x * y[1] * y[2];
	rErgebnis += 2 * y[0] * y[0] * y[1];
	return rErgebnis;
}

double testFunkDGL4(CMyVektor y, double x) // y'' = -4 * y' - 4y
{
	assert(y.get_dim() == 2);
	double rErgebnis = 0;
	rErgebnis += -4 * y[1];
	rErgebnis += -4 * y[0];
	return rErgebnis;
}

int main()
{


	/*
	//aufgabe 4 - 2
	CMyVektor testvektor(1, -1, 2);
	C_DGLSolver malamar(testFunkDGL3);
	malamar.eulerVerfarhren_HOCH(testvektor, 1, 0.1, 10);
	*/

	/*
	C_DGLSolver malamar(testFunkDGL1);
	CMyVektor testv1(2);
	malamar.eulerVerfarhren(testv1, 1, 0.5, 100);
	*/

	/*
	CMyVektor testvektor1(1, 2);
	C_DGLSolver malamar1(testFunkDGL4);
	malamar1.eulerVerfarhren_HOCH(testvektor1, 1, 0.1, 90);
	*/
	return 0;
}