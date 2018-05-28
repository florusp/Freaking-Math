#ifndef objects_h
#define objects_h

#include<ctime>
#include<string>

struct So
{
	int num1, num2; 
	int result, randomResult;

	int RightNum1, RightNum2;
	int RightResult;
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

};

struct TraLoi
{
	bool checkAns;
	bool ans;
};

#endif
