#include"WorkingWithQA.h"
#include<iostream>
#include"WorkingWithNumbers.h"
#include<conio.h>
#include"CustomizeGame.h"

using namespace std;

void TheQuestion(So &so, Toantu &toantu, Capdo &capdo)
{
	srand((unsigned int)time(NULL));
	randomOperator(toantu, capdo);
	randomThe_1stNumber(so, capdo);
	randomThe_2ndNumber(so, capdo, toantu);
	resultRandom(so, toantu);
	cout << "Is " << so._1stNum << toantu.Operator << so._2ndNum << "=" << so.randomResult << " correct? ";
}

void TheAnswer(TraLoi &traloi, DieuKienTroChoi &dieukien, So &so)
{
	while (dieukien.timeCounter != 0)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 49:
				traloi.ans = true;
				//cout << "Yes | ";
				checkTheAnswer(traloi, dieukien, so);
				break;
			case 50:
				traloi.ans = false;
				//cout << "No | ";
				checkTheAnswer(traloi, dieukien, so);
				break;
			default:
				break;
			}
			break;
		}
		else
		{
			dieukien.timeCounter -= 0.1;
			if (dieukien.timeCounter <= 0)
			{
				gotoxy(39, 2);
				cout << "Time Left: 0.0";
				gotoxy(24, 4);
				cout << "You lose";
				dieukien.flag = 2;
				break;
			}
			else
			{
				gotoxy(39, 2);
				cout << "Time Left: " << dieukien.timeCounter;
				dieukien.delay(50);
			}
		}
	}
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
		//cout << "TRUE";
		system("cls");
	}
	else
	{
		dieukien.flag = 2;
		//cout << "FALSE";
	}
}