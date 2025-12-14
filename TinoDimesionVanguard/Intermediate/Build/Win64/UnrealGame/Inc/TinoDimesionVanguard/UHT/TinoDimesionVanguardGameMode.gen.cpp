// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TinoDimesionVanguard/TinoDimesionVanguardGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeTinoDimesionVanguardGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
TINODIMESIONVANGUARD_API UClass* Z_Construct_UClass_ATinoDimesionVanguardGameMode();
TINODIMESIONVANGUARD_API UClass* Z_Construct_UClass_ATinoDimesionVanguardGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_TinoDimesionVanguard();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ATinoDimesionVanguardGameMode ********************************************
void ATinoDimesionVanguardGameMode::StaticRegisterNativesATinoDimesionVanguardGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode;
UClass* ATinoDimesionVanguardGameMode::GetPrivateStaticClass()
{
	using TClass = ATinoDimesionVanguardGameMode;
	if (!Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("TinoDimesionVanguardGameMode"),
			Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode.InnerSingleton,
			StaticRegisterNativesATinoDimesionVanguardGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ATinoDimesionVanguardGameMode_NoRegister()
{
	return ATinoDimesionVanguardGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TinoDimesionVanguardGameMode.h" },
		{ "ModuleRelativePath", "TinoDimesionVanguardGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATinoDimesionVanguardGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_TinoDimesionVanguard,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics::ClassParams = {
	&ATinoDimesionVanguardGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008803ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATinoDimesionVanguardGameMode()
{
	if (!Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode.OuterSingleton, Z_Construct_UClass_ATinoDimesionVanguardGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATinoDimesionVanguardGameMode);
ATinoDimesionVanguardGameMode::~ATinoDimesionVanguardGameMode() {}
// ********** End Class ATinoDimesionVanguardGameMode **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_TinoDimesionVanguardGameMode_h__Script_TinoDimesionVanguard_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATinoDimesionVanguardGameMode, ATinoDimesionVanguardGameMode::StaticClass, TEXT("ATinoDimesionVanguardGameMode"), &Z_Registration_Info_UClass_ATinoDimesionVanguardGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATinoDimesionVanguardGameMode), 2580191860U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_TinoDimesionVanguardGameMode_h__Script_TinoDimesionVanguard_3231620880(TEXT("/Script/TinoDimesionVanguard"),
	Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_TinoDimesionVanguardGameMode_h__Script_TinoDimesionVanguard_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_TinoDimesionVanguardGameMode_h__Script_TinoDimesionVanguard_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
