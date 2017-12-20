CC = g++
CFLAGS = -Wall -ansi
PROG_NAME = prog

SOURCE = main.cpp menuprinc.cpp menujouer.cpp menuoptions.cpp window.cpp navire.cpp territoire_maritime.cpp \
fenetre_de_jeu.cpp message.cpp menu.cpp score.cpp joueur.cpp fntJcIA.cpp cellule.cpp

FICHIER1 = main
FICHIER2 = menuprinc
FICHIER3 = menujouer
FICHIER4 = menuoptions
FICHIER5 = window
FICHIER6 = navire
FICHIER7 = territoire_maritime
FICHIER8 = fenetre_de_jeu
FICHIER9 = message
FICHIER10 = menu  
FICHIER11 = score
FICHIER12 = joueur
FICHIER13 = fntJcIA
FICHIER14 = cellule

all : $(PROG_NAME)

$(FICHIER1).o : $(FICHIER1).cpp $(FICHIER2).h
	$(CC) -c $(FICHIER1).cpp $(CFLAGS)

$(FICHIER2).o : $(FICHIER2).cpp $(FICHIER2).h
	$(CC) -c $(FICHIER2).cpp $(CFLAGS)

$(FICHIER3).o : $(FICHIER3).cpp $(FICHIER3).h
	$(CC) -c $(FICHIER3).cpp $(CFLAGS)

$(FICHIER4).o : $(FICHIER4).cpp $(FICHIER4).h
	$(CC) -c $(FICHIER4).cpp $(CFLAGS)

$(FICHIER5).o : $(FICHIER5).cpp $(FICHIER5).h
	$(CC) -c $(FICHIER5).cpp $(CFLAGS)

$(FICHIER6).o : $(FICHIER6).cpp $(FICHIER6).h
	$(CC) -c $(FICHIER6).cpp $(CFLAGS)

$(FICHIER7).o : $(FICHIER7).cpp $(FICHIER7).h
	$(CC) -c $(FICHIER7).cpp $(CFLAGS)

$(FICHIER8).o : $(FICHIER8).cpp $(FICHIER8).h
	$(CC) -c $(FICHIER8).cpp $(CFLAGS)

$(FICHIER9).o : $(FICHIER9).cpp $(FICHIER9).h
	$(CC) -c $(FICHIER9).cpp $(CFLAGS)

$(FICHIER10).o : $(FICHIER10).cpp $(FICHIER10).h
	$(CC) -c $(FICHIER10).cpp $(CFLAGS)

$(FICHIER11).o : $(FICHIER11).cpp $(FICHIER11).h
	$(CC) -c $(FICHIER11).cpp $(CFLAGS)

$(FICHIER12).o : $(FICHIER12).cpp $(FICHIER12).h
	$(CC) -c $(FICHIER12).cpp $(CFLAGS)

$(FICHIER13).o : $(FICHIER13).cpp $(FICHIER13).h
	$(CC) -c $(FICHIER13).cpp $(CFLAGS)

$(FICHIER14).o : $(FICHIER14).cpp $(FICHIER14).h
	$(CC) -c $(FICHIER14).cpp $(CFLAGS)


$(PROG_NAME) : $(SOURCE:.c=.o)
	$(CC) $(SOURCE:.c=.o) -o $(PROG_NAME) -lncurses
