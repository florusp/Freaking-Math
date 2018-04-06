#include"WorkingWithNumbers.h"
#include<cstdlib>

void randomOperator(Toantu &toantu, Capdo &capdo)
{
	if (capdo.level % 2 == 1)
		toantu.checkOperator = rand() % 1 + 1;
	else
		toantu.checkOperator = rand() % 2 + 1;
}

void randomThe_1stNumber(So &so, Capdo &capdo)
{
	so._1stNum = rand() % capdo.range + 1;
}

void randomThe_2ndNumber(So &so, Capdo &capdo, Toantu &toantu)
{
	if (toantu.checkOperator == 1)
		so._2ndNum = rand() % capdo.range + 1;
	else
		so._2ndNum = rand() % so._1stNum + 1;
}


void resultRandom(So &so, Toantu &toantu)
{
	switch (toantu.checkOperator)
	{
	case 1:
		toantu.Operator = 43;
		so.result = so._1stNum + so._2ndNum;
		so.randomResult = rand() % 5 + (so.result - 2); // 5 la so gia tri co the co cua randomResult 
		if (so.randomResult == so._1stNum)
			so.randomResult++;
		break;
	case 2:
		toantu.Operator = 45;
		so.result = so._1stNum - so._2ndNum;
		so.randomResult = rand() % 3 + so.result;       // 3 la so gia tri co the co cua randomResult
		if (so.randomResult == so._1stNum)
			so.randomResult++;
		break;
	}
}
