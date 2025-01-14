// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#include "DialogWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Components/AudioComponent.h"
#include "DialogCharacterInfo.h"
#include "Kismet/GameplayStatics.h"

void UDialogWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (AdvanceTextButton)
	{
		AdvanceTextButton->OnClicked.AddDynamic(this, &UDialogWidget::OnAdvanceButtonClicked);
	}

	GetNextLine(FirstLineId);
}

void UDialogWidget::GetNextLine(int32 LineId)
{
	FString SpeakerName;

	// Lookup next dialog line
	FString str = FString("000") + FString::FromInt(000 + LineId);
	FName LineIdName = *str.Right(3);
	DialogLineInfo = *DialogDataTable->FindRow<FDialogEntry>(LineIdName, "");

	if (DialogLineInfo.SpeakerName != EDialogCharacterNames::None)
	{
		NextLineId = DialogLineInfo.DialogLine.NextLineId;

		SpeakerName = UEnum::GetValueAsString(DialogLineInfo.SpeakerName);
		SpeakerName = SpeakerName.RightChop(SpeakerName.Find("::") + 2);

		SpeakerNameText->SetText(FText::FromString(SpeakerName));

		DialogText->SetText(DialogLineInfo.DialogLine.DialogText);

		if (DialogLineInfo.AudioClip)
		{
			if (AudioComponent && AudioComponent->IsActive())
			{
				AudioComponent->SetActive(false);
			}

			AudioComponent = UGameplayStatics::SpawnSound2D(GetWorld(), DialogLineInfo.AudioClip);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DialogWidget: DialogLineInfo row not found"));
	}

	// Lookup character info
	FName SpeakerRow = FName(SpeakerName);
	FDialogCharacterInfo* SpeakerInfo = CharacterInfoDataTable->FindRow<FDialogCharacterInfo>(SpeakerRow, "");

	if (SpeakerInfo)
	{
		if (SpeakerInfo->Portrait)
		{
			SpeakerPortrait->SetBrushFromTexture(SpeakerInfo->Portrait);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DialogWidget: CharacterInfoDataTable row not found"));
	}
}

void UDialogWidget::OnAdvanceButtonClicked()
{
	if (AudioComponent && AudioComponent->IsActive())
	{
		AudioComponent->SetActive(false);
	}

	if (NextLineId == -1)
	{
		OnConversationCompletedDelegate.Broadcast();
		return;
	}

	if (!DialogLineInfo.Responses.IsEmpty())
	{
		DisplayPlayerResponses(DialogLineInfo.Responses);
		return;
	}

	GetNextLine(NextLineId);
}

void UDialogWidget::DisplayPlayerResponses(const TArray<FDialogLine>& Responses)
{
	DialogText->SetText(FText());
	
	if (!PlayerResponseClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("DialogWidget: PlayerResponseClass not set"));

		NextLineId = -1;

		return;
	}

	AdvanceTextButton->SetVisibility(ESlateVisibility::Hidden);

	for (const FDialogLine Response : Responses)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

		UDialogPlayerResponse* ResponseWidget = Cast<UDialogPlayerResponse>(CreateWidget<UUserWidget>(this, PlayerResponseClass));

		ResponseWidget->SetResponseText(Response.DialogText);
		ResponseWidget->SetNextLineId(Response.NextLineId);

		ResponseWidget->OnResponseClickedDelegate.AddDynamic(this, &UDialogWidget::OnResponseConfirmed);

		ResponsesVbox->AddChildToVerticalBox(ResponseWidget);
	}

	if (ResponsesVbox->GetChildAt(0))
	{
		ResponsesVbox->GetChildAt(0)->SetFocus();
	}
}

void UDialogWidget::OnResponseConfirmed(const int32& LineId)
{
	for (auto Response : ResponsesVbox->GetAllChildren())
	{
		UDialogPlayerResponse* ResponseWidget = Cast<UDialogPlayerResponse>(Response);

		ResponseWidget->OnResponseClickedDelegate.RemoveDynamic(this, &UDialogWidget::OnResponseConfirmed);
	}

	ResponsesVbox->ClearChildren();

	DialogLineInfo = FDialogEntry();

	AdvanceTextButton->SetVisibility(ESlateVisibility::Visible);
	AdvanceTextButton->SetFocus();
	GetNextLine(LineId);
}
