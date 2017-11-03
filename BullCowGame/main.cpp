/*
This is the console executable that makes use of the BullCowGame class.
This acts as the view in a MVC pattern and is responsible for all the user
interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include "FBullCowGame.h"

// Preparations for Unreal code substitutions
using FText = FString;
using int32 = int;

// Global Constants
constexpr int32 WORD_LENGTH = 5;

// Functions
void PrintIntro();
void PrintBackGuess(FText Guess);
void PlayGame();
FText GetGuess();
bool AsktoPlayAgain();

// Game instantiation
FBullCowGame BCGame(8);

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
	BCGame.Reset();
	int32 Tries = BCGame.GetMaxTries();

	do {
		// TODO change from FOR to WHILE loop once validating tries
		for (int32 i = 1; i <= Tries; i++) {
			PrintBackGuess(GetGuess()); // TODO check for valid guesses

			// Submit valid guess to the game
			// Print number of bulls and cows
		}
		// TODO Add a game summary at the end

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
FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << "Enter your guess (" << CurrentTry << "/" << MaxTries << "): ";
	std::getline(std::cin, Guess);

	return Guess;
}

// repeat the guess back to the player (feedback)
void PrintBackGuess(FText Guess)
{
	std::cout << "Your guess was \"" << Guess << "\"" << std::endl << std::endl;
}

bool AsktoPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	char FirstChar = Response[0];
	return (FirstChar == 'y' || FirstChar == 'Y');
}
