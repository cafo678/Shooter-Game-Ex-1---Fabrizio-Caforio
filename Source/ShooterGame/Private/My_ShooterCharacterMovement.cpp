#include "ShooterGame.h"
#include "My_ShooterCharacterMovement.h"

// Function called from the input binding in the character
void UMy_ShooterCharacterMovement::Teleport()
{
	// Calcolate the Location to teleport to
	TeleportLocation = PawnOwner->GetActorLocation() + PawnOwner->GetActorForwardVector() * TeleportOffset;
	
	// If we are the client and we have control we send the location to the server 
	if (PawnOwner->Role == ENetRole::ROLE_AutonomousProxy) 
		Server_SendTeleportLocation_Validate(TeleportLocation);

	// This boolean will trigger the movement in the OnMovementUpdated function native of the standard Movement Component
	bWantsToTeleport = true;
}

// Here we can validate the location of the teleport to prevent cheating
bool UMy_ShooterCharacterMovement::Server_SendTeleportLocation_Validate(FVector LocationToTeleport)
{
    return true;
}

// Here we save the location sent in the local variable
void UMy_ShooterCharacterMovement::Server_SendTeleportLocation_Implementation(FVector LocationToTeleport)
{
    TeleportLocation = LocationToTeleport;
}

// Function native of the standard Movement Component, this function is triggered at the end of a movement update.
void UMy_ShooterCharacterMovement::OnMovementUpdated(float DeltaTime, const FVector& OldLocation, const FVector& OldVelocity)
{
	if (!CharacterOwner)
		return;

	// If the player has pressed the teleport key
	if (bWantsToTeleport)
	{
		bWantsToTeleport = false;

		// Sweep so we avoid collisions
		CharacterOwner->SetActorLocation(TeleportLocation, true);
	}

	Super::OnMovementUpdated(DeltaTime, OldLocation, OldVelocity);
}