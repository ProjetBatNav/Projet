#ifndef NAVIRE_H
#define NAVIRE_H

#include "window.h"

class Navire
{
private:
	int m_hauteur, m_largeur, m_startX, m_startY;
	char m_spr;
	Color m_navColor;

public:
	Navire(WINDOW* Win, int h, int l, int x, int y, Color c);
	~Navire();

	int getStartX() const;
	int getStartY() const;
	Color getNavColor() const;

  	void print(WINDOW* Win, int x, int y, Color c) const;
  	void print(WINDOW* Win, int x, int y, char s) const;
  	void printNav(WINDOW* Win, int x, int y, Color c) const;
  	void printNavGrille(WINDOW* Win, int x, int y) const;
  	void mvNav(WINDOW* Win, int ch, std::string mode);
};
#endif
