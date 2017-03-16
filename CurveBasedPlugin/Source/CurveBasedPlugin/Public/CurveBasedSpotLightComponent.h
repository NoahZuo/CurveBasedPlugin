#pragma once

#include "Components/SpotLightComponent.h"
#include "DataTypes.h"
#include "CurveBasedSpotLightComponent.generated.h"

const float TOLERANCE_TIME = 0.0001f;

/**
 * This is the SpotLight that allow tick in Editor. 
 * You can use curve tools to change the scalar parameters of a Light Function.
 * Allows preview. So you don't have to run or simulate to view the effect. 
 */
UCLASS(editinlinenew, meta = (BlueprintSpawnableComponent))
class CURVEBASEDPLUGIN_API UCurveBasedSpotLightComponent : public USpotLightComponent
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	uint32 UseCurveIntensity : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	uint32 UseCurveColor : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	uint32 UseCurveLightFunction : 1;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	TArray<FMaterialParameterCurveData> MaterialParameterCurves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	FFloatCurveData IntensityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	FLinearColorCurveData ColorCurve;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	

private:
	UMaterialInstanceDynamic* DMI;

	void UpdateIntensity(float DeltaTime);
	void UpdateMaterialParameter(float DeltaTime);
	void UpdateColor(float DeltaTime);
};
