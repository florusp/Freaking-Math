#ifndef objects_h
#define objects_h

#include<ctime>
#include<string>

struct So
{
	int num1, num2; 
	int result, randomResult;
};

struct Toantu
{
	std::string Operator;
	const std::string assign = "=";
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
	int flag = 1;
	double timeCounter = 2;

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

#endif