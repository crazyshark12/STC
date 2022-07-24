#pragma once
#include <vector>
void print(std::vector <std::vector<double>> leftMartix, std::vector <double> rightVector);
void  Gauss(std::vector <std::vector<double>> leftMartix, std::vector <double>& rightVector);
std::vector <double> interpolate(double z0, double z1, double z0_, double z1_, double t0, double t1);