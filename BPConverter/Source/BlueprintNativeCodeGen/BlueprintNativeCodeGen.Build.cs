// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BlueprintNativeCodeGen : ModuleRules
{
    public BlueprintNativeCodeGen(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
                "DesktopPlatform",
				"EditorFramework",
                "UnrealEd",
                "InputCore",
                "SlateCore",
                "Slate",
                "EditorStyle",
                "KismetCompiler",
                "Json",
                "JsonUtilities",
                "BlueprintCompilerCppBackend",
                "GameProjectGeneration",
                "Projects",
                "Kismet",
                "DesktopWidgets",
				"ToolMenus",
				"UMGEditor"
            }
		);

        DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"AssetRegistry",
			}
		);
	}
}
