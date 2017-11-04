#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

// Definitions

FBullCowGame::FBullCowGame()
{
	Reset();
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)// If the guess is not an isogram
	{
		// TODO write function
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // If the guess is not all lowercase
	{
		// TODO write function
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess if wrong lenght
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";

	bGameIsWon = false;
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

// Receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();
	int32 CurrentGuessLength = Guess.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < CurrentGuessLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) // If they match then
			{
				if (MHWChar == GChar) // if in the right place
				{
					BullCowCount.Bulls++; // Increment Bulls
				}
				else
				{
					BullCowCount.Cows++; // Increment Cows
				}
			}
		}
	}

	bGameIsWon = (BullCowCount.Bulls == WordLength);

	return BullCowCount;
}