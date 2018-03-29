#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


struct So
{
	int _1stNum, _2ndNum;
	int result, randomResult;
};

struct Toantu                            // struct of Operator 
{
	char Operator;
	int checkOperator;
};

struct Diem
{
	int score = 0;
	int Best_Score;
};

struct Capdo
{
	int level = 1;
	int range = 3;
};

struct DieuKienTroChoi
{
	int flag;
	int timeCounter = 2;

	void delay(int ms)
	{
		clock_t timeDelay = ms + clock();
		while (timeDelay > clock());
	}

};

struct TraLoi
{
	bool checkAns;
	bool ans;
};

void instruction(DieuKienTroChoi &dieukien);

void randomOperator(Toantu &toantu, Capdo &capdo);

void randomThe_1stNumber(So &so, Capdo &capdo);
void randomThe_2ndNumber(So &so, Capdo &capdo, Toantu &toantu);
void resultRandom(So &so, Toantu &toantu);

void TheQuestion(So &so, Toantu &toantu, Capdo &capdo);

void TheAnswer(TraLoi &traloi, DieuKienTroChoi &dieukien, So &so);
void checkTheAnswer(TraLoi &traloi, DieuKienTroChoi &dieukien, So &so);

void Score(DieuKienTroChoi &dieukien, Diem &diem);
void addBestScore(Diem &diem);
void BestScore(Diem &diem);

void updateLevel(Diem &diem, Capdo &capdo);

void option(DieuKienTroChoi &dieukien);

int main()
{
	So so;
	Toantu toantu;
	Diem diem;
	Capdo capdo;
	TraLoi traloi;
	DieuKienTroChoi dieukien;

	instruction(dieukien);
	while (dieukien.flag == 1)
	{
		while (dieukien.flag == 1)
		{
			TheQuestion(so, toantu, capdo);
			TheAnswer(traloi, dieukien, so);
			Score(dieukien, diem);
			updateLevel(diem, capdo);
			dieukien.timeCounter = 2;
		}
		option(dieukien);
	}
}

void instruction(DieuKienTroChoi &dieukien)
{
	ifstream intro("Instruction.txt");
	string word;
	char c;

	while (!intro.eof())
	{
		c = intro.get();
		word = word + c;
	}
	cout << word;
	intro.close();
	switch (_getch())
	{
	case 32:
		dieukien.flag = 1;
		break;
	case 27:
		exit(0);
		dieukien.flag = 2;
		break;
	}
	system("cls");
}

void option(DieuKienTroChoi &dieukien)
{
	cout << "\n\nDo you want to play again? Press 1 to continue or 2 to quit: ";
	switch (_getch())
	{
	case 49:
		dieukien.flag = 1;
		break;
	case 50:
		dieukien.flag = 2;
		break;
	}
}


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
		break;
	case 2:
		toantu.Operator = 45;
		so.result = so._1stNum - so._2ndNum;
		so.randomResult = rand() % 3 + so.result;       // 3 la so gia tri co the co cua randomResult
		break;
	}
}

void TheQuestion(So &so, Toantu &toantu, Capdo &capdo)
{
	srand((unsigned int)time(NULL));
	randomOperator(toantu, capdo);
	randomThe_1stNumber(so, capdo);
	randomThe_2ndNumber(so, capdo, toantu);
	resultRandom(so, toantu);
	cout << "\n\nIs " << so._1stNum << toantu.Operator << so._2ndNum << "=" << so.randomResult << " correct? ";
}

void BestScore(Diem &diem)
{
	ifstream readBS("Best Score.txt");
	readBS >> diem.Best_Score;
	readBS.close();
}

void addBestScore(Diem &diem)
{
	ofstream add("Best Score.txt");
	add << diem.Best_Score;
	add.close();
}


void Score(DieuKienTroChoi &dieukien, Diem &diem)
{
	if (dieukien.flag == 1)
	{
		diem.score++;
		cout << "    | Score: " << diem.score;
	}
	else
	{
		BestScore(diem);
		if (diem.score >= diem.Best_Score)
		{
			diem.Best_Score = diem.score;
			addBestScore(diem);
		}
		cout << "\n\nYou've got: " << diem.score << " | Best Score: " << diem.Best_Score;
		diem.score = 0;
	}
}

void updateLevel(Diem &diem, Capdo &capdo)
{
	if (diem.score % 10 == 0)
	{
		capdo.level++;
		if (diem.score % 20 == 0)
			capdo.range = 10;
	}
	else
		capdo.range++;
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
		cout << "TRUE";
	}
	else
	{
		dieukien.flag = 2;
		cout << "FALSE";
	}
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
				cout << "Yes | ";
				checkTheAnswer(traloi, dieukien, so);
				break;
			case 50:
				traloi.ans = false;
				cout << "No | ";
				checkTheAnswer(traloi, dieukien, so);
				break;
			default:
				break;
			}
			break;
		}
		else
		{
			dieukien.timeCounter--;
			if (dieukien.timeCounter == 0)
			{
				cout << "You lose";
				dieukien.flag = 2;
				break;
			}
			else
				dieukien.delay(1000);
		}
	}
}
