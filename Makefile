
CC=g++
CFLAGS=-std=c++11 -Wall -I./src/ora/include
LDFLAGS=
LIB=libOra.so
SOURCES=jacobi.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prod


test: libs 
	cd tests/ && $(MAKE)
	./tests/test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) libs
	#$(CC) -g $(CFLAGS) $(LDFLAGS) $(OBJECTS)  -o $@

libs:
	cd src/ora && $(MAKE) && cd ../../

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -rf *o $(LIB)
	rm -rf tests/*o $(LIB)
	rm -rf $(EXECUTABLE_TESTS)
	cd src/ora && $(MAKE) clean && cd ../../
	cd tests && $(MAKE) clean