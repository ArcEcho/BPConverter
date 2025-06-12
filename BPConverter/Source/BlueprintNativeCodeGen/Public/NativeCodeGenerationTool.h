// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UBlueprint;

//////////////////////////////////////////////////////////////////////////
// FNativeCodeGenerationTool

struct FNativeCodeGenerationTool
{
	BLUEPRINTNATIVECODEGEN_API static void Open(UBlueprint& Object);
	BLUEPRINTNATIVECODEGEN_API static bool CanGenerate(const UBlueprint& Object);
};
