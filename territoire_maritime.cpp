#include "territoire_maritime.h"

terrM::terrM(WINDOW* Win)
: m_startX(0), m_startY(0), m_win(Win){
	m_colorTerrM = BBLUE;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++)
		{
			T[i][j].setX(m_startX+2*i);
			T[i][j].setY(m_startY+j);
			T[i][j].setCouleur(m_colorTerrM);		
		}
	}
	print(Win);
}

terrM::~terrM(){}

WINDOW* terrM::getWin() const{
  return m_win;
}

int terrM::getXAt(int i) const{
	return T[i][0].getX();
}
int terrM::getYAt(int j) const{
	return T[0][j].getY();
}
Color terrM::getCouleur() const{
	return m_colorTerrM;
}

void terrM::setCouleurAt(int i, int j, Color c){
	T[i][j].setCouleur(c);
	print(m_win);
}

// void terrM::setCouleurBordureTerr(Color c){
// 	m_terr.setCouleurBordureFnt(c);
// }

void terrM::print(WINDOW* Win) const{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			T[i][j].print(Win);
		}
	}
}