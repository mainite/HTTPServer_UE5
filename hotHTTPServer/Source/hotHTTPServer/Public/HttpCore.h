// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <HTTPServer/Public/IHttpRouter.h>
#include <HTTPServer/Public/HttpRouteHandle.h>
#include <HTTPServer/Public/HttpServerModule.h>
#include "ServerClass.h"

/**
 * 
 */



class HttpCore
{
public:
	/**
	* 开始服务
	*/
	bool StartServer(uint32 port, FString path);

	/**
	* 停止服务
	*/
	void StopServer();



public:

	class UServerClass* SCPtr = NewObject<UServerClass>();
	void SetServerClass(UServerClass* ucPtr) { SCPtr = ucPtr; };


private:

	bool OnRequestHandler(const  FHttpServerRequest& Request, const FHttpResultCallback& OnComplete);


	TSharedPtr<IHttpRouter> HttpRouter;
	FHttpRouteHandle HttpRouteHandle;




};
