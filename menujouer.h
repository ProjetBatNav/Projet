#ifndef MENUJOUER_H
#define MENUJOUER_H

#include "menu.h"
#include "fntJcIA.h"

//Fonction qui permet de changer la couleur de la bordure et de la fenetre en fonction \
de KEY_UP.
void menuJouer_keyUp(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4, Color const &btnBord1, Color const &btnFen1, int &i);

//Fonction qui permet de changer la couleur de la bordure et de la fenetre en fonction \
de KEY_DOWN.
void menuJouer_keyDown(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4, Color const &btnBord1, Color const &btnFen1, int &i);

//Permet de recharger tout les boutons du menu Principal
void boutonJouer(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4);

//Fonction qui execute le menu jouer.
void menuJouer(std::string &mode);

#endif