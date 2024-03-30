#pragma once


#include <string>


class CPlayer
{
private:
    std::string mName;
    int mYear;
    int mMotivation;
    int mSuccess;
    int mPosition;

public:
    CPlayer(std::string name);

    ~CPlayer();

    std::string GetName() const;
    int GetPosition() const;
    int GetMotivation() const;
    int GetSuccess() const;
    int GetYear() const;

    void SetPosition(int pos);

    void AddMotivation(int motivation);

    void DeductMotivation(int motivation);

    void AddSuccess(int success);


    void UpdateYear();
};


