#pragma once

#include "CoreMinimal.h"
#include "Player/ShooterCharacterMovement.h"
#include "My_ShooterCharacterMovement.generated.h"

UCLASS()
class SHOOTERGAME_API UMy_ShooterCharacterMovement : public UShooterCharacterMovement
{
	GENERATED_BODY()

public:
	void Teleport();
	
};
