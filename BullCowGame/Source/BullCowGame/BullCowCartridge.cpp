// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    HiddenWord = "ape";
    PrintLine(TEXT("Welcome to Bull Cow Game!"));
    PrintLine(TEXT("Can you guess the 3 letter word?"));
    PrintLine(TEXT("Press Enter to Continue...")); 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen(); // Clear up terminal
    PrintLine(Input); // Print out Input

    // Check if Input == HiddenWord
    if (Input == HiddenWord) // Is guess Correct?
    {
        // Print Win Message
        PrintLine(TEXT("You Won!"));
    }
    else
    {
        // Print Lose Message
        PrintLine(TEXT("You Loset!"));
    }
}