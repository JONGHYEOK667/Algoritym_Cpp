#include <iostream>

int main()
{
	int iNumber[9] = {};

	std::srand(static_cast<unsigned int>(std::time(0)));

	// 1~9 까지 숫자를 설정합니다.
	for (int i = 0; i < 9; i++)
	{
		iNumber[i] = i+1;
	}
	
	// 설정된 숫자를 섰어준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

	}

	// cout << "* * *" << endl;
	std::cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << std::endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];

	while (true)
	{
		std::cout << "1~9 사이의 숫자 중 숫자 3개를 입력하세요 (0: 종료) : ";
		std::cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			std::cout << "잘못된 숫자를 입력하였습니다."<<std::endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0] )
		{
			std::cout << "중복된 숫자를 입력하였습니다." << std::endl;
			continue;
		}

		iStrike = iBall = 0;

		// iNumber, iInput 비교를 통한 카운트
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
					{
						iStrike += 1;
					}
					else
					{
						iBall += 1;
					}

					break;
				}
			}
		}

		if (iStrike == 3)
		{
			std::cout << "숫자를 모두 맞췄습니다." << std::endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0)
		{
			std::cout << "out!" << std::endl;
		}
		else
		{
			std::cout << iStrike << " iStrike " << iBall << " iBall " << std::endl;
		}
	}
	
	return 0;

}