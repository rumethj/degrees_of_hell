#pragma once
#include "CSpace.h"
class WelcomeWeek : public CSpace
{

public:
    WelcomeWeek(int type, std::string name);

    ~WelcomeWeek();

    void PlayerLands(CPlayer& player) override;

};