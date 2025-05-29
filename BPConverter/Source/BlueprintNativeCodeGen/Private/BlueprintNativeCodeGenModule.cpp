// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintNativeCodeGenModule.h"
#include "BlueprintEditorModule.h"

#include "WorkflowOrientedApp/WorkflowTabManager.h"
#include "BlueprintEditor.h"
#include "Engine/Blueprint.h"
#include "ToolMenus.h"
#include "Widgets/Input/SButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "NativeCodeGenerationTool.h"

#define LOCTEXT_NAMESPACE "FBlueprintNativeCodeGenModule"

void FBlueprintNativeCodeGenModule::StartupModule()
{
	FBlueprintEditorModule& BlueprintEditorModule = FModuleManager::LoadModuleChecked<FBlueprintEditorModule>("Kismet");
	BlueprintEditorModule.OnRegisterTabsForEditor().AddRaw(this, &FBlueprintNativeCodeGenModule::HandleRegisterTabsForBlueprintEditor);
}

void FBlueprintNativeCodeGenModule::ShutdownModule()
{

}

void FBlueprintNativeCodeGenModule::ExtendBlueprintEditor()
{

}

void FBlueprintNativeCodeGenModule::OnModulesChanged(FName ModuleName, EModuleChangeReason Reason)
{

}

void FBlueprintNativeCodeGenModule::HandleRegisterTabsForBlueprintEditor(FWorkflowAllowedTabSet& TabFactories, FName InModeName, TSharedPtr<FBlueprintEditor> BlueprintEditor)
{
	BlueprintToolbarExtender = MakeShareable(new FExtender());
	BlueprintToolbarExtender->AddToolBarExtension(
		"Compile", 
		EExtensionHook::After,
		nullptr,
		FToolBarExtensionDelegate::CreateLambda(
			[BlueprintEditor](FToolBarBuilder& ToolbarBuilder)
			{
				ToolbarBuilder.AddToolBarButton(
					FUIAction(
						FExecuteAction::CreateLambda([BlueprintEditor]()
							{
								if (BlueprintEditor.IsValid())
								{
									UBlueprint* BlueprintObject = BlueprintEditor->GetBlueprintObj();
									FString BlueprintName;
									BlueprintObject->GetName(BlueprintName);

									FNativeCodeGenerationTool::Open(*BlueprintObject, BlueprintEditor.ToSharedRef());
								}
							}
						)
					),
					NAME_None,
					LOCTEXT("MyButton_Label", "ToCPP"),
					LOCTEXT("MyButton_ToolTip", "To CPP"),
					FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.GameSettings")
				);
			})
	);

	BlueprintEditor->AddToolbarExtender(BlueprintToolbarExtender);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBlueprintNativeCodeGenModule, BlueprintNativeCodeGen)