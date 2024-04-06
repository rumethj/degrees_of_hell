#include "ExtraCurricular.h"

ExtraCurricular::ExtraCurricular( int type, std::string name, int motivationalCost )
	: CSpace( type, name ), mMotivationalCost( motivationalCost ), mSuccessAchievement( 20 )
{
}

ExtraCurricular::~ExtraCurricular( )
{
	for ( int i = 0; i < mUndertakenBy.size(); i++ )
	{
		delete mUndertakenBy[ i ];
	}
}


void ExtraCurricular::PlayerLands( CPlayer& player )
{
	// Player landing message
	std::cout << player.GetName( ) << " lands on " << GetName( ) << std::endl;


	if ( mUndertakenBy.empty( ) )
	{
		if ( player.GetMotivation( ) >= mMotivationalCost ) // Checking for adequate motivation
		{
			UndertakeActivity( player );
		}
		else
		{
			std::cout << player.GetName( ) << " doesn't have the " << mMotivationalCost << " motivation to undertake the activity " << GetName( ) << std::endl;
		}
	}
	else
	{
		// Checking if current player has already completed the assessment
		bool hasPlayerUndertaken = false;
		for ( int i = 0; i < mUndertakenBy.size( ); i++ )
		{
			if ( mUndertakenBy[ i ] == &player )
			{
				hasPlayerUndertaken = true;
			}
		}

		if ( hasPlayerUndertaken )
		{
			std::cout << player.GetName( ) << " has already undertaken the activity " << GetName( ) << std::endl;
		}
		else
		{
			if ( player.GetMotivation( ) >= mMotivationalCost / 2 ) // Checking for adequate motivation
			{
				UndertakeActivity( player, *mUndertakenBy[ 0 ] );
			}
			else
			{
				std::cout << player.GetName( ) << " doesn't have the " << mMotivationalCost / 2 << " motivation to undertake the activity " << GetName( ) << std::endl;
			}
		}
	}

}

void ExtraCurricular::UndertakeActivity( CPlayer& player )
{
	player.DeductMotivation( mMotivationalCost );
	player.AddSuccess( mSuccessAchievement );
	mUndertakenBy.push_back( &player );


	std::cout << player.GetName( ) << " undertakes " << GetName( ) << " for " << mMotivationalCost << " and achieves " << mSuccessAchievement << std::endl;
}

void ExtraCurricular::UndertakeActivity( CPlayer& currentPlayer, CPlayer& previousPlayer )
{
	currentPlayer.DeductMotivation( mMotivationalCost / 2 );
	currentPlayer.AddSuccess( mSuccessAchievement / 2 );
	mUndertakenBy.push_back (&currentPlayer );

	previousPlayer.AddSuccess( mSuccessAchievement / 2 ); // Success addition for previous completor
	previousPlayer.AddMotivation( mMotivationalCost / 2 ); // Success addition for previous completor

	std::cout << currentPlayer.GetName( ) << " undertakes " << GetName( ) << " for " << mMotivationalCost / 2 << " and achieves " << mSuccessAchievement / 2 << std::endl;
	std::cout << currentPlayer.GetName( ) << " motivates " << previousPlayer.GetName( ) << " by joining their activity" << std::endl;
}