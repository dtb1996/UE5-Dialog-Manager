// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#include "DialogPlayerResponse.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UDialogPlayerResponse::NativePreConstruct()
{
	Super::NativePreConstruct();

	DialogText->SetText(ResponseText);
}

void UDialogPlayerResponse::NativeConstruct()
{
	if (ConfirmButton)
	{
		ConfirmButton->OnClicked.AddDynamic(this, &UDialogPlayerResponse::OnConfirmButtonClicked);
	}
}

void UDialogPlayerResponse::OnConfirmButtonClicked()
{
	OnResponseClickedDelegate.Broadcast(NextLineId);
}

void UDialogPlayerResponse::SetResponseText(const FText Text)
{
	ResponseText = Text;

	DialogText->SetText(ResponseText);
}

void UDialogPlayerResponse::SetNextLineId(const int32 Id)
{
	NextLineId = Id;
}
