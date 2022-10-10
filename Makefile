CC=gcc                      # compilateur
CFLAGS=-Wall -g -std=c99    # options de compilation
LDLIBS= -lgame -lm        # bibliothèques
LDFLAGS=-L.
CPPFLAGS=                   # options de preprocessing

# cible principale (par défaut)
all:  game_text dep
 
# règle spécifique pour générer l'exécutable

game_text:game_text.o libgame.a
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
.PHONY: clean dep

game_aux.o: game_aux.c game_aux.h game.h
game_text.o: game_text.c game.h game_aux.h


# génération des dépendances
dep:
	$(CC) -MM *.c > depends.txt

clean:
	rm -f *.o *~ game_text
	rm -f *.o *~ dep 

 
# inclusion des dépendances
-include depends.txt

