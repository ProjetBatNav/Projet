#ifndef MENU_H
#define MENU_H

#include "window.h"

class Menu
{
private:
	std::string m_nomMenu;
	Window m_menu;

public:
	Menu(int h, int w, int x, int y, std::string nom);
	~Menu();

	//Déplace le texte aux coordonnées x,y
	void upDatePrint(int x, int y);

	//Centre le texte
	void printCenter(int x, int y, std::string nom);

	Color getCouleurBordMenu() const;
	Color getCouleurFntMenu() const;
	void setCouleurBordMenu(Color);
	void setCouleurFntMenu(Color);
	
};

#endif