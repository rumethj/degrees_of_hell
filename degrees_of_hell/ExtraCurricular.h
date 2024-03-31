#pragma once
#include "CSpace.h"

#include <vector>

class ExtraCurricular : public CSpace
{
private:
    int mMotivationalCost;
    int mSuccessAchievement;
    std::vector<CPlayer*> mUndertakenBy;

public:
    /**
     * @brief Constructor for ExtraCurricular class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the extracurricular activity
     * @param[in] motivationalCost The motivational cost of undertaking the activity
     */
    ExtraCurricular(int type, std::string name, int motivationalCost);

    ~ExtraCurricular();

    /**
     * @brief Handles actions when a player lands on the extracurricular activity space
     * 
     * Checks if the player has already undertaken this activity and undertakes it accordingly.
     *
     * @param[in] player The player landing on the extracurricular activity space
     */
    void PlayerLands(CPlayer& player) override;

    /**
     * @brief Undertakes the extracurricular activity for a player
     *
     * Deducts motivational cost, adds success achievement, and marks the activity as undertaken by the player.
     *
     * @param[in] player The player undertaking the activity
     */
    void Undertake(CPlayer& player);

    /**
     * @brief Undertakes the extracurricular activity for a player with help from a previous participant
     *
     * Deducts half of the motivational cost and adds half of the success achievement for the current player.
     * Marks the activity as undertaken by the current player and adds half of the success achievement
     * to the player who previously undertook the activity.
     * Also, adds motivation to the previous participant to motivate them.
     *
     * @param[in] currentPlayer The current player undertaking the activity
     * @param[in] previousPlayer The player who previously undertook the activity
     */
    void Undertake(CPlayer& currentPlayer, CPlayer& previousPlayer);


};
