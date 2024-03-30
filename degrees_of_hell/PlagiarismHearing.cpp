#include "PlagiarismHearing.h"
#include "CPlayer.h"

PlagiarismHearing::PlagiarismHearing(int type, std::string name)
	: CSpace(type, name)
{
}

void PlagiarismHearing::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << " and supports their friend" << std::endl;
}
