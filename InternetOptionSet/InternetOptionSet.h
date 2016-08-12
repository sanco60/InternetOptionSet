#pragma once

#ifdef INTERNETOPTIONSET_EXPORTS
#define INTERNETOPTIONSET_PUBLIC __declspec(dllexport)
#else
#define INTERNETOPTIONSET_PUBLIC __declspec(dllimport)
#endif

class INTERNETOPTIONSET_PUBLIC CInternetOptionSet
{
public:
	CInternetOptionSet();

	~CInternetOptionSet();

	bool setProxy(char* proxyBuff);
};

