// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpCore.h"
#include "ServerClass.generated.h"

/**
 * 
 */


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMyDelegate, FString, Str);

UCLASS()
class HOTHTTPSERVER_API UServerClass : public UObject
{
	GENERATED_BODY()


public:

	/**
	*声明一个带参数的代理
	**/
	UPROPERTY(BlueprintAssignable)
	FMyDelegate  MyDelegateName;

	 UFUNCTION(BlueprintCallable,meta=(Port = 1234,route = "/test"))
	 static void BeginHttpServer(int32 Port,FString route, UServerClass*& HttpServer);

 	 void BroadcastMessage(FString Msg);

	// bool SetMsg(FString msg) { Msg = msg; return true; };

private:

	//FString Msg;
		
	
};
