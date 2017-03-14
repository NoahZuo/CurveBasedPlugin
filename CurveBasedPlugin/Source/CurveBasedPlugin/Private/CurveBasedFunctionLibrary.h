
#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CurveBasedFunctionLibrary.generated.h"

#define TIMETOLERANCE 0.0001f

/**
 * 
 */
UCLASS()
class UCurveBasedFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "CurveBasedPlugin")
	static void SetComponentTickableInEditor(UActorComponent* Component, bool bCanEverTick, bool bTickInEditor);
};
