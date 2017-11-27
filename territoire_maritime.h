#ifndef TERRITOIRE_MARITIME_H
#define TERRITOIRE_MARITIME_H

#include "fenetre_de_jeu.h"
#include "window.h"

class terrM
{
 private:
 	int m_hauteur, m_largeur, m_startX, m_startY;
 	Color m_colorWin, m_colorFrame;
  	fntJeu m_terr;
public:
	terrM(int h, int l, int x, int y);
	~terrM();

	WINDOW* getWindowWinTerr() const;
	Color getCouleurFenetreTerr() const;

	void setCouleurFenetreTerr(Color c);
	void setCouleurBordureTerr(Color c);
};
#endif
