#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

// Definitions

FBullCowGame::FBullCowGame(int32 MaxTries)
{
	GameMaxTries = MaxTries;
	FBullCowGame::Reset();
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
	return MyHiddenWord.length();;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	MyMaxTries = GameMaxTries;
	return;
}

// Receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 CurrentGuessLength = Guess.length();
	for (int32 GChar = 0; GChar < CurrentGuessLength; GChar++)
	{
		// compare letters against the hidden word
		for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
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

	return BullCowCount;
}
