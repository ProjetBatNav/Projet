#include "navire.h"

Navire::Navire()
: m_nom(""), m_startX(0), m_startY(0), m_navColor(WBLACK) {}

Navire::Navire(std::string nom, int x, int y, Color c)
: m_nom(nom), m_startX(x), m_startY(y), m_navColor(c) {
	if(m_nom == "destroyer"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3)
				{
					T[i][j].setCouleur(c);
				}
			}
		}
	}
	else if(m_nom == "croiseur"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 4)
				{
					T[i][j].setCouleur(c);
				}
			}
		}
	}
	else if(m_nom == "contreTorpilleur"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 3)
				{
					T[i][j].setCouleur(c);
				}
			}
		}
	}
	else if(m_nom == "sousMarin"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 3)
				{
					T[i][j].setCouleur(c);
				}
			}
		}
	}
	else if(m_nom == "torpilleur"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 2)
				{
					T[i][j].setCouleur(c);
				}
			}
		}
	}
}

Navire::~Navire(){}

int Navire::getStartX() const{
	return m_startX;
}
int Navire::getStartY() const{
	return m_startY;
}
std::string Navire::getNom() const{
	return m_nom;
}
Color Navire::getNavColor() const{
	return m_navColor;
}

void Navire::setStartX(int x){
	m_startX = x;
}
void Navire::setStartY(int y){
	m_startY = y;
}
void Navire::setNom(std::string nom){
	m_nom = nom;
}
void Navire::setNavColor(Color c){
	m_navColor = c;
}

void Navire::print(WINDOW* Win) const{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			T[i][j].print(Win);
		}
	}
}

void Navire::defautNavire(){
	if(m_nom == "destroyer"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3)
				{
					m_navColor = BYELLOW;
					T[i][j].setCouleur(m_navColor);
				}
			}
		}
	}
	else if(m_nom == "croiseur"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 4)
				{
					m_navColor = BGREEN;
					T[i][j].setCouleur(m_navColor);
				}
			}
		}
	}
	else if(m_nom == "contreTorpilleur"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 3)
				{
					m_navColor = BMAGENTA;
					T[i][j].setCouleur(m_navColor);
				}
			}
		}
	}
	else if(m_nom == "sousMarin"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 3)
				{
					m_navColor = BWHITE;
					T[i][j].setCouleur(m_navColor);
				}
			}
		}
	}
	else if(m_nom == "torpilleur"){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++)
			{
				T[i][j].setX(m_startX+2*i);
				T[i][j].setY(m_startY+j);
				if (i == 3 && j < 2)
				{
					m_navColor = BCYAN;
					T[i][j].setCouleur(m_navColor);
				}
			}
		}
	}
}

// void Navire::mvNav(WINDOW* Win, int ch, std::string mode, Color c){
// 	switch(ch){
// 		case KEY_UP :
// 			if(mode == "10x10"){
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startY -= 1;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 			else
// 			{
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startY -= 2;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 		break;
// 		case KEY_DOWN :
// 			if(mode == "10x10"){
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startY += 1;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 			else
// 			{
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startY += 2;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 		break;
// 		case KEY_LEFT :
// 			if(mode == "10x10"){
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startX -= 3;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 			else
// 			{
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startX -= 4;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 		break;
// 		case KEY_RIGHT :
// 			if(mode == "10x10"){
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startX += 3;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 			else
// 			{
// 				printNav(Win,m_startX,m_startY,c);
// 				m_startX += 4;
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 		break;
// 		case 32 :
// 			if(m_largeur > m_hauteur){
// 				printNav(Win,m_startX,m_startY,c);
// 				int largeur = m_largeur;
// 				m_largeur = 2*m_hauteur;
// 				m_hauteur = largeur/2;
// 				m_startX += (m_hauteur/2*2);
// 				m_startY -= (m_hauteur/2);
// 				printNav(Win,m_startX,m_startY,m_navColor);		
// 			}
// 			else{
// 				printNav(Win,m_startX,m_startY,c);
// 				int largeur = m_largeur, hauteur = m_hauteur;
// 				m_largeur = 2*m_hauteur;
// 				m_hauteur = largeur/2;
// 				m_startX -= (hauteur/2*2);
// 				m_startY += (hauteur/2);
// 				printNav(Win,m_startX,m_startY,m_navColor);
// 			}
// 		break;
// 	}
	
// }