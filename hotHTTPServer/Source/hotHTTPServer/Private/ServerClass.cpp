
#include "ServerClass.h"




void UServerClass::BeginHttpServer(int32 Port, FString route, UServerClass*& HttpServer)
{	

	static bool bExecuted = false;

	if (!bExecuted)
	{

		UE_LOG(LogTemp, Warning, TEXT("Server Listen......"));
		HttpServer = NewObject<UServerClass>();

		HttpCore* TempClass = new HttpCore;
		TempClass->StartServer(Port, TCHAR_TO_UTF8(*route));


		//将this传递到core类里
		TempClass->SetServerClass(HttpServer);

		bExecuted = true;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Do Onse"));
	}

	
}

//封装被调代理函数，
void UServerClass::BroadcastMessage(FString Msg)
{
	if (MyDelegateName.IsBound())
	{
		MyDelegateName.Broadcast(Msg);
	}
}

