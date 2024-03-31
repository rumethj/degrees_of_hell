#include "WelcomeWeek.h"

WelcomeWeek::WelcomeWeek(int type, std::string name)
	: CSpace(type, name)
{
}


void WelcomeWeek::PlayerLands(CPlayer& player)
{
	// Updating data
	player.AddMotivation(250);
	player.UpdateYear();

	// Player landing message
	std::cout << player.GetName() << " attends Welcome Week and starts year " << player.GetYear() << " more motivated!" << std::endl;
}
