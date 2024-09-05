#ifndef POLY2_H
#define POLY2_H

class Poly2
{
	float a, b, c;

public:

    /*
     * Constructor
     */
	Poly2(float a, float b, float c);

    /*
     * Evaluate y(x)
     */
	float eval(float x);

    /*
     * Find roots, i.e. x when y(x) = 0
     */
	void findRoots();

    /*
    *  Return the roots of a polynomial equation y(x)
    */
   std::tuple<float,float> getRoots();

    
    /*
     * Destructor:
     * not needed since no dynamic memory has been allocated,
     */
};

class Printer
{

public:
    /*
    * Print roots of a polynomial equation y(x)
    */
   void printRoots(float a, float b, float c);

    /*
    * Evaluate and print the value of y(x) for an inputted x 
    */
   void evaluate(float a, float b, float c);
};


#endif