#include <iostream>

using namespace std;

int value;
int sum;

int main(int argc, const char* argv[])
{
    sum = 0;

    while(std::cin >> value)
    {
        std::cout << "+";
        std::cout << value << endl;
        sum += value;
    }

    std::cout << "= ";
    std::cout << sum << endl;
}