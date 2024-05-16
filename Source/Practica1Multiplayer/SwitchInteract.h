// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchInteract.generated.h"

UCLASS()
class PRACTICA1MULTIPLAYER_API ASwitchInteract : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USceneComponent* Pivot = nullptr;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USceneComponent* Root = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FRotator PivotRotationOn = {};

	UPROPERTY(EditDefaultsOnly)
	FRotator PivotRotationOff = {};
	
public:	
	// Sets default values for this actor's properties
	ASwitchInteract();

	UPROPERTY(BlueprintReadWrite)
	bool IsOn = false;

	UFUNCTION(BlueprintCallable)
	void Toggle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
