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
	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << std::endl;
	 
	// CHECK if player has already done this assignment (store vector in player as well)
	bool playerHasCompleted = false;
	for (int i = 0; i < mCompletedBy.size(); i++)
	{
		if (mCompletedBy[i] == &player)
		{
			playerHasCompleted = true;
		}
	}

	if (!playerHasCompleted)
	{
		if (mCompletedBy.empty())
		{
			if (player.GetMotivation() >= mMotivationalCost)
			{
				Complete(player);
			}
		}
		else
		{
			if (player.GetMotivation() >= mMotivationalCost / 2)
			{
				Complete(player, *mCompletedBy[0]);
			}
		}
	}
}

void Assessment::Complete(CPlayer& player)
{
	player.DeductMotivation(mMotivationalCost);
	player.AddSuccess(mSuccessAchievement);
	mCompletedBy.push_back(&player);

	player.AddCompleteAssessment(*this);

	std::cout << player.GetName() << " completes " << mName << " for " << mMotivationalCost << " and achieves " << mSuccessAchievement << std::endl;
}

void Assessment::Complete(CPlayer& currentPlayer, CPlayer& completedPlayer)
{
	currentPlayer.DeductMotivation(mMotivationalCost / 2);
	currentPlayer.AddSuccess(mSuccessAchievement / 2);
	mCompletedBy.push_back(&currentPlayer);

	currentPlayer.AddCompleteAssessment(*this);
	completedPlayer.AddSuccess(mSuccessAchievement / 2); // Success addition for previous completor

	std::cout << currentPlayer.GetName() << " completes " << mName << " for " << mMotivationalCost / 2 << " and achieves " << mSuccessAchievement / 2 << std::endl;
	std::cout << completedPlayer.GetName() << " helps and achieves " << mSuccessAchievement / 2 << std::endl;
}