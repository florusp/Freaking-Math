#include"GameOver.h"
#include"ButtonPressed.h"
#include"Processing.h"
#include"WorkingWithScore.h"
#include<SFML/Audio.hpp>
#include<iostream>

using namespace std;

int GameOver::Run(sf::RenderWindow &window)
{
	bool checkContinue;  /*bien kiem tra xem co tiep tuc tro choi khong*/

	Diem GetBestScore;   /*lay diem cao nhat*/

	string S_BestScore;  /*dang string cua BestScore*/

	sf::Text text_bestscore; /*dang text cua BestScore*/

	sf::Font font;                            // load font
	if (!font.loadFromFile("VAVKI.ttf"))
	{
		cout << "Error Loading File";
	}

	sf::Text fail;      
	fail.setFont(font);
	fail.setString("You Failed!");
	fail.setPosition(130, 200);
	fail.setCharacterSize(50);
	fail.setFillColor(sf::Color::Red);


	sf::Text Continue;
	Continue.setFont(font);
	Continue.setString("Play Again?");
	Continue.setPosition(130, 300);
	Continue.setCharacterSize(50);
	fail.setFillColor(sf::Color::Red);
	

	sf::Text BestScore;
	BestScore.setFont(font);
	BestScore.setString("Best Score: ");
	BestScore.setPosition(80, 600);
	BestScore.setCharacterSize(50);
	BestScore.setFillColor(sf::Color::White);


	sf::Texture ContinueButton_Image;
	if (!ContinueButton_Image.loadFromFile("playButton.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite ContinueButton;
	ContinueButton.setTexture(ContinueButton_Image);
	ContinueButton.setPosition(sf::Vector2f(200, 450));
	ContinueButton.setTextureRect(sf::IntRect(0, 0, 184, 81));

	///////////////////////

	sf::SoundBuffer FalseSound;
	if (!FalseSound.loadFromFile("FalseSound.flac"))
	{
		cout << "Error Loading File";
	}

	sf::Sound False;
	False.setBuffer(FalseSound);
	False.play();

	/////////////////////////

	readBestScore(GetBestScore);
	Process_BestScore(GetBestScore.Best_Score, S_BestScore, text_bestscore, font);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::MouseButtonPressed:
					IsPlayButtonPressed(ContinueButton, window, checkContinue);

					if (checkContinue == true)
					{
						return 1;
					}
			}
		}
		window.clear();
		window.draw(fail);
		window.draw(Continue);
		window.draw(ContinueButton);
		window.draw(BestScore);
		window.draw(text_bestscore);
		window.display();
	}

	return -1;
}