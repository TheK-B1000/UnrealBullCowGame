// Social Cube Media 2020
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Introduction 
    PrintLine(TEXT("Welcome to Bull Cow Game!"));
    PrintLine(TEXT("Can you guess the 3 letter word?"));
    PrintLine(TEXT("Press Enter to Continue...")); 

    SetupGame(); // Setting up game

    // Prompt to check guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen(); // Clear up terminal
    PrintLine(Input); // Print out Input

    // Check Guess
        // IsIsogram?
            // No
                // Error Message
                    // Try Again
            // Yes
                // Isogram == HiddenWord
                    // No
                        // Remove a life
                    // Yes
                        // Win


        // IsLowercase
             // No
                // Error Message
                    // Try Again
            // Yes
                // Isogram.islower(Letter) == HiddenWord.islower(Letter)
                    // No
                        // Remove a life
                    // Yes

        // Wrong_Length
             // No
                // Error Message
                    // Try Again
            // Yes
                // Isogram.length() == HiddenWord.length()
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
        // Print Win Message
        PrintLine(TEXT("You Won!"));
    }
    else
    {
        // Print Lose Message
        PrintLine(TEXT("You Lost!"));
    }


}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = "ape";  
    Lives = 4;
}
