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
		LD_UseLinearColorCurve, 
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
struct FLinearColorCurveData
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
	class UCurveLinearColor* LinearColorCurve;

	float TimeElapsed;

	virtual FVector GetCurveValue()
	{
		FLinearColor result;
		if (LinearColorCurve)
		{
			float minTime, maxTime;
			LinearColorCurve->GetTimeRange(minTime, maxTime);

			if (maxTime - minTime <= TIMETOLERANCE)
				return result;

			while (TimeElapsed >= maxTime)
			{
				TimeElapsed -= maxTime;
			}

			result = LinearColorCurve->GetLinearColorValue(TimeElapsed);
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
	class UCurveLinearColor* LinearColorCurve;

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

	virtual FVector GetLinearColorCurveValue()
	{
		FLinearColor result;
		if (LinearColorCurve)
		{
			float minTime, maxTime;
			LinearColorCurve->GetTimeRange(minTime, maxTime);

			if (maxTime - minTime <= TIMETOLERANCE)
				return result;

			while (TimeElapsed >= maxTime)
			{
				TimeElapsed -= maxTime;
			}

			result = LinearColorCurve->GetLinearColorValue(TimeElapsed);
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