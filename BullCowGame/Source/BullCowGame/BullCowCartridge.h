// Social Cube Media 2020

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

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

	TArray<FString> GetValidWords(const TArray<FString>& WordsList) const;

	// Your declarations go below!
	private:
		FString HiddenWord;
		int32 Lives; 
		bool bGameOver;
		
		bool IsIsogram(FString Word) const;
		TArray<FString> Isograms;
};
