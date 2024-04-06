#pragma once
#include <map>

#include "CSpace.h"
#include "Spinner.h"

class Bonus : public CSpace
{
private:
    Spinner& mSpinner;
    std::map<int, std::pair<std::string, int>> mBonusData;

public:
    /**
     * @brief Constructor for Bonus class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the space
     * @param[in] spinner Reference to the spinner object
     */
    Bonus( int type, std::string name, Spinner& spinner );

    ~Bonus();


    /**
     * @brief Handles actions when a player lands on the Bonus space
     *
     * The player's motivation is affected based on the result of spinning the spinner.
     *
     * @param[in] player The player landing on the Bonus space
     */
    void PlayerLands( CPlayer& player ) override;

private:
    /**
     * @brief Initialises the bonus data map with spin messages and motivation gains
     *
     * Populates the bonus data map with spin messages and corresponding motivation gains.
     */
    void InitialiseBonusData( );

};

