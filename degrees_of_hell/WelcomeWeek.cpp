#include "WelcomeWeek.h"

WelcomeWeek::WelcomeWeek(int type, std::string name)
	: CSpace(type, name),
	mMotivationGain(250)
{
}


void WelcomeWeek::PlayerLands(CPlayer& player)
{
	// Updating data
	player.AddMotivation(mMotivationGain);
	player.UpdateYear();

	// Player landing message
	std::cout << player.GetName() << " attends Welcome Week and starts year " << player.GetYear() << " more motivated!" << std::endl;
}
