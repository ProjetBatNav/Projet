#ifndef MESSAGE_H
#define MESSAGE_H

#include "window.h"

class Message{
	private :
	WINDOW* win;
	int m_height, m_weight, m_x, m_y;
	Color m_colorwin;
	
	void update() const;


	public :
	Message(int h, int w, int x, int y);

	~Message();

	void setCouleurFenetre(Color c);
	void print(int x, int y, std::string s); 

};

#endif
