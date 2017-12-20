#ifndef NAVIRE_H
#define NAVIRE_H

#include "window.h"
#include "cellule.h"

class Navire
{
private:
	int m_startX, m_startY;
	char m_spr;
	std::string m_nom;
	Color m_navColor;
	Cellule T[5][5];

public:
	Navire();
	Navire(std::string nom, int x, int y, Color c);
	~Navire();

	int getStartX() const;
	int getStartY() const;
	std::string getNom() const;
	Color getNavColor() const;

	void setStartX(int x);
	void setStartY(int y);
	void setNom(std::string nom);
	void setNavColor(Color c);

  	void print(WINDOW* Win) const;
  	void defautNavire();
  	// void printNav(WINDOW* Win, int x, int y, Color c) const;
  	// void mvNav(WINDOW* Win, int ch, std::string mode, Color c);
};
#endif
