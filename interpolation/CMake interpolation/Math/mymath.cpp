#include <cmath>
#include <iostream>
#include <vector>
#include "mymath.h"

void print(std::vector <std::vector<double>> leftMartix, std::vector <double> rightVector)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << leftMartix[i][j] << '\t';
		}
		std::cout << rightVector[i] << '\t' << std::endl;
	}
	std::cout << std::endl;
}
void  Gauss(std::vector <std::vector<double>> leftMartix, std::vector <double> & rightVector)
{
	// прямой ход
	for (int i = 0; i < 4; i++)
	{
		double  normal = leftMartix[i][i];
		rightVector[i] /= normal;
		for (int j = i; j < 4; j++)
		{
			leftMartix[i][j] /= normal;
		}
		for (int k = i+1; k < 4; k++)
		{
			double tmp = leftMartix[k][i];
			rightVector[k] -= tmp * rightVector[i];
			for (int j = i; j < 4; j++)
			{
				leftMartix[k][j] -= tmp * leftMartix[i][j];
			}
		}
	}
	// обратный ход
	for (int i = 3; i > 0; i--)
	{
		for(int k = i - 1; k >= 0; k--)
		{
			rightVector[k] -= leftMartix[k][i] * rightVector[i];
		    leftMartix[k][i] -= leftMartix[k][i] * leftMartix[i][i];
		}
	}

	print(leftMartix, rightVector);
	return ;
}


std::vector <double> interpolate(double z0, double z1, double z0_, double z1_, double t0 , double t1) 
{
	// interpolate z(t) with coordinates and derivatives in t0 and t1
	// return coeffients a,b,c,d  of z(t) = at^3 + bt^2 + ct + d

	std::vector <std::vector<double>> leftMartix (4 , std::vector<double> (4));

	leftMartix[0][0] = pow(t0, 3); leftMartix[0][1] = pow(t0, 2); leftMartix[0][2] = t0; leftMartix[0][3] = 1;
	leftMartix[1][0] = pow(t1, 3); leftMartix[1][1] = pow(t1, 2); leftMartix[1][2] = t1; leftMartix[1][3] = 1;
	leftMartix[2][0] = 3 * pow(t0, 2); leftMartix[2][1] = 2 * t0; leftMartix[2][2] = 1; leftMartix[2][3] = 0;
	leftMartix[3][0] = 3 * pow(t1, 2); leftMartix[3][1] = 2 * t1; leftMartix[3][2] = 1; leftMartix[3][3] = 0;

	std::vector <double> rightVector = {
		z0,
		z1,
		z0_,
		z1_
	};

	Gauss(leftMartix, rightVector);
	return rightVector;

}