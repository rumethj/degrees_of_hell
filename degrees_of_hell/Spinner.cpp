#include "Spinner.h"

Spinner::Spinner()
{
   srand(48);
}

// Spin function to get a random number between 1 and 10
int Spinner::Random()
{
    return static_cast<int>(static_cast<double>(rand()) / (RAND_MAX + 1) * 10.0f + 1);
}