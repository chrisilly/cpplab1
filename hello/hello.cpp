#include <iostream>

int main(int argc, const char* argv[])
{
	std::cout << "Hello World! ";

	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i];
		std::cout << " ";
	}

	return 0;
}