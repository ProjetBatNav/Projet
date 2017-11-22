#include "menu.h"

Menu::Menu(int h, int w, int x, int y, std::string nom)
	: m_menu(h,w,x,y), m_nomMenu(nom) {
		printCenter(h,w,nom);
	}

Menu::~Menu(){}

void Menu::upDatePrint(int x, int y){
	m_menu.clearWin();
	mvwprintw(m_menu.getWindowWin(),y,x,m_nomMenu.c_str());
  	wrefresh(m_menu.getWindowWin());
}

void Menu::printCenter(int h, int w, std::string nom){
	int i;

	for (i = 0; nom[i]; i++){}

	i++;
	int x = (w-i)/2;
	int y = h/2;

	m_menu.print(x,y,nom);
}

Color Menu::getCouleurBordMenu() const{
  return m_menu.getCouleurBordure();
}

Color Menu::getCouleurFntMenu() const{
  return m_menu.getCouleurFenetre();
}

void Menu::setCouleurBordMenu(Color c){
  m_menu.setCouleurBordure(c);
}

void Menu::setCouleurFntMenu(Color c){
  m_menu.setCouleurFenetre(c);
}
