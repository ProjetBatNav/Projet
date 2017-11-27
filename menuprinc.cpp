#include "menuprinc.h"

void menuPrinc_keyUp(Menu &bouton1, Menu &bouton2, Menu &bouton3, Color const &btnBord1, Color const &btnFen1, int &i){
  if (i == 0)
  {
    bouton1.setCouleurBordMenu(bouton3.getCouleurBordMenu());
    bouton1.setCouleurFntMenu(bouton3.getCouleurFntMenu());
    bouton3.setCouleurBordMenu(btnBord1);
    bouton3.setCouleurFntMenu(btnFen1);
    i = 2;
  }
  else if(i == 1){
    bouton2.setCouleurBordMenu(bouton1.getCouleurBordMenu());
    bouton2.setCouleurFntMenu(bouton1.getCouleurFntMenu());
    bouton1.setCouleurBordMenu(btnBord1);
    bouton1.setCouleurFntMenu(btnFen1);
    i--;
  }
  else{
    bouton3.setCouleurBordMenu(bouton2.getCouleurBordMenu());
    bouton3.setCouleurFntMenu(bouton2.getCouleurFntMenu());
    bouton2.setCouleurBordMenu(btnBord1);
    bouton2.setCouleurFntMenu(btnFen1);
    i--;  
  } 
}

void menuPrinc_keyDown(Menu &bouton1, Menu &bouton2, Menu &bouton3, Color const &btnBord1, Color const &btnFen1, int &i){
  if (i == 0)
  {
    bouton1.setCouleurBordMenu(bouton2.getCouleurBordMenu());
    bouton1.setCouleurFntMenu(bouton2.getCouleurFntMenu());
    bouton2.setCouleurBordMenu(btnBord1);
    bouton2.setCouleurFntMenu(btnFen1);
    i++;
  }
  else if(i == 1){
    bouton2.setCouleurBordMenu(bouton3.getCouleurBordMenu());
    bouton2.setCouleurFntMenu(bouton3.getCouleurFntMenu());
    bouton3.setCouleurBordMenu(btnBord1);
    bouton3.setCouleurFntMenu(btnFen1);
    i++;
  }
  else{
    bouton3.setCouleurBordMenu(bouton1.getCouleurBordMenu());
    bouton3.setCouleurFntMenu(bouton1.getCouleurFntMenu());
    bouton1.setCouleurBordMenu(btnBord1);
    bouton1.setCouleurFntMenu(btnFen1);
    i = 0;  
  }
}

void boutonPrinc(Menu &bouton1, Menu &bouton2, Menu &bouton3){
  bouton1.setCouleurBordMenu(BGREEN);
  bouton1.setCouleurFntMenu(BBLUE); 
  bouton2.setCouleurBordMenu(BRED);
  bouton2.setCouleurFntMenu(BYELLOW);
  bouton3.setCouleurBordMenu(BRED);
  bouton3.setCouleurFntMenu(BYELLOW);
}

void menuPrinc(){
  int sourisX, sourisY, bouton, ch, i=0;
  int h=5,w=COLS/3;
  
  Menu jouer(h,w,COLS/3,LINES/8+1, "JOUER");
  Menu options(h,w,COLS/3,3*LINES/8+1, "OPTIONS");
  Menu quitter(h,w,COLS/3,5*LINES/8, "QUITTER");
  boutonPrinc(jouer, options, quitter);

  Color const tmp = jouer.getCouleurBordMenu(), tmp2 = jouer.getCouleurFntMenu();
  

  while(((ch = getch()) != '\n') || (quitter.getCouleurBordMenu() != tmp))
  {
      switch (ch) {
        // case KEY_MOUSE:
        //  if(souris_getpos(&sourisX, &sourisY, &bouton) == OK) {
        //     if(bouton & BUTTON1_PRESSED)
        //       printw("Clic bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
        //     if(bouton & BUTTON1_RELEASED)
        //       printw("UP bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
        //     if(bouton & BUTTON3_PRESSED)
        //       printw("Clic bouton 2 a la position (%d, %d)\n", sourisX, sourisY);
        //     if(bouton & BUTTON1_DOUBLE_CLICKED)
        //       printw("Double-clic bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
        //     if(bouton & BUTTON3_DOUBLE_CLICKED)
        //       printw("Double-clic bouton 2 a la position (%d, %d)\n", sourisX, sourisY);
        //     refresh();
        //  }
        // break;      
        case KEY_UP:
          menuPrinc_keyUp(jouer, options, quitter, tmp, tmp2, i);
        break;
        case KEY_DOWN:
          menuPrinc_keyDown(jouer, options, quitter, tmp, tmp2, i);
        break;
        case '\n':
          if (jouer.getCouleurBordMenu() == tmp)
          {
            clearTerm();
            menuJouer();
            clearTerm();
            boutonPrinc(jouer, options, quitter);
            i = 0;
          }
          else if (options.getCouleurBordMenu() == tmp )
          {
            clearTerm();
            Options();
          }
        break;
      }
  }
}
