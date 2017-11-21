#include "menu.h"

Menu::Menu(int h, int w, int x, int y, std::string nom)
	: Window(h,w,x,y), m_nomMenu(nom) {
		printCenter(h,w,nom);
	}

Menu::~Menu(){}

void Menu::upDatePrint(int x, int y){
	clearWin();
	mvwprintw(win,y,x,m_nomMenu.c_str());
  	update();
}

void Menu::printCenter(int h, int w, std::string nom){
	int i;

	for (i = 0; nom[i]; i++){}

	i++;
	int x = (w-i)/2;
	int y = h/2;

	print(x,y,nom);
}