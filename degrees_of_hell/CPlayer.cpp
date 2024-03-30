#include "CPlayer.h"

CPlayer::CPlayer(std::string name) 
    : mName(name),
    mYear( 1 ),
    mMotivation( 1000 ),
    mSuccess( 0 ),
    mPosition( 0 )
{
    
}

std::string CPlayer::GetName() const
{
    return mName;
}

int CPlayer::GetPosition() const
{
    return mPosition;
}

int CPlayer::GetMotivation() const
{
    return mMotivation;
}


int CPlayer::GetSuccess() const
{
    return mSuccess;
}

int CPlayer::GetYear() const
{
    return mYear;
}


void CPlayer::SetPosition(int pos)
{
    mPosition = pos;
}

void CPlayer::AddMotivation(int motivation)
{
    mMotivation += motivation;
}

void CPlayer::DeductMotivation(int motivation)
{
    mMotivation -= motivation;
}

void CPlayer::AddSuccess(int success)
{
    mSuccess += success;
}

void CPlayer::UpdateYear()
{
    mYear += 1;
}