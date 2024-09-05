#include <iostream>
#include "poly2.h"
#include "constants.h"
#include <tuple>

using namespace std;

int main(int argc, const char* argv[])
{
	Printer printer;
    float a=1, b=2, c=1;
	
	// Get test-case coefficients
	std::cin >> a >> b >> c;

	// Print roots
	printer.printRoots(a, b, c);

	// Print the y-value for a given x
	printer.evaluate(a, b, c);
    
	return 0;
}

/// @brief Get and print the roots of a polynomial equation, given the coefficients
void Printer::printRoots(float a, float b, float c)
{
	Poly2 rootfinder(a, b, c);
	std::cout << "Coefficients selected:" << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;

	std::cout << "Root-finding started..." << std::endl;
	
	// rootfinder.findRoots();

	std::tuple<float,float> roots = rootfinder.getRoots();
	float root1 = std::get<0>(roots);
	float root2 = std::get<1>(roots);

	if(root1 == rootless)
	{
		std::cout << "Found no real roots." << endl;
	}
	else if (root2 == rootless)
	{
		std::cout << "Found one real root: " << root1 << endl;
	}
	else
	{
		std::cout << "Found two real roots: " << root1 << ", " << root2 << endl;
	}
}

/// @brief Print the y-value of a polynomial equation for given coefficients and inputted x 
void Printer::evaluate(float a, float b, float c)
{
	float x = 0;
	Poly2 evaluator(a, b, c);
	std::cout << "Enter arbitrary x value: ";
	std::cin >> x;
	std::cout << "Evaluating y-value for x-value " << x << endl;
	std::cout << "The value of y(" << x << ") = " << x << ": " << evaluator.eval(x);
}
