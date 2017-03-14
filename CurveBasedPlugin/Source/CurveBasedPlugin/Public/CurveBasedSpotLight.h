#pragma once
#include "CurveBasedSpotLightComponent.h"
#include "GameFramework/Actor.h"
#include "CurveBasedSpotLight.generated.h"


UCLASS()
class CURVEBASEDPLUGIN_API ACurveBasedSpotLight : public AActor
{
	GENERATED_UCLASS_BODY()


	UPROPERTY(Category = Light, VisibleAnywhere, BlueprintReadOnly)
	class UCurveBasedSpotLightComponent* LightComponent;
};
