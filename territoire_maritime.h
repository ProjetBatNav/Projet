#ifndef TERRITOIRE_MARITIME_H
#define TERRITOIRE_MARITIME_H

#include "fenetre_de_jeu.h"
#include "window.h"

class terrM
{
 private:
 	int m_hauteur, m_largeur, m_startX, m_startY;
 	std::string m_mode;
  	fntJeu m_terr;
public:
	terrM(int h, int l, int x, int y, std::string mode = "10x10");
	~terrM();

	WINDOW* getWindowWinTerr() const;
	Color getCouleurFenetreTerr() const;

	void print(WINDOW* Win, int x, int y, char s) const;
	void printGrille(std::string mode) const;

	void update() const;
};
#endif
