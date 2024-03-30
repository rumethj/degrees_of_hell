#pragma once
#include "CSpace.h"
#include "Spinner.h"

class Bonus : public CSpace
{
private:
    Spinner& mSpinner;

public:
    Bonus(int type, std::string name, Spinner& spinner);

    ~Bonus();

    void PlayerLands(CPlayer& player) override;

};

