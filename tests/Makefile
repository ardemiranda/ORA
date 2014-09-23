
CC=g++
CFLAGS=-std=c++11 -Wall -I./../src/ora/include
LDFLAGS=-lgtest
LIB=../libOra.so
SOURCES=main.cpp matrix.cpp jacobi.cpp gauss.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	echo 'as';
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(LIB) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -g -c $(CFLAGS) $< -o $@
	
clean:
	rm -rf *o $(LIB) test