#include <iostream>

int main()
{
	// 1. ��������
	std::srand(static_cast<unsigned int>(std::time(0)));

	// 1~25 ���� �̷���� ���ڹ迭 ����
	int iNumber[25] = {};
	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	// ���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ���� ����Ұǵ�
	// INT_MAX��� ���� ����� ���̴�. INT_MAX�� �̹� ���ǵǾ��ִ� ������ int�� ǥ���� �� �մ� �ִ� ���̴�. 
	// INT_MAX Ȯ���� �ϰ� ������ ���� �� F12 ������ Ȯ�ΰ�����
	iNumber[24] = INT_MAX;  // 2147483647

	// ������ ������ �����ϰ� 1~24 ������ ���ڸ� �����ش�. �� �ε����� 0~23�� ������ ���´�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

	}


	// i for���� �������� �ǹ��Ѵ�. 
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			std::cout << iNumber[row * 5 + col] << "\t";
		}
		std::cout << "\n";
	}

}
