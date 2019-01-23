// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameJamMainChar.generated.h"

UCLASS()
class GAMEJAM2018_API AGameJamMainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameJamMainChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		class UCameraComponent* SideViewCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = Camera)
		class UParticleSystem* PulseEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attack)
		class USphereComponent* PulseRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attack)
		bool bIsOnLadder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(float Value);

	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable, Category = Attacks)
	void PulseAttack();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
