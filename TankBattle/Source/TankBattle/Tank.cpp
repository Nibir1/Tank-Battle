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

	InputComponent->BindAxis("Rotate_Turret",this,&ATank::RotateTurret);
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	Turret->AddRelativeRotation(FRotator(0.0f, Speed, 0.0f));
}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBp)
{
	Turret = TurretFromBp;
}
