#include "CurveBasedPluginPrivatePCH.h"
#include "CurveBasedPlugin.h"
#include "CurveBasedFunctionLibrary.h"


void UCurveBasedFunctionLibrary::SetComponentTickableInEditor(UActorComponent* Component, bool bCanEverTick, bool bTickInEditor)
{
	if (Component)
	{
		Component->PrimaryComponentTick.bCanEverTick = bCanEverTick;
		Component->bTickInEditor = bTickInEditor;
	}
}
