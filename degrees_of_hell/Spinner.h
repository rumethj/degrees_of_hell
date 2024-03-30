#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Spinner
{
private:
    int mSeed;

public:
    Spinner(std::string filePath);

    ~Spinner();

    // Spin function to get a random number between 1 and 10
    int GetRandom();
};

