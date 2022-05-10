#include <iostream>

using namespace std;


/*
	addTwoNumbers(int num_a, int num_b)에는 
	정수형 num_a, 정수형 num_b 라는 각각의 매개변수가 있다.
	호출자는 num_a, num_b값을 전달해야 한다.
*/
int addTwoNumbers(int num_a, int num_b)
{
	int sum = num_a + num_b;
	
	return sum;
}

/*
	productTwoNumbers(int num_a, int num_b)에는
	정수형 num_a, 정수형 num_b 라는 각각의 매개변수가 있다.
	호출자는 num_a, num_b값을 전달해야 한다.
*/
int productTwoNumbers(int num_a, int num_b)
{
	int product = num_a * num_b;

	return product;
}

/*
	함수 전방선언 (forward declaration)
	: main 함수 위단에 함수들이 너무 많으면 보기어려움, 그렇다고 해서 함수를 main 뒤로 빼면 실제 main문 수행 시
	  함수 정의가 되어있지않아 작동이 되지 않음
	  -> 함수의 기본형 (Prototype)만 미리 선언해 두고 main 함수 뒤에 함수정의를 이동
*/
int subtractTwoNumbers(int num_a, int num_b); // forward declaration



/*
	printHelloWorld() 의 경우,
	매개변수가 없다.
	호출자는 아무것도 전달하지 않아도 된다.
*/
void printHelloWorld() // Return이 필요없음
{
	cout << "Hello World" << endl;

}

// 함수 재사용 
int getValueFromUser()
{
	std::cout << "Enter Int Value : ";
	int a;
	std::cin >> a;
	return a;

}



int main()
{

	int x = 1;
	int y = 2;

	cout << x + y << endl;
	
	/*
		addTwoNumbers(x, y), productTwoNumbers(x, y) 의 경우,
		함수 선언시 정의된 매개변수에 대한 인수 (x, y)값을 전달한다. 
	*/
	cout << addTwoNumbers(x, y) << endl;
	cout << productTwoNumbers(x, y) << endl;
	cout << subtractTwoNumbers(x, y) << endl;

	/*
		printHelloWorld()
		함수 선언시 정의된 매개변수가 없어 어떤 인수값도 필요없다.
	*/
	printHelloWorld();

	// 함수 재사용을 통한 기능실행
	int a(getValueFromUser());  // 첫번째 실행
	int b(getValueFromUser());  // 두번째 실행

	std::cout << a << "+" << b << "=" << a + b << std::endl;




	return 0;
	
}


int subtractTwoNumbers(int num_a, int num_b) // definition
{
	int subtract = num_a - num_b;

	return subtract;
}