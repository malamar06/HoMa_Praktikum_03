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

CMyVektor testFunkDGL5(CMyVektor y, double x)//Hunter, prey funktion.
{											 //Y1' = 2Y2 - XY1;
	assert(y.get_dim() == 2);				 //Y2' = Y1Y2 - 2X^3

	CMyVektor rErgebnis;
	double erste = 2 * y[1] - x * y[0];
	double zweite = y[0] * y[1] - 2 * x * x * x;
	rErgebnis.manual_push(erste);
	rErgebnis.manual_push(zweite);
	return rErgebnis;
}

int main()
{

	CMyVektor testvektor(0, 1);
	testFunkDGL5(testvektor, 0).print();
	C_DGLSolver malamar(testFunkDGL5);
	malamar.heunVerfahren_vectorf(testvektor, 0, 0.02, 100);

	/*
			//aufgabe 4 - 2
	CMyVektor testvektor(1, -1, 2);
	C_DGLSolver malamar(testFunkDGL3);
	malamar.eulerVerfarhren_HOCH(testvektor, 1, 0.0001, 10000);
	*/

	/*
	CMyVektor testvektor(-2, 1, 1);
	C_DGLSolver malamar(testFunkDGL2);
	malamar.heunVerfarhren_HOCH(testvektor, 1, 0.1, 10);
	*/


	/*
	C_DGLSolver malamar(testFunkDGL1);
	CMyVektor testv1(2);
	malamar.eulerVerfarhren(testv1, 1, 0.5, 100);
	*/

	/*
	C_DGLSolver malamar(testFunkDGL1);
	CMyVektor testv1(2);
	malamar.heunVerfahren(testv1, 1, 0.1, 100);
	*/

	/*
	CMyVektor testvektor1(1, 2);
	C_DGLSolver malamar1(testFunkDGL4);
	malamar1.eulerVerfarhren_HOCH(testvektor1, 1, 0.1, 90);
	*/
	return 0;
}