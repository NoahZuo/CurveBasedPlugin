#include "CurveBasedPluginPrivatePCH.h"
#include "CurveBasedPointLightComponent.h"
#include "CurveBasedFunctionLibrary.h"




UCurveBasedPointLightComponent::UCurveBasedPointLightComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, UseCurveIntensity(false)
	, UseCurveLightFunction(false)
	, UseCurveColor(false)
{
	UCurveBasedFunctionLibrary::SetComponentTickableInEditor(this, true, true);
}

void UCurveBasedPointLightComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateIntensity(DeltaTime);
	UpdateMaterialParameter(DeltaTime);
	UpdateColor(DeltaTime);
}

void UCurveBasedPointLightComponent::UpdateIntensity(float DeltaTime)
{
	if (UseCurveIntensity)
	{
		IntensityCurve.TimeElapsed += DeltaTime;

		auto result = IntensityCurve.GetCurveValue();
		SetIntensity(result);
	}
}

void UCurveBasedPointLightComponent::UpdateMaterialParameter(float DeltaTime)
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
			case ECurveType::LD_UseLinearColorCurve:
				DMI->SetVectorParameterValue(itr.Parameter, itr.GetLinearColorCurveValue());
			}
		}
	}
}

void UCurveBasedPointLightComponent::UpdateColor(float DeltaTime)
{
	if (UseCurveColor)
	{
		ColorCurve.TimeElapsed += DeltaTime;

		auto result = ColorCurve.GetCurveValue();
		SetLightColor(result);
	}
}

void UCurveBasedPointLightComponent::OnRegister()
{
	Super::OnRegister();

	if (LightFunctionMaterial)
	{
		auto tmpDMI = Cast<UMaterialInstanceDynamic>(LightFunctionMaterial);

		if (tmpDMI)
		{
			DMI = UMaterialInstanceDynamic::Create(tmpDMI->Parent, this);
			SetLightFunctionMaterial(DMI);
		}
		else
		{
			DMI = UMaterialInstanceDynamic::Create(LightFunctionMaterial, this);
			SetLightFunctionMaterial(DMI);
		}
	}
	else
	{
		UseCurveLightFunction = false;
		DMI = NULL;
	}
	

}