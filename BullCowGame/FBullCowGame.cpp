#include "FBullCowGame.h"
#include <map>
#define TMap std::map

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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))// If the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // If the guess is not all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) // the guess is blank or one letter only
	{
		return true;
	}

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		if (!isalpha(Letter)) {
			return true; // leave this checking to IsLowercase
		}
		else if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word.length() == 0) // the guess is blank
	{
		return true;
	}

	for (auto Letter : Word)
	{
		if (!islower(Letter) || !isalpha(Letter)) {
			return false;
		}
	}

	return true;
}