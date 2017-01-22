// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyHeight.generated.h"

UCLASS()
class GGJ17_API AMyHeight : public AActor
{
		GENERATED_BODY()

		UPROPERTY(Category = HeightMap, EditAnywhere)
		UTextureRenderTarget2D* RenderTarget;

		UFUNCTION(BluePrintCallable, Category = "HeightMap|Update")
			void UpdateBuffer();

		UFUNCTION(BluePrintCallable, Category = "HeightMap|Texture Helper")
			FColor GetRenderTargetValue(float x, float y);


public:	
	// Sets default values for this actor's properties
	AMyHeight();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float RuningTime;

private:
	TArray<FColor> ColorBuffer;
	
	
};
