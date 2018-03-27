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

int flag;
int timeCounter = 2;
int level = 1;
int _1stNum,_2ndNum;
int result;
int randomResult;
int checkOperator;
int score = 0;
int range = 3;
int Best_Score;
char Operator;
bool check;
bool ans;

void instruction(int &flag);
void delay(int ms);
void randomThe_1stNumber(int &num, int &range);
void randomThe_2ndNumber(int &num, int &num1, int &range);
void randomOperator(int &checkOperator, int &level);
void resultRandom(int num1, int num2, int checkOperator, char &Operator,  int &result, int &randomResult);
void TheQuestion(int num1, int num2, int checkOperator, char Operator, int &result, int &randomResult);
void TheAnswer(bool &ans, int &flag);
void checkTheAnswer(bool &ans, bool &check, int &flag, int &result, int &randomResult);
void option(int &flag);
void Score(int flag, int &score);
void addBestScore(int &Best_Score);
void BestScore(int &Best_Score);
void updateLevel(int &score, int &level, int &range);

int main()
{
	instruction(flag);
	while (flag == 1)
	{
		while (flag == 1)
		{
			TheQuestion(_1stNum, _2ndNum, checkOperator, Operator, result, randomResult);
			TheAnswer(ans,flag);
			Score(flag,score);
			updateLevel(score, level, range);
			timeCounter = 2;
		}
		option(flag);
	}
	system("pause");
}

void instruction(int &flag)
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
		flag = 1;
		break;
	case 27:
		exit(0);
		flag = 2;
		break;
	}
}

void option(int &flag)
{
	cout << "\n\nDo you want to play again? Press 1 to continue or 2 to quit: ";
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

void randomOperator(int &checkOperator, int &level)
{
	if (level % 2 == 1)
		checkOperator = rand() % 1 + 1;
	else
		checkOperator = rand() % 2 + 1;
}

void randomThe_1stNumber(int &_1stNum, int &range)
{
	_1stNum = rand() %  range + 1;
}

void randomThe_2ndNumber(int &_2ndNum, int &_1stNum, int &range)
{
	if (checkOperator == 1)
		_2ndNum = rand() % range + 1;
	else
		_2ndNum = rand() % _1stNum + 1;
}


void resultRandom(int _1stNum, int _2ndNum, int checkOperator, char &Operator, int &result, int &randomResult)
{
	switch (checkOperator)
	{
		case 1:
			Operator = 43;
			result = _1stNum + _2ndNum;
			randomResult = rand() % 5 + (result - 2); // 5 la so gia tri co the co cua randomResult 
			break;
		case 2:
			Operator = 45;
			result = _1stNum - _2ndNum;
			randomResult = rand() % 3 + result; 
			break;
	}
}

void TheQuestion(int _1stNum, int _2ndNum, int checkOperator, char Operator, int &result, int &randomResult)
{
	srand((unsigned int)time(NULL));
	randomOperator(checkOperator, level);
	randomThe_1stNumber(_1stNum, range);
	randomThe_2ndNumber(_2ndNum, _1stNum, range);
	resultRandom(_1stNum, _2ndNum, checkOperator, Operator, result, randomResult);
	cout << "\n\nIs " << _1stNum << Operator << _2ndNum << "=" << randomResult << " correct? ";
}

void BestScore(int &Best_Score)
{
	ifstream readBS("Best Score.txt");
	readBS >> Best_Score;
	readBS.close();
}

void addBestScore(int &Best_Score)
{
	ofstream add("Best Score.txt");
	add << Best_Score;
	add.close();
}


void Score(int flag, int &score)
{
	if (flag == 1)
	{
		score++;
		cout << "    | Score: " << score;
	}
	else
	{
		BestScore(Best_Score);
		if (score >= Best_Score)
		{
			Best_Score = score;
			addBestScore(Best_Score);
		}
		cout << "\n\nYou've got: " << score << " | Best Score: " << Best_Score;
		score = 0;
	}
}

void updateLevel(int &score, int &level, int &range)
{
	if (score % 10 == 0)
	{
		level++;
		if (score % 20 == 0)
			range = 10;
	}
	else
		range++;
}
void checkTheAnswer(bool &ans, bool &check, int &flag, int &result, int &randomResult)
{
	if (result == randomResult)
		check = true;
	else
		check = false;

	if (ans == check)
	{
		flag = 1;
		cout << "TRUE";
	}
	else
	{
		flag = 2;
		cout << "FALSE";
	}
}

void TheAnswer(bool &ans, int &flag)
{
	while (timeCounter != 0)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 49:
				ans = true;
				cout << "Yes | ";
				checkTheAnswer(ans, check, flag, result, randomResult);
				break;
			case 50:
				ans = false;
				cout << "No | ";
				checkTheAnswer(ans, check, flag, result, randomResult);
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
