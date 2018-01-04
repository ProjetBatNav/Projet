#include "fntJcIA.h"

void jeuJcIA(std::string &mode){
	int ch;
	fntJeu joueur(20,40,10,7);
  joueur.setCouleurBordureFnt(WGREEN);
  terrM terrJoueur(joueur.getWindowWinFnt());
	fntJeu IA(20,40,111,7);
  IA.setCouleurBordureFnt(WYELLOW);
  terrM terrIA(IA.getWindowWinFnt());
  fntJeu flotte(5,50,5,34);
  flotte.setCouleurFenetreFnt(WBLUE);
  flotte.setCouleurBordureFnt(WGREEN);
	Menu titreJoueur(3,30,15,1,"Votre Territoire");
  Menu titreIA(3,30,116,1,"Territoire Adverse");

  IA IA(terrIA);
  Joueur J1("Guidyous",flotte.getWindowWinFnt());

  Message Messombre(5,100,62,36);
  Messombre.setCouleurFenetre(WYELLOW);
  Message Mess(5,100,60,35);
  Mess.print(2,1,"Wallah j'incrément bro ! IIIIIIIIIIII IIIIIIIIII IIIIIIIIIIIIII IIIIIIIIIIIIIIIIIIIIII IIIIIIIIIIIIIIIIIIIIII IIIIIIIIJJJJJJJJJ IJIJIJIJIJIJIJIJIJIJIJIJ EXCELLENT");

	

  J1.selectNav(terrJoueur);
  while((ch = getch()) != '\n')
  {
  }
}
