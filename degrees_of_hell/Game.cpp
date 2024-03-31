#include "Game.h"


Game::Game(std::vector<std::string> players, std::string filePath, int rounds)
{
    InitialiseBoard(filePath);
    InitialisePlayers(players);
    mpSpinner = new Spinner("seed.txt"); // CHECK MAGIC NUMBER

    mRounds = rounds;
}

void Game::InitialisePlayers(std::vector<std::string> players)
{
    for (int i = 0; i < players.size(); i++)
    {
        mPlayers.push_back(new CPlayer(players[i], *mpBoard));
    }
}

void Game::InitialiseBoard(std::string filePath)
{
    mpBoard = new Board(filePath, *mpSpinner);
}

void Game::EndGame()
{
    std::cout << "Game Over" << std::endl;
    std::cout << "=========" << std::endl;

    int mostSuccess = mPlayers[0]->GetSuccess();

    // Get the most amount of success
    for ( int i = 0; i < mPlayers.size(); i++ )
    {
        std::cout << mPlayers[i]->GetName() << " has achieved " << mPlayers[i]->GetSuccess() << std::endl;
        if (mPlayers[i]->GetSuccess() > mostSuccess)
        {
            mostSuccess = mPlayers[i]->GetSuccess();
        }
        
    }

    // Declaring winner/s
    // For each player with the most success (incase of draws)
    for (int i = 0; i < mPlayers.size(); i++)
    {
        if (mPlayers[i]->GetSuccess() == mostSuccess)
        {
            std::cout << mPlayers[i]->GetName() << " wins." << std::endl;
        }
    }
    
}

void Game::StartGame()
{
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
            int playerSpin = mpSpinner->GetSpin(*mPlayers[j]);

            int newPlayerPosition = mPlayers[j]->GetPosition() + playerSpin;
            mPlayers[j]->SetPosition(newPlayerPosition % mpBoard->GetSize());

            mpBoard->RunSpaceAction( *mPlayers[j] );
            
            if (newPlayerPosition > mpBoard->GetSize()) // Passes Welcome Week
            {
                mPlayers[j]->AddMotivation(250);
                mPlayers[j]->UpdateYear();
                std::cout << mPlayers[j]->GetName() << " attends Welcome Week and starts year " << mPlayers[j]->GetYear() << " more motivated!" << std::endl;
            }

            std::cout << mPlayers[j]->GetName() << "'s motivation is " << mPlayers[j]->GetMotivation() << " and success is " << mPlayers[j]->GetSuccess() << std::endl;

            std::cout << std::endl;
        }

        

    }
}