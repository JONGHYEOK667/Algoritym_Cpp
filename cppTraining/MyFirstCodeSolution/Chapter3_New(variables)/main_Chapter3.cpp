#include <iostream>

int main()
{

	std::cout << "this is chapter3 main function" << std::endl;


	int x = 123; // initialization
	int y(123); // initialization


	x = 5; // assignment
	//y = 6; // assignment

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	//std::cout << &x << std::endl;


	// Summary

	int a = 1;
	a = a + 2;
	std::cout << "a = " << a << std::endl; // #1

	int b = a;
	std::cout << "b = " << b << std::endl; // #2

	// is (a + b) l-value or r-value??
	std::cout << "a + b = " << a + b << std::endl; // #3

	std::cout << "a = " << a << std::endl; // #4

	int z(0);
	std::cout << "z = " << z << std::endl; // #5







	return 0;
}