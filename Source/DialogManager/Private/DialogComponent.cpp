// Copyright 2025, Bit Gaming Studio. All Rights Reserved

#include "DialogComponent.h"

UDialogComponent::UDialogComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDialogComponent::BeginPlay()
{
	Super::BeginPlay();
}

EDialogCharacterNames UDialogComponent::GetCharacterName() const
{
	return Name;
}

void UDialogComponent::SetCharacterName(const EDialogCharacterNames NewName)
{
	Name = NewName;
}

int32 UDialogComponent::GetNextDialogLineId() const
{
	return InitialDialogLineId >= 0 ? InitialDialogLineId : NextDialogLineId;
}

void UDialogComponent::SetNextDialogLineId(const int32 LineId)
{
	NextDialogLineId = LineId;
}

void UDialogComponent::ConversationCompleted_Implementation()
{

}
