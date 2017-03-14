#pragma once

#include "DataTypes.generated.h"
#define TIMETOLERANCE 0.0001f
UENUM(BlueprintType)
namespace ECurveType
{
	enum Type
	{
		CT_DoNotUseCurve = 0,
		LD_UseFloatCurve,
		LD_UseVectorCurve,
	};
}

/*
* Todo: Using Template instead of this stupid way. 
*/
USTRUCT(BlueprintType)
struct FFloatCurveData
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	class UCurveFloat* FloatCurve;

	float TimeElapsed;

	virtual float GetCurveValue()
	{
		float result = 0.f;
		if (FloatCurve)
		{
			float minTime, maxTime;
			FloatCurve->GetTimeRange(minTime, maxTime);

			if (maxTime - minTime <= TIMETOLERANCE)
				return result;

			while (TimeElapsed >= maxTime)
			{
				TimeElapsed -= maxTime;
			}

			result = FloatCurve->GetFloatValue(TimeElapsed);
		}

		return result;
	
	}
};


USTRUCT(BlueprintType)
struct FVectorCurveData
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	class UCurveVector* VectorCurve;

	float TimeElapsed;

	virtual FVector GetCurveValue()
	{
		FVector result;
		if (VectorCurve)
		{
			float minTime, maxTime;
			VectorCurve->GetTimeRange(minTime, maxTime);

			if (maxTime - minTime <= TIMETOLERANCE)
				return result;

			while (TimeElapsed >= maxTime)
			{
				TimeElapsed -= maxTime;
			}

			result = VectorCurve->GetVectorValue(TimeElapsed);
		}

		return result;

	}
};

USTRUCT(BlueprintType)
struct FSelectableCurveData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	class UCurveFloat* FloatCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	class UCurveVector* VectorCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	TEnumAsByte<ECurveType::Type> CurveType;

	float TimeElapsed;

	virtual float GetFloatCurveValue()
	{
		float result = 0.f;
		if (FloatCurve)
		{
			float minTime, maxTime;
			FloatCurve->GetTimeRange(minTime, maxTime);

			if (maxTime - minTime <= TIMETOLERANCE)
				return result;

			while (TimeElapsed >= maxTime)
			{
				TimeElapsed -= maxTime;
			}

			result = FloatCurve->GetFloatValue(TimeElapsed);
		}

		return result;

	}


	virtual FVector GetVectorCurveValue()
	{
		FVector result;
		if (VectorCurve)
		{
			float minTime, maxTime;
			VectorCurve->GetTimeRange(minTime, maxTime);

			if (maxTime - minTime <= TIMETOLERANCE)
				return result;

			while (TimeElapsed >= maxTime)
			{
				TimeElapsed -= maxTime;
			}

			result = VectorCurve->GetVectorValue(TimeElapsed);
		}

		return result;

	}
};

USTRUCT(BlueprintType)
struct FMaterialParameterCurveData : public FSelectableCurveData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	FName Parameter;
};