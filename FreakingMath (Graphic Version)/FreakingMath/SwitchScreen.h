#ifndef SWITCHSCREEN_h
#define SWITCHSCREEN_h

#include<SFML/Graphics.hpp>

/*man hinh tro choi*/
class Screen
{
	public:
		virtual int Run(sf::RenderWindow &window) = 0;
};

#endif
