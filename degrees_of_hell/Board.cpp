#include "Board.h"
#include "CPlayer.h"
//#include "CSpace.h"



#include <iostream>

void Board::RunSpaceAction(CPlayer& player)
{
    mBoard[ player.GetPosition() ]->PlayerLands(player);
}

void Board::ShowBoard()
{
    /*for (int i = 0; i < mBoard.size(); i++)
    {
        std::cout << mBoard[i]->GetName()<< std::endl;
    }*/
    
    std::cout << "This is " << mBoard[3]->GetName() << std::endl;
    
}

int Board::GetSize() const
{
    return mBoard.size();
}

int Board::GetPlagiarismHearingIndex() const
{
    return mPlagiarismHearingIndex;
}

std::string Board::GetSpaceName(int spacePos) const
{
    return mBoard[spacePos]->GetName();
}

Board::Board(std::string setUpFilePath)
{
    mPlagiarismHearingIndex = 0;
    mAccusedOfPlagiarismIndex = 0;

    std::ifstream inputFile(setUpFilePath); //"data/degrees.txt");
    if (!inputFile) {
        throw std::runtime_error("Unable to open file: " + setUpFilePath);
    }

    std::string line;

    while (std::getline(inputFile, line))
    {
        std::istringstream stringStream(line);
        std::vector<std::string> tokens; 
        std::string token;


        // Populate token
        while (stringStream >> token)
        {
            tokens.push_back(token);
        }

        // Populating board
        if (std::stoi(tokens[0]) == 1) // Assignment
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1] + " " + tokens[2];
            int motivationalCost = std::stoi(tokens[3]);
            int successScore = std::stoi(tokens[4]);
            int year = std::stoi(tokens[5]);

            mBoard.push_back(new Assessment(type, name, motivationalCost, successScore, year));
        }
        else if (std::stoi(tokens[0]) == 2) // Welcome week
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1] + " " + tokens[2];

            mBoard.push_back(new CSpace(type, name));
        }
        else if (std::stoi(tokens[0]) == 3) // Extra-curricular
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1] + " " + tokens[2];
            int motivationalCost = std::stoi(tokens[3]);

            mBoard.push_back(new ExtraCurricular(type, name, motivationalCost));
        }
        else if (std::stoi(tokens[0]) == 4) // Bonus
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1];

            mBoard.push_back(new CSpace(type, name));
        }
        else if (std::stoi(tokens[0]) == 5) // Bogus
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1];

            mBoard.push_back(new CSpace(type, name));
        }
        else if (std::stoi(tokens[0]) == 6) // Plagiarism Hearing
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1] + " " + tokens[2];

            mBoard.push_back(new PlagiarismHearing(type, name));
            
            // Save index
            mPlagiarismHearingIndex = mBoard.size() - 1;
        }
        else if (std::stoi(tokens[0]) == 7) // Accused of plagiarism
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1] + " " + tokens[2] + " " + tokens[3];

            mBoard.push_back(new AccusedOfPlagiarism(type, name));

            // Save index
            mAccusedOfPlagiarismIndex = mBoard.size() - 1;
        }
        else if (std::stoi(tokens[0]) == 8) // Skip classes
        {
            int type = std::stoi(tokens[0]);
            std::string name = tokens[1] + " " + tokens[2];

            mBoard.push_back(new SkipClasses(type, name));
        }
        

    }


    inputFile.close();
}
