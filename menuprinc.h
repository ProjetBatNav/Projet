#ifndef MENUPRINC_H
#define MENUPRINC_H

#include "menu.h"
#include "menujouer.h"
// #include "menuoptions.h"

//Fonction qui permet de changer la couleur de la bordure et de la fenetre en fonction \
de KEY_UP.
void menuPrinc_keyUp(Menu &bouton1, Menu &bouton2, Menu &bouton3, Color const &btnBord1, Color const &btnFen1, int &i);

//Fonction qui permet de changer la couleur de la bordure et de la fenetre en fonction \
de KEY_DOWN.
void menuPrinc_keyDown(Menu &bouton1, Menu &bouton2, Menu &bouton3, Color const &btnBord1, Color const &btnFen1, int &i);

//Permet de recharger tout les boutons du menu Principal
void boutonPrinc(Menu &bouton1, Menu &bouton2, Menu &bouton3);

//Fonction qui exécute le jeu.
void menuPrinc();

#endif
