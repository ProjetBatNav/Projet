CC = g++
FLAGS = -ansi -g
LIB = -lncurses
SRCS = main.cpp cellule.cpp navire.cpp window.cpp fenetre_de_jeu.cpp fntJcIA.cpp joueur.cpp score.cpp\
menu.cpp menujouer.cpp menuoptions.cpp menuprinc.cpp message.cpp score.cpp territoire_maritime.cpp choixOptions.cpp
OBJS = $(SRCS:.cpp = .o)
BIN = prog
SUPR = *.o

$(BIN): $(OBJS)
	clear; clear;
	$(CC) $(FLAGS) $(OBJS) -o $(BIN) $(LIB)

%.o: %.cpp
	$(CC) $(FLAGS) -c $@ $<

clean:
	rm $(FLAGS)
