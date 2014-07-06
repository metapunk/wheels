# noob makefile

CC=gcc
CFLAGS=-c -Wall
SOURCE_DIR=../source

all: wheels_test

wheels_test: main.o log.o mutex.o
	$(CC) main.o log.o mutex.o -o wheels_test

main.o: $(SOURCE_DIR)/main.c
	$(CC) $(CFLAGS) $(SOURCE_DIR)/main.c

log.o: $(SOURCE_DIR)/log.c
	$(CC) $(CFLAGS) $(SOURCE_DIR)/log.c

mutex.o: $(SOURCE_DIR)/mutex.c
	$(CC) $(CFLAGS) $(SOURCE_DIR)/mutex.c

clean:
	rm -rf *o wheels_test
