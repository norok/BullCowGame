#pragma once

#include <string>;

using FString = std::string;
using int32 = int;

// all variables initialised to zero
// structs should be named like Classes by UE Standards
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// Declarations
class FBullCowGame
{
public:
	FBullCowGame(int32 MaxTries); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	void IntroduceTheGame() const;
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);
	
	bool IsGameWon() const;
	void Reset();


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	int32 GameMaxTries;
	FString MyHiddenWord;
};
