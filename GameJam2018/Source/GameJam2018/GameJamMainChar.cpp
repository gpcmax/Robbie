// Fill out your copyright notice in the Description page of Project Settings.

#include "GameJamMainChar.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AGameJamMainChar::AGameJamMainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCamera->SetupAttachment(SpringArm);

	PulseRadius = CreateDefaultSubobject<USphereComponent>(TEXT("PulseRadius"));
	PulseRadius->SetupAttachment(GetMesh());

	bIsOnLadder = false;
}

// Called when the game starts or when spawned
void AGameJamMainChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameJamMainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameJamMainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AGameJamMainChar::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameJamMainChar::MoveForward);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//PlayerInputComponent->BindAction("Pulse", IE_Pressed, this, &AGameJamMainChar::PulseAttack);
}

void AGameJamMainChar::MoveRight(float Value)
{
	if (bIsOnLadder) 
	{

	}
	else
	{
		AddMovementInput(FVector(0.0f, -1.0f, 0.0f), Value);
	}
}

void AGameJamMainChar::MoveForward(float Value)
{
	if (bIsOnLadder) 
	{
		//GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		//AddMovementInput(FVector(0.0f, 0.0f, 1.0f), Value);
		//GetMesh()->SetWorldRotation(FRotator(0.0f, 180.f, 0.0f));
		//AGameJamMainChar::AddActorWorldRotation(FRotator(0.0f, 180.f, 0.0f));
	}
	else
	{
		AddMovementInput(FVector(-0.85f, 0.0f, 0.0f), Value);
		//GetMesh()->SetWorldRotation(FRotator(0.0f, -180.f, 0.0f));
	}
}

void AGameJamMainChar::PulseAttack()
{
	//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PulseEffect, GetActorLocation());
	PulseRadius->SetSphereRadius(100);
}
