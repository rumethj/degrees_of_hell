#include "AccusedOfPlagiarism.h"

AccusedOfPlagiarism::AccusedOfPlagiarism(int type, std::string name)
	: CSpace(type, name),
	mMotivationCost(50)
{
}

void AccusedOfPlagiarism::PlayerLands(CPlayer& player)
{
	player.SetPosition(player.GetPlagiarismHearingIndex());
	player.DeductMotivation(mMotivationCost);


	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << " and goes to the hearing" << std::endl;
	std::cout << player.GetName() << " loses motivation" << std::endl;

}
