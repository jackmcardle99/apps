#include <iostream>
#include<cstdlib>
#include <time.h>

int main()
{
    srand(time(NULL)); //time function for allowing rand int

    int ranNum = rand()%10; //assigning int to rand out of 10
    int userGuess;
    int maxGuesses = 3;
    int guessCount =0;

    std::cout << "Welcome to the number guessing game.\n\n";
    std::cout << "You must guess a number between 1 and 10.\n\nYou have 3 tries.\n\n";


    while(guessCount <= maxGuesses)
    {
        std::cout << "Please enter a number between 1 and 10\n\n";
        std::cin >> userGuess;
        guessCount ++;
        if (userGuess == ranNum)
        {
            std::cout << "Congrats you got it!\n\n";
            break;
        }
        if (guessCount == 3)
        {
            std::cout << "No guesses left, game over!\n\n";
            break;
        }
        else if (userGuess != ranNum)
        {
            std::cout << "That wasn't it, try again!\n\n" << maxGuesses - guessCount << " guesses left.\n\n";
        }
    }
}
