#include "fenetre_de_jeu.h"

fntJeu::fntJeu(int h, int w, int x, int y)
: m_fnt(h,w,x,y){}

fntJeu::~fntJeu(){}

int fntJeu::getStartX(){
	return m_fnt.getX();
}
int fntJeu::getStartY(){
	return m_fnt.getY();
}
int fntJeu::getHauteur(){
	return m_fnt.getHauteur();
}
int fntJeu::getLargeur(){
	return m_fnt.getLargeur();
}

WINDOW* fntJeu::getWindowWinFnt() const{
  return m_fnt.getWindowWin();
}

Color fntJeu::getCouleurFenetreFnt() const{
	return m_fnt.getCouleurFenetre();
}

void fntJeu::setCouleurFenetreFnt(Color c){
	m_fnt.setCouleurFenetre(c);
}

void fntJeu::setCouleurBordureFnt(Color c){
	m_fnt.setCouleurBordure(c);
}