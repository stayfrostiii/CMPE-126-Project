CC = g++
RUNOPTION = main
CFLAGS = -g -Wall

SRCS = main.cpp player.cpp chessPieces.cpp game.cpp
OBJ = $(patsubst %.cpp,%.o,$(SRCS))

all: $(RUNOPTION)
$(RUNOPTION): $(OBJ) 
	$(CC) -o $@ $^ 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

run:
	./$(RUNOPTION)

clean:
	rm *.o $(RUNOPTION)