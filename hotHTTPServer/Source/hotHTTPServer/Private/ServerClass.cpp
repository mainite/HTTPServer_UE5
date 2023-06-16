
#include "ServerClass.h"




void UServerClass::BeginHttpServer(int32 Port, FString route, UServerClass*& HttpServer)
{	

	UE_LOG(LogTemp, Warning, TEXT("Server Listen......"));
 	HttpServer = NewObject<UServerClass>();



	static HttpCore* TempClass = nullptr;
	if (TempClass)
	{
		TempClass->StopServer();
		delete TempClass;
	}
	TempClass = new HttpCore;
	TempClass->StartServer(Port, "/test");
	

	//将this传递到core类里
	TempClass->SetServerClass(HttpServer);

	
}

//封装被调代理函数，
void UServerClass::BroadcastMessage(FString Msg)
{
	if (MyDelegateName.IsBound())
	{
		MyDelegateName.Broadcast(Msg);
	}
}

