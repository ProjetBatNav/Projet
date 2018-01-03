#include "window.h"
#include "choixOptions.h"
#include "menuprinc.h"
#include <cstdlib>


int main(int argc, char const **argv)
{
	if (argc == 2)
		choixOptions(argc, argv);
	else {
	system("resize -s 55 165");
	startProgramX();
	menuPrinc();
	stopProgramX();
	return 0;
}
}