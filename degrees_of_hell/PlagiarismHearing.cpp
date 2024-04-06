#include "PlagiarismHearing.h"

PlagiarismHearing::PlagiarismHearing( int type, std::string name )
	: CSpace( type, name )
{
}


void PlagiarismHearing::PlayerLands( CPlayer& player )
{
	// Player landing message
	std::cout << player.GetName( ) << " lands on " << GetName( ) << " and supports their friend" << std::endl;
}
