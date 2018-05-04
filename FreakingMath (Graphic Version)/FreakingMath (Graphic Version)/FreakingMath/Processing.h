#include<string>
#include"Objects.h"
#include<SFML/Graphics.hpp>

using namespace std;

// chuyen cac phan tu cua phuong trinh tu dang int sang dang string
void Process_Calculation(So &so, Toantu &toantu, string &S_num1, string &S_num2, string &calculation, sf::Text &text_calculation, sf::Font &font);

// xu ly toan tu gan
void Process_Assign(Toantu &toantu, sf::Text &text_assign, sf::Font &font);

// chuyen ket qua ngau nhien tu dang int sang dang string
void Process_RandomResult(So &so, string &S_RandomResult, sf::Text &text_RandomResult, sf::Font &font);

// chuyen bien dem tu dang int sang dang string
void Process_Counting(sf::Int32 &countdown, string &S_countdown, sf::Text &text_countdown, sf::Font &font);

// chuyen diem tu dang int sang string  
void Process_Score(Diem &diem, string &S_score, sf::Text &text_socre, sf::Font &font);

// chuyen diem cao nhat tu dang int sang string
void Process_BestScore(int &GetBestScore, string &S_BestScore, sf::Text &text_bestscore, sf::Font &font);