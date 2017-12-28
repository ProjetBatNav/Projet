#include "joueur.h"

Joueur::Joueur(std::string pseudo, WINDOW* Win, int defaut)
: m_pseudo(pseudo), m_win(Win), m_defaut(defaut){
	T[0].setNom("destroyer");
	T[1].setNom("croiseur");
	T[2].setNom("contreTorpilleur");
	T[3].setNom("sousMarin");
	T[4].setNom("torpilleur");

	if(defaut){
		for (int i = 0; i < 5; ++i)
		{
			T[i].defautNavire();
			T[i].initNav(4+10*i,0,m_win);
			print(i);
		}
	}	
}

Joueur::~Joueur(){}

std::string Joueur::getPseudo(){
	return m_pseudo;
}

void Joueur::print(int i) const{
	T[i].print();
}

void Joueur::mvNav(int i, terrM jeu){
	int ch;
	while((ch = getch()) != '\n'){
		int j = 0;
		switch(ch){
			case KEY_UP :			
				// T[i].effacer(jeu);
				// T[i].setY(T[i].getStartY()-1);
				if (j == i)
				{
					j++; 
				}
				while(j < 4 && (T[i] != T[j] || T[j].getWin() != jeu.getWin()))
				{
					if (j == i-1 && j < 3)
					{
						j+=2; 
					}
					else{
						j++;
					}
				}
				T[i].effacer(jeu);
				T[i].setY(T[i].getStartY()-1);				
				// while(T[i] == T[j] && T[j].getWin() == jeu.getWin()){
				// 	T[i].setY(T[i].getStartY()-1);
				// }
				print(j);
				print(i);
			break;
			case KEY_DOWN :
				// T[i].effacer(jeu);
				// T[i].setY(T[i].getStartY()+1);
				if (j == i)
				{
					j++; 
				}
				while(j < 4 && (T[i] != T[j] || T[j].getWin() != jeu.getWin()))
				{
					if (j == i-1 && j < 3)
					{
						j+=2; 
					}
					else{
						j++;
					}
				}
				T[i].effacer(jeu);
				T[i].setY(T[i].getStartY()+1);
				// while(T[i] == T[j] && T[j].getWin() == jeu.getWin()){
				// 	T[i].setY(T[i].getStartY()+1);
				// }
				print(j);
				print(i);
			break;
			case KEY_LEFT :
				// T[i].effacer(jeu);
				// T[i].setX(T[i].getStartX()-2);
				if (j == i)
				{
					j++; 
				}
				while(j < 4 && (T[i] != T[j] || T[j].getWin() != jeu.getWin()))
				{
					if (j == i-1 && j < 3)
					{
						j+=2; 
					}
					else{
						j++;
					}
				}
				T[i].effacer(jeu);
				T[i].setX(T[i].getStartX()-2);
				// while(T[i] == T[j] && T[j].getWin() == jeu.getWin()){
				// 	T[i].setX(T[i].getStartX()-2);
				// }
				print(j);
				print(i);
			break;
			case KEY_RIGHT :
				// T[i].effacer(jeu);
				// T[i].setX(T[i].getStartX()+2);
				if (j == i)
				{
					j++; 
				}
				while(j < 4 && (T[i] != T[j] || T[j].getWin() != jeu.getWin()))
				{
					if (j == i-1 && j < 3)
					{
						j+=2; 
					}
					else{
						j++;
					}
				}
				T[i].effacer(jeu);
				T[i].setX(T[i].getStartX()+2);
				// while(T[i] == T[j] && T[j].getWin() == jeu.getWin()){
				// 	T[i].setX(T[i].getStartX()+2);
				// }
				print(j);
				print(i);
			break;
		}
	}
}

void Joueur::selectNav(terrM jeu){
	int ch, i = 0;
	while(T[i].getWin() != m_win){
		i++;
	}
	while(T[i].getWin() == m_win){
		while(ch != '\n'){
			while(((ch = getch()) != KEY_RIGHT) && (ch != KEY_LEFT) && (ch != '\n')){
				T[i].clignot();
			}
			switch(ch){
				case KEY_RIGHT :
					if ((i < 4) && (T[i].getWin() == m_win))
					{
						i++;
					}
					else{
						i = 0;
					}
					while((i < 4) && (T[i].getWin() != m_win)){
						i++;
					}
					if((i == 4) && (T[i].getWin() != m_win)){
						i = 0;
						while((i < 4) && (T[i].getWin() != m_win)){
							i++;
						}
					}
				break;
				case KEY_LEFT :
					if ((i > 0) && (T[i].getWin() == m_win))
					{
						i--;
					}
					else{
						i = 4;
					}
					while((i > 0) && (T[i].getWin() != m_win)){
						i--;
					}
					if((i == 0) && (T[i].getWin() != m_win)){
						i = 4;
						while((i > 0) && (T[i].getWin() != m_win)){
							i--;
						}
					}
				break;
			}
		}
		T[i].deplacer(jeu);
		mvNav(i,jeu);
		i = 0;
		ch = 0; 
		while((i < 4) && (T[i].getWin() != m_win)){
		i++;
		}
	}
	
}

