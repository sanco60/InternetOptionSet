#include <stdio.h>
#include <string>

#include "InternetOptionSet.h"


int main(int argc, char* argv[])
{
	int err = 0;

	while(1)
	{
		if (argc < 3)
		{
			err = -1;
			break;
		}

		CInternetOptionSet inetSet;

		if (0 == strcmp("0", argv[1]))
		{
			inetSet.setProxy("");
		} else 
		{
			char buff[1024] = {0};
			sprintf(buff, "%s:%s", argv[1], argv[2]);
			inetSet.setProxy(buff);
		}	
		
		//must break here
		break;
	}
	
	return err;
}

