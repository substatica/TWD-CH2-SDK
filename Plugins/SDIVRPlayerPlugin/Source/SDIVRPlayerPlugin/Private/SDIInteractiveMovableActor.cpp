#include "SDIInteractiveMovableActor.h"
#include "SDICollisionChannelIgnoranceComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

class UPrimitiveComponent;
class AActor;
class APawn;
class ASDIPlayerHand;

void ASDIInteractiveMovableActor::UpdateTickEnabled_Implementation() {
}

bool ASDIInteractiveMovableActor::ShouldTickBeEnabled_Implementation() const {
    return false;
}

void ASDIInteractiveMovableActor::SetProjectedLinearVelocity(FVector DesiredVelocity) {
}

void ASDIInteractiveMovableActor::SetCanBeMoved(bool bMovable) {
}

void ASDIInteractiveMovableActor::SetAllowMantle(bool bMantle) {
}

void ASDIInteractiveMovableActor::ReleaseGrips() {
}

FVector ASDIInteractiveMovableActor::ProjectVectorIntoMovementPlane(const FVector& Vector) const {
    return FVector{};
}

void ASDIInteractiveMovableActor::OnPhysicsComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName) {
}

void ASDIInteractiveMovableActor::OnPhysicsComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName) {
}

void ASDIInteractiveMovableActor::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void ASDIInteractiveMovableActor::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASDIInteractiveMovableActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool ASDIInteractiveMovableActor::IsStandingOn(const APawn* Pawn) const {
    return false;
}

bool ASDIInteractiveMovableActor::IsMantlingOn(const APawn* Pawn) const {
    return false;
}

bool ASDIInteractiveMovableActor::IsInWater() const {
    return false;
}

bool ASDIInteractiveMovableActor::IsBeingGripped() const {
    return false;
}

AActor* ASDIInteractiveMovableActor::GetGrippedBy() const {
    return NULL;
}

FVector ASDIInteractiveMovableActor::GetCurrentFloorNormal() const {
    return FVector{};
}

bool ASDIInteractiveMovableActor::CanBeGrabbed_Implementation(ASDIPlayerHand* hand) const {
    return false;
}

bool ASDIInteractiveMovableActor::AllowHandMove_Implementation(ASDIPlayerHand* hand) const {
    return false;
}

ASDIInteractiveMovableActor::ASDIInteractiveMovableActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint"));
    this->CollisionIgnoranceComp = CreateDefaultSubobject<USDICollisionChannelIgnoranceComponent>(TEXT("CollisionIgnorance"));
    this->bCanBeMoved = true;
    this->bAxialMovementOnly = false;
    this->bSlopeTransitionAssistance = false;
    this->SlopeTransitionForce = 10000.00f;
    this->bAllowMantle = true;
    this->MaxMovementVelocity = 150.00f;
    this->MovementAcceleration = 100.00f;
    this->MovementDeceleration = 1000.00f;
    this->Buoyancy = 0.00f;
    this->FluidFrictionMultiplier = 1.00f;
    this->bCustomPhysicsBeingMantled = false;
    this->bCustomPhysicsInWater = false;
    this->CustomPhysicsFluidFriction = 0.00f;
    this->CustomPhysicsImmersionDepth = 0.00f;
    this->CustomPhysicsGravityZ = 0.00f;
    this->CurrentFloorNormalFrame = 0;
}

