#include"PlayScreen.h"
#include"ButtonPressed.h"
#include"Processing.h"
#include"WorkingWithScore.h"
#include"WorkingWithQA.h"
#include"WorkingWithLevel.h"
#include"SFML/Audio.hpp"

#include<iostream>

using namespace std;


int Play::Run(sf::RenderWindow &window)
{
	So so;
	Capdo capdo;
	Toantu toantu;
	Diem diem;
	DieuKienTroChoi dieukien;
	TraLoi traloi;

	int color; // mau background

	bool checkplay;   //bien kiem tra xem chuot co duoc bam khong

	// chuyen bien cua cac doi tuong tu dang string sang dang text de in ra man hinh
	string S_num1, S_num2, S_RandomResult, S_countdown, S_score, S_calculation; 


	//declare text form of objects
	sf::Text text_num1;
	sf::Text text_num2;
	sf::Text text_operator;
	sf::Text text_calculation;
	sf::Text text_assign;
	sf::Text text_RandomResult;
	sf::Text text_countdown;
	sf::Text text_score;


	// load font chu
	sf::Font font;                           
	if (!font.loadFromFile("ANCUU.ttf"))
	{
		cout << "Error Loading File";
	}


	// display your score
	sf::Text display_score;                 
	display_score.setFont(font);
	display_score.setString("Score: ");
	display_score.setPosition(380, 10);
	display_score.setCharacterSize(20);
	display_score.setFillColor(sf::Color::White);
	display_score.setStyle(sf::Text::Bold);

	//set timer
	sf::Text time_left;                      
	time_left.setFont(font);
	time_left.setString("Time Left: ");
	time_left.setPosition(380, 50);
	time_left.setCharacterSize(20);
	time_left.setFillColor(sf::Color::White);
	time_left.setStyle(sf::Text::Bold);


	// set fixed time
	sf::Clock clock;                        
	sf::Time timeline = sf::seconds(1);    



	// load False Button for TRUE answer
	sf::Texture TrueButton_Image;
	if (!TrueButton_Image.loadFromFile("TrueButton.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite TrueButton;
	TrueButton.setTexture(TrueButton_Image);
	TrueButton.setPosition(sf::Vector2f(65, 500));  // cai dat vi tri cua nut
	TrueButton.setTextureRect(sf::IntRect(0, 0, 237, 203)); // cai dat do phan giai cua nut



	// load False Button for FALSE answer
	sf::Texture FalseButton_Image;
	if (!FalseButton_Image.loadFromFile("FalseButton.png"))
	{
		cout << "Error Loading File";
	}
	sf::Sprite FalseButton;
	FalseButton.setTexture(FalseButton_Image);
	FalseButton.setPosition(sf::Vector2f(310, 500));  // cai dat vi tri cua nut
	FalseButton.setTextureRect(sf::IntRect(0, 0, 223, 206));  // cai dat do phan giai cua nut


	/*Load Sound*/
	sf::SoundBuffer TrueSound;
	if (!TrueSound.loadFromFile("TrueSound.flac"))
	{
		cout << "Error Loading File";
	}

	sf::Sound True;
	True.setBuffer(TrueSound);
	


	/*random mau cua background*/
	srand((unsigned int)time(NULL));
	color = rand() % 6 + 1;
	

	// creat the first equation
	RandomQuestion(so, toantu, capdo);
	Process_Calculation(so, toantu, S_num1, S_num2, S_calculation, text_calculation, font);
	Process_Assign(toantu, text_assign, font);
	Process_RandomResult(so, S_RandomResult, text_RandomResult, font);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event) && dieukien.flag == 1)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:

				IsButtonPressed(TrueButton, FalseButton, window, checkplay, traloi);

				checkTheAnswer(traloi, dieukien, so);  // kiem tra dap an dung hay sai 

				addScore(dieukien, diem);              // cong 1 diem neu tra loi dung
				Process_Score(diem, S_score, text_score, font);

				if (checkplay == true)
				{
					if (dieukien.flag == 1)
					{
						True.play();     // play sound if your answer is correct

						RandomQuestion(so, toantu, capdo);
						Process_Calculation(so, toantu, S_num1, S_num2, S_calculation, text_calculation, font);
						Process_Assign(toantu, text_assign, font);
						Process_RandomResult(so, S_RandomResult, text_RandomResult, font);

						updateLevel(diem, capdo);  // nang cap do 
						clock.restart();           // khoi dong lai bien dem
					}
				}
				break;
			}

		}

		if (color == 1)
			window.clear(sf::Color::Green);
		else if (color == 2)
			window.clear(sf::Color::Cyan);
		else if (color == 3)
			window.clear(sf::Color::Blue);
		else if (color == 4)
			window.clear(sf::Color::Red);
		else if (color == 5)
			window.clear(sf::Color::Magenta);
		else
			window.clear(sf::Color::Yellow);
		window.draw(display_score);
		window.draw(text_score);
		window.draw(time_left);
		window.draw(TrueButton);
		window.draw(FalseButton);
		window.draw(text_calculation);
		window.draw(text_assign);
		window.draw(text_RandomResult);
		if (dieukien.flag == 2)
		{
			returnBestScore(dieukien, diem);
			resetLevel(diem, capdo);

			/*tra gia tri cua ham Run de chuyen sang man hinh GameOver*/
			return 2;  
		}
		else if(dieukien.flag==1&&diem.score>0)
		{
			sf::Time elapsed = clock.getElapsedTime();       // bien dem thoi gian da qua
			sf::Int32 countdown = elapsed.asMilliseconds();  // bien chuyen thoi gian tu kieu Time sang Int
			if (elapsed.asMilliseconds() >= timeline.asMilliseconds())
			{
				dieukien.flag = 2;
			}
			Process_Counting(countdown, S_countdown, text_countdown, font);
			window.draw(text_countdown);
		}
		window.display();
	}

	return -1;
}