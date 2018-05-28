#include<vector>
#include"IntroScreen.h"
#include"PlayScreen.h"
#include"GameOver.h"

using namespace std;


int main()
{

	std::vector<Screen*> Screens;
	int screen = 0; // chi so man hinh
	sf::RenderWindow window(sf::VideoMode(600, 800), "Freaking Math");

	Intro intro;
	Screens.push_back(&intro);
	Play play;
	Screens.push_back(&play);
	GameOver gameover;
	Screens.push_back(&gameover);

	//Main loop
	while (screen >= 0)
	{
		// tra ve gia tri cua chi so mang Screens
		screen = Screens[screen]->Run(window);
	}

}