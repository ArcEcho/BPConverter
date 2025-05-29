//#include "DynamicClass.h"
//
//#include "UObject/ObjectMacros.h"
//
///*-----------------------------------------------------------------------------
//UDynamicClass constructors.
//-----------------------------------------------------------------------------*/
//
///**
//* Internal constructor.
//*/
//UDynamicClass::UDynamicClass(const FObjectInitializer& ObjectInitializer)
//: UClass(ObjectInitializer)
//, AnimClassImplementation(nullptr)
//{
//	// If you add properties here, please update the other constructors and PurgeClass()
//}
//
///**
//* Create a new UDynamicClass given its superclass.
//*/
//UDynamicClass::UDynamicClass(const FObjectInitializer& ObjectInitializer, UClass* InBaseClass)
//: UClass(ObjectInitializer, InBaseClass)
//, AnimClassImplementation(nullptr)
//{
//}
//
///**
//* Called when dynamically linked.
//*/
//UDynamicClass::UDynamicClass(
//	EStaticConstructor,
//	FName			InName,
//	uint32			InSize,
//	uint32			InAlignment,
//	EClassFlags		InClassFlags,
//	EClassCastFlags	InClassCastFlags,
//	const TCHAR*    InConfigName,
//	EObjectFlags	InFlags,
//	ClassConstructorType InClassConstructor,
//	ClassVTableHelperCtorCallerType InClassVTableHelperCtorCaller,
//	DynamicClassInitializerType InDynamicClassInitializer)
//: UClass(
//  EC_StaticConstructor
//, InName
//, InSize
//, InAlignment
//, InClassFlags
//, InClassCastFlags
//, InConfigName
//, InFlags
//, InClassConstructor
//, InClassVTableHelperCtorCaller
//, InClassAddReferencedObjects)
//, AnimClassImplementation(nullptr)
//, DynamicClassInitializer(InDynamicClassInitializer)
//{
//}
//
//void UDynamicClass::AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector)
//{
//	UDynamicClass* This = CastChecked<UDynamicClass>(InThis);
//
//	Collector.AddReferencedObjects(This->MiscConvertedSubobjects, This);
//	Collector.AddReferencedObjects(This->ReferencedConvertedFields, This);
//	Collector.AddReferencedObjects(This->UsedAssets, This);
//	Collector.AddReferencedObjects(This->DynamicBindingObjects, This);
//	Collector.AddReferencedObjects(This->ComponentTemplates, This);
//	Collector.AddReferencedObjects(This->Timelines, This);
//
//	for (TPair<FName, UClass*>& Override : This->ComponentClassOverrides)
//	{
//		Collector.AddReferencedObject(Override.Value);
//	}
//
//	Collector.AddReferencedObject(This->AnimClassImplementation, This);
//
//	Super::AddReferencedObjects(This, Collector);
//}
//
//UObject* UDynamicClass::CreateDefaultObject()
//{
//#if DO_CHECK
//	if (!HasAnyFlags(RF_ClassDefaultObject) && (0 == (ClassFlags & CLASS_Constructed)))
//	{
//		UE_LOG(LogClass, Error, TEXT("CDO is created for a dynamic class, before the class was constructed. %s"), *GetPathName());
//	}
//#endif
//	return Super::CreateDefaultObject();
//}
//
//void UDynamicClass::PurgeClass(bool bRecompilingOnLoad)
//{
//	Super::PurgeClass(bRecompilingOnLoad);
//
//	MiscConvertedSubobjects.Empty();
//	ReferencedConvertedFields.Empty();
//	UsedAssets.Empty();
//
//	DynamicBindingObjects.Empty();
//	ComponentTemplates.Empty();
//	Timelines.Empty();
//	ComponentClassOverrides.Empty();
//
//	AnimClassImplementation = nullptr;
//}
//
//UObject* UDynamicClass::FindArchetype(const UClass* ArchetypeClass, const FName ArchetypeName) const
//{
//	UObject* Archetype = static_cast<UObject*>(FindObjectWithOuter(this, ArchetypeClass, ArchetypeName));
//	if (!Archetype)
//	{
//		// See UBlueprintGeneratedClass::FindArchetype, UE-35259, UE-37480
//		const FName ArchetypeBaseName = FName(ArchetypeName, 0);
//		if (ArchetypeBaseName != ArchetypeName)
//		{
//			UObject* const* FountComponentTemplate = ComponentTemplates.FindByPredicate([&](UObject* InObj) -> bool
//			{ 
//				return InObj && (InObj->GetFName() == ArchetypeBaseName) && InObj->IsA(ArchetypeClass);
//			});
//			Archetype = FountComponentTemplate ? *FountComponentTemplate : nullptr;
//		}
//	}
//	const UClass* SuperClass = GetSuperClass();
//	return Archetype ? Archetype :
//		(SuperClass ? SuperClass->FindArchetype(ArchetypeClass, ArchetypeName) : nullptr);
//}
//
//void UDynamicClass::SetupObjectInitializer(FObjectInitializer& ObjectInitializer) const
//{
//	for (const TPair<FName, UClass*>& Override : ComponentClassOverrides)
//	{
//		ObjectInitializer.SetDefaultSubobjectClass(Override.Key, Override.Value);
//	}
//
//	GetSuperClass()->SetupObjectInitializer(ObjectInitializer);
//}
//
//
//FStructProperty* UDynamicClass::FindStructPropertyChecked(const TCHAR* PropertyName) const
//{
//	return FindFieldChecked<FStructProperty>(this, PropertyName);
//}
//
//const FString& UDynamicClass::GetTempPackagePrefix()
//{
//	static const FString PackagePrefix(TEXT("/Temp/__TEMP_BP__"));
//	return PackagePrefix;
//}
//
//IMPLEMENT_CORE_INTRINSIC_CLASS(UDynamicClass, UClass,
//{
//	Class->ClassAddReferencedObjects = &UDynamicClass::AddReferencedObjects;
//}