#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetTurretChildActor(UChildActorComponent* TurretFromBp);

private:

	// Rotate turret at speed , -ve values for CCW
	void RotateTurret(float Speed);

	// A reference from blueprint
	UChildActorComponent* Turret = nullptr;
};
