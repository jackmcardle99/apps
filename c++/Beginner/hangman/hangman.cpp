#include <iostream>
#include <stdlib.h> //srand and rand
#include <stdio.h>
#include <time.h> // allows for time

using namespace std;


/*In the game of Hangman, the computer chooses a word
at random from a given list of words. This word is the answer.
The player then tries to guess the word, by guessing one letter
at a time. Whenever the user guesses a letter that is in the answer,
all occurrences of that letter are revealed to the user. The game ends
when the user has guessed every letter in the word, before he reaches the
allowed number of strikes (usually 5). This program is an interactive Hangman
game. The focus is to use and manipulate strings and loops.*/

const int maxGuess = 5;
int guesses;
const string words[5] = {"danger", "computer", "table", "elephant", "uniform"};
const int arrSize = sizeof(words) / sizeof(string);
char currGuess;
string currentWord;
string guessedWord;
//string hiddenWord;

//generating random number between 1 and 5 - used for choosing random array element, needed to be paired with time

string displayRules()
{
    return "\n\nYou have 5 guesses, with each guess being a letter from A-Z.\nYou must figure out the word by using these guesses as clues.\n\n";
}

string randomizeWord()
{
    srand (time(NULL)); //this allows for random integers https://www.cplusplus.com/reference/cstdlib/srand/
    int seed = rand()%arrSize; //sizeof array divided by size of string type (otherwise displays size of array in bytes)
    return words[seed]; //this is selecting a new hangman word by assigning seed number to array index
}

void guessChar()
{
    cout << "\n\nEnter a letter\n\n";
    cin >> currGuess;
    cout << currGuess;
    if (currentWord.find(currGuess) != std::string::npos)
    {
        cout << "\n\nLetter " << currGuess << " is in word!\n\n";
    }
    else
        cout << "\n\n not found!!!!\n\n";

    guesses +=1; //increasing counter of guesses
}

void guessWord()
{
    cout << "\n\nType the word you're trying to guess.\n\n";
    cin >> guessedWord;

}

string hiddenWord()
{
    int wordLength = currentWord.length();
    char hiddenWordArr[wordLength];
    string hiddenWord = "";
    for (int k = 0; k < sizeof(hiddenWordArr) / sizeof(char); k++)
    {
        hiddenWordArr[k] = '_';
        hiddenWord += hiddenWordArr[k];
    }
    return hiddenWord;
}
void start()
{
    currentWord = randomizeWord(); //calling function and assigning return value as word
    cout << "\n\nNew word has been selected.\n\n";
    cout << hiddenWord();
    guessChar();
}
void menu()
{
    while (true)
    {
        string userResponse;

        cout << "\n\nPlease enter number response.\n\n(1)Play\n(2)Rules\n(3)Exit\n\n";
        cin >> userResponse;

        if (userResponse == "1")
        {
            start();
        }
        else if (userResponse == "2")
        {
            cout << displayRules();
        }
        else if (userResponse == "3")
        {
            cout << "Goodbye!";
            break;
        }
        else
        {
            cout << "\n\nPlease enter valid input\n\n";
        }
    }
}

int main()
{
    cout << "Welcome to hangman!";

    menu();
    return 0;
}
