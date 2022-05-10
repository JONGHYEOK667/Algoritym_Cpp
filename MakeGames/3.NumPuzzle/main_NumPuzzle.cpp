#include <iostream>

int main()
{
	// 1. 난수생성
	std::srand(static_cast<unsigned int>(std::time(0)));

	// 1~25 까지 이루어진 숫자배열 생성
	int iNumber[25] = {};
	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을 사용할건데
	// INT_MAX라는 값을 사용할 것이다. INT_MAX는 이미 정의되어있는 값으로 int로 표현할 수 잇는 최대 값이다. 
	// INT_MAX 확인을 하고 싶으면 음영 후 F12 누르면 확인가능함
	iNumber[24] = INT_MAX;  // 2147483647

	// 마지막 공백을 제외하고 1~24 까지의 숫자만 섞어준다. 즉 인덱스는 0~23번 까지만 섞는다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

	}


	// i for문이 세로줄을 의미한다. 
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			std::cout << iNumber[row * 5 + col] << "\t";
		}
		std::cout << "\n";
	}

}
