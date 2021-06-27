# == VARIAVEIS ===

CC=g++ # compilador
CFLAGS=-Wall -Wextra # compiler flags
EXEC=./tp3 # nome do executavel que sera gerado

# === REGRAS =====

$(EXEC): main.cpp no.o arvore.o
	$(CC) $(CFLAGS) main.cpp no.o arvore.o -o $(EXEC)

main.o: main.cpp 
	g++ -c main.cpp

no.o: no.cpp headers/no.h
	g++ -c no.cpp

arvore.o: arvore.cpp headers/arvore.h
	g++ -c arvore.cpp 

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf main.o no.o arvore.o
