#include"Instruction.h"
#include<string>
#include<fstream>
#include<iostream>
#include<conio.h>
#include"CustomizeGame.h"

using namespace std;

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
	gotoxy(15, 11);
	cout << "Do you want to play again?";
	gotoxy(12, 12);
	cout << "Press 1 to continue or 2 to quit: ";
	switch (_getch())
	{
	case 49:
		dieukien.flag = 1;
		system("cls");
		break;
	case 50:
		dieukien.flag = 2;
		break;
	}
}