#include "Game.h"

Game::~Game()
{
    delete mpBoard;
    delete mpSpinner;

    for (int i = 0; i < mPlayers.size(); i++)
    {
        delete mPlayers[i];
    }
}

Game::Game(std::vector<std::string> players, std::string boardFilePath, int rounds)
{
    InitialiseBoard(boardFilePath);
    InitialisePlayers(players);
    mpSpinner = new Spinner("seed.txt");

    mRounds = rounds;
}

void Game::InitialisePlayers(std::vector<std::string> players)
{
    // Add each player to container
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
    // Game over message
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

    std::cout << std::endl;

    // Declaring winner/s
    // For each player with the most success (incase of drawed game)
    for (int i = 0; i < mPlayers.size(); i++)
    {
        if (mPlayers[i]->GetSuccess() == mostSuccess)
        {
            std::cout << mPlayers[i]->GetName() << " wins!" << std::endl;
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
        // Round message
        std::cout << "Round " << round << std::endl;
        std::cout << "=========" << std::endl;

        // Player turn
        for (int j = 0; j < mPlayers.size(); j++)
        {
            
            int playerSpin = mpSpinner->GetSpin(*mPlayers[j]); // Spin

            int newPlayerPosition = mPlayers[j]->GetPosition() + playerSpin;
            mPlayers[j]->SetPosition(newPlayerPosition % mpBoard->GetSize());

            if (newPlayerPosition > mpBoard->GetSize()) // Check if player passes Welcome Week
            {
                mPlayers[j]->AddMotivation(250);
                mPlayers[j]->UpdateYear();
                std::cout << mPlayers[j]->GetName() << " attends Welcome Week and starts year " << mPlayers[j]->GetYear() << " more motivated!" << std::endl;
            }

            // Run space actions
            mpBoard->RunSpaceAction( *mPlayers[j] );
            
            // Player status message
            std::cout << mPlayers[j]->GetName() << "'s motivation is " << mPlayers[j]->GetMotivation() << " and success is " << mPlayers[j]->GetSuccess() << std::endl;

            std::cout << std::endl;
        }

        

    }
}