#include <iostream>

using namespace std;


/*
	addTwoNumbers(int num_a, int num_b)���� 
	������ num_a, ������ num_b ��� ������ �Ű������� �ִ�.
	ȣ���ڴ� num_a, num_b���� �����ؾ� �Ѵ�.
*/
int addTwoNumbers(int num_a, int num_b)
{
	int sum = num_a + num_b;
	
	return sum;
}

/*
	productTwoNumbers(int num_a, int num_b)����
	������ num_a, ������ num_b ��� ������ �Ű������� �ִ�.
	ȣ���ڴ� num_a, num_b���� �����ؾ� �Ѵ�.
*/
int productTwoNumbers(int num_a, int num_b)
{
	int product = num_a * num_b;

	return product;
}

/*
	�Լ� ���漱�� (forward declaration)
	: main �Լ� ���ܿ� �Լ����� �ʹ� ������ ��������, �׷��ٰ� �ؼ� �Լ��� main �ڷ� ���� ���� main�� ���� ��
	  �Լ� ���ǰ� �Ǿ������ʾ� �۵��� ���� ����
	  -> �Լ��� �⺻�� (Prototype)�� �̸� ������ �ΰ� main �Լ� �ڿ� �Լ����Ǹ� �̵�
*/
int subtractTwoNumbers(int num_a, int num_b); // forward declaration



/*
	printHelloWorld() �� ���,
	�Ű������� ����.
	ȣ���ڴ� �ƹ��͵� �������� �ʾƵ� �ȴ�.
*/
void printHelloWorld() // Return�� �ʿ����
{
	cout << "Hello World" << endl;

}

// �Լ� ���� 
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
		addTwoNumbers(x, y), productTwoNumbers(x, y) �� ���,
		�Լ� ����� ���ǵ� �Ű������� ���� �μ� (x, y)���� �����Ѵ�. 
	*/
	cout << addTwoNumbers(x, y) << endl;
	cout << productTwoNumbers(x, y) << endl;
	cout << subtractTwoNumbers(x, y) << endl;

	/*
		printHelloWorld()
		�Լ� ����� ���ǵ� �Ű������� ���� � �μ����� �ʿ����.
	*/
	printHelloWorld();

	// �Լ� ������ ���� ��ɽ���
	int a(getValueFromUser());  // ù��° ����
	int b(getValueFromUser());  // �ι�° ����

	std::cout << a << "+" << b << "=" << a + b << std::endl;




	return 0;
	
}


int subtractTwoNumbers(int num_a, int num_b) // definition
{
	int subtract = num_a - num_b;

	return subtract;
}