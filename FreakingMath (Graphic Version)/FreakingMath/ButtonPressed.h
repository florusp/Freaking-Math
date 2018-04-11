#ifndef BUTTONPRESSED_h
#define BUTTONPRESSED_h

#include<SFML/Graphics.hpp>
#include"Objects.h"

void IsButtonPressed(sf::Sprite &CheckButton, sf::Sprite &XButton, sf::RenderWindow &window, bool &check, TraLoi &traloi);
void IsPlayButtonPressed(sf::Sprite &playButton, sf::RenderWindow &window, bool &check);

#endif // !BUTTONPRESSED_h
