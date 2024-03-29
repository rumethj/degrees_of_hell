#pragma once
#include "CPlayer.h"

#include <string>
#include <iostream>


class CSpace
{
protected:
    int mType;
    std::string mName;

public:
    CSpace( int type, std::string name );

    ~CSpace();

    std::string GetName() const;

    /**@brief Action to take when player lands on space.
     *
     *The type of space will determine what action to take
    */
    virtual void PlayerLands( CPlayer& player );
};

