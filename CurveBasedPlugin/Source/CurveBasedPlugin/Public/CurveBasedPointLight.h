#pragma once

#include "GameFramework/Actor.h"
#include "CurveBasedPointLightComponent.h"
#include "CurveBasedPointLight.generated.h"

UCLASS()
class CURVEBASEDPLUGIN_API ACurveBasedPointLight : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(Category = Light, VisibleAnywhere, BlueprintReadOnly)
	class UCurveBasedPointLightComponent* LightComponent;
	
};
