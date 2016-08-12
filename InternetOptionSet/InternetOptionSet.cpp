
#include "InternetOptionSet.h"

#include <stdio.h> 
#include <windows.h> 
#include <wininet.h>
#include <atlbase.h>



CInternetOptionSet::CInternetOptionSet()
{}


CInternetOptionSet::~CInternetOptionSet()
{}


bool CInternetOptionSet::setProxy(char* proxyBuff)
{
	USES_CONVERSION;
	if (NULL == proxyBuff)
	{
		return false;
	}
    // To include server for FTP, HTTPS, and so on, use the string
    // (ftp=http://<ProxyServerName>:80; https=https://<ProxyServerName>:80) 
    INTERNET_PER_CONN_OPTION_LIST    List; 
    INTERNET_PER_CONN_OPTION         Option[3]; 
    unsigned long                    nSize = sizeof(INTERNET_PER_CONN_OPTION_LIST); 


    Option[0].dwOption = INTERNET_PER_CONN_PROXY_SERVER; 
	Option[0].Value.pszValue = A2W(proxyBuff);

    Option[1].dwOption = INTERNET_PER_CONN_FLAGS; 
    Option[1].Value.dwValue = PROXY_TYPE_DIRECT ; 

//	unsigned int iLenBuff = _tclen(proxyBuff);
	if (0 != strcmp(proxyBuff, ""))
		Option[1].Value.dwValue |= PROXY_TYPE_PROXY;
    // This option sets all the possible connection types for the client. 
    // This case specifies that the proxy can be used or direct connection is possible.

    Option[2].dwOption = INTERNET_PER_CONN_PROXY_BYPASS; 
    Option[2].Value.pszValue = _T("<local>"); 

    List.dwSize = sizeof(INTERNET_PER_CONN_OPTION_LIST); 
    List.pszConnection = NULL; 
    List.dwOptionCount = 3; 
    List.dwOptionError = 0; 
    List.pOptions = Option; 

    if(!InternetSetOption(NULL, INTERNET_OPTION_PER_CONNECTION_OPTION, &List, nSize))
	{
		printf("InternetSetOption failed! (%d)\n", GetLastError()); 
		return false;
	}

	if (!InternetSetOption(NULL, INTERNET_OPTION_SETTINGS_CHANGED, NULL, NULL))
	{
		printf("InternetSetOption failed! (%d)\n", GetLastError()); 
		return false;
	}

    if (!InternetSetOption(NULL, INTERNET_OPTION_REFRESH, NULL, NULL))
	{
		printf("InternetSetOption failed! (%d)\n", GetLastError());
		return false;
	}		
	//The connection settings for other instances of Internet Explorer. 

    return true;
}


