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
        if (Input == HiddenWord) // Is guess Correct?
        {
            PrintLine(TEXT("You Won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The HiddenWord is %i characters long. \nYou have lost!"), HiddenWord.Len());
            }
            PrintLine(TEXT("Try Again!"));
            EndGame();
        }

        // Check Guess
         // IsIsogram?
             // No
                 // Error Message
                     // Try Again
             // Yes
     // Check if Lives > 0
            // Yes 
                 // Try Again
            // No
                 // You Lose
     // Ask To Play Again

    }
 
}

void UBullCowCartridge::SetupGame()
{
    // Introduction 
    PrintLine(TEXT("Welcome to Bull Cow Game!"));

    HiddenWord = "house";
    Lives = 4;
    bGameOver = false;

    PrintLine(TEXT("Can you guess the %i letter word?"), HiddenWord.Len());
    PrintLine(TEXT("Enter your guess! \nPress enter to continue..."));



}

void UBullCowCartridge::EndGame()
{
    bGameOver = true; 
    PrintLine(TEXT("Press enter to play again..."));
}
