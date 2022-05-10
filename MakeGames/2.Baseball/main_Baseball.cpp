#include <iostream>

/*
	Baseball 게임
	1. 1~9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
	2. 3개의 숫자는 * * * 형태로 출력되고, 이 3개의 숫자를 맞추는 게임이다. 
	3. 사용자는 이 3개의 숫자를 맞출때까지 계속해서 3개씩 숫자를 입력한다. 
	4. 만약 맞춰야할 숫자가 7 3 8 일 경우 사용자는 3개의 숫자를 계속입력한다. 

	입력 : 1 2 4 를 입력했을 경우 
	출력 : Out

	입력 : 7 5 9 를 입력했을 경우, 7은 포함되어 있으면서 위치가 같기 때문에 Strike
	출력 : 1strike 0ball

	입력 : 7 8 6 을 입력했을 경우, 7은 포함되어 있으면서 위치가 같기 때문에 Strike, 8은 포함되어 있으면서 위치가 다르기 때문에 Ball
	출력 : 1strike 1ball

	5. 이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게 입력하면 게임이 종료
	6. 만약 입력받은 숫자 3개 중 한개라도 0이 있을 경우 게임을 종료한다. 

	*/

void getComNum(int* comBall);
void getUserNum(int* userBall);
void calCount(int* count, int * comBall, int * userBall);

int main()
{
	// 1. 난수생성
	std::srand(static_cast<unsigned int>(std::time(0)));

	// 2.1~9사이 랜덤 수 3개 획득
	int comBall[3] = {};
	getComNum(comBall);

	/*std::cout << "select number : " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << *(comBall + i) << "\t";
	}
	std::cout << std::endl;*/


	// 게임 끝날때까지 3~4 반복수행
	int finishGame = 0;
	while (finishGame == 0)
	{
		// 3. 1~9 사이 숫자 입력
		int userBall[3] = {};
		getUserNum(userBall);

		/*std::cout << "user number : " << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << *(userBall + i) << "\t";
		}
		std::cout << std::endl;*/
		
		// 4. 볼 판정
		int count[4] = {};  // {strike, ball, out, hit}
		calCount(count, comBall, userBall);

		/*std::cout << "count [strike, ball, out, hit] : " << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << *(count + i) << "\t";
		}
		std::cout << std::endl;*/

		// 5. 결과 출력
		if (count[2] == 1) // out -> 게임종료
		{
			std::cout << "out!!" << std::endl;
			finishGame = 1;
		}
		else if (count[3] == 1) // hit -> 게임종료
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

	// index 배열 내 숫자 1~9까지 할당
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


	// 3개 공 획득
	for (int i = 0; i < 3; i++)
	{
		comBall[i] = index[i];
	}

}

void getUserNum(int* userBall)
{
	int i = 0; 
	// userNum 3개 입력
	while (i < 3)
	{
		
		std::cout << "insert " << i + 1 << " number : " << std::endl;
		std::cin >> userBall[i];

		// 1. user 입력값 중복 판단
		int sameValue = 0;
		for (int j = 0; j < i; j++)
		{
			if ((userBall[i]!=0) && (userBall[j] == userBall[i]))
			{
				sameValue = 1;
			}
		}
		
		// 2. user 입력 유효값 범위 판단
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

		// out (사용자 입력 중 0 포함)인 경우 찾기
		if (userBall[i] == 0)
		{
			count[2] = 1;
			break;
		}

		// strike or ball 찾기
		for (int j = 0; j < 3; j++)
		{
			if ((i == j) && (userBall[i] == comBall[j]))
			{
				count[0] += 1; // 같은 자리에 숫자 같음 -> strike
			}
			else if ((i != j) && (userBall[i] == comBall[j]))
			{
				count[1] += 1; // 다른 자리에 숫자 같음 -> ball
			}
		}

		// hit 찾기
		if (count[0] == 3 )
		{
			count[3] = 1; // 숫자 모두 동일 -> 3 strike = hit
			break;
		}
	}

}
