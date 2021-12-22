#include <iostream> // cout, cin, endl, ...
#include <cstdio> // printf

int main()
{
	std::cout << "this is chapter4 main function" << std::endl;

	int x = 1024;
	double pi = 3.141592;

	std::cout << "I love this lecture!" << "\n"; // << std::endl;
	std::cout << "x is " << x << "pi is " << pi << std::endl;

	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	using namespace std;

	cout << "abc" << "\t" << "def" << endl;
	cout << "\a"; //alarm 

	int a = 1;

	cout << "Before your input, a was " << a << endl;

	cin >> a;

	cout << "Your input is " << a << endl;

	return 0;

}