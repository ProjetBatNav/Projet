#include "territoire_maritime.h"

terrM::terrM(int h, int l, int x, int y)
: m_hauteur(h), m_largeur(l), m_startX(x), m_startY(y), m_terr(h,l,x,y) {
	printGrille(getWindowWinTerr());
}

terrM::~terrM(){}

WINDOW* terrM::getWindowWinTerr() const{
  return m_terr.getWindowWinFnt();
}

Color terrM::getCouleurFenetreTerr() const{
	return m_terr.getCouleurFenetreFnt();
}

void terrM::print(WINDOW* Win, int x, int y, char s) const{
  mvwaddch(Win,y,x,s);
  wrefresh(Win);
  refresh();  
}

void terrM::printGrille(WINDOW* Win) const{
	int H = m_hauteur;
	int L = m_largeur;

	for (int i = 0; i < L; ++i)
	{
		if (i%2 == 0)
		{
			for (int j = 0; j < H; ++j)
			{
			print(Win,i,j,'|');
			}
		}
		else{
			for (int j = 0; j < H; ++j)
			{
			print(Win,i,j,'_');
			}
		}
		
	}
}

// void update() const{
// 	wrefresh(Win);
//   	refresh(); 
// }