#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all variables initialised to zero
// structs should be named like Classes by UE Standards
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};

// Declarations
class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	// Getters
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	FBullCowCount SubmitGuess(FString);
	EGuessStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	void Reset();

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
