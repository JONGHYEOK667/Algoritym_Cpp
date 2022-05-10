#include <iostream>


void doSomething(int a) 
{
	a = 123; // �Լ� doSomething ������ �������� �ٸ� ������ �����̱� ������ �ٸ� ������ �ٸ� �޸𸮸� ����
	
	std::cout << "a value   : " << a << std::endl;
	std::cout << "a address : " << &a << std::endl;

}

int main()
{

	std::cout << "this is chapter3 main function" << std::endl;



	int x; 
	x = 123; // ���� �Ҵ�
	std::cout << x << std::endl;  // ���� �Ҵ� �� 
	std::cout << &x << std::endl;  // ������ ������ �ּ�


	/*
		l - value VS r - value
	
	l-value : ���� �ִ� ��, �޸𸮿� �ּҸ� ������ �ִ� ��, ǥ���� ���Ŀ��� �������� �ʴ� ��
	r-value : ������ �ִ� ��, �޸𸮿� �ּҸ� ������ ���� ���� ��, ǥ���� �۵� �� �����


	*/ 

	int y; // y�� ���� ������ �����Ѵ�.
	y = 4; // 4(r-value)�� 4�� �򰡵ǰ�, y(l-value)�� �Ҵ�ȴ�.
	y = 2 + 5; // 2(r-value)+5(r-value)�� 7�� �򰡵Ǿ�����, y(l-value)�� �Ҵ�ȴ�. \

	x = y; // y(l-value)�� 7(r-value)�� �򰡵Ǿ�����, x(l-value)�� �Ҵ�ȴ�.
	x = x + 1; // x(l-value)+1(r-value)�� 8(r-value)�� �򰡵Ǿ�����, x(l-value)�� �Ҵ�ȴ�.


	
	/*	Debug VS Release 
	
	Debug ����� ���������� ���,  ���α׷� ����������� ���� �뷮�� ŭ
	Release ����� ���, ������ ���α׷��� ���� �����Ҷ� �ʿ���. �ӵ��� ����

	*/
	



	/* ������ �������� */
	int a(0);
	// int a(1);  ���� �������� ���� ���� �ߺ� �����ؼ� �Ұ�����

	std::cout <<"a value   : " << a << std::endl;
	std::cout <<"a address : " << &a << std::endl;


	{
		int a(1); // �߰�ȣ{} ������ �������� �ٸ� ������ �����̱� ������ �ٸ� ������ �ٸ� �޸𸮸� ����
		std::cout << "a value   : " << a << std::endl;
		std::cout << "a address : " << &a << std::endl;
	}

	// ���������� �ش� ������ ����� ����� �� ����
	std::cout << "a value   : " << a << std::endl;
	std::cout << "a address : " << &a << std::endl;

	doSomething(a);

	// ���������� �ش� ������ ����� ����� �� ����
	std::cout << "a value   : " << a << std::endl;
	std::cout << "a address : " << &a << std::endl;






	return 0;
}