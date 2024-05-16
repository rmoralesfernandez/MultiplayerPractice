// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchInteract.h"

// Sets default values
ASwitchInteract::ASwitchInteract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Root->SetupAttachment(RootComponent);
	SetRootComponent(Root);
	
	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));
	Pivot->SetupAttachment(Root);

	
}

void ASwitchInteract::Toggle()
{
	IsOn = !IsOn;

	Pivot->SetRelativeRotation(IsOn ? PivotRotationOn : PivotRotationOff);
}

// Called when the game starts or when spawned
void ASwitchInteract::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitchInteract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

