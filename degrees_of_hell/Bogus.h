#pragma once
#include <map>


#include "CSpace.h"
#include "Spinner.h"

class Bogus : public CSpace
{
private:
    Spinner& mSpinner;
    std::map<int, std::pair<std::string, int>> mBogusData;

public:
    /**
     * @brief Constructor for Bogus class
     *
     * Initializes a Bogus object with the provided parameters.
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the space
     * @param[in] spinner Reference to the spinner object
     */
    Bogus(int type, std::string name, Spinner& spinner);

    ~Bogus();

    /**
     * @brief Handles actions when a player lands on the Bogus space
     * 
     * The player's motivation is affected based on the result of spinning the spinner.
     *
     * @param[in] player The player landing on the Bogus space
     */
    void PlayerLands(CPlayer& player) override;

private:
    /**
     * @brief Initialises the bogus data map with spin messages and motivation costs
     *
     * Populates the bogus data map with spin messages and corresponding motivation costs.
     */
    void InitialiseBogusData();
};