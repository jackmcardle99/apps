#python hangman game
#where i left off - fixing the guess letter 
import random
ran_int = random.randint(0,4) #generating a random int for word seed
words = ['elephant', 'table', 'uniform', 'danger', 'invite'] #words that the game will choose from
current_word = words[ran_int] #assigning value to word from array via ran num seed
max_guesses = 6
guess_count = 0   
hidden_word = ''

for letters in range(len(current_word)): #length of hidden word
    hidden_word += '_' #creating a hidden word same length as current word
print(hidden_word)
print(current_word)

while guess_count <= 6:
    guessed_char = input("Please guess a single letter. ")
    if guessed_char in current_word:
        print("Nice! That letter was in the word.")
        for letter in range(len(current_word)):   
            if current_word[letter] == guessed_char:
                hidden_word = hidden_word[:letter] + guessed_char + hidden_word[letter + 1:]      #strings are immutable in python!! remember this!!!!!
                print(hidden_word)              
    else:
        print("That was not in the word!")
    guess_count +=1


print(hidden_word)


