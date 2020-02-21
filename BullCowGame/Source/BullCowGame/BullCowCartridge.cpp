// Social Cube Media 2020
#include "BullCowCartridge.h"
#include "Public/HiddenWordList.h"

void UBullCowCartridge::BeginPlay() 
{
    Super::BeginPlay();
    auto Isograms = GetValidWords(Words);
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(PlayerInput);
    }
}

void UBullCowCartridge::SetupGame()
{
    // Introduction 
    PrintLine(TEXT("Welcome to Bull Cow Game!"));

    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
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

void UBullCowCartridge::ProcessGuess(const FString& Guess)
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
        PrintLine(TEXT("Please enter an Isogram! A word without \nrepeating letters!"));
        PrintLine(TEXT("You have lost a live! You have %i lives \nremaining!"), Lives--);    // Remove Life & Show Lives Left
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

   FBullCowCount Score = GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);
    PrintLine(TEXT("Trying guessing again, you have %i lives left"), Lives);
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }
    return ValidWords;
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

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 HWIndex = 0; HWIndex < HiddenWord.Len(); HWIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HWIndex])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}
