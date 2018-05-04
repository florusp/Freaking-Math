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
	so.num1 = rand() % capdo.range + 1;
}

void randomThe_2ndNumber(So &so, Capdo &capdo, Toantu &toantu)
{
	if (toantu.checkOperator == 1)
		so.num2 = rand() % capdo.range + 1;
	else
		so.num2 = rand() % so.num1 + 1;
}


void resultRandom(So &so, Toantu &toantu)
{
	switch (toantu.checkOperator)
	{
	case 1:
		toantu.Operator = "+";
		so.result = so.num1 + so.num2;
		so.randomResult = rand() % 4 + so.result; // 4 la so gia tri co the co cua randomResult 
		break;
	case 2:
		toantu.Operator = "-";
		so.result = so.num1 - so.num2;
		so.randomResult = rand() % 3 + so.result; // 3 la so gia tri co the co cua randomResult
		if (so.randomResult == so.num1)
			so.randomResult++;
		break;
	}
}
