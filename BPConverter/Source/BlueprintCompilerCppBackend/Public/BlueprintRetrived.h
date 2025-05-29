// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Misc/Guid.h"
#include "UObject/Class.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "EdGraph/EdGraphPin.h"
#include "Engine/BlueprintCore.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "UObject/SoftObjectPath.h"
#include "Blueprint/BlueprintSupport.h"

#include "BlueprintRetrived.generated.h"

USTRUCT()
struct FCompilerNativizationOptions
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName PlatformName;

	UPROPERTY()
	bool ServerOnlyPlatform;

	UPROPERTY()
	bool ClientOnlyPlatform;

	UPROPERTY()
	bool bExcludeMonolithicHeaders;

	UPROPERTY()
	TArray<FName> ExcludedModules;

	// Individually excluded assets
	UPROPERTY()
	TSet<FSoftObjectPath> ExcludedAssets;

	// Excluded folders. It excludes only BPGCs, enums and structures are still converted.
	UPROPERTY()
	TArray<FString> ExcludedFolderPaths;

	FCompilerNativizationOptions()
		: ServerOnlyPlatform(false)
		, ClientOnlyPlatform(false)
		, bExcludeMonolithicHeaders(false)
	{}
};