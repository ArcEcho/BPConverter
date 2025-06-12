// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FWorkflowAllowedTabSet;
class FBlueprintEditor;

class FBlueprintNativeCodeGenModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void HandleGatherBlueprintMenuExtensions(TSharedPtr<FExtender> InExtender, UBlueprint* InBlueprintObj);
};
