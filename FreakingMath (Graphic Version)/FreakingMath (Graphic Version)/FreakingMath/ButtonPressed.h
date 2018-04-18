#ifndef BUTTONPRESSED_h
#define BUTTONPRESSED_h

#include<SFML/Graphics.hpp>
#include"Objects.h"

/*kiem tra xem nut da duoc bam chua*/
void IsButtonPressed(sf::Sprite &TrueButton, sf::Sprite &FalseButton, sf::RenderWindow &window, bool &check, TraLoi &traloi);

/*kiem tra xem nut play duoc bam chua*/
void IsPlayButtonPressed(sf::Sprite &playButton, sf::RenderWindow &window, bool &check);

#endif // !BUTTONPRESSED_h
