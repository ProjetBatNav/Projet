#include "navire.h"

Navire::Navire(WINDOW* Win, int h, int l, int x, int y, Color c)
: m_hauteur(h), m_largeur(l), m_startX(x), m_startY(y), m_navColor(c) {
        char s = ' ';
	int i, j, X = x;

	for (i = 0; i < h ; ++i)
	{
		for (j = 0; j < l; ++j)
		{
		  print(Win,X,y,s,c);
		  X++;
		}
		X = x;
		y++;
	}
}

Navire::~Navire(){}

void Navire::print(WINDOW* Win, int x, int y, char s, Color c) const{
  wattron(Win,COLOR_PAIR(c));
  mvwaddch(Win,y,x,s);
  wattroff(Win,COLOR_PAIR(c));
  wrefresh(Win);
  refresh();
}

void Navire::printChanger(WINDOW* Win, int x, int y){
  m_startX = x;
  m_startY = y;
}
