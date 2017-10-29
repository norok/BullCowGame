#include <iostream>
#include "FBullCowGame.h"

// Global Constants
constexpr int WORD_LENGTH = 5;

// Functions
void PrintIntro();
void PrintBackGuess(std::string Guess);
void PlayGame();
std::string GetGuess();
bool AsktoPlayAgain();

// Game instantiation
FBullCowGame BCGame;

// The entry point for our application
int main()
{
	PrintIntro();
	PlayGame();

	return 0;
}

// Play a single game
void PlayGame()
{
	int Tries = BCGame.GetMaxTries();

	do {
		for (int i = 1; i <= Tries; i++) {
			PrintBackGuess(GetGuess());
			BCGame.NextTry();
		}
		// fail
		std::cout << "\nSorry, wrong answers buddy." << std::endl << std::endl;
		BCGame.Reset();
	} while (AsktoPlayAgain());
}

// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH
			<< " letter isogram I'm thinking of?" << std::endl;
	return;
}

// get a guess from the player
std::string GetGuess()
{
	std::string Guess = "";
	int CurrentTry = BCGame.GetCurrentTry();
	int MaxTries = BCGame.GetMaxTries();

	std::cout << "Enter your guess (" << CurrentTry << "/" << MaxTries << "): ";
	std::getline(std::cin, Guess);

	return Guess;
}

// repeat the guess back to the player (feedback)
void PrintBackGuess(std::string Guess)
{
	std::cout << "Your guess was \"" << Guess << "\"" << std::endl << std::endl;
}

bool AsktoPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	char FirstChar = Response[0];
	return (FirstChar == 'y' || FirstChar == 'Y');
}