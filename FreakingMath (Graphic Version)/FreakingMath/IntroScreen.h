#include"SwitchScreen.h"
#include<iostream>
/*man hinh bat dau tro choi*/
class Intro : public Screen
{
	public:
		// run intro screen
		virtual int Run(sf::RenderWindow &window);
};
