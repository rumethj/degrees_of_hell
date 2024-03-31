#pragma once

#include <string>
#include <vector>

class Board;
class CSpace;

class CPlayer
{
private:
    std::string mName;
    int mYear;
    int mMotivation;
    int mSuccess;
    int mPosition;
    Board& mpBoard;
    std::vector<CSpace*> mCompletedAssessments;

public:
    /**
     * @brief Constructor for CPlayer class
     *
     * Initializes member variables of CPlayer class.
     *
     * @param[in] name The name of the player
     * @param[in] board Reference to the game board
     */
    CPlayer(std::string name, Board& board);

    /**
     * @brief Retrieves the name of the player
     *
     * @return mName The name of the player
     */
    std::string GetName() const;

    /**
     * @brief Retrieves the position of the player on the board
     *
     * @return The position of the player
     */
    int GetPosition() const;

    /**
     * @brief Retrieves the motivation level of the player
     *
     * @return The motivation level of the player
     */
    int GetMotivation() const;

    /**
     * @brief Retrieves the success score of the player
     *
     * @return The success score of the player
     */
    int GetSuccess() const;


    /**
     * @brief Retrieves the year of the game
     *
     * @return The current year of the game
     */
    int GetYear() const;

    /**
     * @brief Retrieves the plagiarism hearing index from the board
     *
     * @return The plagiarism hearing index
     */
    int GetPlagiarismHearingIndex() const;

    /**
     * @brief Sets the position of the player on the board
     *
     * @param[in] pos The position to set
     */
    void SetPosition(int pos);

    /**
     * @brief Increases the motivation level of the player
     *
     * @param[in] motivation The amount to add to the motivation level
     */
    void AddMotivation(int motivation);

    /**
     * @brief Decreases the motivation level of the player
     *
     * @param[in] motivation The amount to deduct from the motivation level
     */
    void DeductMotivation(int motivation);

    /**
     * @brief Increases the success level of the player
     *
     * @param[in] success The amount to add to the success level
     */
    void AddSuccess(int success);

    /**
     * @brief Adds a completed assessment to the player's list
     *
     * @param[in] assessment Reference to the completed assessment
     */
    void AddCompleteAssessment(CSpace& assessment);

    /**
     * @brief Updates the year player is in
     *
     * Increments the current player year to the next year
     */
    void UpdateYear();
};


