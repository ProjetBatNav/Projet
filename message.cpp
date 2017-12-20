#include "message.h"

Message::Message(int h, int w, int x, int y)
: m_height(h), m_weight(w), m_x(x), m_y(y){
	m_colorwin = WRED;
	win = newwin(h,w,y,x);
	wattron(win,COLOR_PAIR(m_colorwin));
	wbkgd(win,COLOR_PAIR(m_colorwin));
	update();
}

Message::~Message(){
	wattroff(win,COLOR_PAIR(m_colorwin));
	werase(win);
	update();
	delwin(win);
}

void Message::update() const{
	wrefresh(win);
	refresh();
}

void Message::setCouleurFenetre(Color c){
	m_colorwin=c;
	wattron(win,COLOR_PAIR(m_colorwin));
	wbkgd(win,COLOR_PAIR(m_colorwin));
	update();
}

void Message::print(int x, int y, std::string s){
	mvwprintw(win,y,x,s.c_str());
	update();
}
