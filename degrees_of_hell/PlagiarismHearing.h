#pragma once
#include "CSpace.h"

class PlagiarismHearing : public CSpace
{

public:
    /**
     * @brief Constructor for PlagiarismHearing class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the plagiarism hearing space
     */
    PlagiarismHearing(int type, std::string name);

    ~PlagiarismHearing();

    /**
     * @brief Handles actions when a player lands on the plagiarism hearing space
     * 
     * In this case, it prints a message indicating that the player supports their friend.
     *
     * @param[in] player The player landing on the plagiarism hearing space
     */
    void PlayerLands(CPlayer& player) override;

};
