#include <iostream>
#include "poly2.h"
#include <cmath>
#include "constants.h"
#include <tuple>

using namespace std;

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
	return (a * x * x) + (b * x) + c;
}

/// @brief 
/// @return Roots of a polynomial equation. If no real root exists, returns external constant float "rootless"
std::tuple<float,float> Poly2::getRoots()
{
	float root1;
	float root2;

	float d = sqrt((b*b) - 4 * a * c);

	if(d > 0)
	{
		root1 = (d-b)/(2*a);
		root2 = (-d-b)/(2*a);
		return std::make_tuple(root1,root2);
	}
	else if(d == 0)
	{
		root1 = (-b)/(2*a);
		return std::make_tuple(root1,rootless);
	}

	return std::make_tuple(rootless,rootless);
}

void Poly2::findRoots()
{
    float root1;
	float root2;
    
	float d = sqrt((b*b) - 4 * a * c);

	if(d > 0)
	{
		root1 = (d-b)/(2*a);
		root2 = (-d-b)/(2*a);

		std::cout << "Two roots were found: ";
		std::cout << root1 << ", " << root2 << endl;
	}
	else if(d == 0)
	{
		root1 = (-b)/(2*a);
		std::cout << "One root was found: ";
		std::cout << root1 << endl;
	}
	else
	{
		std::cout << "Unable to find any real roots." << endl;
	}
}