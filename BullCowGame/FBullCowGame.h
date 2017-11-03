#pragma once

#include <string>;

// Declarations
class FBullCowGame
{
public:
	FBullCowGame(int MaxTries); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	void IntroduceTheGame() const;
	bool CheckGuessValidity(std::string);
	void NextTry();
	
	bool IsGameWon() const;
	void Reset();

	// provide a method for counting bulls and cows and increasing turn numbers

private:
	int MyCurrentTry;
	int MyMaxTries;
	int GameMaxTries;
};
