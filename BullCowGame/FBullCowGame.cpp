#include "FBullCowGame.h"

// Definitions

FBullCowGame::FBullCowGame(int MaxTries)
{
	GameMaxTries = MaxTries;
	FBullCowGame::Reset();
	return;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
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

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

void FBullCowGame::NextTry()
{
	MyCurrentTry++;
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = GameMaxTries;
	return;
}
