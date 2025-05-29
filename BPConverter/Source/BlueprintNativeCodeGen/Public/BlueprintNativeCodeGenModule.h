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
	void ExtendBlueprintEditor();

	void OnModulesChanged(FName ModuleName, EModuleChangeReason Reason);

	TSharedPtr<FExtender> BlueprintToolbarExtender;
	FDelegateHandle BlueprintExtenderHandle;

	void HandleRegisterTabsForBlueprintEditor(FWorkflowAllowedTabSet& TabFactories, FName InModeName, TSharedPtr<FBlueprintEditor> BlueprintEditor);
};
