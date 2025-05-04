CC=gcc
CFLAGS=`pkg-config --cflags gtk+-3.0` -Wall -g
LDFLAGS=`pkg-config --libs gtk+-3.0`
SRC=$(wildcard src/*.c)
OUT=dashboard

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT) 