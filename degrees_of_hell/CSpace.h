#pragma once

#include "CPlayer.h"

#include <string>
#include <iostream>

class CSpace
{
private:
    int mType = 0;
    std::string mName = "";

public:
    /**
     * @brief Constructor for CSpace class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the space
     */
    CSpace( int type, std::string name );

    /**
     * @brief Gets the name of the space
     *
     * @return mName The name of the space
     */
    std::string GetName( ) const;

    /**
     * @brief Gets the type of the space
     *
     * @return mType The type of the space
     */
    int GetType( ) const;

    /**
     * @brief Handles actions when a player lands on the space
     *
     * Executes actions related to a player landing on the space.
     * By default, it prints a message indicating the player has landed on the space.
     *
     * @param[in] player The player landing on the space
     */
    virtual void PlayerLands( CPlayer& player ) = 0;

};

