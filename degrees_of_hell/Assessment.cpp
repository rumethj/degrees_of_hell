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
	std::cout << player.GetName() << " lands on " << GetName() << std::endl;
	 
	
	if (mCompletedBy.empty())
	{
		if (player.GetMotivation() >= mMotivationalCost) // Checking for adequate motivation
		{
			Complete(player);
		}
		else
		{
			std::cout << player.GetName() << " doesn't have the " << mMotivationalCost << " motivation to complete the " << GetName() << std::endl;
		}
	}
	else
	{
		// Checking if current player has already completed the assessment
		bool hasPlayerCompleted = false;
		for (int i = 0; i < mCompletedBy.size(); i++)
		{
			if (mCompletedBy[i] == &player)
			{
				hasPlayerCompleted = true;
			}
		}

		if (hasPlayerCompleted)
		{
			std::cout << player.GetName() << " has already completed the " << GetName() << std::endl;
		}
		else
		{
			if (player.GetMotivation() >= mMotivationalCost / 2) // Checking for adequate motivation
			{
				Complete(player, *mCompletedBy[0]);
			}
			else
			{
				std::cout << player.GetName() << " doesn't have the " << mMotivationalCost / 2 << " motivation to complete the " << GetName() << std::endl;
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

	std::cout << player.GetName() << " completes " << GetName() << " for " << mMotivationalCost << " and achieves " << mSuccessAchievement << std::endl;
}

void Assessment::Complete(CPlayer& currentPlayer, CPlayer& completedPlayer)
{
	currentPlayer.DeductMotivation(mMotivationalCost / 2);
	currentPlayer.AddSuccess(mSuccessAchievement / 2);
	mCompletedBy.push_back(&currentPlayer);

	currentPlayer.AddCompleteAssessment(*this);
	completedPlayer.AddSuccess(mSuccessAchievement / 2); // Success addition for previous completor

	std::cout << currentPlayer.GetName() << " completes " << GetName() << " for " << mMotivationalCost / 2 << " and achieves " << mSuccessAchievement / 2 << std::endl;
	std::cout << completedPlayer.GetName() << " helps and achieves " << mSuccessAchievement / 2 << std::endl;
}