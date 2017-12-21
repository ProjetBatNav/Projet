#ifndef TERRITOIRE_MARITIME_H
#define TERRITOIRE_MARITIME_H

#include "fenetre_de_jeu.h"
#include "window.h"
#include "cellule.h"

class terrM
{
 private:
 	int m_startX, m_startY;
 	Color m_colorTerrM;
  	Cellule T[20][20];
public:
	terrM(WINDOW* Win);
	~terrM();

	// WINDOW* getWindowWinTerr() const;
	// Color getCouleurFenetreTerr() const;

	// void setCouleurFenetreTerr(Color c);
	// void setCouleurBordureTerr(Color c);

	void print(WINDOW* Win) const;
};
#endif
