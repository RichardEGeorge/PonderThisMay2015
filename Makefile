CC=g++
OPT=-O3
RM=rm

.PHONY: clean solve tidy

solution.txt: ponder
	./ponder solution.txt
    
clean: tidy
	$(RM) -f solution.txt

tidy:
	$(RM) -f ponder.o GameState.o ponder ponder.exe

ponder: ponder.o GameState.o
	$(CC) $(OPT) ponder.o GameState.o -o ponder
    
ponder.o: ponder.cpp ponder.h GameState.h
	$(CC) $(OPT) -c ponder.cpp -o ponder.o
    
GameState.o: GameState.h GameState.cpp
	$(CC) $(OPT) -c GameState.cpp -o GameState.o
    
    
