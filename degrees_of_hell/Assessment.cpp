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
		if (mCompletedBy[i] == &player) // CHECK
		{
			playerHasCompleted = true;
		}
	}

	if (!playerHasCompleted)
	{
		if (mCompletedBy.empty()) //(mCompletedBy.size() < 1)
		{
			if (player.GetMotivation() >= mMotivationalCost)
			{
				player.DeductMotivation(mMotivationalCost);
				player.AddSuccess(mSuccessAchievement);
				mCompletedBy.push_back(&player);

				player.AddCompleteAssessment(*this);

				std::cout << player.GetName() << " completes " << mName << " for " << mMotivationalCost << " and achieves " << mSuccessAchievement << std::endl;
			}
		}
		else
		{
			if (player.GetMotivation() >= mMotivationalCost / 2)
			{
				player.DeductMotivation(mMotivationalCost / 2);
				player.AddSuccess(mSuccessAchievement / 2);
				mCompletedBy.push_back(&player);

				player.AddCompleteAssessment(*this);
				mCompletedBy[0]->AddSuccess(mSuccessAchievement / 2); // Success addition for previous completor

				std::cout << player.GetName() << " completes " << mName << " for " << mMotivationalCost / 2 << " and achieves " << mSuccessAchievement / 2 << std::endl;
				std::cout << mCompletedBy[0]->GetName() << " helps and achieves " << mSuccessAchievement / 2 << std::endl;
			}
		}
	}
}