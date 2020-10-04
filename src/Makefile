#==========================================
#    Makefile: makefile for goheels 5.1
#	Copyright 1993, 1998, 2014
#                 Toyoda Masashi
#		  (mtoyoda@acm.org)
#	Last Modified: 2014/03/31
#==========================================

CC=gcc
CFLAGS=-O -Wall

all: goheels static

goheels: goheels.c goheels.h
	$(CC) $(CFLAGS) -o goheels goheels.c -lncurses

# Need to add -ltermcap on WSL2 ubuntu 20.04. Could possibly be other
# 	libraries on other platforms.
static: goheels.c goheels.h
	$(CC) $(CFLAGS) -o goheels-static goheels.c -static -lncurses -ltermcap

clean:
	rm -f goheels goheels-static

distclean: clean
