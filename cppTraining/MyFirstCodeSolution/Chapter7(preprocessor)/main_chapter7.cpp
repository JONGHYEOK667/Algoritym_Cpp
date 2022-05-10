#include <iostream>

using namespace std;


/*
	define
	코드 내 define으로 정의한 부분을 자동적으로 실행 (macro) 
	매크로 값 변경하면 다시빌드함
*/
#define	MY_NUMBER 9
#define	MY_WORD "Hello"
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define LIKE_APPLE

int main()
{
	cout << MY_NUMBER << endl;
	cout << MY_WORD << endl;
	cout << MAX(-1,2) << endl;



#ifdef LIKE_APPLE

	cout << "Apple" << endl;

#endif // LIKE_APPLE


#ifndef LIKE_APPLE

	cout << "Orange" << endl;

#endif // LIKE_APPLE
}