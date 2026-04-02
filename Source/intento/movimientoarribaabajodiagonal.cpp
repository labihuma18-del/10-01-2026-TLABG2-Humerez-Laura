#include "movimientoarribaabajodiagonal.h"
#include "Components/StaticMeshComponent.h"

// Constructor
Amovimientoarribaabajodiagonal::Amovimientoarribaabajodiagonal()
{
	PrimaryActorTick.bCanEverTick = true;

	// Crear el mesh (cubo)
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Valores por defecto
	Velocidad = 200.0f;
	bMover = true;
	DireccionMovimiento = EMoveDirection::Right;
}

// BeginPlay
void Amovimientoarribaabajodiagonal::BeginPlay()
{
	Super::BeginPlay();
}

// Tick (movimiento continuo)
void Amovimientoarribaabajodiagonal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bMover) return;

	FVector Direccion = ObtenerVectorDireccion();

	FVector NuevaPosicion = GetActorLocation() + (Direccion * Velocidad * DeltaTime);
	SetActorLocation(NuevaPosicion);
}

// Función que convierte enum ? vector (CLAVE DE LA TAREA)
FVector Amovimientoarribaabajodiagonal::ObtenerVectorDireccion()
{
	switch (DireccionMovimiento)
	{
	case EMoveDirection::Up: return FVector(0, 1, 0);
	case EMoveDirection::Down: return FVector(0, -1, 0);
	case EMoveDirection::Left: return FVector(-1, 0, 0);
	case EMoveDirection::Right: return FVector(1, 0, 0);

	case EMoveDirection::UpRight: return FVector(1, 1, 0).GetSafeNormal();
	case EMoveDirection::UpLeft: return FVector(-1, 1, 0).GetSafeNormal();
	case EMoveDirection::DownRight: return FVector(1, -1, 0).GetSafeNormal();
	case EMoveDirection::DownLeft: return FVector(-1, -1, 0).GetSafeNormal();
	}

	return FVector(1, 0, 0);
}