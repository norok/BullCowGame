/*
This is the console executable that makes use of the BullCowGame class.
This acts as the view in a MVC pattern and is responsible for all the user
interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include "FBullCowGame.h"

// Preparations for Unreal code substitutions
using FText = std::string;
using int32 = int;

// Game instantiation
FBullCowGame BCGame;

// Functions
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AsktoPlayAgain();
void PrintGameSummary();

// The entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AsktoPlayAgain());

	return 0;
}

// introduce the game
void PrintIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength()
		<< " letter isogram I'm thinking of?" << std::endl;
	return;
}

// Play a single game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	PrintGameSummary();

	BCGame.Reset();

	return;
}

// loop until the user giver a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		int32 MaxTries = BCGame.GetMaxTries();

		std::cout << "\nEnter your guess (" << CurrentTry << "/" << MaxTries << "): ";
		std::getline(std::cin, Guess);

		// Check the status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Lenght:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter only lowercase letters.\n";
				break;
			default:
				// assume the guess is valid
				break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors

	return Guess;
}

bool AsktoPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	char FirstChar = Response[0];
	return (FirstChar == 'y' || FirstChar == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "\nCongratulations! You won!." << std::endl << std::endl;
	}
	else
	{
		std::cout << "\nSorry, wrong answers buddy." << std::endl << std::endl;
	}

	return;
}