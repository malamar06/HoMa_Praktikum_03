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


int main()
{
	CMyVektor testvektor(2);
	C_DGLSolver malamar(testFunkDGL1);
	malamar.eulerVerfarhren(testvektor, 1, 0.5, 10);

	return 0;
}