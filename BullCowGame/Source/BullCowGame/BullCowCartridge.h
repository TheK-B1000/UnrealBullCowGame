// Social Cube Media 2020

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& PlayerInput) override;
	void SetupGame();
	void EndGame();
	void ProcessGuess(const FString& Guess);
	FBullCowCount GetBullCows(const FString& Guess) const;

	TArray<FString> GetValidWords(const TArray<FString>& WordsList) const;

	// Your declarations go below!
	private:
		FString HiddenWord;
		int32 Lives; 
		bool bGameOver;
		
		bool IsIsogram(FString Word) const;
		TArray<FString> Isograms;
};
