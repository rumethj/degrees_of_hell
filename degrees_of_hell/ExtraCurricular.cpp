#include "ExtraCurricular.h"
#include "CPlayer.h"

ExtraCurricular::ExtraCurricular(int type,
	std::string name,
	int motivationalCost)
	: CSpace(type, name),
	mMotivationalCost(motivationalCost),
	mSuccessAchievement(20)
{
}

void ExtraCurricular::PlayerLands(CPlayer& player)
{
	// Player landing message
	std::cout << player.GetName() << " lands on " << mName << std::endl;

	// CHECK if player has already done this assignment (store vector in player as well)
	bool playerHasCompleted = false;
	for (int i = 0; i < mUndertakenBy.size(); i++)
	{
		if (mUndertakenBy[i] == &player) // CHECK
		{
			playerHasCompleted = true;
		}
	}

	if (!playerHasCompleted)
	{
		if (mUndertakenBy.empty()) //(mpCompletedBy.size() < 1)
		{
			if (player.GetMotivation() >= mMotivationalCost)
			{
				player.DeductMotivation(mMotivationalCost);
				player.AddSuccess(mSuccessAchievement);
				mUndertakenBy.push_back(&player);

				player.AddCompleteAssessment(*this);

				std::cout << player.GetName() << " undertakes " << mName << " for " << mMotivationalCost << " and achieves " << mSuccessAchievement << std::endl;
			}
		}
		else
		{
			if (player.GetMotivation() >= mMotivationalCost / 2)
			{
				player.DeductMotivation(mMotivationalCost / 2);
				player.AddSuccess(mSuccessAchievement / 2);
				mUndertakenBy.push_back(&player);

				player.AddCompleteAssessment(*this);
				mUndertakenBy[0]->AddSuccess(mSuccessAchievement / 2); // Success addition for previous completor
				mUndertakenBy[0]->AddMotivation(mMotivationalCost / 2); // Success addition for previous completor

				std::cout << player.GetName() << " undertakes " << mName << " for " << mMotivationalCost / 2 << " and achieves " << mSuccessAchievement / 2 << std::endl;
				std::cout << player.GetName() << " motivates " << mUndertakenBy[0]->GetName() << " by joining their activity" << std::endl;
			}
		}
	}
}