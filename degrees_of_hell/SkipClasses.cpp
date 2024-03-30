#include "SkipClasses.h"
#include "CPlayer.h"


SkipClasses::SkipClasses(int type, std::string name)
	: CSpace(type, name)
{
}

void SkipClasses::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << " and hangs out with their dodgy mates" << std::endl;
}
