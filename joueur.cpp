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

//Empeche les Navires de se superposer
void Joueur::supNav(int i, int ch, const terrM jeu){
	int j = 0;
	if (j == i)
	{
		j++; 
	}
	while(j < 4 && (T[i] != T[j]))
	{
		if (j == i-1 && j < 3)
		{
			j+=2; 
		}
		else{
			j++;
		}
	}
	do{
		if (j != i)
		{
			int som = 1;
			while(T[i] == T[j]){
				if (ch == KEY_UP)
				{
					T[i].setY(T[i].getStartY()-1);
					if (T[i].horsLimiteJeu(jeu))
					{
						som++;
						T[i].setY(T[i].getStartY()+som);
					}
				}
				else if (ch == KEY_DOWN)
				{
					T[i].setY(T[i].getStartY()+1);
					if (T[i].horsLimiteJeu(jeu))
					{
						T[i].setY(T[i].getStartY()-som);
					}	
				}
				else if (ch == KEY_LEFT)
				{
					T[i].setX(T[i].getStartX()-2);
					if (T[i].horsLimiteJeu(jeu))
					{
						T[i].setX(T[i].getStartX()+som*2);
					}
				}
				else if (ch == KEY_RIGHT)
				{
					T[i].setX(T[i].getStartX()+2);
					if (T[i].horsLimiteJeu(jeu))
					{
						T[i].setX(T[i].getStartX()-som*2);
					}
				}
				else if (ch == 32)
				{
					T[i].pivoterG();
				}
				else
				{
					T[i].effacer();
					T[i].setX(T[i].getStartX()+2);
				}
				som++;
			}
			print(j);
		}
		j = 0;
		if (j == i)
		{
			j++; 
		}
		while(j < 4 && (T[i] != T[j]))
		{
			if (j == i-1 && j < 3)
			{
				j+=2; 
			}
			else{
				j++;
			}
		}
	}while(T[i] == T[j] && j != i);
	print(i);
}

//Permet de bouger les Navires
void Joueur::mvNav(int i, const terrM &jeu){
	int ch;
	supNav(i,ch,jeu);
	while((ch = getch()) != '\n'){
		switch(ch){
			case KEY_UP :
				T[i].effacer();
				T[i].setY(T[i].getStartY()-1);
				if (T[i].horsLimiteJeu(jeu))
				{
					T[i].setY(T[i].getStartY()+1);
				}
				supNav(i,ch,jeu);
			break;
			case KEY_DOWN :
				T[i].effacer();
				T[i].setY(T[i].getStartY()+1);
				if (T[i].horsLimiteJeu(jeu))
				{
					T[i].setY(T[i].getStartY()-1);
				}
				supNav(i,ch,jeu);
			break;
			case KEY_LEFT :
				T[i].effacer();
				T[i].setX(T[i].getStartX()-2);
				if (T[i].horsLimiteJeu(jeu))
				{
					T[i].setX(T[i].getStartX()+2);
				}
				supNav(i,ch,jeu);
			break;
			case KEY_RIGHT :
				T[i].effacer();
				T[i].setX(T[i].getStartX()+2);
				if (T[i].horsLimiteJeu(jeu))
				{
					T[i].setX(T[i].getStartX()-2);
				}
				supNav(i,ch,jeu);
			break;
			case 32 :
				T[i].effacer();
				T[i].pivoterD();
				if (T[i].horsLimiteJeu(jeu))
				{
					T[i].pivoterG();
				}
				supNav(i,ch,jeu);
			break;
		}
	}
}

void Joueur::selectNav(const terrM &jeu){
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

