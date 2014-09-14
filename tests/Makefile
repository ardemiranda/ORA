
CC=g++
CFLAGS=-std=c++11 -Wall -I./../src/ora/include
LDFLAGS=-lgtest
LIB=../libOra.so
SOURCES=main.cpp matrix.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(OBJECTS)  -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -rf *o $(LIB) test