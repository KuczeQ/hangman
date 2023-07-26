# Hangman Game

Hangman is a classic word-guessing game where the player tries to guess a hidden word letter by letter. The player has a limited number of attempts to guess the word correctly. Each correct guess reveals the correctly guessed letters in the word, while each incorrect guess contributes to a drawing of a hanging man. If the player correctly guesses all the letters before running out of attempts, they win the game. Otherwise, if the man is fully drawn before the word is guessed, the player loses.

## How to Play

1. Run the program, and it will randomly select a word from a word list (provided in "words.txt").
2. The length of the hidden word will be displayed as underscores "_", representing the unguessed letters.
3. The player needs to guess a letter and input it.
4. The game will check if the guessed letter exists in the hidden word:
   - If the letter is correct, all occurrences of the letter will be revealed.
   - If the letter is incorrect, the player will lose one attempt.
5. The game will continue until one of the following conditions is met:
   - The player correctly guesses all the letters in the word, and they win.
   - The player exceeds the maximum number of attempts (default: 7), and they lose.
6. After the game ends, the correct word will be revealed.

## Code Overview

1. The code uses a text file ("words.txt") to store a list of words.
2. The function `getRandomWord()` reads the word list from "words.txt" and returns a randomly selected word.
3. The function `displayGame()` displays the current state of the game, showing the correctly guessed letters and underscores for unguessed letters.
4. In `main()`, the game loop continues until the player wins or loses.
5. The player is prompted to guess a letter.
6. The guessed letter is checked against the hidden word, and the game state is updated accordingly.
7. If the player correctly guesses all the letters, they win the game.
8. If the player exceeds the maximum attempts, they lose the game, and the correct word is revealed.

## Word List

The word list is stored in "words.txt". Each line in the file contains a single word that can be used for the game. You can modify or extend this list to include more words that the player can guess during the game.

## Customization

You can customize the game by adjusting the following parameters:

- `const int maxAttempts`: You can change the maximum number of attempts allowed for the player to guess the word.

## Have Fun!

Compile and run the code to play Hangman! Have fun guessing the hidden words!
