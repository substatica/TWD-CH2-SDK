#pragma once
#include "CoreMinimal.h"
#include "SDIPlayerHandMove.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIPlayerHandMove {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinVal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxVal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Factor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FactorExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AvgTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinOffsetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float BlendLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUseAcc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bCheckAgainstOffsetDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NonVRInputButtonTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float CheckAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bDirectionalityAffectsFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DirectionalityFactorExp;
    
    FSDIPlayerHandMove();
};

