#include"SwitchScreen.h"
#include"Objects.h"
#include"Processing.h"
#include"WorkingWithScore.h"
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>

/*man hinh khi tro choi ket thuc*/
class GameOver : public Screen
{
	public:
		//run gameover screen
		virtual int Run(sf::RenderWindow &window);
};