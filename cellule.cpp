#include "cellule.h"
#include <iostream>
#include <string>
using namespace std;

Cellule::Cellule(): m_touche(0), m_spr("  "), m_startX(0), m_startY(0), m_couleur(WBLACK) {
}

Cellule::Cellule(bool touche, int x, int y, Color c):
  m_touche(touche ? 1 : 0), m_spr("  "), m_startX(x), m_startY(y), m_couleur(c) {
}

Cellule::~Cellule(){}

bool Cellule::getTouche() const {
  return m_touche;
}

int Cellule::getX() const {
  return m_startX;
}

int Cellule::getY() const {
  return m_startY;
}

Color Cellule::getCouleur() const {
  return m_couleur;
}

// Accesseurs en écriture
void Cellule::setX(int x) {
  m_startX = x;
}

void Cellule::setY(int y) {
  m_startY = y;
}

void Cellule::setCouleur(Color couleur){
	m_couleur = couleur;
}

bool Cellule::estVoisineH(const Cellule &c) const {
  return (m_startY - c.m_startY) * (m_startY - c.m_startY) < 2;
}

void Cellule::print(WINDOW* Win) const {
	wattron(Win,COLOR_PAIR(m_couleur));
  mvwprintw(Win,m_startY,m_startX,m_spr.c_str());
	wattroff(Win,COLOR_PAIR(m_couleur));
	wrefresh(Win);
	refresh();
}

void Cellule::setTouche(bool touche) {
  if (touche) {
    m_couleur = BRED;
    m_touche = 1;
  } else {
    m_touche = 0;
  }
}

bool CelluleEstDeLaCouleur(const Cellule &cellule, Color couleur) {
  return (cellule.getCouleur() == couleur);
}

bool Cellule::estAvant(const Cellule &c) const {
  return (m_startX < c.m_startX) || ((m_startX == c.m_startX) && (m_startY < c.m_startY));
}
bool Cellule::estApres(const Cellule &c) const {
  return c.estAvant(*this);
}
bool Cellule::estEquivalente(const Cellule &c) const {
  return !estAvant(c) && !estApres(c);
}
bool Cellule::estDifferente(const Cellule &c) const {
  return !estEquivalente(c);
}
bool Cellule::estAvantOuEquivalente(const Cellule &c) const {
  return estAvant(c) || estEquivalente(c);
}
bool Cellule::estApresOuEquivalente(const Cellule &c) const {
  return estApres(c) || estEquivalente(c);
}

bool Cellule::operator<(const Cellule &c) const {
  return (m_startX < c.m_startX) || ((m_startX == c.m_startX) && (m_startY < c.m_startY));
}

bool Cellule::operator>(const Cellule &c) const {
  return c.operator<(*this);
}

bool Cellule::operator==(const Cellule &c) const {
  return !operator<(c) && !operator>(c);
}

bool Cellule::operator!=(const Cellule &c) const {
  return !operator==(c);
}

bool Cellule::operator<=(const Cellule &c) const {
  return operator<(c) || operator==(c);
}
bool Cellule::operator>=(const Cellule &c) const {
  return operator>(c) || operator==(c);
}

 
void echanger(Cellule &a, Cellule &b) {
  Cellule tmp = a;
  a = b;
  b = tmp;
}

  
void read_cell(std::istream& is, Cellule& C){
  unsigned int x,y,b;
  is>>x>>y>>b;
  C.setX(x);
  C.setY(y);
  C.setTouche(b);
}
void write_cell(std::ostream& os, const Cellule& C){
  os << C.getX() << "x" << C.getY();
}

 bool identique(const Cellule& C1,const Cellule& C2){
   return (C1.getX()==C2.getX()) && (C1.getY()==C2.getY()) && (C1.getTouche()==C2.getTouche()); 
 }


ostream &operator<<(ostream& os, const Cellule& C){
  write_cell(os,C);return os;
}

istream &operator>>(istream& is, Cellule &C){
  read_cell(is,C); return is;
}
