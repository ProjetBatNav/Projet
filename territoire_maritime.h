#ifndef TERRITOIRE_MARITIME_H
#define TERRITOIRE_MARITIME_H

#include "fenetre_de_jeu.h"
#include "cellule.h"

class terrM
{
 private:
 	int m_startX, m_startY;
 	WINDOW* m_win;
 	Color m_colorTerrM;
  	Cellule T[20][20];
public:
	terrM(WINDOW* Win);
	~terrM();

	WINDOW* getWin() const;
	int getXAt(int i) const;
	int getYAt(int j) const;
	Color getCouleur() const;

	// void setCouleurFenetreTerr(Color c);
	void setCouleurAt(int i, int j, Color c);

	void print(WINDOW* Win) const;
};
#endif
