#include "menujouer.h"

void menuJouer_keyUp(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4, Color const &btnBord1, Color const &btnFen1, int &i){
  if (i == 0){
    bouton1.setCouleurBordMenu(bouton4.getCouleurBordMenu());
    bouton1.setCouleurFntMenu(bouton4.getCouleurFntMenu());
    bouton4.setCouleurBordMenu(btnBord1);
    bouton4.setCouleurFntMenu(btnFen1);
    i = 3;
  }
  else if(i == 1){
    bouton2.setCouleurBordMenu(bouton1.getCouleurBordMenu());
    bouton2.setCouleurFntMenu(bouton1.getCouleurFntMenu());
    bouton1.setCouleurBordMenu(btnBord1);
    bouton1.setCouleurFntMenu(btnFen1);
    i--;
  }
  else if(i == 2){
    bouton3.setCouleurBordMenu(bouton2.getCouleurBordMenu());
    bouton3.setCouleurFntMenu(bouton2.getCouleurFntMenu());
    bouton2.setCouleurBordMenu(btnBord1);
    bouton2.setCouleurFntMenu(btnFen1);
    i--;  
  }
  else{
    bouton4.setCouleurBordMenu(bouton3.getCouleurBordMenu());
    bouton4.setCouleurFntMenu(bouton3.getCouleurFntMenu());
    bouton3.setCouleurBordMenu(btnBord1);
    bouton3.setCouleurFntMenu(btnFen1);
    i--;
  } 
}

void menuJouer_keyDown(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4, Color const &btnBord1, Color const &btnFen1, int &i){
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
  else if(i == 2){
    bouton3.setCouleurBordMenu(bouton4.getCouleurBordMenu());
    bouton3.setCouleurFntMenu(bouton4.getCouleurFntMenu());
    bouton4.setCouleurBordMenu(btnBord1);
    bouton4.setCouleurFntMenu(btnFen1);
    i++;  
  }
  else{
    bouton4.setCouleurBordMenu(bouton1.getCouleurBordMenu());
    bouton4.setCouleurFntMenu(bouton1.getCouleurFntMenu());
    bouton1.setCouleurBordMenu(btnBord1);
    bouton1.setCouleurFntMenu(btnFen1);
    i = 0;
  }
}

void boutonJouer(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4){
  bouton1.setCouleurBordMenu(BGREEN);
  bouton1.setCouleurFntMenu(WBLUE);
  bouton2.setCouleurBordMenu(BRED);
  bouton2.setCouleurFntMenu(BYELLOW);
  bouton3.setCouleurBordMenu(BRED);
  bouton3.setCouleurFntMenu(BYELLOW);
  bouton4.setCouleurBordMenu(BRED);
  bouton4.setCouleurFntMenu(BYELLOW);
}

void menuJouer(){
  int h=5, w=COLS/3, i=0, ch;
	Menu JcJ(h,w,COLS/3,7, "JOUEUR VS JOUEUR");
  // JcJ.upDatePrint(11,1);
	Menu JcIA(h,w,COLS/3,2*LINES/8+5, "JOUEUR VS IA");
  // JcIA.upDatePrint(13,1);
	Menu IAcIA(h,w,COLS/3,4*LINES/8+2, "IA VS IA");
	Menu backMenuPrinc(h,w,COLS/3,6*LINES/8-1, "RETOUR");
	boutonJouer(JcJ,JcIA,IAcIA,backMenuPrinc);


  Color const tmp = JcJ.getCouleurBordMenu(), tmp2 = JcJ.getCouleurFntMenu();
  

  while(((ch = getch()) != '\n') || (backMenuPrinc.getCouleurBordMenu() != tmp))
  {

    switch (ch) {
  //       case KEY_MOUSE:
  // if(souris_getpos(&sourisX, &sourisY, &bouton) == OK) {
  //   if(bouton & BUTTON1_PRESSED)
  //     printw("Clic bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
  //   if(bouton & BUTTON3_PRESSED)
  //     printw("Clic bouton 2 a la position (%d, %d)\n", sourisX, sourisY);
  //   if(bouton & BUTTON1_DOUBLE_CLICKED)
  //     printw("Double-clic bouton 1 a la position (%d, %d)\n", sourisX, sourisY);
  //   if(bouton & BUTTON3_DOUBLE_CLICKED)
  //     printw("Double-clic bouton 2 a la position (%d, %d)\n", sourisX, sourisY);
  //   refresh();
  // }
  // break;      
    	case KEY_UP:
  			menuJouer_keyUp(JcJ, JcIA, IAcIA, backMenuPrinc, tmp, tmp2, i);
  		break;
      case KEY_DOWN:
  			menuJouer_keyDown(JcJ, JcIA, IAcIA, backMenuPrinc, tmp, tmp2, i);
  		break;
      case '\n':
        if (JcJ.getCouleurBordMenu() == tmp)
        {

        }
        else if (JcIA.getCouleurBordMenu() == tmp )
        {
          clearTerm();
          jeuJcIA();
          clearTerm();
          boutonJouer(JcJ,JcIA,IAcIA,backMenuPrinc);
          i = 0;
        }
      break;
		}
	}
}
