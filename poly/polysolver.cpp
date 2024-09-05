#include <iostream>
#include "poly2.h"

int main(int argc, const char* argv[])
{
	std::cout << "Root-finding started..." << std::endl;

	// Make dynamic way to get coefficients. Pull from file?
    float a=1, b=2, c=1;
	float x=-1;

	// Logic & testing
	Poly2 polysolver(a, b, c);
	
	polysolver.findRoots();
	std::cout << "The value of y for x = " << x << ": " << polysolver.eval(x);
    
	return 0;
}
