#pragma once

#include <iostream>
#include <vector>

#include "CSpace.h"


class Assessment : public CSpace
{
private:
    int mMotivationalCost;
    int mSuccessAchievement;
    int mYear;
    std::vector<CPlayer*> mCompletedBy;

public:
    /**
     * @brief Constructor for Assessment class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the assessment
     * @param[in] motivationalCost The motivational cost of completing the assessment
     * @param[in] successAchievement The success achieved upon completing the assessment
     * @param[in] year The year in which the assessment is due
     */
    Assessment(int type,std::string name,int motivationalCost,int successAchievement,int year);

    ~Assessment();

    /**
     * @brief Handles actions when a player lands on the assessment space
     *
     * @param[in] player The player landing on the assessment space
     */
    void PlayerLands(CPlayer& player) override;

    /**
     * @brief Completes the assessment for a player
     *
     * Deducts motivational cost, adds success achievement, and marks the assessment as completed by the player.
     *
     * @param[in] player The player completing the assessment
     */
    void Complete(CPlayer& player);

    /**
     * @brief Completes the assessment for a player with help from a previous completer
     *
     * Deducts half of the motivational cost and adds half of the success achievement for the current player.
     * Marks the assessment as completed by the current player and adds half of the success achievement
     * to the player who previously completed the assessment.
     *
     * @param[in] currentPlayer The current player completing the assessment
     * @param[in] completedPlayer The player who previously completed the assessment
     */
    void Complete(CPlayer& currentPlayer, CPlayer& completedPlayer);
};

