// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DialogCharacterNames.h"
#include "DialogCharacterInfo.generated.h"

USTRUCT(BlueprintType)
struct FDialogCharacterInfo : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EDialogCharacterNames Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UTexture2D* Portrait;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Occupation;
};
