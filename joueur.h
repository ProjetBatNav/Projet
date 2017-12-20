#ifndef JOUEUR_H
#define JOUEUR_H

#include "navire.h"
#include "window.h"
#include <unistd.h>

class Joueur
{
private:
	std::string m_pseudo;
	int m_defaut;
	Navire T[5];
public:
	Joueur(std::string pseudo, int defaut = 1);
	~Joueur();
	
	std::string getPseudo();

	// void mvNav(WINDOW* Win, Navire &nom, int ch, std::string mode, Color c);
	// void selectNav(WINDOW* Win, Navire &nom1, Navire &nom2, Navire &nom3, Navire &nom4, Navire &nom5);
	void lancerMiss();
	
};

#endif