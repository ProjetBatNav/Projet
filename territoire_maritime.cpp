#include "territoire_maritime.h"

terrM::terrM(int h, int w, int x, int y)
: m_terr(h,w,x,y) {

  box(m_terr.getWindowWin(),ACS_VLINE,ACS_HLINE);
	m_terr.print(1,1,'|');
}

terrM::~terrM(){}

WINDOW* terrM::getWindowWinTerr() const{
  return m_terr.getWindowWin();
}
