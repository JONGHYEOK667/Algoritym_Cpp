#include <iostream>
#include <time.h>


int main()
{

	std::srand(static_cast<unsigned int>(std::time(0)));

	int iLotto[45] = {};

	

	/*
	
	이렇게 짜면 숫자가 중복으로 나올 수 있기 때문에 좋지못함
	 
	for (int i = 0; i < 6; i++)
	{
		int randNum = std::rand();
		int lottoNum = randNum % 45 + 1;

		std::cout << lottoNum << std::endl;
	}   
	*/ 

	// 1~ 45 까지 숫자를 차례대로 넣어준다
	std::cout << "Lotto Number : " << std::endl;
	for (int i = 0; i < 45; i++)
	{
		iLotto[i] = i + 1;
		std::cout << iLotto[i] << "\t";
	}
	std::cout << std::endl;

	/*
	* 
		Shuffle (swap 알고리즘)
	int iNum1 = 1, iNum2 = 2, iNum3 = 3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;

	*/

	
	
	// rnadom한 2개의 인덱스를 뽑아 계속 교체 -> 횟수 증가할수록 섞임
	

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = std::rand() % 45;
		idx2 = std::rand() % 45;

		iTemp		 = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	std::cout << "Lotto Number(Shffled) : " << std::endl;
	for (int i = 0; i < 45; i++)
	{

		std::cout << iLotto[i] << "\t";
	}
	std::cout << std::endl;


	std::cout << "Lotto Number(selected) : " << std::endl;

	for (int i = 0; i < 6; i++)
	{

		std::cout << iLotto[i] << "\t";
	}
	std::cout << std::endl;



		



	return 0;


}