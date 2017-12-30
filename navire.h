#ifndef NAVIRE_H
#define NAVIRE_H

#include "territoire_maritime.h"
#include <unistd.h>

class Navire
{
private:
	int m_startX, m_startY, m_taille;
	WINDOW* m_win;
	std::string m_nom;
	Color m_navColor;
	Cellule* T;

public:
	//Constructeurs
	Navire();
	Navire(std::string nom, int x, int y, WINDOW* Win);
	Navire(std::string nom, int x, int y, WINDOW* Win, Color c);

	//Destructeurs
	~Navire();

	//Accesseurs en lecture
	int getStartX() const;
	int getStartY() const;
	int getTaille() const;
	WINDOW* getWin() const;
	std::string getNom() const;
	Color getNavColor() const;

	//Accesseurs en ecriture
	void setStartX(int x);
	void setStartY(int y);
	void setX(int x);
	void setY(int y);
	void setTaille(int taille);
	void setWin(WINDOW* Win);
	void setNom(std::string nom);
	void setNavColor(Color c);

	bool horsLimiteJeu(const terrM &jeu) const;
	bool estMemeWin(const Navire &n) const;
	bool estEquivalent(const Navire &n) const;
	bool operator==(const Navire &n) const;
	bool operator!=(const Navire &n) const;
  	
  	void print() const;
  	void pivoterD();
  	void pivoterG();
  	void effacer();
  	void defautNavire();
	void initNav(int x, int y, WINDOW* Win);
  	void clignot();
  	void deplacer(const terrM &jeu);
};
#endif
