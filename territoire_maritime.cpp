#include "territoire_maritime.h"

terrM::terrM(WINDOW* Win)
: m_startX(0), m_startY(0){
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

// WINDOW* terrM::getWindowWinTerr() const{
//   return m_terr.getWindowWinFnt();
// }

// Color terrM::getCouleurFenetreTerr() const{
// 	return m_terr.getCouleurFenetreFnt();
// }

// void terrM::setCouleurFenetreTerr(Color c){
// 	m_terr.setCouleurFenetreFnt(c);
// }

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