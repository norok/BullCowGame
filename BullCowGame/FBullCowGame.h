#pragma once

#include <string>;

class FBullCowGame
{
public:
	FBullCowGame(int MaxTries); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	void IntroduceTheGame() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string);
	void NextTry();
	void Reset();

private:
	int MyCurrentTry;
	int MyMaxTries;
	int GameMaxTries;
};
