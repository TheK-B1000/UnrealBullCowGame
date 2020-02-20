// Social Cube Media 2020
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); // Setting up game

    PrintLine(TEXT("The HiddenWord is: %s. \nIt is %i charactes long."), *HiddenWord, HiddenWord.Len()); // Debug line

    // Introduction 
    PrintLine(TEXT("Welcome to Bull Cow Game!"));
    PrintLine(TEXT("Can you guess the %i letter word?"), HiddenWord.Len());
    PrintLine(TEXT("Enter your guess!")); 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen(); // Clear up terminal

    HiddenWord.Len();

    PrintLine(Input); // Print out Input

    // Check Guess
        // IsIsogram?
            // No
                // Error Message
                    // Try Again
            // Yes
             
                  
                   

        // IsLowercase
             // No
                // Error Message
                    // Try Again
            // Yes
                // Isogram.islower(Letter) == HiddenWord.islower(Letter)
                    // No
                        // Remove a life
                    // Yes


    // Check if Lives > 0
           // Yes 
                // Try Again
           // No
                // You Lose
    // Ask To Play Again


    // Check if Input == HiddenWord
    if (Input == HiddenWord) // Is guess Correct?
    {
        PrintLine(TEXT("You Won!"));
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The HiddenWord is %i characters long. \nPlease try again!"), HiddenWord.Len());
        }
        PrintLine(TEXT("You Lost!"));
    }


}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = "ape";  
    Lives = 4;
}
