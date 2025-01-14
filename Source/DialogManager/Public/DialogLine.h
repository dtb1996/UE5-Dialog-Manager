// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DialogLine.generated.h"

USTRUCT(BlueprintType)
struct FDialogLine : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DialogText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 NextLineId;
};