#include "WelcomeWeek.h"

WelcomeWeek::WelcomeWeek(int type, std::string name)
	: CSpace(type, name),
	mMotivationGain(250)
{
}


void WelcomeWeek::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << GetName() << std::endl;
}
