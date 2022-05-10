#include <iostream>

int main()
{
	int iNumber[9] = {};

	std::srand(static_cast<unsigned int>(std::time(0)));

	// 1~9 ���� ���ڸ� �����մϴ�.
	for (int i = 0; i < 9; i++)
	{
		iNumber[i] = i+1;
	}
	
	// ������ ���ڸ� �����ش�.
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
		std::cout << "1~9 ������ ���� �� ���� 3���� �Է��ϼ��� (0: ����) : ";
		std::cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			std::cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�."<<std::endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0] )
		{
			std::cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << std::endl;
			continue;
		}

		iStrike = iBall = 0;

		// iNumber, iInput �񱳸� ���� ī��Ʈ
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
			std::cout << "���ڸ� ��� ������ϴ�." << std::endl;
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