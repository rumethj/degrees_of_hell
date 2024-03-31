#pragma once

#include "CSpace.h"
#include "Board.h"




class AccusedOfPlagiarism :public CSpace
{
private:
    int mMotivationCost;
    const int mkPlagiarismHearingIndex = 6;

public:

    /**
     * @brief Constructor for AccusedOfPlagiarism class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the space
     */
    AccusedOfPlagiarism(int type, std::string name);

    ~AccusedOfPlagiarism();


    /**
     * @brief Handles actions when a player lands on the AccusedOfPlagiarism space
     *
     * Executes actions related to a player landing on the AccusedOfPlagiarism space.
     * Moves the player to the plagiarism hearing index and deducts motivation.
     *
     * @param[in] player The player landing on the AccusedOfPlagiarism space
     */
    void PlayerLands(CPlayer& player) override;

};


