#include"PlayScreen.h"
#include"ButtonPressed.h"
#include"Processing.h"

#include"WorkingWithQA.h"
#include"WorkingWithLevel.h"
#include"WorkingWithScore.h"

#include"SFML/Audio.hpp"

#include<iostream>

using namespace std;

int Play::Run(sf::RenderWindow &window)
{
	So so;
	Capdo capdo;
	Toantu toantu;
	Diem diem;
	DieuKienTroChoi dieukien;
	TraLoi traloi;

	string S_num1, S_num2, S_RandomResult, S_countdown, S_score, S_calculation;
	
	int color;        // color of the background

	bool checkplay;

	sf::Font font;                            // load font
	if (!font.loadFromFile("ANCUU.ttf"))
	{
		cout << "Error Loading File";
	}

	//////////////////////////

	sf::Text time_left;
	time_left.setFont(font);
	time_left.setString("Time Left: ");
	time_left.setPosition(380, 50);
	time_left.setCharacterSize(20);
	time_left.setFillColor(sf::Color::White);
	time_left.setStyle(sf::Text::Bold);

	sf::Clock clock;
	sf::Time timeline = sf::seconds(1);

	///////////////////////////////////

	sf::Text display_score;
	display_score.setFont(font);
	display_score.setString("Score: ");
	display_score.setPosition(380, 10);
	display_score.setCharacterSize(20);
	display_score.setFillColor(sf::Color::White);
	display_score.setStyle(sf::Text::Bold);

	//////////////////////////////////

	sf::Text text_num1;

	sf::Text text_num2;

	sf::Text text_operator;

	sf::Text text_calculation;

	sf::Text text_assign;

	sf::Text text_RandomResult;

	sf::Text text_countdown;

	sf::Text text_score;

	//////////////////////////////////////////////



	sf::Texture CheckButton_Image;
	if (!CheckButton_Image.loadFromFile("CheckButton.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite CheckButton;
	CheckButton.setTexture(CheckButton_Image);
	CheckButton.setPosition(sf::Vector2f(50, 500));
	CheckButton.setTextureRect(sf::IntRect(0, 0, 237, 203));

	//////////////////////////////////

	sf::Texture XButton_Image;
	if (!XButton_Image.loadFromFile("XButton.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite XButton;
	XButton.setTexture(XButton_Image);
	XButton.setPosition(sf::Vector2f(320, 500));
	XButton.setTextureRect(sf::IntRect(0, 0, 223, 206));

	///////////////////////////////////

	/*Load Sound*/

	sf::SoundBuffer TrueSound;
	if (!TrueSound.loadFromFile("TrueSound.flac"))
	{
		cout << "Error Loading File";
	}

	sf::Sound True;
	True.setBuffer(TrueSound);
	

	/////////////////////////////
	
	srand((unsigned int)time(NULL));
	color = rand() % 6 + 1;

	RandomQuestion(so, toantu, capdo);
	Process_Calculation(so, toantu, S_num1, S_num2, S_calculation, text_calculation, font);
	Process_Assign(toantu, text_assign, font);
	Process_RandomResult(so, S_RandomResult, text_RandomResult, font);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event) && dieukien.flag == 1)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:

				IsButtonPressed(CheckButton, XButton, window, checkplay, traloi);

				checkTheAnswer(traloi, dieukien, so);

				addScore(dieukien, diem);
				Process_Score(diem, S_score, text_score, font);

				if (checkplay == true)
				{
					if (dieukien.flag == 1)
					{
						True.play();
						RandomQuestion(so, toantu, capdo);
						Process_Calculation(so, toantu, S_num1, S_num2, S_calculation, text_calculation, font);
						Process_Assign(toantu, text_assign, font);
						Process_RandomResult(so, S_RandomResult, text_RandomResult, font);
						Process_Assign(toantu, text_assign, font);
						Process_RandomResult(so, S_RandomResult, text_RandomResult, font);
						updateLevel(diem, capdo);
						clock.restart();
					}
				}
				break;
			}

		}
		if (color == 1)
			window.clear(sf::Color::Green);
		else if (color == 2)
			window.clear(sf::Color::Cyan);
		else if (color == 3)
			window.clear(sf::Color::Blue);
		else if (color == 4)
			window.clear(sf::Color::Red);
		else if (color == 5)
			window.clear(sf::Color::Magenta);
		else
			window.clear(sf::Color::Yellow);
		window.draw(display_score);
		window.draw(text_score);
		window.draw(time_left);
		window.draw(CheckButton);
		window.draw(XButton);
		window.draw(text_calculation);
		window.draw(text_assign);
		window.draw(text_RandomResult);
		if (dieukien.flag == 2)
		{
			returnBestScore(dieukien, diem);
			resetLevel(diem, capdo);
			return 2;
		}
		else if(dieukien.flag == 1 && diem.score > 0)
		{
			sf::Time elapsed = clock.getElapsedTime();
			sf::Int32 countdown = elapsed.asMilliseconds();
			if (elapsed.asMilliseconds() >= timeline.asMilliseconds())
			{
				dieukien.flag = 2;
			}
			Process_Counting(countdown, S_countdown, text_countdown, font);
			window.draw(text_countdown);
		}
		window.display();
	}

	return -1;
}
