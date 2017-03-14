
#include "CurveBasedPluginPrivatePCH.h"
#include "CurveBasedSpotLight.h"


// Sets default values
ACurveBasedSpotLight::ACurveBasedSpotLight(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightComponent = CreateDefaultSubobject<UCurveBasedSpotLightComponent>(TEXT("LightComponent0"));
	RootComponent = LightComponent;

}
