#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "movimientoarribaabajodiagonal.generated.h"

// Enum visible en el editor (dropdown)
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

	// Componente visual (el cubo)
	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UStaticMeshComponent* MeshComponent;

public:
	virtual void Tick(float DeltaTime) override;

	// ?? CONFIGURACIÓN DE MOVIMIENTO (esto es lo que tu profe quiere ver)
	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Velocidad;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	EMoveDirection DireccionMovimiento;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMover;

private:
	FVector ObtenerVectorDireccion();
};