#include <iostream>
#include "Gra.h"
#include <thread>

#define _CRTDBG_MAP_ALLOC	//Do 
#include <stdlib.h>			//wycieku 
#include <crtdbg.h>			//pamiêci

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Do wycieku pamiêci
	srand( time(NULL) );
	Gra gierka;
	gierka.Menu();
	return 0;
}