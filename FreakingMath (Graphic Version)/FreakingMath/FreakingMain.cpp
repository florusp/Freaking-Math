#include<vector>
#include"IntroScreen.h"
#include"PlayScreen.h"
#include"GameOver.h"

using namespace std;


int main()
{

	std::vector<Screen*> Screens;
	int screen = 0;
	sf::RenderWindow window(sf::VideoMode(600, 800), "Freaking Math");

	Intro s0;
	Screens.push_back(&s0);
	Play s1;
	Screens.push_back(&s1);
	GameOver s2;
	Screens.push_back(&s2);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}

}