#include"ButtonPressed.h"

void IsPlayButtonPressed(sf::Sprite &playButton, sf::RenderWindow &window, bool &check)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	if (playButton.getGlobalBounds().contains(mousePosF))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			check = true;
		}
	}
}

void IsButtonPressed(sf::Sprite &CheckButton, sf::Sprite &XButton, sf::RenderWindow &window, bool &check, TraLoi &traloi)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	if (CheckButton.getGlobalBounds().contains(mousePosF))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			check = true;
			traloi.ans = true;
		}
	}
	if (XButton.getGlobalBounds().contains(mousePosF))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			check = true;
			traloi.ans = false;
		}
	}
}