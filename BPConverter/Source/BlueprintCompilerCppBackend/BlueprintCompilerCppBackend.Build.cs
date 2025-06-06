// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class BlueprintCompilerCppBackend : ModuleRules
	{
		public BlueprintCompilerCppBackend(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"EditorFramework",
					"Engine",
					"KismetCompiler",
					"UnrealEd",
					"BlueprintGraph",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"UMG",
					"SlateCore",
					"MovieScene",
				}
			);
		}
	}
}
