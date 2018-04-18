#include"IntroScreen.h"
#include<iostream>
#include"ButtonPressed.h"

using namespace std;

int Intro::Run(sf::RenderWindow &window)
{
	bool checkintro;       /*bien kiem tra xem chuot co duoc bam khong*/

	/*load banner*/
	sf::Texture banner_Image;    
	if (!banner_Image.loadFromFile("banner.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite banner;
	banner.setTexture(banner_Image);
	banner.setPosition(sf::Vector2f(0, 0));
	banner.setTextureRect(sf::IntRect(0, 0, 600, 800));

	/*load play Button*/
	sf::Texture playButton_Image;
	if (!playButton_Image.loadFromFile("playButton.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite playButton;
	playButton.setTexture(playButton_Image);
	playButton.setPosition(sf::Vector2f(200, 400));
	playButton.setTextureRect(sf::IntRect(0, 0, 184, 81));

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
				IsPlayButtonPressed(playButton, window, checkintro);

				if (checkintro == true)
				{
					return 1;  /*chuyen sang man hinh PlayScreen*/
				}
				break;
			}
		}
		window.clear();
		window.draw(banner);
		window.draw(playButton);
		window.display();
	}

	return -1;
}