CC := clang++
CFLAGS := -std=c++17 -Wall -pedantic -g
SOURCES := $(wildcard *.cpp)
BIN := pnuts

all: $(SOURCES)
	$(CC) $(CDFLAGS) $(CDFLAGS) $(SOURCES) -o pnuts

clean:
	rm pnuts

