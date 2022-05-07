#python hangman game
import random

ran_int = random.randint(0,4) #generating a random int for word seed
words = ['elephant', 'table', 'uniform', 'danger', 'invite'] #words that the game will choose from
current_word = words[ran_int] #assigning value to word from array via ran num seed
max_guesses = 6
guess_count = 0   
hidden_word = '' 
already_guessed = []#array to store users past guesses

def guess_word(): #function for guessing the word, only 1 chance
    user_guess = input("Please enter the word you think it is. You only have one try!\n")
    if user_guess == current_word:
        print("Well done! You guessed the word!\n")
    else:
        print("Sorry that was not the word, Game over!\n")

for letters in range(len(current_word)): #length of hidden word
    hidden_word += '_' #creating a hidden word same length as current word

print('\n',hidden_word,"\n")

while guess_count < 6: #while loop until 6 guesses have been made
    if '_' not in hidden_word: #if all chars have bee guessed this will be printed and game will finish
        print("You have guessed all of the letters, well done you win!\n")
        break
    while True: #nested while loop to ensure user cant guess same letter twice
        print("You have ", max_guesses - guess_count, " guesses left!\n")
        guessed_char = input("Please guess a single letter. Or enter 1 to guess the word.\n")
        if guessed_char in already_guessed:
            print("That letter has already been guessed, try another. You have not lost a guess.\n")
        else:
            break
    already_guessed.append(guessed_char)#adding char into an array, so that we can verify if its already been used
    
    if guessed_char in current_word:
        print("Nice! That letter was in the word.\n")
        for letter in range(len(current_word)):   #looping through range of word
            if current_word[letter] == guessed_char:    #if the guessed char is equivalent to curren_word current index  -->        
                hidden_word = hidden_word[:letter] + guessed_char + hidden_word[letter + 1:] #then replace '_' char with original letter  
                print(hidden_word) #strings are immutable in python!! remember this!!!!!           
    elif guessed_char == "1":
        guess_word()
        break             
    else:
        print("That was not in the word!\n")
    guess_count +=1

if guess_count == 6 and '_' in hidden_word:#if guesses reach 6 and the full word hasnt veen guessed then game over
    print("Game over, out of guesses!\n")
elif guess_count == 6 and '-' not in hidden_word:#else if they reach 6 guesses and it has been guessed
    print("You guessed all the letters within 6 guesses well done!")

