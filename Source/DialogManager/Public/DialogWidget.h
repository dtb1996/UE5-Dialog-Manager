// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogEntry.h"
#include "DialogPlayerResponse.h"
#include "DialogWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConversationCompletedSignature);

UCLASS(Abstract)
class DIALOGMANAGER_API UDialogWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Dialog Manager")
	FConversationCompletedSignature OnConversationCompletedDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	int32 FirstLineId;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<class UDialogPlayerResponse> PlayerResponseClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* DialogDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* CharacterInfoDataTable;
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Dialog Manager")
	void GetNextLine(int32 LineId);

	UFUNCTION(BlueprintCallable, Category = "Dialog Manager")
	void OnAdvanceButtonClicked();

	UFUNCTION(BlueprintCallable, Category = "Dialog Manager")
	void DisplayPlayerResponses(const TArray<FDialogLine>& Responses);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* DialogText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* SpeakerNameText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* SpeakerPortrait;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* AdvanceTextButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UVerticalBox* ResponsesVbox;

	UPROPERTY(BlueprintReadWrite)
	int32 NextLineId;

	UPROPERTY(BlueprintReadWrite)
	FDialogEntry DialogLineInfo;

	UAudioComponent* AudioComponent;

private:
	UFUNCTION()
	void OnResponseConfirmed(const int32& LineId);
};
