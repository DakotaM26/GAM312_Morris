// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "ResourceM.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingPart.h"
#include "PlayerWidget.h"
#include "PlayerChar.generated.h"

UCLASS()
class GAM312_MORRIS_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	    void MoveForward(float axisValue);

	UFUNCTION()
		void MoveRight(float axisValue);

	UFUNCTION()
	    void StartJump();

	UFUNCTION()
	    void StopJump();

	UFUNCTION()
	    void FindObject();
//Camera is set and function
	UPROPERTY(VisibleAnywhere)
	    UCameraComponent* PlayerCamComp;
//Identify player stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	    float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	    float Stamina = 100.0f;
    //Identify resources
	UPROPERTY(EditAnywhere, Category = "Resources")
	    int Wood;
	
	UPROPERTY(EditAnywhere, Category = "Resources")
	    int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources")
	    int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	    TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
	    TArray<FString> ResourcesNameArray;
	//Identify and create hit maker and hit decal
	UPROPERTY(EditAnywhere, Category = "HitMaker")
	    UMaterialInterface* hitDecal;

	//A Array will store the informantion on how many each buidling item.
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Building Supplies")
	    TArray<int> BuildingArray;
	//Bool determines if we are in the act of building.
    UPROPERTY()
	    bool isBuilding;
	//Tsubclass help select our childern when spawning.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	    TSubclassOf<ABuildingPart> BuildPartClass;
	//Individual class that set a variable to spawn of building parts.
	UPROPERTY()
	    ABuildingPart* spawnedPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	    UPlayerWidget* playerUI;

//Set player stats as functions
	UFUNCTION(BlueprintCallable)
	    void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
	    void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	UFUNCTION()
	    void DecreaseStats();

	UFUNCTION()
	    void GiveResource(float amount, FString resourceType);
	//Determine what object we will build.
	UFUNCTION(BlueprintCallable)
	    void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);
	//Allow player to spawn a building.
	UFUNCTION(BlueprintCallable)
	    void SpawnBuilding(int buildingID, bool& isSuccess);
	//Allow player to rotate/rotate building function.
	UFUNCTION()
	    void RotateBuilding();
};
