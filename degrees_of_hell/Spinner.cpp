#include "Spinner.h"

Spinner::Spinner(std::string filePath) 
{
    std::ifstream seedFile(filePath);
    if (seedFile) 
    {
        seedFile >> mSeed; // Read the seed value from the file
        seedFile.close(); // Close the file
    }
    else 
    {
        // Handle error if file cannot be opened
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        std::cout << "Seed set to default: 48" << std::endl;

        // Use a default seed value in case of failure
        mSeed = 48;
    }

    // Seed the random number generator with the obtained seed value
    srand(mSeed);
}

// Spin function to get a random number between 1 and 10
int Spinner::GetRandom()
{
    return static_cast<int>(static_cast<double>(rand()) / (RAND_MAX + 1) * 10.0f + 1);
}

int Spinner::GetSpin(CPlayer& player)
{
    int playerSpin = GetRandom();
    std::cout << player.GetName() << " spins " << playerSpin << std::endl;

    return playerSpin;
}