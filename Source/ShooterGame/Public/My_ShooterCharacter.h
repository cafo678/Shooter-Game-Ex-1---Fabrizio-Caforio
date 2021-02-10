#pragma once

#include "CoreMinimal.h"
#include "Player/ShooterCharacter.h"
#include "My_ShooterCharacter.generated.h"

// Forward Declarations
class UMy_ShooterCharacterMovement;

UCLASS()
class SHOOTERGAME_API AMy_ShooterCharacter : public AShooterCharacter
{
	GENERATED_BODY()

public:
	// With this constructor Unreal will automatically initialize this Character with my new Movement Component
	AMy_ShooterCharacter(const class FObjectInitializer& ObjectInitializer);

private:
	// Input binding is set in the character in the original project, overriding this method let us expand those bindings
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Function that will call the Teleport implementation in the Movement Component
	void Teleport();

	// Function for get our Movement Component without casting
	UMy_ShooterCharacterMovement* GetMyMovementComponent() const;
	
};
