#include "Assessment.h"

Assessment::Assessment( int type,
	std::string name,
	int motivationalCost,
	int successAchievement,
	int year )
	: CSpace( type, name ),
	mMotivationalCost( motivationalCost ),
	mSuccessAchievement( successAchievement ),
	mYear( year )
{
}

void Assessment::PlayerLands( CPlayer& player )
{
	// add the printing line as well
}