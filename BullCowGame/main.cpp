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

// Game instantiation
FBullCowGame BCGame(5);

// Functions
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AsktoPlayAgain();

// The entry point for our application
int main()
{
	PrintIntro();
	PlayGame();

	return 0;
}

// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength()
		<< " letter isogram I'm thinking of?" << std::endl;
	return;
}

// Play a single game
void PlayGame()
{
	BCGame.Reset();
	int32 Tries = BCGame.GetMaxTries();

	do {
		// TODO change from FOR to WHILE loop once validating tries
		for (int32 i = 1; i <= Tries; i++) {
			FText Guess = GetGuess();

			// Submit valid guess to the game and receive counts
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
			// Print number of bulls and cows
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		}
		// TODO Add a game summary at the end

		std::cout << "\nSorry, wrong answers buddy." << std::endl << std::endl;
		BCGame.Reset();
	} while (AsktoPlayAgain());

	return;
}

// get a guess from the player
FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << "\nEnter your guess (" << CurrentTry << "/" << MaxTries << "): ";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AsktoPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	char FirstChar = Response[0];
	return (FirstChar == 'y' || FirstChar == 'Y');
}
