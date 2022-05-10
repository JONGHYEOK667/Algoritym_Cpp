#include <iostream>
#include "math.h"

using namespace std;


/*
	namespace »ç¿ë¹ý
*/
namespace mySpace1
{
	namespace innerSpace
	{
		int doSomething(int a, int b)
		{
			return a  + b;
		}
	}

	int doSomething(int a, int b)
	{
		return a + b + b;
	}

}

namespace mySpace2
{
	int doSomething(int a, int b)
	{
		return a + b + b + a;
	}

}

int main()
{

	int x = 3;
	int y = 1;


	
	cout << "add         : " << addTwoNumbers(x, y) << endl;
	cout << "product     : " << productTwoNumbers(x, y) << endl;
	cout << "subtract    : " << subtractTwoNumbers(x, y) << endl;


	cout << "doSomething : " << mySpace1::doSomething(x, y) << endl;
	cout << "doSomething : " << mySpace2::doSomething(x, y) << endl;
	cout << "doSomething : " << mySpace1::innerSpace::doSomething(x, y) << endl;

	return 0;

}
