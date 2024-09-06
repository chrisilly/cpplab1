#include <iostream>
#include "poly2.h"
#include "constants.h"
#include <tuple>

using namespace std;

int main(int argc, const char* argv[])
{
	Program printer;

    float a=1, b=2, c=1;

	bool evaluateX = false;
	float toggleEvaluateX = 0;
	string lineBreaker = "-----------------------------------------------------";
	// bool debugCodeEntered = (a == 0 && b == 0 && c == 0);
	
	std::cout << lineBreaker << endl;
	std::cout << "Enter three coefficients for a polynomial, one coefficient at a time." << endl;
	std::cout << "Alternatively, enter \'0\' for all coefficients to toggle evaluation for y(x) (given an inputted x) after routine." << endl;
	std::cout << lineBreaker << endl;

	// Get test-case coefficients
	while(std::cin >> a >> b >> c)
	{
		std::cout << lineBreaker << endl;

		if(printer.debugCodeEntered(a, b, c))
		{
			evaluateX = !evaluateX;
			std::cout << "y(x) for inputted x routine toggled." << endl;
		}
		else
			// Print roots
			printer.printRoots(a, b, c);

		if(evaluateX && !printer.debugCodeEntered(a, b, c))
			printer.evaluate(a, b, c);
		
		std::cout << lineBreaker << endl;
		std::cout << "Enter three coefficients for a polynomial, one coefficient at a time." << endl;
		std::cout << "Alternatively, enter \'0\' for all coefficients to toggle evaluation for y(x) (given an inputted x) after routine." << endl;
		std::cout << lineBreaker << endl;
	}


	// Print the y-value for a given x
	// printer.evaluate(a, b, c);
    
	return 0;
}

bool Program::debugCodeEntered(float a, float b, float c)
{
	return (a == 0 && b == 0 && c == 0);
}

/// @brief Get and print the roots of a polynomial equation, given the coefficients
void Program::printRoots(float a, float b, float c)
{
	Poly2 rootfinder(a, b, c);
	std::cout << "Coefficients selected:" << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;

	std::cout << "Root-finding started..." << std::endl;
	
	// rootfinder.findRoots();

	// float root1 = std::get<0>(roots);
	// float root2 = std::get<1>(roots);
	float root1 = rootless;
	float root2 = rootless;
	rootfinder.getRoots(root1, root2);

	// std::tuple<float,float> roots = rootfinder.getRoots();

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
void Program::evaluate(float a, float b, float c)
{
	float x = 0;
	Poly2 evaluator(a, b, c);
	std::cout << "Enter arbitrary x value: ";
	std::cin >> x;
	std::cout << "Evaluating y-value for x-value " << x << endl;
	std::cout << "The value of y(" << x << ") = " << evaluator.eval(x) << endl;
}
