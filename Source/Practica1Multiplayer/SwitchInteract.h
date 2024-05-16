// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "SwitchInteract.generated.h"

class UPointLightComponent;

UCLASS()
class PRACTICA1MULTIPLAYER_API ASwitchInteract : public AActor, public IInteractable
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

	UPROPERTY(EditDefaultsOnly)
	UPointLightComponent* Light = nullptr;
	
public:	
	// Sets default values for this actor's properties
	ASwitchInteract();

	UPROPERTY(BlueprintReadWrite)
	bool IsOn = false;

	UFUNCTION(BlueprintCallable)
	void Toggle();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_Toggle();

	virtual void Interact_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
