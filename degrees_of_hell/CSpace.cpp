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

int CSpace::GetType() const
{
    return mType;
}

void CSpace::PlayerLands(CPlayer& player)
{
    // Landing message
    std::cout << player.GetName() << " lands on " << mName << std::endl;
}
