#include "Bogus.h"

Bogus::Bogus(int type,
	std::string name,
	Spinner& spinner)
	: CSpace(type, name),
	mSpinner(spinner)
{
	InitialiseBogusData();
}

Bogus::~Bogus()
{
	delete &mBogusData;
}

void Bogus::InitialiseBogusData() 
{
	// Initialize map with bonus spin messages and deduction values
	mBogusData[1] = std::make_pair("Fall asleep in a boring lecture. Lose motivation of 20", 20 );
	mBogusData[2] = std::make_pair("Meet with coach about poor attendance. Lose motivation of 50", 50);
	mBogusData[3] = std::make_pair("Feel really tired after a night out. Lose motivation of 80", 80);
	mBogusData[4] = std::make_pair("Get kicked out of lab for messing about. Lose motivation of 100", 100);
	mBogusData[5] = std::make_pair("Get dumped before a big night out. Lose motivation of 150", 150);
	mBogusData[6] = std::make_pair("Fail an assignment. Lose motivation of 200", 200);
	mBogusData[7] = std::make_pair("Get caught skipping class. Lose motivation of 50", 50);
	mBogusData[8] = std::make_pair("Your friend drops out of uni. Lose motivation of 200", 200);
	mBogusData[9] = std::make_pair("Nobody turns up to teach your class. Lose motivation of 300", 300);
	mBogusData[10] = std::make_pair("Lecturer changes assignment schedule. Lose motivation of 20", 20);
}

void Bogus::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << GetName() << std::endl;

	// Spinning again
	int bonusSpin = mSpinner.GetSpin(player);
	std::cout << mBogusData[bonusSpin].first << std::endl;
	player.DeductMotivation(mBogusData[bonusSpin].second);

	std::cout << player.GetName() << " has " << player.GetMotivation() << std::endl;
}