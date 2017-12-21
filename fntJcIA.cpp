#include "fntJcIA.h"

void jeuJcIA(std::string &mode){
	int ch;
  Joueur J1("Guidyous");
	fntJeu joueur(20,40,10,7);
  joueur.setCouleurBordureFnt(WYELLOW);
  terrM terrJoueur(joueur.getWindowWinFnt());
	fntJeu IA(20,40,111,7);
  IA.setCouleurBordureFnt(WYELLOW);
  terrM terrIA(IA.getWindowWinFnt());
  fntJeu flotte(5,50,5,34);
	Menu titreJoueur(3,30,15,1,"Votre Territoire");
  Menu titreIA(3,30,116,1,"Territoire Adverse");

  Navire destroyer("destroyer",-2,0,BMAGENTA);
  Navire croiseur("croiseur",8,0,BGREEN);
  Navire contreTorpilleur("contreTorpilleur",18,0,BYELLOW);
  Navire sousMarin("sousMarin",28,0,BCYAN);
  Navire torpilleur("torpilleur",38,0,BWHITE);
  destroyer.print(flotte.getWindowWinFnt());
  croiseur.print(flotte.getWindowWinFnt());
  contreTorpilleur.print(flotte.getWindowWinFnt());
  sousMarin.print(flotte.getWindowWinFnt());
  torpilleur.print(flotte.getWindowWinFnt());
  
  Message Messombre(5,100,62,36);
  Messombre.setCouleurFenetre(WYELLOW);
  Message Mess(5,100,60,35);
  Mess.print(2,1,"Wallah j'incrément bro ! IIIIIIIIIIII IIIIIIIIII IIIIIIIIIIIIII IIIIIIIIIIIIIIIIIIIIII IIIIIIIIIIIIIIIIIIIIII IIIIIIIIJJJJJJJJJ IJIJIJIJIJIJIJIJIJIJIJIJ EXCELLENT");

	
  while(((ch = getch()) != '\n'))
  {
    // J1.mvNav(joueur.getWindowWinTerr(),destroyer,ch,"10x10",joueur.getCouleurFenetreTerr());
  }
}
