#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "CPlayer.h"

class Spinner
{
private:
    int mSeed;

public:
    /**
     * @brief Constructor for Spinner class
     *
     * Initializes the spinner with a seed value obtained from a file.
     *
     * @param[in] filePath File path to read the seed value from
     */
    Spinner(std::string filePath);


    /**
     * @brief Generates a random number between 1 and 10
     *
     * @return A random integer between 1 and 10
     */
    int GetRandom() const;

    /**
     * @brief Simulates a spin for a player and returns the result
     *
     * Generates a random spin for the given player and prints the spin result.
     *
     * @param[in] player The player spinning the spinner
     * @return The spin result (a random integer between 1 and 10)
     */
    int GetSpin(CPlayer& player) const;
};

