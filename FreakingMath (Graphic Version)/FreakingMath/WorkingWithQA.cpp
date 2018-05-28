#include"WorkingWithQA.h"
#include<iostream>
#include"WorkingWithNumbers.h"
#include<conio.h>
#include<string>

using namespace std;

void RandomQuestion(So &so, Toantu &toantu, Capdo &capdo)
{
	srand((unsigned int)time(NULL));
	randomOperator(toantu, capdo);
	randomThe_1stNumber(so, capdo);
	randomThe_2ndNumber(so, capdo, toantu);
	resultRandom(so, toantu);
}


void checkTheAnswer(TraLoi &traloi, DieuKienTroChoi &dieukien, So &so)
{
	if (so.result == so.randomResult)
		traloi.checkAns = true;
	else
		traloi.checkAns = false;

	if (traloi.ans == traloi.checkAns)
	{
		dieukien.flag = 1;
	}
	else
	{
		dieukien.flag = 2;
	}

}