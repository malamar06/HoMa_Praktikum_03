#include "C_DGLSolver.h"
#include <vector>
#include <assert.h>


C_DGLSolver::C_DGLSolver (double (*f_DGL_System)(double y, double x))//hoehere ordnung weil return von eingabefunktion vektor ist
{
	hoehereOrdnung = false;
	funk = f_DGL_System;
}

C_DGLSolver::C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x))
{
	hoehereOrdnung = true;
	funkhochord = f_DGL_nterOrdnung;
}

void C_DGLSolver::eulerVerfarhren_HOCH(CMyVektor y, double x, double h, int schritt)
{
	double x_aktuel = x;
	std::vector<std::vector<double>> database;
	int dimension = y.get_dim();
	assert(dimension > 1);
	std::vector<double> transporter;
	transporter.push_back(x);
	for (int i = 0; i < dimension; i++)
	{
		transporter.push_back(y[i]);
	}
	database.push_back(transporter);//first line saved database[0]


	std::cout << "===================== Schritt 0 =====================" << std::endl;
	std::cout << "h = " << h << std::endl << "x = " << x << std::endl;
	for (int i = 0; i < dimension; i++)
	{
		std::cout << "Y" << i << " = " << transporter[i + 1] << std::endl;
	}	
	


	for (int q = 0; q < schritt; q++)//mutter schleife
	{
		transporter.clear();
		x_aktuel += h;
		transporter.push_back(x_aktuel);

		for (int i = 0; i < dimension ; i++)//weil letzte wert durch funktion berechnet wird.
		{
			CMyVektor kuchen;

			if (i < dimension -1)
			{
				transporter.push_back(database[q][i + 1] + h * database[q][i + 2]);//hier ist f(x+h) = f(x) + h * f'(x)
			}
			else
			{
				for (int j = 0; j < dimension; j++)
				{
					kuchen.manual_push(database[q][j + 1]);
				}
				transporter.push_back(database[q][i + 1] + h * funkhochord(kuchen, database[q][0]));
			}
		}
		
		database.push_back(transporter);



		std::cout << "===================== Schritt " << q + 1 << " =====================" << std::endl;
		std::cout << "x" << " = " << transporter[0] << std::endl;
		for (int i = 0; i < dimension; i++)
		{
			std::cout << "Y" << i << " = " << transporter[i + 1] << std::endl;
		}

	}
}

void C_DGLSolver::heunVerfarhren_HOCH(CMyVektor y, double x, double h, int schritt)
{
	std::vector<double> test_schritt;
	double x_aktuel = x;
	std::vector<std::vector<double>> database;
	int dimension = y.get_dim();
	assert(dimension > 1);
	std::vector<double> transporter;
	transporter.push_back(x);
	for (int i = 0; i < dimension; i++)
	{
		transporter.push_back(y[i]);
	}
	database.push_back(transporter);//first line saved database[0]


	std::cout << "===================== Schritt 0 =====================" << std::endl;
	std::cout << "h = " << h << std::endl << "x = " << x << std::endl;
	for (int i = 0; i < dimension; i++)
	{
		std::cout << "Y" << i << " = " << transporter[i + 1] << std::endl;
	}



	for (int q = 0; q < schritt; q++)//mutter schleife
	{
		x_aktuel += h;

		transporter.clear();
		transporter.push_back(x_aktuel);
		
		test_schritt.clear();
		test_schritt.push_back(x_aktuel);

		for (int i = 0; i < dimension; i++)//weil der letzte wert durch funktion berechnet wird.
		{
			CMyVektor kuchen;
			
			
			if (i < dimension - 1)
			{
				test_schritt.push_back(database[q][i + 1] + h * database[q][i + 2]);//hier ist f(x+h) = f(x) + h * f'(x)
			}
			else
			{
				for (int j = 0; j < dimension; j++)
				{
					kuchen.manual_push(database[q][j + 1]);
				}

				test_schritt.push_back(database[q][i + 1] + h * funkhochord(kuchen, database[q][0]));
			}
		}

		for (int i = 0; i < dimension; i++)//Heun Schleife
		{
			CMyVektor kuchen;
			CMyVektor kuchen1;

			if (i < dimension - 1)
			{
				transporter.push_back(database[q][i + 1] + h * 0.5 * (database[q][i + 2] + test_schritt[i +2]));//hier ist f(x+h) = f(x) + h * 0.5(f'(x) + f'(x+h))
			}
			else
			{
				for (int j = 0; j < dimension; j++)
				{
					kuchen.manual_push(database[q][j + 1]);
				}
				for (int j = 0; j < dimension; j++)
				{
					kuchen1.manual_push(test_schritt[j + 1]);
				}

				transporter.push_back(database[q][i + 1] + h * 0.5 * (funkhochord(kuchen, database[q][0] + funkhochord(kuchen1, test_schritt[0]))));
			}
		}
		database.push_back(transporter);


		std::cout << "===================== Schritt " << q + 1 << " =====================" << std::endl;
		std::cout << "x" << " = " << transporter[0] << std::endl;
		for (int i = 0; i < dimension; i++)
		{
			std::cout << "Y" << i << " = " << transporter[i + 1] << std::endl;
		}

	}
}

void C_DGLSolver::eulerVerfarhren(CMyVektor y, double x, double h, int schritt)
{
	double y_neu;
	double y_aktuel = y[0];

	//give info
	std::cout << "Euler Verfahren Y = " << y_aktuel << " X = " << x << " h = " << h << " fuhren fur " << schritt << " Schritte." << std::endl;

	for (int i = 0; i < schritt; i++)
	{

		std::cout << "======================= Schritt " << i + 1 << " =======================" << std::endl;
		y_neu = y_aktuel + h * funk(y_aktuel, x);
		x += h;
		std::cout << "X = " << x << std::endl;
		std::cout << "Y = " << y_neu << std::endl;
		std::cout << "Y' = " << funk(y_neu, x) << std::endl;
		y_aktuel = y_neu;

	}
}

void C_DGLSolver::heunVerfahren(CMyVektor y, double x, double h, int schritt)
{

	double y_aktuel = y[0];
	double y_neu;
	double y_result;
	//give info
	std::cout << "Euler Verfahren Y = " << y_aktuel << " X = " << x << " h = " << h << " fuhren fur " << schritt << " Schritte." << std::endl;

	for (int i = 0; i < schritt; i++)
	{

		std::cout << "======================= Schritt " << i + 1 << " =======================" << std::endl;
		y_neu = y_aktuel + h * funk(y_aktuel, x);
		y_result = y_aktuel + h * 0.5 * (funk(y_aktuel, x) + funk(y_neu, x));
		x += h;
		std::cout << "X = " << x << std::endl;
		std::cout << "Y = " << y_result << std::endl;
		std::cout << "Y' = " << funk(y_result, x) << std::endl;
		y_aktuel = y_result;

	}
}
