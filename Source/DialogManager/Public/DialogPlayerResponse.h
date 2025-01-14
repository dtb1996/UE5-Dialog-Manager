// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogPlayerResponse.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResponseClickedSignature, const int32&, NextLineId);

UCLASS(Abstract)
class DIALOGMANAGER_API UDialogPlayerResponse : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Inventory Manager")
	FResponseClickedSignature OnResponseClickedDelegate;
	
protected:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnConfirmButtonClicked();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* DialogText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ConfirmButton;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	FText ResponseText;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = true))
	int32 NextLineId;

public:
	void SetResponseText(const FText Text);

	void SetNextLineId(const int32 Id);
};
