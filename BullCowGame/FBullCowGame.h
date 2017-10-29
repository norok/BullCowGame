#pragma once

#include <string>;

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	void IntroduceTheGame() const;
	void NextTry();
	bool CheckGuessValidity(std::string);
	bool IsGameWon();
	void Reset();

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
