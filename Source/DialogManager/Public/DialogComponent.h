// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogCharacterNames.h"
#include "DialogComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIALOGMANAGER_API UDialogComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDialogComponent();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	EDialogCharacterNames Name;

	UPROPERTY(EditAnywhere)
	int32 InitialDialogLineId = -1;

	UPROPERTY(EditAnywhere)
	int32 NextDialogLineId;
		
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	EDialogCharacterNames GetCharacterName() const;

	UFUNCTION(BlueprintCallable)
	void SetCharacterName(const EDialogCharacterNames NewName);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetNextDialogLineId() const;

	UFUNCTION(BlueprintCallable)
	void SetNextDialogLineId(const int32 LineId);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ConversationCompleted();
};
