#include"WorkingWithScore.h"
#include<fstream>
#include<iostream>

using namespace std;


void readBestScore(Diem &diem)
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


void addScore(DieuKienTroChoi &dieukien, Diem &diem)
{
	if (dieukien.flag == 1)
	{
		diem.score++;
	}
}

void returnBestScore(DieuKienTroChoi &dieukien, Diem &diem)
{
	if (dieukien.flag == 2)
	{
		readBestScore(diem);
		if (diem.score >= diem.Best_Score)
		{
			diem.Best_Score = diem.score;
			addBestScore(diem);
		}
	}
}

