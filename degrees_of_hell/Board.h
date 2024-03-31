#pragma once

#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "Assessment.h"
#include "WelcomeWeek.h"
#include "SkipClasses.h"
#include "PlagiarismHearing.h"
#include "AccusedOfPlagiarism.h"
#include "ExtraCurricular.h"
#include "Bogus.h"
#include "Bonus.h"

#include "Spinner.h"


class CPlayer;
class CSpace;

class Board
{
private:
    Spinner& mSpinner;
    std::vector<CSpace*> mBoard;
    int mPlagiarismHearingIndex;
    int mAccusedOfPlagiarismIndex;

public:
    /**
     * @brief Constructor for Board class
     *
     * Initializes member variables of the Board class and creates the game board.
     *
     * @param[in] setUpFilePath The file path for setting up the board
     * @param[in] spinner Reference to the spinner object
     */
    Board(std::string setUpFilePath, Spinner& spinner);

    ~Board();



    /**
     * @brief Retrieves the size of the board
     *
     * @return The size of the board
     */
    int GetSize() const;


     /**
      * @brief Retrieves the index of the first space with the specified type
      *
      * @param[in] type The type of space to search for
      * @return The index of the first space with the specified type
      */
    int GetSpaceIndex(int type) const;


    /**
     * @brief Retrieves the name of the space at the given position
     *
     * @param[in] spacePos The position of the space
     * @return The name of the space at the specified position
     */
    std::string GetSpaceName(int spacePos) const;

    /**
     * @brief Displays the names of all spaces on the board
     */
    void ShowBoard() const;

    /**
     * @brief Executes the action associated with the space where the player lands
     *
     * @param[in] player Reference to the player landing on a space
     */
    void RunSpaceAction( CPlayer& player );

private:
    /**
     * @brief Creates the game board based on the setup file
     *
     * Reads the setup file, creates different types of spaces, and populates the game board.
     *
     * @param[in] setUpFilePath The file path for setting up the board
     * @param[in] spinner Reference to the spinner object
     */
    void CreateBoard(std::string setUpFilePath, Spinner& spinner);
};
