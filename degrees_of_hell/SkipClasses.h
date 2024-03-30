#pragma once
#include "CSpace.h"
class SkipClasses : public CSpace
{

public:
    SkipClasses(int type, std::string name);

    ~SkipClasses();

    void PlayerLands(CPlayer& player) override;
};

