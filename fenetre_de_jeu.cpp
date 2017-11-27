#include "fenetre_de_jeu.h"

fntJeu::fntJeu(int h, int w, int x, int y)
: m_fnt(h,w,x,y){}

fntJeu::~fntJeu(){}

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