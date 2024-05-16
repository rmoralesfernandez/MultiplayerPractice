// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Logging/StructuredLog.h"
#include "Net/UnrealNetwork.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// DOREPLIFETIME(UHealthComponent, Health);
	DOREPLIFETIME_CONDITION(UHealthComponent, Health, COND_OwnerOnly);
}

void UHealthComponent::OnRep_Health(int old)
{
	UE_LOGFMT(LogTemp, Log, "Rep HEalth {0}", Health);
}