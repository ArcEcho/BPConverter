//
//#pragma once
//
//#include "CoreMinimal.h"
///**
//* Dynamic class (can be constructed after initial startup)
//*/
//class UDynamicClass : public UClass
//{
//	DECLARE_CASTED_CLASS_INTRINSIC_NO_CTOR(UDynamicClass, UClass, 0, TEXT("/Script/CoreUObject"), CASTCLASS_None, NO_API)
//	DECLARE_WITHIN_UPACKAGE()
//
//public:
//	typedef void (*ClassAddReferencedObjectsType)	(UObject*, class FReferenceCollector&);
//	typedef void (*DynamicClassInitializerType)	(UDynamicClass*);
//
//	UDynamicClass(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
//	explicit UDynamicClass(const FObjectInitializer& ObjectInitializer, UClass* InSuperClass);
//	UDynamicClass(EStaticConstructor, FName InName, uint32 InSize, uint32 InAlignment, EClassFlags InClassFlags, EClassCastFlags InClassCastFlags,
//		const TCHAR* InClassConfigName, EObjectFlags InFlags, ClassConstructorType InClassConstructor,
//		ClassVTableHelperCtorCallerType InClassVTableHelperCtorCaller,
//		ClassAddReferencedObjectsType InClassAddReferencedObjects,
//		DynamicClassInitializerType InDynamicClassInitializer);
//
//	// UObject interface.
//	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);
//
//	// UClass interface
//	virtual UObject* CreateDefaultObject();
//	virtual void PurgeClass(bool bRecompilingOnLoad) override;
//	virtual UObject* FindArchetype(const UClass* ArchetypeClass, const FName ArchetypeName) const override;
//	virtual void SetupObjectInitializer(FObjectInitializer& ObjectInitializer) const override;
//
//	/** Find a struct property, called from generated code */
//	FStructProperty* FindStructPropertyChecked(const TCHAR* PropertyName) const;
//
//	/** Misc objects owned by the class. */
//	TArray<UObject*> MiscConvertedSubobjects;
//
//	/** Additional converted fields, that are used by the class. */
//	TArray<UField*> ReferencedConvertedFields;
//
//	/** Outer assets used by the class */
//	TArray<UObject*> UsedAssets;
//
//	/** Specialized sub-object containers */
//	TArray<UObject*> DynamicBindingObjects;
//	TArray<UObject*> ComponentTemplates;
//	TArray<UObject*> Timelines;
//
//	/** Array of blueprint overrides of component classes in parent classes */
//	TArray<TPair<FName, UClass*>> ComponentClassOverrides;
//
//	/** IAnimClassInterface (UAnimClassData) or null */
//	UObject* AnimClassImplementation;
//
//	DynamicClassInitializerType DynamicClassInitializer;
//
//	/** Prefix for the temporary package where the dynamic classes are stored when being generated */
//	static const FString& GetTempPackagePrefix();
//};
