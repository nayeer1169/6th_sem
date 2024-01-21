# -*- coding: utf-8 -*-
"""2.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1XWRrYTL22CichuKFYVpTZ5VGV_lxBptn
"""

import random

num = random.randint(1, 10)
guess = None
count = 2

while guess != num:
    count += 1
    guess = input("Guess the number between 1 to 10 = ")

    if guess.isdigit():
        guess = int(guess)
        if guess == num:
            print(f"Congratulations! You guessed the right number in {count} attempts.")
        else:
            print("Nope, try again")
    else:
        print("Please enter a valid number.")

#guess the word
word=["Alaska" , "Spice" , "Jet" , "Pulse" , "Zen" , "Blaze" , "Swift" , "Bolt" , "Thunder" , "Pulsar"]
ran =random.choice(word)
count = 10
flag = 0

while(count!=5):
  guess = input("Enter the number you have guessed:")
  if guess == ran:
    flag+=1
    break
  else:
    print("Guess again.")
  count-=1

if flag == 1:
  print("You guessed it right")
else:
  print("The first and last letter of word is:" ,ran[0],"and",ran[-1])

while(count!=0):
  guess = input("Enter the Guess:")
  if guess== ran:
    flag+=1
    break
  else:
    print("Guess again")
if flag == 1:
  print("You guessed it right")
else:
  print("You lost your chance , The word was:" ,ran)

