#python hangman game
#where i left off - fixing the guess letter 
import random
ran_int = random.randint(0,4) #generating a random int for word seed
words = ['elephant', 'table', 'uniform', 'danger', 'invite'] #words that the game will choose from

def set_current_word():
    current_word = words[ran_int] #assigning value to word from array via ran num seed
    print(current_word)
    return current_word

current_word = set_current_word() #assgining word

def start():
    global guess_count
    guess_count = 0
    set_current_word() 
    while guess_count <= 6:
        guessed_char = input("Please guess a single letter. ")
        guess_letter(guessed_char)

def guess_letter(guessed_char):
    print(current_word)
    
    if guessed_char in current_word:
        print("Nice! That letter was in the word.")
    else:
        print("That was not in the word!")


def rules():
    print("Here are the rules")

def menu():
    user_choice = input("(1)Play\n(2)Rules\n(3)Quit\n")
    if user_choice == "1":
        start()
    elif user_choice == "2":
        rules()
    else:
        print("Thanks for playing!") 

menu()