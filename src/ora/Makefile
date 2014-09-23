

CC=g++
LCFLAGS=-std=c++11 -c -Wall -I./include -fPIC
SOURCES=Matrix.cpp Jacobi.cpp Gauss.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libOra.so

all: $(SOURCES) $(LIB)
	cp $(LIB) ../../

$(LIB): $(OBJECTS)
	$(CC) -shared $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(LCFLAGS) $< -o $@
	
clean:
	rm -rf *o $(LIB)
