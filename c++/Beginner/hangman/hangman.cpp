#include <iostream>
#include <stdlib.h> //srand and rand for random numbers
#include <stdio.h>
#include <time.h> // allows for time

using namespace std;


//This hangman is made using OOP in mind, could be made smaller but i wanted to fiddle around with OOP concepts at beginner level

const int maxGuess = 6;//max guesses
int guesses;//counter for guesses
const string words[5] = {"danger", "computer", "table", "elephant", "uniform"};
const int arrSize = sizeof(words) / sizeof(string);//sizeof array divided by size of string type (otherwise displays size of array in bytes)
string currentWord; //current word in game
string hiddenWord = ""; //replaces currentWord with ____

//generating random number between 1 and 5 - used for choosing random array element, needed to be paired with time

string displayRules()
{
    return "\n\nYou have 6 guesses, with each guess being a letter from A-Z.\nYou must figure out the word by using these guesses as clues. \nYou get one chance to guess the word correctly. If you guess incorrectly you lose.\n\n";
}

string randomizeWord()
{
    srand (time(NULL)); //this allows for random integers https://www.cplusplus.com/reference/cstdlib/srand/
    return currentWord = words[rand()%arrSize]; //this is selecting a new hangman word by assigning rand()%arrSize as seed number to array index
}

void guessWord()
{
    string guessedWord;
    cout << "\n\nType the word you're trying to guess.\n\n";
    cin >> guessedWord;
    if (guessedWord == currentWord)
    {
        cout << "\n\nCongrats, you guessed correctly. YOU WIN!\n\n";
    }
    else
    {
        cout << "\n\nSorry, you guessed incorrectly. YOU LOSE!\n\n";
    }
    hiddenWord = ""; //resetting worrd
}

void guessChar()
{
    char currGuess;
    cout << "\n\nEnter a letter to guess.\n\n";
    cin >> currGuess;

    for (int j = 0; j < currentWord.length(); j++)
    {
        if (currentWord.at(j) == currGuess)  //if guessed char is same as currentWord char iteration
        {                                      // then replace '_' char with letter
            cout << "\n\nLetter " << currGuess << " is in word!\n\n";
            hiddenWord[j] = currGuess;
            guesses ++; //increment guess counter
        }
    }
    if (currentWord.find(currGuess) == string::npos) //if guessed character isnt in word
    {
        cout << "\n\nLetter " << currGuess << " is not in word!\n\n";
        guesses ++;//increasing counter of guesses, if guessed incorrectly
    }
}

string hideWord()
{
    for (int k = 0; k < currentWord.length(); k++)
    {
        hiddenWord += '_';  //replacing word with underlines
    }
    return hiddenWord;
}

void start()
{
    currentWord = randomizeWord(); //calling function and assigning return value as word
    cout << "\n\nNew word has been selected.\n\n";
    hideWord();
    while (guesses <= 6) //game will play as long as guesses below 6
    {
       cout << "(" << hiddenWord << ")" << endl <<endl;
       string response;
       cout << "\n\n(1)Guess letter\n(2)Guess word\n\n";
       cin >> response;

       if (response == "1")
       {
           cout << "You have " << maxGuess - guesses << " guesses remaining!";
           guessChar(); //calling guess function repeatedly
           if (hiddenWord.find('_') == string::npos) //if '_' isnt found, then player has guessed word by finding all chars
           {
               cout << "You guessed all the letters, you win!";
               hiddenWord = "";
               break;
           }
       }
       else if (response == "2")
       {
           guessWord(); //player wants to guess word
           break;
       }

    }
    if (guesses >= 6 && hiddenWord.find('_') != string::npos) //if guesses hit 6, and '_'s are not all gone, then display this
    {
        cout << "\n\nOut of guesses, GAME OVER!\n\n";
    }
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
