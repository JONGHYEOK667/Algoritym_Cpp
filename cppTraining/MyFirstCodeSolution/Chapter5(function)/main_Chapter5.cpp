#include <iostream>

using namespace std;

int addTwoNumbers(int num_a, int num_b)
{
	int sum = num_a + num_b;
	
	return sum;
}


int productTwoNumbers(int num_a, int num_b)
{
	int product = num_a * num_b;

	return product;
}

void printHelloWorld()
{
	cout << "Hello World" << endl;

	return;
}

int main()
{

	int x = 1;
	int y = 2;

	cout << x + y << endl;
	cout << addTwoNumbers(x, y) << endl;
	cout << productTwoNumbers(x, y) << endl;

	// using printHelloWorld function
	printHelloWorld();


	return 0;
	
}