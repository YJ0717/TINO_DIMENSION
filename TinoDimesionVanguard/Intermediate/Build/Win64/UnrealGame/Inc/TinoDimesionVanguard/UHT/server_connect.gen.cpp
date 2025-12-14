// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "server_connect.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeserver_connect() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
TINODIMESIONVANGUARD_API UClass* Z_Construct_UClass_Userver_connect();
TINODIMESIONVANGUARD_API UClass* Z_Construct_UClass_Userver_connect_NoRegister();
UPackage* Z_Construct_UPackage__Script_TinoDimesionVanguard();
// ********** End Cross Module References **********************************************************

// ********** Begin Class Userver_connect **********************************************************
void Userver_connect::StaticRegisterNativesUserver_connect()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_Userver_connect;
UClass* Userver_connect::GetPrivateStaticClass()
{
	using TClass = Userver_connect;
	if (!Z_Registration_Info_UClass_Userver_connect.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("server_connect"),
			Z_Registration_Info_UClass_Userver_connect.InnerSingleton,
			StaticRegisterNativesUserver_connect,
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
	return Z_Registration_Info_UClass_Userver_connect.InnerSingleton;
}
UClass* Z_Construct_UClass_Userver_connect_NoRegister()
{
	return Userver_connect::GetPrivateStaticClass();
}
struct Z_Construct_UClass_Userver_connect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "server_connect.h" },
		{ "ModuleRelativePath", "Public/server_connect.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Userver_connect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_Userver_connect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_TinoDimesionVanguard,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Userver_connect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_Userver_connect_Statics::ClassParams = {
	&Userver_connect::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Userver_connect_Statics::Class_MetaDataParams), Z_Construct_UClass_Userver_connect_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_Userver_connect()
{
	if (!Z_Registration_Info_UClass_Userver_connect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Userver_connect.OuterSingleton, Z_Construct_UClass_Userver_connect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_Userver_connect.OuterSingleton;
}
Userver_connect::Userver_connect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(Userver_connect);
Userver_connect::~Userver_connect() {}
// ********** End Class Userver_connect ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_Public_server_connect_h__Script_TinoDimesionVanguard_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_Userver_connect, Userver_connect::StaticClass, TEXT("Userver_connect"), &Z_Registration_Info_UClass_Userver_connect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Userver_connect), 1749476073U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_Public_server_connect_h__Script_TinoDimesionVanguard_2586995184(TEXT("/Script/TinoDimesionVanguard"),
	Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_Public_server_connect_h__Script_TinoDimesionVanguard_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Admin_Desktop_TINO_DIMENSION_TinoDimesionVanguard_Source_TinoDimesionVanguard_Public_server_connect_h__Script_TinoDimesionVanguard_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
