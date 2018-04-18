#include<string>
#include"Objects.h"
#include<SFML/Graphics.hpp>

using namespace std;

// transform objects of the equation from int to string
void Process_Calculation(So &so, Toantu &toantu, string &S_num1, string &S_num2, string &calculation, sf::Text &text_calculation, sf::Font &font);

// transform assign from int to string
void Process_Assign(Toantu &toantu, sf::Text &text_assign, sf::Font &font);

// transform random result from int to string
void Process_RandomResult(So &so, string &S_RandomResult, sf::Text &text_RandomResult, sf::Font &font);

// transform timer from int to string
void Process_Counting(sf::Int32 &countdown, string &S_countdown, sf::Text &text_countdown, sf::Font &font);

// transform score from int to string 
void Process_Score(Diem &diem, string &S_score, sf::Text &text_socre, sf::Font &font);

// transform best score from int to string 
void Process_BestScore(int &GetBestScore, string &S_BestScore, sf::Text &text_bestscore, sf::Font &font);