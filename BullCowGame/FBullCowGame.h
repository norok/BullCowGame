#pragma once
#include <string>
#include <map>
#define TMap std::map

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
	Invalid_Status,
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

	// Constants
	const FString BAD_ANSWER = "BadAnswer";
	const FString AVERAGE_ANSWER = "AverageAnswer";
	const FString GOOD_ANSWER = "GoodAnswer";
	const FString RIGHT_ANSWER = "RightAnswer";

	// Getters
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	FString GetBullCowCountFeedback(FString);

	// Methods
	FBullCowCount SubmitValidGuess(FString);
	EGuessStatus CheckGuessValidity(FString) const;
	void SetDifficulty(int32);
	bool IsValidDifficulty(char) const;
	bool IsGameWon() const;

	// Reset the game
	void Reset();

private:
	int32 MyCurrentTry;
	int32 Difficulty;
	FString MyHiddenWord;
	bool bGameIsWon;

	TMap<FString, FString> FBullCowCountFeedback
	{
		{ BAD_ANSWER, "That was not good, try another word" },
		{ AVERAGE_ANSWER, "Nice choice but still wrong, don't give up!" },
		{ GOOD_ANSWER, "You're almost there!" },
		{ RIGHT_ANSWER, "That's right! You've got it!" }
	};

	TMap<int32, FString> FEasyWords
	{
		{ 1, "ape" },
		{ 2, "for" },
		{ 3, "six" },
		{ 4, "the" }
	};

	TMap<int32, FString> FNormalWords
	{
		{ 1, "easy" },
		{ 2, "star" },
		{ 3, "helm" },
		{ 4, "luck" }
	};

	TMap<int32, FString> FHardWords
	{
		{ 1, "jumpy" },
		{ 2, "treck" },
		{ 3, "waltz" },
		{ 4, "brick" }
	};

	TMap<int32, FString> FVeryHardWords
	{
		{ 1, "planet" },
		{ 2, "wonder" },
		{ 3, "dwarfs" },
		{ 4, "boxing" }
	};

	TMap<int32, TMap<int32, FString>> FWordDifficulty
	{
		{ 1, FEasyWords },
		{ 2, FNormalWords },
		{ 3, FHardWords },
		{ 4, FVeryHardWords }
	};

	FString GetRandomHiddenWord();
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
