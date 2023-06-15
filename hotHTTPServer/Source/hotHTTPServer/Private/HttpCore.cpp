
#include "HttpCore.h"
#include "ServerClass.h"


bool HttpCore::StartServer(uint32 port, FString path)
{
	uint32 HttpRouterPort = port;
	FString HttpPath = path;


	if (HttpRouterPort > 0 && port <= 80)
	{
		return false;
	}


	const FHttpPath HttpPathTemp(HttpPath);
	HttpRouter = FHttpServerModule::Get().GetHttpRouter(port);

	check(HttpRouter.IsValid())



	const FHttpRequestHandler RequestHandler = [this](const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete) {return OnRequestHandler(Request, OnComplete); };

	HttpRouteHandle = HttpRouter->BindRoute(HttpPath, EHttpServerRequestVerbs::VERB_POST, RequestHandler);



	if (!HttpRouteHandle.IsValid())
	{
		StopServer();
		return false;
	}


	FHttpServerModule::Get().StartAllListeners();
	return true;

}

void HttpCore::StopServer()
{
	if (HttpRouter.IsValid()) {
		HttpRouter->UnbindRoute(HttpRouteHandle);
	}
		HttpRouter.Reset();
 	
}

bool HttpCore::OnRequestHandler(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete)
{

	FString ReqBody = FString::Printf(TEXT("%s"), UTF8_TO_TCHAR(reinterpret_cast<const char*>(Request.Body.GetData())));


	SCPtr->BroadcastMessage(*ReqBody);

	GLog->Log(ReqBody);


   //回复消息
	auto MyTest = FHttpServerResponse::Create(FDateTime::Now().ToString(), "");
	OnComplete(MoveTemp(MyTest));


	return true;
}

