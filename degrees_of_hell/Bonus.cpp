#include "Bonus.h"

Bonus::Bonus(int type,
	std::string name,
	Spinner& spinner)
	: CSpace(type, name),
	mSpinner(spinner)
{
}

void Bonus::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << std::endl;

	int bonusSpin = mSpinner.GetRandom();

	switch (bonusSpin)
	{
	case 1:
		std::cout << "Recieve some useful feedback. Gain motivation of 20" << std::endl;
		player.AddMotivation(20);
		break;
	case 2:
		std::cout << "Win a hackathon. Gain motivation of 50" << std::endl;
		player.AddMotivation(50);
		break;
	case 3:
		std::cout << "Get a free coffee with full loyalty card. Gain motivation of 80" << std::endl;
		player.AddMotivation(80);
		break;
	case 4:
		std::cout << "Impress your lecturer in class. Gain motivation of 100" << std::endl;
		player.AddMotivation(100);
		break;
	case 5:
		std::cout << "Motivational talk from course leader. Gain motivation of 5" << std::endl;
		player.AddMotivation(5);
		break;
	case 6:
		std::cout << "Secure an industry placement. Gain motivation of 150" << std::endl;
		player.AddMotivation(150);
		break;
	case 7:
		std::cout << "Attend an inspiring C++ lecture. Gain motivation of 200" << std::endl;
		player.AddMotivation(200);
		break;
	case 8:
		std::cout << "Get your best ever assignment mark. Gain motivation of 300" << std::endl;
		player.AddMotivation(300);
		break;
	case 9:
		std::cout << "Make a new romantic friend. Gain motivation of 150" << std::endl;
		player.AddMotivation(150);
		break;
	case 10:
		std::cout << "Get elected School President. Gain motivation of 10" << std::endl;
		player.AddMotivation(10);
		break;
	}

	// CHECK if MESSAGE needed - according assignment brief yes
	//std::cout << player.GetName() << " has " << player.GetMotivation() << std::endl;
}