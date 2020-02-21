// Social Cube Media 2020
#include "BullCowCartridge.h"
#include "Public/HiddenWordList.h"

void UBullCowCartridge::BeginPlay() 
{
    Super::BeginPlay();
    SetupGame();
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

    if (Guess.Len() != HiddenWord.Len()) // Check Right Number Of Characters 
    {
        PrintLine(TEXT("Sorry wrong number of characters, try guessing again!"));
        PrintLine(TEXT("The word is %i characters long"), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining"), Lives);
        return;
    }

    /// Check If Isogram
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("Please enter an Isogram! A word without repeating letters!"));
        PrintLine(TEXT("You have lost a live! You have %i lives remaining!"), Lives--);    // Remove Life & Show Lives Left
        return;
    }

      if (Lives <= 0)
      {
          ClearScreen();
          PrintLine(TEXT("You have no lives left!"));
          PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
          EndGame();
          return;
      }
    PrintLine(TEXT("Trying guessing again, you have %i lives left"), Lives);
}

TArray<FString> UBullCowCartridge::CheckValidWords(TArray<FString> WordsList) const
{
    TArray<FString> ValueWords;

    for (auto Index = 0; Index < 10; Index++)
    {
        if (WordsList[Index].Len() >= 4 && WordsList[Index].Len() <= 8)
        {
            if (IsIsogram(WordsList[Index]))
            {
                ValueWords.Emplace(WordsList[Index]);
            }
        }
    }
    return ValueWords;
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    for (auto Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }
    return true;
}
