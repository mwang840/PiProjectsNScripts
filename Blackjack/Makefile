CARD:=card.o

all: game

%.o: %.c card.h
	cc -g -c $<

game: game.o $(CARD)
	cc -g -o game game.o $(CARD)

clean:
	rm -f game game.o card.o
