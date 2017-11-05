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
void ChooseDifficulty();
void PlayGame();
FText GetValidGuess();
bool AsktoPlayAgain();
void PrintGameSummary();
void BullCowCountFeedback(FBullCowCount);

// The entry point for our application
int main()
{
	do
	{
		PrintIntro();
		ChooseDifficulty();
		PlayGame();
	} while (AsktoPlayAgain());

	return 0;
}

// introduce the game
void PrintIntro()
{
	std::system("cls"); // Not good but welcome. Only works under Windows, though.
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "___                    __" << std::endl;
	std::cout << "|  \\     | |          /" << std::endl;
	std::cout << "|  /     | |         |     __" << std::endl;
	std::cout << "|  \\ | | | | /_      |    |  | \\    / /_" << std::endl;
	std::cout << "|__/ \\_/ | |  /   &   \\__ |__|  \\/\\/   /" << std::endl << std::endl;
	std::cout << "A Bull is a right letter in the right place." << std::endl;
	std::cout << "A Cow is a right letter in the wrong place." << std::endl;
	return;
}

void ChooseDifficulty()
{
	int32 Difficulty = '0';
	FString Answer = "";

	std::cout << "\nChoose your difficulty:" << std::endl;
	// Only advance if the player chooses between 1 and 4
	while (!BCGame.IsValidDifficulty(Difficulty))
	{
		std::cout << "(1) Easy, (2) Normal, (3) Hard, (4) Very Hard: ";
		std::getline(std::cin, Answer);
		Difficulty = Answer[0];
	}

	BCGame.SetDifficulty(Difficulty);

	std::cout << "\n\nCan you guess the " << BCGame.GetHiddenWordLength()
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

		// Give some friendly feedback
		BullCowCountFeedback(BullCowCount);

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
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	char FirstChar = Response[0];
	return (FirstChar == 'y' || FirstChar == 'Y');
}

void BullCowCountFeedback(FBullCowCount BullCowCount)
{
	int32 FullCount = BullCowCount.Bulls + BullCowCount.Cows;

	if (FullCount == 0)
	{
		std::cout << BCGame.GetBullCowCountFeedback(BCGame.BAD_ANSWER);
	}
	else if (FullCount > 0 && FullCount < BCGame.GetHiddenWordLength() - 2)
	{
		std::cout << BCGame.GetBullCowCountFeedback(BCGame.AVERAGE_ANSWER);
	}
	else if (BullCowCount.Bulls < BCGame.GetHiddenWordLength())
	{
		std::cout << BCGame.GetBullCowCountFeedback(BCGame.GOOD_ANSWER);
	}
	else {
		std::cout << BCGame.GetBullCowCountFeedback(BCGame.RIGHT_ANSWER);
	}

	std::cout << std::endl;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "\nCongratulations! You won!." << std::endl << std::endl;
	}
	else
	{
		std::cout << "\nSorry, wrong answers buddy. Better luck next time!" << std::endl << std::endl;
	}

	return;
}