#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "utility.h"
#include "request.h"


#define UNIT "REQUEST"


httpRequest *newRequestObject(httpReqMethod method,char* uri,char*httpversion)
{
	httpRequest *request = malloc(sizeof(httpRequest));

	if(!request)
		RAmsg(request);

	request->method = malloc(sizeof(httpReqMethod));
	request->uri = malloc((strlen(uri)+1) * sizeof(char));
	request->httpversion = malloc((strlen(httpversion)+1) * sizeof(char));
	
	if(!request->method)
		RAmsg(request->method);
	
	if(!request->httpversion)
		RAmsg(request->httpversion);

	if(!request->uri)
		RAmsg(request->uri);

	
	return request;
}


void *freeRequestObject(httpRequest* request)
{
	delete(request,method);	
	delete(request,uri);
	delete(request,httpversion);
	delete(request,accept);
	delete(request,acceptCharset);
	delete(request,acceptEncoding);
	delete(request,acceptLanguage);
	delete(request,authorization);
	delete(request,except);
	delete(request,from);
	delete(request,host);
	delete(request,cookie);
	delete(request,ifNoneMatch);
	delete(request,ifMatch);
	delete(request,ifRange);
	delete(request,ifUnmodifiedSince);
	delete(request,maxForwards);
	delete(request,proxyAuthorization);
	delete(request,range);
	delete(request,referer);
	delete(request,te);
	delete(request,userAgent);	

	delete(request,connection);
	delete(request,cacheControl);
	delete(request,date);
	delete(request,pragma);
	delete(request,upgrade);
	delete(request,trailer);
	delete(request,transferEncoding);
	delete(request,via);
	delete(request,warning);
	
	
	delete(request,contentEncoding);
	delete(request,contentLanguage);
	delete(request,contentLength);
	delete(request,contentLocation);
	delete(request,contentMd5);
	delete(request,contentRange);
	delete(request,contentType);
	delete(request,expires);
	delete(request,lastModified);

	delete(request,body);
		
	free(request);

	return NULL;
}


