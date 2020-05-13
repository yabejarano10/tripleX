#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a war prisoner trying to escape of a LEVEL " << Difficulty <<   " security jail.\n";
    std::cout << "You need to guess the code of the door in order to get out.\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The numbers add-up to: " << CodeSum << "\n";
    std::cout << "+ The numbers multiply to give: : " << CodeProduct << "\n";

    int GuessA,GuessB,GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You escaped, but know there is more doors to open in order to get your freedom back ***\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou get caught!!!! Try Again bruh\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;
    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "WELL DONE, YOU ARE FREE NOW TO EAT SOME ENCHILADAS OR WHATEVER!!!\n\n";
    return 0;
}