#include"SwitchScreen.h"
#include"Objects.h"
#include"Processing.h"
#include"WorkingWithScore.h"
#include"WorkingWithQA.h"
#include"WorkingWithLevel.h"
#include"SFML/Audio.hpp"
#include<iostream>

/*man hinh choi game*/
class Play : public Screen
{
	public:
		//run play screen
		virtual int Run(sf::RenderWindow &window);
};

