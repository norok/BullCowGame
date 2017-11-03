#include "FBullCowGame.h"

using int32 = int;

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

void FBullCowGame::IntroduceTheGame() const
{
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
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
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment turn number
	MyCurrentTry++;
	// setup a return variable
	BullCowCount BullCowCount;

	// loop through all letters in the guess
		// compare letters against the hidden word

	return BullCowCount;
}
