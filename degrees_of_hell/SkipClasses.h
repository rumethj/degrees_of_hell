#pragma once


#include "CSpace.h"
class SkipClasses : public CSpace
{

public:
    /**
     * @brief Constructor for SkipClasses class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the skip classes space
     */
    SkipClasses( int type, std::string name );


    /**
     * @brief Handles actions when a player lands on the skip classes space
     * 
     * Prints a message indicating that the player Skips classes and hangs out with their dodgy mates.
     *
     * @param[in] player The player landing on the skip classes space
     */
    void PlayerLands( CPlayer& player ) override;

};

