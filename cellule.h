#ifndef __CELLULE_H
#define __CELLULE_H

#include <string>
#include "window.h"

class Cellule {
 private:
  size_t m_touche;
  std::string m_spr;
  unsigned int m_startX, m_startY;
  Color m_couleur;

 public:

  // Constructeurs
  Cellule(); // morte par défaut
  Cellule(bool touche, unsigned int x, unsigned int y, Color c);

  // Accesseurs en lecture
  bool getTouche() const;
  unsigned int getX() const;
  unsigned int getY() const;
  Color getCouleur() const;

  // Accesseurs en écriture
  void setX(unsigned int x);
  void setY(unsigned int y);
  void setTouche(bool touche);
  void setCouleur(Color couleur);

  // renvoie vrai si la cellule courante est vivante et est voisine de c
  bool estVoisine(const Cellule &c) const;
  // affiche la cellule
  void print(WINDOW* Win) const;

  // comparaison de cellules
  bool estAvant(const Cellule &c) const;
  bool estApres(const Cellule &c) const;
  bool estEquivalente(const Cellule &c) const;
  bool estDifferente(const Cellule &c) const;
  bool estAvantOuEquivalente(const Cellule &c) const;
  bool estApresOuEquivalente(const Cellule &c) const;

   // comparaison de cellules
  bool operator<(const Cellule &c) const;
  bool operator>(const Cellule &c) const;
  bool operator==(const Cellule &c) const;
  bool operator!=(const Cellule &c) const;
  bool operator<=(const Cellule &c) const;
  bool operator>=(const Cellule &c) const;
};

// Renvoie vrai si la cellule est de la couleur passée en paramètre, faux sinon.
bool CelluleEstDeLaCouleur(const Cellule &cellule, Color couleur);

// echange 2 cellules
void echanger(Cellule &a, Cellule &b);

void read_cell(std::istream&, Cellule&);
void write_cell(std::ostream&, const Cellule&);
bool identique(const Cellule&,const Cellule&);
std::ostream &operator<<(std::ostream &os, const Cellule& C);
std::istream &operator>>(std::istream &is, Cellule &C);


#endif

