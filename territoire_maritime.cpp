#include "territoire_maritime.h"

terrM::terrM(int h, int l, int x, int y)
: m_hauteur(h), m_largeur(l), m_startX(x), m_startY(y), m_terr(h,l,x,y) {
	m_colorWin = BBLUE;
	m_colorFrame = BRED;
	setCouleurBordureTerr(m_colorFrame);
	setCouleurFenetreTerr(m_colorWin);
}

terrM::~terrM(){}

WINDOW* terrM::getWindowWinTerr() const{
  return m_terr.getWindowWinFnt();
}

Color terrM::getCouleurFenetreTerr() const{
	return m_terr.getCouleurFenetreFnt();
}

void terrM::setCouleurFenetreTerr(Color c){
	m_terr.setCouleurFenetreFnt(c);
}

void terrM::setCouleurBordureTerr(Color c){
	m_terr.setCouleurBordureFnt(c);
}