#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "CPlayer.h"
#include "Board.h"
#include "Spinner.h"

class Game
{
private:
    std::vector<CPlayer*> mPlayers;
    Board* mpBoard = nullptr;
    Spinner* mpSpinner = nullptr;
    int mRounds = 20;

public:
    /**
     * @brief Constructor for Game class
     *
     * Initializes the game board, players, spinner, and number of rounds.
     *
     * @param[in] players Vector containing names of players
     * @param[in] filePath File path for setting up the board
     * @param[in] rounds Number of rounds to play
     */
    Game( std::vector<std::string> players, std::string boardFilePath, int rounds );

    /**
     * @brief Destructor for Game class
     *
     * Delets all memory allocations in object
     */
    ~Game( );

    /**
     * @brief Starts the game and executes the rounds
     *
     * Displays a welcome message, plays the specified number of rounds, and updates player positions and actions accordingly.
     */
    void StartGame( );

    /**
     * @brief Ends the game and declares the winner
     */
    void EndGame( );

private:
    /**
     * @brief Initialises players for the game
     *
     * Creates player objects based on the provided names and adds them to the list of players.
     *
     * @param[in] players Vector containing names of players
     */
    void InitialisePlayers( std::vector<std::string> players );

    /**
     * @brief Initialises the game board
     *
     * Creates a game board object according to the file
     *
     * @param[in] filePath File path for setting up the board
     */
    void InitialiseBoard( std::string filePath );

};


