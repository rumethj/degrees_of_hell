#pragma once

#include "CSpace.h"
class WelcomeWeek : public CSpace
{

public:
    /**
     * @brief Constructor for WelcomeWeek class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the Welcome Week space
     */
    WelcomeWeek(int type, std::string name);

    ~WelcomeWeek();

    /**
     * @brief Handles actions when a player lands on the Welcome Week space
     * 
     * Increases the player's motivation by 250 and updates their year.
     * Prints a message indicating the player's attendance at Welcome Week.
     *
     * @param[in] player The player landing on the Welcome Week space
     */
    void PlayerLands(CPlayer& player) override;

};