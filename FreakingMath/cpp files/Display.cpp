#include"Display.h"
#include<string>
#include<iostream>
#include"CustomizeGame.h"
#include<fstream>
#include"WorkingWithQA.h"
#include"WorkingWithScore.h"

using namespace std;

void display(So &so, Toantu& toantu, Diem &diem, Capdo &capdo, DieuKienTroChoi &dieukien, TraLoi &traloi)
{
	string frame;
	char c;
	ifstream file("frame.txt");
	while (!file.eof())
	{
		c = file.get();
		frame = frame + c;
	}
	cout << frame;
	file.close();

	gotoxy(19, 6);
	TheQuestion(so, toantu, capdo);
	gotoxy(39, 1);
	cout << "score: " << diem.score;
	TheAnswer(traloi, dieukien, so);
	Score(dieukien, diem);
}