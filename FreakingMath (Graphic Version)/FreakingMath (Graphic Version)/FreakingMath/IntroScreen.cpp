#include"IntroScreen.h"
#include"ButtonPressed.h"

int Intro::Run(sf::RenderWindow &window)
{

	bool checkintro; /*bien kiem tra xem chuot co duoc bam khong*/

	// load banner
	sf::Texture banner_Image;
	sf::Sprite banner;
	if (!banner_Image.loadFromFile("banner.png"))
	{
		std::cout << "Error Loading File";
	}
	banner.setTexture(banner_Image);
	banner.setPosition(sf::Vector2f(0, 0));
	banner.setTextureRect(sf::IntRect(0, 0, 600, 800));


	//load play button
	sf::Texture playButton_Image;
	sf::Sprite playButton;
	if (!playButton_Image.loadFromFile("playButton.png"))
	{
		std::cout << "Error Loading File";
	}
	playButton.setTexture(playButton_Image);
	playButton.setPosition(sf::Vector2f(200, 450));
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
					// tra ve gia tri ham Run de chuyen sang man hinh PlayScreen
					return 1;  
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