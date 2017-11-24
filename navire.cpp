#include "navire.h"

Navire::Navire(WINDOW* Win, int h, int l, int x, int y, Color c)
: m_hauteur(h), m_largeur(l), m_startX(x), m_startY(y), m_navColor(c) {
        char s = ' ';
        m_spr = s;
	// int i, j, X = x;

	// for (i = 0; i < h ; ++i)
	// {
	// 	for (j = 0; j < l; ++j)
	// 	{
	// 	  print(Win,X,y,c);
	// 	  X++;
	// 	}
	// 	X = x;
	// 	y++;
	// }
        printNavVerti(Win,x,y,c);
}

Navire::~Navire(){}

int Navire::getStartX() const{
	return m_startX;
}
int Navire::getStartY() const{
	return m_startY;
}

void Navire::print(WINDOW* Win, int x, int y, Color c) const{
  wattron(Win,COLOR_PAIR(c));
  mvwaddch(Win,y,x,m_spr);
  wattroff(Win,COLOR_PAIR(c));
  wrefresh(Win);
  refresh();
}

void Navire::printNavVerti(WINDOW* Win, int x, int y, Color c) const{
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

void Navire::printNavHori(WINDOW* Win, int x, int y, Color c) const{
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
	// if (mode == "20x20")
	// {
	// 	m_hauteur *= 2;
	// 	m_largeur *= 2; 
	// }
	if(ch == KEY_UP){
		if(mode == "10x10"){
			printNavVerti(Win,m_startX,m_startY,c);
			m_startY -= 1;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
		else
		{
			printNavVerti(Win,m_startX,m_startY,c);
			m_startY -= 2;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
	}
	else if(ch == KEY_DOWN){
		if(mode == "10x10"){
			printNavVerti(Win,m_startX,m_startY,c);
			m_startY += 1;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
		else
		{
			printNavVerti(Win,m_startX,m_startY,c);
			m_startY += 2;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
	}
	else if(ch == KEY_LEFT){
		if(mode == "10x10"){
			printNavVerti(Win,m_startX,m_startY,c);
			m_startX -= 2;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
		else
		{
			printNavVerti(Win,m_startX,m_startY,c);
			m_startX -= 4;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
	}
	else if(ch == KEY_RIGHT){
		if(mode == "10x10"){
			printNavVerti(Win,m_startX,m_startY,c);
			m_startX += 2;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
		else
		{
			printNavVerti(Win,m_startX,m_startY,c);
			m_startX += 4;
			printNavVerti(Win,m_startX,m_startY,m_navColor);
		}
	}
	else{
		if(m_largeur > m_hauteur){
			printNavHori(Win,m_startX,m_startY,c);
			int largeur = m_largeur;
			m_largeur = 2*m_hauteur;
			m_hauteur = largeur/2;
			printNavVerti(Win,m_startX,m_startY,m_navColor);		
		}
		else{
			printNavVerti(Win,m_startX,m_startY,c);
			int largeur = m_largeur;
			m_largeur = 2*m_hauteur;
			m_hauteur = largeur/2;
			printNavHori(Win,m_startX,m_startY,m_navColor);
		}
	}
}