
#include "CurveBasedPluginPrivatePCH.h"
#include "CurveBasedPointLight.h"
#include "CurveBasedPointLightComponent.h"


// Sets default values
ACurveBasedPointLight::ACurveBasedPointLight(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightComponent = CreateDefaultSubobject<UCurveBasedPointLightComponent>(TEXT("LightComponent0"));
	RootComponent = LightComponent;


}
