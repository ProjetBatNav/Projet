#include "territoire_maritime.h"

terrM::terrM(int h, int l, int x, int y, std::string mode)
: m_hauteur(h), m_largeur(l), m_startX(x), m_startY(y), m_mode(mode), m_terr(h,l,x,y) {
	printGrille(mode);
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

void terrM::printGrille(std::string mode) const{
	if (mode == "10x10")
	{
		for (int i = 0; i < m_largeur; ++i)
		{
			if (i%3 == 0)
			{
				for (int j = 0; j < m_hauteur; ++j)
				{
				print(getWindowWinTerr(),i,j,'|');
				}
			}
			else{
				for (int j = 0; j < m_hauteur; ++j)
				{
				print(getWindowWinTerr(),i,j,'_');
				}
			}
		}
	}
	else{
		for (int i = 0; i < m_largeur; ++i)
		{
			if (i%5 == 0)
			{
				for (int j = 0; j < m_hauteur; ++j)
				{
				print(getWindowWinTerr(),i,j,'|');
				}
			}
			else{
				for (int j = 0; j < m_hauteur; ++j)
				{
				print(getWindowWinTerr(),i,j,'_');
				}
			}
		}
	}
}

void terrM::update() const{
	wrefresh(getWindowWinTerr());
  	refresh(); 
}