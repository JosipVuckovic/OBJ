// Vjezba_LAB1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	double unos;
	std::cin >> unos;
	std::cout << std::setprecision(2) << std::scientific << unos;
	return 0;
}

