// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ17.h"
#include "MyHeight.h"


// Sets default values
AMyHeight::AMyHeight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyHeight::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AMyHeight::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	
	

	 //NewRotation.X += 300;
	float DeltaHeight = (FMath::Sin(RuningTime + DeltaTime) - FMath::Sin(RuningTime));
	NewLocation.Z += DeltaHeight * (55.0f + (rand() % 50));
	RuningTime += DeltaTime;
	SetActorLocation(NewLocation);

}

void AMyHeight::UpdateBuffer()
{
	ColorBuffer.Reset();

	if (RenderTarget != NULL)
	{
		FTextureRenderTarget2DResource* textureResource = (FTextureRenderTarget2DResource*)RenderTarget->Resource;
		if (textureResource->ReadPixels(ColorBuffer))
		{ }
	}
}

FColor AMyHeight::GetRenderTargetValue(float x, float y)
{
	float size = 50000.0f;

	if(RenderTarget == NULL || ColorBuffer.Num() == 0)
	{
		return FColor(0);
	}

	float width = RenderTarget->GetSurfaceWidth();
	float height = RenderTarget->GetSurfaceHeight();

	//Convert the coordinates to texture space
	float normalizedX = (x / size) + 0.5f;
	float normalizedY = (y / size) + 0.5f;

	int i = (int)(normalizedX * width);
	int j = (int)(normalizedY * height);

	if (i < 0) i = 0;
	if (i >= width) i = width - 1;
	if (j < 0) j = 0;
	if (j >= height) j = height - 1;

	int index = i + j * width;
	if (index < 0) index = 0;
	if (index >= ColorBuffer.Num()) index = ColorBuffer.Num();

	return ColorBuffer[index];

}
