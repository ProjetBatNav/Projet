#include "fntJcIA.h"

void jeuJcIA(){
	int ch;
	terrM joueur(20,40,10,7);
	terrM IA(20,40,111,7);
	Menu titreJoueur(3,30,15,1,"Votre Territoire");
	Navire destroyer(joueur.getWindowWinTerr(),5,2,4,4,BMAGENTA);

	while(((ch = getch()) != '\n'))
  {
  	switch(ch){
  		case KEY_UP :
  			destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10",joueur.getCouleurFenetreTerr());
  			joueur.printGrille();
        destroyer.printNavVerti(joueur.getWindowWinTerr(),destroyer.getStartX(),destroyer.getStartY(),destroyer.getNavColor());
  		break;
  		case KEY_DOWN :
  			destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10",joueur.getCouleurFenetreTerr());
        joueur.update();
        // joueur.printGrille();
  		break;
  		case KEY_LEFT :
  			destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10",joueur.getCouleurFenetreTerr());
        joueur.update();
        // joueur.printGrille();
  		break;
  		case KEY_RIGHT :
  			destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10",joueur.getCouleurFenetreTerr());
        joueur.update();
        // joueur.printGrille();
  		break;
  		case 32 :
  			destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10",joueur.getCouleurFenetreTerr());
        joueur.update();
        // joueur.printGrille();
  		break;
  	}
  }
}
