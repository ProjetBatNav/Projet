#ifndef FENETRE_DE_JEU_H
#define FENETRE_DE_JEU_H

#include "window.h"

class fntJeu
{
private:
	Window m_fnt;

public:
	fntJeu(int h, int w, int x, int y);
	~fntJeu();

	int getStartX();
	int getStartY();
	int getHauteur();
	int getLargeur();
	WINDOW* getWindowWinFnt() const;
	Color getCouleurFenetreFnt() const;

	void setCouleurFenetreFnt(Color c);
	void setCouleurBordureFnt(Color c);
};

#endif