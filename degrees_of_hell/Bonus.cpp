#include "Bonus.h"

Bonus::Bonus(int type,
	std::string name,
	Spinner& spinner)
	: CSpace(type, name),
	mSpinner(spinner)
{
	InitialiseBonusData();
}

Bonus::~Bonus()
{
	delete &mBonusData;
}

void Bonus::InitialiseBonusData() {
	// Initialize map with bonus spin messages and motivation gains
	mBonusData[1] = std::make_pair("Recieve some useful feedback. Gain motivation of 20", 20);
	mBonusData[2] = std::make_pair("Win a hackathon. Gain motivation of 50", 50);
	mBonusData[3] = std::make_pair("Get a free coffee with full loyalty card. Gain motivation of 80", 80);
	mBonusData[4] = std::make_pair("Impress your lecturer in class. Gain motivation of 100", 100);
	mBonusData[5] = std::make_pair("Motivational talk from course leader. Gain motivation of 5", 5);
	mBonusData[6] = std::make_pair("Secure an industry placement. Gain motivation of 150", 150);
	mBonusData[7] = std::make_pair("Attend an inspiring C++ lecture. Gain motivation of 200", 200);
	mBonusData[8] = std::make_pair("Get your best ever assignment mark. Gain motivation of 300", 300);
	mBonusData[9] = std::make_pair("Make a new romantic friend. Gain motivation of 150", 150);
	mBonusData[10] = std::make_pair("Get elected School President. Gain motivation of 10", 10);
}



void Bonus::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << GetName() << std::endl;

	// Spinning again
	int bonusSpin = mSpinner.GetSpin(player);
	std::cout << mBonusData[bonusSpin].first << std::endl;
	player.AddMotivation(mBonusData[bonusSpin].second);

	std::cout << player.GetName() << " has " << player.GetMotivation() << std::endl;
}