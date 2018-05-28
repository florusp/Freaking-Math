#include"Processing.h"

void Process_Calculation(So &so, Toantu &toantu, string &S_num1, string &S_num2, string &calculation, sf::Text &text_calculation, sf::Font &font)
{
	S_num1 = to_string(so.num1);    // chuyen dang int cua so thu nhat sang dang string
	S_num2 = to_string(so.num2);    // chuyen dang int cua so thu hai sang dang string
	calculation = S_num1 + " " + toantu.Operator + " " + S_num2;
	text_calculation.setFont(font);
	text_calculation.setString(calculation); 

	//dat vi tri cua phep tinh cho phu hop 
	if(so.num1<10&&so.num2<10)
		text_calculation.setPosition(sf::Vector2f(200 / 2.0f, 200 / 2.0f));
	else if((so.num1>10&&so.num2<10)||(so.num1<10&&so.num2>10))
		text_calculation.setPosition(sf::Vector2f(150 / 2.0f, 200 / 2.0f));
	else
		text_calculation.setPosition(sf::Vector2f(100 / 2.0f, 200 / 2.0f));

	//chinh co chu
	text_calculation.setCharacterSize(150);  

	//chinh mau chu
	text_calculation.setFillColor(sf::Color::White);

	//dinh dang kieu chu
	text_calculation.setStyle(sf::Text::Bold);
}

void Process_Assign(Toantu &toantu, sf::Text &text_assign, sf::Font &font)
{
	text_assign.setFont(font);
	text_assign.setString(toantu.assign);
	text_assign.setPosition(sf::Vector2f(350 / 2.0f, 500 / 2.0f));
	text_assign.setCharacterSize(150);
	text_assign.setFillColor(sf::Color::White);
	text_assign.setStyle(sf::Text::Bold);
}

void Process_RandomResult(So &so, string &S_RandomResult, sf::Text &text_RandomResult, sf::Font &font)
{
	S_RandomResult = to_string(so.randomResult);
	text_RandomResult.setFont(font);
	text_RandomResult.setString(S_RandomResult);
	text_RandomResult.setPosition(sf::Vector2f(600 / 2.0f, 500 / 2.0f));
	text_RandomResult.setCharacterSize(150);
	text_RandomResult.setFillColor(sf::Color::White);
	text_RandomResult.setStyle(sf::Text::Bold);
}

void Process_Counting(sf::Int32 &countdown, string &S_countdown, sf::Text &text_countdown, sf::Font &font)
{
	S_countdown = to_string(countdown);
	S_countdown += " ms";
	text_countdown.setFont(font);
	text_countdown.setString(S_countdown);
	text_countdown.setPosition(sf::Vector2f(500, 50));
	text_countdown.setCharacterSize(20);
	text_countdown.setFillColor(sf::Color::White);
	text_countdown.setStyle(sf::Text::Bold);
}

void Process_Score(Diem &diem, string &S_score, sf::Text &text_score, sf::Font &font)
{
	S_score = to_string(diem.score);
	text_score.setFont(font);
	text_score.setString(S_score);
	text_score.setPosition(sf::Vector2f(460, 10));
	text_score.setCharacterSize(20);
	text_score.setFillColor(sf::Color::White);
	text_score.setStyle(sf::Text::Bold);
}

void Process_BestScore(int &GetBestScore, string &S_BestScore, sf::Text &text_bestscore, sf::Font &font)
{
	S_BestScore = to_string(GetBestScore);
	text_bestscore.setFont(font);
	text_bestscore.setString(S_BestScore);
	text_bestscore.setPosition(sf::Vector2f(420, 600));
	text_bestscore.setCharacterSize(50);
	text_bestscore.setFillColor(sf::Color::White);
	text_bestscore.setStyle(sf::Text::Bold);
}