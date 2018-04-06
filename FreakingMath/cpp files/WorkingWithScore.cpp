#include"WorkingWithScore.h"
#include<fstream>
#include<iostream>
#include"CustomizeGame.h"

using namespace std;

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
	}
	else
	{
		BestScore(diem);
		if (diem.score >= diem.Best_Score)
		{
			diem.Best_Score = diem.score;
			addBestScore(diem);
		}
		gotoxy(13, 8);
		cout << "You've got: " << diem.score << " | Best Score: " << diem.Best_Score;
		diem.score = 0;
	}
}