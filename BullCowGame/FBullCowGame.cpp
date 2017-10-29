#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
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

void FBullCowGame::NextTry()
{
	MyCurrentTry++;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	return;
}
