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

	void RotateCW();
	void RotateCCW();
	
	UChildActorComponent* Turret;
};
