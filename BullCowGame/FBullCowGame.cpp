/*
This is the file where the FBullCowGame Class get its Definitions from
*/

#pragma once
#include "FBullCowGame.h"
#include <map>
#include <random>
#define TMap std::map

// Preparations for Unreal code substitutions (Unreal friendly)
using int32 = int;
using FString = std::string;

// Code for generating a random number
std::random_device rd;
std::mt19937 rng(rd());

// Definitions
FBullCowGame::FBullCowGame()
{
	Reset();
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{
		{3, 4},
		{4, 7},
		{5, 10},
		{6, 16}
	};

	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

FString FBullCowGame::GetBullCowCountFeedback(FString Key)
{
	return FBullCowCountFeedback[Key];
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

void FBullCowGame::SetDifficulty(int32 DifficultySetting)
{
	Difficulty = DifficultySetting - '0'; // prevents the conversion side effect
	MyHiddenWord = GetRandomHiddenWord();

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

void FBullCowGame::Reset()
{
	bGameIsWon = false;
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

/* Private methods */

FString FBullCowGame::GetRandomHiddenWord()
{
	TMap<int32, FString> WordsMap = FWordDifficulty[Difficulty];
	std::uniform_int_distribution<int> uni(1, 4);
	int32 WordIndex = uni(rng);

	return WordsMap[WordIndex];
}

bool FBullCowGame::IsValidDifficulty(char DifficultySetting) const
{
	if (!isalpha(DifficultySetting)) {
		int32 Character = DifficultySetting - '0'; // convert char to int
		return Character >= 1 && Character <= 4;
	}

	return false;
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