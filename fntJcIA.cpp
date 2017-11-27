#include "fntJcIA.h"

void jeuJcIA(){
	int ch;
	terrM joueur(20,61,10,7,"10x10");
	terrM IA(20,40,111,7);
	Menu titreJoueur(3,30,15,1,"Votre Territoire");
	Navire destroyer(joueur.getWindowWinTerr(),5,2,1,0,BMAGENTA);

	while(((ch = getch()) != '\n'))
  {
    destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10");
  }
}
