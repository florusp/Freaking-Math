#ifndef objects_h
#define objects_h

#include<ctime>
struct So
{
	int _1stNum, _2ndNum;
	int result, randomResult;
};

struct Toantu
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
