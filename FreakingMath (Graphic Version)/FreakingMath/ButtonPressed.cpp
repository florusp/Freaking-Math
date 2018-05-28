#include"ButtonPressed.h"

void IsPlayButtonPressed(sf::Sprite &playButton, sf::RenderWindow &window, bool &check)
{
	/*gan vi tri cho chuot*/
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	/*vi tri toa do cua chuot*/
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	if (playButton.getGlobalBounds().contains(mousePosF)) /*kiem tra xem vi tri cua chuot co trong nut play khong*/
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			check = true;  /*neu dung tra ve gia tri true*/
		}
	}
}

void IsButtonPressed(sf::Sprite &TrueButton, sf::Sprite &FalseButton, sf::RenderWindow &window, bool &check, TraLoi &traloi)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	if (TrueButton.getGlobalBounds().contains(mousePosF)) /*kiem tra xem vi tri cua chuot co trong nut True Button khong*/
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			check = true;
			traloi.ans = true;
		}
	}

	else if (FalseButton.getGlobalBounds().contains(mousePosF)) /*kiem tra xem vi tri cua chuot co trong nut False Button khong*/
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			check = true;
			traloi.ans = false;
		}
	}
}
