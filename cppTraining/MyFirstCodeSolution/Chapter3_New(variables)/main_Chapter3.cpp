#include <iostream>


void doSomething(int a) 
{
	a = 123; // 함수 doSomething 영역을 기준으로 다른 영역내 변수이기 때문에 다른 변수임 다른 메모리를 가짐
	
	std::cout << "a value   : " << a << std::endl;
	std::cout << "a address : " << &a << std::endl;

}

int main()
{

	std::cout << "this is chapter3 main function" << std::endl;



	int x; 
	x = 123; // 변수 할당
	std::cout << x << std::endl;  // 변수 할당 값 
	std::cout << &x << std::endl;  // 변수가 가지는 주소


	/*
		l - value VS r - value
	
	l-value : 왼편에 있는 값, 메모리에 주소를 가지고 있는 값, 표현식 이후에도 없어지지 않는 값
	r-value : 오른편에 있는 값, 메모리에 주소를 가지고 있지 않은 값, 표현식 작동 후 사라짐


	*/ 

	int y; // y를 정수 변수로 정의한다.
	y = 4; // 4(r-value)는 4로 평가되고, y(l-value)에 할당된다.
	y = 2 + 5; // 2(r-value)+5(r-value)는 7로 평가되어지고, y(l-value)에 할당된다. \

	x = y; // y(l-value)는 7(r-value)로 평가되어지고, x(l-value)에 할당된다.
	x = x + 1; // x(l-value)+1(r-value)은 8(r-value)로 평가되어지고, x(l-value)에 할당된다.


	
	/*	Debug VS Release 
	
	Debug 빌드된 실행파일의 경우,  프로그램 디버그정보를 포함 용량이 큼
	Release 모드의 경우, 개발한 프로그램을 실제 배포할때 필요함. 속도도 빠름

	*/
	



	/* 변수의 지역범위 */
	int a(0);
	// int a(1);  동일 영역에서 같은 변수 중복 선언해서 불가능함

	std::cout <<"a value   : " << a << std::endl;
	std::cout <<"a address : " << &a << std::endl;


	{
		int a(1); // 중괄호{} 영역을 기준으로 다른 영역내 변수이기 때문에 다른 변수임 다른 메모리를 가짐
		std::cout << "a value   : " << a << std::endl;
		std::cout << "a address : " << &a << std::endl;
	}

	// 지역변수는 해당 영역을 벗어나면 사용할 수 없음
	std::cout << "a value   : " << a << std::endl;
	std::cout << "a address : " << &a << std::endl;

	doSomething(a);

	// 지역변수는 해당 영역을 벗어나면 사용할 수 없음
	std::cout << "a value   : " << a << std::endl;
	std::cout << "a address : " << &a << std::endl;






	return 0;
}