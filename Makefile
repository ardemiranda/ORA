
CC=g++
CFLAGS=-std=c++11 -Wall -I./src/ora/include
LDFLAGS=
LIB=libOra.so
SOURCES=tests/add.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)

tests: clean all
	./test
	

$(EXECUTABLE): $(OBJECTS) libs
	$(CC) -g $(CFLAGS) $(LDFLAGS)  $(OBJECTS)  -o $@
	
libs:
	cd src/ora && $(MAKE) && cd ../../
	
.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -rf *o $(LIB)
	rm -rf tests/*o $(LIB)
	cd src/ora && $(MAKE) clean && cd ../../