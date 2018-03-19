#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<stdio.h>

using namespace std;

int flag;
int timeCounter = 2;
int level = 1;
int _1stNum,_2ndNum;
int checkOperator;
int result;
char Operator;

void instruction(int &flag);
void delay(int ms);
void randomThe_1stNumber(int level, int &num);
void randomThe_2ndNumber(int level, int &num);
void randomOperator(int &checkOperator);
void resultRandom(int num1, int num2, int checkOperator, char &Operator,  int &result);
void TheQuestion(int num1, int num2, int checkOperator, char Operator, int result);
void TheAnswer(int &flag);
void option(int &flag);


int main()
{
	instruction(flag);
	while (flag == 1)
	{
		while (flag == 1)
		{
			TheQuestion(_1stNum, _2ndNum, checkOperator, Operator, result);
			TheAnswer(flag);
			timeCounter = 2;
		}
		option(flag);
	}
	system("pause");
}

void instruction(int &flag)
{
	cout << "Welcome to Freaking Math. Press 1 to play or 2 to quit: ";
	switch (_getch())
	{
	case 49:
		flag = 1;
		break;
	case 50:
		flag = 2;
		break;
	}
}

void option(int &flag)
{
	cout << "\n\nDo you want to play again? Press 1 to play or 2 to quit: ";
	switch (_getch())
	{
	case 49:
		flag = 1;
		break;
	case 50:
		flag = 2;
		break;
	}
}

void delay(int ms)
{
	clock_t timeDelay = ms + clock();
	while (timeDelay > clock());
}

void TheAnswer(int &flag)
{
	while (timeCounter != 0)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 49:
				cout << "You're right";
				flag = 1;
				break;
			case 50:
				cout << "You're wrong";
				flag = 2;
				break;
			default:
				break;
			}
			break;
		}
		else
		{
			timeCounter--;
			if (timeCounter == 0)
			{
				cout << "You lose";
				flag = 2;
				break;
			}
			else
				delay(1000);
		}
	}
}

void randomThe_1stNumber(int level,int &_1stNum)
{
	srand(time(NULL));
	_1stNum = rand() % level + 1;
}

void randomThe_2ndNumber(int level,int &_2ndNum)
{
	srand(time(NULL));
	_2ndNum = rand() % level + 1;
}

void randomOperator(int &checkOperator)
{
	srand(time(NULL));
	checkOperator = rand() % 2 + 1;
}

void resultRandom(int _1stNum, int _2ndNum, int checkOperator, char &Operator, int &result)
{
	switch (checkOperator)
	{
		case 1:
			Operator = 43;
			result = _1stNum + _2ndNum;
			srand(time(NULL));
			//result = rand() % (result - 2) + (result + 2);
			break;
		case 2:
			Operator = 45;
			result = _1stNum - _2ndNum;
			srand(time(NULL));
			//result = rand() % (result - 2) + (result + 2);
			break;
	}
}

void TheQuestion(int _1stNum, int _2ndNum, int checkOperator, char Operator, int result)
{
	randomThe_1stNumber(level, _1stNum);
	randomThe_2ndNumber(level, _2ndNum);
	randomOperator(checkOperator);
	resultRandom(_1stNum, _2ndNum, checkOperator, Operator, result);
	cout << "\n\nIs " << _1stNum << Operator << _2ndNum << "=" << result << " correct? ";
}