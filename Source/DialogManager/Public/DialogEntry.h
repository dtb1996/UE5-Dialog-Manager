// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DialogCharacterNames.h"
#include "DialogLine.h"
#include "DialogEntry.generated.h"

USTRUCT(BlueprintType)
struct FDialogEntry : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EDialogCharacterNames SpeakerName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FDialogLine DialogLine;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USoundBase* AudioClip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FDialogLine> Responses;
};