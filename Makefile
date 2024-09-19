all: pokedoku

pokedoku: pokedoku.cpp
		g++ pokedoku.cpp -o pokedoku -lncurses

clean:
		rm -f pokedoku *~ core