#include "navire.h"

//Constructeurs
Navire::Navire()
: m_nom(""), m_startX(0), m_startY(0), m_win(NULL), m_navColor(WBLACK) {}

Navire::Navire(std::string nom, int x, int y, WINDOW* Win)
: m_nom(nom), m_startX(x), m_startY(y), m_win(Win){
	defautNavire();
}

Navire::Navire(std::string nom, int x, int y, WINDOW* Win, Color c)
: m_nom(nom), m_startX(x), m_startY(y), m_win(Win), m_navColor(c){
	if(m_nom == "destroyer"){
		m_taille = 5;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(c);
		}
	}
	else if(m_nom == "croiseur"){
		m_taille = 4;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(c);
		}
	}
	else if(m_nom == "contreTorpilleur"){
		m_taille = 3;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(c);
		}
	}
	else if(m_nom == "sousMarin"){
		m_taille = 3;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(c);
		}
	}
	else if(m_nom == "torpilleur"){
		m_taille = 2;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(c);
		}
	}
}

//Destructeurs
Navire::~Navire(){
	delete[] T;
}

//Accesseurs en lecture
int Navire::getStartX() const{
	return m_startX;
}
int Navire::getStartY() const{
	return m_startY;
}
int Navire::getTaille() const{
	return m_taille;
}
WINDOW* Navire::getWin() const{
	return m_win;
}
std::string Navire::getNom() const{
	return m_nom;
}
Color Navire::getNavColor() const{
	return m_navColor;
}

//Accesseurs en ecriture
void Navire::setStartX(int x){
	m_startX = m_startX+x;
	for (int i = 0; i < m_taille; ++i)
	{
		T[i].setX(T[i].getX()+x);
	}
}
void Navire::setStartY(int y){
	m_startY = m_startY+y;
	for (int i = 0; i < m_taille; ++i)
	{
		T[i].setY(T[i].getY()+y);
	}
}
void Navire::setX(int x){
	int X = m_startX;
	m_startX = x;
	for (int i = 0; i < m_taille; ++i)
	{
		T[i].setX(m_startX+T[i].getX()-X);
	}
}
void Navire::setY(int y){
	int Y = m_startY;
	m_startY = y;
	for (int i = 0; i < m_taille; ++i)
	{
		T[i].setY(m_startY+T[i].getY()-Y);
	}
}
void Navire::setTaille(int taille){
	m_taille = taille;
}
void Navire::setWin(WINDOW* Win){
	m_win = Win;
}
void Navire::setNom(std::string nom){
	m_nom = nom;
}
void Navire::setNavColor(Color c){
	for (int i = 0; i < m_taille; ++i)
	{
		T[i].setCouleur(c);
	}
	m_navColor = c;
}
bool Navire::horsLimiteJeu(const terrM &jeu) const{
	for (int i = 0; i < m_taille; ++i)
	{
		if (T[i].getX() < jeu.getXAt(0) || T[i].getX() > jeu.getXAt(19) || T[i].getY() < jeu.getYAt(0) || T[i].getY() > jeu.getYAt(19))
		{
			return true;
		}
	}
	return false;
}
bool Navire::estMemeWin(const Navire &n) const{
	return m_win == n.m_win;
}
bool Navire::estEquivalent(const Navire &n) const{
	for (int i = 0; i < m_taille; i++){
		int j = 0;
		while((T[i].estDifferente(n.T[j]) || !estMemeWin(n)) && j < n.m_taille){
			j++;
		}
		if (T[i].estEquivalente(n.T[j]) && estMemeWin(n)){
			return true;
		}
	}
	return false;
}
bool Navire::operator==(const Navire &n) const{
	for (int i = 0; i < m_taille; i++){
		int j = 0;
		while((T[i] != n.T[j] || !estMemeWin(n)) && j < n.m_taille){
			j++;
		}
		if (T[i] == n.T[j] && estMemeWin(n)){
			return true;
		}
	}
	return false;
}
bool Navire::operator!=(const Navire &n) const{
	return !operator==(n);
}

void Navire::print() const{
	for (int i = 0; i < m_taille; i++)
	{
		T[i].print(m_win);
	}
}
void Navire::pivoterD(){
	for (int i = 1; i < m_taille; ++i)
	{
		// if (ph = 15)
		// {
		// 	if (T[0].getX() == T[i].getX())
		// 	{
		// 		T[i].setX(T[i].getX()-2*(T[0].getY()-T[i].getY()));
		// 		T[i].setY(T[0].getY());
		// 	}
		// 	else if (T[0].getY() == T[i].getY())
		// 	{
		// 		T[i].setY(T[i].getY()-((T[i].getX()-T[0].getX())/2));
		// 		T[i].setX(T[0].getX());
		// 	}
		// }
		// else{
			if (T[0].getX() == T[i].getX())
			{
				T[i].setX(T[i].getX()+2*(T[0].getY()-T[i].getY()));
				T[i].setY(T[0].getY());
			}
			else if (T[0].getY() == T[i].getY())
			{
				T[i].setY(T[i].getY()+((T[i].getX()-T[0].getX())/2));
				T[i].setX(T[0].getX());
			}
		// }
	}
}
void Navire::pivoterG(){
	for (int i = 1; i < m_taille; ++i)
	{
		if (T[0].getX() == T[i].getX())
		{
			T[i].setX(T[i].getX()-2*(T[0].getY()-T[i].getY()));
			T[i].setY(T[0].getY());
		}
		else if (T[0].getY() == T[i].getY())
		{
			T[i].setY(T[i].getY()-((T[i].getX()-T[0].getX())/2));
			T[i].setX(T[0].getX());
		}
	}
}
void Navire::effacer(){
	Color C = m_navColor;
	setNavColor(BBLUE);
	for (int i = 0; i < m_taille; i++)
	{
		T[i].print(m_win);
	}
	setNavColor(C);
}

void Navire::initNav(int x, int y, WINDOW* Win){
	setStartX(x);
	setStartY(y);
	setWin(Win);
}

void Navire::defautNavire(){
	if(m_nom == "destroyer"){
		m_navColor = BYELLOW;
		m_taille = 5;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(m_navColor);
		}
	}
	else if(m_nom == "croiseur"){
		m_navColor = BGREEN;
		m_taille = 4;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(m_navColor);
		}
	}
	else if(m_nom == "contreTorpilleur"){
		m_navColor = BMAGENTA;
		m_taille = 3;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(m_navColor);
		}
	}
	else if(m_nom == "sousMarin"){
		m_navColor = BWHITE;
		m_taille = 3;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(m_navColor);
		}
	}
	else if(m_nom == "torpilleur"){
		m_navColor = BCYAN;
		m_taille = 2;
		T = new Cellule[m_taille];
		for(int i = 0; i < m_taille; i++){
			T[i].setY(m_startY+i);
			T[i].setCouleur(m_navColor);
		}
	}
}

void Navire::clignot(){
	Color c = getNavColor();
	setNavColor(WGREY);
	print();
	usleep(200500);
	setNavColor(c);
	print();
	usleep(200500);
}

void Navire::deplacer(const terrM &jeu){
	effacer();
	initNav(-m_startX,-m_startY,jeu.getWin());
	setX(jeu.getXAt(8));
	setY(jeu.getYAt(8));
	print();
}