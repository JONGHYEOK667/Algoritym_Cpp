#include <iostream>

/*
	Baseball ����
	1. 1~9 ������ ������ ���� 3���� ���´�. ��, ���ڴ� �ߺ��Ǿ�� �ȵȴ�.
	2. 3���� ���ڴ� * * * ���·� ��µǰ�, �� 3���� ���ڸ� ���ߴ� �����̴�. 
	3. ����ڴ� �� 3���� ���ڸ� ���⶧���� ����ؼ� 3���� ���ڸ� �Է��Ѵ�. 
	4. ���� ������� ���ڰ� 7 3 8 �� ��� ����ڴ� 3���� ���ڸ� ����Է��Ѵ�. 

	�Է� : 1 2 4 �� �Է����� ��� 
	��� : Out

	�Է� : 7 5 9 �� �Է����� ���, 7�� ���ԵǾ� �����鼭 ��ġ�� ���� ������ Strike
	��� : 1strike 0ball

	�Է� : 7 8 6 �� �Է����� ���, 7�� ���ԵǾ� �����鼭 ��ġ�� ���� ������ Strike, 8�� ���ԵǾ� �����鼭 ��ġ�� �ٸ��� ������ Ball
	��� : 1strike 1ball

	5. �̷��� ����� �ϰ� �Է��� �����鼭 ���������� 3���� ���ڸ� �ڸ����� ��� ��ġ�ϰ� �Է��ϸ� ������ ����
	6. ���� �Է¹��� ���� 3�� �� �Ѱ��� 0�� ���� ��� ������ �����Ѵ�. 

	*/

void getComNum(int* comBall);
void getUserNum(int* userBall);
void calCount(int* count, int * comBall, int * userBall);

int main()
{
	// 1. ��������
	std::srand(static_cast<unsigned int>(std::time(0)));

	// 2.1~9���� ���� �� 3�� ȹ��
	int comBall[3] = {};
	getComNum(comBall);

	/*std::cout << "select number : " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << *(comBall + i) << "\t";
	}
	std::cout << std::endl;*/


	// ���� ���������� 3~4 �ݺ�����
	int finishGame = 0;
	while (finishGame == 0)
	{
		// 3. 1~9 ���� ���� �Է�
		int userBall[3] = {};
		getUserNum(userBall);

		/*std::cout << "user number : " << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << *(userBall + i) << "\t";
		}
		std::cout << std::endl;*/
		
		// 4. �� ����
		int count[4] = {};  // {strike, ball, out, hit}
		calCount(count, comBall, userBall);

		/*std::cout << "count [strike, ball, out, hit] : " << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << *(count + i) << "\t";
		}
		std::cout << std::endl;*/

		// 5. ��� ���
		if (count[2] == 1) // out -> ��������
		{
			std::cout << "out!!" << std::endl;
			finishGame = 1;
		}
		else if (count[3] == 1) // hit -> ��������
		{
			std::cout << "hit!!" << std::endl;
			finishGame = 1;
		}
		else
		{
			std::cout <<"\n" << count[0] << " strike " << count[1] << " ball try again!!" << std::endl;
			std::cout <<  " -------------------------------------------- \n" << std::endl;
		}


	}
	


	return 0;

}

void getComNum(int* comBall)
{
	int index[9] = {};

	// index �迭 �� ���� 1~9���� �Ҵ�
	for (int i = 0; i < 9; i++)
	{
		index[i] = i+1;
	}
	

	// shffle
	int iIdx1, iIdx2, iTemp;
	for (int i = 0; i < 5; i++)
	{
		iIdx1 = std::rand() % 9 ;
		iIdx2 = std::rand() % 9 ;

		iTemp        = index[iIdx1];
		index[iIdx1] = index[iIdx2];
		index[iIdx2] = iTemp;

	}


	// 3�� �� ȹ��
	for (int i = 0; i < 3; i++)
	{
		comBall[i] = index[i];
	}

}

void getUserNum(int* userBall)
{
	int i = 0; 
	// userNum 3�� �Է�
	while (i < 3)
	{
		
		std::cout << "insert " << i + 1 << " number : " << std::endl;
		std::cin >> userBall[i];

		// 1. user �Է°� �ߺ� �Ǵ�
		int sameValue = 0;
		for (int j = 0; j < i; j++)
		{
			if ((userBall[i]!=0) && (userBall[j] == userBall[i]))
			{
				sameValue = 1;
			}
		}
		
		// 2. user �Է� ��ȿ�� ���� �Ǵ�
		int invalidNum = 0;
		if ((userBall[i] < 0) || (userBall[i] > 9))
		{
			invalidNum = 1;
		}
		

		if (sameValue == 1)
		{
			std::cout << "insert number again (same number)" << std::endl;
		}
		else if (invalidNum == 1)
		{
			std::cout << "insert number again (invalid number)" << std::endl;
		}
		else
		{
			++i;
		}
		
		

	}


}

void calCount(int* count, int* comBall, int* userBall)
{
	
	
	for (int i = 0; i < 3; i++)
	{

		// out (����� �Է� �� 0 ����)�� ��� ã��
		if (userBall[i] == 0)
		{
			count[2] = 1;
			break;
		}

		// strike or ball ã��
		for (int j = 0; j < 3; j++)
		{
			if ((i == j) && (userBall[i] == comBall[j]))
			{
				count[0] += 1; // ���� �ڸ��� ���� ���� -> strike
			}
			else if ((i != j) && (userBall[i] == comBall[j]))
			{
				count[1] += 1; // �ٸ� �ڸ��� ���� ���� -> ball
			}
		}

		// hit ã��
		if (count[0] == 3 )
		{
			count[3] = 1; // ���� ��� ���� -> 3 strike = hit
			break;
		}
	}

}
