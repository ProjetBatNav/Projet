#include "menuprinc.h"

void menuPrinc_keyUp(Menu &bouton1, Menu &bouton2, Menu &bouton3, Color const &btnBord1, Color const &btnFen1, int &i){
  if (i == 0)
  {
    bouton1.setCouleurBordure(bouton3.getCouleurBordure());
    bouton1.setCouleurFenetre(bouton3.getCouleurFenetre());
    bouton3.setCouleurBordure(btnBord1);
    bouton3.setCouleurFenetre(btnFen1);
    i = 2;
  }
  else if(i == 1){
    bouton2.setCouleurBordure(bouton1.getCouleurBordure());
    bouton2.setCouleurFenetre(bouton1.getCouleurFenetre());
    bouton1.setCouleurBordure(btnBord1);
    bouton1.setCouleurFenetre(btnFen1);
    i--;
  }
  else{
    bouton3.setCouleurBordure(bouton2.getCouleurBordure());
    bouton3.setCouleurFenetre(bouton2.getCouleurFenetre());
    bouton2.setCouleurBordure(btnBord1);
    bouton2.setCouleurFenetre(btnFen1);
    i--;  
  } 
}

void menuPrinc_keyDown(Menu &bouton1, Menu &bouton2, Menu &bouton3, Color const &btnBord1, Color const &btnFen1, int &i){
  if (i == 0)
  {
    bouton1.setCouleurBordure(bouton2.getCouleurBordure());
    bouton1.setCouleurFenetre(bouton2.getCouleurFenetre());
    bouton2.setCouleurBordure(btnBord1);
    bouton2.setCouleurFenetre(btnFen1);
    i++;
  }
  else if(i == 1){
    bouton2.setCouleurBordure(bouton3.getCouleurBordure());
    bouton2.setCouleurFenetre(bouton3.getCouleurFenetre());
    bouton3.setCouleurBordure(btnBord1);
    bouton3.setCouleurFenetre(btnFen1);
    i++;
  }
  else{
    bouton3.setCouleurBordure(bouton1.getCouleurBordure());
    bouton3.setCouleurFenetre(bouton1.getCouleurFenetre());
    bouton1.setCouleurBordure(btnBord1);
    bouton1.setCouleurFenetre(btnFen1);
    i = 0;  
  }
}

void boutonPrinc(Menu &bouton1, Menu &bouton2, Menu &bouton3){
  bouton1.setCouleurBordure(BGREEN);
  bouton1.setCouleurFenetre(BBLUE); 
  bouton2.setCouleurBordure(BRED);
  bouton2.setCouleurFenetre(BYELLOW);
  bouton3.setCouleurBordure(BRED);
  bouton3.setCouleurFenetre(BYELLOW);
}

void menuPrinc(){
  int sourisX, sourisY, bouton, ch, i=0;
  int h=3,w=COLS/3;
  
  Menu jouer(h,w,COLS/3,LINES/8+1, "JOUER");
  Menu aPropos(h,w,COLS/3,3*LINES/8+1, "A PROPOS");
  Menu quitter(h,w,COLS/3,5*LINES/8, "QUITTER");
  boutonPrinc(jouer, aPropos, quitter);

  Color const tmp = jouer.getCouleurBordure(), tmp2 = jouer.getCouleurFenetre();
  

  while(((ch = getch()) != '\n') || (quitter.getCouleurBordure() != tmp))
    {
      switch (ch) {
   //       case KEY_MOUSE:
   // if(souris_getpos(&sourisX, &sourisY, &bouton) == OK) {
   //    if(bouton & BUTTON1_PRESSED)
   //      printw("Clic bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
   //    if(bouton & BUTTON1_RELEASED)
   //      printw("UP bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
   //    if(bouton & BUTTON3_PRESSED)
   //      printw("Clic bouton 2 a la position (%d, %d)\n", sourisX, sourisY);
   //    if(bouton & BUTTON1_DOUBLE_CLICKED)
   //      printw("Double-clic bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
   //    if(bouton & BUTTON3_DOUBLE_CLICKED)
   //      printw("Double-clic bouton 2 a la position (%d, %d)\n", sourisX, sourisY);
   //    refresh();
   // }
   // break;      
      case KEY_UP:
  menuPrinc_keyUp(jouer, aPropos, quitter, tmp, tmp2, i);
  break;
      case KEY_DOWN:
  menuPrinc_keyDown(jouer, aPropos, quitter, tmp, tmp2, i);
  break;
      case '\n':
  if (jouer.getCouleurBordure() == tmp)
  {
    clearTerm();
    menuJouer();
    clearTerm();
    boutonPrinc(jouer, aPropos, quitter);
    i = 0;
  }
  else if (aPropos.getCouleurBordure() == tmp )
  {
    clearTerm();
    APropos();
  }
  break;
      }
    }
}