#ifndef TERRITOIRE_MARITIME_H
#define TERRITOIRE_MARITIME_H

#include "window.h"

class terrM
{
 private:
  Window m_terr;
public:
	terrM(int h, int w, int x, int y);
	~terrM();
	WINDOW* getWindowWinTerr() const;
	
};
#endif
