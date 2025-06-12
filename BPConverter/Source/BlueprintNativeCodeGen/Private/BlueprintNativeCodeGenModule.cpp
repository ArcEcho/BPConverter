// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintNativeCodeGenModule.h"
#include "BlueprintEditorModule.h"

#include "WorkflowOrientedApp/WorkflowTabManager.h"
#include "BlueprintEditor.h"
#include "Engine/Blueprint.h"
#include "ToolMenus.h"
#include "Widgets/Input/SButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "WidgetBlueprint.h"

#include "NativeCodeGenerationTool.h"

#define LOCTEXT_NAMESPACE "FBlueprintNativeCodeGenModule"

void FBlueprintNativeCodeGenModule::StartupModule()
{
	FBlueprintEditorModule& BlueprintEditorModule = FModuleManager::LoadModuleChecked<FBlueprintEditorModule>("Kismet");
	//BlueprintEditorModule.OnRegisterTabsForEditor().AddRaw(this, &FBlueprintNativeCodeGenModule::HandleRegisterTabsForBlueprintEditor);
	BlueprintEditorModule.OnGatherBlueprintMenuExtensions().AddRaw(this, &FBlueprintNativeCodeGenModule::HandleGatherBlueprintMenuExtensions);
}

void FBlueprintNativeCodeGenModule::ShutdownModule()
{
}

void FBlueprintNativeCodeGenModule::HandleGatherBlueprintMenuExtensions(TSharedPtr<FExtender> InExtender, UBlueprint* InBlueprintObj)
{
	UToolMenu* Menu = nullptr;
	UWidgetBlueprint* AsWidgetBlueprint = Cast<UWidgetBlueprint>(InBlueprintObj);

	// Determine the correct toolbar menu based on blueprint type
	if (AsWidgetBlueprint != nullptr)
	{
		//Menu = UToolMenus::Get()->FindMenu(TEXT("AssetEditor.WidgetBlueprintEditor.ToolBar.DesignerName"));
		Menu = UToolMenus::Get()->FindMenu(TEXT("AssetEditor.WidgetBlueprintEditor.ToolBar"));
	}
	else
	{
		//Menu = UToolMenus::Get()->FindMenu(TEXT("AssetEditor.BlueprintEditor.ToolBar.GraphName"));
		Menu = UToolMenus::Get()->FindMenu(TEXT("AssetEditor.BlueprintEditor.ToolBar"));
	}

	// Exit if the target menu is not found
	if (Menu == nullptr)
	{
		return;
	}

	// Add a new section or retrieve an existing one
	FToolMenuSection& Section = Menu->FindOrAddSection(NAME_None);

	// Add a toolbar button to the section
	Section.AddEntry(FToolMenuEntry::InitToolBarButton(
		"Style Button", // Unique name for the button entry
		FUIAction(
			FExecuteAction::CreateLambda([InBlueprintObj]()
				{
					// Action to execute when the button is clicked
					FNativeCodeGenerationTool::Open(*InBlueprintObj);
				}
			)
		),
		FText::FromString("ToCPP"),     // Button label
		FText::FromString("To CPP"),    // Tooltip text
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.GameSettings") // Button icon
	));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBlueprintNativeCodeGenModule, BlueprintNativeCodeGen)