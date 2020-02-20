// Social Cube Media 2020
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame(); // Setting up game

    PrintLine(TEXT("The HiddenWord is: %s. \nIt is %i charactes long."), *HiddenWord, HiddenWord.Len()); // Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    // Introduction 
    PrintLine(TEXT("Welcome to Bull Cow Game!"));

    HiddenWord = "house";
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Can you guess the %i letter word?"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives!"), Lives);
    PrintLine(TEXT("Enter your guess! \nPress enter to continue..."));



}

void UBullCowCartridge::EndGame()
{
    bGameOver = true; 
    PrintLine(TEXT("\nPress enter to play again...")); // Prompt To Play Again, Press Enter To Play Again?
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
      if (Guess == HiddenWord) // Is guess Correct?
      {
          PrintLine(TEXT("You Won!"));
          EndGame();
          return;
      }

      /// Check If Isogram
      if (!IsIsogram())
      {
          PrintLine(TEXT("Please enter an Isogram! A word without repeating letters!"));
          PrintLine(TEXT("You have lost a live! You have %i lives remaining!"), Lives--);    // Remove Life & Show Lives Left
          return;
      }

      if (Guess.Len() != HiddenWord.Len()) // Check Right Number Of Characters 
      {
          PrintLine(TEXT("Sorry wrong number of characters, try guessing again!"));
          PrintLine(TEXT("The word is %i characters long"), HiddenWord.Len());
          PrintLine(TEXT("You have %i lives remaining"), Lives);
          return;
      }

      if (Lives <= 0)
      {
          PrintLine(TEXT("You have no lives left!"));
          PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
          EndGame();
          return;
      }

    PrintLine(TEXT("Trying guessing again, you have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram()
{
    return false;
}
