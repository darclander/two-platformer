
OBJS = ./src/*.cpp

CC=g++

CFLAGS= -I$(IDIR) -lmingw32 -lSDL2main -lSDL2 -lSDL2_Image 


IDIR = ./src/headers
_DEPS = GUI.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR = ./obj
_OBJ = main.o GUI.o Particle.o Firework.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: twoplatformer

./obj/%.o: ./src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

twoplatformer: $(OBJ)
	$(CC) -o ./debug/$@ $^ $(CFLAGS) 

run: twoplatformer
	./debug/twoplatformer

clean:
	rm -r **/*.o
	rm ./debug/twoplatformer.exe
