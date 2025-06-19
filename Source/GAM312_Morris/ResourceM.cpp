// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceM.h"

// Sets default values
AResourceM::AResourceM()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ResourceNameTxt = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Render"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = Mesh;

	ResourceNameTxt->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void AResourceM::BeginPlay()
{
	Super::BeginPlay();

	tempText = tempText.FromString(resourceName);

	ResourceNameTxt->SetText(tempText);
}

// Called every frame
void AResourceM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

