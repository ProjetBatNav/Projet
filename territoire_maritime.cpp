#include "territoire_maritime.h"

terrM::terrM(int h, int w, int x, int y)
: fntJeu(h,w,x,y) {

	box(win,ACS_VLINE,ACS_HLINE);
	print(1,1,'|');
}

terrM::~terrM(){}