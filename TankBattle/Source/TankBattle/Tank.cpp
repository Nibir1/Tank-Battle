#include "Tank.h"

ATank::ATank()
{	
	PrimaryActorTick.bCanEverTick = true;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent Called"));

	InputComponent->BindAxis();
	InputComponent->BindAction("Turret_CounterClockwise", IE_Pressed, this, &ATank::RotateCCW);
}

void ATank::RotateCW() 
{
	UE_LOG(LogTemp, Warning, TEXT("RotateCW Called"));
	Turret->SetRelativeRotation(FRotator(0.0f,45.0f,0.0f));
}

void ATank::RotateCCW()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateCCW Called"));
	Turret->SetRelativeRotation(FRotator(0.0f, -45.0f, 0.0f));
}


void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBp)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor Called"));
	Turret = TurretFromBp;
}
