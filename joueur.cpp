#include "joueur.h"

Joueur::Joueur(std::string pseudo, int defaut)
: m_pseudo(pseudo), m_defaut(defaut){
	T[0].setNom("destroyer");
	T[1].setNom("croiseur");
	T[2].setNom("contreTorpilleur");
	T[3].setNom("sousMarin");
	T[4].setNom("torpilleur");
	
	if(defaut){
		for (int i = 0; i < 5; ++i)
		{
			T[i].defautNavire();
		}
	}
}

Joueur::~Joueur(){}

std::string Joueur::getPseudo(){
	return m_pseudo;
}

// void Joueur::mvNav(WINDOW* Win, Navire &nom, int ch, std::string mode, Color c){
// 	switch(ch){
// 		case KEY_UP :
// 			if(mode == "10x10"){
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartY(nom.getStartY()-1);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 			else
// 			{
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartY(nom.getStartY()-2);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 		break;
// 		case KEY_DOWN :
// 			if(mode == "10x10"){
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartY(nom.getStartY()+1);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 			else
// 			{
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartY(nom.getStartY()+2);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 		break;
// 		case KEY_LEFT :
// 			if(mode == "10x10"){
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartX(nom.getStartX()-2);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 			else
// 			{
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartX(nom.getStartX()-4);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 		break;
// 		case KEY_RIGHT :
// 			if(mode == "10x10"){
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartX(nom.getStartX()+2);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 			else
// 			{
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				nom.setStartX(nom.getStartX()+4);
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 		break;
// 		case 32 :
// 			if(nom.getLargeur() > nom.getHauteur()){
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				int largeur = nom.getLargeur();
// 				nom.setLargeur(2*nom.getHauteur());
// 				nom.setHauteur(largeur/2);
// 				nom.setStartX(nom.getStartX()+(nom.getHauteur()/2*2));
// 				nom.setStartY(nom.getStartY()-(nom.getHauteur()/2));
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());		
// 			}
// 			else{
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),c);
// 				int largeur = nom.getLargeur(), hauteur = nom.getHauteur();
// 				nom.setLargeur(2*nom.getHauteur());
// 				nom.setHauteur(largeur/2);
// 				nom.setStartX(nom.getStartX()-(hauteur/2*2));
// 				nom.setStartY(nom.getStartY()+(hauteur/2));
// 				nom.printNav(Win,nom.getStartX(),nom.getStartY(),nom.getNavColor());
// 			}
// 		break;
// 	}
	
// }

// void Joueur::selectNav(int ch){
// 	int i = 0;
// 	while(ch != '\n'){
// 		while(ch != KEY_RIGHT || ch != KEY_LEFT){
// 		T[i].setNavColor(BWHITE);
// 		sleep(1);
// 		T[i].setNavColor(T[i].getNavColor());
// 		}
// 		switch(ch){
// 			case KEY_RIGHT :
// 				sleep(1);
// 		}
// 	}
// }

// bool appartientFntJeu(fntJeu flotte, Navire nom){
// 	return nom.getStartX() >= flotte.getStartX() && nom.getStartY() >= flotte
// }