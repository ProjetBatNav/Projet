#ifndef NAVIRE_H
#define NAVIRE_H

#include "window.h"

class Navire
{
private:
	int m_hauteur, m_largeur, m_startX, m_startY;
	Color m_navColor;

public:
	Navire(WINDOW* win, int h, int l, int x, int y, Color c);
	~Navire();

  	void print(WINDOW* Win, int x, int y, char s, Color c) const;
	void printChanger(WINDOW* Win, int x, int y) const;
	
};
#endif
