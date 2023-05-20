#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

void displayGame(const std::string& hiddenWord, const std::vector<bool>& guessedLetters) {
    std::cout << "\nGame state: ";

    for (std::size_t i = 0; i < hiddenWord.length(); ++i) {
        if (guessedLetters[i]) {
            std::cout << hiddenWord[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }

    std::cout << "\n";
}

std::string getRandomWord() {
    std::ifstream wordFile("words.txt");
    std::vector<std::string> words;

    if (wordFile.is_open()) {
        std::string word;

        while (std::getline(wordFile, word)) {
            words.push_back(word);
        }

        wordFile.close();
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int randomIndex = std::rand() % words.size();
    return words[randomIndex];
}

void displayCorrectWord(const std::string& hiddenWord) {
    std::cout << "The correct word was: " << hiddenWord << "\n";
}

int main() {
    std::string hiddenWord = getRandomWord();
    const int maxAttempts = 7;

    std::vector<bool> guessedLetters(hiddenWord.length(), false);
    int attempts = 0;

    std::cout << "Welcome to Hangman!\n";

    while (true) {
        displayGame(hiddenWord, guessedLetters);

        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;

        bool correctGuess = false;

        for (std::size_t i = 0; i < hiddenWord.length(); ++i) {
            if (hiddenWord[i] == guess) {
                guessedLetters[i] = true;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            std::cout << "Correct guess!\n";
        } else {
            std::cout << "Incorrect guess!\n";
            attempts++;

            if (attempts >= maxAttempts) {
                std::cout << "You exceeded the maximum number of attempts. You lose!\n";
                displayCorrectWord(hiddenWord);
                break;
            }
        }

        if (guessedLetters == std::vector<bool>(hiddenWord.length(), true)) {
            std::cout << "Congratulations! You guessed all the letters. You win!\n";
            break;
        }
    }

    std::cout << "Thank you for playing!\n";

    return 0;
}
