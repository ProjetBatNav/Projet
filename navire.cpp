#include "navire.h"

Navire::Navire(WINDOW* Win, int h, int l, int x, int y, Color c)
: m_hauteur(h), m_largeur(l), m_startX(x), m_startY(y), m_navColor(c) {
        char s = ' ';
        m_spr = s;
        printNav(Win,x,y,c);
}

Navire::~Navire(){}

int Navire::getStartX() const{
	return m_startX;
}
int Navire::getStartY() const{
	return m_startY;
}
Color Navire::getNavColor() const{
	return m_navColor;
}

void Navire::print(WINDOW* Win, int x, int y, Color c) const{
  wattron(Win,COLOR_PAIR(c));
  mvwaddch(Win,y,x,m_spr);
  wattroff(Win,COLOR_PAIR(c));
  wrefresh(Win);
  refresh();
}

void Navire::printNav(WINDOW* Win, int x, int y, Color c) const{
	int X = x;

	for (int i = 0; i < m_hauteur ; ++i)
	{
		for (int j = 0; j < m_largeur; ++j)
		{
		  print(Win,X,y,c);
		  X++;
		}
		X = x;
		y++;
	}
}

void Navire::mvNav(WINDOW* Win, int ch, std::string mode, Color c){
	switch(ch){
		case KEY_UP :
			if(mode == "10x10"){
				printNav(Win,m_startX,m_startY,c);
				m_startY -= 1;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
			else
			{
				printNav(Win,m_startX,m_startY,c);
				m_startY -= 2;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
		break;
		case KEY_DOWN :
			if(mode == "10x10"){
				printNav(Win,m_startX,m_startY,c);
				m_startY += 1;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
			else
			{
				printNav(Win,m_startX,m_startY,c);
				m_startY += 2;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
		break;
		case KEY_LEFT :
			if(mode == "10x10"){
				printNav(Win,m_startX,m_startY,c);
				m_startX -= 3;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
			else
			{
				printNav(Win,m_startX,m_startY,c);
				m_startX -= 4;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
		break;
		case KEY_RIGHT :
			if(mode == "10x10"){
				printNav(Win,m_startX,m_startY,c);
				m_startX += 3;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
			else
			{
				printNav(Win,m_startX,m_startY,c);
				m_startX += 4;
				printNav(Win,m_startX,m_startY,m_navColor);
			}
		break;
		case 32 :
			if(m_largeur > m_hauteur){
				printNav(Win,m_startX,m_startY,c);
				int largeur = m_largeur;
				m_largeur = 2*m_hauteur;
				m_hauteur = largeur/2;
				m_startX += (m_hauteur/2*2);
				m_startY -= (m_hauteur/2);
				printNav(Win,m_startX,m_startY,m_navColor);		
			}
			else{
				printNav(Win,m_startX,m_startY,c);
				int largeur = m_largeur, hauteur = m_hauteur;
				m_largeur = 2*m_hauteur;
				m_hauteur = largeur/2;
				m_startX -= (hauteur/2*2);
				m_startY += (hauteur/2);
				printNav(Win,m_startX,m_startY,m_navColor);
			}
		break;
	}
	
}