#include "CurveBasedPluginPrivatePCH.h"
#include "CurveBasedSpotLightComponent.h"
#include "CurveBasedFunctionLibrary.h"

UCurveBasedSpotLightComponent::UCurveBasedSpotLightComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, UseCurveIntensity(false)
	, UseCurveLightFunction(false)
	, UseCurveColor(false)
{
	UCurveBasedFunctionLibrary::SetComponentTickableInEditor(this, true, true);
}

void UCurveBasedSpotLightComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateIntensity(DeltaTime);
	UpdateMaterialParameter(DeltaTime);
	UpdateColor(DeltaTime);
}

void UCurveBasedSpotLightComponent::UpdateIntensity(float DeltaTime)
{
	if (UseCurveIntensity)
	{
		IntensityCurve.TimeElapsed += DeltaTime;

		auto result = IntensityCurve.GetCurveValue();
		SetIntensity(result);
	}
}

void UCurveBasedSpotLightComponent::UpdateMaterialParameter(float DeltaTime)
{
	if (UseCurveLightFunction && LightFunctionMaterial && DMI)
	{
		for (auto& itr : MaterialParameterCurves)
		{
			itr.TimeElapsed += DeltaTime;
			switch (itr.CurveType)
			{
			case ECurveType::CT_DoNotUseCurve:
				break;
			case ECurveType::LD_UseFloatCurve:
				DMI->SetScalarParameterValue(itr.Parameter, itr.GetFloatCurveValue());
				break;
			case ECurveType::LD_UseVectorCurve:
				DMI->SetVectorParameterValue(itr.Parameter, itr.GetVectorCurveValue());
				break;
			}
		}
	}
}

void UCurveBasedSpotLightComponent::UpdateColor(float DeltaTime)
{
	if (UseCurveColor)
	{
		ColorCurve.TimeElapsed += DeltaTime;

		auto result = ColorCurve.GetCurveValue();
		SetLightColor(result);
	}
}

void UCurveBasedSpotLightComponent::OnRegister()
{
	Super::OnRegister();
	if (LightFunctionMaterial)
	{
		auto mat = LightFunctionMaterial->GetMaterial();

		DMI = UMaterialInstanceDynamic::Create(mat, this);
		SetLightFunctionMaterial(DMI);
	}
	else
	{
		UseCurveLightFunction = false;
		DMI = NULL;
	}
}