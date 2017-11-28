#include "fntJcIA.h"

void jeuJcIA(std::string &mode){
	int ch;
	terrM joueur(20,40,10,7);
	terrM IA(20,40,111,7);
  fntJeu flotte(5,12,76,25);
	Menu titreJoueur(3,30,15,1,"Votre Territoire");
  Menu titreIA(3,30,116,1,"Territoire Adverse");
	Navire destroyer(flotte.getWindowWinFnt(),5,2,1,0,BMAGENTA);
  Navire croiseur(flotte.getWindowWinFnt(),4,2,3,0,BGREEN);
  Navire contreTorpilleur(flotte.getWindowWinFnt(),3,2,5,0,BYELLOW);
  Navire sousMarin(flotte.getWindowWinFnt(),3,2,7,0,BGREEN);
  Navire torpilleur(flotte.getWindowWinFnt(),2,2,9,0,BMAGENTA);

	while(((ch = getch()) != '\n'))
  {
    destroyer.mvNav(joueur.getWindowWinTerr(),ch,"10x10",joueur.getCouleurFenetreTerr());
  }
}
