#pragma once
#include "CMyVektor.h"
#include <iostream>
class C_DGLSolver
{
private:
	bool hoehereOrdnung;
	double (*funk)(double y, double x) = nullptr;
	double (*funkhochord)(CMyVektor y, double x) = nullptr;

	/*
	CMyVektor ableitungen(CMyVektor y, double x)
	{//diese ableitung funktion von Praktikum Aufgabe verstehe ich nicht so klar
	 //Meiner Meinung kann man das inline schaffen und weare es schoner aussehen
	 //ich sehe den Grund dafur nicht. Ich lasse diese so weahrend ich den Rest des Praktikums schreibe.
	 
		if (hoehereOrdnung)
		{
			CMyVektor rErgebnis(funkhochord(y, x), x);//Ableitung am x position
			//std::cout << "Hoeher ordnung funktions Ableitung ist: " << rErgebnis[0] << ", " << rErgebnis[0] << std::endl;
			return rErgebnis;
		}
		else
		{
			CMyVektor rErgebnis(funkhochord(y, x), x);//Ableitung am x position
			//std::cout << "Normal ordnung funktions Ableitung ist: " << rErgebnis[0] << ", " << rErgebnis[0] << std::endl;
			return rErgebnis;
		}
	}*/
public:

	C_DGLSolver(double (*f_DGL_System)(double y, double x));
	C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x));
	void eulerVerfarhren(CMyVektor y, double x, double h, int schritt);
	void eulerVerfarhren_HOCH(CMyVektor y, double x, double h, int schritt);
	void heunVerfahren(CMyVektor y, double x, double h, int schritt);
	void heunVerfarhren_HOCH(CMyVektor y, double x, double h, int schritt);



};
