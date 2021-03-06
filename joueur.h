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
	Joueur();
	Joueur(std::string pseudo, WINDOW* Win, int defaut = 1);
	~Joueur();
	
	std::string getPseudo() const;
	WINDOW* getWin() const;

	void setPseudo(std::string pseudo);
	void setWin(WINDOW* Win);

	void print(int i) const;

	void supNav(int i, int ch, const terrM jeu);
	void mvNav(int i, const terrM &jeu);
	void selectNav(const terrM &jeu);
	void lancerMiss();
	
};

#endif