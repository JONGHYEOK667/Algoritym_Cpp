#include <iostream>

using namespace std;


/*
	define
	�ڵ� �� define���� ������ �κ��� �ڵ������� ���� (macro) 
	��ũ�� �� �����ϸ� �ٽú�����
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