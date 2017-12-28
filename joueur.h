#ifndef JOUEUR_H
#define JOUEUR_H

#include "navire.h"

class Joueur
{
private:
	std::string m_pseudo;
	WINDOW* m_win;
	int m_defaut;
	Navire T[5];
public:
	Joueur(std::string pseudo, WINDOW* Win, int defaut = 1);
	~Joueur();
	
	std::string getPseudo();

	void print(int i) const;

	void mvNav(int i, terrM jeu);
	void selectNav(terrM jeu);
	void lancerMiss();
	
};

#endif