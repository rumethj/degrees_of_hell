#pragma once
#include "CSpace.h"
#include "Spinner.h"

class Bogus : public CSpace
{
private:
    Spinner& mSpinner;

public:
    Bogus(int type, std::string name, Spinner& spinner);

    ~Bogus();

    void PlayerLands(CPlayer& player) override;

};