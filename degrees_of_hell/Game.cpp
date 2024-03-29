#include "Game.h"

#include <iostream>

int Game::Random()
{
    return static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1) * 10.0f + 1 );
}

Game::Game(std::vector<std::string> players, std::string filePath, int rounds)
{
    InitialisePlayers(players);
    InitialiseBoard(filePath);

    mRounds = rounds;
    mCurrentRound = 1;
}

void Game::InitialisePlayers(std::vector<std::string> players)
{
    for (int i = 0; i < players.size(); i++)
    {
        mPlayers.push_back(new CPlayer(players[i]));
    }
}

void Game::InitialiseBoard(std::string filePath)
{
    mpBoard = new Board(filePath);
}

void Game::EndGame()
{
    std::cout << "Game Over" << std::endl;
}

void Game::StartGame()
{
    //srand(static_cast<unsigned int> (time(0)));
    srand( 4 ); // Set the seed
    
    //mpBoard->ShowBoard();

    // Welcome message
    std::cout << "Welcome to Scumbag College" << std::endl;
    std::cout << std::endl;

    // Play amount of rounds
    for (int round = 1; round <= mRounds; round++)
    {
        
        std::cout << "Round " << round << std::endl;
        std::cout << "=========" << std::endl;
        for (int j = 0; j < mPlayers.size(); j++)
        {
            

            int playerSpin = Random();
            std::cout << mPlayers[j]->GetName() << " spins " << playerSpin << std::endl;

            int newPlayerPosition = mPlayers[j]->GetPosition() + playerSpin;
            mPlayers[j]->SetPosition(newPlayerPosition % mpBoard->GetSize());

            //std::cout << mPlayers[j]->GetName() << " lands on " << mpBoard->GetSpaceName(mPlayers[j]->GetPosition()) << std::endl;
            mpBoard->RunSpaceAction( *mPlayers[j] );
            
            if (newPlayerPosition >= mpBoard->GetSize()) // Passes or lands on Welcome Week //mpBoard->GetSpaceName(mPlayers[j]->GetPosition()) == "Welcome Week" || CHECK 
            {
                mPlayers[j]->AddMotivation(250);
                mPlayers[j]->UpdateYear();
                std::cout << mPlayers[j]->GetName() << " attends Welcome Week and starts year " << mPlayers[j]->GetYear() << " more motivated!" << std::endl;
            }

            std::cout << std::endl;
        }

        

    }
}