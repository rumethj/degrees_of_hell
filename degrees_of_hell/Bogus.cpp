#include "Bogus.h"

Bogus::Bogus(int type,
	std::string name,
	Spinner& spinner)
	: CSpace(type, name),
	mSpinner(spinner)
{
}

void Bogus::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << std::endl;

	int bonusSpin = mSpinner.Random();

	switch (bonusSpin)
	{
	case 1:
		std::cout << "Fall asleep in a boring lecture. Lose motivation of 20" << std::endl;
		player.DeductMotivation(20);
		break;
	case 2:
		std::cout << "Meet with coach about poor attendance. Lose motivation of 50" << std::endl;
		player.DeductMotivation(50);
		break;
	case 3:
		std::cout << "Feel really tired after a night out. Lose motivation of 80" << std::endl;
		player.DeductMotivation(80);
		break;
	case 4:
		std::cout << "Get kicked out of lab for messing about. Lose motivation of 100" << std::endl;
		player.DeductMotivation(100);
		break;
	case 5:
		std::cout << "Get dumped before a big night out. Lose motivation of 150" << std::endl;
		player.DeductMotivation(150);
		break;
	case 6:
		std::cout << "Fail an assignment. Lose motivation of 200" << std::endl;
		player.DeductMotivation(200);
		break;
	case 7:
		std::cout << "Get caught skipping class. Lose motivation of 50" << std::endl;
		player.DeductMotivation(50);
		break;
	case 8:
		std::cout << "Your friend drops out of uni. Lose motivation of 200" << std::endl;
		player.DeductMotivation(200);
		break;
	case 9:
		std::cout << "Nobody turns up to teach your class. Lose motivation of 300" << std::endl;
		player.DeductMotivation(300);
		break;
	case 10:
		std::cout << "Lecturer changes assignment schedule. Lose motivation of 20" << std::endl;
		player.DeductMotivation(20);
		break;
	}

	// CHECK if MESSAGE needed - according assignment brief yes
	//std::cout << player.GetName() << " has " << player.GetMotivation() << std::endl;
}