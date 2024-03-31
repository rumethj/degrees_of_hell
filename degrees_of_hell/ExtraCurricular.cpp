#include "ExtraCurricular.h"

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
		if (mUndertakenBy.empty())
		{
			if (player.GetMotivation() >= mMotivationalCost)
			{
				Undertake(player);
			}
		}
		else
		{
			if (player.GetMotivation() >= mMotivationalCost / 2)
			{
				Undertake(player, *mUndertakenBy[0]);
			}
		}
	}
}

void ExtraCurricular::Undertake(CPlayer& player)
{
	player.DeductMotivation(mMotivationalCost);
	player.AddSuccess(mSuccessAchievement);
	mUndertakenBy.push_back(&player);

	player.AddCompleteAssessment(*this);

	std::cout << player.GetName() << " undertakes " << mName << " for " << mMotivationalCost << " and achieves " << mSuccessAchievement << std::endl;
}

void ExtraCurricular::Undertake(CPlayer& currentPlayer, CPlayer& previousPlayer)
{
	currentPlayer.DeductMotivation(mMotivationalCost / 2);
	currentPlayer.AddSuccess(mSuccessAchievement / 2);
	mUndertakenBy.push_back(&currentPlayer);

	currentPlayer.AddCompleteAssessment(*this);
	previousPlayer.AddSuccess(mSuccessAchievement / 2); // Success addition for previous completor
	previousPlayer.AddMotivation(mMotivationalCost / 2); // Success addition for previous completor

	std::cout << currentPlayer.GetName() << " undertakes " << mName << " for " << mMotivationalCost / 2 << " and achieves " << mSuccessAchievement / 2 << std::endl;
	std::cout << currentPlayer.GetName() << " motivates " << previousPlayer.GetName() << " by joining their activity" << std::endl;
}