#pragma once

#include "CoreMinimal.h"
#include "Player/ShooterCharacterMovement.h"
#include "My_ShooterCharacterMovement.generated.h"

UCLASS()
class SHOOTERGAME_API UMy_ShooterCharacterMovement : public UShooterCharacterMovement
{
	GENERATED_BODY()

public:
	// Function called from the input binding in the character
	void Teleport();

private:
	// RPC that will execute on the server, sending the location to which the character will teleport. We can validate if we want.
	UFUNCTION(Reliable, Server, WithValidation)
	void Server_SendTeleportLocation(FVector LocationToTeleport);

	// Function native of the standard Movement Component, this function is triggered at the end of a movement update.
	void OnMovementUpdated(float DeltaTime, const FVector& OldLocation, const FVector& OldVelocity) override;

	// Location to which the character will teleport
	FVector TeleportLocation;

	// We want to teleport 10m forward
	float TeleportOffset = 1000; 

	// This boolean will trigger the movement in the OnMovementUpdated function native of the standard Movement Component
	// We use a single bit of a byte to fit this boolean in the FSavedMove_Character template we will override
	uint8 bWantsToTeleport : 1;
	
};
