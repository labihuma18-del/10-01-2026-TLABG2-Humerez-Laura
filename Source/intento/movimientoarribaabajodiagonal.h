#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "movimientoarribaabajodiagonal.generated.h"

UENUM(BlueprintType)
enum class EMoveDirection : uint8
{
	Up          UMETA(DisplayName = "Arriba"),
	Down        UMETA(DisplayName = "Abajo"),
	Left        UMETA(DisplayName = "Izquierda"),
	Right       UMETA(DisplayName = "Derecha"),
	UpRight     UMETA(DisplayName = "Diagonal Arriba Derecha"),
	UpLeft      UMETA(DisplayName = "Diagonal Arriba Izquierda"),
	DownRight   UMETA(DisplayName = "Diagonal Abajo Derecha"),
	DownLeft    UMETA(DisplayName = "Diagonal Abajo Izquierda")
};

UCLASS()
class INTENTO_API Amovimientoarribaabajodiagonal : public APawn
{
	GENERATED_BODY()

public:
	Amovimientoarribaabajodiagonal();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UStaticMeshComponent* MeshComponent;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Velocidad;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	EMoveDirection DireccionMovimiento;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMover;

private:
	FVector ObtenerVectorDireccion();
};
