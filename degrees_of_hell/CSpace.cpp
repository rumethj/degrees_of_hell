#include "CSpace.h"
#include "CPlayer.h"

CSpace::CSpace(int type, std::string name)
    : mType(type),
    mName(name)
{

}


std::string CSpace::GetName() const
{
    return mName;
}

void CSpace::PlayerLands(CPlayer& player)
{
    // Landing message
    std::cout << player.GetName() << " lands on " << mName << std::endl;
}
