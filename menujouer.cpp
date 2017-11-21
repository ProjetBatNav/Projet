#include "menujouer.h"

void menuJouer_keyUp(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4, Color const &btnBord1, Color const &btnFen1, int &i){
  if (i == 0){
    bouton1.setCouleurBordure(bouton4.getCouleurBordure());
    bouton1.setCouleurFenetre(bouton4.getCouleurFenetre());
    bouton4.setCouleurBordure(btnBord1);
    bouton4.setCouleurFenetre(btnFen1);
    i = 3;
  }
  else if(i == 1){
    bouton2.setCouleurBordure(bouton1.getCouleurBordure());
    bouton2.setCouleurFenetre(bouton1.getCouleurFenetre());
    bouton1.setCouleurBordure(btnBord1);
    bouton1.setCouleurFenetre(btnFen1);
    i--;
  }
  else if(i == 2){
    bouton3.setCouleurBordure(bouton2.getCouleurBordure());
    bouton3.setCouleurFenetre(bouton2.getCouleurFenetre());
    bouton2.setCouleurBordure(btnBord1);
    bouton2.setCouleurFenetre(btnFen1);
    i--;  
  }
  else{
    bouton4.setCouleurBordure(bouton3.getCouleurBordure());
    bouton4.setCouleurFenetre(bouton3.getCouleurFenetre());
    bouton3.setCouleurBordure(btnBord1);
    bouton3.setCouleurFenetre(btnFen1);
    i--;
  } 
}

void menuJouer_keyDown(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4, Color const &btnBord1, Color const &btnFen1, int &i){
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
  else if(i == 2){
    bouton3.setCouleurBordure(bouton4.getCouleurBordure());
    bouton3.setCouleurFenetre(bouton4.getCouleurFenetre());
    bouton4.setCouleurBordure(btnBord1);
    bouton4.setCouleurFenetre(btnFen1);
    i++;  
  }
  else{
    bouton4.setCouleurBordure(bouton1.getCouleurBordure());
    bouton4.setCouleurFenetre(bouton1.getCouleurFenetre());
    bouton1.setCouleurBordure(btnBord1);
    bouton1.setCouleurFenetre(btnFen1);
    i = 0;
  }
}

void boutonJouer(Menu &bouton1, Menu &bouton2, Menu &bouton3, Menu &bouton4){
  bouton1.setCouleurBordure(BGREEN);
  bouton1.setCouleurFenetre(WBLUE);
  bouton2.setCouleurBordure(BRED);
  bouton2.setCouleurFenetre(BYELLOW);
  bouton3.setCouleurBordure(BRED);
  bouton3.setCouleurFenetre(BYELLOW);
  bouton4.setCouleurBordure(BRED);
  bouton4.setCouleurFenetre(BYELLOW);
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


  Color const tmp = JcJ.getCouleurBordure(), tmp2 = JcJ.getCouleurFenetre();
  

  while(((ch = getch()) != '\n') || (backMenuPrinc.getCouleurBordure() != tmp))
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
        if (JcJ.getCouleurBordure() == tmp)
        {

        }
        else if (JcIA.getCouleurBordure() == tmp )
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